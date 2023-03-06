#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "student.h"
#include<QString>
#include<QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QListWidgetItem;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void AddStudent(Student* student);
    void AddStudent(QString name);
    void AddStudent(QString name, QString dob, QString className);

    void RemoveStudent(Student* student);

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    QVector<Student*> m_Students;
};
#endif // WIDGET_H
