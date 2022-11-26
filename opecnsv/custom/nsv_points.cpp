#include "nsv_points.h"

NPointItem::NPointItem(QAbstractGraphicsShapeItem* parent, QPointF p, PointType type): QAbstractGraphicsShapeItem(parent), m_point(p), m_type(type)
{
    this->setPos(m_point);

    this->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable |QGraphicsItem::ItemIsFocusable);

    switch (type)//设置鼠标悬浮效果
    {
    case Center:
        this->setCursor(Qt::OpenHandCursor);
        break;
    case Edge:
        this->setCursor(Qt::PointingHandCursor);
        break;
    case rotate:
        this->setCursor(Qt::OpenHandCursor);
        break;
    case Edge_n:
        this->setCursor(Qt::ForbiddenCursor);
        break;
    default: break;
    }
}

QRectF NPointItem::boundingRect() const
{
    return QRectF(point_size.x()-3,point_size.y()-3,point_size.width()+6,point_size.height()+6);
}

void NPointItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::PenStyle::NoPen);
    painter->setBrush(this->brush());
    this->setPos(m_point);

    switch (m_type)//设置绘点形状
    {
    case Center:
        break;
    case Edge:
        painter->drawRect(point_size);
        break;
    case rotate:
        painter->drawRect(point_size);
        break;
    case Edge_n:
        painter->drawEllipse(point_size);
        break;
    default:break;
    }

    if(this->parentItem()!=NULL)
    {
        this->parentItem()->scene()->update();
    }
    else
    {
        this->scene()->update();
    }
}

void NPointItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if ( event->buttons() == Qt::LeftButton )
    {
        qreal dx = event->scenePos().x() - event->lastScenePos().x();
        qreal dy = event->scenePos().y() - event->lastScenePos().y();

        NGraphicsItem* item = static_cast<NGraphicsItem *>(this->parentItem());

        NGraphicsItem::ItemType itemType = item->getType();

        if(m_type==Edge)
        {
            if(item->flag_move)
            {
                m_point = this->mapToParent(event->pos());
                this->setPos(m_point);
                this->scene()->update();

                if(itemType==NGraphicsItem::ItemType::Polygon)
                {
                    NPolygon *polygon = dynamic_cast<NPolygon *>(item);
                    polygon->updatePolygon(QPointF(event->lastScenePos().x(), event->lastScenePos().y()),QPointF(event->scenePos().x(), event->scenePos().y()));
                }
            }
        }
        else if(m_type==Center)
        {
            if(item->flag_move)
            {
                NPolygon* item_p = static_cast<NPolygon *>(this->parentItem());
                if(item_p!=NULL)
                {
                    item_p->move(float(dx), float(dy));
                }

                this->scene()->update();
            }
        }
        else if(m_type==rotate)
        {
            if(item->flag_move)
            {
                NPolygon* item_p = static_cast<NPolygon *>(this->parentItem());
                if(item_p!=NULL)
                {
                    item_p->rotate(atanf(dy/1));
                }
                this->scene()->update();
            }
        }
    }
}

void NPointItem::focusInEvent(QFocusEvent *event)
{
    QGraphicsItem::focusInEvent(event);

    if(this->parentItem()!=NULL)
    {
        this->parentItem()->setFocus();
        this->parentItem()->update();
    }
    else
    {
        this->scene()->update();
    }


}

void NPointItem::focusOutEvent(QFocusEvent *event)
{
    QGraphicsItem::focusOutEvent(event);

    if(this->parentItem()!=NULL)
    {
        this->parentItem()->scene()->update();
    }
    else
    {
        this->scene()->update();
    }
}

QColor NPointItemList::setRandColor()
{
    QColor color=QColor(rand()%256, rand()%256, rand()%256, 200);
    this->setColor(color);
    return color;
}

void NPointItemList::setColor(const QColor color)
{
    for (auto &temp : *this)
    {
        temp->setBrush(QBrush(color));
    }
}

