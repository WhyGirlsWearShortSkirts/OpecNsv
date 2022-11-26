#include "nsv_view.h"

//自定义view
Nshowforimageview::Nshowforimageview(QWidget *parent) : QGraphicsView(parent)
{
    setMouseTracking(true);
    setRenderHint(QPainter::Antialiasing,true);

    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(&scene);

    init_penandfont();
    init_Item();
    init_color_label();
}

//初始化部件
void Nshowforimageview::init_Item()
{
    rectforimage->setPen(Qt::PenStyle::NoPen);
    rectforimage->setBrush(QColor(255,0,0,255));

    scene.addItem(imageshow);

    roi_image->setPen(pen2);

    rectforpoint->setPen(Qt::PenStyle::NoPen);
    rectforpoint->setBrush(QColor(0,0,0,150));
    scene.addItem(rectforpoint);

    posforpoint->setPos(5,2);
    posforpoint->setPen(pen);
    posforpoint->setFont(font);
    posforpoint->setBrush(QColor(255,255,255,150));
    posforpoint->setText("pos     ");
    scene.addItem(posforpoint);

    QPointF SC00 = mapToScene(0,0);
    QPointF SC55 = mapToScene(5,2);
    posforpoint->setPos(SC55);
    rectforpoint->setPos(SC00);

    speed_show->setFont(big_font);
    speed_show->setPos(mapToScene(QPoint(this->width()/2,this->height()/2)-QPoint(520,164)));

    arr->setPen(pen_shadow);

    update();
}

//初始化画笔
void Nshowforimageview::init_penandfont()
{
    pen.setColor(QColor(255,255,255,150));
    pen.setWidth(1);

    pen2.setColor(QColor(255,0,0,255));
    pen2.setWidth(3);
    pen2.setStyle(Qt::DashDotDotLine);

    pen_shadow.setColor(QColor(0,150,230,150));
    pen_shadow.setWidth(4);

    font.setPointSize(11);
    big_font.setPointSize(200);
}

//初始化色彩集
void Nshowforimageview::init_color_label()
{
    color_list.append(QColor(255,0,0));
    color_list.append(QColor(0,255,0));
    color_list.append(QColor(0,0,255));

    color_list.append(QColor(255,255,0));
    color_list.append(QColor(255,0,255));
    color_list.append(QColor(0,255,255));

    color_list.append(QColor(127,255,0));
    color_list.append(QColor(255,127,0));
    color_list.append(QColor(127,0,255));
    color_list.append(QColor(255,0,127));
    color_list.append(QColor(0,127,255));
    color_list.append(QColor(0,255,127));

    color_list.append(QColor(255,127,127));
    color_list.append(QColor(127,255,127));
    color_list.append(QColor(127,127,255));

    color_list.append(QColor(127,255,255));
    color_list.append(QColor(255,127,255));
    color_list.append(QColor(255,255,127));

    color_list.append(QColor(127,0,0));
    color_list.append(QColor(0,127,0));
    color_list.append(QColor(0,0,127));

    color_list.append(QColor(127,127,0));
    color_list.append(QColor(127,0,127));
    color_list.append(QColor(0,127,127));

    color_list.append(QColor(255,0,0));
    color_list.append(QColor(0,255,0));
    color_list.append(QColor(0,0,255));

    color_list.append(QColor(255,255,0));
    color_list.append(QColor(255,0,255));
    color_list.append(QColor(0,255,255));

    color_list.append(QColor(127,255,0));
    color_list.append(QColor(255,127,0));
    color_list.append(QColor(127,0,255));
    color_list.append(QColor(255,0,127));
    color_list.append(QColor(0,127,255));
    color_list.append(QColor(0,255,127));

    color_list.append(QColor(255,127,127));
    color_list.append(QColor(127,255,127));
    color_list.append(QColor(127,127,255));

    color_list.append(QColor(127,255,255));
    color_list.append(QColor(255,127,255));
    color_list.append(QColor(255,255,127));

    color_list.append(QColor(127,0,0));
    color_list.append(QColor(0,127,0));
    color_list.append(QColor(0,0,127));

    color_list.append(QColor(127,127,0));
    color_list.append(QColor(127,0,127));
    color_list.append(QColor(0,127,127));

    color_list.append(QColor(255,0,0));
    color_list.append(QColor(0,255,0));
    color_list.append(QColor(0,0,255));

    color_list.append(QColor(255,255,0));
    color_list.append(QColor(255,0,255));
    color_list.append(QColor(0,255,255));

    color_list.append(QColor(127,255,0));
    color_list.append(QColor(255,127,0));
    color_list.append(QColor(127,0,255));
    color_list.append(QColor(255,0,127));
    color_list.append(QColor(0,127,255));
    color_list.append(QColor(0,255,127));

    color_list.append(QColor(255,127,127));
    color_list.append(QColor(127,255,127));
    color_list.append(QColor(127,127,255));

    color_list.append(QColor(127,255,255));
    color_list.append(QColor(255,127,255));
    color_list.append(QColor(255,255,127));

    color_list.append(QColor(127,0,0));
    color_list.append(QColor(0,127,0));
    color_list.append(QColor(0,0,127));

    color_list.append(QColor(127,127,0));
    color_list.append(QColor(127,0,127));
    color_list.append(QColor(0,127,127));
}

//画面缩放
float Nshowforimageview::scene_scale(float size)
{
    if(size<=size_min_scale)
    {
        size=size_min_scale;
    }
    else if(size>=size_max_scale)
    {
        size=size_max_scale;
    }
    scale(1/scaleValue,1/scaleValue);
    scale(size,size);
    scaleValue=size;
    emit scalechange(size);
    return size;
}

//添加图像
float Nshowforimageview::image_add(cv::Mat image)
{
    float size_scale_image=1;
    if(!image.empty())
    {
        image_now=image;
        widthandheight=QPoint(image.cols,image.rows);
        QImage showimage = cvMat2QImage(image);
        QPixmap src_dis = QPixmap::fromImage(showimage);
        mask=cv::Mat(image.size(),CV_8UC4,cv::Scalar(5,5,5,175));
        QImage showmask = cvMat2QImage(mask);
        QPixmap mask1 = QPixmap::fromImage(showmask);
        maskshow->setPixmap(mask1);
        imageshow->setPixmap(src_dis);

        float size_scale_width=float(size().width())/float(widthandheight.x());
        float size_scale_height=float(size().height())/float(widthandheight.y());
        size_scale_image=std::min(size_scale_width,size_scale_height);
        scene.setSceneRect(0,0,widthandheight.x(),widthandheight.y());
        update();
        size_scale_image=float(int(size_scale_image*100))/100;
        size_scale_image=scene_scale(size_scale_image);
        scaleValue=size_scale_image;
        scene.setSceneRect(0,0,scene.sceneRect().width(),scene.sceneRect().height());
    }
    update();

    return size_scale_image;
}

