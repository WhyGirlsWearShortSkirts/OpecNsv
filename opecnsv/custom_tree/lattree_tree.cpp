#include "lattree_tree.h"

//交叉树
LActCross::LActCross(QWidget *parent): QGroupBox(parent)
{
    this->setLayout(root_box);

    this->setStyleSheet(style_this.back);

    m_tree="";

    init_box();
}

//设置默认变量类型
void LActCross::setdefaultType(QList<QString> type)
{
    m_data_ui->setdefaultType(type);
}

//获取树
tree_param LActCross::now_Tree()
{
    tree_param t;
    t.tree=m_tree;
    t.data=m_data;
    t.n_l=m_node_list;
    t.d_l=m_data_list;
    t.p_l=m_param_list;
    t.tree_img=getScrollArea(m_tree_widget);
    t.data_img=getScrollArea(m_data_widget);
    return t;
}

//设置树
void LActCross::set_Tree(tree_param t)
{
    m_tree=t.tree;
    m_data=t.data;
    m_node_list=t.n_l;
    m_data_list=t.d_l;
    init_item();
    init_data();
    init_tree();
}

//设置节点
void LActCross::set_Node(QList<node_cross> n_l)
{
    m_node_list=n_l;
    m_node_ui->setNodeItem(m_node_list);
    if(m_node_list.size()>0)
    {
        m_param_ui->hiddHow(true);
        m_param_ui->setNode(m_node_list);
    }
    else
    {
        m_param_ui->hiddHow(false);
    }
}

//初始化树显示
void LActCross::init_box()
{
    root_box->addWidget(m_group_param);

    m_group_param->setLayout(m_param_box);

    m_group_param->setMinimumHeight(172);
    m_group_param->setMaximumHeight(172);

    m_group_param->setStyleSheet(style_this.group);

    m_group_data->setMinimumHeight(60);
    m_group_data->setMaximumHeight(60);
    m_group_data->setHorizontalScrollBar(m_data_horbar);

    m_data_left->setMinimumSize(20,60);
    m_data_left->setMaximumSize(20,60);
    m_data_left->setText("<|");
    m_data_left->setStyleSheet(style_this.group);
    connect(m_data_left,SIGNAL(clicked()),this,SLOT(DataLeft()));
    m_data_right->setMinimumSize(20,60);
    m_data_right->setMaximumSize(20,60);
    m_data_right->setText("|>");
    m_data_right->setStyleSheet(style_this.group);
    connect(m_data_right,SIGNAL(clicked()),this,SLOT(DataRight()));

    m_data_box_back->addWidget(m_data_left);

    m_data_box_back->addWidget(m_group_data);

    m_data_box_back->addWidget(m_data_right);

    root_box->addLayout(m_data_box_back);

    root_box->addLayout(root_box_back);

    root_box_back->addWidget(m_group_tree,10);

    QVBoxLayout* do_box=new QVBoxLayout();

    do_box->addLayout(m_do_box);

    QSpacerItem* verSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    do_box->addItem(verSpacer);

    m_group_do->setLayout(do_box);

    m_group_do->setMaximumWidth(180);

    m_group_do->setMinimumWidth(150);

    m_group_do->setStyleSheet(style_this.group);

    root_box_back->addWidget(m_group_do,1);

    m_group_tree->setWidgetResizable(false);

    m_group_data->setWidgetResizable(false);

    m_group_data->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_group_data->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_tree_widget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    m_data_widget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    m_tree_widget->setLayout(m_tree_box);

    m_data_widget->setLayout(m_data_box);

    m_group_tree->setWidget(m_tree_widget);

    m_group_data->setWidget(m_data_widget);

    m_group_tree->setStyleSheet(style_this.group);

    m_group_data->setStyleSheet(style_this.group);

    m_tree_widget->setStyleSheet(style_this.widget);

    m_data_widget->setStyleSheet(style_this.widget);

    m_param_ui->setStyleSheet(style_this.ui);

    m_build_ui->setStyleSheet(style_this.ui);

    m_judge_ui->setStyleSheet(style_this.ui);

    m_data_ui->setStyleSheet(style_this.ui);

    m_node_ui->setStyleSheet(style_this.ui);

    m_color_list=init_color_label();

    init_param();

    init_do();

    init_item();

    init_data();

    init_tree();
}