void NPointItemList::setVisible(bool visible)
{
    for (auto &temp : *this)
    {
        temp->setVisible(visible);
    }
}

NGraphicsItem::NGraphicsItem(QPointF center, QPointF edge, ItemType type): m_center(center), m_edge(edge), m_type(type)
{
    m_pen_noSelected.setColor(QColor(255, 255, 0, 127));
    m_pen_noSelected.setWidth(4);
    m_pen_isSelected.setColor(QColor(255, 100, 255, 200));
    m_pen_isSelected.setWidth(6);
    m_pen_isSelected.setStyle(Qt::DashDotDotLine);
    font_text.setPixelSize(22);

    this->setPen(m_pen_noSelected);
    this->setFlags(QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsMovable |
                   QGraphicsItem::ItemIsFocusable);
}

void NGraphicsItem::color(QColor color,QString label)
{
    m_pen_noSelected.setColor(color);
    this->setPen(m_pen_noSelected);
    m_label = label;
    update();
}

void NGraphicsItem::setFocusEnable(bool enable)
{
    use_focus=enable;

    if(!use_focus)
    {
        this->setPen(m_pen_noSelected);

        isfocus=false;
        rotate_point->setRect(QRectF(0,0,0,0));
        update();
    }
}

void NGraphicsItem::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
    if(use_focus)
    {
        this->setPen(m_pen_isSelected);

        isfocus=true;
        rotate_point->setRect(QRectF(-6,-6,12,12));
        rotate_point->setPoint(QPointF(m_center.x()+100,m_center.y()));
        update();
    }
}

void NGraphicsItem::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
    this->setPen(m_pen_noSelected);

    isfocus=false;
    rotate_point->setRect(QRectF(0,0,0,0));
    update();
}

NPolygon::NPolygon(ItemType type): NGraphicsItem(QPointF(0,0), QPointF(0,0), type)
{
    is_create_finished = false;
    m_type=type;
}

NPolygon::NPolygon(ItemType type, QList<QPointF> point,QRectF): NGraphicsItem(QPointF(0,0), QPointF(0,0), type)
{
    is_create_finished = false;
    m_type=type;
    if(type==Polygon)
    {
        for(int i=0;i<point.size();i++)
        {
            pushPoint(point[i],point,false);
        }
        pushPoint(QPointF(0,0),point,true);
        updatePolygon(QPointF(0,0),QPointF(0,0));
    }
    else if(type==Rectangle)
    {
        if(point.size()==2)
        {
            pushPoint(point[0],point,false);
            pushPoint(point[1],point,true);
        }
        else
        {
            QList<QPointF> pointc;
            pointc.append(point[0]);
            pointc.append(point[1]);
            pushPoint(point[0],point,false);
            pushPoint(point[1],point,true);
        }
        updatePolygon(QPointF(0,0),QPointF(0,0));
    }
}

NPolygon::~NPolygon()
{
    emit polygondelete(getPointlist());
}

