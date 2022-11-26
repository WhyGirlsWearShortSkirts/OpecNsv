#ifndef BQGRAPHICSSCENE_H
#define BQGRAPHICSSCENE_H

#include <QGraphicsScene>
#include "custom/nsv_points.h"
#include "param/nsv_include.h"
#include <QPaintEvent>

class nobjectforlabelscene : public QGraphicsScene
{
    Q_OBJECT

signals:
    void updatePoint(QPointF p, QList<QPointF> list, bool isCenter);

    void mouse_point_move(QPointF p,QRectF r);

    void createFinished(QString,QList<QPointF>);

    void toOther();

public slots:

    void stop_paint(bool flag);

public:

    nobjectforlabelscene(QObject *parent = nullptr);

    bool is_creating_BPolygon;

    bool is_time_to_stop;

    bool is_tagging=false;

    int tagg_type=0;

    int Nib=100;

    QList<QPointF> point_list;

    void startCreate(bool creat_enable);

    QPointF uPoint=QPointF(0,0);

    QPointF pos;

protected:

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *) override;

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *) override;

    virtual void drawBackground(QPainter *painter, const QRectF &rect) override;

    virtual void drawForeground(QPainter *painter, const QRectF &rect) override;

public:
    labels_ui *ui_labels;

protected slots:

    void createFinish(QString label);


private slots:

};

#endif //BQGRAPHICSSCENE_H


