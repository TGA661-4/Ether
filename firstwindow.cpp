#include "firstwindow.h"
#include "ui_firstwindow.h"

FirstWindow::FirstWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
}

FirstWindow::~FirstWindow()
{
    delete ui;
}

void FirstWindow::on_view_button_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Выбирете файл");
    ui->file_line->setText(file_name);
}

void FirstWindow::on_go_button_clicked()
{
    go_analis(ui->file_line->text());
}

void FirstWindow::closewindow()
{
    this->close();
}
