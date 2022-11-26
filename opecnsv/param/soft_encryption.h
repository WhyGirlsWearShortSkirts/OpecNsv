#ifndef SOFT_ENCRYPTION_H
#define SOFT_ENCRYPTION_H

#include <QString>
#include <QtDebug>
#include <QProcess>

class Soft_Encryption
{
public:
    Soft_Encryption();

    //密文获取
    QString GetCiphertext(QString add, QString upset);

    //解码
    QString GetDecoDe(QString str, QString mask, QString upset);

    //字符串转字节
    char *StrToChar(QString str);

public slots:

    QString MoveToLeft(QString str);

    QString MoveToRight(QString str);

protected:

    //调用cmd
    QString CMD(const QString &cmd);

    //16进制数转10进制数
    QString S16ToI10(QString str);

    //分解排序码
    QStringList UpsetType(QString str);

    //字码重新排序
    QString ByUpset(QString str, QStringList type);

    //字码收缩
    QString ByTten(QString str, int tighten, int type);

    //补位
    QString I10ToBy(QString str, int num);

};

#endif // SOFT_ENCRYPTION_H
