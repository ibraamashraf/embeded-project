#ifndef TST_HISTORYWINDOW_H
#define TST_HISTORYWINDOW_H

#include <QObject>

class HistoryWindowTest : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void test_display_history_items();
    void test_display_empty_history();
    void test_close_button_closes_window();
};

#endif // TST_HISTORYWINDOW_H
