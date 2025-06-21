QT += testlib widgets core gui
TEMPLATE = app
CONFIG += console c++11 testcase
CONFIG -= app_bundle
DEFINES += UNIT_TESTING

# Relative paths - TicTacToe_design is at the same level as tictactoe_test
TICTACTOE_BASE = ../TicTacToe_design

INCLUDEPATH += $$TICTACTOE_BASE

SOURCES += \
    main.cpp \
    mockgamewindow.cpp \
    tst_difficultywindow.cpp \
    tst_gamewindow.cpp \
    $$TICTACTOE_BASE/gamewindow.cpp \
    $$TICTACTOE_BASE/usermanager.cpp \
    $$TICTACTOE_BASE/difficultywindow.cpp \
    $$TICTACTOE_BASE/historywindow.cpp \
    $$TICTACTOE_BASE/security.cpp \
    $$TICTACTOE_BASE/registerwindow.cpp \
    $$TICTACTOE_BASE/playmodewindow.cpp \
    $$TICTACTOE_BASE/homewindow.cpp \
    $$TICTACTOE_BASE/mainwindow.cpp \
    tst_historywindow.cpp \
    tst_registerwindow.cpp \
    tst_security.cpp \
    tst_usermanager.cpp

HEADERS += \
    $$TICTACTOE_BASE/gamewindow.h \
    $$TICTACTOE_BASE/usermanager.h \
    $$TICTACTOE_BASE/difficultywindow.h \
    $$TICTACTOE_BASE/historywindow.h \
    $$TICTACTOE_BASE/registerwindow.h \
    $$TICTACTOE_BASE/homewindow.h \
    $$TICTACTOE_BASE/mainwindow.h \
    $$TICTACTOE_BASE/security.h \
    mockgamewindow.h \
    tst_difficultywindow.h \
    $$TICTACTOE_BASE/playmodewindow.h \
    tst_historywindow.h \
    tst_registerwindow.h

FORMS += \
    $$TICTACTOE_BASE/gamewindow.ui \
    $$TICTACTOE_BASE/historywindow.ui \
    $$TICTACTOE_BASE/registerwindow.ui \
    $$TICTACTOE_BASE/homewindow.ui \
    $$TICTACTOE_BASE/mainwindow.ui \
    $$TICTACTOE_BASE/playmodewindow.ui \
    $$TICTACTOE_BASE/difficultywindow.ui

# Ensure Meta-Object Compiler (moc) works
CONFIG += moc_predefs depend_includepath
CONFIG += console
