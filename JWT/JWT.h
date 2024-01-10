#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_JWT.h"

class JWT : public QMainWindow
{
    Q_OBJECT

public:
    JWT(QWidget *parent = nullptr);
    ~JWT();

private:
    Ui::JWTClass ui;
};