void NPolygon::pushPoint(QPointF p, QList<QPointF> list, bool isCenter)
{
    if(m_type==Polygon)
    {
        if (!is_create_finished)
        {
            m_center = getCentroid(list);//获取中心点

            if (isCenter)//最后一个点
            {
                m_pointList.append(new NPointItem(this, m_center, NPointItem::Center));
                m_pointList.at(0)->setRect(QRectF(-4,-4,8,8));
                QColor color=m_pointList.setRandColor();//为所有点设置随机颜色，最后一个点之前固定

                rotate_point->setParentItem(this);
                rotate_point->setBrush(QBrush(color));
                rotate_point->setRect(QRectF(0,0,0,0));
                QPointF SCCENTER=mapToScene(m_center);
                rotate_point->setPoint(QPointF(SCCENTER.x()+100,SCCENTER.y()));
                is_create_finished = true;

                std::vector<cv::Point> pl=getCvPointlist();
                cv::RotatedRect poly=cv::minAreaRect(pl);
                if(poly.size.height<poly.size.width)
                {
                    m_angle=poly.angle+180;
                }
                else
                {
                    m_angle=(poly.angle+90)+180;
                }

                emit finishCreate();
            }
            else
            {

                NPointItem *point = new NPointItem(this, p, NPointItem::Edge);
                point->setParentItem(this);//设置父物体，说明该点归属于该物体
                m_pointList.append(point);
                m_pointList.setColor(QColor(255,0,200));
            }

            this->update();
        }
    }
    else
    {
        if (!is_create_finished)
        {
            m_center = getCentroid(list);//获取中心点

            if (isCenter)//最后一个点
            {
                NPointItem *point = new NPointItem(this, p, NPointItem::Edge);
                point->setParentItem(this);//设置父物体，说明该点归属于该物体
                m_pointList.append(point);
                m_pointList.setColor(QColor(255,0,200));

                m_pointList.append(new NPointItem(this, m_center, NPointItem::Center));
                m_pointList.at(0)->setRect(QRectF(-4,-4,8,8));
                m_pointList.setRandColor();//为所有点设置随机颜色，最后一个点之前固定
                is_create_finished = true;

                std::vector<cv::Point> pl=getCvPointlist();
                if(pl.size()>1)
                {
                    if(abs(pl[0].x-pl[1].x)>abs(pl[0].y-pl[1].y))
                    {
                        m_angle=0;
                    }
                    else
                    {
                        m_angle=270;
                    }
                }
                emit finishCreate();
            }
            else if(m_pointList.size()==0)
            {
                NPointItem *point = new NPointItem(this, p, NPointItem::Edge);
                point->setParentItem(this);//设置父物体，说明该点归属于该物体
                m_pointList.append(point);
                m_pointList.setColor(QColor(255,0,200));
            }

            this->update();
        }
    }
}

void NPolygon::removelastpoint()
{
    if(!is_create_finished)
    {
        if(m_pointList.size()>1)
        {
            m_pointList[m_pointList.size()-1]->setParentItem(NULL);
            m_pointList[m_pointList.size()-1]->scene()->removeItem(m_pointList[m_pointList.size()-1]);//我删我自己
            m_pointList.removeAt(m_pointList.size()-1);
        }
    }
}

void NPolygon::setcolor(QColor co,QString label)
{
    if(!is_create_finished)
    {
       color(co,label);
    }
}

QList<QPointF> NPolygon::rotate(float angle)
{
    QList<QPointF> pointflist_out;
    if(flag_move)
    {
        QList<QPointF> pointflist=getPointlist();
        QPointF center= m_pointList[m_pointList.size()-1]->getPoint();
        for(int i=0;i<m_pointList.size()-1;i++)
        {
            QPointF point=pointflist[i];
            float x_=point.x()-center.x();
            float y_=point.y()-center.y();
            QPointF pointP=DesToPolar(QPointF(x_,y_));
            float angle_now=(angle+pointP.x());
            QPointF pointD=PolarToDes(QPointF(angle_now,pointP.y()));
            QPointF point_now=QPointF(pointD.x()+center.x(),pointD.y()+center.y());
            pointflist_out.append(point_now);
        }

        if(isinscene(pointflist_out))
        {
            for(int i=0;i<pointflist_out.size();i++)
            {
                m_pointList[i]->setPoint(pointflist_out[i]);
            }
            updatePolygon(QPointF(0,0),QPointF(0,0));
        }
    }
    return pointflist_out;
}

