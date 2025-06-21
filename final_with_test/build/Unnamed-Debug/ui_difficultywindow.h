/********************************************************************************
** Form generated from reading UI file 'difficultywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTYWINDOW_H
#define UI_DIFFICULTYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DifficultyWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_easy;
    QPushButton *pushButton_medium;
    QPushButton *pushButton_hard;
    QPushButton *pushButton_back;

    void setupUi(QDialog *DifficultyWindow)
    {
        if (DifficultyWindow->objectName().isEmpty())
            DifficultyWindow->setObjectName("DifficultyWindow");
        DifficultyWindow->resize(766, 408);
        verticalLayoutWidget = new QWidget(DifficultyWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(280, 110, 160, 116));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_easy = new QPushButton(verticalLayoutWidget);
        pushButton_easy->setObjectName("pushButton_easy");

        verticalLayout->addWidget(pushButton_easy);

        pushButton_medium = new QPushButton(verticalLayoutWidget);
        pushButton_medium->setObjectName("pushButton_medium");

        verticalLayout->addWidget(pushButton_medium);

        pushButton_hard = new QPushButton(verticalLayoutWidget);
        pushButton_hard->setObjectName("pushButton_hard");

        verticalLayout->addWidget(pushButton_hard);

        pushButton_back = new QPushButton(verticalLayoutWidget);
        pushButton_back->setObjectName("pushButton_back");

        verticalLayout->addWidget(pushButton_back);


        retranslateUi(DifficultyWindow);

        QMetaObject::connectSlotsByName(DifficultyWindow);
    } // setupUi

    void retranslateUi(QDialog *DifficultyWindow)
    {
        DifficultyWindow->setWindowTitle(QCoreApplication::translate("DifficultyWindow", "Dialog", nullptr));
        pushButton_easy->setText(QCoreApplication::translate("DifficultyWindow", "easy", nullptr));
        pushButton_medium->setText(QCoreApplication::translate("DifficultyWindow", "meduim", nullptr));
        pushButton_hard->setText(QCoreApplication::translate("DifficultyWindow", "hard", nullptr));
        pushButton_back->setText(QCoreApplication::translate("DifficultyWindow", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DifficultyWindow: public Ui_DifficultyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTYWINDOW_H
