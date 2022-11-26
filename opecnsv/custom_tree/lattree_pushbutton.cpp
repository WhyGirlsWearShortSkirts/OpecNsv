#include "lattree_pushbutton.h"

//无图标按钮
LPushButton::LPushButton(QWidget* parent,int tip) : QPushButton(parent)
{
    m_tip=tip;
    connect(this,SIGNAL(clicked()),this,SLOT(ISclick()));
}

//点击响应
void LPushButton::ISclick()
{
    emit isClick(m_tip);
}

//图标按钮
LToolButton::LToolButton(QWidget *parent,int type,QRect where) : QToolButton(parent)
{
    if(type==0)
    {
        this->setMaximumSize(100,100);
        this->setMinimumSize(100,100);
        this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
     }
    else if(type==1)
    {
        this->setMaximumSize(100,15);
        this->setMinimumSize(100,15);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==2)
    {
        this->setMaximumSize(15,100);
        this->setMinimumSize(15,100);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==3)
    {
        this->setMaximumSize(100,30);
        this->setMinimumSize(100,30);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==4)
    {
        this->setMaximumSize(30,100);
        this->setMinimumSize(30,100);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==5)
    {
        this->setMaximumSize(15,40);
        this->setMinimumSize(15,40);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==6)
    {
        this->setMaximumSize(70,20);
        this->setMinimumSize(70,20);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==7)
    {
        this->setMaximumSize(30,40);
        this->setMinimumSize(30,40);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }

    m_where=where;
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    this->setStyleSheet(style_this.pushButton);
    connect(this,SIGNAL(clicked()),this,SLOT(ISclick()));
}

//重构（只设置类型）
LToolButton::LToolButton(QWidget *parent, int type) : QToolButton(parent)
{
    if(type==0)
    {
        this->setMaximumSize(100,100);
        this->setMinimumSize(100,100);
        this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
     }
    else if(type==1)
    {
        this->setMaximumSize(100,15);
        this->setMinimumSize(100,15);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==2)
    {
        this->setMaximumSize(15,100);
        this->setMinimumSize(15,100);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==3)
    {
        this->setMaximumSize(100,30);
        this->setMinimumSize(100,30);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==4)
    {
        this->setMaximumSize(30,100);
        this->setMinimumSize(30,100);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==5)
    {
        this->setMaximumSize(15,40);
        this->setMinimumSize(15,40);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==6)
    {
        this->setMaximumSize(70,20);
        this->setMinimumSize(70,20);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==7)
    {
        this->setMaximumSize(30,40);
        this->setMinimumSize(30,40);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }

    m_where=QRect(0,0,0,0);
    m_tig=0;
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    this->setStyleSheet(style_this.pushButton);
    connect(this,SIGNAL(clicked()),this,SLOT(ISclick()));
}

//重构（设置按钮编号）
LToolButton::LToolButton(QWidget *parent,int type,QRect where,int tig) : QToolButton(parent)
{
    if(type==0)
    {
        this->setMaximumSize(100,100);
        this->setMinimumSize(100,100);
        this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
     }
    else if(type==1)
    {
        this->setMaximumSize(100,15);
        this->setMinimumSize(100,15);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==2)
    {
        this->setMaximumSize(15,100);
        this->setMinimumSize(15,100);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==3)
    {
        this->setMaximumSize(100,30);
        this->setMinimumSize(100,30);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==4)
    {
        this->setMaximumSize(30,100);
        this->setMinimumSize(30,100);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==5)
    {
        this->setMaximumSize(15,40);
        this->setMinimumSize(15,40);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==6)
    {
        this->setMaximumSize(70,20);
        this->setMinimumSize(70,20);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }
    else if(type==7)
    {
        this->setMaximumSize(30,40);
        this->setMinimumSize(30,40);
        this->setToolButtonStyle(Qt::ToolButtonTextOnly);
    }

    m_where=where;
    m_tig=tig;
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    this->setStyleSheet(style_this.pushButton);
    connect(this,SIGNAL(clicked()),this,SLOT(ISclick()));
}

