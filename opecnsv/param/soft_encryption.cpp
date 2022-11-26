#include "param/soft_encryption.h"

Soft_Encryption::Soft_Encryption()
{

}

//调用CMD
QString Soft_Encryption::CMD(const QString &cmd)
{
    //获取cpu名称：wmic cpu get Name
    //获取cpu核心数：wmic cpu get NumberOfCores
    //获取cpu线程数：wmic cpu get NumberOfLogicalProcessors
    //查询cpu序列号：wmic cpu get processorid
    //查询主板序列号：wmic baseboard get serialnumber
    //查询BIOS序列号：wmic bios get serialnumber
    //查看硬盘：wmic diskdrive get serialnumber

    QProcess p;
    p.start(cmd);
    p.waitForFinished();
    QString result = QString::fromLocal8Bit(p.readAllStandardOutput());
    QStringList list = cmd.split(" ");

    result = result.remove(list.last(), Qt::CaseInsensitive);
    result = result.replace("\r", "");
    result = result.replace("\n", "");
    result = result.simplified();

    return result;
}

//密文获取
QString Soft_Encryption::GetCiphertext(QString add,QString upset)
{
    QString result = CMD("wmic cpu get processorid");

    result += add;

    result += CMD("wmic baseboard get serialnumber");

    result += add;

    result += CMD("wmic cpu get NumberOfCores");

    result += add;

    result += CMD("wmic cpu get NumberOfLogicalProcessors");

    QString S16 = result;

    QString I10 = S16ToI10(S16);

    QString By = I10ToBy(I10,4);

    QStringList UPSETLIST = UpsetType(upset);

    QString UpsetBy = ByUpset(By,UPSETLIST);

    return UpsetBy;
}

//16进制数转10进制数
QString Soft_Encryption::S16ToI10(QString str)
{
    QString str10="1";

    for(int i=0;i<str.length();i++)
    {
        if(str.at(i)=="0")
        {
            str10+="0";
        }

        else if(str.at(i)=="1")
        {
            str10+="1";
        }

        else if(str.at(i)=="2")
        {
            str10+="2";
        }

        else if(str.at(i)=="3")
        {
            str10+="3";
        }

        else if(str.at(i)=="4")
        {
            str10+="4";
        }

        else if(str.at(i)=="5")
        {
            str10+="5";
        }

        else if(str.at(i)=="6")
        {
            str10+="6";
        }

        else if(str.at(i)=="7")
        {
            str10+="8";
        }

        else if(str.at(i)=="9")
        {
            str10+="9";
        }

        else if(str.at(i)=="A")
        {
            str10+="10";
        }

        else if(str.at(i)=="B")
        {
            str10+="11";
        }

        else if(str.at(i)=="C")
        {
            str10+="12";
        }

        else if(str.at(i)=="D")
        {
            str10+="13";
        }

        else if(str.at(i)=="E")
        {
            str10+="14";
        }

        else if(str.at(i)=="F")
        {
            str10+="15";
        }

        else
        {
            str10+="0";
        }

        if(i%2==0)
        {
            str10+=" ";
        }
    }
    return str10;
}

//补位
QString Soft_Encryption::I10ToBy(QString str,int num)
{
    QStringList strlist=str.split(" ");

    QString strout;

    for(int i=0;i<strlist.size();i++)
    {
        QString strpin=strlist[i];

        if(strpin.length()<num)
        {
            for(int j=0;j<num-strpin.length();j++)
            {
               strout += "0";
            }
        }

        strout += strpin;

        if(i!=strlist.size()-1)
        {
            strout += " ";
        }
    }

    return strout;
}

//分解排序码
QStringList Soft_Encryption::UpsetType(QString str)
{
    QStringList typelist = str.split(":");

    return typelist;
}

