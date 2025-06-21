#include <QtTest/QtTest>
#include <QString>
#include <QDebug>
#include <QPushButton>

#include "gamewindow.h"
#include "usermanager.h"

// Subclass GameWindow to access protected members
class TestableGameWindow : public GameWindow {
public:
    using GameWindow::checkWin;
    using GameWindow::resetBoard;
    using GameWindow::buttons;
    using GameWindow::movesCount;
    using GameWindow::player1Turn;
    using GameWindow::makeAIMove;


    TestableGameWindow(GameMode mode, int difficulty, UserManager* manager, const QString& username, QWidget* parent = nullptr)
        : GameWindow(mode, difficulty, manager, username, parent) {}
};

class GameWindowTest : public QObject {
    Q_OBJECT

private slots:
    // UI Tests
    void test_button_click_marks_X();
    void test_all_buttons_clickable();
    void test_prevent_double_click();
    void test_alternate_turns();
    void test_clicking_disabled_button_has_no_effect();
    // Logic Tests
    void test_board_reset();
    void test_all_horizontal_wins();
    void test_all_vertical_wins();
    void test_all_diagonal_wins();
    void test_no_win_on_empty_board();
    void test_all_draw_permutations();

    void test_ai_hard_blocks_many_player_win_cases();
};

// ✅ UI Test 1: One button click should mark X
void GameWindowTest::test_button_click_marks_X() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");
    window.buttons[0]->click();
    QCOMPARE(window.buttons[0]->text(), "X");
    qDebug() << "✅ UI Test 1 passed: Button marks X";
}

// ✅ UI Test 2: All buttons should be clickable
void GameWindowTest::test_all_buttons_clickable() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");

    for (int i = 0; i < 9; ++i) {
        QVERIFY(window.buttons[i]->isEnabled());
        window.buttons[i]->click();
        QVERIFY(!window.buttons[i]->text().isEmpty());
        window.resetBoard(); // Reset before next click
    }

    qDebug() << "✅ UI Test 2 passed: All buttons clickable and responsive";
}
// UI Test 3 - Prevent double-click
void GameWindowTest::test_prevent_double_click() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");
    window.buttons[0]->click(); // Player 1 (X)
    QString firstClick = window.buttons[0]->text();
    window.buttons[0]->click(); // Try again
    QCOMPARE(window.buttons[0]->text(), firstClick); // Should remain X
    qDebug() << "✅ UI Test 3 passed: Double click did not overwrite";
}
// UI Test 4 - Prevent test_alternate_turns
void GameWindowTest::test_alternate_turns() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");
    window.buttons[0]->click();
    QCOMPARE(window.buttons[0]->text(), "X");
    window.buttons[1]->click();
    QCOMPARE(window.buttons[1]->text(), "O");
    window.buttons[2]->click();
    QCOMPARE(window.buttons[2]->text(), "X");
    qDebug() << "✅ UI Test 4 passed: Turns alternate correctly";
}
// UI Test 5 - test_restart_button_clears_ui


// UI Test 5 -test_clicking_disabled_button_has_no_effect
void GameWindowTest::test_clicking_disabled_button_has_no_effect() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");

    window.buttons[0]->click(); // X
    window.buttons[0]->setEnabled(false);
    QString before = window.buttons[0]->text();
    window.buttons[0]->click();
    QCOMPARE(window.buttons[0]->text(), before);

    qDebug() << "✅ UI Test passed: Clicking disabled button has no effect";
}

// ✅ Logic Test 1: Reset should clear all buttons
void GameWindowTest::test_board_reset() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");

    window.buttons[0]->setText("X");
    window.buttons[1]->setText("O");

    window.resetBoard();

    for (int i = 0; i < 9; ++i) {
        QCOMPARE(window.buttons[i]->text(), "");
        QVERIFY(window.buttons[i]->isEnabled());
    }

    qDebug() << "✅ Logic Test 1 passed: Board reset cleared all cells";
}
// ✅ Logic Test 2: Horizontal wins detection
void GameWindowTest::test_all_horizontal_wins() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");
    for (int row = 0; row < 3; ++row) {
        window.resetBoard();
        for (int i = 0; i < 3; ++i)
            window.buttons[row * 3 + i]->setText("X");
        QCOMPARE(window.checkWin(), 1);
    }
    qDebug() << "✅ Logic Test passed: All horizontal win conditions detected";
}


