#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QDialog>

namespace Ui {
class ErrorWindow;
}

class ErrorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorWindow(QWidget *parent = 0);
    ~ErrorWindow();

private:
    Ui::ErrorWindow *ui;
public slots:
    void out();
    void waitWindow();
    void closeWindow();
};

#endif // ERRORWINDOW_H