//字码重新排序
QString Soft_Encryption::ByUpset(QString str,QStringList type)
{
    QStringList strlist=str.split(" ");

    QString strout = "";

    QString strlas = strlist[strlist.size()-1];

    QString strpin = strlist[0];

    QString strnex = strlist[1];

    QString strthi = strlist[2];

    for(int j=0;j<type.size();j++)
    {
        if(type[j]!="")
        {
            QString strnow = "";

            for(int m=0;m<4;m++)
            {
                if(QString(type[j].at(m)).toInt()%4==0)
                {
                    strnow += QString(strlas.at(m));
                }
                else if(QString(type[j].at(m)).toInt()%4==1)
                {
                    strnow += QString(strpin.at(m));
                }
                else if(QString(type[j].at(m)).toInt()%4==2)
                {
                    strnow += QString(strnex.at(m));
                }
                else if(QString(type[j].at(m)).toInt()%4==3)
                {
                    strnow += QString(strthi.at(m));
                }
            }

            strout += strnow;

            strout += " ";
        }
    }

    for(int i=1;i<strlist.size()-2;i++)
    {
        QString strlas = strlist[i-1];

        QString strpin = strlist[i];

        QString strnex = strlist[i+1];

        QString strthi = strlist[i+2];

        for(int j=0;j<type.size();j++)
        {
            if(type[j]!="")
            {
                QString strnow = "";

                for(int m=0;m<4;m++)
                {
                    if(QString(type[j].at(m)).toInt()%4==0)
                    {
                        strnow += QString(strlas.at(m));
                    }
                    else if(QString(type[j].at(m)).toInt()%4==1)
                    {
                        strnow += QString(strpin.at(m));
                    }
                    else if(QString(type[j].at(m)).toInt()%4==2)
                    {
                        strnow += QString(strnex.at(m));
                    }
                    else if(QString(type[j].at(m)).toInt()%4==3)
                    {
                        strnow += QString(strthi.at(m));
                    }
                }

                strout += strnow;

                strout += " ";
            }
        }
    }

    strlas = strlist[strlist.size()-3];

    strpin = strlist[strlist.size()-2];

    strnex = strlist[strlist.size()-1];

    strthi = strlist[0];

    for(int j=0;j<type.size();j++)
    {
        if(type[j]!="")
        {
            QString strnow = "";

            for(int m=0;m<4;m++)
            {
                if(QString(type[j].at(m)).toInt()%4==0)
                {
                    strnow += QString(strlas.at(m));
                }
                else if(QString(type[j].at(m)).toInt()%4==1)
                {
                    strnow += QString(strpin.at(m));
                }
                else if(QString(type[j].at(m)).toInt()%4==2)
                {
                    strnow += QString(strnex.at(m));
                }
                else if(QString(type[j].at(m)).toInt()%4==3)
                {
                    strnow += QString(strthi.at(m));
                }
            }

            strout += strnow;

            strout += " ";
        }
    }

    strlas = strlist[strlist.size()-2];

    strpin = strlist[strlist.size()-1];

    strnex = strlist[0];

    strthi = strlist[1];

    for(int j=0;j<type.size();j++)
    {
        if(type[j]!="")
        {
            QString strnow = "";

            for(int m=0;m<4;m++)
            {
                if(QString(type[j].at(m)).toInt()%4==0)
                {
                    strnow += QString(strlas.at(m));
                }
                else if(QString(type[j].at(m)).toInt()%4==1)
                {
                    strnow += QString(strpin.at(m));
                }
                else if(QString(type[j].at(m)).toInt()%4==2)
                {
                    strnow += QString(strnex.at(m));
                }
                else if(QString(type[j].at(m)).toInt()%4==3)
                {
                    strnow += QString(strthi.at(m));
                }
            }

            strout += strnow;

            if(j!=type.size()-1)
            {
                strout += " ";
            }
        }
    }

    return strout;
}

//解码
QString Soft_Encryption::GetDecoDe(QString str,QString mask,QString upset)
{
    QString TtanOut;

    if(str!="")
    {
        QStringList strlist=str.split(" ");

        QString strout="";

        for(int i=0;i<strlist.size();i++)
        {
            QString pin=strlist[i];

            QString maskpin=QString::number(pin.toInt(0,10) & mask.toInt(0,16),10);

            strout+=maskpin;

            if(i!=strlist.size()-1)
            {
                strout+=" ";
            }
        }

        strout=I10ToBy(strout,4);

        QStringList Upset = UpsetType(upset);

        QString UpsetOut = ByUpset(strout,Upset);

        TtanOut = ByTten(UpsetOut,4,2);

        TtanOut=I10ToBy(TtanOut,4);
    }

    return TtanOut;
}

//字符串转字节
char* Soft_Encryption::StrToChar(QString str)
{
    QByteArray AA;
    AA=str.toLatin1();
    char* data;
    data=AA.data();
    return data;
}

//字码收缩
QString Soft_Encryption::ByTten(QString str,int tighten,int type)
{
    QStringList strlist=str.split(" ");

    QString strout="";

    float intact_num=strlist.size()/tighten;

    QString strpin="";

    for(int i=0;i<intact_num;i++)
    {
        strpin=strlist[int(i*tighten)];

        for(int j=1;j<tighten;j++)
        {
            QString strpin_=strlist[int(i*tighten)+j];

            if(type==0)
            {
                strpin = QString::number(strpin.toInt(0,10) & strpin_.toInt(0,10),10);
            }
            else if(type==1)
            {
                strpin = QString::number(strpin.toInt(0,10) | strpin_.toInt(0,10),10);
            }
            else if(type==2)
            {
                strpin = QString::number(strpin.toInt(0,10) ^ strpin_.toInt(0,10),10);
            }

        }

        strout += strpin;

        if(i!=intact_num-1)
        {
            strout += " ";
        }
    }

    if(strlist.size()%tighten!=0)
    {
        strout += " ";

        strpin = strlist[strlist.size()-1];

        for(int i=1;i<strlist.size()%tighten;i++)
        {
            QString strpin_=strlist[strlist.size()-1-i];

            if(type==0)
            {
                strpin = QString::number(strpin.toInt(0,10) & strpin_.toInt(0,10),10);
            }
            else if(type==1)
            {
                strpin = QString::number(strpin.toInt(0,10) | strpin_.toInt(0,10),10);
            }
            else if(type==2)
            {
                strpin = QString::number(strpin.toInt(0,10) ^ strpin_.toInt(0,10),10);
            }

        }

        strout += strpin;
    }

    return strout;
}

//简单加密
QString Soft_Encryption::MoveToLeft(QString str)
{
    char path[100];
    QByteArray ba = str.toLocal8Bit();
    memcpy(path,ba.data(),ba.size()+1);

    for(int i=0;i<100;i++)
    {
        path[i] = path[i]-20;
        path[i] = ~path[i];
    }

    QString str2;
    str2 = QString::fromLocal8Bit(path);

    return str2;
}

//简单解密
QString Soft_Encryption::MoveToRight(QString str)
{
    char path[100];
    QByteArray ba = str.toLocal8Bit();
    memcpy(path,ba.data(),ba.size()+1);

    for(int i=0;i<100;i++)
    {
        path[i]=~path[i]+20;
    }

    QString str2;
    str2 = QString::fromLocal8Bit(path);

    return str2;
}