//被选中显示响应
void LToolButton::isMe(int tig)
{
    if(m_tig!=1000000)
    {
        if(tig==m_tig)
        {
            this->setStyleSheet(style_this.pushButton_click);
        }
        else
        {
            this->setStyleSheet(style_this.pushButton);
        }
    }
}

//点击响应
void LToolButton::ISclick()
{
    emit isClick(m_where);

    emit isClick(m_tig);

    emit isClick(m_where,m_tig);
}

//自定义图像显示label
LLabel::LLabel(QWidget *parent): QLabel(parent)
{

}

//切换显示状态
void LLabel::sethidd()
{
    if(this->isHidden())
    {
        this->setHidden(false);
    }
    else
    {
        this->setHidden(true);
    }
}

//显示图像
void LLabel::addImg(QImage img)
{
    QPixmap pix=QPixmap::fromImage(img);

    int height=this->height();

    QPixmap pix_s=pix.scaled(int(float(pix.width())/float(pix.height())*height),height);

    this->setPixmap(pix_s);
}

//自定义图像显示view
LView::LView(QWidget *parent) : QGraphicsView(parent)
{
    setMouseTracking(true);
    setRenderHint(QPainter::Antialiasing,true);

    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(&m_scene);

    m_scene.addItem(imageshow);
}

//画面缩放
float LView::scene_scale(float size)
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
    return size;
}

//添加图像
float LView::image_add(cv::Mat image)
{
    imagelist.push_back(image);
    float size = image_add(imagelist.size()-1);
    return size;
}

//添加图像
float LView::image_add(int tig)
{
  float size_scale_image=1;

  if(tig>imagelist.size())
  {
      tig=0;
  }

  cv::Mat image=imagelist[tig];

  if(!image.empty())
  {
      widthandheight=QPoint(image.cols,image.rows);
      item_image(image,imageshow);
      float size_scale_width=float(size().width())/float(widthandheight.x());
      float size_scale_height=float(size().height())/float(widthandheight.y());
      size_scale_image=std::min(size_scale_width,size_scale_height);
      m_scene.setSceneRect(0,0,widthandheight.x(),widthandheight.y());
      this->update();
      size_scale_image=float(int(size_scale_image*100))/100;
      size_scale_image=scene_scale(size_scale_image);
      scaleValue=size_scale_image;
      m_scene.setSceneRect(0,0,m_scene.sceneRect().width(),m_scene.sceneRect().height());
  }
  this->update();

  return size_scale_image;
}

//显示图像
void LView::item_image(cv::Mat image,QGraphicsPixmapItem *item)
{
    QImage showimage = cq::cvMat2QImage(image);
    QPixmap src_dis = QPixmap::fromImage(showimage);
    item->setPixmap(src_dis);
}

//鼠标滚轮事件
void LView::wheelEvent(QWheelEvent *event)
{
    if(LongPress_ctrl and underMouse())
    {
        float scale=scaleValue;
        if(event->angleDelta().y() > 0 && scale<=size_max_scale)
        {
            scale += 0.01*2;
        }
        if(event->angleDelta().y() < 0 && scale >= size_min_scale)
        {
            scale -= 0.01*2;
        }

        scaleValue=scene_scale(scale);

    }
    update();
}

//键盘事件
void LView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Control:
        LongPress_ctrl = true;
        break;
    }
}

//键盘事件
void LView::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Control:
        LongPress_ctrl = false;
        break;
    }
}

//自定义按钮组
LButtonGroup::LButtonGroup(QWidget *parent) : QWidget(parent)
{
    m_btnPosition=0;
    m_curIndex=0;
    m_preIndex=0;
    m_offset=0;
    m_lineHeight=2;
    m_lineColor=QColor(21, 156, 119);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_btnGroup = new QButtonGroup(this);
    connect(m_btnGroup, SIGNAL(buttonClicked(int)), SLOT(onbuttonClicked(int)));

    m_animation = new QPropertyAnimation(this, "");
    m_animation->setDuration(200);
    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(onvalueChanged(QVariant)));

    //默认在上边
    setButtonPosition(LButtonGroup::North);
}

