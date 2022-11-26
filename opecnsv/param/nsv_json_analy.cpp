#include "nsv_json_analy.h"

//构造函数
nsv_json_analy::nsv_json_analy()
{

}

//标注文件读取
nsv_objects_image nsv_json_analy::json_read_nsv(QString jsonpath)
{
    nsv_objects_image objects;

    objects.path_json=jsonpath;

    QFile f(jsonpath);
    f.open(QIODevice::ReadOnly);
    QString src = f.readAll();
    f.close();




    std::string json_content = src.toUtf8().toStdString();

    QList<QString> image_file;
    image_file=imagename_getfrompath(objects.path_json);

    rapidjson::Document dom;

    if (!dom.Parse(json_content.c_str()).HasParseError())
    {
        if (dom.HasMember("version") && dom["version"].IsString())
        {
            objects.version=utf8Togbk(dom["version"].GetString());
        }

        if (dom.HasMember("shapes") && dom["shapes"].IsArray())
        {
            const rapidjson::Value& arr = dom["shapes"];

            for (unsigned int i = 0; i < arr.Size(); i++)
            {
                nsv_object object;

                if (arr[i].HasMember("label") && arr[i]["label"].IsString())
                {
                    object.lables=utf8Togbk(arr[i]["label"].GetString());
                }

                if (arr[i].HasMember("points") && arr[i]["points"].IsArray())
                {
                    QList<QPointF> points;
                    const rapidjson::Value& arr_points = arr[i]["points"];
                    for(unsigned int j=0;j<arr_points.Size();j++)
                    {
                        if(arr_points[j].IsArray())
                        {
                            const rapidjson::Value& arr_point = arr_points[j];

                            if(arr_point.Size()==2)
                            {
                                if(arr_point[0].IsDouble() && arr_point[1].IsDouble())
                                {
                                    points.append(QPoint(arr_point[0].GetDouble(),arr_point[1].GetDouble()));
                                }
                                else if(arr_point[0].IsInt() && arr_point[1].IsInt())
                                {
                                    points.append(QPoint(arr_point[0].GetInt(),arr_point[1].GetInt()));
                                }
                            }
                        }
                    }
                    object.points=points;
                }

                if (arr[i].HasMember("group_id") && arr[i]["group_id"].IsString())
                {
                    object.group_id=utf8Togbk(arr[i]["group_id"].GetString());
                }

                if (arr[i].HasMember("shape_type") && arr[i]["shape_type"].IsString())
                {
                    object.shape_type=utf8Togbk(arr[i]["shape_type"].GetString());
                }

                if (arr[i].HasMember("angle") && arr[i]["angle"].IsDouble())
                {
                    object.angle=arr[i]["angle"].GetDouble();
                }
                else
                {
                    object.angle=0;
                }

                objects.objects.append(object);
            }
        }

        if (dom.HasMember("imagePath") && dom["imagePath"].IsString())
        {
           objects.image_file=utf8Togbk(dom["imagePath"].GetString());
        }

        if (dom.HasMember("imageData") && dom["imageData"].IsString() && save_image_data)
        {
            objects.image_data=dom["imageData"].GetString();
        }
        else
        {
            objects.image_data="";
        }

        if (dom.HasMember("imageHeight") && dom["imageHeight"].IsInt())
        {
            objects.image_height=dom["imageHeight"].GetInt();
        }

        if (dom.HasMember("imageWidth") && dom["imageWidth"].IsInt())
        {
            objects.image_width=dom["imageWidth"].GetInt();
        }

        objects.path=image_file[3]+objects.image_file;

        cv::Mat image=cv::imread(objects.path.toUtf8().toStdString());

        objects.image=image.clone();

        objects.flags_use=true;

    }
    else
    {
        qDebug()<<"fail to parse json file:"+jsonpath;
        objects.flags_use=false;
    }

    return objects;
}

