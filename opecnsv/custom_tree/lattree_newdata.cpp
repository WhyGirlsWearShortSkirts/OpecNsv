#include "lattree_newdata.h"
#include "ui_lattree_newdata.h"
#include <QtDebug>

//构造函数
LatTree_NewData::LatTree_NewData(QWidget *parent) :QDialog(parent),ui(new Ui::LatTree_NewData)
{
    ui->setupUi(this);

    this->setWindowTitle("注册变量");

    m_now_data.name="";
    m_now_data.tig=1000000;
    m_now_data.type="";

    ui->lineEdit_data_name->setFocus();
}

//析构
LatTree_NewData::~LatTree_NewData()
{
    delete ui;
}

//初始化类型
void LatTree_NewData::init_type()
{
    m_name_list.clear();

    for(int i=0;i<m_data_list.size();i++)
    {
        data_cross d=m_data_list[i];
        if(!StrinList_tree(d.type,m_type_list))
        {
            m_type_list.append(d.type);
        }
        m_name_list.append(d.name);
    }

    show_type_show();
}

//类型表显示
void LatTree_NewData::show_type_show()
{
    setHiddAllitemsOfLayout(ui->now_type);

    QVBoxLayout* type_box=new QVBoxLayout();

    for(int i=0;i<m_type_list.size();i++)
    {
        LPushButton* type=new LPushButton(this,i);

        connect(type,SIGNAL(isClick(int)),this,SLOT(ChoType(int)));

        type->setText(m_type_list[i]);

        type->setStyleSheet(style_this.item);

        type->setMinimumHeight(20);

        type_box->addWidget(type);
    }

    ui->now_type->addLayout(type_box);
}

//类型确定响应
void LatTree_NewData::ChoType(int type)
{
    if(type<m_type_list.size())
    {
        ui->lineEdit_data_type->setText(m_type_list[type]);
        on_pushButton_clicked();
    }
}

//新增变量
void LatTree_NewData::on_pushButton_clicked()
{
    if(ui->lineEdit_data_name->text()!="" && ui->lineEdit_data_type->text()!="" && !StrinList_tree(ui->lineEdit_data_name->text(),m_name_list))
    {
        m_now_data.name=ui->lineEdit_data_name->text();
        m_now_data.tig=m_data_list.size()+100000;
        m_now_data.type=ui->lineEdit_data_type->text();
        m_data_list.append(m_now_data);
        init_type();
        this->close();
    }
    else
    {
        ui->pushButton->setText("变量名为空，或已存在，请修改变量名。");
        QEventLoop eventloop;
        QTimer::singleShot(1500, &eventloop, SLOT(quit()));
        eventloop.exec();
        ui->pushButton->setText("注册变量");
    }
}
