#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

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

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();
private:
    Ui::SecondWindow *ui;
public slots:
    void outFirst(name n);
    void outSecond(QVector <packets> p);
signals:
    void closeWaitWindow();
};

#endif // SECONDWINDOW_H