//析构
LButtonGroup::~LButtonGroup()
{

}

//数值切换响应
void LButtonGroup::onvalueChanged(QVariant variant)
{
    m_offset = variant.toInt();
    update();
}

//设置标识线长度
void LButtonGroup::setLineHeight(int lineHeight)
{
    m_lineHeight = lineHeight;
}

//绘制事件
void LButtonGroup::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(m_lineColor);
    if (m_btnPosition == LButtonGroup::North)
    {
        painter.drawRect(m_offset, 0, m_btnSize.width(), m_lineHeight);
    }
    else if (m_btnPosition == LButtonGroup::South)
    {
        painter.drawRect(m_offset, this->height() - m_lineHeight, m_btnSize.width(), m_lineHeight);
    }
    else if (m_btnPosition == LButtonGroup::West)
    {
        painter.drawRect(0, m_offset, m_lineHeight, m_btnSize.height());
    }
    else if (m_btnPosition == LButtonGroup::East)
    {
        painter.drawRect(this->width() - m_lineHeight, m_offset, m_lineHeight, m_btnSize.height());
    }
}

//设置标识线位置
void LButtonGroup::setButtonPosition(int position)
{
    deleteLayout();
    m_btnPosition = position;
    if (position == LButtonGroup::North)
    {
        QHBoxLayout* layout = new QHBoxLayout(this);
        layout->setContentsMargins(0, m_lineHeight, 0, 0);
        layout->setSpacing(2);
        this->setLayout(layout);
    }
    else if (position == LButtonGroup::South)
    {
        QHBoxLayout* layout = new QHBoxLayout(this);
        layout->setContentsMargins(0, 0, 0, m_lineHeight);
        layout->setSpacing(2);
        this->setLayout(layout);
    }
    else if (position == LButtonGroup::West)
    {
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->setContentsMargins(m_lineHeight, 0, 0, 0);
        layout->setSpacing(2);
        this->setLayout(layout);
    }
    else if (position == LButtonGroup::East)
    {
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->setContentsMargins(0, 0, m_lineHeight, 0);
        layout->setSpacing(2);
        this->setLayout(layout);
    }
    else
    {
        Q_ASSERT(false && "no match position!");
    }
}

//新增按钮
void LButtonGroup::addButton(QPushButton* btn, int id)
{
    m_btnGroup->addButton(btn, id);
    m_buttonLst.append(btn);
    layout()->addWidget(btn);
    m_btnSize = btn->size();

    QString style = QString("QPushButton{color:rgb(0,0,0);background-color:rgba(255,255,255,1);border:none;}"
        "QPushButton:hover{background-color:rgba(%1, %2, %3, 40);}"
        "QPushButton:pressed, "
        "QPushButton:checked{background-color:rgba(%1, %2, %3, 80);}")
        .arg(m_lineColor.red()).arg(m_lineColor.green()).arg(m_lineColor.blue());

    btn->setStyleSheet(style);
}

//设置按钮颜色
void LButtonGroup::setButtonColor(QColor color)
{
    m_lineColor = color;
}

//按钮按下响应
void LButtonGroup::onbuttonClicked(int index)
{
    m_btnGroup->button(index)->setChecked(true);
    m_preIndex = m_curIndex;
    m_curIndex = index;
    emit choose_buttons(index);
    if (m_btnPosition == LButtonGroup::North || m_btnPosition == LButtonGroup::South)
    {
        m_animation->setStartValue(m_preIndex * (m_btnSize.width()+2));
        m_animation->setEndValue(index * (m_btnSize.width()+2));
    }
    else if (m_btnPosition == LButtonGroup::West || m_btnPosition == LButtonGroup::East)
    {
        m_animation->setStartValue(m_preIndex * (m_btnSize.height()+2));
        m_animation->setEndValue(index * (m_btnSize.height()+2));
    }
    m_animation->start();
}