//标注文件写入
int nsv_json_analy::json_create_nsv(nsv_objects_image objects)
{
    rapidjson::StringBuffer buf;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buf); // it can word wrap
    QList<QString> image_file;
    image_file=imagename_getfrompath(objects.path);

    writer.StartObject();

    writer.Key("version"); writer.String(objects.version.toUtf8());

    writer.Key("flags");
    writer.StartObject();
    writer.EndObject();

    writer.Key("shapes");
    writer.StartArray();
    for(int j=0;j<objects.objects.size();j++)
    {
        object_add(writer,objects.objects[j].lables,objects.objects[j].points,NULL,objects.objects[j].shape_type,objects.objects[j].angle);
    }
    writer.EndArray();

    writer.Key("imagePath");
    writer.String(objects.image_file.toUtf8());

    writer.Key("imageData");
    writer.String(objects.image_data);

    writer.Key("imageHeight");
    writer.Int(objects.image_height);

    writer.Key("imageWidth");
    writer.Int(objects.image_width);

    writer.EndObject();

    const char* json_content = buf.GetString();

    QString name=image_file[3]+image_file[1]+".json";

    qDebug()<<image_file[3]<<image_file[1]<<name;

    QFile fp(name);
    fp.open(QIODevice::WriteOnly);
    fp.write(json_content);
    fp.close();

    return 0;
}

//添加标注框
void nsv_json_analy::object_add(rapidjson::PrettyWriter<rapidjson::StringBuffer>& Mather,QString label,QList<QPointF> points,QString group_id,QString shape_type)
{
    Mather.StartObject();

    Mather.Key("label");
    Mather.String(label.toUtf8());

    Mather.Key("points");
    Mather.StartArray();
    for(int i=0;i<points.size();i++)
    {
        Mather.StartArray();
        Mather.Double(points[i].x());
        Mather.Double(points[i].y());
        Mather.EndArray();
    }
    Mather.EndArray();

    Mather.Key("group_id");
    if(group_id==NULL)
    {
        Mather.Null();
    }
    else
    {
        Mather.String(group_id.toUtf8());
    }


    Mather.Key("shape_type");
    Mather.String(shape_type.toUtf8());

    Mather.Key("flags");
    Mather.StartObject();
    Mather.EndObject();

    Mather.EndObject();
}

//添加标注框（带角度）
void nsv_json_analy::object_add(rapidjson::PrettyWriter<rapidjson::StringBuffer> &Mather, QString label, QList<QPointF> points, QString group_id, QString shape_type, double angle)
{
    Mather.StartObject();

    Mather.Key("label");
    Mather.String(label.toUtf8());

    Mather.Key("points");
    Mather.StartArray();
    for(int i=0;i<points.size();i++)
    {
        Mather.StartArray();
        Mather.Double(points[i].x());
        Mather.Double(points[i].y());
        Mather.EndArray();
    }
    Mather.EndArray();

    Mather.Key("group_id");
    if(group_id==NULL)
    {
        Mather.Null();
    }
    else
    {
        Mather.String(group_id.toUtf8());
    }


    Mather.Key("shape_type");
    Mather.String(shape_type.toUtf8());

    Mather.Key("flags");
    Mather.StartObject();
    Mather.EndObject();

    Mather.Key("angle");
    Mather.Double(angle);

    Mather.EndObject();
}

//地址拆解
QList<QString> nsv_json_analy::imagename_getfrompath(QString path)
{
    QStringList list_path=path.split(QRegExp("[/.]"));

    QList<QString> image_file;

    QString image_all=list_path[list_path.size()-2]+"."+list_path[list_path.size()-1];
    QString image_name=list_path[list_path.size()-2];
    QString image_type=list_path[list_path.size()-1];
    QString image_place=path.mid(0,path.size()-image_all.size());
    image_file.append(image_all);
    image_file.append(image_name);
    image_file.append(image_type);
    image_file.append(image_place);

    return image_file;
}