//初始化流程信息显示
void LActCross::init_param()
{
    QLabel* label_tite=new QLabel("流程名: ");

    m_param_box->addWidget(label_tite,0,0,1,3);

    m_param_box->addWidget(label_tite_,0,3,1,1);

    label_ico_->setMaximumSize(126,126);

    connect(label_ico_,SIGNAL(clicked()),this,SLOT(NowItem()));

    m_param_box->addWidget(label_ico_,1,0,2,2);

    QLabel* label_info=new QLabel("流程描述: ");

    m_param_box->addWidget(label_info,1,2);

    label_info_->setMaximumHeight(60);

    m_param_box->addWidget(label_info_,1,3);

    QLabel* label_param=new QLabel("流程参数: ");

    m_param_box->addWidget(label_param,2,2);

    label_param_->setMaximumHeight(60);

    m_param_box->addWidget(label_param_,2,3);

    QSpacerItem* verSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    m_param_box->addItem(verSpacer,3,0);

    label_tite_->setText(" ----");
    label_info_->setText("----");
    label_param_->setText("----");
    QIcon icon = QApplication::style()->standardIcon(QStyle::StandardPixmap(33));
    label_ico_->setIcon(icon);
    label_ico_->setIconSize(label_ico_->size());
}

//初始化树形图区域（默认树）
void LActCross::init_tree()
{
    setTree(m_tree);
}

//初始化变量表
void LActCross::init_data()
{
    m_data_list=nsv_image_tree::ListAsData(m_data);

    setData(m_data_list);
}

//初始化表操作区域
void LActCross::init_do()
{
    QPushButton* save_node=new QPushButton("保存为节点");

    save_node->setMinimumSize(132,20);

    m_do_box->addWidget(save_node);

    connect(save_node,SIGNAL(clicked()),this,SLOT(SaveAsNode()));

    QPushButton* save_png=new QPushButton("保存为图片");

    save_png->setMinimumSize(132,20);

    m_do_box->addWidget(save_png);

    connect(save_png,SIGNAL(clicked()),this,SLOT(saveAsPng()));

    QPushButton* clear_all_tree=new QPushButton("清空流程树");

    clear_all_tree->setMinimumSize(132,20);

    clear_all_tree->setStyleSheet(style_this.pushButton_error);

    m_do_box->addWidget(clear_all_tree);

    connect(clear_all_tree,SIGNAL(clicked()),this,SLOT(dlAllBran()));

    QPushButton* clear_all_data=new QPushButton("清空变量集");

    clear_all_data->setMinimumSize(132,20);

    clear_all_data->setStyleSheet(style_this.pushButton_error);

    m_do_box->addWidget(clear_all_data);

    connect(clear_all_data,SIGNAL(clicked()),this,SLOT(DeleteAllData()));
}

//初始化算子表（变量）
void LActCross::init_item()
{
    m_param_ui->setCroItem(m_param_list);

    if(m_node_list.size()>0)
    {
        m_param_ui->hiddHow(true);
        m_param_ui->setNode(m_node_list);
    }
    else
    {
        m_param_ui->hiddHow(false);
    }

    setData(m_data_list);

    m_node_ui->setNodeItem(m_node_list);

    m_node_name=m_node_ui->NodeName();
}

//变量表显示
void LActCross::setData(QList<data_cross> datalist)
{
    m_data_list=datalist;

    m_data_ui->setData(m_data_list);

    setHiddAllitemsOfLayout(m_data_box);

    m_data_cols=datalist.size();

    QVBoxLayout* memo_box=new QVBoxLayout();

    QLabel* label_memo = new QLabel();

    label_memo->setText("现有变量:");

    label_memo->setMaximumHeight(20);

    QLabel* label_memo1 = new QLabel();

    label_memo1->setText("类型:");

    label_memo1->setMaximumHeight(20);

    memo_box->addWidget(label_memo,0,Qt::AlignHCenter);

    memo_box->addWidget(label_memo1,0,Qt::AlignHCenter);

    m_data_box->addLayout(memo_box);

    LToolButton* delLast=new LToolButton(this,5,QRect(0,0,0,0));

    connect(delLast,SIGNAL(isClick(int)),this,SLOT(DeleteData()));

    delLast->setText("-");

    m_data_box->addWidget(delLast);

    m_data=nsv_image_tree::DataAsList(datalist);

    for(int i=0;i<datalist.size();i++)
    {
        addNewData(datalist[i],i);
    }

    LToolButton* addNext=new LToolButton(this,5,QRect(0,0,0,0));

    connect(addNext,SIGNAL(isClick(int)),this,SLOT(addData(int)));

    addNext->setText("+");

    m_data_box->addWidget(addNext);

    QSpacerItem* her=new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    m_data_box->addItem(her);
}