QList<QPointF> NPolygon::move(float dx,float dy)
{
    QList<QPointF> pointflist_out;
    if(flag_move)
    {
        QList<QPointF> pointflist=getPointlist();
        for(int i=0;i<m_pointList.size()-1;i++)
        {
            QPointF point=pointflist[i];
            float x_=point.x()+dx;
            float y_=point.y()+dy;
            QPointF point_now=QPointF(x_,y_);
            pointflist_out.append(point_now);
        }

        if(isinscene(pointflist_out))
        {
            for(int i=0;i<pointflist_out.size();i++)
            {
                m_pointList[i]->setPoint(pointflist_out[i]);
            }
            QPointF point=rotate_point->getPoint();
            float x_=point.x()+dx;
            float y_=point.y()+dy;
            QPointF point_now=QPointF(x_,y_);
            rotate_point->setPoint(point_now);

            updatePolygon(QPointF(0,0),QPointF(0,0));
        }
    }
    return pointflist_out;
}

bool NPolygon::isinscene(QList<QPointF> point)
{
    bool flag=true;
    for(int i=0;i<point.size();i++)
    {
        if(point[i].x()<background_scene.x() || point[i].x()>background_scene.x()+background_scene.width())
        {
            flag=false;
            return flag;
        }

        if(point[i].y()<background_scene.y() || point[i].y()>background_scene.y()+background_scene.height())
        {
            flag=false;
            return flag;
        }
    }

    return flag;
}

QList<QPointF> NPolygon::getPointlist()
{
    QList<QPointF> pointlist;
    for(int i=0;i<m_pointList.size()-1;i++)
    {
        pointlist.append(m_pointList[i]->getPoint());
    }
    return pointlist;
}

std::vector<cv::Point> NPolygon::getCvPointlist()
{
    std::vector<cv::Point> pointlist;
    for(int i=0;i<m_pointList.size()-1;i++)
    {
        pointlist.push_back(cv::Point(m_pointList[i]->getPoint().x(),m_pointList[i]->getPoint().y()));
    }
    return pointlist;
}

bool NPolygon::point_isNear(QPointF point)
{
    if(is_create_finished)
    {
        updatePolygon(QPointF(0,0),QPointF(0,0));
        QPointF SCCENTER=mapToScene(m_center);
        if(sqrt(pow(point.x()-SCCENTER.x(),2)+pow(point.y()-SCCENTER.y(),2))<15)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(sqrt(pow(point.x()-m_pointList.at(0)->getPoint().x(),2)+pow(point.y()-m_pointList.at(0)->getPoint().y(),2))<10)
        {
            emit isnear(true);
            return true;
        }
        else
        {
            emit isnear(false);
            return false;
        }
    }

}

void NPolygon::mouse_point_change(QPointF point,QRectF rect)
{
    mouse_point=point;
    background_scene=rect;
    if(m_pointList.size()>0)
    {
        if(is_create_finished)
        {
            if(point_isNear(point))
            {
                m_pointList.at(m_pointList.size()-1)->setRect(QRectF(-12,-12,24,24));
                background_paint=getMaxLength();
            }
            else
            {
                m_pointList.at(m_pointList.size()-1)->setRect(QRectF(-6,-6,12,12));
                background_paint=QRectF(m_center.x() - 10, m_center.y() - 10, 20, 20);
            }
        }
        else
        {
            if(point_isNear(point))
            {
                m_pointList.at(0)->setRect(QRectF(-12,-12,24,24));
            }
            else
            {
                m_pointList.at(0)->setRect(QRectF(-4,-4,8,8));
            }
            background_paint=rect;
        }
        this->update();
    }
}

QRectF NPolygon::getMaxLength()
{
    QRectF rect=QRectF(0,0,0,0);
    qreal xmax=0,xmin=999999,ymax=0,ymin=999999;
    for(int i=0;i<m_pointList.size();i++)
    {
        qreal x=m_pointList[i]->getPoint().x();
        qreal y=m_pointList[i]->getPoint().y();
        if(x<xmin)
        {
            xmin=x;
        }

        if(y<ymin)
        {
            ymin=y;
        }

        if(x>xmax)
        {
            xmax=x;
        }

        if(y>ymax)
        {
            ymax=y;
        }
    }
    rect=QRectF(xmin,ymin,xmax-xmin,ymax-ymin);
    return rect;
}

