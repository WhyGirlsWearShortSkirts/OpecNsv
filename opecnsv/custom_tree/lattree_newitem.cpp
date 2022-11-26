#include "lattree_newitem.h"
#include "ui_lattree_newitem.h"

//构造函数
LatTree_NewItem::LatTree_NewItem(QWidget *parent,int type) :QDialog(parent),ui(new Ui::LatTree_NewItem)
{
    ui->setupUi(this);
    this->setWindowTitle("选择动作");

    ui->scrollArea->setMaximumWidth(500);
    ui->scrollArea->setMinimumWidth(500);

    ui->scrollArea_2->setMaximumWidth(250);
    ui->scrollArea_2->setMinimumWidth(250);

    m_color_list=init_color_label();

    ui->tabWidget->tabBar()->hide();//隐藏tab
    ui->tabWidget->setCurrentIndex(type);

    ui->tabWidget->setStyleSheet(style_this.item);
    ui->scrollArea->setStyleSheet(style_this.item);
    ui->scrollArea_2->setStyleSheet(style_this.item);
}

//析构
LatTree_NewItem::~LatTree_NewItem()
{
    delete ui;
}

//算子表显示
void LatTree_NewItem::setCroItem(QList<param_cross> p_l)
{
    m_param_c_list=p_l;

    deleteAllitemsOfLayout(ui->verticalLayout_all_action);

    for(int i=0;i<p_l.size();i++)
    {
        param_cross p=p_l[i];

        QGroupBox* group_item=new QGroupBox();

        group_item->setStyleSheet(style_this.param);

        QGridLayout* param_box=new QGridLayout();

        LPushButton* label_ico=new LPushButton(this,p.tig);
        connect(label_ico,SIGNAL(isClick(int)),this,SLOT(setTip(int)));
        connect(label_ico,SIGNAL(isClick(int)),this,SLOT(close()));

        label_ico->setMaximumSize(130,130);
        label_ico->setMinimumSize(130,130);

        param_box->addWidget(label_ico,0,0,3,3);

        if(p.ico.isNull())
        {
            QIcon icon = QApplication::style()->standardIcon(QStyle::StandardPixmap(33));
            label_ico->setIcon(icon);
        }
        else
        {
            label_ico->setIcon(p.ico);
        }
        QSize size = label_ico->size();

        label_ico->setIconSize(size);

        QTextBrowser* label_name=new QTextBrowser();

        label_name->setMaximumHeight(25);

        param_box->addWidget(label_name,0,4);

        QTextBrowser* label_info=new QTextBrowser();

        label_info->setMaximumHeight(45);

        param_box->addWidget(label_info,1,4);

        QTextBrowser* label_param=new QTextBrowser();

        label_param->setMaximumHeight(50);

        param_box->addWidget(label_param,2,4);

        label_name->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

        label_info->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

        label_param->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

        label_name->setText(p.name);

        label_info->setText(p.info);

        label_param->setText(p.param);

        group_item->setLayout(param_box);

        ui->verticalLayout_all_action->addWidget(group_item);
    }
}

//设置节点及算子表显示类型
void LatTree_NewItem::setHow(int tip)
{
    m_how_now=tip;
    if(itemlist_color_diffent)
    {
        m_howcolor=m_color_list[m_how_now-100000];
        ui->scrollArea->setStyleSheet(style_this.tite+"background-color:rgba("
                                         +QString::number(m_howcolor.red())+","
                                         +QString::number(m_howcolor.green())+","
                                         +QString::number(m_howcolor.blue())+",0.2);");
    }
}

//设置表类型（是否启用节点）
void LatTree_NewItem::showHow(bool show)
{
    if(show)
    {
        ui->scrollArea_2->setEnabled(1);
        ui->scrollArea_2->setHidden(0);
    }
    else
    {
        ui->scrollArea_2->setEnabled(0);
        ui->scrollArea_2->setHidden(1);
    }
}

//设置表类型（是否显示节点）
void LatTree_NewItem::hiddHow(bool show)
{
    if(show)
    {
        ui->scrollArea_2->setHidden(0);
    }
    else
    {
        ui->scrollArea_2->setHidden(1);
    }
}

//清空算子表显示
void LatTree_NewItem::clear_Action()
{
    deleteAllitemsOfLayout(ui->verticalLayout_all_action);
}

//节点表显示
void LatTree_NewItem::setNode(QList<node_cross> dolist)
{
    deleteAllitemsOfLayout(ui->verticalLayout_HowToDo);

    m_node_list=dolist;

    setHow(m_how_now);

    for(int i=0;i<dolist.size();i++)
    {
        node_cross p=dolist[i];

        QGroupBox* group_item=new QGroupBox();

        group_item->setStyleSheet(style_this.node);

        QGridLayout* param_box=new QGridLayout();

        LPushButton* label_ico=new LPushButton(this,p.tig);
        connect(label_ico,SIGNAL(isClick(int)),this,SLOT(setTip(int)));
        connect(label_ico,SIGNAL(isClick(int)),this,SLOT(close()));

        label_ico->setMinimumHeight(100);
        label_ico->setMaximumHeight(100);

        param_box->addWidget(label_ico,0,0);

        if(p.ico.isNull())
        {
            QIcon icon = QApplication::style()->standardIcon(QStyle::StandardPixmap(33));
            label_ico->setIcon(icon);
        }
        else
        {
            label_ico->setIcon(p.ico);
        }

        QSize size = label_ico->size();

        label_ico->setIconSize(size);

        QTextBrowser* label_name=new QTextBrowser();

        label_name->setMaximumHeight(25);

        label_name->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

        param_box->addWidget(label_name,1,0);

        QTextBrowser* label_info=new QTextBrowser();

        label_info->setMaximumHeight(45);

        label_info->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

        param_box->addWidget(label_info,2,0);

        QTextBrowser* label_param=new QTextBrowser();

        label_param->setMaximumHeight(50);

        label_param->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

        param_box->addWidget(label_param,3,0);

        label_name->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

        label_info->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

        label_param->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

        label_name->setText(p.name);

        label_info->setText(p.info);

        label_param->setText(p.param);

        group_item->setLayout(param_box);

        ui->verticalLayout_HowToDo->addWidget(group_item);
    }
}

//绘制事件
void LatTree_NewItem::paintEvent(QPaintEvent *event)
{
    QDialog::paintEvent(event);
}

//结构控制
void LatTree_NewItem::on_pushButton_2_clicked()
{
    m_tip_now=0;
    this->close();
}

//结构控制
void LatTree_NewItem::on_pushButton_clicked()
{
    m_tip_now=1;
    this->close();
}

//判断方式
void LatTree_NewItem::on_pushButton_4_clicked()
{
    m_tip_now=300002;
    this->close();
}

//判断方式
void LatTree_NewItem::on_pushButton_5_clicked()
{
    m_tip_now=300003;
    this->close();
}

//判断方式
void LatTree_NewItem::on_pushButton_8_clicked()
{
    m_tip_now=300004;
    this->close();
}

//判断方式
void LatTree_NewItem::on_pushButton_7_clicked()
{
    m_tip_now=300005;
    this->close();
}

//判断方式
void LatTree_NewItem::on_pushButton_6_clicked()
{
    m_tip_now=300006;
    this->close();
}

//判断方式
void LatTree_NewItem::on_pushButton_3_clicked()
{
    m_tip_now=300007;
    this->close();
}