//树形图显示
void LActCross::setTree(QString tree)
{
    setHiddAllitemsOfLayout(m_tree_box);

    ClearDataAttr();

    if(tree=="")
    {
        param_cross start;

        start.name=" start ";
        start.tig=1000000;
        start.ico = QApplication::style()->standardIcon(QStyle::StandardPixmap(33));
        start.intype.append("Mat");
        start.outtype.append("Mat");
        start.intype_info.append("");
        start.outtype_info.append("");

        addNewItem(QList<param_cross>{start},1);
    }
    else
    {
        QList<QList<param_cross>> pl=nsv_image_tree::ListAsTree(m_tree,m_data_list,m_param_list,m_node_list);

        m_tree_cols=1;

        for(int i=0;i<pl.size();i++)
        {
            addNewItem(pl[i],m_tree_cols);
            m_tree_cols+=pl[i].size();
        }
    }

    QVBoxLayout* do_box = new QVBoxLayout();

    LToolButton* addNext=new LToolButton(this,2,QRect(0,0,0,0));

    connect(addNext,SIGNAL(isClick(QRect)),this,SLOT(addNext(QRect)));

    addNext->setText("+");

    do_box->addWidget(addNext);

    LToolButton* delLast=new LToolButton(this,2,QRect(0,0,0,0));

    connect(delLast,SIGNAL(isClick(QRect)),this,SLOT(DeleteItem()));

    delLast->setText("-");

    do_box->addWidget(delLast);

    QSpacerItem* vor=new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    do_box->addItem(vor);

    m_tree_box->addLayout(do_box);

    QSpacerItem* her=new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    m_tree_box->addItem(her);

    setData(m_data_list);
}

//删除尾部变量
void LActCross::DeleteData()
{
    if(m_data_list.size()>0)
    {
        m_data_list.removeLast();
        setData(m_data_list);
    }
    else
    {
        QMessageBox mask;
        mask.setText("变量删除失败，变量列表为空。");
        mask.exec();
    }
}

//删除所有变量
void LActCross::DeleteAllData()
{
    if(m_data_list.size()>0)
    {
        QMessageBox mask;
        mask.setText("是否删除所有变量？");
        mask.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        mask.setDefaultButton(QMessageBox::No);
        int ret = mask.exec();
        if(ret==QMessageBox::Yes)
        {
            QList<data_cross> data_list;
            setData(data_list);
        }
    }
    else
    {
        QMessageBox mask;
        mask.setText("变量删除失败，变量列表为空。");
        mask.exec();
    }
}

//新增变量
void LActCross::addData(int)
{
    m_data_ui->setWindowFlags(Qt::WindowStaysOnTopHint);
    m_data_ui->exec();
    m_data_list=m_data_ui->getData();

    setData(m_data_list);
}

//变量表左移
void LActCross::DataLeft()
{
    if(m_data_horbar->value()-10>0)
    {
        m_data_horbar->setValue(m_data_horbar->value()-10);
    }
    else
    {
        m_data_horbar->setValue(0);
    }
}

//变量表右移
void LActCross::DataRight()
{
    if(m_data_horbar->value()+10<m_data_horbar->maximum())
    {
        m_data_horbar->setValue(m_data_horbar->value()+10);
    }
    else
    {
        m_data_horbar->setValue(m_data_horbar->maximum());
    }
}

//新增树流程
void LActCross::addNewItem(QList<param_cross> start_list,int col)
{
    if(start_list.size()==0)
    {
        return;
    }

    if(start_list[0].tig==300001)
    {
        LParamCard* item_start=new LParamCard(this,QRect(0,1,col,0),1,start_list,m_data_list);

        connect(item_start,SIGNAL(isClick(QRect,int)),this,SLOT(showAct(QRect,int)));

        connect(item_start,SIGNAL(DataClick(QRect,int)),this,SLOT(showData(QRect,int)));

        connect(this,SIGNAL(isYou(int)),item_start,SIGNAL(isYou(int)));

        m_tree_box->addWidget(item_start);
    }
    else
    {
        LParamCard* item_start=new LParamCard(this,QRect(0,1,col,0),0,start_list,m_data_list);

        connect(item_start,SIGNAL(isClick(QRect,int)),this,SLOT(showAct(QRect,int)));

        connect(item_start,SIGNAL(DataClick(QRect,int)),this,SLOT(showData(QRect,int)));

        connect(this,SIGNAL(isYou(int)),item_start,SIGNAL(isYou(int)));

        m_tree_box->addWidget(item_start);
    }
}

