/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *button_20;
    QPushButton *button_00;
    QPushButton *button_10;
    QPushButton *button_01;
    QPushButton *button_02;
    QPushButton *button_11;
    QPushButton *button_12;
    QPushButton *button_21;
    QPushButton *button_22;
    QPushButton *button_restart;
    QPushButton *button_back;
    QLabel *label_turn;

    void setupUi(QDialog *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName("GameWindow");
        GameWindow->resize(703, 300);
        gridLayoutWidget = new QWidget(GameWindow);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(230, 80, 254, 86));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        button_20 = new QPushButton(gridLayoutWidget);
        button_20->setObjectName("button_20");

        gridLayout->addWidget(button_20, 2, 0, 1, 1);

        button_00 = new QPushButton(gridLayoutWidget);
        button_00->setObjectName("button_00");

        gridLayout->addWidget(button_00, 0, 0, 1, 1);

        button_10 = new QPushButton(gridLayoutWidget);
        button_10->setObjectName("button_10");

        gridLayout->addWidget(button_10, 1, 0, 1, 1);

        button_01 = new QPushButton(gridLayoutWidget);
        button_01->setObjectName("button_01");

        gridLayout->addWidget(button_01, 0, 1, 1, 1);

        button_02 = new QPushButton(gridLayoutWidget);
        button_02->setObjectName("button_02");

        gridLayout->addWidget(button_02, 0, 2, 1, 1);

        button_11 = new QPushButton(gridLayoutWidget);
        button_11->setObjectName("button_11");

        gridLayout->addWidget(button_11, 1, 1, 1, 1);

        button_12 = new QPushButton(gridLayoutWidget);
        button_12->setObjectName("button_12");

        gridLayout->addWidget(button_12, 1, 2, 1, 1);

        button_21 = new QPushButton(gridLayoutWidget);
        button_21->setObjectName("button_21");

        gridLayout->addWidget(button_21, 2, 1, 1, 1);

        button_22 = new QPushButton(gridLayoutWidget);
        button_22->setObjectName("button_22");

        gridLayout->addWidget(button_22, 2, 2, 1, 1);

        button_restart = new QPushButton(GameWindow);
        button_restart->setObjectName("button_restart");
        button_restart->setGeometry(QRect(410, 180, 80, 24));
        button_back = new QPushButton(GameWindow);
        button_back->setObjectName("button_back");
        button_back->setGeometry(QRect(230, 180, 80, 24));
        label_turn = new QLabel(GameWindow);
        label_turn->setObjectName("label_turn");
        label_turn->setGeometry(QRect(330, 40, 49, 16));

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QDialog *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "Dialog", nullptr));
        button_20->setText(QCoreApplication::translate("GameWindow", "PushButton", nullptr));
        button_00->setText(QCoreApplication::translate("GameWindow", "PushButton", nullptr));
        button_10->setText(QCoreApplication::translate("GameWindow", "PushButton", nullptr));
        button_01->setText(QCoreApplication::translate("GameWindow", "PushButton", nullptr));
        button_02->setText(QCoreApplication::translate("GameWindow", "PushButton", nullptr));
        button_11->setText(QCoreApplication::translate("GameWindow", "PushButton", nullptr));
        button_12->setText(QCoreApplication::translate("GameWindow", "PushButton", nullptr));
        button_21->setText(QCoreApplication::translate("GameWindow", "PushButton", nullptr));
        button_22->setText(QCoreApplication::translate("GameWindow", "PushButton", nullptr));
        button_restart->setText(QCoreApplication::translate("GameWindow", "restart", nullptr));
        button_back->setText(QCoreApplication::translate("GameWindow", "back", nullptr));
        label_turn->setText(QCoreApplication::translate("GameWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