//删除所有控件
void LButtonGroup::deleteLayout()
{
    //清除布局，包括布局内控件
    if (this->layout() != nullptr)
    {
        QLayoutItem *child;
        while ((child = this->layout()->takeAt(0)) != 0)
        {
            if(child->widget())
            {
                this->layout()->removeWidget(child->widget());
                delete child;
                child->widget()->setHidden(1);
            }
        }
        m_buttonLst.clear();
        delete this->layout();
    }
}

//变量卡片
LDataCard::LDataCard(QWidget *parent, QRect where,data_cross d) : QGroupBox(parent)
{
    m_where=where;
    m_data=d;

    init_show();
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    this->setStyleSheet(style_this.pushButton);

    connect(m_main_button,SIGNAL(clicked()),this,SLOT(ISclick()));
    connect(m_check_button,SIGNAL(clicked()),this,SLOT(SetCheck()));
}

//初始化显示
void LDataCard::init_show()
{
    this->setMinimumSize(80,45);
    this->setMaximumSize(80,45);

    QVBoxLayout* data_box=new QVBoxLayout();

    data_box->setContentsMargins(0,0,0,0);
    data_box->setMargin(0);
    data_box->setSpacing(0);

    QHBoxLayout* Tool_box=new QHBoxLayout();

    Tool_box->setContentsMargins(0,0,0,0);
    Tool_box->setMargin(0);
    Tool_box->setSpacing(0);

    m_main_button->setText(m_data.name);

    m_main_button->setMaximumSize(65,22);
    m_main_button->setMinimumSize(65,22);

    if(m_data.isFixed)
    {
        m_check_button->setText("♦");
        m_check_button->setToolTip("常量(忽略)");
    }
    else
    {
        m_check_button->setText("♢");
        m_check_button->setToolTip("变量");
    }

    m_check_button->setMaximumSize(15,22);
    m_check_button->setMinimumSize(15,22);

    m_type_label->setText(m_data.type);

    if(m_data.attr==1)
    {
        m_type_label->setStyleSheet(style_this.data_input);
    }
    else if(m_data.attr==2)
    {
        m_type_label->setStyleSheet(style_this.data_output);
    }
    else if(m_data.attr==3)
    {
        m_type_label->setStyleSheet(style_this.data_link);
    }
    else
    {
        m_type_label->setStyleSheet(style_this.data_nouse);
    }

    m_type_label->setAlignment(Qt::AlignCenter);

    m_type_label->setMaximumSize(80,22);
    m_type_label->setMinimumSize(80,22);

    m_type_label->setToolTip(m_type_label->text());

    Tool_box->addWidget(m_main_button);

    Tool_box->addWidget(m_check_button);

    data_box->addLayout(Tool_box);

    data_box->addWidget(m_type_label);

    this->setLayout(data_box);
}

//被选中显示响应
void LDataCard::isMe(int tig)
{
    if(m_data.tig!=1000000)
    {
        if(tig==m_data.tig)
        {
            this->setStyleSheet(style_this.pushButton_click);
        }
        else
        {
            this->setStyleSheet(style_this.pushButton);
        }
    }
}

//点击响应
void LDataCard::ISclick()
{
    emit isClick(m_where);

    emit isClick(m_data.tig);

    emit isClick(m_where,m_data.tig);
}

//常量切换
void LDataCard::SetCheck()
{
    if(m_check_button->text()=="♦")
    {
        m_data.isFixed=false;
        m_check_button->setText("♢");
        m_check_button->setToolTip("变量");
    }
    else
    {
        m_data.isFixed=true;
        m_check_button->setText("♦");
        m_check_button->setToolTip("常量(忽略)");
    }
    emit data_back(m_data);
}

//流程卡
LParamCard::LParamCard(QWidget *parent, QRect where,int type,QList<param_cross> p,QList<data_cross> data_list)  : QGroupBox(parent)
{
    m_where=where;
    m_param=p;
    p_data_list=data_list;

    if(type==0)
    {
        init_Param();

        connect(start_ico,SIGNAL(clicked()),this,SLOT(IcoClick()));
    }
    else if(type==1)
    {
        init_Compare();
    }
//    connect(start_ico,SIGNAL(clicked()),this,SLOT(show_this()));
}