// Logic Test 3 - Vertical wins
void GameWindowTest::test_all_vertical_wins() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");
    for (int col = 0; col < 3; ++col) {
        window.resetBoard();
        for (int i = 0; i < 3; ++i)
            window.buttons[i * 3 + col]->setText("O");
        QCOMPARE(window.checkWin(), 2);
    }
    qDebug() << "✅ Logic Test passed: All vertical win conditions detected";
}
void GameWindowTest::test_all_diagonal_wins() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");
    // Major diagonal
    window.resetBoard();
    window.buttons[0]->setText("X");
    window.buttons[4]->setText("X");
    window.buttons[8]->setText("X");
    QCOMPARE(window.checkWin(), 1);

    // Minor diagonal
    window.resetBoard();
    window.buttons[2]->setText("X");
    window.buttons[4]->setText("X");
    window.buttons[6]->setText("X");
    QCOMPARE(window.checkWin(), 1);

    qDebug() << "✅ Logic Test passed: All diagonal win conditions detected";
}
// Logic Test 5 - No win when board is empty
void GameWindowTest::test_no_win_on_empty_board() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");
    QCOMPARE(window.checkWin(), 0); // No winner
    qDebug() << "✅ Logic Test 5 passed: No win on empty board";
}
// Logic Test 6 - draw case
void GameWindowTest::test_all_draw_permutations() {
    TestableGameWindow window(PvP, 1, nullptr, "Ahmed");

    QStringList symbols = {"X", "O"};
    QVector<int> indices = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    int drawCount = 0;
    auto isDraw = [](const QStringList& board) {
        return !board.contains("") && !(board[0] == board[1] && board[1] == board[2]) &&
               !(board[3] == board[4] && board[4] == board[5]) &&
               !(board[6] == board[7] && board[7] == board[8]) &&
               !(board[0] == board[3] && board[3] == board[6]) &&
               !(board[1] == board[4] && board[4] == board[7]) &&
               !(board[2] == board[5] && board[5] == board[8]) &&
               !(board[0] == board[4] && board[4] == board[8]) &&
               !(board[2] == board[4] && board[4] == board[6]);
    };

    std::function<void(QStringList, int)> generate = [&](QStringList board, int depth) {
        if (depth == 9) {
            if (isDraw(board)) {
                for (int i = 0; i < 9; ++i)
                    window.buttons[i]->setText(board[i]);
                if (window.checkWin() == 0)
                    ++drawCount;
                else
                    QFAIL(qPrintable("False positive: win detected in supposed draw: " + board.join(",")));
            }
            return;
        }
        for (const QString& s : symbols) {
            board[depth] = s;
            generate(board, depth + 1);
        }
    };

    generate(QStringList{"", "", "", "", "", "", "", "", ""}, 0);
    qDebug() << "✅ Logic Test (All Draws) passed:" << drawCount << "draw patterns verified.";
}

void GameWindowTest::test_ai_hard_blocks_many_player_win_cases() {
    struct BlockCase {
        int playerX1;
        int playerX2;
        int aiShouldBlock;
    };
        const QVector<BlockCase> cases = {
                     // Rows
                     {0, 1, 2}, {1, 2, 0}, {0, 2, 1},
                     {3, 4, 5}, {4, 5, 3}, {3, 5, 4},
                     {6, 7, 8}, {7, 8, 6}, {6, 8, 7},
                     // Columns
                     {0, 3, 6}, {3, 6, 0}, {0, 6, 3},
                     {1, 4, 7}, {4, 7, 1}, {1, 7, 4},
                     {2, 5, 8}, {5, 8, 2}, {2, 8, 5},
                     // Diagonals
                     {0, 4, 8}, {4, 8, 0}, {0, 8, 4},
                     {2, 4, 6}, {4, 6, 2}, {2, 6, 4},
                     };

    for (const BlockCase& bc : cases) {
        TestableGameWindow window(PvAI, 3, nullptr, "testUser");
        window.show();
        QTest::qWaitForWindowExposed(&window);

        window.resetBoard();
        window.buttons[bc.playerX1]->setText("X");
        window.buttons[bc.playerX2]->setText("X");
        window.buttons[bc.playerX1]->setEnabled(false);
        window.buttons[bc.playerX2]->setEnabled(false);
        window.player1Turn = false;
        window.movesCount = 2;

        window.makeAIMove();

        QString actual = window.buttons[bc.aiShouldBlock]->text();
        QVERIFY2(actual == "O", qPrintable(
                                    QString("❌ AI failed to block player win at index %1 for case [%2, %3]. Actual value: '%4'")
                                        .arg(bc.aiShouldBlock)
                                        .arg(bc.playerX1)
                                        .arg(bc.playerX2)
                                        .arg(actual)
                                    ));
        qDebug() << QString("✅ Blocked player win at index %1 for case [%2, %3]")
                        .arg(bc.aiShouldBlock)
                        .arg(bc.playerX1)
                        .arg(bc.playerX2);
    }
}

#include "tst_gamewindow.moc"
