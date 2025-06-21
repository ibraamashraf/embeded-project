/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Login;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_register;
    QPushButton *pushButton_back;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(731, 387);
        verticalLayoutWidget = new QWidget(RegisterWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(260, 140, 271, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Login = new QLabel(verticalLayoutWidget);
        Login->setObjectName("Login");
        Login->setStyleSheet(QString::fromUtf8("color: #007BFF;  /* \330\247\331\204\330\243\330\262\330\261\331\202 */\n"
"font-size: 18px;  /* \330\252\330\272\331\212\331\212\330\261 \330\255\330\254\331\205 \330\247\331\204\330\256\330\267 */\n"
"font-weight: bold;  /* \330\254\330\271\331\204 \330\247\331\204\330\256\330\267 \330\271\330\261\331\212\330\266 */"));

        verticalLayout->addWidget(Login);

        lineEdit_username = new QLineEdit(verticalLayoutWidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0;  /* \330\256\331\204\331\201\331\212\330\251 \330\256\331\201\331\212\331\201\330\251 */\n"
"color: #333333;  /* \330\247\331\204\331\204\331\210\331\206 \330\247\331\204\330\257\330\247\331\203\331\206 \331\204\331\204\331\206\330\265 */\n"
"border: 1px solid #888;  /* \330\255\330\257\331\210\330\257 \330\256\331\201\331\212\331\201\330\251 \330\255\331\210\331\204 \330\247\331\204\331\200QLineEdit */"));

        verticalLayout->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(verticalLayoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0;  /* \330\256\331\204\331\201\331\212\330\251 \330\256\331\201\331\212\331\201\330\251 */\n"
"color: #333333;  /* \330\247\331\204\331\204\331\210\331\206 \330\247\331\204\330\257\330\247\331\203\331\206 \331\204\331\204\331\206\330\265 */\n"
"border: 1px solid #888;  /* \330\255\330\257\331\210\330\257 \330\256\331\201\331\212\331\201\330\251 \330\255\331\210\331\204 \330\247\331\204\331\200QLineEdit */"));
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(lineEdit_password);

        pushButton_register = new QPushButton(verticalLayoutWidget);
        pushButton_register->setObjectName("pushButton_register");
        pushButton_register->setStyleSheet(QString::fromUtf8("background-color: #4CAF50;  /* \330\247\331\204\331\204\331\210\331\206 \330\247\331\204\330\243\330\256\330\266\330\261 */\n"
"color: white;  /* \330\247\331\204\331\206\330\265 \331\212\330\250\331\202\331\211 \331\204\331\210\331\206\331\207 \330\243\330\250\331\212\330\266 */\n"
"border-radius: 5px;  /* \330\255\331\210\330\247\331\201 \330\247\331\204\330\262\330\261\330\247\330\261 \331\205\330\257\331\210\330\261\330\251 \330\264\331\210\331\212\330\251 */"));

        verticalLayout->addWidget(pushButton_register);

        pushButton_back = new QPushButton(verticalLayoutWidget);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setStyleSheet(QString::fromUtf8("background-color: #4CAF50;  /* \330\247\331\204\331\204\331\210\331\206 \330\247\331\204\330\243\330\256\330\266\330\261 */\n"
"color: white;  /* \330\247\331\204\331\206\330\265 \331\212\330\250\331\202\331\211 \331\204\331\210\331\206\331\207 \330\243\330\250\331\212\330\266 */\n"
"border-radius: 5px;  /* \330\255\331\210\330\247\331\201 \330\247\331\204\330\262\330\261\330\247\330\261 \331\205\330\257\331\210\330\261\330\251 \330\264\331\210\331\212\330\251 */"));

        verticalLayout->addWidget(pushButton_back);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        Login->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        pushButton_register->setText(QCoreApplication::translate("RegisterWindow", "Create Account", nullptr));
        pushButton_back->setText(QCoreApplication::translate("RegisterWindow", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
