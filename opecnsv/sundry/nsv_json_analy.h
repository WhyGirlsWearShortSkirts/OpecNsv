#ifndef NSV_JSON_ANALY_H
#define NSV_JSON_ANALY_H

#include "param/nsv_include.h"

class nsv_json_analy
{
public:
    nsv_json_analy();

    void createjsonfile();

    void readjsonfile();

    void add_object(Json::Value &Mather, QString label, QList<cv::Point> points, QString group_id, QString shape_type);
};

#endif // NSV_JSON_ANALY_H
