#include "widget.h"
#include "./ui_widget.h"
#include "student.h"
#include<QListWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Student* student = new Student();
    student->SetName("Pham The Thinh");
    student->SetDOB("08/08/2000");
    student->SetClass("Class 2");

    ui->listWidget->addItem((QListWidgetItem*) student);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    Student* student = (Student*) item;
    ui->studentName->setText(student->GetName());
    ui->studentDOB->setText(student->GetDOB());
    ui->studentClass->setText(student->GetClass());
}

