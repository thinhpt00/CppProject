#include "studentdialog.h"
#include "ui_studentdialog.h"
#include "student.h"

StudentDialog::StudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentDialog)
{
    ui->setupUi(this);

    setWindowTitle(QString::fromUtf8("Thông tin sinh viên"));
}

void StudentDialog::Show(Student *student){
    ui->name->setText(student->GetName());
    ui->dob->setText(student->GetDOB());
    ui->className->setText(student->GetClass());

    m_Student = student;

    show();
}
StudentDialog::~StudentDialog()
{
    delete ui;
}

void StudentDialog::on_pushButton_released()
{
    m_Student->SetName(ui->name->text());
    m_Student->SetDOB(ui->dob->text());
    m_Student->SetClass(ui->className->text());

    hide();
}


void StudentDialog::on_pushButton_2_clicked()
{
    hide();
}

