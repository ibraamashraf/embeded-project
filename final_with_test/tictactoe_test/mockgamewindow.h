#ifndef MOCKGAMEWINDOW_H
#define MOCKGAMEWINDOW_H

#include "../TicTacToe_design/gamewindow.h"
#include <QDebug>

// ✅ Inherits from GameWindow to match expected pointer type
class MockGameWindow : public GameWindow {
    Q_OBJECT

public:
    static int lastDifficulty;

    static void reset() {
        lastDifficulty = -1;
    }

    // ✅ Constructor matches GameWindow signature but uses dummy values
    MockGameWindow(int difficulty, QWidget* parent = nullptr)
        : GameWindow(PvAI, difficulty, nullptr, "MockUser", parent)
    {
        lastDifficulty = difficulty;
        qDebug() << "📦 MockGameWindow created with difficulty:" << difficulty;
    }

    int exec() override {
        qDebug() << "▶️ Mock exec() called";
        return QDialog::Accepted;  // Simulate dialog being accepted
    }
};

#endif // MOCKGAMEWINDOW_H