//底部小图显示
void Nshowforimageview::image_pyimage(cv::Mat image,bool enable)
{
    if(enable==true)
    {
        pywidthandheight=QPoint(image.cols,image.rows);

        QPointF SCM10M10=mapToScene(size().width()-pywidthandheight.x()-10,size().height()-pywidthandheight.y()-10);
        rectforimage->setRect(SCM10M10.x(),SCM10M10.y(),pywidthandheight.x()+10,pywidthandheight.y()+10);

        QImage showimage = cvMat2QImage(image);
        QPixmap src_dis = QPixmap::fromImage(showimage);
        pyimageshow->setPixmap(src_dis);

        QPointF SCM5M5=mapToScene(size().width()-pywidthandheight.x()-5,size().height()-pywidthandheight.y()-5);
        pyimageshow->setPos(SCM5M5);

        flag_py=true;

        scene.addItem(rectforimage);
        scene.addItem(pyimageshow);

        pos_updatashow();
    }
    else
    {
        scene.removeItem(rectforimage);
        scene.removeItem(pyimageshow);
        flag_py=false;
    }

    update();

}

//指针位置信息获取
void Nshowforimageview::pos_updata(QPointF pos)
{
    if(imageshow->isUnderMouse())
    {
        QColor color= imageshow->pixmap().toImage().pixelColor(pos.x(),pos.y());
        QString color_s=QString("(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue());
        if(flag_tag==true && !flag_py && !flag_roi && (tag_type==2 || tag_type==3 || tag_type==4) && tag_from==0)
        {
            posforpoint->setText("pos "+QString::number(int(pos.x()),10)+" "+QString::number(int(pos.y()),10)+" color:"+color_s+" Nib:"+QString::number(Nib));
        }
        else
        {
            posforpoint->setText("pos "+QString::number(int(pos.x()),10)+" "+QString::number(int(pos.y()),10)+" color:"+color_s);
        }
        update();
    }
}

//指针位置信息更新
void Nshowforimageview::pos_updatashow()
{
    scene.removeItem(posforpoint);
    scene.removeItem(rectforpoint);
    scene.addItem(rectforpoint);
    scene.addItem(posforpoint);
}

//ROI区域显示
void Nshowforimageview::roi_PaintEnable(bool enable)
{
    if(enable == true)
    {
        roi_image->setRect(imageshow->x()+1,imageshow->y()+1,widthandheight.x()-2,widthandheight.y()-2);
        scene.addItem(roi_image);
        flag_roi=true;
    }
    else
    {
        scene.removeItem(roi_image);
        flag_roi=false;
    }
    update();
}

//最大ROI
void Nshowforimageview::roi_BeMax()
{
    if(flag_roi==true)
    {
        nowwhere=QPointF(widthandheight.x(),widthandheight.y());
        lastwhere=QPointF(imageshow->x(),imageshow->y());
        roi_image->setRect(min(lastwhere.x(),nowwhere.x()),min(lastwhere.y(),nowwhere.y()),abs(nowwhere.x()-lastwhere.x()),abs(nowwhere.y()-lastwhere.y()));
        update();
        emit returnbackroi(lastwhere,nowwhere);
    }
}

//配置ROI
void Nshowforimageview::roi_BeMax(cv::Rect rect)
{
    if(flag_roi==true)
    {
        if(rect!=cv::Rect(0,0,0,0))
        {
            nowwhere=QPointF(rect.width+rect.x,rect.height+rect.y);
            lastwhere=QPointF(rect.x,rect.y);
            roi_image->setRect(min(lastwhere.x(),nowwhere.x()),min(lastwhere.y(),nowwhere.y()),abs(nowwhere.x()-lastwhere.x()),abs(nowwhere.y()-lastwhere.y()));
            update();
            emit returnbackroi(lastwhere,nowwhere);
        }

    }
}

//添加标定框（启用标定）
void Nshowforimageview::object_add_pointlist(bool taggingenable,int type,int from)
{
    flag_tag=taggingenable;
    scene.is_tagging=flag_tag;
    scene.tagg_type=type;
    tag_type=type;
    tag_from=from;
    if(tag_from!=2)
    {
        if(flag_tag)
        {
            if(tag_type==2 || tag_type==3 || tag_type==4)
            {
                scene.addItem(maskshow);
            }
            this->setCursor(Qt::CrossCursor);
            for(int i=0;i<ploygon_list.size();i++)
            {
                if(ploygon_list[i]->type()==QGraphicsItem::UserType+10)
                {
                    NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[i]);
                    item_b->flag_move=false;
                    item_b->setFocusEnable(false);
                }
            }
        }
        else
        {
            if(tag_type==2 || tag_type==3 || tag_type==4)
            {
                scene.removeItem(maskshow);
            }
            this->setCursor(Qt::ArrowCursor);
            for(int i=0;i<ploygon_list.size();i++)
            {
                if(ploygon_list[i]->type()==QGraphicsItem::UserType+10)
                {
                    NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[i]);
                    item_b->flag_move=true;
                    item_b->setFocusEnable(true);
                }
            }
        }
    }
}