//新增变量
void LActCross::addNewData(data_cross d,int col)
{
    LDataCard* data=new LDataCard(this,QRect(col,0,0,0),d);

    connect(this,SIGNAL(isYou(int)),data,SLOT(isMe(int)));

    connect(data,SIGNAL(isClick(int)),this,SIGNAL(isYou(int)));

    connect(data,SIGNAL(isClick(int)),this,SLOT(choData(int)));

    connect(data,SIGNAL(data_back(data_cross)),this,SLOT(reviseData(data_cross)));

    m_data_box->addWidget(data);
}

//清空流程树显示
void LActCross::tree_clear()
{
    deleteAllitemsOfLayout(m_tree_box);
}

//清理变量属性
void LActCross::ClearDataAttr()
{
    for(int i=0;i<m_data_list.size();i++)
    {
        m_data_list[i].isGiveBefore=false;
        m_data_list[i].isUseLast=false;
        m_data_list[i].WhoGiveMe.clear();
        m_data_list[i].WhoUseMe.clear();
        m_data_list[i].attr=0;
    }
}

//清空流程树响应
void LActCross::dlAllBran()
{
    m_tree="";
    m_tree_cols=0;
    m_tree_rows=0;

    setTree(m_tree);

    ClearDataAttr();
}

//保存为节点响应
void LActCross::SaveAsNode()
{
    if(m_tree!="")
    {
        QList<QList<param_cross>> pl=nsv_image_tree::ListAsTree(m_tree,m_data_list,m_param_list,m_node_list);

        for(int i=0;i<pl.size();i++)
        {
            for(int k=0;k<pl[i].size();k++)
            {
                if(!pl[i][k].canrun)
                {
                    QMessageBox mask;
                    mask.setText("流程树中存在流程输入未定义，请检查后重新生成节点。");
                    mask.exec();
                    return;
                }
            }
        }

        m_node_ui->exec();
        m_node_name=m_node_ui->NodeName();
        if(m_node_ui->NowNode().name!="" && !StrinList_tree(m_node_ui->NowNode().name,m_node_name))
        {
            node_cross info;
            info.name=m_node_ui->NowNode().name;
            info.info=m_node_ui->NowNode().info;
            info.param=m_node_ui->NowNode().param;
            info.ico=m_node_ui->NowNode().ico;
            info.tree=m_tree;
            info.tree_img=getScrollArea(m_tree_widget);
            info.data_img=getScrollArea(m_data_widget);
            info.data=m_data;

            node_cross node=nsv_image_tree::TreeToNode(info,m_param_list,m_node_list);

            if(node.tig<200000 || node.tig>=300000)
            {
                QMessageBox mask;
                mask.setText("要保存的流程树存在常量输入没有赋值，请尝试运行后并赋值后再保存。");
                mask.exec();
                return;
            }

            if(node.intype.size()<1 || node.outtype.size()<1)
            {
                QMessageBox mask;
                mask.setText("节点至少需要一个输入，一个输出。");
                mask.exec();
                return;
            }

            m_node_list.append(node);
            m_node_ui->setNodeItem(m_node_list);
            if(m_node_list.size()>0)
            {
                m_param_ui->hiddHow(true);
                m_param_ui->setNode(m_node_list);
            }
            else
            {
                m_param_ui->hiddHow(false);
            }
            dlAllBran();
            DeleteAllData();
        }
        else
        {
            QMessageBox mask;
            mask.setText("节点名为空，或已存在，请修改节点名。");
            mask.exec();
            return;
        }
    }
    else
    {
        QMessageBox mask;
        mask.setText("流程树为空，无法将流程树保存为节点。");
        mask.exec();
        return;
    }
}

