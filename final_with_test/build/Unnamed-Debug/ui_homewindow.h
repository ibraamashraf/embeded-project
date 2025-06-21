/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_play;
    QPushButton *pushButton_history;
    QPushButton *pushButton_exit;

    void setupUi(QDialog *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName("HomeWindow");
        HomeWindow->resize(689, 425);
        verticalLayoutWidget = new QWidget(HomeWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(240, 140, 160, 86));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_play = new QPushButton(verticalLayoutWidget);
        pushButton_play->setObjectName("pushButton_play");

        verticalLayout->addWidget(pushButton_play);

        pushButton_history = new QPushButton(verticalLayoutWidget);
        pushButton_history->setObjectName("pushButton_history");

        verticalLayout->addWidget(pushButton_history);

        pushButton_exit = new QPushButton(verticalLayoutWidget);
        pushButton_exit->setObjectName("pushButton_exit");

        verticalLayout->addWidget(pushButton_exit);


        retranslateUi(HomeWindow);

        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QDialog *HomeWindow)
    {
        HomeWindow->setWindowTitle(QCoreApplication::translate("HomeWindow", "Dialog", nullptr));
        pushButton_play->setText(QCoreApplication::translate("HomeWindow", "play", nullptr));
        pushButton_history->setText(QCoreApplication::translate("HomeWindow", "history", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("HomeWindow", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
