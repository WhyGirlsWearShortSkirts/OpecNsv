#include "nsv_json_analy.h"

nsv_json_analy::nsv_json_analy()
{
    createjsonfile();
}

void nsv_json_analy::createjsonfile()
{
    // write
    Json::Value shapesValue;
    QList<cv::Point> test_list;
    for(int i=0;i<5;i++)
    {
        cv::Point testpoint(0,5*i);
        test_list.push_back(testpoint);
    }
    add_object(shapesValue,"back",test_list,NULL,"polygon");

    Json::Value flagsValue;

    Json::Value writeValue;
    writeValue["version"]="4.6.0";
    writeValue["flags"]=flagsValue;
    writeValue["shapes"] = shapesValue;

    Json::StyledWriter swriter;
    std::string strs = swriter.write(writeValue);
    std::ofstream ofss("example_styled_writer.json");
    ofss << strs;
    ofss.close();
}

void nsv_json_analy::add_object(Json::Value& Mather,QString label,QList<cv::Point> points,QString group_id,QString shape_type)
{
    Json::Value Object;
    Json::Value Object_flag;
    Json::Value Point_array;

    for(int i=0;i<points.size();i++)
    {
        Json::Value Point;
        Point.append(points[i].x);
        Point.append(points[i].y);
        Point_array.append(Point);
    }

    Object["label"]=label.toStdString();
    Object["points"]=Point_array;
    Object["group_id"]=group_id.toStdString();
    Object["shape_type"]=shape_type.toStdString();
    Object["flags"]=Object_flag;

    Mather.append(Object);
}

void nsv_json_analy::readjsonfile()
{
    // read
    string strValue = "{\"key1\":\"111\",\"array\":[{\"key2\":\"222\"},{\"key2\":\"333\"},{\"key2\":\"444\"}]}";
    Json::Reader reader;
    Json::Value root;
    if (reader.parse(strValue, root))
    {
        std::string out = root["key1"].asString();
        qDebug()<<QString::fromStdString(out);
        Json::Value arrayObj = root["array"];
        for (int i=0; i<arrayObj.size(); i++)
        {
            out = arrayObj[i]["key2"].asString();
            qDebug()<<QString::fromStdString(out);
        }
    }

    std::ifstream ifs("example_fast_writer.json");
    if (reader.parse(ifs, root))
    {
        std::string out = root["classname"].asString();
        qDebug()<<QString::fromStdString(out);
        Json::Value peoples = root["peoples"];
        for (int i=0; i<peoples.size(); i++)
        {
            qDebug()<<QString::fromStdString(peoples[i]["name"].asString());
            qDebug()<<QString::fromStdString(peoples[i]["sex"].asString());
            qDebug()<<QString::fromStdString(peoples[i]["age"].asString());
            qDebug()<<QString::fromStdString(peoples[i]["note"].asString());
        }
    }
}


