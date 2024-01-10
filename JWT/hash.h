#pragma once
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <string>
#include <QString>


std::string base64Encode(const std::string&);
std::string base64_url_decode(const std::string& encoded_string);

std::string generateJWTSignature(std::string&, std::string&, std::string&, std::string&, bool);

QString removeSpacesInJson(const QString& jsonString);
    