//预标注配置写入
int nsv_json_analy::json_create_analy(nsv Nsv)
{
    rapidjson::StringBuffer buf;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buf); // it can word wrap

    writer.StartObject();

    writer.Key("image_alpha_beta_enable");
    writer.Bool(Nsv.image_alpha_beta_enable);

    writer.Key("image_objectname");
    writer.String(Nsv.objectname.toUtf8());

    writer.Key("image_alpha_beta");
    writer.StartObject();
    writer.Key("image_alpha");
    writer.Int(Nsv.image_alpha);
    writer.Key("image_beta");
    writer.Int(Nsv.image_beta);
    writer.EndObject();

    writer.Key("image_clur_enable");
    writer.Bool(Nsv.image_clur_enable);

    writer.Key("image_clur");
    writer.StartObject();
    writer.Key("image_clur_size");
    writer.Int(Nsv.image_clur);
    writer.EndObject();

    writer.Key("image_thresold_inv_enable");
    writer.Bool(Nsv.image_thresold_inv_enable);

    writer.Key("image_thresold_inv");
    writer.StartObject();
    writer.Key("image_thresold_inv_size");
    writer.Int(Nsv.image_thresold_inv);
    writer.EndObject();

    writer.Key("image_necess");
    writer.StartObject();
    writer.Key("image_split_type");
    writer.Int(Nsv.image_split_type);
    writer.Key("image_thresold");
    writer.Int(Nsv.image_thresold);
    writer.Key("image_re_color");
    writer.Bool(Nsv.image_re_color);
    writer.EndObject();

    writer.Key("image_roi_enable");
    writer.Bool(Nsv.image_roi_enable);

    writer.Key("image_roi_rect");
    writer.StartArray();
    writer.Double(Nsv.rect_cut.x);
    writer.Double(Nsv.rect_cut.y);
    writer.Double(Nsv.rect_cut.width);
    writer.Double(Nsv.rect_cut.height);
    writer.EndArray();

    writer.Key("image_erdi_enable");
    writer.Bool(Nsv.image_erdi_enable);

    writer.Key("image_erdi");
    writer.StartObject();
    writer.Key("image_erdi_size");
    writer.Int(Nsv.image_erdi);
    writer.EndObject();

    writer.Key("object_necess");
    writer.StartObject();
    writer.Key("object_min_size");
    writer.Int(Nsv.min_size);
    writer.Key("object_max_size");
    writer.Int(Nsv.max_size);
    writer.Key("object_contours_type");
    writer.Int(Nsv.contours_type);
    writer.Key("object_contours_size");
    writer.Int(Nsv.contours_size);
    writer.EndObject();

    writer.Key("image_other_enable");
    writer.Bool(Nsv.other_enable);

    writer.Key("image_other");
    writer.StartObject();

    writer.Key("image_legth_enable");
    writer.Bool(Nsv.legth_enable);

    writer.Key("legth");
    writer.StartObject();
    writer.Key("min_legth_size");
    writer.Int(Nsv.min_legth);
    writer.Key("max_legth_size");
    writer.Int(Nsv.max_legth);
    writer.EndObject();

    writer.Key("image_width_enable");
    writer.Bool(Nsv.width_enable);

    writer.Key("width");
    writer.StartObject();
    writer.Key("min_width_size");
    writer.Int(Nsv.min_width);
    writer.Key("max_width_size");
    writer.Int(Nsv.max_width);
    writer.EndObject();

    writer.Key("image_cir_enable");
    writer.Bool(Nsv.cir_enable);

    writer.Key("cir");
    writer.StartObject();
    writer.Key("min_cir_size");
    writer.Double(Nsv.min_cir);
    writer.Key("max_cir_size");
    writer.Double(Nsv.max_cir);
    writer.EndObject();

    writer.Key("image_pyl_enable");
    writer.Bool(Nsv.pyl_enable);

    writer.Key("pyl");
    writer.StartObject();
    writer.Key("min_pyl_size");
    writer.Double(Nsv.min_pyl);
    writer.Key("max_pyl_size");
    writer.Double(Nsv.max_pyl);
    writer.EndObject();

    writer.Key("image_rectsize_enable");
    writer.Bool(Nsv.rectsize_enable);

    writer.Key("rectsize");
    writer.StartObject();
    writer.Key("min_rectsize_size");
    writer.Double(Nsv.min_rectsize);
    writer.Key("max_rectsize_size");
    writer.Double(Nsv.max_rectsize);
    writer.EndObject();

    writer.Key("image_hullnum_enable");
    writer.Bool(Nsv.hullnum_enable);

    writer.Key("hullnum");
    writer.StartObject();
    writer.Key("min_hullnum_size");
    writer.Int(Nsv.min_hullnum);
    writer.Key("max_hullnum_size");
    writer.Int(Nsv.max_hullnum);
    writer.EndObject();

    writer.EndObject();

    writer.EndObject();

    const char* json_content = buf.GetString();

    QString name="stats_config.json";
    QFile fp(name);
    fp.open(QIODevice::WriteOnly);
    fp.write(json_content);
    fp.close();

    return 0;
}