QPointF NPolygon::getCentroid(QList<QPointF> list)
{
    qreal x = 0;
    qreal y = 0;
    for(auto &temp : list)
    {
        x += temp.x();
        y += temp.y();
    }
    x = x/list.size();
    y = y/list.size();
    return QPointF(x,y);
}

void NPolygon::updatePolygon(QPointF origin, QPointF end)
{
    QList<QPointF> list;

    for (auto &temp : m_pointList)
    {
        if (temp->getPoint() == origin)
        {
            temp->setPoint(end);
        }
        list.append(temp->getPoint());
    }

    m_center = getCentroid(list);
    m_pointList.at(m_pointList.size()-1)->setPoint(m_center);
}

QRectF NPolygon::boundingRect() const
{
    return background_paint;
}

void NPolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->setFont(font_text);

    QRectF rec=getMaxLength();

    QPointF rd(rec.x()+rec.width(),rec.y()+rec.height());

    if(m_type==Polygon)
    {
        if (is_create_finished)//结束时连接最后一个点和第一个点，m_pointlist中最后一个点是中心点
        {
            painter->drawText(rd+QPointF(10,0),m_label);

            for (int i = 1; i < m_pointList.size() - 1; i++)
            {
                painter->drawLine(m_pointList.at(i-1)->getPoint(), m_pointList.at(i)->getPoint());
            }

            painter->drawLine(m_pointList.at(m_pointList.size()-2)->getPoint(), m_pointList.at(0)->getPoint());

            if(flag_angle_show || isfocus)
            {
                QPointF last(m_angle,30);

                pt::drawCustomLine(painter,m_center-0.5*PolarToDes(last),m_center+0.5*PolarToDes(last));

                if(isfocus)
                {
                    painter->drawText(rd+QPointF(10,25),QString::number(m_angle));

                    if(pl_rect.size()>3)
                    {
                        for (unsigned long long int i = 1; i < pl_rect.size(); i++)
                        {
                            painter->drawLine(QPoint(pl_rect[i-1].x,pl_rect[i-1].y),QPoint(pl_rect[i].x,pl_rect[i].y));
                        }
                        painter->drawLine(QPoint(pl_rect[pl_rect.size()-1].x,pl_rect[pl_rect.size()-1].y),QPoint(pl_rect[0].x,pl_rect[0].y));
                    }
                }
            }
        }
        else
        {
            for (int i = 1; i < m_pointList.size(); i++)
            {
                painter->drawLine(m_pointList.at(i-1)->getPoint(), m_pointList.at(i)->getPoint());
            }

            if(m_pointList.size()>0)
            {
                if(mouse_point!=QPointF(0,0))
                {
                    painter->drawLine(m_pointList.at(m_pointList.size()-1)->getPoint(), mouse_point);
                }
            }
        }
    }
    else if(m_type==Rectangle)
    {
        if (is_create_finished)//结束时连接最后一个点和第一个点，m_pointlist中最后一个点是中心点
        {
            painter->drawText(rd+QPointF(10,0),m_label);

            painter->drawLine(m_pointList.at(0)->getPoint(), QPointF(m_pointList.at(0)->getPoint().x(),m_pointList.at(1)->getPoint().y()));
            painter->drawLine(m_pointList.at(1)->getPoint(), QPointF(m_pointList.at(0)->getPoint().x(),m_pointList.at(1)->getPoint().y()));
            painter->drawLine(m_pointList.at(1)->getPoint(), QPointF(m_pointList.at(1)->getPoint().x(),m_pointList.at(0)->getPoint().y()));
            painter->drawLine(m_pointList.at(0)->getPoint(), QPointF(m_pointList.at(1)->getPoint().x(),m_pointList.at(0)->getPoint().y()));

            if(flag_angle_show || isfocus)
            {
                QPointF last(m_angle,30);

                pt::drawCustomLine(painter,m_center-0.5*PolarToDes(last),m_center+0.5*PolarToDes(last));

                if(isfocus)
                {
                    painter->drawText(rd+QPointF(10,25),QString::number(m_angle));

                    if(pl_rect.size()>3)
                    {
                        for (unsigned long long int i = 1; i < pl_rect.size(); i++)
                        {
                            painter->drawLine(QPoint(pl_rect[i-1].x,pl_rect[i-1].y),QPoint(pl_rect[i].x,pl_rect[i].y));
                        }
                        painter->drawLine(QPoint(pl_rect[pl_rect.size()-1].x,pl_rect[pl_rect.size()-1].y),QPoint(pl_rect[0].x,pl_rect[0].y));
                    }
                }
            }
        }
        else
        {
            if(mouse_point!=QPointF(0,0))
            {
                painter->drawLine(m_pointList.at(0)->getPoint(),    QPointF(m_pointList.at(0)->getPoint().x(),mouse_point.y()));
                painter->drawLine(mouse_point,                      QPointF(m_pointList.at(0)->getPoint().x(),mouse_point.y()));
                painter->drawLine(mouse_point,                      QPointF(mouse_point.x(),m_pointList.at(0)->getPoint().y()));
                painter->drawLine(m_pointList.at(0)->getPoint(),    QPointF(mouse_point.x(),m_pointList.at(0)->getPoint().y()));
            }
        }
    }

    if(this->parentItem()!=NULL)
    {
        this->parentItem()->scene()->update();
    }
    else
    {
        this->scene()->update();
    }
}

