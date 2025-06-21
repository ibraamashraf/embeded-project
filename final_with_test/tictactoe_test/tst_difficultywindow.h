#ifndef TST_DIFFICULTYWINDOW_H
#define TST_DIFFICULTYWINDOW_H

#include <QObject>

class DifficultyWindowTest : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void test_easy_button_launches_game();
    void test_medium_button_launches_game();
    void test_hard_button_launches_game();
};

#endif // TST_DIFFICULTYWINDOW_H