//预标注配置读取
nsv nsv_json_analy::json_read_analy()
{
    nsv Nsv;

    QString jsonpath="stats_config.json";

    QFile f(jsonpath);
    f.open(QIODevice::ReadOnly);
    QString src = f.readAll();
    f.close();

    std::string json_content = src.toUtf8().toStdString();

    rapidjson::Document dom;

    if (!dom.Parse(json_content.c_str()).HasParseError())
    {
        if (dom.HasMember("image_alpha_beta_enable") && dom["image_alpha_beta_enable"].IsBool())
        {
            Nsv.image_alpha_beta_enable=dom["image_alpha_beta_enable"].GetBool();
        }

        if (dom.HasMember("image_objectname") && dom["image_objectname"].IsString())
        {
            Nsv.objectname=utf8Togbk(dom["image_objectname"].GetString());
        }

        if (dom.HasMember("image_alpha_beta") && dom["image_alpha_beta"].IsObject())
        {
            const rapidjson::Value& arr = dom["image_alpha_beta"];

            if (arr.HasMember("image_alpha") && arr["image_alpha"].IsInt())
            {
                Nsv.image_alpha=arr["image_alpha"].GetInt();
            }

            if (arr.HasMember("image_beta") && arr["image_beta"].IsInt())
            {
                Nsv.image_beta=arr["image_beta"].GetInt();
            }
        }

        if (dom.HasMember("image_clur_enable") && dom["image_clur_enable"].IsBool())
        {
            Nsv.image_clur_enable=dom["image_clur_enable"].GetBool();
        }

        if (dom.HasMember("image_clur") && dom["image_clur"].IsObject())
        {
            const rapidjson::Value& arr = dom["image_clur"];

            if (arr.HasMember("image_clur_size") && arr["image_clur_size"].IsInt())
            {
                Nsv.image_clur=arr["image_clur_size"].GetInt();
            }
        }

        if (dom.HasMember("image_thresold_inv_enable") && dom["image_thresold_inv_enable"].IsBool())
        {
            Nsv.image_thresold_inv_enable=dom["image_thresold_inv_enable"].GetBool();
        }

        if (dom.HasMember("image_thresold_inv") && dom["image_thresold_inv"].IsObject())
        {
            const rapidjson::Value& arr = dom["image_thresold_inv"];

            if (arr.HasMember("image_thresold_inv_size") && arr["image_thresold_inv_size"].IsInt())
            {
                Nsv.image_thresold_inv=arr["image_thresold_inv_size"].GetInt();
            }
        }

        if (dom.HasMember("image_roi_enable") && dom["image_roi_enable"].IsBool())
        {
            Nsv.image_roi_enable=dom["image_roi_enable"].GetBool();
        }

        if (dom.HasMember("image_roi_rect") && dom["image_roi_rect"].IsArray())
        {
            cv::Rect rect;
            const rapidjson::Value& arr = dom["image_roi_rect"];
            if(arr.Size()==4)
            {
                if(arr[0].IsDouble() && arr[1].IsDouble() && arr[2].IsDouble() && arr[3].IsDouble())
                {
                    rect.x=arr[0].GetDouble();
                    rect.y=arr[1].GetDouble();
                    rect.width=arr[2].GetDouble();
                    rect.height=arr[3].GetDouble();
                }
            }
            Nsv.rect_cut=rect;
         }

        if (dom.HasMember("image_erdi_enable") && dom["image_erdi_enable"].IsBool())
        {
            Nsv.image_erdi_enable=dom["image_erdi_enable"].GetBool();
        }

        if (dom.HasMember("image_erdi") && dom["image_erdi"].IsObject())
        {
            const rapidjson::Value& arr = dom["image_erdi"];

            if (arr.HasMember("image_erdi_size") && arr["image_erdi_size"].IsInt())
            {
                Nsv.image_erdi=arr["image_erdi_size"].GetInt();
            }
        }

        if (dom.HasMember("image_necess") && dom["image_necess"].IsObject())
        {
            const rapidjson::Value& arr = dom["image_necess"];

            if (arr.HasMember("image_split_type") && arr["image_split_type"].IsInt())
            {
                Nsv.image_split_type=arr["image_split_type"].GetInt();
            }

            if (arr.HasMember("image_thresold") && arr["image_thresold"].IsInt())
            {
                Nsv.image_thresold=arr["image_thresold"].GetInt();
            }

            if (arr.HasMember("image_re_color") && arr["image_re_color"].IsBool())
            {
                Nsv.image_re_color=arr["image_re_color"].GetBool();
            }
        }

        if (dom.HasMember("object_necess") && dom["object_necess"].IsObject())
        {
            const rapidjson::Value& arr = dom["object_necess"];

            if (arr.HasMember("object_min_size") && arr["object_min_size"].IsInt())
            {
                Nsv.min_size=arr["object_min_size"].GetInt();
            }

            if (arr.HasMember("object_max_size") && arr["object_max_size"].IsInt())
            {
                Nsv.max_size=arr["object_max_size"].GetInt();
            }

            if (arr.HasMember("object_contours_type") && arr["object_contours_type"].IsInt())
            {
                Nsv.contours_type=arr["object_contours_type"].GetInt();
            }

            if (arr.HasMember("object_contours_size") && arr["object_contours_size"].IsInt())
            {
                Nsv.contours_size=arr["object_contours_size"].GetInt();
            }
        }

        if (dom.HasMember("image_other_enable") && dom["image_other_enable"].IsBool())
        {
            Nsv.other_enable=dom["image_other_enable"].GetBool();
        }

        if (dom.HasMember("image_other") && dom["image_other"].IsObject())
        {
            const rapidjson::Value& arr = dom["image_other"];

            if (arr.HasMember("image_legth_enable") && arr["image_legth_enable"].IsBool())
            {
                Nsv.legth_enable=arr["image_legth_enable"].GetBool();
            }

            if (arr.HasMember("legth") && arr["legth"].IsObject())
            {
                const rapidjson::Value& tt = arr["legth"];

                if(tt.HasMember("min_legth_size") && tt["min_legth_size"].IsInt())
                {
                    Nsv.min_legth=tt["min_legth_size"].GetInt();
                }

                if(tt.HasMember("max_legth_size") && tt["max_legth_size"].IsInt())
                {
                    Nsv.max_legth=tt["max_legth_size"].GetInt();
                }
            }

            if (arr.HasMember("image_width_enable") && arr["image_width_enable"].IsBool())
            {
                Nsv.width_enable=arr["image_width_enable"].GetBool();
            }

            if (arr.HasMember("width") && arr["width"].IsObject())
            {
                const rapidjson::Value& tt = arr["width"];

                if(tt.HasMember("min_width_size") && tt["min_width_size"].IsInt())
                {
                    Nsv.min_width=tt["min_width_size"].GetInt();
                }

                if(tt.HasMember("max_width_size") && tt["max_width_size"].IsInt())
                {
                    Nsv.max_width=tt["max_width_size"].GetInt();
                }
            }

            if (arr.HasMember("image_cir_enable") && arr["image_cir_enable"].IsBool())
            {
                Nsv.cir_enable=arr["image_cir_enable"].GetBool();
            }

            if (arr.HasMember("cir") && arr["cir"].IsObject())
            {
                const rapidjson::Value& tt = arr["cir"];

                if(tt.HasMember("min_cir_size") && tt["min_cir_size"].IsDouble())
                {
                    Nsv.min_cir=tt["min_cir_size"].GetDouble();
                }

                if(tt.HasMember("max_cir_size") && tt["max_cir_size"].IsDouble())
                {
                    Nsv.max_cir=tt["max_cir_size"].GetDouble();
                }
            }

            if (arr.HasMember("image_pyl_enable") && arr["image_pyl_enable"].IsBool())
            {
                Nsv.pyl_enable=arr["image_pyl_enable"].GetBool();
            }

            if (arr.HasMember("pyl") && arr["pyl"].IsObject())
            {
                const rapidjson::Value& tt = arr["pyl"];

                if(tt.HasMember("min_pyl_size") && tt["min_pyl_size"].IsDouble())
                {
                    Nsv.min_pyl=tt["min_pyl_size"].GetDouble();
                }

                if(tt.HasMember("max_pyl_size") && tt["max_pyl_size"].IsDouble())
                {
                    Nsv.max_pyl=tt["max_pyl_size"].GetDouble();
                }
            }

            if (arr.HasMember("image_rectsize_enable") && arr["image_rectsize_enable"].IsBool())
            {
                Nsv.rectsize_enable=arr["image_rectsize_enable"].GetBool();
            }

            if (arr.HasMember("rectsize") && arr["rectsize"].IsObject())
            {
                const rapidjson::Value& tt = arr["rectsize"];

                if(tt.HasMember("min_rectsize_size") && tt["min_rectsize_size"].IsDouble())
                {
                    Nsv.min_rectsize=tt["min_rectsize_size"].GetDouble();
                }

                if(tt.HasMember("max_rectsize_size") && tt["max_rectsize_size"].IsDouble())
                {
                    Nsv.max_rectsize=tt["max_rectsize_size"].GetDouble();
                }
            }

            if (arr.HasMember("image_hullnum_enable") && arr["image_hullnum_enable"].IsBool())
            {
                Nsv.hullnum_enable=arr["image_hullnum_enable"].GetBool();
            }

            if (arr.HasMember("hullnum") && arr["hullnum"].IsObject())
            {
                const rapidjson::Value& tt = arr["hullnum"];

                if(tt.HasMember("min_hullnum_size") && tt["min_hullnum_size"].IsInt())
                {
                    Nsv.min_hullnum=tt["min_hullnum_size"].GetInt();
                }

                if(tt.HasMember("max_hullnum_size") && tt["max_hullnum_size"].IsInt())
                {
                    Nsv.max_hullnum=tt["max_hullnum_size"].GetInt();
                }
            }
        }

        Nsv.flags_use=true;

    }
    else
    {
        qDebug()<<"fail to parse json file:"+jsonpath;
        Nsv.flags_use=false;
    }
    return Nsv;
}