NPolygon_Group::NPolygon_Group()
{
    init_Pen();

    this->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsFocusable);

    is_create_finished = false;
}

NPolygon_Group::NPolygon_Group(QList<QList<QPointF>> group, QList<QString> label)
{
    init_Pen();

    this->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsFocusable);

    Polygon_Group=group;

    label_group=label;

    background_paint=getMaxLength();

    is_create_finished = true;
}

NPolygon_Group::~NPolygon_Group()
{
    emit polygondelete(getgrouplist());
}

void NPolygon_Group::init_Pen()
{
    font_text.setPixelSize(20);
    pen_around.setBrush(QColor(120,0,120,200));
    pen_around.setWidth(4);
    pen_inside.setBrush(QColor(0,255,255,200));
    pen_inside.setWidth(3);
    pen_inside.setStyle(Qt::DashDotDotLine);
}

QRectF NPolygon_Group::getMaxLength()
{
    QRectF rect=QRectF(0,0,0,0);
    qreal xmax=0,xmin=999999,ymax=0,ymin=999999;
    for(int tip=0;tip<Polygon_Group.size();tip++)
    {
        QList<QPointF> pf=Polygon_Group[tip];
        for(int i=0;i<pf.size();i++)
        {
            qreal x=pf[i].x();
            qreal y=pf[i].y();
            if(x<xmin)
            {
                xmin=x;
            }

            if(y<ymin)
            {
                ymin=y;
            }

            if(x>xmax)
            {
                xmax=x;
            }

            if(y>ymax)
            {
                ymax=y;
            }
        }
    }
    rect=QRectF(xmin,ymin,xmax-xmin,ymax-ymin);
    return rect;
}

QRectF NPolygon_Group::getMaxLength(QList<QList<QPointF>> group)
{
    QRectF rect=QRectF(0,0,0,0);
    qreal xmax=0,xmin=999999,ymax=0,ymin=999999;
    for(int tip=0;tip<group.size();tip++)
    {
        QList<QPointF> pf=group[tip];
        for(int i=0;i<pf.size();i++)
        {
            qreal x=pf[i].x();
            qreal y=pf[i].y();
            if(x<xmin)
            {
                xmin=x;
            }

            if(y<ymin)
            {
                ymin=y;
            }

            if(x>xmax)
            {
                xmax=x;
            }

            if(y>ymax)
            {
                ymax=y;
            }
        }
    }
    rect=QRectF(xmin,ymin,xmax-xmin,ymax-ymin);
    return rect;
}

