#include "tst_historywindow.h"
#include <QtTest>
#include <QPushButton>
#include <QListWidget>

#include "../TicTacToe_design/historywindow.h"
#include "../TicTacToe_design/usermanager.h"

static QString dummyFile = "temp_history_test.json";
static UserManager* dummyManager = nullptr;

void HistoryWindowTest::initTestCase() {
    dummyManager = new UserManager(dummyFile);

    // Pre-register user with fake history
    dummyManager->registerUser("testUser", "testPass");
    dummyManager->recordGameResult("win");
    dummyManager->recordGameResult("loss");
    dummyManager->recordGameResult("draw");

    // Add a second user with no history
    dummyManager->registerUser("emptyUser", "emptyPass");
}

// ✅ Test if history entries are shown in listWidget
void HistoryWindowTest::test_display_history_items() {
    HistoryWindow window(dummyManager, "testUser");
    QListWidget* list = window.findChild<QListWidget*>("listWidget_history");
    QVERIFY2(list, "listWidget_history not found!");

    window.show();
    QTest::qWait(100);  // Allow UI to load

    QCOMPARE(list->count(), 3);
    QCOMPARE(list->item(0)->text(), "win");
    QCOMPARE(list->item(1)->text(), "loss");
    QCOMPARE(list->item(2)->text(), "draw");
}

// ✅ Test when history is empty
void HistoryWindowTest::test_display_empty_history() {
    HistoryWindow window(dummyManager, "emptyUser");
    QListWidget* list = window.findChild<QListWidget*>("listWidget_history");
    QVERIFY2(list, "listWidget_history not found!");

    window.show();
    QTest::qWait(100);

    QCOMPARE(list->count(), 1);
    QCOMPARE(list->item(0)->text(), "No games played yet.");
}

// ✅ Test close button
void HistoryWindowTest::test_close_button_closes_window() {
    HistoryWindow window(dummyManager, "testUser");
    QPushButton* closeBtn = window.findChild<QPushButton*>("pushButton_close");
    QVERIFY2(closeBtn, "pushButton_close not found!");

    QTimer::singleShot(0, closeBtn, &QPushButton::click);
    window.show();

    QTest::qWait(200);
    QVERIFY(!window.isVisible());
}
