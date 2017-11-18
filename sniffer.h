#ifndef SNIFFER_H
#define SNIFFER_H

#include <QDialog>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <cmath>
#include <algorithm>
#include <QLineEdit>
#include <QString>
#include <sstream>
#include <QChar>
#include <QVector>
#include <QFile>
#include "packets.h"

class sniffer : public QObject
{
    Q_OBJECT
private:
    name Name;
    QFile *file;
    QVector <packets> Packets;
public:
    sniffer();
public slots:
    void analis(QString str);
signals:
    void outFirst(name n);
    void outSecond(QVector <packets> p);
    void errorour();
    void waitWindow();
};

#endif // SNIFFER_H