//流程卡
LParamCard::LParamCard(QWidget *parent, QRect where,int type,param_cross p,QList<data_cross> data_list)  : QGroupBox(parent)
{
    m_where=where;
    m_param.append(p);
    p_data_list=data_list;

    if(type==0)
    {
        init_Param();

        connect(start_ico,SIGNAL(clicked()),this,SLOT(IcoClick()));
    }
    else if(type==1)
    {
        init_Compare();
    }
//    connect(start_ico,SIGNAL(clicked()),this,SLOT(show_this()));
}

//流程卡信息
void LParamCard::show_this()
{
    for(int i=0;i<20;i++)
    {
        qDebug()<<"";
    }

    qDebug()<<"m_where"<<m_where<<"m_where.width()"<<m_where.width();

    qDebug()<<"m_param.size()"<<m_param.size();

    for(int i=0;i<m_param.size();i++)
    {
        nsv_image_tree::LDebug(m_param[i]);
    }

    qDebug()<<"=========================================================";
}

//初始化判断结构
void LParamCard::init_Compare()
{
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    this->setLayout(item_box);

    item_box->setContentsMargins(9,5,9,9);

    QFont font;
    font.setPointSize(9);

    QHBoxLayout* item_judge = new QHBoxLayout();

    QVBoxLayout* item_Compare = new QVBoxLayout();

    QLabel* direction = new QLabel();

    direction->setText("判断 ▼|▽");
    this->setStyleSheet(style_this.Compare);

    direction->setFont(font);
    direction->setMinimumHeight(15);
    direction->setMaximumHeight(15);

    item_Compare->addWidget(direction);

    start_ico->setText("✔/✖");

    start_ico->setToolTip(start_ico->text());

    start_ico->setStyleSheet(style_this.name);

    item_Compare->addWidget(start_ico);

    if(m_param.size()>0)
    {
        QLabel* label_c = new QLabel();

        label_c->setText("比较值：");

        label_c->setFont(font);

        item_Compare->addWidget(label_c);

        LToolButton* start_c=new LToolButton(this,3,QRect(1,0,m_where.width(),0));

        connect(start_c,SIGNAL(isClick(QRect,int)),this,SIGNAL(DataClick(QRect,int)));

        connect(this,SIGNAL(isYou(int)),start_c,SLOT(isMe(int)));

        if(m_param[0].inList.size()>1)
        {
            if(m_param[0].inList[1]-100000<p_data_list.size())
            {
                data_cross d=p_data_list[m_param[0].inList[1]-100000];
                start_c->setText(d.name);
                start_c->setTig(d.tig);
            }
            else
            {
                start_c->setText("-- NULL --");
                start_c->setStyleSheet(style_this.pushButton_error);
            }
        }
        else
        {
            start_c->setText("-- NULL --");
            start_c->setStyleSheet(style_this.pushButton_error);
        }

        item_Compare->addWidget(start_c);

        QLabel* label_a = new QLabel();

        label_a->setText("比较方式：");

        label_a->setFont(font);

        item_Compare->addWidget(label_a);

        LToolButton* start_a=new LToolButton(this,3,QRect(0,3,m_where.width(),0));

        connect(start_a,SIGNAL(isClick(QRect,int)),this,SIGNAL(DataClick(QRect,int)));

        connect(this,SIGNAL(isYou(int)),start_a,SLOT(isMe(int)));

        if(m_param[0].inList.size()>0)
        {
            if(m_param[0].inList[0]>300001 && m_param[0].inList[0]<300010 )
            {
                QString name;

                switch(m_param[0].inList[0])
                {
                case 300002:
                    name="＞";
                    break;
                case 300003:
                    name="≥";
                    break;
                case 300004:
                    name="＜";
                    break;
                case 300005:
                    name="≤";
                    break;
                case 300006:
                    name="＝";
                    break;
                case 300007:
                    name="≠";
                    break;
                default:break;
                }

                start_a->setText(name);
                start_a->setTig(m_param[0].inList[0]);
            }
            else
            {
                start_a->setText("-- NULL --");
                start_a->setStyleSheet(style_this.pushButton_error);
            }
        }
        else
        {
            start_a->setText("-- NULL --");
            start_a->setStyleSheet(style_this.pushButton_error);
        }

        item_Compare->addWidget(start_a);

        QLabel* label_nc = new QLabel();

        label_nc->setText("待比值：");

        label_nc->setFont(font);

        item_Compare->addWidget(label_nc);

        LToolButton* start_nc=new LToolButton(this,3,QRect(2,0,m_where.width(),0));

        connect(start_nc,SIGNAL(isClick(QRect,int)),this,SIGNAL(DataClick(QRect,int)));

        connect(this,SIGNAL(isYou(int)),start_nc,SLOT(isMe(int)));

        if(m_param[0].inList.size()>2)
        {
            if(m_param[0].inList[2]-100000<p_data_list.size())
            {
                data_cross d=p_data_list[m_param[0].inList[2]-100000];
                start_nc->setText(d.name);
                start_nc->setTig(d.tig);
            }
            else
            {
                start_nc->setText("-- NULL --");
                start_nc->setStyleSheet(style_this.pushButton_error);
            }
        }
        else
        {
            start_nc->setText("-- NULL --");
            start_nc->setStyleSheet(style_this.pushButton_error);
        }

        item_Compare->addWidget(start_nc);
    }

    QSpacerItem* ver=new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Expanding);

    item_Compare->addItem(ver);

    item_judge->addLayout(item_Compare);

    QVBoxLayout* item_true = new QVBoxLayout();

    QLabel* label_true = new QLabel();

    label_true->setText("✔: ▼");

    label_true->setFont(font);

    item_true->addWidget(label_true);

    if(m_param.size()>1)
    {
        LParamCard* item_start_1=new LParamCard(this,QRect(0,1,m_where.width()+1,0),0,m_param[1],p_data_list);

        connect(item_start_1,SIGNAL(isClick(QRect,int)),this,SIGNAL(isClick(QRect,int)));

        connect(item_start_1,SIGNAL(DataClick(QRect,int)),this,SIGNAL(DataClick(QRect,int)));

        connect(this,SIGNAL(isYou(int)),item_start_1,SIGNAL(isYou(int)));

        item_true->addWidget(item_start_1);
    }
    else
    {
        param_cross p;

        LParamCard* item_start_1=new LParamCard(this,QRect(0,1,m_where.width()+1,0),0,p,p_data_list);

        item_true->addWidget(item_start_1);
    }

    item_judge->addLayout(item_true);

    QVBoxLayout* item_false = new QVBoxLayout();

    QLabel* label_false = new QLabel();

    label_false->setText("✖: ▽");

    label_false->setFont(font);

    item_false->addWidget(label_false);

    if(m_param.size()>2)
    {
        LParamCard* item_start_2=new LParamCard(this,QRect(0,1,m_where.width()+2,0),0,m_param[2],p_data_list);

        connect(item_start_2,SIGNAL(isClick(QRect,int)),this,SIGNAL(isClick(QRect,int)));

        connect(item_start_2,SIGNAL(DataClick(QRect,int)),this,SIGNAL(DataClick(QRect,int)));

        connect(this,SIGNAL(isYou(int)),item_start_2,SIGNAL(isYou(int)));

        item_false->addWidget(item_start_2);
    }
    else
    {
        param_cross p;

        LParamCard* item_start_2=new LParamCard(this,QRect(0,1,m_where.width()+2,0),0,p,p_data_list);

        item_false->addWidget(item_start_2);
    }

    item_judge->addLayout(item_false);

    item_box->addLayout(item_judge);
}

