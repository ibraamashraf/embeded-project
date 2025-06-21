#include "tst_difficultywindow.h"
#include <QtTest>
#include <QPushButton>
#include <QTimer>

#include "../TicTacToe_design/difficultywindow.h"
#include "../TicTacToe_design/usermanager.h"
#include "mockgamewindow.h"

static UserManager* dummyManager = nullptr;

void DifficultyWindowTest::initTestCase() {
    dummyManager = new UserManager("temp_dummy.json");
}

void DifficultyWindowTest::test_easy_button_launches_game() {
    MockGameWindow::reset();

    DifficultyWindow window("PvAI", dummyManager, "tester");
    auto* easyBtn = window.findChild<QPushButton*>("pushButton_easy");
    QVERIFY2(easyBtn, "❌ Easy button not found!");

    QTimer::singleShot(0, easyBtn, &QPushButton::click);
    window.show();
    QTest::qWait(200);

    QCOMPARE(MockGameWindow::lastDifficulty, 1);
}

void DifficultyWindowTest::test_medium_button_launches_game() {
    MockGameWindow::reset();

    DifficultyWindow window("PvAI", dummyManager, "tester");
    auto* btn = window.findChild<QPushButton*>("pushButton_medium");
    QVERIFY2(btn, "❌ Medium button not found!");

    QTimer::singleShot(0, btn, &QPushButton::click);
    window.show();
    QTest::qWait(200);

    QCOMPARE(MockGameWindow::lastDifficulty, 2);
}

void DifficultyWindowTest::test_hard_button_launches_game() {
    MockGameWindow::reset();

    DifficultyWindow window("PvAI", dummyManager, "tester");
    auto* btn = window.findChild<QPushButton*>("pushButton_hard");
    QVERIFY2(btn, "❌ Hard button not found!");

    QTimer::singleShot(0, btn, &QPushButton::click);
    window.show();
    QTest::qWait(200);

    QCOMPARE(MockGameWindow::lastDifficulty, 3);
}
