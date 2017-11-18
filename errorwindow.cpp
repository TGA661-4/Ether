#include "errorwindow.h"
#include "ui_errorwindow.h"

ErrorWindow::ErrorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorWindow)
{
    ui->setupUi(this);
}

ErrorWindow::~ErrorWindow()
{
    delete ui;
}

void ErrorWindow::out()
{
    ui->label->setText("Ошибка чтения файла");
    this->show();
}

void ErrorWindow::waitWindow()
{
    ui->label->setText("Пожалуйста, подождите");
    this->show();
}

void ErrorWindow::closeWindow()
{
    this->close();
}
