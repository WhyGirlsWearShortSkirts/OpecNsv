#ifndef NSHOWFORIMAGEVIEW_H
#define NSHOWFORIMAGEVIEW_H

#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QMapData>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QMouseEventTransition>
#include <QPoint>
#include <QObject>
#include "param/nsv_include.h"
#include "custom/nsv_points.h"
#include "custom/nsv_scene.h"

class Nshowforimageview : public QGraphicsView
{   Q_OBJECT

public:

signals:

    void returnbackroi(QPointF,QPointF);

    void scalechange(float);

    void colorset(QColor,QString);

    void labels_change(QList<QString>);

    void del_object(QList<QPointF>);

    void key_event(QKeyEvent *);

    void color_back(QColor,QPointF);

    void nowlabelschange(QList<QString>);

    void sortlabelchange(QString);

    void ocr_show(cv::Mat,cv::Rect,QString);

public:

    Nshowforimageview(QWidget *parent = nullptr);

    void init_Item();

    void init_penandfont();

    void init_color_label();

    void pos_updata(QPointF pos);

    void pos_updatashow();

    void roi_PaintEnable(bool enable);

    void roi_BeMax();

    void roi_BeMax(cv::Rect rect);

    void image_pyimage(cv::Mat image,bool enable);

    float image_add(cv::Mat image);

    float scene_scale(float size);

    void object_add_pointlist(QList<QList<QPointF>> point, QList<QString> label, QList<double> angle, int type,int from);

    void object_add_pointlist(bool taggingenable, int type,int from);

    void object_delete(QGraphicsItem *item);

    void object_clear();

    virtual void mousePressEvent(QMouseEvent *) override;

    virtual void mouseMoveEvent(QMouseEvent *) override;

    virtual void mouseReleaseEvent(QMouseEvent *) override;

    virtual void mouseDoubleClickEvent(QMouseEvent *) override;

    virtual void paintEvent(QPaintEvent *) override;

    virtual void wheelEvent(QWheelEvent *) override;

    virtual void keyPressEvent(QKeyEvent *) override;

    virtual void keyReleaseEvent(QKeyEvent *) override;

public:

    nobjectforlabelscene scene;

    QList<QString> label_list;

    QList<QColor> color_list;

    QList<QGraphicsItem *> ploygon_list;

    QList<Item_save> ploygon_back;

    QString clipboard_label;

    QList<QPointF> clipboard_point;

    QPointF clipboard_center;

    double clipboard_angle=0;

    int clipboard_type;

    QList<QString> nowlabels;

    QString sortlabel;

public slots:

    void object_labelset(QString label);

    void showornot(bool clear);

    cv::Mat getimage();

    void census_labels();

    void reset_sortlabel(QString label);

    void PolygontoGroup();

    void OpenOcrShow();

protected:

    cv::Mat Mask_NibPLine(std::vector<cv::Point> pl, cv::Mat image);

private:

    bool flag_noclear=true;

    bool flag_tag = false;

    int tag_type=0;

    int tag_from=0;

    bool flag_roi = false;

    bool flag_py = false;

    bool LongPress_ctrl= false;

    bool LongPress_alt= false;

    float Rotation_speed=1;

    bool LongPress_left= false;

    bool LongPress_right= false;

    bool LongPress_up= false;

    bool LongPress_down= false;

    float scaleValue=1;

    float size_min_scale=0.25;

    float size_max_scale=4;

    int Nib=100;

    std::vector<cv::Point> m_pl;

    QPoint widthandheight;

    QPoint pywidthandheight;

    QPointF pos_now;

    QPointF pos_down;

    QPointF centerAnchor;

    QPointF posAnchor;

    cv::Mat mask;

    cv::Mat image_now;

    QPen pen;
    QPen pen2;
    QPen pen_shadow;

    QFont font;
    QFont big_font;

    QPointF lastwhere;

    QPointF nowwhere;

    QRectF lastRectScene;

    QGraphicsRectItem *rectforpoint = new QGraphicsRectItem(0,0,400,20);

    QGraphicsRectItem *rectforimage = new QGraphicsRectItem();

    QGraphicsSimpleTextItem *posforpoint = new QGraphicsSimpleTextItem();

    QGraphicsPixmapItem *imageshow = new QGraphicsPixmapItem();

    QGraphicsPixmapItem *maskshow = new QGraphicsPixmapItem();

    QGraphicsPixmapItem *pyimageshow = new QGraphicsPixmapItem();

    QGraphicsRectItem *roi_image = new QGraphicsRectItem();

    QGraphicsTextItem *speed_show=new QGraphicsTextItem();

    NArrow *arr= new NArrow();
};

#endif // NSHOWFORIMAGEVIEW_H
