/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *listWidget;
    QLabel *studentName;
    QLabel *studentDOB;
    QLabel *studentClass;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(110, 170, 501, 281));
        studentName = new QLabel(Widget);
        studentName->setObjectName(QString::fromUtf8("studentName"));
        studentName->setGeometry(QRect(110, 90, 191, 20));
        studentDOB = new QLabel(Widget);
        studentDOB->setObjectName(QString::fromUtf8("studentDOB"));
        studentDOB->setGeometry(QRect(320, 90, 251, 20));
        studentClass = new QLabel(Widget);
        studentClass->setObjectName(QString::fromUtf8("studentClass"));
        studentClass->setGeometry(QRect(590, 90, 161, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        studentName->setText(QCoreApplication::translate("Widget", "Name", nullptr));
        studentDOB->setText(QCoreApplication::translate("Widget", "DOB", nullptr));
        studentClass->setText(QCoreApplication::translate("Widget", "Class", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
