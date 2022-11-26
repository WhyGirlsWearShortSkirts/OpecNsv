#include "lattree_newnode.h"
#include "ui_lattree_newnode.h"

//构造函数
LatTree_NewNode::LatTree_NewNode(QWidget *parent) :QDialog(parent),ui(new Ui::LatTree_NewNode)
{
    ui->setupUi(this);

    this->setWindowTitle("注册节点");

    ui->scrollArea->setStyleSheet(style_this.item);
    QIcon icon = QApplication::style()->standardIcon(QStyle::StandardPixmap(39));
    ui->pushButton->setIcon(icon);
}

//析构
LatTree_NewNode::~LatTree_NewNode()
{
    delete ui;
}

//节点表显示
void LatTree_NewNode::setNodeItem(QList<node_cross> p_l)
{
    m_node_list=p_l;

    deleteAllitemsOfLayout(ui->verticalLayout_now_node);

    m_name_list.clear();

    for(int i=0;i<p_l.size();i++)
    {
        node_cross p=p_l[i];

        m_name_list.append((p.name));

        QGroupBox* group_item=new QGroupBox();

        group_item->setStyleSheet(style_this.node);

        QGridLayout* param_box=new QGridLayout();

        LPushButton* label_ico=new LPushButton(this,p.tig);

        label_ico->setMaximumSize(130,130);
        label_ico->setMinimumSize(130,130);

        param_box->addWidget(label_ico,0,0,3,3);

        if(p.ico.isNull())
        {
            QIcon icon = QApplication::style()->standardIcon(QStyle::StandardPixmap(39));
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

        label_info->setMaximumHeight(35);

        param_box->addWidget(label_info,1,4);

        QTextBrowser* label_param=new QTextBrowser();

        label_param->setMaximumHeight(50);

        param_box->addWidget(label_param,2,4);

        LLabel* label_tree=new LLabel(this);

        label_tree->setMaximumHeight(400);
        label_tree->setMinimumHeight(400);

        param_box->addWidget(label_tree,3,4);

        label_name->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

        label_info->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

        label_param->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

        label_name->setText(p.name);

        label_info->setText(p.info);

        label_param->setText(p.param);

        connect(label_ico,SIGNAL(isClick(int)),label_tree,SLOT(sethidd()));

        label_tree->addImg(p.tree_img);

        label_tree->setHidden(true);

        group_item->setLayout(param_box);

        ui->verticalLayout_now_node->addWidget(group_item);
    }
}

//新增节点
void LatTree_NewNode::on_pushButton_add_node_clicked()
{
    if(ui->lineEdit_node_name->text()!="")
    {
        m_now_node.name=ui->lineEdit_node_name->text();
        m_now_node.info=ui->textEdit_node_info->toHtml();
        m_now_node.param=ui->textEdit_node_param->toHtml();
        m_now_node.ico=ui->pushButton->icon();
        this->close();
    }
}