//树形图保存为图像响应
void LActCross::saveAsPng()
{
    QImage img=getScrollArea(m_tree_widget);

    QImage img_data=getScrollArea(m_data_widget);

    QWidget* show=new QWidget();

    show->resize(img.size());

    show->setWindowTitle("流程树");

    show->setStyleSheet(style_this.ui);

    QGridLayout* root_box_w=new QGridLayout();

    show->setLayout(root_box_w);

    LLabel* img1=new LLabel(show);

    root_box_w->addWidget(img1);

    img1->setPixmap(QPixmap::fromImage(img_data));

    LLabel* img2=new LLabel(show);

    root_box_w->addWidget(img2);

    img2->setPixmap(QPixmap::fromImage(img));

    show->show();
}

//新增流程
void LActCross::addNext(QRect)
{
    m_build_ui->setWindowFlags(Qt::WindowStaysOnTopHint);
    m_build_ui->exec();

    int build_tip=m_build_ui->getTip();

    if(build_tip==0)
    {
        m_param_ui->setWindowFlags(Qt::WindowStaysOnTopHint);
        m_param_ui->exec();

        int tip=m_param_ui->getTip();

        m_tree=nsv_image_tree::AddParamToTree(tip,m_param_list,m_node_list,m_tree);
    }
    else if(build_tip==1)
    {
        m_param_ui->setWindowFlags(Qt::WindowStaysOnTopHint);
        m_param_ui->exec();

        int tip1=m_param_ui->getTip();

        m_param_ui->setWindowFlags(Qt::WindowStaysOnTopHint);
        m_param_ui->exec();

        int tip2=m_param_ui->getTip();

        m_tree=nsv_image_tree::AddJudgeToTree(tip1,tip2,m_param_list,m_node_list,m_tree);
    }

    qDebug()<<m_tree;

    setTree(m_tree);
}

//删除末端流程
void LActCross::DeleteItem()
{
    if(m_tree=="")
    {
        QMessageBox mask;
        mask.setText("流程树回撤失败，树中没有算子。");
        mask.exec();
    }

    m_tree=nsv_image_tree::DelParamAsTree(m_tree);

    setTree(m_tree);
}

//流程信息显示响应
void LActCross::showAct(QRect,int tig)
{
    m_tip_now=tig;
    if(tig<m_param_list.size())
    {
        param_cross p=m_param_list[tig];

        label_tite_->setText(" 算子: "+p.name);
        label_info_->setText(p.info);
        label_param_->setText(p.param);
        if(p.ico.isNull())
        {
            QIcon icon = QApplication::style()->standardIcon(QStyle::StandardPixmap(33));
            label_ico_->setIcon(icon);
        }
        else
        {
            label_ico_->setIcon(p.ico);
        }
        label_ico_->setIconSize(label_ico_->size());
    }
    else if(tig>=200000 && tig-200000<m_node_list.size())
    {
        node_cross p=m_node_list[tig-200000];

        label_tite_->setText(" 节点: "+p.name);
        label_info_->setText(p.info);
        label_param_->setText(p.param);
        if(p.ico.isNull())
        {
            QIcon icon = QApplication::style()->standardIcon(QStyle::StandardPixmap(33));
            label_ico_->setIcon(icon);
        }
        else
        {
            label_ico_->setIcon(p.ico);
        }
        label_ico_->setIconSize(label_ico_->size());
    }
    else if(tig==1000000)
    {
        qDebug()<<"its start";
    }
    else
    {
        label_tite_->setText(" ----");
        label_info_->setText("算法编号异常");
        label_param_->setText("----");
        QIcon icon = QApplication::style()->standardIcon(QStyle::StandardPixmap(11));
        label_ico_->setIcon(icon);
        label_ico_->setIconSize(label_ico_->size());
    }
}

//节点内容显示响应
void LActCross::ShowNode(node_cross node)
{
    QWidget* show=new QWidget();

    show->resize(QSize(800,600));

    show->setWindowTitle("节点: "+node.name+"      tip: "+QString::number(node.tig));

    show->setStyleSheet(style_this.ui);

    QGridLayout* root_box_w=new QGridLayout();

    show->setLayout(root_box_w);

    LLabel* data=new LLabel(show);

    root_box_w->addWidget(data);

    data->setText("节点变量集："+node.data);

    LLabel* img1=new LLabel(show);

    root_box_w->addWidget(img1);

    img1->setPixmap(QPixmap::fromImage(node.data_img));

    LLabel* tree=new LLabel(show);

    root_box_w->addWidget(tree);

    tree->setText("节点流程树："+node.tree);

    LLabel* img2=new LLabel(show);

    root_box_w->addWidget(img2);

    img2->setPixmap(QPixmap::fromImage(node.tree_img));

    show->show();
}