//添加标定框（固定信息）
void Nshowforimageview::object_add_pointlist(QList<QList<QPointF>> point,QList<QString> label,QList<double> angle,int type,int from)
{
    scene.startCreate(true);
    if(scene.is_creating_BPolygon==true && point.size()>0 && from==0)
    {
        if(point[0]!=QList<QPointF>{})
        {
            if(type==1)
            {
                NPolygon *m_polygon = new NPolygon(NGraphicsItem::ItemType::Rectangle,point[0],scene.sceneRect());
                m_polygon->setlabel(label[0]);
                m_polygon->setangle(angle[0]);
                scene.addItem(m_polygon);
                ploygon_list.append(m_polygon);
                census_labels();
                connect(&scene, SIGNAL(mouse_point_move(QPointF,QRectF)), m_polygon, SLOT(mouse_point_change(QPointF,QRectF)));
                connect(m_polygon, SIGNAL(polygondelete(QList<QPointF>)), this, SIGNAL(del_object(QList<QPointF>)));
                if(label[0]!="")
                {
                    if(!StrinList(label[0],label_list))
                    {
                        label_list.append(label);
                        scene.ui_labels->addlistLabel(label_list);
                        emit labels_change(label_list);
                    }
                    int colortip=TipinList(label[0],label_list);
                    if(colortip<color_list.size())
                    {
                        m_polygon->color(color_list[colortip],label[0]);
                    }
                    else
                    {
                        m_polygon->color(color_list[color_list.size()-1],label[0]);
                    }
                }
                scene.is_creating_BPolygon=false;
                scene.stop_paint(false);
            }
            else
            {
                NPolygon *m_polygon = new NPolygon(NGraphicsItem::ItemType::Polygon,point[0],scene.sceneRect());
                m_polygon->setlabel(label[0]);
                m_polygon->setangle(angle[0]);
                if(flag_tag)
                {
                    m_polygon->flag_move=false;
                }
                scene.addItem(m_polygon);
                ploygon_list.append(m_polygon);
                census_labels();
                connect(&scene, SIGNAL(mouse_point_move(QPointF,QRectF)), m_polygon, SLOT(mouse_point_change(QPointF,QRectF)));
                connect(m_polygon, SIGNAL(polygondelete(QList<QPointF>)), this, SIGNAL(del_object(QList<QPointF>)));
                if(label[0]!="")
                {
                    if(!StrinList(label[0],label_list))
                    {
                        label_list.append(label);
                        scene.ui_labels->addlistLabel(label_list);
                        emit labels_change(label_list);
                    }
                    int colortip=TipinList(label[0],label_list);
                    if(colortip<color_list.size())
                    {
                        m_polygon->color(color_list[colortip],label[0]);
                    }
                    else
                    {
                        m_polygon->color(color_list[color_list.size()-1],label[0]);
                    }
                }
                scene.is_creating_BPolygon=false;
                scene.stop_paint(false);
            }
        }
    }
    else if(scene.is_creating_BPolygon==true && point.size()==0 && from==2)
    {
        NPolygon *m_polygon = new NPolygon(NGraphicsItem::ItemType::Sort,QList<QPointF>{},scene.sceneRect());
        m_polygon->setlabel(label[0]);
        scene.addItem(m_polygon);
        ploygon_list.append(m_polygon);
        census_labels();
        if(label[0]!="")
        {
            if(!StrinList(label[0],label_list))
            {
                label_list.append(label);
                scene.ui_labels->addlistLabel(label_list);
                emit labels_change(label_list);
            }
            int colortip=TipinList(label[0],label_list);
            if(colortip<color_list.size())
            {
                m_polygon->color(color_list[colortip],label[0]);
            }
            else
            {
                m_polygon->color(color_list[color_list.size()-1],label[0]);
            }
        }
        scene.is_creating_BPolygon=false;
        scene.stop_paint(false);
    }
    else if(scene.is_creating_BPolygon==true && point.size()>0 && from==1)
    {
        NPolygon_Group* Np=new NPolygon_Group(point,label);
        scene.addItem(Np);
        ploygon_list.append(Np);
        scene.is_creating_BPolygon=false;
        scene.stop_paint(false);
    }
}

//删除物体
void Nshowforimageview::object_delete(QGraphicsItem *item)
{
    if(item!=imageshow && item!=maskshow && item!=pyimageshow && item!=rectforpoint && item!=rectforimage && item!=posforpoint && item!=roi_image)
    {
        if(item != NULL && item->scene() != NULL)
        {
            if(item!=NULL && item->type()==QGraphicsItem::UserType+10)
            {
                NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(item);
                ploygon_list.removeOne(item_b);
                census_labels();
                scene.removeItem(item);  //移除

                try
                {
                    delete item;
                    item = NULL;
                }
                catch (...)
                {
                    qDebug()<<item;
                }

            }
            else if(item!=NULL && item->type()==QGraphicsItem::UserType+20)
            {
                NPolygon_Group *item_c = qgraphicsitem_cast<NPolygon_Group *>(item);
                ploygon_list.removeOne(item_c);
                scene.removeItem(item);//移除

                try
                {
                    delete item;
                    item = NULL;
                }
                catch (...)
                {
                    qDebug()<<item;
                }

            }
        }
        update();
    }
}

//显示或隐藏物体
void Nshowforimageview::showornot(bool clear)
{
    if(clear && flag_noclear)
    {
        for(int i=0;i<ploygon_list.size();i++)
        {
            try
            {
                scene.removeItem(ploygon_list[i]);
            }
            catch (...)
            {

            }
        }
        flag_noclear=false;
    }
    else if(!clear && !flag_noclear)
    {
        for(int i=0;i<ploygon_list.size();i++)
        {
            try
            {
                if(ploygon_list[i]->type()==QGraphicsItem::UserType+10)
                {
                    NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[i]);
                    if(item_b->parent()==nullptr)
                    {
                        scene.addItem(item_b);
                    }
                }
                else if(ploygon_list[i]->type()==QGraphicsItem::UserType+20)
                {
                    NPolygon_Group *item_b = qgraphicsitem_cast<NPolygon_Group *>(ploygon_list[i]);
                    if(item_b->parent()==nullptr)
                    {
                        scene.addItem(item_b);
                    }
                }
            }
            catch (...)
            {

            }
        }
        flag_noclear=true;
    }
}

//获取显示图像
cv::Mat Nshowforimageview::getimage()
{
    cv::Mat image_out=cv::Mat::zeros(1920,1080,CV_8UC3);
    if(!imageshow->pixmap().toImage().isNull())
    {
        image_out=QImage2cvMat(imageshow->pixmap().toImage());
    }
    return image_out;
}

//清空物体
void Nshowforimageview::object_clear()
{
    QList<QGraphicsItem *> item_list_p = scene.items();
    ploygon_list=QList<QGraphicsItem *>{};
    census_labels();
    ploygon_back=QList<Item_save>{};
    //删除所有选中的图元
    for(int i=0; i<item_list_p.size(); i++)
    {
        object_delete(item_list_p[i]);
    }
}

//设置物体标签
void Nshowforimageview::object_labelset(QString label)
{
    if(ploygon_list[ploygon_list.size()-1]->type()==QGraphicsItem::UserType+10)
    {
        if(tag_from==0)
        {
            NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[ploygon_list.size()-1]);
            item_b->setlabel(label);
            census_labels();
            if(!StrinList(label,label_list))
            {
                label_list.append(label);
                scene.ui_labels->addlistLabel(label_list);
                emit labels_change(label_list);
            }
            int colortip=TipinList(label,label_list);
            if(colortip<color_list.size())
            {
                emit colorset(color_list[colortip],label);
            }
            else
            {
                emit colorset(color_list[color_list.size()-1],label);
            }
            if(flag_tag==true)
            {
                scene.is_time_to_stop=false;
            }
        }
        else if(tag_from==1)
        {
            NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[ploygon_list.size()-1]);
            item_b->setlabel(label);
            if(flag_tag==true)
            {
                scene.is_time_to_stop=false;
            }
        }

    }
}

//多边形转多边形组
void Nshowforimageview::PolygontoGroup()
{
    if(tag_from==1)
    {
        NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[ploygon_list.size()-1]);
        NPolygon_Group * item_c = new NPolygon_Group();

        if(item_b->getType()==NGraphicsItem::ItemType::Polygon)
        {
            QList<QPointF> pl=item_b->getPointlist();
            QString la=item_b->getlabel();
            item_c->pushPolygon(pl,la);
        }
        else if(item_b->getType()==NGraphicsItem::ItemType::Rectangle)
        {
            QList<QPointF> pl=item_b->getPointlist();
            QString la=item_b->getlabel();
            QList<QPointF> pl_={pl[0],QPointF(pl[0].x(),pl[1].y()),pl[1],QPointF(pl[1].x(),pl[0].y())};
            item_c->pushPolygon(pl_,la);
        }
        object_delete(ploygon_list[ploygon_list.size()-1]);
        scene.addItem(item_c);
        ploygon_list.append(item_c);
    }
}

