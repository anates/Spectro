/********************************************************************************
** Form generated from reading UI file 'logfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGFILEDIALOG_H
#define UI_LOGFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LogFileDialog
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *LogName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *LogSlit1;
    QLabel *label_6;
    QLineEdit *LogSlit2;
    QLabel *label_7;
    QLineEdit *LogSlit3;
    QLabel *label_8;
    QLineEdit *LogSlit4;
    QLineEdit *LogPower;
    QLineEdit *LogSens;
    QHBoxLayout *horizontalLayout;
    QPushButton *LogConfirm;
    QPushButton *LogCancel;

    void setupUi(QDialog *LogFileDialog)
    {
        if (LogFileDialog->objectName().isEmpty())
            LogFileDialog->setObjectName(QStringLiteral("LogFileDialog"));
        LogFileDialog->resize(400, 300);
        gridLayout = new QGridLayout(LogFileDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(LogFileDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(LogFileDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(LogFileDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(LogFileDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        LogName = new QLineEdit(LogFileDialog);
        LogName->setObjectName(QStringLiteral("LogName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, LogName);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(LogFileDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        LogSlit1 = new QLineEdit(LogFileDialog);
        LogSlit1->setObjectName(QStringLiteral("LogSlit1"));

        horizontalLayout_2->addWidget(LogSlit1);

        label_6 = new QLabel(LogFileDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        LogSlit2 = new QLineEdit(LogFileDialog);
        LogSlit2->setObjectName(QStringLiteral("LogSlit2"));

        horizontalLayout_2->addWidget(LogSlit2);

        label_7 = new QLabel(LogFileDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        LogSlit3 = new QLineEdit(LogFileDialog);
        LogSlit3->setObjectName(QStringLiteral("LogSlit3"));

        horizontalLayout_2->addWidget(LogSlit3);

        label_8 = new QLabel(LogFileDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        LogSlit4 = new QLineEdit(LogFileDialog);
        LogSlit4->setObjectName(QStringLiteral("LogSlit4"));

        horizontalLayout_2->addWidget(LogSlit4);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        LogPower = new QLineEdit(LogFileDialog);
        LogPower->setObjectName(QStringLiteral("LogPower"));

        formLayout->setWidget(1, QFormLayout::FieldRole, LogPower);

        LogSens = new QLineEdit(LogFileDialog);
        LogSens->setObjectName(QStringLiteral("LogSens"));

        formLayout->setWidget(3, QFormLayout::FieldRole, LogSens);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        LogConfirm = new QPushButton(LogFileDialog);
        LogConfirm->setObjectName(QStringLiteral("LogConfirm"));

        horizontalLayout->addWidget(LogConfirm);

        LogCancel = new QPushButton(LogFileDialog);
        LogCancel->setObjectName(QStringLiteral("LogCancel"));

        horizontalLayout->addWidget(LogCancel);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(LogFileDialog);

        QMetaObject::connectSlotsByName(LogFileDialog);
    } // setupUi

    void retranslateUi(QDialog *LogFileDialog)
    {
        LogFileDialog->setWindowTitle(QApplication::translate("LogFileDialog", "Dialog", 0));
        label->setText(QApplication::translate("LogFileDialog", "Log name", 0));
        label_2->setText(QApplication::translate("LogFileDialog", "Laser power [mW]", 0));
        label_3->setText(QApplication::translate("LogFileDialog", "Slit width", 0));
        label_4->setText(QApplication::translate("LogFileDialog", "Sensitivity", 0));
        label_5->setText(QApplication::translate("LogFileDialog", "1", 0));
        label_6->setText(QApplication::translate("LogFileDialog", "2", 0));
        label_7->setText(QApplication::translate("LogFileDialog", "3", 0));
        label_8->setText(QApplication::translate("LogFileDialog", "4", 0));
        LogConfirm->setText(QApplication::translate("LogFileDialog", "Ok", 0));
        LogCancel->setText(QApplication::translate("LogFileDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class LogFileDialog: public Ui_LogFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGFILEDIALOG_H
