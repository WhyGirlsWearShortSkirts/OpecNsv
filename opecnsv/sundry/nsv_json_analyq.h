#ifndef NSV_JSON_ANALY_H
#define NSV_JSON_ANALY_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>

#include <QJsonParseError>
#include <QByteArray>

class nsv_json_analy
{
public:
    nsv_json_analy();

    void clearJsonObject(QJsonObject &object);

    void add_object(QJsonArray &Mather, int tip, QString label, QList<cv::Point> points, QString group_id, QString shape_type);

    void createJsonFile(const QString &fileName, QString path, cv::Mat image);

    QByteArray imageToBase64(QString image);
};

#endif // NSV_JSON_ANALY_H