//系统设置写入
int nsv_json_analy::json_create_config(config con)
{
    rapidjson::StringBuffer buf;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buf); // it can word wrap

    writer.StartObject();

    writer.Key("imagelist_path");
    writer.String(con.imagelist_path.toUtf8());

    writer.Key("scale");
    writer.Double(con.scale);

    writer.Key("tip");
    writer.Int(con.tip);

    writer.EndObject();

    const char* json_content = buf.GetString();

    QString name="config.json";
    QFile fp(name);
    fp.open(QIODevice::WriteOnly);
    fp.write(json_content);
    fp.close();
    return 0;
}

//系统设置读取
config nsv_json_analy::json_read_config()
{
    config con;

    QString jsonpath="config.json";

    QFile f(jsonpath);
    f.open(QIODevice::ReadOnly);
    QString src = f.readAll();
    f.close();

    std::string json_content = src.toUtf8().toStdString();

    rapidjson::Document dom;

    if (!dom.Parse(json_content.c_str()).HasParseError())
    {
        if (dom.HasMember("imagelist_path") && dom["imagelist_path"].IsString())
        {
            con.imagelist_path=dom["imagelist_path"].GetString();
        }

        if (dom.HasMember("scale") && dom["scale"].IsDouble())
        {
            con.scale=dom["scale"].GetDouble();
        }

        if (dom.HasMember("tip") && dom["tip"].IsInt())
        {
            con.tip=dom["tip"].GetInt();
        }
    }
    else
    {
        qDebug()<<"fail to parse json file:"+jsonpath;
    }

    return con;
}

