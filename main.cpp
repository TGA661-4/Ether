#include "firstwindow.h"
#include "secondwindow.h"
#include "sniffer.h"
#include "errorwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstWindow *w1 = new FirstWindow;
    SecondWindow *w2 = new SecondWindow;
    sniffer *s = new sniffer;
    ErrorWindow *e = new ErrorWindow;
    QObject::connect(w1, SIGNAL(go_analis(QString)), s, SLOT(analis(QString)));
    QObject::connect(s, SIGNAL(out(QString)), w2, SLOT(out(QString)));
    QObject::connect(s, SIGNAL(errorour()), e, SLOT(out()));
    QObject::connect(s, SIGNAL(outFirst(name)), w2, SLOT(outFirst(name)));
    QObject::connect(s, SIGNAL(outSecond(QVector<packets>)), w2, SLOT(outSecond(QVector<packets>)));
    //QObject::connect(s, SIGNAL(waitWindow()), e, SLOT(waitWindow()));
    //QObject::connect(w2, SIGNAL(closeWaitWindow()), e, SLOT(closeWindow()));
    w1->show();

    return a.exec();
}