//获取截取图像
void Nshowforimageview::OpenOcrShow()
{
    try
    {
        if(ploygon_list[ploygon_list.size()-1]->type()==QGraphicsItem::UserType+20)
        {
            NPolygon_Group *item_c = qgraphicsitem_cast<NPolygon_Group *>(ploygon_list[ploygon_list.size()-1]);
            QRectF roi=item_c->getMaxLength();
            if(roi.width()!=0 && roi.height()!=0)
            {
                cv::Rect rect(roi.x(),roi.y(),roi.width(),roi.height());
                cv::Mat image_cut=image_now(rect);
                emit ocr_show(image_cut,rect,item_c->getlabellist()[0]);
            }

        }
        else if(ploygon_list[ploygon_list.size()-1]->type()==QGraphicsItem::UserType+10)
        {
            NPolygon *item_c = qgraphicsitem_cast<NPolygon *>(ploygon_list[ploygon_list.size()-1]);
            QRectF roi=item_c->getMaxLength();
            if(roi.width()!=0 && roi.height()!=0)
            {
                cv::Rect rect(roi.x(),roi.y(),roi.width(),roi.height());
                cv::Mat image_cut=image_now(rect);
                emit ocr_show(image_cut,rect,item_c->getlabel());
            }

        }
    }
    catch (...)
    {

    }
}

//重设图像分类标签
void Nshowforimageview::reset_sortlabel(QString label)
{
    sortlabel=label;
    for(int i=0;i<ploygon_list.size();i++)
    {
        if(ploygon_list[i]->type()==QGraphicsItem::UserType+10)
        {
            NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[i]);
            if(item_b->getType()==NGraphicsItem::ItemType::Sort)
            {
                item_b->setlabel(sortlabel);
            }
        }
    }

    census_labels();
}

//统计全局标签(数量)
void Nshowforimageview::census_labels()
{
    nowlabels.clear();
    sortlabel="";
    std::vector<int> label_num = std::vector<int>(label_list.size(),0);
    for(int i=0;i<ploygon_list.size();i++)
    {
        if(ploygon_list[i]->type()==QGraphicsItem::UserType+10)
        {
            NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[i]);
            if(item_b->getType()==NGraphicsItem::ItemType::Sort)
            {
                sortlabel=item_b->getlabel();
            }
            else
            {
                if(item_b->getlabel()!="")
                {
                    int tip=TipinList(item_b->getlabel(),label_list);
                    if(tip<label_list.size())
                    {
                        label_num[tip]+=1;
                    }
                    else
                    {
                        nowlabels.append(item_b->getlabel());
                    }
                }
            }
        }
    }

    for(unsigned long long int i=0;i<label_num.size();i++)
    {
        if(label_num[i]!=0)
        {
            nowlabels.append(label_list[i]+"("+QString::number(label_num[i])+")");
        }
    }

    emit nowlabelschange(nowlabels);
    emit sortlabelchange(sortlabel);
}

//点集补充
cv::Mat Nshowforimageview::Mask_NibPLine(std::vector<cv::Point> pl,cv::Mat image)
{
    cv::Mat image_out=image.clone();
    if(!image.empty())
    {
        for(unsigned long long int i=0;i<pl.size()-1;i++)
        {
            cv::line(image_out,pl[i],pl[i+1],cv::Scalar(0,127,255,100),Nib);
        }
    }
    return image_out;
}

//鼠标事件
void Nshowforimageview::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    if(event->buttons()==Qt::LeftButton && this->underMouse())
    {
        if(imageshow->isUnderMouse())
        {
            QColor color= imageshow->pixmap().toImage().pixelColor(QPoint(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()));
            emit color_back(color,mapToScene(event->pos()));
        }
        if(scene.focusItem()==NULL && LongPress_ctrl && LongPress_alt && !flag_roi && !flag_py && !flag_tag)
        {
            for(int i=0;i<ploygon_list.size();i++)
            {
                if(ploygon_list[i]->type()==QGraphicsItem::UserType+10)
                {
                    NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[i]);
                    item_b->flag_move=false;
                    item_b->setFocusEnable(false);
                }
            }
            if(clipboard_point!=QList<QPointF>() && clipboard_label!="")
            {
                pos_down=mapToScene(event->pos());
                scene.addItem(arr);
                arr->setArrow(pos_down,pos_down);
                arr->setShadow(QList<QPointF>{},false);
            }
        }
        if(flag_roi==true && imageshow->isUnderMouse() && !flag_py && !flag_tag)
        {
            lastwhere=mapToScene(event->pos().x(),event->pos().y());

            roi_image->setRect(lastwhere.x(),lastwhere.y(),widthandheight.x()-2-lastwhere.x(),widthandheight.y()-2-lastwhere.y());

            update();
        }
        if(flag_tag==true && !flag_py && !flag_roi && tag_from!=2 && !scene.ui_labels->isVisible())
        {
            if(tag_type==0)
            {
                if(scene.is_creating_BPolygon==false && scene.is_time_to_stop==false)
                {
                    scene.startCreate(flag_tag);
                    if(scene.is_creating_BPolygon==true)
                    {
                        NPolygon *m_polygon = new NPolygon(NGraphicsItem::ItemType::Polygon);
                        m_polygon->flag_move = false;
                        scene.addItem(m_polygon);
                        ploygon_list.append(m_polygon);
                        census_labels();
                        QList<QPointF> plist;
                        QPointF SCP=mapToScene(event->pos());
                        plist.append(QPoint(SCP.x(),SCP.y()));
                        m_polygon->pushPoint(QPoint(SCP.x(),SCP.y()),plist,false);
                        scene.point_list.append(SCP);
                        connect(&scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), m_polygon, SLOT(pushPoint(QPointF, QList<QPointF>, bool)));
                        connect(&scene, SIGNAL(mouse_point_move(QPointF,QRectF)), m_polygon, SLOT(mouse_point_change(QPointF,QRectF)));
                        connect(&scene, SIGNAL(createFinished(QString,QList<QPointF>)), this, SLOT(object_labelset(QString)));
                        connect(m_polygon, SIGNAL(isnear(bool)), &scene, SLOT(stop_paint(bool)));
                        connect(m_polygon, SIGNAL(polygondelete(QList<QPointF>)), this, SIGNAL(del_object(QList<QPointF>)));
                        connect(this,SIGNAL(colorset(QColor,QString)),m_polygon,SLOT(setcolor(QColor,QString)));
                        if(tag_from==1)
                        {
                            connect(m_polygon, SIGNAL(finishCreate()), this, SLOT(OpenOcrShow()));
                            connect(m_polygon, SIGNAL(finishCreate()), this, SLOT(PolygontoGroup()));
                        }
                    }
                }
            }
            else if(tag_type==1)
            {
                if(scene.is_creating_BPolygon==false && scene.is_time_to_stop==false)
                {
                    scene.startCreate(flag_tag);
                    if(scene.is_creating_BPolygon==true)
                    {
                        NPolygon *m_polygon = new NPolygon(NGraphicsItem::ItemType::Rectangle);
                        m_polygon->flag_move=false;
                        scene.addItem(m_polygon);
                        ploygon_list.append(m_polygon);
                        census_labels();
                        QList<QPointF> plist;
                        QPointF SCP=mapToScene(event->pos());
                        plist.append(QPoint(SCP.x(),SCP.y()));
                        m_polygon->pushPoint(QPoint(SCP.x(),SCP.y()),plist,false);
                        scene.point_list.append(SCP);
                        connect(&scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), m_polygon, SLOT(pushPoint(QPointF, QList<QPointF>, bool)));
                        connect(&scene, SIGNAL(mouse_point_move(QPointF,QRectF)), m_polygon, SLOT(mouse_point_change(QPointF,QRectF)));
                        connect(&scene,SIGNAL(createFinished(QString,QList<QPointF>)),this,SLOT(object_labelset(QString)));
                        connect(m_polygon, SIGNAL(polygondelete(QList<QPointF>)), this, SIGNAL(del_object(QList<QPointF>)));
                        connect(this,SIGNAL(colorset(QColor,QString)),m_polygon,SLOT(setcolor(QColor,QString)));
                        if(tag_from==1)
                        {
                            connect(m_polygon, SIGNAL(finishCreate()), this, SLOT(OpenOcrShow()));
                            connect(m_polygon, SIGNAL(finishCreate()), this, SLOT(PolygontoGroup()));
                        }
                    }
                }
            }
            else if(tag_type==2)
            {
                if(!mask.empty() && m_pl.size()==0)
                {
                    m_pl.push_back(cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()));
                    cv::circle(mask,cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()),0.5*float(Nib),cv::Scalar(0,127,255,100),-1);
                    QImage showmask = cvMat2QImage(mask);
                    QPixmap mask = QPixmap::fromImage(showmask);
                    maskshow->setPixmap(mask);
                }
            }
            else if(tag_type==3)
            {
                if(!mask.empty() && m_pl.size()==0)
                {
                    m_pl.push_back(cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()));
                    cv::rectangle(mask,cv::Rect(mapToScene(event->pos()).x()-0.5*float(Nib),mapToScene(event->pos()).y()-0.5*float(Nib),Nib,Nib),cv::Scalar(0,127,255,100),-1);
                    QImage showmask = cvMat2QImage(mask);
                    QPixmap mask = QPixmap::fromImage(showmask);
                    maskshow->setPixmap(mask);
                }
            }
            else if(tag_type==4)
            {
                if(!mask.empty() && m_pl.size()==0)
                {
                    m_pl.push_back(cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()));
                    cv::circle(mask,cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()),0.5*float(Nib),cv::Scalar(120,0,255,100),-1);
                    QImage showmask = cvMat2QImage(mask);
                    QPixmap mask = QPixmap::fromImage(showmask);
                    maskshow->setPixmap(mask);
                }
            }
        }
    }
    if(event->buttons()==Qt::RightButton && this->underMouse() && !flag_roi && !flag_py && !flag_tag)
    {
        centerAnchor = mapToScene(event->pos())-event->pos()+QPointF(width()/2,height()/2);
        posAnchor = event->pos();
    }
}