//流程树

//节点信息写入
int nsv_json_analy::json_create_node(node_cross n,QString path)
{
    rapidjson::StringBuffer buf;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buf); // it can word wrap

    writer.StartObject();

    writer.Key("node_tig");
    writer.Int(n.tig);

    writer.Key("node_name");
    writer.String(n.name.toUtf8());

    writer.Key("node_info");
    writer.String(n.info.toUtf8());

    writer.Key("node_param");
    writer.String(n.param.toUtf8());

    if(n.intype.size() != n.intype_info.size() || n.intype.size() !=  n.inList_inside.size())
    {
        qDebug()<<"节点输入("+QString::number(n.intype.size())+")，输入描述("+QString::number(n.intype_info.size())+")，节点内输入变量("+QString::number(n.inList_inside.size())+")无法一一对应！";
        return -1;
    }

    writer.Key("node_intype");
    writer.StartArray();

    for(int i=0;i<n.intype.size();i++)
    {
        writer.StartObject();

        writer.Key("in");
        writer.String(n.intype[i].toUtf8());

        writer.Key("info");
        writer.String(n.intype_info[i].toUtf8());

        writer.Key("inside");
        writer.Int(n.inList_inside[i]);

        writer.EndObject();
    }

    writer.EndArray();

    if(n.outtype.size() != n.outtype_info.size() || n.outtype.size() !=  n.outList_inside.size())
    {
        qDebug()<<"节点输出("+QString::number(n.outtype.size())+")，输出描述("+QString::number(n.outtype_info.size())+")，节点内输出变量("+QString::number(n.outList_inside.size())+")无法一一对应！";
        return -1;
    }

    writer.Key("node_outtype");
    writer.StartArray();

    for(int i=0;i<n.outtype.size();i++)
    {
        writer.StartObject();

        writer.Key("out");
        writer.String(n.outtype[i].toUtf8());

        writer.Key("info");
        writer.String(n.outtype_info[i].toUtf8());

        writer.Key("inside");
        writer.Int(n.outList_inside[i]);

        writer.EndObject();
    }

    writer.EndArray();

    writer.Key("node_tree");
    writer.String(n.tree.toUtf8());

    writer.Key("node_data_inside");
    writer.String(n.data.toUtf8());

    writer.EndObject();

    const char* json_content = buf.GetString();

    QString name= path+"/node.json";
    QFile fp(name);
    fp.open(QIODevice::WriteOnly);
    fp.write(json_content);
    fp.close();

    return 0;
}