//初始化流程
void LParamCard::init_Param()
{
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    this->setLayout(item_box);

    item_box->setContentsMargins(9,5,9,9);

    init_Param_Type();

    start_ico->setText(m_param[0].name);

    if(m_param[0].ico.isNull())
    {
        m_param[0].ico = QApplication::style()->standardIcon(QStyle::StandardPixmap(33));
    }

    start_ico->setIcon(m_param[0].ico);

    start_ico->setIconSize(QSize(80,80));

    start_ico->setToolTip(start_ico->text());

    item_box->addWidget(start_ico);

    init_Param_input();

    init_Param_output();

    QSpacerItem* ver=new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Expanding);

    item_box->addItem(ver);
}

//初始化流程类型
void LParamCard::init_Param_Type()
{
    QLabel* direction = new QLabel();

    if(m_param[0].tig>=200000 && m_param[0].tig<300000)
    {
        direction->setText("节点 |>");
        this->setStyleSheet(style_this.node);
    }
    else
    {
        direction->setText("算子 |>");
        this->setStyleSheet(style_this.param);
    }

    QFont font;
    font.setPointSize(9);
    direction->setFont(font);
    direction->setMinimumHeight(15);
    direction->setMaximumHeight(15);

    item_box->addWidget(direction);
}

//初始化流程输入
void LParamCard::init_Param_input()
{
    QLabel* input = new QLabel();

    input->setText("input:");

    item_box->addWidget(input);

    for(int i=0;i<m_param[0].intype.size();i++)
    {
        if(m_param[0].intype[i]!="")
        {
            LToolButton* start_input=new LToolButton(this,3,QRect(i,0,m_where.width(),0));

            connect(start_input,SIGNAL(isClick(QRect,int)),this,SIGNAL(DataClick(QRect,int)));

            connect(this,SIGNAL(isYou(int)),start_input,SLOT(isMe(int)));

            start_input->setToolTip(m_param[0].intype_info[i]);

            if(i<m_param[0].inList.size())
            {
                if(m_param[0].inList[i]-100000<p_data_list.size())
                {
                    data_cross d=p_data_list[m_param[0].inList[i]-100000];
                    start_input->setText(d.name);
                    start_input->setTig(d.tig);
                }
                else
                {
                    start_input->setText("-- "+m_param[0].intype[i]+" --");
                    if(m_param[0].inList[i]==2000000)
                    {
                        start_input->setStyleSheet(style_this.pushButton_type_error);
                    }
                    else
                    {
                        start_input->setStyleSheet(style_this.pushButton_error);
                    }
                }
            }
            else
            {
                start_input->setText("-- "+m_param[0].intype[i]+" --");
                start_input->setStyleSheet(style_this.pushButton_error);
            }

            item_box->addWidget(start_input);
        }
    }
}

