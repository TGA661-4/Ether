#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::outFirst(name n)
{
    ui->nameOfFile->setText("Файл: " + n.nameOfFile);
    ui->magic->setText("magic: " + QString::number(n.magic));
    ui->linkType->setText("link type: " + QString::number(n.linkType));
    ui->nomberOfpackets->setText("nomber of packets: " + QString::number(n.nomberOfPackets));
    ui->sigfigs->setText("sigfigs: " + QString::number(n.sigfigs));
    ui->snaplen->setText("snap length: " + QString::number(n.snaplen));
    ui->thisZone->setText("this zone: " + QString::number(n.thisZone));
    ui->versionMinor->setText("minor version: " + QString::number(n.versionMinor));
    ui->versionMojor->setText("mojor version: " + QString::number(n.versionMajor));
}

void SecondWindow::outSecond(QVector<packets> p)
{
    for(int i = 0; i < p.size(); i++)
    {
        ui->textEdit->append("Пакет №" + QString::number(i + 1));
        ui->textEdit->append("t1: " + QString::number(p[i].t1));
        ui->textEdit->append("t2: " + QString::number(p[i].t2));
        ui->textEdit->append("length: " + QString::number(p[i].len));
        ui->textEdit->append("captured length: " + QString::number(p[i].captureLen));
        if(p[i].isEth)
        {
             ui->textEdit->append("Ethernet:");
             ui->textEdit->append("Отправитель: " + p[i].ethOut);
             ui->textEdit->append("Получатель: " + p[i].ethIn);
             if(p[i].isIth)
             {
                 ui->textEdit->append("Internet: ");
                 ui->textEdit->append("Протокол: " + p[i].ithType);
                 ui->textEdit->append("IP Отправителя: " + p[i].ipIn);
                 ui->textEdit->append("IP Получателя: " + p[i].ipOut);
                 if(p[i].ithType == "TCPIP")
                 {
                     ui->textEdit->append("Порт отправителя: " + p[i].portOut);
                     ui->textEdit->append("Порт получателя: " + p[i].portIn);
                 }
             }
             else
                 ui->textEdit->append("Not Internet");
        }
        else
             ui->textEdit->append("Not Ethernet");
        ui->textEdit->append("");
        ui->textEdit->append("");
        for(int j = 0; j < p[i].captureLen; j++)
        {
            QString s("");
            if(p[i].file[j] / 16 == 0)
                s = "0";
            if(p[i].file[j] / 16 == 1)
                s = "1";
            if(p[i].file[j] / 16 == 2)
                s = "2";
            if(p[i].file[j] / 16 == 3)
                s = "3";
            if(p[i].file[j] / 16 == 4)
                s = "4";
            if(p[i].file[j] / 16 == 5)
                s = "5";
            if(p[i].file[j] / 16 == 6)
                s = "6";
            if(p[i].file[j] / 16 == 7)
                s = "7";
            if(p[i].file[j] / 16 == 8)
                s = "8";
            if(p[i].file[j] / 16 == 9)
                s = "9";
            if(p[i].file[j] / 16 == 10)
                s = "A";
            if(p[i].file[j] / 16 == 11)
                s = "B";
            if(p[i].file[j] / 16 == 12)
                s = "C";
            if(p[i].file[j] / 16 == 13)
                s = "D";
            if(p[i].file[j] / 16 == 14)
                s = "E";
            if(p[i].file[j] / 16 == 15)
                s = "F";

            if(p[i].file[j] % 16 == 0)
                s += "0";
            if(p[i].file[j] % 16 == 1)
                s += "1";
            if(p[i].file[j] % 16 == 2)
                s += "2";
            if(p[i].file[j] % 16 == 3)
                s += "3";
            if(p[i].file[j] % 16 == 4)
                s += "4";
            if(p[i].file[j] % 16 == 5)
                s += "5";
            if(p[i].file[j] % 16 == 6)
                s += "6";
            if(p[i].file[j] % 16 == 7)
                s += "7";
            if(p[i].file[j] % 16 == 8)
                s += "8";
            if(p[i].file[j] % 16 == 9)
                s += "9";
            if(p[i].file[j] % 16 == 10)
                s += "A";
            if(p[i].file[j] % 16 == 11)
                s += "B";
            if(p[i].file[j] % 16 == 12)
                s += "C";
            if(p[i].file[j] % 16 == 13)
                s += "D";
            if(p[i].file[j] % 16 == 14)
                s += "E";
            if(p[i].file[j] % 16 == 15)
                s += "F";

            ui->textEdit->insertPlainText(s + " ");
        }
        ui->textEdit->append("");
        ui->textEdit->append("");
        ui->textEdit->append("");
    }
    closeWaitWindow();
    this->show();
}
