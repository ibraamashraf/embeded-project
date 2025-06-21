#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"
#include "homewindow.h"
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent, UserManager* manager)
    : QDialog(parent), ui(new Ui::RegisterWindow), userManager(manager)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username.isEmpty() || password.isEmpty()) {
#ifdef UNIT_TESTING
        qDebug() << "[Mocked QMessageBox] Warning: كل الخانات مطلوبة" ;
#else
        QMessageBox::warning(this, "خطأ", "كل الخانات مطلوبة");
#endif
        return;
    }

    if (userManager->registerUser(username, password)) {
#ifdef UNIT_TESTING
        qDebug() << "[Mocked QMessageBox] Info: تم إنشاء الحساب بنجاح";
#else
        QMessageBox::information(this, "تم", "تم إنشاء الحساب بنجاح");
#endif


        // ✅ Open HomeWindow and close this one
        HomeWindow* home = new HomeWindow(nullptr, userManager);
        home->show();
        this->close();

    } else {
#ifdef UNIT_TESTING
        qDebug() << "[Mocked QMessageBox] Warning: اسم المستخدم موجود بالفعل";
#else
        QMessageBox::warning(this, "خطأ", "اسم المستخدم موجود بالفعل");
#endif
    }
}


void RegisterWindow::on_pushButton_back_clicked()
{
    MainWindow *mainWin = new MainWindow(this); // ✅ FIX: only pass the parent
    mainWin->show();
    this->hide();
}
