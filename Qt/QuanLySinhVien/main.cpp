#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.AddStudent("Pham The A","20/11/2000","Class 1");
    w.AddStudent("Pham The B","20/11/2000","Class 1");
    w.AddStudent("Pham The C","20/11/2000","Class 1");
    w.AddStudent("Pham The D","20/11/2000","Class 1");

    w.show();
    return a.exec();
}
