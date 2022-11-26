#include "nsv_json_analy.h"

nsv_json_analy::nsv_json_analy()
{
    QString path="laina.bmp";
    cv::Mat image=cv::imread(path.toLocal8Bit().toStdString());
    createJsonFile("test.json",path,image);
}

void nsv_json_analy::clearJsonObject(QJsonObject &object)
{
    QStringList strList = object.keys();

    for(int i = 0; i < strList.size(); ++i)
    {
        object.remove(strList.at(i));
    }

}

void nsv_json_analy::createJsonFile(const QString &fileName,QString path,cv::Mat image)
{
    QJsonArray jsonArray;
    QJsonObject Object_flgs;
    QJsonObject rootObject;

    QList<cv::Point> test_list;
    for(int i=0;i<5;i++)
    {
        cv::Point testpoint(0,5*i);
        test_list.push_back(testpoint);
    }
    add_object(jsonArray,0,"back",test_list,NULL,"polygon");

    rootObject.insert("version","4.6.0");
    rootObject.insert("flags",Object_flgs);
    rootObject.insert("shapes", jsonArray);
    rootObject.insert("imagePath",path);
    QByteArray image_base_data=imageToBase64(path);
    rootObject.insert("imageDate",QString(image_base_data));
    rootObject.insert("imageHeight",image.rows);
    rootObject.insert("imageWidth",image.cols);


    QJsonDocument jsonDocument;
    jsonDocument.setObject(rootObject);

    QByteArray byteArray = jsonDocument.toJson(QJsonDocument::Indented);

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << QString("fail to open the file: %1, %2, %3").arg(__FILE__).arg(__LINE__).arg(__FUNCTION__);
        return;
    }
    QTextStream out(&file);
    out << byteArray;

    file.close();

    qDebug() << byteArray;
}

void nsv_json_analy::add_object(QJsonArray& Mather,int tip,QString label,QList<cv::Point> points,QString group_id,QString shape_type)
{
    QJsonObject Object;
    QJsonObject Object_flag;
    QJsonArray Array_point;

    for(int i=0;i<points.size();i++)
    {
        QJsonArray Point;
        Point.insert(0,points[i].x);
        Point.insert(1,points[i].y);
        Array_point.insert(0,Point);
    }

    Object.insert("label",label);
    Object.insert("points",Array_point);
    Object.insert("group_id",group_id);
    Object.insert("shape_type",shape_type);
    Object.insert("flags",Object_flag);

    Mather.append(Object);
}

QByteArray nsv_json_analy::imageToBase64(QString image)
{
    QImage Image(image);
    QByteArray ba;
    QBuffer buf(&ba);
    Image.save(&buf, "png");
    qDebug() << ba.toBase64();
    return ba.toBase64();
}

