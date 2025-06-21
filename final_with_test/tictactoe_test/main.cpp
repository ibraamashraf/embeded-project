#include <QApplication>
#include <QTest>

#include "tst_gamewindow.cpp"
#include "tst_usermanager.cpp"
#include "tst_security.cpp"
#include "tst_difficultywindow.h"  // Only include the HEADER here
#include "tst_historywindow.h"
#include "tst_registerwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    int status = 0;

    {
        GameWindowTest test;
        status |= QTest::qExec(&test, argc, argv);
    }

    {
        UserManagerTest test;
        status |= QTest::qExec(&test, argc, argv);
    }

    {
        SecurityTest test;
        status |= QTest::qExec(&test, argc, argv);
    }

    {
        DifficultyWindowTest test;
        status |= QTest::qExec(&test, argc, argv);
    }

    {
        HistoryWindowTest test;
        status |= QTest::qExec(&test, argc, argv);
    }

    {
        RegisterWindowTest test;
        status |= QTest::qExec(&test, argc, argv);
    }

    return status;
}