//鼠标事件
void Nshowforimageview::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    if(this->underMouse())
    {
        pos_now = mapToScene(event->pos());
        if(this->underMouse())
        {
            pos_updata(pos_now);
        }
        if(event->buttons()==Qt::LeftButton && scene.focusItem()==NULL && LongPress_ctrl && LongPress_alt && !flag_roi && !flag_py && !flag_tag)
        {
            if(clipboard_point!=QList<QPointF>() && clipboard_label!="")
            {
                QList<QPointF> pl;
                QPointF now=mapToScene(event->pos());
                QPointF angle=QPointF(0,0);
                if(now!=pos_down)
                {
                    angle=DesToPolar(QPointF(now.x()-pos_down.x(),now.y()-pos_down.y()));
                }
                for(int i=0;i<clipboard_point.size();i++)
                {
                    QPointF point=clipboard_point[i];
                    float x_=point.x()-clipboard_center.x();
                    float y_=point.y()-clipboard_center.y();
                    QPointF pointP=DesToPolar(QPointF(x_,y_));
                    float angle_now=(angle.x()+pointP.x()-clipboard_angle);
                    QPointF pointD=PolarToDes(QPointF(angle_now,pointP.y()));
                    QPointF point_now=QPointF(pointD.x()+clipboard_center.x(),pointD.y()+clipboard_center.y());
                    pl.append(point_now+pos_down-clipboard_center);
                }
                arr->setArrow(pos_down,mapToScene(event->pos()));
                arr->setShadow(pl,true);
            }
        }
        if(flag_roi==true && event->buttons()==Qt::LeftButton && this->underMouse() && !flag_py && !flag_tag)
        {
            nowwhere = mapToScene(event->pos());
            roi_image->setRect(min(lastwhere.x(),nowwhere.x()),min(lastwhere.y(),nowwhere.y()),abs(nowwhere.x()-lastwhere.x()),abs(nowwhere.y()-lastwhere.y()));
            update();
            emit returnbackroi(lastwhere,nowwhere);
        }
        if(event->buttons()==Qt::RightButton && !flag_roi && !flag_py && !flag_tag)
        {
            QPointF offsetPos = event->pos() - posAnchor;
            this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
            QPointF move=centerAnchor-offsetPos;
            this->centerOn(move);
            this->update();
        }
        if(event->buttons()==Qt::LeftButton && flag_tag==true && !flag_py && !flag_roi && tag_type==2 && tag_from!=2 && !scene.ui_labels->isVisible())
        {
            if(!mask.empty())
            {
                m_pl.push_back(cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()));
                cv::circle(mask,cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()),0.5*float(Nib),cv::Scalar(0,127,255,100),-1);
                QImage showmask = cvMat2QImage(mask);
                QPixmap mask = QPixmap::fromImage(showmask);
                maskshow->setPixmap(mask);
            }
        }
        if(event->buttons()==Qt::LeftButton && flag_tag==true && !flag_py && !flag_roi && tag_type==3 && tag_from!=2 && !scene.ui_labels->isVisible())
        {
            if(!mask.empty())
            {
                m_pl.push_back(cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()));
                cv::rectangle(mask,cv::Rect(mapToScene(event->pos()).x()-0.5*float(Nib),mapToScene(event->pos()).y()-0.5*float(Nib),Nib,Nib),cv::Scalar(0,127,255,100),-1);
                QImage showmask = cvMat2QImage(mask);
                QPixmap mask = QPixmap::fromImage(showmask);
                maskshow->setPixmap(mask);
            }
        }
        if(event->buttons()==Qt::LeftButton && flag_tag==true && !flag_py && !flag_roi && tag_type==4 && tag_from!=2 && !scene.ui_labels->isVisible())
        {
            if(!mask.empty())
            {
                m_pl.push_back(cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()));
                cv::circle(mask,cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()),0.5*float(Nib),cv::Scalar(120,0,255,100),-1);
                QImage showmask = cvMat2QImage(mask);
                QPixmap mask = QPixmap::fromImage(showmask);
                maskshow->setPixmap(mask);
            }
        }
    }
}

