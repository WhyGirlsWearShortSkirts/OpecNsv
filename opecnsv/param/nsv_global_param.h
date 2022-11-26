#ifndef NSV_GLOBAL_PARAM_H
#define NSV_GLOBAL_PARAM_H

#include "param/nsv_include.h"

struct object_for_stats
{
    float 	cx;         //光心坐标

    float 	cy;

    int     x;          //光斑范围

    int     y;

    int     width;

    int     height;

    float 	size;		//光斑尺寸

    float   angle;

    std::vector<cv::Point> point_list;

    cv::Mat Img_point;  //光斑图像

    cv::Mat image_last;

    cv::Mat image_cut_all;

    cv::Mat image_cut;
};

struct result_for_stats
{
    QList<object_for_stats> object_stats;

    cv::Mat image_out;
};

struct result_for_hull
{
    QList<object_for_stats> hull_list;

    object_for_stats max_hull;
};

struct result_for_findC
{
    QList<object_for_stats> object_stats;

    QList<QList<QPointF>> point_list;

    QList<std::vector<cv::Rect2f>> angle_list;

    QList<int> Per_list;

    QList<float> legth_list;

    QList<float> width_list;

    QList<float> size_list;

    QList<float> rectsize_list;

    QList<float> cir_list;

    QList<float> pyl_list;

    QList<int> hull_size;

    cv::Mat image_out;

    int list_type;
};

struct result_for_fast
{
    cv::Mat image_out;

    std::vector<cv::KeyPoint> keypointlist;
};

struct nsv_object
{
    QString lables="";

    QList<QPointF> points;

    QString group_id="";

    QString shape_type="";

    QList<QString> flags;

    double angle=0;
};

struct nsv_objects_image
{
    bool flags_use=false;

    QString path;

    QString path_json;

    QList<nsv_object> objects;

    cv::Mat image;

    QString image_file;

    QByteArray image_data;

    int image_width;

    int image_height;

    QList<QString> flags;

    QList<QString> labels;

    QString sortlabels;

    QString version;

};

struct nsv
{

    bool flags_use=true;

    //预处理算子

    QString objectname="";

    bool image_alpha_beta_enable=false;

    float image_alpha=1;

    int image_beta=0;

    bool image_clur_enable=false;

    int image_clur=3;

    int image_split_type=0;

    int image_thresold=100;

    bool image_thresold_inv_enable=false;

    int image_thresold_inv=200;

    bool image_re_color=false;

    bool image_roi_enable=false;

    cv::Rect rect_cut;

    bool image_erdi_enable=false;

    int image_erdi=0;

    //结果输出

    int min_size=0;

    int max_size=999999999;

    int contours_type=0;

    int contours_size=5;

    bool other_enable=false;

    bool legth_enable=false;

    bool width_enable=false;

    bool cir_enable=false;

    bool pyl_enable=false;

    bool rectsize_enable=false;

    bool hullnum_enable=false;

    int min_legth=0;

    int max_legth=4000;

    int min_width=0;

    int max_width=4000;

    float min_cir=0;

    float max_cir=100;

    float min_pyl=0;

    float max_pyl=100;

    float min_rectsize=0;

    float max_rectsize=100;

    int min_hullnum=0;

    int max_hullnum=1000;

    int angle_type=0;

    float angle_com=0;

    bool angle_left=false;

    //高级算子

    bool color_extract=false;

    cv::Scalar extract_color=cv::Scalar(255,255,255);

    bool erdi_more=false;

    int erdi_legth=0;

    int erdi_width=0;

    int erdi_type=0;

    int erdi_dowhat=0;

    bool clane=false;

    bool clane_colour=false;

    int clane_type=0;

    float clane_clsize=0;

    cv::Size clane_size=cv::Size(0,0);

};

struct config
{
    QString imagelist_path="";

    float scale=1;

    int tip=0;
};

struct labels_sheel
{
    QList<QString> lables;

    QList<QColor> color;

};

struct expan_size
{
    float alpha_size=1;

    int beta_size=0;

    float scale_size=1;

};

struct rename_size
{
    QString name="image_nsv";

    int type=0;

    int single=1;

    QString filetype="bmp";
};

struct Item_save
{
    QList<QList<QPointF>> pointlist=QList<QList<QPointF>>{};

    int type=0;

    QList<QString> labels=QList<QString>{};

    QList<double> angle=QList<double>{};
};

#endif // NSV_GLOBAL_PARAM_H
