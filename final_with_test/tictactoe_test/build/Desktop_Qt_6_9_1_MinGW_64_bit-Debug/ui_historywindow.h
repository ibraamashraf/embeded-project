/********************************************************************************
** Form generated from reading UI file 'historywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYWINDOW_H
#define UI_HISTORYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HistoryWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_username;
    QListWidget *listWidget_history;
    QPushButton *pushButton_close;

    void setupUi(QDialog *HistoryWindow)
    {
        if (HistoryWindow->objectName().isEmpty())
            HistoryWindow->setObjectName("HistoryWindow");
        HistoryWindow->resize(735, 378);
        verticalLayout = new QVBoxLayout(HistoryWindow);
        verticalLayout->setObjectName("verticalLayout");
        label_username = new QLabel(HistoryWindow);
        label_username->setObjectName("label_username");
        QFont font;
        font.setPointSize(12);
        label_username->setFont(font);

        verticalLayout->addWidget(label_username);

        listWidget_history = new QListWidget(HistoryWindow);
        listWidget_history->setObjectName("listWidget_history");

        verticalLayout->addWidget(listWidget_history);

        pushButton_close = new QPushButton(HistoryWindow);
        pushButton_close->setObjectName("pushButton_close");

        verticalLayout->addWidget(pushButton_close);


        retranslateUi(HistoryWindow);

        QMetaObject::connectSlotsByName(HistoryWindow);
    } // setupUi

    void retranslateUi(QDialog *HistoryWindow)
    {
        HistoryWindow->setWindowTitle(QCoreApplication::translate("HistoryWindow", "Dialog", nullptr));
        label_username->setText(QCoreApplication::translate("HistoryWindow", "Username:", nullptr));
        pushButton_close->setText(QCoreApplication::translate("HistoryWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryWindow: public Ui_HistoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYWINDOW_H
