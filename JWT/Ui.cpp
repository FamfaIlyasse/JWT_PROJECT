#include "Ui.h"
#include "hash.h"
#include<string>
#include <QString>

std::string codeHeaderPayload(QString Qstr) {
    Qstr = removeSpacesInJson(Qstr);
    std::string strpayload = Qstr.toStdString();

    return base64Encode(strpayload);
}

bool testJson(QString jsonString) {
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);

    if (error.error != QJsonParseError::NoError || !jsonDoc.isObject()) {
        return true;
    }
    return false;
}