//节点信息读取
node_cross nsv_json_analy::json_read_node(QString path)
{
    node_cross n;

    QString jsonpath=path+"/node.json";

    QFile f(jsonpath);
    f.open(QIODevice::ReadOnly);
    QString src = f.readAll();
    f.close();

    std::string json_content = src.toUtf8().toStdString();

    rapidjson::Document dom;

    if (!dom.Parse(json_content.c_str()).HasParseError())
    {
        if (dom.HasMember("node_tig") && dom["node_tig"].IsInt())
        {
            n.tig=dom["node_tig"].GetInt();
        }

        if (dom.HasMember("node_name") && dom["node_name"].IsString())
        {
            n.name=dom["node_name"].GetString();
        }

        if (dom.HasMember("node_info") && dom["node_info"].IsString())
        {
            n.info=dom["node_info"].GetString();
        }

        if (dom.HasMember("node_param") && dom["node_param"].IsString())
        {
            n.param=dom["node_param"].GetString();
        }

        if (dom.HasMember("node_intype") && dom["node_intype"].IsArray())
        {
            const rapidjson::Value& arr = dom["node_intype"];

            for(unsigned int i=0;i<arr.Size();i++)
            {
                if (arr[i].HasMember("in") && arr[i]["in"].IsString())
                {
                    n.intype.append(arr[i]["in"].GetString());
                }

                if (arr[i].HasMember("info") && arr[i]["info"].IsString())
                {
                    n.intype_info.append(arr[i]["info"].GetString());
                }

                if (arr[i].HasMember("inside") && arr[i]["inside"].IsInt())
                {
                    n.inList_inside.append(arr[i]["inside"].GetInt());
                }
            }
        }

        if(n.intype.size() != n.intype_info.size() || n.intype.size() !=  n.inList_inside.size())
        {
            qDebug()<<"节点输入("+QString::number(n.intype.size())+")，输入描述("+QString::number(n.intype_info.size())+")，节点内输入变量("+QString::number(n.inList_inside.size())+")无法一一对应！";
            n.tig=9999999;
            return n;
        }

        if (dom.HasMember("node_outtype") && dom["node_outtype"].IsArray())
        {
            const rapidjson::Value& arr = dom["node_outtype"];

            for(unsigned int i=0;i<arr.Size();i++)
            {
                if (arr[i].HasMember("out") && arr[i]["out"].IsString())
                {
                    n.outtype.append(arr[i]["out"].GetString());
                }

                if (arr[i].HasMember("info") && arr[i]["info"].IsString())
                {
                    n.outtype_info.append(arr[i]["info"].GetString());
                }

                if (arr[i].HasMember("inside") && arr[i]["inside"].IsInt())
                {
                    n.outList_inside.append(arr[i]["inside"].GetInt());
                }
            }
        }

        if(n.outtype.size() != n.outtype_info.size() || n.outtype.size() !=  n.outList_inside.size())
        {
            qDebug()<<"节点输出("+QString::number(n.outtype.size())+")，输出描述("+QString::number(n.outtype_info.size())+")，节点内输出变量("+QString::number(n.outList_inside.size())+")无法一一对应！";
            n.tig=9999999;
            return n;
        }

        if (dom.HasMember("node_tree") && dom["node_tree"].IsString())
        {
            n.tree=dom["node_tree"].GetString();
        }

        if (dom.HasMember("node_data_inside") && dom["node_data_inside"].IsString())
        {
            n.data=dom["node_data_inside"].GetString();
        }

    }
    else
    {
        qDebug()<<"fail to parse json file:"+jsonpath;
        n.tig=9999999;
    }

    return n;
}

