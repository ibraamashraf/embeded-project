/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Login;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(270, 50, 271, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Login = new QLabel(verticalLayoutWidget);
        Login->setObjectName("Login");
        Login->setStyleSheet(QString::fromUtf8("color: #007BFF;  /* \330\247\331\204\330\243\330\262\330\261\331\202 */\n"
"font-size: 18px;  /* \330\252\330\272\331\212\331\212\330\261 \330\255\330\254\331\205 \330\247\331\204\330\256\330\267 */\n"
"font-weight: bold;  /* \330\254\330\271\331\204 \330\247\331\204\330\256\330\267 \330\271\330\261\331\212\330\266 */"));

        verticalLayout->addWidget(Login);

        usernameLineEdit = new QLineEdit(verticalLayoutWidget);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0;  /* \330\256\331\204\331\201\331\212\330\251 \330\256\331\201\331\212\331\201\330\251 */\n"
"color: #333333;  /* \330\247\331\204\331\204\331\210\331\206 \330\247\331\204\330\257\330\247\331\203\331\206 \331\204\331\204\331\206\330\265 */\n"
"border: 1px solid #888;  /* \330\255\330\257\331\210\330\257 \330\256\331\201\331\212\331\201\330\251 \330\255\331\210\331\204 \330\247\331\204\331\200QLineEdit */"));

        verticalLayout->addWidget(usernameLineEdit);

        passwordLineEdit = new QLineEdit(verticalLayoutWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0;  /* \330\256\331\204\331\201\331\212\330\251 \330\256\331\201\331\212\331\201\330\251 */\n"
"color: #333333;  /* \330\247\331\204\331\204\331\210\331\206 \330\247\331\204\330\257\330\247\331\203\331\206 \331\204\331\204\331\206\330\265 */\n"
"border: 1px solid #888;  /* \330\255\330\257\331\210\330\257 \330\256\331\201\331\212\331\201\330\251 \330\255\331\210\331\204 \330\247\331\204\331\200QLineEdit */"));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passwordLineEdit);

        loginButton = new QPushButton(verticalLayoutWidget);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("background-color: #4CAF50;  /* \330\247\331\204\331\204\331\210\331\206 \330\247\331\204\330\243\330\256\330\266\330\261 */\n"
"color: white;  /* \330\247\331\204\331\206\330\265 \331\212\330\250\331\202\331\211 \331\204\331\210\331\206\331\207 \330\243\330\250\331\212\330\266 */\n"
"border-radius: 5px;  /* \330\255\331\210\330\247\331\201 \330\247\331\204\330\262\330\261\330\247\330\261 \331\205\330\257\331\210\330\261\330\251 \330\264\331\210\331\212\330\251 */"));

        verticalLayout->addWidget(loginButton);

        registerButton = new QPushButton(verticalLayoutWidget);
        registerButton->setObjectName("registerButton");
        registerButton->setStyleSheet(QString::fromUtf8("background-color: #4CAF50;  /* \330\247\331\204\331\204\331\210\331\206 \330\247\331\204\330\243\330\256\330\266\330\261 */\n"
"color: white;  /* \330\247\331\204\331\206\330\265 \331\212\330\250\331\202\331\211 \331\204\331\210\331\206\331\207 \330\243\330\250\331\212\330\266 */\n"
"border-radius: 5px;  /* \330\255\331\210\330\247\331\201 \330\247\331\204\330\262\330\261\330\247\330\261 \331\205\330\257\331\210\330\261\330\251 \330\264\331\210\331\212\330\251 */"));

        verticalLayout->addWidget(registerButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Login->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
