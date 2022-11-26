#ifndef NOBIECTFORLABELITEM_H
#define NOBIECTFORLABELITEM_H

#include <QObject>
#include <QAbstractGraphicsShapeItem>
#include <QPointF>
#include <QPen>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QCursor>
#include <QKeyEvent>
#include <QList>
#include "math.h"
#include <QVector>
#include <QDebug>
#include <QMenu>
#include <QSpinBox>
#include <QWidgetAction>
#include "param/nsv_include.h"
#include "custom/nsv_scene.h"

namespace pt
{
    inline void drawCustomLine(QPainter * painter, QPointF startp, QPointF stopp)
    {
        painter->save();

        float theta1 = atan2f(stopp.y() - startp.y(), stopp.x() - startp.x());
        stopp = QPointF(stopp.x() - 10 * cosf(theta1), stopp.y() - 10 * sinf(theta1));

        if (startp.isNull() == false && stopp.isNull() == false) {
            QLineF line(startp, stopp);
            painter->drawLine(line);

            QLineF v = line.unitVector();
            if (!v.isNull()) {
                v.setLength(10);
                v.translate(QPointF(line.dx(), line.dy()));
                QLineF n = v.normalVector();
                n.setLength(n.length() * 0.5);
                QLineF n2 = n.normalVector().normalVector();
                QPointF p1 = v.p2();
                QPointF p2 = n.p2();
                QPointF p3 = n2.p2();
                if (p1.isNull() == false && p2.isNull() == false) {
                    QLineF lineA(p1, p2);
                    if (lineA.length() > 4) {
                        painter->drawLine(lineA);
                    }
                }
                if (p2.isNull() == false && p3.isNull() == false) {
                    QLineF lineB(p2, p3);
                    if (lineB.length() > 4) {
                        painter->drawLine(lineB);
                    }
                }
                if (p3.isNull() == false && p1.isNull() == false) {
                    QLineF lineC(p3, p1);
                    if (lineC.length() > 4) {
                        painter->drawLine(lineC);
                    }
                }
            }
        }
        painter->restore();
    }
}

// 自定义功能图元 - 点
class NPointItem : public QObject, public QAbstractGraphicsShapeItem
{
    Q_OBJECT

public:

    enum PointType
    {
        Center = 0, // 中心点
        Edge,       // 边缘点（可拖动改变图形的形状、大小）
        Edge_n,     // 边缘点（不可拖动）
        rotate,     // 旋转点
    };

    NPointItem(QAbstractGraphicsShapeItem* parent, QPointF p, PointType type);

    QPointF getPoint() { return m_point; }

    void setPoint(QPointF p) { m_point = p; }

    void setRect(QRectF rect) { point_size=rect;}

protected:

    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    virtual void focusInEvent(QFocusEvent *event) override;

    virtual void focusOutEvent(QFocusEvent *event) override;

private:

    QPointF m_point;

    QPointF last_point;

    PointType m_type;

    QRectF point_size=QRectF(-4, -4, 8, 8);
};

// 存放点的容器
class NPointItemList: public QList<NPointItem *>
{
public:
    QColor  setRandColor();
    void setColor(const QColor color);
    void setVisible(bool visible);
};

// 自定义图元 - 基础类
class NGraphicsItem : public QObject, public QAbstractGraphicsShapeItem
{
    Q_OBJECT

public:

    enum ItemType
    {
        Polygon=0,            // 多边形
        Rectangle=1,          //矩形
        Sort=2,               //分类
    };

    QPointF getCenter() { return m_center; }
    void setCenter(QPointF p) { m_center = p; }

    QPointF getEdge() { return m_edge; }
    void setEdge(QPointF p) { m_edge = p; }

    ItemType getType() { return m_type; }

    QString getlabel() { return m_label; }
    void setlabel(QString label) { m_label = label; }

    float getangle() { return m_angle; }
    void setangle(float angle) { m_angle = angle; }

    void color(QColor color,QString label);

    void setFocusEnable(bool enable);

    NPointItem *rotate_point=new NPointItem(this, QPointF(100,100), NPointItem::rotate);