//节点信息写入
int nsv_json_analy::json_create_tree(node_cross n,QString path)
{
    rapidjson::StringBuffer buf;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buf); // it can word wrap

    writer.StartObject();

    writer.Key("m_tree");
    writer.String(n.tree.toUtf8());

    writer.Key("m_data");
    writer.String(n.data.toUtf8());

    writer.Key("node_list");
    writer.StartArray();

    for(int i=0;i<n.intype.size();i++)
    {
        writer.String(n.intype[i].toUtf8());
    }

    writer.EndArray();

    writer.EndObject();

    const char* json_content = buf.GetString();

    QString name= path+"/tree.json";
    QFile fp(name);
    fp.open(QIODevice::WriteOnly);
    fp.write(json_content);
    fp.close();

    return 0;
}

//节点信息读取
node_cross nsv_json_analy::json_read_tree(QString path)
{
    node_cross n;

    QString jsonpath=path+"/tree.json";

    QFile f(jsonpath);
    f.open(QIODevice::ReadOnly);
    QString src = f.readAll();
    f.close();

    std::string json_content = src.toUtf8().toStdString();

    rapidjson::Document dom;

    if (!dom.Parse(json_content.c_str()).HasParseError())
    {
        if (dom.HasMember("m_tree") && dom["m_tree"].IsString())
        {
            n.tree=dom["m_tree"].GetString();
        }

        if (dom.HasMember("m_data") && dom["m_data"].IsString())
        {
            n.data=dom["m_data"].GetString();
        }

        if (dom.HasMember("node_list") && dom["node_list"].IsArray())
        {
            const rapidjson::Value& arr = dom["node_list"];

            for(unsigned int i=0;i<arr.Size();i++)
            {
                n.intype.append(arr[i].GetString());
            }
        }
    }
    else
    {
        qDebug()<<"fail to parse json file:"+jsonpath;
        n.tig=9999999;
    }

    return n;
}
