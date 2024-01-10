#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include "hash.h"
#include <vector>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>

const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";

std::string base64_url_decode(const std::string& encoded_string) {
    // Pad the string with '=' characters to make its length a multiple of 4
    std::string padded_string = encoded_string + std::string((4 - encoded_string.length() % 4) % 4, '=');

    // Replace URL-safe characters
    std::replace(padded_string.begin(), padded_string.end(), '-', '+');
    std::replace(padded_string.begin(), padded_string.end(), '_', '/');

    // Decode base64 string
    BIO* bio = BIO_new(BIO_f_base64());
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    BIO* bio_mem = BIO_new_mem_buf(padded_string.c_str(), -1);
    bio = BIO_push(bio, bio_mem);

    std::vector<char> buffer(padded_string.length());
    int decoded_length = BIO_read(bio, buffer.data(), static_cast<int>(buffer.size()));

    // Clean up
    BIO_free_all(bio);

    if (decoded_length <= 0) {
        // Error in decoding
        return "";
    }

    return std::string(buffer.begin(), buffer.begin() + decoded_length);
}

std::string base64Encode(const std::string& input) {
    std::string encoded;
    int i = 0, j = 0;
    unsigned char array3[3];
    unsigned char array4[4];

    while (i < input.size()) {
        array3[j++] = input[i++];
        if (j == 3) {
            array4[0] = (array3[0] & 0xFC) >> 2;
            array4[1] = ((array3[0] & 0x03) << 4) + ((array3[1] & 0xF0) >> 4);
            array4[2] = ((array3[1] & 0x0F) << 2) + ((array3[2] & 0xC0) >> 6);
            array4[3] = array3[2] & 0x3F;

            for (j = 0; j < 4; j++)
                encoded += base64_chars[array4[j]];

            j = 0;
        }
    }

    if (j != 0) {
        for (int k = j; k < 3; k++)
            array3[k] = '\0';

        array4[0] = (array3[0] & 0xFC) >> 2;
        array4[1] = ((array3[0] & 0x03) << 4) + ((array3[1] & 0xF0) >> 4);
        array4[2] = ((array3[1] & 0x0F) << 2) + ((array3[2] & 0xC0) >> 6);
        array4[3] = array3[2] & 0x3F;

        for (int k = 0; k < j + 1; k++)
            encoded += base64_chars[array4[k]];

        // while (j++ < 3)
        //     encoded += '=';
    }

    return encoded;
}

std::string generateJWTSignature(std::string& header, std::string& payload, std::string& secret, std::string& selectedAlgo, bool check) {
    std::string tokenData = header + "." + payload;
    unsigned int hashLen = 0;
    std::string secret1 = secret;
    std::vector<unsigned char> hash(EVP_MAX_MD_SIZE);
    if (check) {
        secret1 = base64_url_decode(secret1);

    }
    if (selectedAlgo == "HS256") {
        HMAC(EVP_sha256(), secret1.c_str(), secret1.length(),
            reinterpret_cast<const unsigned char*>(tokenData.c_str()), tokenData.length(), hash.data(), &hashLen);


    }
    else if (selectedAlgo == "HS384") {
        HMAC(EVP_sha384(), secret1.c_str(), secret1.length(),
            reinterpret_cast<const unsigned char*>(tokenData.c_str()), tokenData.length(), hash.data(), &hashLen);
    }
    else if (selectedAlgo == "HS512") {
        HMAC(EVP_sha512(), secret1.c_str(), secret1.length(),
            reinterpret_cast<const unsigned char*>(tokenData.c_str()), tokenData.length(), hash.data(), &hashLen);

    }


    std::string signature(hash.begin(), hash.begin() + hashLen);
    return base64Encode(signature);
}


QString removeSpacesInJson(const QString& jsonString) {
    // Regular expression to match spaces between various JSON elements
    QRegularExpression regex("\\s*([\\{\\}\\[\\],:]|\"(?:[^\"\\\\]|\\\\.)*\")\\s*");

    // Replace spaces based on the regular expression
    QString result = jsonString;
    result.replace(regex, "\\1");

    return result;
}