//当前流程响应
void LActCross::NowItem()
{
    if(m_tip_now>=0 && m_tip_now<100000)
    {

    }
    else if(m_tip_now>=200000 && m_tip_now<300000)
    {
        node_cross node=m_node_list[m_tip_now-200000];
        ShowNode(node);
    }
}

//新增操作按钮
void LActCross::add_Button(QString name, bool isrisk, const QObject *receiver, const char *member)
{
    if(!isrisk)
    {
        QPushButton* np=new QPushButton(name);

        np->setMinimumSize(132,20);

        m_do_box->addWidget(np);

        connect(np,SIGNAL(clicked()),receiver,member);
    }
    else
    {
        QPushButton* npr=new QPushButton(name);

        npr->setMinimumSize(132,20);

        npr->setStyleSheet(style_this.pushButton_error);

        m_do_box->addWidget(npr);

        connect(npr,SIGNAL(clicked()),receiver,member);
    }
}

//活动变量显示（流程参数选择）
void LActCross::showData(QRect where,int tig)
{
    if(m_tree!="")
    {
        emit isYou(tig);
        if(tig-100000<m_data_list.size())
        {
            data_cross d=m_data_list[tig-100000];
        }
        else
        {
            m_data_where=where;
            if(m_data_where.y()==3)
            {
                m_judge_ui->setWindowFlags(Qt::WindowStaysOnTopHint);
                m_judge_ui->exec();

                int judge_tip=m_judge_ui->getTip();

                m_group_tree->setEnabled(false);
                choData(judge_tip);
            }
            else
            {
                m_group_tree->setEnabled(false);
            }
        }
    }
}

//参数选择响应
void LActCross::choData(int tig)
{
    if(!m_group_tree->isEnabled())
    {
        QString result=nsv_image_tree::ChoParamData(m_data_where,tig,m_tree,m_param_list,m_node_list,m_data_list);

        if(result == "")
        {
            QMessageBox msgBox;
            msgBox.setText("当前所选变量类型错误，请重新选择。");
            msgBox.exec();

            m_group_tree->setEnabled(true);
            return;
        }

        if(result == "DIFFERENT")
        {
            QMessageBox msgBox;
            msgBox.setText("做判断的变量必须类型相同，请重新选择。");
            msgBox.exec();

            m_group_tree->setEnabled(true);
            return;
        }

        if(result == "NULL")
        {
            QMessageBox msgBox;
            msgBox.setText("请先确认做判断的变量，再选择变量方式。");
            msgBox.exec();

            m_group_tree->setEnabled(true);
            return;
        }

        if(result == "ERROR")
        {
            QMessageBox msgBox;
            msgBox.setText("未选中算法，流程树执行异常。");
            msgBox.exec();

            m_group_tree->setEnabled(true);
            return;
        }

        if(result == "CANT")
        {
            QMessageBox msgBox;
            msgBox.setText("做判断的变量无法使用该判断方式，请重新选择");
            msgBox.exec();

            m_group_tree->setEnabled(true);
            return;
        }

        if(result == "CANTTYPE")
        {
            QMessageBox msgBox;
            msgBox.setText("该变量类型无法用于判断");
            msgBox.exec();

            m_group_tree->setEnabled(true);
            return;
        }

        m_tree=result;

        qDebug()<<m_tree;

        setTree(m_tree);

        m_group_tree->setEnabled(true);
    }
}

//变量回值
void LActCross::reviseData(data_cross d)
{
    if(d.tig-100000<m_data_list.size())
    {
        m_data_list[d.tig-100000]=d;
    }

    setData(m_data_list);
}

//绘制事件
void LActCross::paintEvent(QPaintEvent *event)
{
    QGroupBox::paintEvent(event);

    m_tree_widget->setMinimumSize(int(126*m_tree_cols+126+100),int(406*m_tree_rows+406+220));
    m_tree_widget->setMaximumSize(int(126*m_tree_cols+126+100),int(406*m_tree_rows+406+220));

    m_data_widget->setMinimumSize(int(86*m_data_cols+180),int(50));
    m_data_widget->setMaximumSize(int(86*m_data_cols+180),int(50));
}
