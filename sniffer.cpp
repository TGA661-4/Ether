#include "sniffer.h"

sniffer::sniffer()
{

}

void sniffer::analis(QString str)
{
    waitWindow();
    file = new QFile(str);
    if(!file->open(QIODevice::ReadOnly))
        errorour();
    else
    {
        Name.nameOfFile = str;
        file->read((char *)&Name.magic, 4);
        file->read((char *)&Name.versionMajor, 2);
        file->read((char *)&Name.versionMinor, 2);
        file->read((char *)&Name.thisZone, 4);
        file->read((char *)&Name.sigfigs, 4);
        file->read((char *)&Name.snaplen, 4);
        file->read((char *)&Name.linkType, 4);
        while(file->pos() < file->size())
        {
            packets p;
            Packets.push_back(p);
            file->read((char *)&Packets[Packets.size() - 1].t1, 4);
            file->read((char *)&Packets[Packets.size() - 1].t2, 4);
            file->read((char *)&Packets[Packets.size() - 1].captureLen, 4);
            file->read((char *)&Packets[Packets.size() - 1].len, 4);
            for(int i = 0; i < Packets[Packets.size() - 1].captureLen; i++)
            {
                qint8 q;
                file->read((char *)&q, 1);
                Packets[Packets.size() - 1].file.push_back(q);
                if(Packets[Packets.size() - 1].file[i] < 0)
                    Packets[Packets.size() - 1].file[i] += 256;
            }
            if(Packets[Packets.size() - 1].file.size() > 13)
            {
                Packets[Packets.size() - 1].isEth = true;

                Packets[Packets.size() - 1].ethIn = "";
                if(Packets[Packets.size() - 1].file[0] / 16 == 0)
                    Packets[Packets.size() - 1].ethIn += "0";
                Packets[Packets.size() - 1].ethIn += QString::number(Packets[Packets.size() - 1].file[0], 16).toUpper() + ":";  //Мак получателя
                if(Packets[Packets.size() - 1].file[1] / 16 == 0)
                    Packets[Packets.size() - 1].ethIn += "0";
                Packets[Packets.size() - 1].ethIn += QString::number(Packets[Packets.size() - 1].file[1], 16).toUpper() + ":";
                if(Packets[Packets.size() - 1].file[2] / 16 == 0)
                    Packets[Packets.size() - 1].ethIn += "0";
                Packets[Packets.size() - 1].ethIn += QString::number(Packets[Packets.size() - 1].file[2], 16).toUpper() + ":";
                if(Packets[Packets.size() - 1].file[3] / 16 == 0)
                    Packets[Packets.size() - 1].ethIn += "0";
                Packets[Packets.size() - 1].ethIn += QString::number(Packets[Packets.size() - 1].file[3], 16).toUpper() + ":";
                if(Packets[Packets.size() - 1].file[4] / 16 == 0)
                    Packets[Packets.size() - 1].ethIn += "0";
                Packets[Packets.size() - 1].ethIn += QString::number(Packets[Packets.size() - 1].file[4], 16).toUpper() + ":";
                if(Packets[Packets.size() - 1].file[5] / 16 == 0)
                    Packets[Packets.size() - 1].ethIn += "0";
                Packets[Packets.size() - 1].ethIn += QString::number(Packets[Packets.size() - 1].file[5], 16).toUpper();

                Packets[Packets.size() - 1].ethOut = "";
                if(Packets[Packets.size() - 1].file[6] / 16 == 0)
                    Packets[Packets.size() - 1].ethOut += "0";
                Packets[Packets.size() - 1].ethOut = QString::number(Packets[Packets.size() - 1].file[6], 16).toUpper() + ":";   //мак отправителя
                if(Packets[Packets.size() - 1].file[7] / 16 == 0)
                    Packets[Packets.size() - 1].ethOut += "0";
                Packets[Packets.size() - 1].ethOut += QString::number(Packets[Packets.size() - 1].file[7], 16).toUpper() + ":";
                if(Packets[Packets.size() - 1].file[8] / 16 == 0)
                    Packets[Packets.size() - 1].ethOut += "0";
                Packets[Packets.size() - 1].ethOut += QString::number(Packets[Packets.size() - 1].file[8], 16).toUpper() + ":";
                if(Packets[Packets.size() - 1].file[9] / 16 == 0)
                    Packets[Packets.size() - 1].ethOut += "0";
                Packets[Packets.size() - 1].ethOut += QString::number(Packets[Packets.size() - 1].file[9], 16).toUpper() + ":";
                if(Packets[Packets.size() - 1].file[10] / 16 == 0)
                    Packets[Packets.size() - 1].ethOut += "0";
                Packets[Packets.size() - 1].ethOut += QString::number(Packets[Packets.size() - 1].file[10], 16).toUpper() + ":";
                if(Packets[Packets.size() - 1].file[11] / 16 == 0)
                    Packets[Packets.size() - 1].ethOut   += "0";
                Packets[Packets.size() - 1].ethOut += QString::number(Packets[Packets.size() - 1].file[11], 16).toUpper();

                Packets[Packets.size() - 1].type = Packets[Packets.size() - 1].file[12] * 256 + Packets[Packets.size() - 1].file[13]; //тип

                if(Packets[Packets.size() - 1].type == 8 * 256)
                {
                    Packets[Packets.size() - 1].isIth = true;
                    int prop = (Packets[Packets.size() - 1].file[14] / 16) * (Packets[Packets.size() - 1].file[14] % 16);
                    if(Packets[Packets.size() - 1].file[23] == 6)
                        Packets[Packets.size() - 1].ithType = "TCPIP";
                    else
                        if(Packets[Packets.size() - 1].file[23] == 11)
                            Packets[Packets.size() - 1].ithType = "UDP";
                        else
                            Packets[Packets.size() - 1].ithType = "Не определено";
                    Packets[Packets.size() - 1].ipIn = QString::number(Packets[Packets.size() - 1].file[26]) + ":";
                    Packets[Packets.size() - 1].ipIn += QString::number(Packets[Packets.size() - 1].file[27]) + ":";
                    Packets[Packets.size() - 1].ipIn += QString::number(Packets[Packets.size() - 1].file[28]) + ":";
                    Packets[Packets.size() - 1].ipIn += QString::number(Packets[Packets.size() - 1].file[29]);

                    Packets[Packets.size() - 1].ipOut = QString::number(Packets[Packets.size() - 1].file[30]) + ":";
                    Packets[Packets.size() - 1].ipOut += QString::number(Packets[Packets.size() - 1].file[31]) + ":";
                    Packets[Packets.size() - 1].ipOut += QString::number(Packets[Packets.size() - 1].file[32]) + ":";
                    Packets[Packets.size() - 1].ipOut += QString::number(Packets[Packets.size() - 1].file[33]);

                    Packets[Packets.size() - 1].portOut = QString::number(Packets[Packets.size() - 1].file[14 + prop] * 256 + Packets[Packets.size() - 1].file[15 + prop]);
                    Packets[Packets.size() - 1].portIn = QString::number(Packets[Packets.size() - 1].file[16 + prop] * 256 + Packets[Packets.size() - 1].file[17 + prop]);
                }
                else
                    Packets[Packets.size() - 1].isIth = false;
            }
            else
                 Packets[Packets.size() - 1].isEth = false;
        }
        Name.nomberOfPackets = Packets.size();
        outFirst(Name);
        outSecond(Packets);
    }
}