    bool flag_move=true;

    bool flag_angle_show=true;

    bool isfocus=false;

protected:

    NGraphicsItem(QPointF center, QPointF edge, ItemType type);

    virtual void focusInEvent(QFocusEvent *event) override;

    virtual void focusOutEvent(QFocusEvent *event) override;

protected:

    QString m_label;
    QPointF m_center;
    QPointF m_edge;
    ItemType m_type;
    float m_angle=0;
    NPointItemList m_pointList;

    QPen m_pen_isSelected;
    QPen m_pen_noSelected;

    QFont font_text;

    bool use_focus=true;
};

// 多边形
class NPolygon : public NGraphicsItem
{
    Q_OBJECT

signals:

    void isnear(bool flag);

    void polygondelete(QList<QPointF>);

    void finishCreate();

public:

    enum {Type=UserType+10};

    virtual int type() const override{return Type;};

    NPolygon(ItemType type);

    NPolygon(ItemType type, QList<QPointF> point, QRectF rect);

    ~NPolygon();

    QPointF getCentroid(QList<QPointF> list);

    void updatePolygon(QPointF origin, QPointF end);

    bool point_isNear(QPointF point);

    QRectF getMaxLength();

    QList<QPointF> getPointlist();

    std::vector<cv::Point> getCvPointlist();

    void removelastpoint();

    bool isFinished(){return is_create_finished;};

    void setCreate(bool pl){is_create_finished=pl;};

public slots:

    void pushPoint(QPointF p, QList<QPointF> list, bool isCenter);

    void mouse_point_change(QPointF point,QRectF rect);

    void setcolor(QColor co, QString label);

    QList<QPointF> rotate(float angle);

    QList<QPointF> move(float dx, float dy);

protected:

    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;

protected:

    qreal m_radius;

    QPointF mouse_point;

    QRectF background_paint;

    QRectF background_scene;

    bool is_create_finished;

    std::vector<cv::Point> pl_rect;

protected slots:

    bool isinscene(QList<QPointF> point);

};

//多多边形
class NPolygon_Group : public QObject, public QAbstractGraphicsShapeItem
{
    Q_OBJECT

signals:

    void polygondelete(QList<QList<QPointF>>);

public:

    enum {Type=UserType+20};

    virtual int type() const override{return Type;};

    NPolygon_Group();

    NPolygon_Group(QList<QList<QPointF>> group, QList<QString> label);

    ~NPolygon_Group();

    void init_Pen();

    QRectF getMaxLength();

    QRectF getMaxLength(QList<QList<QPointF>> group);

    QList<QList<QPointF>> getgrouplist(){return Polygon_Group;};

    QList<QString> getlabellist(){return label_group;};

    bool isFinished(){return is_create_finished;};

    void setCreate(bool pl){is_create_finished=pl;};

    void setFocusEnable(bool enable);

public slots:

    void pushPolygon(QList<QPointF> p,QString label);

    void Create_Finished();

protected:

    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;

    virtual void focusInEvent(QFocusEvent *event) override;

    virtual void focusOutEvent(QFocusEvent *event) override;

protected:

    QList<QList<QPointF>> Polygon_Group;

    QList<QString> label_group;

    QRectF background_paint;

    bool is_create_finished;

    QPen pen_around;

    QPen pen_inside;

    QFont font_text;

    bool use_focus=true;
};

// 箭头线
class NArrow : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:

    enum {Type=UserType+30};

    virtual int type() const override{return Type;};

    NArrow(QGraphicsItem* parent = nullptr);

    ~NArrow();

    void setArrow(QPointF font,QPointF back){point_font=font;point_back=back;};

    void setShadow(QList<QPointF> shadow,bool enable){m_shadow=shadow;use_shadow=enable;};

    void setPen(const QPen &pen);

    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;

protected:

    QPointF point_font=QPointF(0,0);
    QPointF point_back=QPointF(0,0);
    QPen m_pen;

    QList<QPointF> m_shadow;

    bool use_shadow=false;
};

#endif // NOBIECTFORLABELITEM_H