//鼠标事件
void Nshowforimageview::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    if(this->underMouse())
    {
        if(arr->isActive() && !flag_roi && !flag_py && !flag_tag)
        {
            if(clipboard_point!=QList<QPointF>() && clipboard_label!="")
            {
                QList<QPointF> pl;
                QPointF now=mapToScene(event->pos());
                QPointF angle=QPointF(0,0);
                scene.removeItem(arr);
                if(now!=pos_down)
                {
                    angle=DesToPolar(QPointF(now.x()-pos_down.x(),now.y()-pos_down.y()));
                }
                for(int i=0;i<clipboard_point.size();i++)
                {
                    QPointF point=clipboard_point[i];
                    float x_=point.x()-clipboard_center.x();
                    float y_=point.y()-clipboard_center.y();
                    QPointF pointP=DesToPolar(QPointF(x_,y_));
                    float angle_now=(angle.x()+pointP.x()-clipboard_angle);
                    QPointF pointD=PolarToDes(QPointF(angle_now,pointP.y()));
                    QPointF point_now=QPointF(pointD.x()+clipboard_center.x(),pointD.y()+clipboard_center.y());
                    pl.append(point_now+pos_down-clipboard_center);
                }
                object_add_pointlist(QList<QList<QPointF>>{pl},QList<QString>{clipboard_label},QList<double>{angle.x()-clipboard_angle},clipboard_type,0);
                census_labels();
                for(int i=0;i<ploygon_list.size();i++)
                {
                    if(ploygon_list[i]->type()==QGraphicsItem::UserType+10)
                    {
                        NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[i]);
                        item_b->flag_move=true;
                        item_b->setFocusEnable(true);
                    }
                }
            }
        }
        if(flag_roi==true && !flag_py && !flag_tag)
        {
            emit returnbackroi(lastwhere,nowwhere);
        }
        if(flag_tag==true && !flag_py && !flag_roi && tag_type==1 && scene.is_creating_BPolygon==true && tag_from!=2 && !scene.ui_labels->isVisible())
        {
            scene.uPoint=mapToScene(event->pos());
            scene.stop_paint(true);
            scene.ui_labels->setWindowFlags(Qt::WindowStaysOnTopHint);
            scene.ui_labels->exec();
        }
        if(flag_tag==true && !flag_py && !flag_roi && (tag_type==2 || tag_type==3)&& tag_from!=2 && !scene.ui_labels->isVisible())
        {
            if(!mask.empty() && m_pl.size()!=0)
            {
                m_pl.push_back(cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()));
                cv::Mat mask_item=mask.clone();
                mask_item=Mask_NibPLine(m_pl,mask_item);

                if(mask_item.channels()!=1)
                {
                    cv::cvtColor(mask_item,mask_item,cv::COLOR_BGR2GRAY);
                }
                cv::threshold(mask_item,mask_item,10,255,cv::THRESH_BINARY);

                result_for_findC result=image_FindPointstoMask(mask_item,image_now,false);

                scene.ui_labels->exec();
                mask=cv::Mat(cv::Size(widthandheight.x(),widthandheight.y()),CV_8UC4,cv::Scalar(5,5,5,175));
                QImage showmask = cvMat2QImage(mask);
                QPixmap mask1 = QPixmap::fromImage(showmask);
                maskshow->setPixmap(mask1);

                if(scene.ui_labels->now_label!="")
                {
                    for(int i=0;i<result.point_list.size();i++)
                    {
                        if(result.point_list[i].size()>2 && result.size_list[i]>100)
                        {
                            if(tag_from==0)
                            {
                                object_add_pointlist(QList<QList<QPointF>>{result.point_list[i]},QList<QString>{scene.ui_labels->now_label},QList<double>{0},0,0);
                            }
                            else if(tag_from==1)
                            {
                                object_add_pointlist(QList<QList<QPointF>>{result.point_list[i]},QList<QString>{scene.ui_labels->now_label},QList<double>{0},0,1);
                                OpenOcrShow();
                            }
                        }
                    }
                }

                m_pl.clear();
            }
        }
        if(flag_tag==true && !flag_py && !flag_roi && (tag_type==4) && tag_from!=2 && !scene.ui_labels->isVisible())
        {
            if(!mask.empty() && m_pl.size()!=0)
            {
                m_pl.push_back(cv::Point(mapToScene(event->pos()).x(),mapToScene(event->pos()).y()));
                cv::Mat mask_item=mask.clone();
                mask_item=Mask_NibPLine(m_pl,mask_item);

                if(mask_item.channels()!=1)
                {
                    cv::cvtColor(mask_item,mask_item,cv::COLOR_BGR2GRAY);
                }
                cv::threshold(mask_item,mask_item,10,255,cv::THRESH_BINARY);

                if(image_now.type()==CV_8UC3)
                {
                    result_for_findC result=image_FindPointstoMask(mask_item,image_now,true);
                    scene.ui_labels->exec();

                    mask=cv::Mat(cv::Size(widthandheight.x(),widthandheight.y()),CV_8UC4,cv::Scalar(5,5,5,175));
                    QImage showmask = cvMat2QImage(mask);
                    QPixmap mask1 = QPixmap::fromImage(showmask);
                    maskshow->setPixmap(mask1);

                    if(scene.ui_labels->now_label!="")
                    {
                        for(int i=0;i<result.point_list.size();i++)
                        {
                            if(result.point_list[i].size()>2 && result.size_list[i]>100)
                            {
                                if(tag_from==0)
                                {
                                    object_add_pointlist(QList<QList<QPointF>>{result.point_list[i]},QList<QString>{scene.ui_labels->now_label},QList<double>{0},0,0);
                                }
                                else if(tag_from==1)
                                {
                                    object_add_pointlist(QList<QList<QPointF>>{result.point_list[i]},QList<QString>{scene.ui_labels->now_label},QList<double>{0},0,1);
                                    OpenOcrShow();
                                }
                            }
                        }
                    }
                }
                m_pl.clear();
            }
        }
    }
}

