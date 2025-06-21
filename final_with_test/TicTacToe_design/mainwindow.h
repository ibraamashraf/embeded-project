#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "usermanager.h"
#include "registerwindow.h"  // ✅ Include the registration window

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();  // ✅ This is all you need

private:
    Ui::MainWindow *ui;
    UserManager* userManager;
    RegisterWindow* registerWindow = nullptr;
};

#endif // MAINWINDOW_H