//初始化流程输出
void LParamCard::init_Param_output()
{
    QLabel* output = new QLabel();

    output->setText("output:");

    item_box->addWidget(output);

    for(int i=0;i<m_param[0].outtype.size();i++)
    {
        if(m_param[0].outtype[i]!="")
        {
            LToolButton* start_output=new LToolButton(this,3,QRect(i,2,m_where.width(),0));

            connect(start_output,SIGNAL(isClick(QRect,int)),this,SIGNAL(DataClick(QRect,int)));

            connect(this,SIGNAL(isYou(int)),start_output,SLOT(isMe(int)));

            start_output->setToolTip(m_param[0].outtype_info[i]);

            if(i<m_param[0].outList.size())
            {
                if(m_param[0].outList[i]-100000<p_data_list.size())
                {
                    data_cross d=p_data_list[m_param[0].outList[i]-100000];
                    start_output->setText(d.name);
                    start_output->setTig(d.tig);
                }
                else
                {
                    start_output->setText("== "+m_param[0].outtype[i]+" ==");
                    if(m_param[0].outList[i]==2000000)
                    {
                        start_output->setStyleSheet(style_this.pushButton_type_error);
                    }
                    else
                    {
                        start_output->setStyleSheet(style_this.pushButton_error);
                    }
                }
            }
            else
            {
                start_output->setText("== "+m_param[0].outtype[i]+" ==");
                start_output->setStyleSheet(style_this.pushButton_error);
            }

            item_box->addWidget(start_output);
        }
    }
}

//点击响应
void LParamCard::IcoClick()
{
    emit isClick(m_where,m_param[0].tig);
}
