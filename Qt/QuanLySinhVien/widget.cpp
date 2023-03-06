#include "widget.h"
#include "./ui_widget.h"
#include "student.h"
#include "studentdialog.h"
#include<QListWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_StudentDialog = new StudentDialog;
    //m_StudentDialog->show();

//    Student* student = new Student();
//    student->SetName("Pham The Thinh");
//    student->SetDOB("08/08/2000");
//    student->SetClass("Class 2");

//    ui->listWidget->addItem((QListWidgetItem*) student);
}

void Widget::AddStudent(Student *student){
    ui->listWidget->addItem((QListWidgetItem*) student);
    m_Students.push_back(student);
}

void Widget::AddStudent(QString name){
    Student* student = new Student(name);
    AddStudent(student);
}

void Widget::AddStudent(QString name, QString dob, QString className){
    Student* student = new Student(name,dob,className);
    AddStudent(student);
}

void Widget::RemoveStudent(Student *student){
    ui->listWidget->removeItemWidget(student);
    for(int i = 0; i < m_Students.size(); i++){
        if(m_Students[i] == student){
            m_Students.remove(i);
            delete student;
        }
    }
}

void Widget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    m_StudentDialog->Show((Student*) item);
//    Student* student = (Student*) item;
//    ui->studentName->setText(student->GetName());
//    ui->studentDOB->setText(student->GetDOB());
//    ui->studentClass->setText(student->GetClass());
}

Widget::~Widget()
{
    for(int i = 0; i < m_Students.size(); i++){
        RemoveStudent(m_Students[i]);
    }
    delete ui;
    delete m_StudentDialog;
}

void Widget::on_pushButton_2_clicked()
{
    RemoveStudent((Student*)ui->listWidget->currentItem());
}


void Widget::on_pushButton_clicked()
{
    AddStudent("hhhhhhhhhhh");
}

