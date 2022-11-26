#include "nsv_scene.h"

//自定义场景
nobjectforlabelscene::nobjectforlabelscene(QObject *parent) : QGraphicsScene(parent)
{
    setItemIndexMethod(QGraphicsScene::NoIndex);
    is_creating_BPolygon = false;
    is_time_to_stop = false;
    is_tagging =false;
    ui_labels=new labels_ui();
    connect(ui_labels,SIGNAL(push_label(QString)), this, SLOT(createFinish(QString)));
}

//多边形开始
void nobjectforlabelscene::startCreate(bool creat_enable)
{
    is_creating_BPolygon = creat_enable;
    point_list.clear();
}

//鼠标点击事件
void nobjectforlabelscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (is_creating_BPolygon)
    {
        QPointF p(event->scenePos().x(), event->scenePos().y());

        if(event->buttons()==Qt::LeftButton)
        {
            if (point_list.size() >= 3 && is_time_to_stop)
            {
                ui_labels->setWindowFlags(Qt::WindowStaysOnTopHint);
                ui_labels->exec();
            }
            else
            {
                if(point_list.size()==0)
                {
                    is_time_to_stop=false;
                }
                ui_labels->close();
                point_list.push_back(p);
                emit updatePoint(p, point_list, false);
            }

        }
    }
    else
    {
        QGraphicsScene::mousePressEvent(event);
    }
}

//停止绘制
void nobjectforlabelscene::stop_paint(bool flag)
{
    is_time_to_stop=flag;
}

//多边形结束
void nobjectforlabelscene::createFinish(QString label)
{
    if(tagg_type<2 && is_creating_BPolygon == true)
    {
        emit createFinished(label,point_list);
        emit updatePoint(uPoint, point_list, true);
        is_creating_BPolygon = false;
        point_list.clear();
    }
}

//鼠标移动事件
void nobjectforlabelscene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    pos=QPoint(event->scenePos().x(), event->scenePos().y());
    if(!ui_labels->isVisible())
    {
        emit mouse_point_move(pos,sceneRect());
    }
}

//绘制背景
void nobjectforlabelscene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter,rect);
//    painter->drawPixmap(rect,QPixmap(":/new/prefix1/icon/qipan.png"),QRect());
//    setBackgroundBrush(QBrush(QPixmap(":/new/prefix1/icon/qipan.png")));
}

//绘制前景
void nobjectforlabelscene::drawForeground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawForeground(painter,rect);

    if(true && is_tagging)
    {
        QPen pen;
        pen.setColor(QColor(127,127,127,255));
        painter->setPen(pen);
        if(tagg_type==2)
        {
            painter->drawEllipse(pos.x()-0.5*float(Nib),pos.y()-0.5*float(Nib),Nib,Nib);
        }
        else if(tagg_type==3)
        {
            painter->drawRect(pos.x()-0.5*float(Nib),pos.y()-0.5*float(Nib),Nib,Nib);
        }
        else if(tagg_type==4)
        {
            painter->drawEllipse(pos.x()-0.5*float(Nib),pos.y()-0.5*float(Nib),Nib,Nib);
        }
        else
        {
            painter->drawLine(pos,QPoint(0,pos.y()));
            painter->drawLine(pos,QPoint(100000,pos.y()));
            painter->drawLine(pos,QPoint(pos.x(),0));
            painter->drawLine(pos,QPoint(pos.x(),100000));
        }
    }

}

