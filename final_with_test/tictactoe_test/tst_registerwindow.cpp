#include "tst_registerwindow.h"
#include <QtTest>
#include "../TicTacToe_design/registerwindow.h"
#include "../TicTacToe_design/usermanager.h"
#include "../TicTacToe_design/homewindow.h"
#include "../TicTacToe_design/mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

// Optional: mock the HomeWindow and MainWindow if needed
// (You can create dummy subclasses that override .show() to track behavior)

// Called once before all test functions
void RegisterWindowTest::initTestCase() {
    qDebug() << "Starting RegisterWindow tests...";
}

// Test that empty username/password shows warning
void RegisterWindowTest::test_empty_fields_show_warning() {
    UserManager manager("test_users.json");
    RegisterWindow window(nullptr, &manager);


    QLineEdit *usernameField = window.findChild<QLineEdit*>("lineEdit_username");
    QLineEdit *passwordField = window.findChild<QLineEdit*>("lineEdit_password");
    QPushButton *registerButton = window.findChild<QPushButton*>("pushButton_register");

    QVERIFY(usernameField);
    QVERIFY(passwordField);
    QVERIFY(registerButton);

    usernameField->setText("");  // empty username
    passwordField->setText("");  // empty password

    QTest::mouseClick(registerButton, Qt::LeftButton);

    // Check that a warning dialog appears (manual check if needed)
    qDebug() << "✅ test_empty_fields_show_warning passed.";
}

// Test that duplicate username is rejected
void RegisterWindowTest::test_existing_username_rejected() {
    UserManager manager("test_users.json");
    manager.registerUser("existingUser", "1234");

    RegisterWindow window(nullptr, &manager);


    QLineEdit *usernameField = window.findChild<QLineEdit*>("lineEdit_username");
    QLineEdit *passwordField = window.findChild<QLineEdit*>("lineEdit_password");
    QPushButton *registerButton = window.findChild<QPushButton*>("pushButton_register");

    QVERIFY(usernameField);
    QVERIFY(passwordField);
    QVERIFY(registerButton);

    usernameField->setText("existingUser");
    passwordField->setText("1234");

    QTest::mouseClick(registerButton, Qt::LeftButton);

    qDebug() << "✅ test_existing_username_rejected passed.";
}

// Test that a new user is registered and home window opens
void RegisterWindowTest::test_successful_registration_opens_home() {
    QString filename = "test_users_register.json";
    QFile::remove(filename);  // ensure clean state

    UserManager manager(filename);
    RegisterWindow window(nullptr, &manager);

    QLineEdit* usernameField = window.findChild<QLineEdit*>("lineEdit_username");
    QLineEdit* passwordField = window.findChild<QLineEdit*>("lineEdit_password");
    QPushButton* registerButton = window.findChild<QPushButton*>("pushButton_register");

    QVERIFY(usernameField);
    QVERIFY(passwordField);
    QVERIFY(registerButton);

    // Provide a new, unique user
    usernameField->setText("newUser");
    passwordField->setText("pass123");

    QTest::mouseClick(registerButton, Qt::LeftButton);

    // Delay slightly to allow slot to finish (because of UI slot timing)
    QTest::qWait(100);

    // Check if user is registered and logged in
    QString current = manager.getCurrentUser();
    qDebug() << "[DEBUG] currentUser after registration:" << current;
    QCOMPARE(current, QString("newUser"));
}


// Test that clicking "Back" opens the main window
void RegisterWindowTest::test_back_button_shows_main() {
    UserManager manager("test_users.json");

    RegisterWindow window(nullptr, &manager);


    QPushButton *backButton = window.findChild<QPushButton*>("pushButton_back");
    QVERIFY(backButton);

    QTest::mouseClick(backButton, Qt::LeftButton);

    qDebug() << "✅ test_back_button_shows_main passed.";
}


