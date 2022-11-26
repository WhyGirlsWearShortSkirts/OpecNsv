#ifndef NSV_JSON_ANALY_H
#define NSV_JSON_ANALY_H

#include "param/nsv_include.h"
#include "param/lattree_param.h"
#include "param/nsv_global_param.h"

class nsv_json_analy
{
public:
    nsv_json_analy();

    nsv_objects_image json_read_nsv(QString jsonpath);

    int json_create_nsv(nsv_objects_image objects);

    QList<QString> imagename_getfrompath(QString path);

    int json_create_analy(nsv Nsv);

    nsv json_read_analy();

    void object_add(rapidjson::PrettyWriter<rapidjson::StringBuffer> &Mather, QString label, QList<QPointF> points, QString group_id, QString shape_type);

    void object_add(rapidjson::PrettyWriter<rapidjson::StringBuffer> &Mather, QString label, QList<QPointF> points, QString group_id, QString shape_type,double angle);

    bool save_image_data=false;

    int json_create_config(config con);

    config json_read_config();

    static int json_create_node(node_cross n, QString path);

    static node_cross json_read_node(QString path);

    static int json_create_tree(node_cross n, QString path);

    static node_cross json_read_tree(QString path);
};

#endif // NSV_JSON_ANALY_H
