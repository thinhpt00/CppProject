#include "student.h"

Student::Student(){

}

Student::Student(QString name)
    : QListWidgetItem(name)
{

}

Student::Student(QString name, QString dob, QString className)
    :QListWidgetItem(name), m_DOB(dob), m_Class(className)
{

}