void NPolygon_Group::setFocusEnable(bool enable)
{
    use_focus=enable;
    if(!use_focus)
    {
        init_Pen();
        update();
    }
}

void NPolygon_Group::pushPolygon(QList<QPointF> p,QString label)
{
    if(!is_create_finished)
    {
        Polygon_Group.append(p);
        label_group.append(label);
        background_paint=getMaxLength();
    }
}

void NPolygon_Group::Create_Finished()
{
    is_create_finished=true;
    background_paint=QRectF(0,0,0,0);
}

QRectF NPolygon_Group::boundingRect() const
{
    return background_paint;
}

void NPolygon_Group::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
    if(use_focus)
    {
        QGraphicsItem::focusInEvent(event);
        font_text.setPixelSize(20);
        pen_around.setBrush(QColor(255,0,255,200));
        pen_around.setWidth(6);
        pen_inside.setBrush(QColor(0,100,100,200));
        pen_inside.setWidth(5);
        pen_inside.setStyle(Qt::DashDotDotLine);
        update();
    }
}

void NPolygon_Group::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
    QGraphicsItem::focusInEvent(event);
    init_Pen();
    update();
}

void NPolygon_Group::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(this->brush());
    painter->setFont(font_text);

    for(int i=0;i<Polygon_Group.size();i++)
    {        
        if(i==0)
        {
            painter->setPen(pen_around);
            if(Polygon_Group[i].size()>2)
            {
                for (int t = 1; t < Polygon_Group[i].size(); t++)
                {
                    painter->drawLine(Polygon_Group[i][t-1], Polygon_Group[i][t]);
                }

                painter->drawLine(Polygon_Group[i][Polygon_Group[i].size()-1],Polygon_Group[i][0]);
            }
        }
        else
        {
            painter->setPen(pen_inside);
            if(Polygon_Group[i].size()>2)
            {
                for (int t = 1; t < Polygon_Group[i].size(); t++)
                {
                    painter->drawLine(Polygon_Group[i][t-1], Polygon_Group[i][t]);
                }

                painter->drawLine(Polygon_Group[i][Polygon_Group[i].size()-1],Polygon_Group[i][0]);
            }
        }
        QRectF rec=getMaxLength(QList<QList<QPointF>>{Polygon_Group[i]});

        if(label_group.size()>i)
        {
            painter->drawText(QPointF(rec.x()+rec.width()+5,rec.y()+rec.height()),label_group[i]);
        }
        else
        {
            painter->drawText(QPointF(rec.x()+rec.width()+5,rec.y()+rec.height()),"-");
        }
    }
}

NArrow::NArrow(QGraphicsItem* parent):QGraphicsItem(parent)
{
}

NArrow::~NArrow()
{

}

void NArrow::setPen(const QPen &pen)
{
    m_pen=pen;
}

QRectF NArrow::boundingRect() const
{

}

void NArrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(m_pen);

    if(sqrt(pow(point_font.x()-point_back.x(),2)+pow(point_font.y()-point_back.y(),2))>30)
    {
        pt::drawCustomLine(painter,point_font,point_back);
    }
    else
    {
        painter->drawLine(point_font,point_back);
    }

    if(m_shadow.size()>=3 && use_shadow)
    {
        for (int i=1; i < m_shadow.size(); i++)
        {
            painter->drawLine(m_shadow[i-1],m_shadow[i]);
        }

        painter->drawLine(m_shadow[m_shadow.size()-1],m_shadow[0]);
    }

    if(this->parentItem()!=NULL)
    {
        this->parentItem()->scene()->update();
    }
    else
    {
        this->scene()->update();
    }
}

