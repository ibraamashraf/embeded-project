/********************************************************************************
** Form generated from reading UI file 'playmodewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYMODEWINDOW_H
#define UI_PLAYMODEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayModeWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_player;
    QPushButton *pushButton_ai;

    void setupUi(QDialog *PlayModeWindow)
    {
        if (PlayModeWindow->objectName().isEmpty())
            PlayModeWindow->setObjectName("PlayModeWindow");
        PlayModeWindow->resize(741, 427);
        verticalLayoutWidget = new QWidget(PlayModeWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(300, 170, 160, 86));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_player = new QPushButton(verticalLayoutWidget);
        pushButton_player->setObjectName("pushButton_player");

        verticalLayout->addWidget(pushButton_player);

        pushButton_ai = new QPushButton(verticalLayoutWidget);
        pushButton_ai->setObjectName("pushButton_ai");

        verticalLayout->addWidget(pushButton_ai);


        retranslateUi(PlayModeWindow);

        QMetaObject::connectSlotsByName(PlayModeWindow);
    } // setupUi

    void retranslateUi(QDialog *PlayModeWindow)
    {
        PlayModeWindow->setWindowTitle(QCoreApplication::translate("PlayModeWindow", "Dialog", nullptr));
        pushButton_player->setText(QCoreApplication::translate("PlayModeWindow", "player vs player", nullptr));
        pushButton_ai->setText(QCoreApplication::translate("PlayModeWindow", "play with Ai", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayModeWindow: public Ui_PlayModeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYMODEWINDOW_H
