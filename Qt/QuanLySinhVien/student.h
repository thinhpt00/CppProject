#ifndef STUDENT_H
#define STUDENT_H

#include<QListWidgetItem>
#include<QString>

class Student : public QListWidgetItem
{
public:
    Student();
    Student(QString name);
    Student(QString name, QString dob, QString className);
    QString GetName() const;
    QString GetDOB() const;
    QString GetClass() const;

    void SetClass(QString className);
    void SetDOB(QString dob);
    void SetName(QString name);

private:
    QString m_DOB;
    QString m_Class;
};

inline void Student::SetName(QString name){
    QListWidgetItem::setText(name);
}

inline void Student::SetClass(QString className){
    m_Class = className;
}

inline void Student::SetDOB(QString dob){
    m_DOB = dob;
}

inline QString Student::GetName() const{
    return QListWidgetItem::text();
}

inline QString Student::GetDOB() const{
    return m_DOB;
}

inline QString Student::GetClass() const{
    return m_Class;
}

#endif // STUDENT_H
