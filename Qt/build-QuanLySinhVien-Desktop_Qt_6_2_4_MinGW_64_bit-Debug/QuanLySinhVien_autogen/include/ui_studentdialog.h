/********************************************************************************
** Form generated from reading UI file 'studentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDIALOG_H
#define UI_STUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudentDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *name;
    QLineEdit *dob;
    QLineEdit *className;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *StudentDialog)
    {
        if (StudentDialog->objectName().isEmpty())
            StudentDialog->setObjectName(QString::fromUtf8("StudentDialog"));
        StudentDialog->resize(240, 179);
        verticalLayout_5 = new QVBoxLayout(StudentDialog);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(StudentDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(StudentDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(StudentDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        name = new QLineEdit(StudentDialog);
        name->setObjectName(QString::fromUtf8("name"));

        verticalLayout->addWidget(name);

        dob = new QLineEdit(StudentDialog);
        dob->setObjectName(QString::fromUtf8("dob"));

        verticalLayout->addWidget(dob);

        className = new QLineEdit(StudentDialog);
        className->setObjectName(QString::fromUtf8("className"));

        verticalLayout->addWidget(className);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(StudentDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(StudentDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(StudentDialog);

        QMetaObject::connectSlotsByName(StudentDialog);
    } // setupUi

    void retranslateUi(QDialog *StudentDialog)
    {
        StudentDialog->setWindowTitle(QCoreApplication::translate("StudentDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("StudentDialog", "T\303\252n sinh vi\303\252n:", nullptr));
        label_2->setText(QCoreApplication::translate("StudentDialog", "Ng\303\240y sinh:", nullptr));
        label_3->setText(QCoreApplication::translate("StudentDialog", "L\341\273\233p:", nullptr));
        pushButton->setText(QCoreApplication::translate("StudentDialog", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StudentDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentDialog: public Ui_StudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDIALOG_H
