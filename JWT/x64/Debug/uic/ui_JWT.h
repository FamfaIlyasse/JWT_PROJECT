/********************************************************************************
** Form generated from reading UI file 'JWT.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JWT_H
#define UI_JWT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JWTClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *JWTClass)
    {
        if (JWTClass->objectName().isEmpty())
            JWTClass->setObjectName("JWTClass");
        JWTClass->resize(600, 400);
        menuBar = new QMenuBar(JWTClass);
        menuBar->setObjectName("menuBar");
        JWTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(JWTClass);
        mainToolBar->setObjectName("mainToolBar");
        JWTClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(JWTClass);
        centralWidget->setObjectName("centralWidget");
        JWTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(JWTClass);
        statusBar->setObjectName("statusBar");
        JWTClass->setStatusBar(statusBar);

        retranslateUi(JWTClass);

        QMetaObject::connectSlotsByName(JWTClass);
    } // setupUi

    void retranslateUi(QMainWindow *JWTClass)
    {
        JWTClass->setWindowTitle(QCoreApplication::translate("JWTClass", "JWT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JWTClass: public Ui_JWTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JWT_H
