#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

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
#include <QFileDialog>

namespace Ui {
class FirstWindow;
}

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = 0);
    ~FirstWindow();

private slots:
    void on_view_button_clicked();
    void on_go_button_clicked();

private:
    Ui::FirstWindow *ui;

signals:
    void go_analis(QString str);
public slots:
    void closewindow();
};

#endif // FIRSTWINDOW_H