//鼠标事件
void Nshowforimageview::mouseDoubleClickEvent(QMouseEvent *event)
{
    QGraphicsView::mouseDoubleClickEvent(event);
    if(event->buttons()==Qt::RightButton && !flag_roi && !flag_py && !flag_tag)
    {
        this->centerOn(QPointF(0,0));
        this->update();;
    }
    if(LongPress_ctrl==true && event->buttons()==Qt::LeftButton && !flag_roi && !flag_py && !flag_tag)
    {
        if(!scene.is_creating_BPolygon)
        {
            QGraphicsItem *item=scene.focusItem();
            if(item!=NULL && item->type()==QGraphicsItem::UserType+10)
            {
                try
                {
                    Item_save save;
                    NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(item);
                    if(item_b->getType()!=NGraphicsItem::ItemType::Sort)
                    {
                        save.pointlist.append(item_b->getPointlist());
                        save.type=item_b->getType();
                        save.labels.append(item_b->getlabel());
                        save.angle.append(item_b->getangle());
                        object_delete(item);
                    }

                    scene.ui_labels->exec();

                    if(save.type!=10000 && save.pointlist.size()>0)
                    {
                        if(scene.ui_labels->now_label!="")
                        {
                            object_add_pointlist(save.pointlist,QList<QString>{scene.ui_labels->now_label},save.angle,save.type,0);
                        }
                        else
                        {
                            object_add_pointlist(save.pointlist,save.labels,save.angle,save.type,0);
                        }
                    }
                }
                catch (...)
                {
                    qDebug()<<"修改标签失败！";
                }
            }
        }
    }
}

//绘制事件
void Nshowforimageview::paintEvent(QPaintEvent *event)
{
    rectforpoint->setRect(0,0,400/scaleValue,20/scaleValue);
    font.setPointSizeF(11/scaleValue);
    big_font.setPointSizeF(200/scaleValue);
    pen.setWidthF(1/scaleValue);
    posforpoint->setPen(pen);
    posforpoint->setFont(font);
    speed_show->setFont(big_font);

    QGraphicsView::paintEvent(event);
    QPointF SC00 = mapToScene(0,0);
    QPointF SC55 = mapToScene(5,2);
    posforpoint->setPos(SC55);
    rectforpoint->setPos(SC00);
    speed_show->setPos(mapToScene(QPoint(this->width()/2,this->height()/2)-QPoint(520,164)));

    if(flag_py==true)
    {
        QPointF SCM10M10=mapToScene(size().width()-pywidthandheight.x()-10,size().height()-pywidthandheight.y()-10);
        rectforimage->setRect(SCM10M10.x(),SCM10M10.y(),pywidthandheight.x()+10,pywidthandheight.y()+10);
        QPointF SCM5M5=mapToScene(size().width()-pywidthandheight.x()-5,size().height()-pywidthandheight.y()-5);
        pyimageshow->setPos(SCM5M5);
    }

    update();
}

//鼠标滚轮事件
void Nshowforimageview::wheelEvent(QWheelEvent *event)
{
    if(LongPress_ctrl and underMouse())
    {
        float scale=scaleValue;
        if(event->angleDelta().y() > 0 && scale<=size_max_scale)
        {
            scale += 0.01*Rotation_speed;
        }
        if(event->angleDelta().y() < 0 && scale >= size_min_scale)
        {
            scale -= 0.01*Rotation_speed;
        }

        scaleValue=scene_scale(scale);

    }
    if(flag_tag && !LongPress_ctrl && !flag_py && !flag_roi && (tag_type==2 || tag_type==3 || tag_type==4) && tag_from!=2)
    {
        if(event->angleDelta().y() > 0 && Nib<=10000)
        {
            Nib += Rotation_speed;
        }
        if(event->angleDelta().y() < 0 && Nib >= 0)
        {
            Nib -= Rotation_speed;
        }
        scene.Nib=Nib;
        pos_updata(pos_now);
    }

    QGraphicsItem *item=scene.focusItem();
    if(!flag_tag && !LongPress_ctrl && item!=NULL && item->type()==QGraphicsItem::UserType+10)
    {
        Item_save save;
        NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(item);
        if(item_b->getType()!=NGraphicsItem::ItemType::Sort)
        {
            float angle=item_b->getangle();
            if(event->angleDelta().y()>0)
            {
                if(angle+Rotation_speed>360)
                {
                    angle=angle-360;
                }
                item_b->setangle(angle+Rotation_speed);

            }
            else if(event->angleDelta().y()<0)
            {
                if(angle-Rotation_speed<0)
                {
                    angle=360-angle;
                }
                item_b->setangle(angle-Rotation_speed);
            }
        }
    }

    update();
}

