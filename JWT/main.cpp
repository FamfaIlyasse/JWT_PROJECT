#include "JWT.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QApplication>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QTextEdit>
#include "QComboBox"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include "hash.h"
#include <string>
#include <QString>
#include "Ui.h"
#include <QFont>


int main(int argc, char* argv[])
{
    //QtWidgetsApplication1 w;
    QApplication app(argc, argv);

    QWidget* fenetre = new QWidget;


    // CREATE HORIZANTAL LATOUT
    QHBoxLayout* horizantalLayout1 = new QHBoxLayout;
    QHBoxLayout* horizantalLayout2 = new QHBoxLayout;



    // CREATE VERTICAL LAYOUT
    QVBoxLayout* verticalLayout1 = new QVBoxLayout;
    QVBoxLayout* verticalLayout2 = new QVBoxLayout;
    QVBoxLayout* verticalLayout3 = new QVBoxLayout;
    QVBoxLayout* verticalLayout4 = new QVBoxLayout;
    QVBoxLayout* verticalLayout5 = new QVBoxLayout;
    QVBoxLayout* verticalLayout6 = new QVBoxLayout;

    QLineEdit* sousLabel = new QLineEdit("your-256-bit-secret");


    // CREATE LABEL
    QLabel* label1 = new QLabel(nullptr);
    QLabel* label2 = new QLabel(nullptr);
    QLabel* label3 = new QLabel(nullptr);

    QString LabelStyle = "QLabel {"
        "   background-color:white;"
        "   color:black;"
        "   border: .5px solid rgb(155 155 155 / 50%);"
        "   border-radius: 2px;"
        "   padding:5px;"
        "}";
    QString label_1 = "<font style=\"font-family: 'fakt-web','Helvetica Neue',Helvetica,Arial,sans-serif; color: black;\">HEADER :</font>"
        "<font style=\"font-family: 'fakt-web','Helvetica Neue',Helvetica,Arial,sans-serif; color: gray;\"> ALGORITHM & TOKEN TYPE</font>";
    QString label_2 = "<font style=\"font-family: 'fakt-web','Helvetica Neue',Helvetica,Arial,sans-serif; color: black;\">PAYLOAD :</font>"
        "<font style=\"font-family: 'fakt-web','Helvetica Neue',Helvetica,Arial,sans-serif; color: gray;\"> DATA </font>";

    // ADD TEXT TO LABEL
    label1->setText(label_1);
    label1->setStyleSheet(LabelStyle);
    label2->setText(label_2);
    label2->setStyleSheet(LabelStyle);
    label3->setText("VERIFY SIGNATURE");
    label3->setStyleSheet(LabelStyle);


    // CREATE TEXT BOX
    QTextEdit* textbox1 = new QTextEdit;
    textbox1->setText("{\n   \"alg\":\"HS256\",\n   \"typ\":\"JWT\"\n}");
    textbox1->setStyleSheet("color:red;border: 0.5px solid rgb(155 155 155 / 50%);border-radius: 2px;");
    QTextEdit* textbox2 = new QTextEdit;
    textbox2->setText("{\n   \"sub\":\"1234567890\",\n   \"name\":\"John Doe\",\n   \"iat\":1516239022\n}");
    textbox2->setStyleSheet("color:#d63aff;border: 0.5px solid rgb(155 155 155 / 50%);border-radius: 2px;");
    QTextEdit* textbox3 = new QTextEdit;
    textbox3->setText("HMACSHA256(\n   base64UrlEncode(header) + \".\" +\n   base64UrlEncode(payload),\n\n\n)");
    textbox3->setStyleSheet("font-size: 14px ;color:#00b9f1 ;font-family: monospace,monospace; background-color : #F4F4F4;border: 0.5px solid rgb(155 155 155 / 50%);border-radius: 2px;");
    textbox3->setReadOnly(true);
    QTextEdit* textbox4 = new QTextEdit;
    textbox4->setStyleSheet("font-size: 14px ; font-weight :500;letter-spacing : 1px;border: 0.5px solid rgb(155 155 155 / 50%);border-radius: 2px;");
   

    QLineEdit* lineedit = new QLineEdit("your-256-bit-secret", textbox3);
    lineedit->setFixedWidth(150);
    lineedit->setStyleSheet("border: 0.5px solid rgb(155 155 155 / 50%);border-radius: 4px; color:#00b9f1 ; background-color : white; height:20px; padding: 2px;");
    lineedit->move(15, 60);

    QCheckBox* checkbox = new QCheckBox("secret base64 encoded", textbox3);
    checkbox->setFixedWidth(160);
    checkbox->setStyleSheet("border:null;");
    checkbox->move(15, 88);

    //CREATE COMBOBOX
    QComboBox* combobox1 = new QComboBox;
    // Setting the background color, border, padding, and text color
    combobox1->setStyleSheet(
        "QComboBox {"
        "   background-color: white;"
        "   color: black;"
        "   border: 1px solid rgba(155, 155, 155, 0.5);"
        "   border-radius: 5px;"
        "   padding: 8px;"
        "   max-width: 100px;"
        "}"
        "QComboBox::down-arrow {"
        "   image: url(C:/Users/ardem/source/repos/JWT/JWT/images/down.jpg); "
        "   width: 16px; "
        "   height: 16px; "
        "}"
        "QComboBox::drop-down {"
        "   subcontrol-origin: padding;"
        "   subcontrol-position: top right;"
        "   width: 20px;"
        "   border-left-width: 1px;"
        "   border-left-color: rgba(155, 155, 155, 0.5);"
        "   border-left-style: solid;"
        "   border-top-right-radius: 5px;"
        "   border-bottom-right-radius: 5px;"
        "}"
    );

    // ADD ITEMS TO COMBO BOX
    combobox1->addItem("HS256");
    combobox1->addItem("HS384");
    combobox1->addItem("HS512");



    // ADD LABEL TO THE VERTICAL LAYOUT
    verticalLayout1->addWidget(label1);
    verticalLayout2->addWidget(label2);
    verticalLayout3->addWidget(label3);

    // ADD TEXT BOX TO  THE VERTICAL LAYOUT
    verticalLayout1->addWidget(textbox1);
    verticalLayout2->addWidget(textbox2);
    verticalLayout3->addWidget(textbox3);
    verticalLayout4->addWidget(textbox4);

    // ADD COMBO BOX TO THE HORIZANTAL LAYOUT
    horizantalLayout2->addWidget(combobox1);



    // ADD VERTICAL LAYOUT TO THE VERICAL LAYOUT
    verticalLayout5->addLayout(verticalLayout1);
    verticalLayout5->addLayout(verticalLayout2);
    verticalLayout5->addLayout(verticalLayout3);

    // REMOVE SPACING
    verticalLayout1->setSpacing(0);
    verticalLayout2->setSpacing(0);
    verticalLayout3->setSpacing(0);


    horizantalLayout1->addLayout(verticalLayout4);
    horizantalLayout1->addLayout(verticalLayout5);

    verticalLayout6->addLayout(horizantalLayout2);
    verticalLayout6->addLayout(horizantalLayout1);

    QObject::connect(combobox1, QOverload<int>::of(&QComboBox::currentIndexChanged),
        [=](int index) {
            QString selectedtext2 = combobox1->itemText(index);

            if (selectedtext2 == "HS256") {
                textbox1->setPlainText("{\n   \"alg\":\"HS256\",\n   \"typ\":\"JWT\"\n}");
                textbox2->setPlainText("{\n    \"sub\":\"1234567890\",\n   \"name\":\"John Doe\",\n   \"iat\":1516239022\n}");
                textbox3->setPlainText("HMACSHA256(\n   base64UrlEncode(header) + \".\" +\n   base64UrlEncode(payload),\n\n\n)");
                lineedit->setText("your-256-bit-secret");

            }
            else if (selectedtext2 == "HS384") {
                textbox1->setPlainText("{\n   \"alg\":\"HS384\",\n   \"typ\":\"JWT\"\n}");
                textbox2->setPlainText("{\n   \"sub\":\"1234567890\",\n   \"name\":\"John Doe\",\n   \"admin\":true,\n   \"iat\":1516239022\n}");
                lineedit->setText("your-384-bit-secret");
                textbox3->setPlainText("HMACSHA384(\n   base64UrlEncode(header) + \".\" +\n   base64UrlEncode(payload),\n\n\n)");
            }
            else if (selectedtext2 == "HS512") {
                textbox1->setPlainText("{\n   \"alg\":\"HS512\",\n   \"typ\":\"JWT\"\n}");
                textbox2->setPlainText("{\n   \"sub\":\"1234567890\",\n   \"name\":\"John Doe\",\n   \"iat\":1516239022\n}");
                textbox3->setPlainText("HMACSHA512(\n   base64UrlEncode(header) + \".\" +\n   base64UrlEncode(payload),\n\n\n)");
                lineedit->setText("your-512-bit-secret");



            }


        });



    QString code1 = "";
    QString code2 = "";
    QString code3 = "";
    QString code = "";


    std::string header = codeHeaderPayload(textbox1->toPlainText());
    std::string payload = codeHeaderPayload(textbox2->toPlainText());
    std::string secret = lineedit->text().toStdString();
    std::string selectedAlgo = combobox1->currentText().toStdString();
   // std::string header1 = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9";
    //std::string payload1 = "eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ";
    //std::string secret1 = "your-256-bit-secret";
    //std::string selectedAlgo1 = "HS256";
    std::string signateur = generateJWTSignature(header, payload, secret, selectedAlgo, checkbox->isChecked());
    std::string validation = header + "." + payload + "." + signateur;
    code1 = QString::fromStdString(header);
    code2 = QString::fromStdString(payload);
    code3 = QString::fromStdString(signateur);
    code = "<font color=\"red\">" + code1 + "</font>" + "." + "<font color=\"#d63aff\">" + code2 + "</font>" + "." + "<font color=\"#00b9f1\">" + code3 + "</font>";

    textbox4->setHtml(code);

    //Line Edit 

    QObject::connect(lineedit, &QLineEdit::textChanged, [&]() {

        std::string header = codeHeaderPayload(textbox1->toPlainText());
        std::string payload = codeHeaderPayload(textbox2->toPlainText());
        std::string secret = lineedit->text().toStdString();
        std::string selectedAlgo = combobox1->currentText().toStdString();
        std::string signateur = generateJWTSignature(header, payload, secret, selectedAlgo, checkbox->isChecked());

        auto updateCode = [&](QString& code1, QString& code2, QString& code3, QString& code) {
            code1 = QString::fromStdString(header);
            code2 = QString::fromStdString(payload);
            code3 = QString::fromStdString(signateur);
            code = "<font color=\"red\">" + code1 + "</font>" + "." + "<font color=\"#d63aff\">" + code2 + "</font>" + "." + "<font color=\"#00b9f1\">" + code3 + "</font>";
            textbox4->setHtml(code);

            };

        updateCode(code1, code2, code3, code);
        });

    //TEXTBOX1
    QObject::connect(textbox1, &QTextEdit::textChanged, [&]() {

        std::string header = codeHeaderPayload(textbox1->toPlainText());
        std::string payload = codeHeaderPayload(textbox2->toPlainText());
        std::string secret = lineedit->text().toStdString();
        std::string selectedAlgo = combobox1->currentText().toStdString();
        std::string signateur = generateJWTSignature(header, payload, secret, selectedAlgo, checkbox->isChecked());

        auto updateCode = [&](QString& code1, QString& code2, QString& code3, QString& code) {
            code3 = QString::fromStdString(signateur);
            code1 = QString::fromStdString(header);
            code = "<font color=\"red\">" + code1 + "</font>" + "." + "<font color=\"#d63aff\">" + code2 + "</font>" + "." + "<font color=\"#00b9f1\">" + code3 + "</font>";

            textbox4->setHtml(code);

            };

        updateCode(code1, code2, code3, code);
        });

    QObject::connect(textbox2, &QTextEdit::textChanged, [&]() {

        std::string header = codeHeaderPayload(textbox1->toPlainText());
        std::string payload = codeHeaderPayload(textbox2->toPlainText());
        std::string secret = lineedit->text().toStdString();
        std::string selectedAlgo = combobox1->currentText().toStdString();
        std::string signateur = generateJWTSignature(header, payload, secret, selectedAlgo, checkbox->isChecked());

        auto updateCode = [&](QString& code1, QString& code2, QString& code3, QString& code) {
            code3 = QString::fromStdString(signateur);
            code2 = QString::fromStdString(payload);
            code = "<font color=\"red\">" + code1 + "</font>" + "." + "<font color=\"#d63aff\">" + code2 + "</font>" + "." + "<font color=\"#00b9f1\">" + code3 + "</font>";
            textbox4->setHtml(code);

            };

        updateCode(code1, code2, code3, code);
        });

    QObject::connect(checkbox, &QCheckBox::stateChanged, [&]() {

        std::string header = codeHeaderPayload(textbox1->toPlainText());
        std::string payload = codeHeaderPayload(textbox2->toPlainText());
        std::string secret = lineedit->text().toStdString();
        std::string selectedAlgo = combobox1->currentText().toStdString();
        std::string signateur = generateJWTSignature(header, payload, secret, selectedAlgo, checkbox->isChecked());

        auto updateCode = [&](QString& code1, QString& code2, QString& code3, QString& code) {
            code3 = QString::fromStdString(signateur);

            code = "<font color=\"red\">" + code1 + "</font>" + "." + "<font color=\"#d63aff\">" + code2 + "</font>" + "." + "<font color=\"#00b9f1\">" + code3 + "</font>";
            textbox4->setHtml(code);

            };

        updateCode(code1, code2, code3, code);
        });



    QObject::connect(textbox1, &QTextEdit::textChanged, [=]() {
        if (testJson(textbox1->toPlainText())){
            textbox1->setStyleSheet("background-color: #F5C7DA; color: red;");
            textbox4->setText("");
        }
        else {
            textbox1->setStyleSheet("background-color: white; color: red;");

        }

        });

    QObject::connect(textbox2, &QTextEdit::textChanged, [=]() {
        if (testJson(textbox2->toPlainText())) {
            textbox2->setStyleSheet("background-color: #F5C7DA; color: #d63aff;");
            textbox4->setText("");
        }
        else {
            textbox2->setStyleSheet("background-color: white; color: #d63aff ;");

        }
        });

    QLabel* statusImage = nullptr;
    QString enteredText = textbox4->toPlainText();
    std::string text = enteredText.toStdString();

    if (statusImage) {

        if (text == validation) {
            statusImage->setPixmap(QPixmap("C:/Users/ardem/source/repos/JWT/JWT/images/valid.png"));
        }
        else {
            statusImage->setPixmap(QPixmap("C:/Users/ardem/source/repos/JWT/JWT/images/invalid.png"));
        }
    }
    else {
        statusImage = new QLabel;

        if (text == validation) {
            statusImage->setPixmap(QPixmap("C:/Users/ardem/source/repos/JWT/JWT/images/valid.png"));
        }
        else {
            statusImage->setPixmap(QPixmap("C:/Users/ardem/source/repos/JWT/JWT/images/invalid.png"));
        }

        verticalLayout4->addWidget(statusImage);
    }

    QObject::connect(textbox4, &QTextEdit::textChanged, [&]() {
        QString enteredText = textbox4->toPlainText();
        std::string text = enteredText.toStdString();
        std::string header = codeHeaderPayload(textbox1->toPlainText());
        std::string payload = codeHeaderPayload(textbox2->toPlainText());
        std::string secret = lineedit->text().toStdString();
        std::string selectedAlgo = combobox1->currentText().toStdString();
        std::string signateur = generateJWTSignature(header, payload, secret, selectedAlgo, checkbox->isChecked());
        std::string validation = header + "." + payload + "." + signateur; 
        if (statusImage) {

            if (text == validation) {
                statusImage->setPixmap(QPixmap("C:/Users/ardem/source/repos/JWT/JWT/images/valid.png"));
            }
            else {
                statusImage->setPixmap(QPixmap("C:/Users/ardem/source/repos/JWT/JWT/images/invalid.png"));
            }
        }
        else {
            statusImage = new QLabel;

            if (text == validation) {
                statusImage->setPixmap(QPixmap("C:/Users/ardem/source/repos/JWT/JWT/images/valid.png"));
            }
            else {
                statusImage->setPixmap(QPixmap("C:/Users/ardem/source/repos/JWT/JWT/images/invalid.png"));
            }

            verticalLayout4->addWidget(statusImage);
        }
        }); 




    fenetre->setLayout(verticalLayout6);

    app.setStyleSheet("QWidget { background-color: #FFFFFF; }");
    QIcon icon("C:/Users/ardem/Desktop/icon.jpg");
    fenetre->setWindowIcon(icon);
    fenetre->setWindowTitle("JWT APPLICATION");
    fenetre->resize(800, 600);
    fenetre->show();




    return app.exec();
}


