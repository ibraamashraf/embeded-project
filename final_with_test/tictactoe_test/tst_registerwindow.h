#ifndef TST_REGISTERWINDOW_H
#define TST_REGISTERWINDOW_H

#include <QObject>

class RegisterWindowTest : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void test_empty_fields_show_warning();
    void test_existing_username_rejected();
    void test_successful_registration_opens_home();
    void test_back_button_shows_main();
};

#endif // TST_REGISTERWINDOW_H