//键盘事件
void Nshowforimageview::keyPressEvent(QKeyEvent *event)
{
    emit key_event(event);

    switch (event->key())
    {
    case Qt::Key_Control:
        LongPress_ctrl = true;
        break;

    case Qt::Key_Alt:
        LongPress_alt = true;
        break;

    case Qt::Key_F1:
        if(this->underMouse())
        {
            if(Rotation_speed==1)
            {
                Rotation_speed=5;
            }
            else if(Rotation_speed==5)
            {
                Rotation_speed=1;
            }
            speed_show->setHtml("<font color='#808080'> Speed:"+QString::number(Rotation_speed)+"</font>");
            scene.addItem(speed_show);
            QEventLoop eventloop;
            QTimer::singleShot(800, &eventloop, SLOT(quit()));
            eventloop.exec();
            scene.removeItem(speed_show);
        }
        break;

    case Qt::Key_Q:
        if(!flag_roi && !flag_py && !flag_tag)
        {
            QGraphicsItem *item=scene.focusItem();
            if(item!=NULL && item->type()==QGraphicsItem::UserType+10)
            {
                NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(item);
                Item_save save;
                save.pointlist.append(item_b->getPointlist());
                save.type=item_b->getType();
                save.labels.append(item_b->getlabel());
                save.angle.append(item_b->getangle());
                ploygon_back.append(save);
            }
            else if(item!=NULL && item->type()==QGraphicsItem::UserType+20)
            {
                NPolygon_Group *item_c = qgraphicsitem_cast<NPolygon_Group *>(item);
                Item_save save;
                save.pointlist=item_c->getgrouplist();
                save.type=10000;
                save.labels=item_c->getlabellist();
                save.angle.append(0);
                ploygon_back.append(save);
            }
            object_delete(item);
        }
        break;

    case Qt::Key_C:
        if(LongPress_ctrl && !flag_roi && !flag_py && !flag_tag)
        {
            QGraphicsItem *item=scene.focusItem();
            if(item!=NULL && item->type()==QGraphicsItem::UserType+10)
            {
                NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(item);
                if(item_b!=NULL)
                {
                    clipboard_point=item_b->getPointlist();
                    clipboard_label=item_b->getlabel();
                    clipboard_angle=item_b->getangle();
                    clipboard_center=item_b->getCenter();
                    if(item_b->getType()==NGraphicsItem::ItemType::Polygon)
                    {
                        clipboard_type=0;
                    }
                    else if(item_b->getType()==NGraphicsItem::ItemType::Rectangle)
                    {
                        clipboard_type=1;
                    }
                }
            }
        }
        break;

    case Qt::Key_E:
        if(!flag_roi && !flag_py && !flag_tag)
        {
            if(!scene.is_creating_BPolygon)
            {
                QGraphicsItem *item=scene.focusItem();

                if(item!=NULL && item->type()==QGraphicsItem::UserType+10)
                {
                    try
                    {
                        NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(item);
                        if(item_b->getType()!=NGraphicsItem::ItemType::Sort)
                        {
                            Item_save save;
                            save.pointlist.append(item_b->getPointlist());
                            save.type=item_b->getType();
                            save.labels.append(item_b->getlabel());
                            save.angle.append(item_b->getangle());
                            object_delete(item);

                            scene.ui_labels->exec();

                            if(save.type!=10000 && save.pointlist.size()>0)
                            {
                                if(scene.ui_labels->now_label!="")
                                {
                                    object_add_pointlist(save.pointlist,QList<QString>{scene.ui_labels->now_label},save.angle,save.type,0);
                                }
                                else
                                {
                                    object_add_pointlist(save.pointlist,save.labels,save.angle,save.type,0);
                                }
                            }
                        }
                    }
                    catch (...)
                    {
                        qDebug()<<"修改标签失败！";
                    }
                }
            }
        }
        break;

    case Qt::Key_V:
        if(LongPress_ctrl && !flag_roi && !flag_py && !flag_tag)
        {
            if(clipboard_point!=QList<QPointF>() && clipboard_label!="")
            {
                QList<QPointF> pl;
                for(int i=0;i<clipboard_point.size();i++)
                {
                    pl.append(clipboard_point[i]+pos_now-clipboard_center);
                }
                object_add_pointlist(QList<QList<QPointF>>{pl},QList<QString>{clipboard_label},QList<double>{clipboard_angle},clipboard_type,0);
                census_labels();
            }
        }
        break;

    case Qt::Key_Z:
        if(LongPress_ctrl && !flag_roi && !flag_py)
        {
            if(!scene.is_creating_BPolygon)
            {
                if(ploygon_list.size()>0)
                {
                    if(ploygon_list[ploygon_list.size()-1]->type()==QGraphicsItem::UserType+10)
                    {
                        NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[ploygon_list.size()-1]);
                        if(item_b->getType()==NGraphicsItem::ItemType::Sort)
                        {
                            if(ploygon_list.size()>1)
                            {
                                NPolygon *item_c = qgraphicsitem_cast<NPolygon *>(ploygon_list[ploygon_list.size()-2]);
                                Item_save save;
                                save.pointlist.append(item_c->getPointlist());
                                save.type=item_c->getType();
                                save.labels.append(item_c->getlabel());
                                save.angle.append(item_c->getangle());
                                ploygon_back.append(save);

                                object_delete(ploygon_list[ploygon_list.size()-2]);
                            }
                        }
                        else
                        {
                            Item_save save;
                            save.pointlist.append(item_b->getPointlist());
                            save.type=item_b->getType();
                            save.labels.append(item_b->getlabel());
                            save.angle.append(item_b->getangle());
                            ploygon_back.append(save);

                            object_delete(ploygon_list[ploygon_list.size()-1]);
                        }
                    }
                    else if(ploygon_list[ploygon_list.size()-1]->type()==QGraphicsItem::UserType+20)
                    {
                        NPolygon_Group *item_c = qgraphicsitem_cast<NPolygon_Group *>(ploygon_list[ploygon_list.size()-1]);
                        Item_save save;
                        save.pointlist=item_c->getgrouplist();
                        save.type=10000;
                        save.labels=item_c->getlabellist();
                        save.angle.append(0);
                        ploygon_back.append(save);

                        object_delete(ploygon_list[ploygon_list.size()-1]);
                    }
                }
            }
            else
            {
                if(ploygon_list.size() > 0)
                {
                    NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ploygon_list[ploygon_list.size()-1]);
                    item_b->removelastpoint();
                }
            }
        }
        break;

    case Qt::Key_Y:
        if(LongPress_ctrl && !flag_roi && !flag_py)
        {
            if(!scene.is_creating_BPolygon)
            {
                if(ploygon_back.size()>0)
                {
                    if(ploygon_back[ploygon_back.size()-1].type==10000)
                    {
                        object_add_pointlist(ploygon_back[ploygon_back.size()-1].pointlist,ploygon_back[ploygon_back.size()-1].labels,ploygon_back[ploygon_back.size()-1].angle,ploygon_back[ploygon_back.size()-1].type,1);
                    }
                    else
                    {
                        object_add_pointlist(ploygon_back[ploygon_back.size()-1].pointlist,ploygon_back[ploygon_back.size()-1].labels,ploygon_back[ploygon_back.size()-1].angle,ploygon_back[ploygon_back.size()-1].type,0);
                    }
                    ploygon_back.removeLast();
                }
            }
        }
        break;

    case Qt::Key_Up:
        LongPress_up=true;
        if(LongPress_left)
        {
            QCursor::setPos(QCursor::pos().x()-2*Rotation_speed,QCursor::pos().y()-2*Rotation_speed);
        }
        else if(LongPress_right)
        {
            QCursor::setPos(QCursor::pos().x()+2*Rotation_speed,QCursor::pos().y()-2*Rotation_speed);
        }
        else
        {
            QCursor::setPos(QCursor::pos().x(),QCursor::pos().y()-2*Rotation_speed);
        }
        break;

    case Qt::Key_Down:
        LongPress_down=true;
        if(LongPress_left)
        {
            QCursor::setPos(QCursor::pos().x()-2*Rotation_speed,QCursor::pos().y()+2*Rotation_speed);
        }
        else if(LongPress_right)
        {
            QCursor::setPos(QCursor::pos().x()+2*Rotation_speed,QCursor::pos().y()+2*Rotation_speed);
        }
        else
        {
            QCursor::setPos(QCursor::pos().x(),QCursor::pos().y()+2*Rotation_speed);
        }
        break;

    case Qt::Key_Left:
        LongPress_left=true;
        if(LongPress_up)
        {
            QCursor::setPos(QCursor::pos().x()-2*Rotation_speed,QCursor::pos().y()-2*Rotation_speed);
        }
        else if(LongPress_down)
        {
            QCursor::setPos(QCursor::pos().x()-2*Rotation_speed,QCursor::pos().y()+2*Rotation_speed);
        }
        else
        {
            QCursor::setPos(QCursor::pos().x()-2*Rotation_speed,QCursor::pos().y());
        }
        break;

    case Qt::Key_Right:
        LongPress_right=true;
        if(LongPress_up)
        {
            QCursor::setPos(QCursor::pos().x()+2*Rotation_speed,QCursor::pos().y()-2*Rotation_speed);
        }
        else if(LongPress_down)
        {
            QCursor::setPos(QCursor::pos().x()+2*Rotation_speed,QCursor::pos().y()+2*Rotation_speed);
        }
        else
        {
            QCursor::setPos(QCursor::pos().x()+2*Rotation_speed,QCursor::pos().y());
        }
        break;
    }
}

//键盘事件
void Nshowforimageview::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Control:
        LongPress_ctrl = false;
        break;
    case Qt::Key_Alt:
        LongPress_alt = false;
        break;
    case Qt::Key_Up:
        LongPress_up = false;
        break;
    case Qt::Key_Down:
        LongPress_down = false;
        break;
    case Qt::Key_Left:
        LongPress_left = false;
        break;
    case Qt::Key_Right:
        LongPress_right = false;
        break;
    }
}
