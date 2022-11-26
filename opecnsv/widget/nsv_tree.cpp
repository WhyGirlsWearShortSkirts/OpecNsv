#include "nsv_tree.h"
#include "ui_nsv_tree.h"

nsv_tree::nsv_tree(QWidget *parent) :QDialog(parent),ui(new Ui::nsv_tree)
{
    ui->setupUi(this);

    init_ui();

    init_item();

    init_node();
}

nsv_tree::~nsv_tree()
{
    delete ui;
}

void nsv_tree::init_ui()
{
    this->setWindowTitle("自定义算法");
    this->setWindowIcon(QIcon("titg.ico"));

    ui->tabWidget->tabBar()->hide();//隐藏tab
    ui->tabWidget->setCurrentIndex(0);

//    ui->groupBox->add_Button("获取树信息",false,this,SLOT(GetTree()));
    ui->groupBox->add_Button("添加节点",false,this,SLOT(AddNode()));
    ui->groupBox->add_Button("添加节点至默认库",false,this,SLOT(AddNodeToDefault()));
    ui->groupBox->add_Button("保存运行树",false,this,SLOT(SaveTree()));
    ui->groupBox->add_Button("加载运行树",false,this,SLOT(ReadTree()));
    ui->groupBox->add_Button("运行算法",false,this,SLOT(TreeRun()));

    //设置下划线颜色
    button_group->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group->setLineHeight(4);
    //设置下划线位置
    button_group->setButtonPosition(CusButtonGroup::West);

    ui->button_group->addWidget(button_group);

    connect(button_group,SIGNAL(choose_buttons(int)),ui->View_image,SLOT(image_add(int)));
    connect(m_tree_run,SIGNAL(run_back(QList<QVariant>)),this,SLOT(result_show(QList<QVariant>)));
    connect(m_tree_run,SIGNAL(error_back(QString)),this,SLOT(error_show(QString)));
}

void nsv_tree::init_item()
{
    QList<QString> type_list=nsv_image_tree::init_Type();
    QList<param_cross> param_list=nsv_image_tree::init_Param();
    m_param_list=param_list;
    ui->groupBox->setitemlist(param_list);
    ui->groupBox->setdefaultType(type_list);

}

void nsv_tree::init_node()
{
    QString default_node="default_node";

    QDir dir;
    if (!dir.exists(default_node))
    {
        dir.mkpath(default_node);
        node_cross n_tree;
        nsv_json_analy::json_create_tree(n_tree,default_node);
    }

    node_cross n_tree=nsv_json_analy::json_read_tree(default_node);

    QList<node_cross> dnl;

    for(int i=0;i<n_tree.intype.size();i++)
    {
        node_cross n=nsv_image_tree::ReadNode(default_node+"/"+n_tree.intype[i]);

        if(n.tig>=200000 && n.tig<300000)
        {
            n.tig=200000+dnl.size();
            dnl.append(n);
        }
        else
        {
            qDebug()<<"节点："+n.name+",tig:"+QString::number(n.tig)+"为非法节点!";
        }
    }

    ui->groupBox->set_Node(dnl);
}

void nsv_tree::GetTree()
{
    tree_param tree=ui->groupBox->now_Tree();
    m_node_list=tree.n_l;

    QList<QList<param_cross>> pc = nsv_image_tree::ListAsTree(tree.tree,tree.d_l,tree.p_l,tree.n_l);

    for(int i=0;i<pc.size();i++)
    {
        for(int k=0;k<pc[i].size();k++)
        {
            nsv_image_tree::LDebug(pc[i][k]);
        }
    }
}

void nsv_tree::TreeRun()
{
    m_widge_list.clear();
    m_exec_data.clear();
    this->setEnabled(false);
    tree_param tree=ui->groupBox->now_Tree();
    m_node_list=tree.n_l;
    deleteAllitemsOfLayout(ui->verticalLayout_input);
    deleteAllitemsOfLayout(ui->verticalLayout_output);
    for(int i=0;i<tree.d_l.size();i++)
    {
        if(tree.d_l[i].attr==1)
        {
            QList<QWidget*> wl=add_new_input(tree.d_l[i]);
            m_widge_list.push_back(wl);
        }
        else if(tree.d_l[i].attr==2)
        {
            QList<QWidget*> wl=add_new_output(tree.d_l[i]);
            m_widge_list.push_back(wl);
        }
        else if(tree.d_l[i].attr==3)
        {
            QList<QWidget*> wl=add_new_output(tree.d_l[i]);
            m_widge_list.push_back(wl);
        }
        else
        {
            m_widge_list.push_back(QList<QWidget*>());
        }
        m_exec_data.push_back(QVariant());
    }
    for(int i=0;i<m_widge_list.size();i++)
    {
        show_value(tree.d_l[i].data,tree.d_l[i],m_widge_list[i]);
    }
    m_tree=tree;
    this->setEnabled(true);
    ui->tabWidget->setCurrentIndex(1);
}

void nsv_tree::AddNode()
{
    tree_param tree=ui->groupBox->now_Tree();

    QList<node_cross> n_l=tree.n_l;

    QString ns=QFileDialog::getExistingDirectory(this,"节点获取","./");

    qDebug()<<ns;

    node_cross n=nsv_image_tree::ReadNode(ns);

    if(n.tig>=200000 && n.tig<300000)
    {
        n.tig=200000+n_l.size();
        n_l.append(n);
        ui->groupBox->set_Node(n_l);
    }
    else
    {
        qDebug()<<"节点："+n.name+",tig:"+QString::number(n.tig)+"为非法节点!";
    }
}

void nsv_tree::AddNodeToDefault()
{
    QString default_node="default_node";

    node_cross n_tree=nsv_json_analy::json_read_tree(default_node);

    QString ns=QFileDialog::getExistingDirectory(this,"节点获取","./");

    qDebug()<<ns;

    node_cross n=nsv_image_tree::ReadNode(ns);

    if(n.tig>=200000 && n.tig<300000)
    {
        n.tig=200000+n_tree.intype.size();

        n_tree.intype.append(n.name);
    }
    else
    {
        qDebug()<<"节点："+n.name+",tig:"+QString::number(n.tig)+"为非法节点!";
    }

    nsv_image_tree::SaveNode(n,default_node);

    nsv_json_analy::json_create_tree(n_tree,default_node);
}

void nsv_tree::SaveTree()
{
    tree_param tree=ui->groupBox->now_Tree();

    QString name=QFileDialog::getSaveFileName(this,"保存流程树","./","");

    QDir dir;
    if (!dir.exists(name))
    {
        dir.mkpath(name);
    }

    node_cross n_tree;
    n_tree.tree=tree.tree;
    n_tree.data=tree.data;
    n_tree.tree_img=tree.tree_img;
    n_tree.data_img=tree.data_img;

    if(!n_tree.tree_img.isNull())
    {
        n_tree.tree_img.save(name+"/tree.png","PNG",100);
    }

    if(!n_tree.data_img.isNull())
    {
        n_tree.data_img.save(name+"/data.png","PNG",100);
    }

    for(int i=0;i<tree.n_l.size();i++)
    {
        nsv_image_tree::SaveNode(tree.n_l[i],name);

        n_tree.intype.append(tree.n_l[i].name);
    }

    nsv_json_analy::json_create_tree(n_tree,name);
}

void nsv_tree::ReadTree()
{
    QString name=QFileDialog::getExistingDirectory(this,"读取流程树","./");

    qDebug()<<name;

    node_cross n_tree=nsv_json_analy::json_read_tree(name);

    tree_param tree;

    tree.tree=n_tree.tree;
    tree.data=n_tree.data;
    tree.d_l=nsv_image_tree::ListAsData(tree.data);

    for(int i=0;i<n_tree.intype.size();i++)
    {
        node_cross n=nsv_image_tree::ReadNode(name+"/"+n_tree.intype[i]);

        if(n.tig>=200000 && n.tig<300000)
        {
            n.tig=200000+tree.n_l.size();
            tree.n_l.append(n);
        }
        else
        {
            qDebug()<<"节点："+n.name+",tig:"+QString::number(n.tig)+"为非法节点!";
        }
    }

    ui->groupBox->set_Tree(tree);
}

void nsv_tree::RunTree(cv::Mat image_now)
{
    m_image_now=image_now;

    on_pushButton_torun_clicked();
}

void nsv_tree::on_pushButton_torun_clicked()
{
    if(m_widge_list.size()>0)
    {
        m_exec_data_c=m_exec_data;
        for(int i=0;i<m_widge_list.size();i++)
        {
            m_exec_data[i]=get_value(m_tree.d_l[i],m_widge_list[i]);

            m_exec_data_c[i]=m_exec_data[i];
            if(m_tree.d_l[i].type=="image")//这里只执行了原图一种方式，以后得更改一下
            {
                QString text=m_exec_data[i].toString();
                m_exec_data[i].setValue<cv::Mat>(m_image_now);
            }
        }

        ui->groupBox->setData(m_tree.d_l);

        m_tree_run->now_tree=m_tree;
        m_tree_run->now_exec_data=m_exec_data;

        this->setEnabled(false);

        if(!f3.isRunning())
        {
            Start = GetTickCount();
            f3 = QtConcurrent::run(m_tree_run,&nsv_image_tree::item_th);
        }
    }
}

void nsv_tree::error_show(QString error)
{
    QMessageBox megb;
    megb.setText(error);
    megb.exec();
}

void nsv_tree::result_show(QList<QVariant> result)
{
    f3.cancel();
    DWORD End = GetTickCount();

    ui->label_runtime->setText(QString::number(End-Start));

    m_exec_data=result;

    if(button_group->size()>0)
    {
        button_group->deleteLayout();
        //设置下划线颜色
        button_group->setButtonColor(QColor(255, 163, 69));
        //设置下划线高度
        button_group->setLineHeight(4);
        //设置下划线位置
        button_group->setButtonPosition(CusButtonGroup::West);
    }
    ui->View_image->clearImageList();

    for(int i=0;i<m_exec_data_c.size();i++)
    {
        if(m_tree.d_l[i].type=="image")
        {
            QString text=m_exec_data_c[i].toString();
            m_tree.d_l[i]=show_value(m_exec_data_c[i],m_tree.d_l[i],m_widge_list[i]);
            cv::Mat image=m_exec_data[i].value<cv::Mat>();
            if(text=="原图")
            {
                QPushButton *btn = new QPushButton;
                btn->setCheckable(true);
                btn->setText("原图");
                btn->setFixedSize(60,25);
                button_group->addButton(btn,button_group->size());
                ui->View_image->image_add(image);
            }
            else if(text=="显示" || text=="输出")
            {
                QPushButton *btn = new QPushButton;
                btn->setCheckable(true);
                btn->setText(m_tree.d_l[i].name);
                btn->setFixedSize(60,25);
                button_group->addButton(btn,button_group->size());
                ui->View_image->image_add(image);
                if(text=="输出")
                {
                    m_image_result=image;
                }
            }
        }
        else
        {
            m_tree.d_l[i]=show_value(m_exec_data[i],m_tree.d_l[i],m_widge_list[i]);
        }
    }

    //显示最后一帧图像
    button_group->onbuttonClicked(button_group->size()-1);

    ui->groupBox->set_Tree(m_tree);

    emit TreeRunFinish(m_image_result);

    this->setEnabled(true);
}

void nsv_tree::on_pushButton_back_tree_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

QList<QWidget*> nsv_tree::add_new_input(data_cross d)
{
    QHBoxLayout* box=new QHBoxLayout();
    QList<QWidget*> wl;
    QLabel* name=new QLabel(d.name);
    box->addWidget(name);

    QString show="";
    for(int i=0;i<d.WhoUseMe.size();i++)
    {
        QStringList stl=d.WhoUseMe[i].split("-");
        if(stl.size()>1)
        {
            if(stl[0].toInt()>=200000)
            {
                if(stl[0].toInt()-200000<m_node_list.size())
                {
                    show+=m_node_list[stl[0].toInt()-200000].name;
                    show+=":";
                    show+=m_node_list[stl[0].toInt()-200000].intype_info[stl[1].toInt()];
                }

                if(stl[0].toInt()==300001)
                {
                    if(stl[1].toInt()==1)
                    {
                        show+="比较值";
                    }
                    else if(stl[1].toInt()==2)
                    {
                        show+="待比值";
                    }
                }

                if(i!=d.WhoUseMe.size()-1)
                {
                    show+=" ";
                }
            }
            else
            {
                if(stl[0].toInt()<m_param_list.size())
                {
                    show+=m_param_list[stl[0].toInt()].name;
                    show+=":";
                    show+=m_param_list[stl[0].toInt()].intype_info[stl[1].toInt()];
                }
                if(i!=d.WhoUseMe.size()-1)
                {
                    show+=" ";
                }
            }
        }
        if(i>2)
        {
            break;
        }
    }
    QLabel* l_=new QLabel();
    l_->setText(show);
    l_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    box->addWidget(l_);

    if(d.type == "image")
    {
        QComboBox* put=new QComboBox();
        put->addItem("原图");
        box->addWidget(put);
        wl.push_back(put);
    }
    else if(d.type == "color")
    {
        QLabel* R=new QLabel("R:");
        QSpinBox* r=new QSpinBox();
        r->setMinimum(0);
        r->setMaximum(255);

        QLabel* G=new QLabel("G:");
        QSpinBox* g=new QSpinBox();
        g->setMinimum(0);
        g->setMaximum(255);

        QLabel* B=new QLabel("B:");
        QSpinBox* b=new QSpinBox();
        b->setMinimum(0);
        b->setMaximum(255);

        box->addWidget(R);
        box->addWidget(r);
        box->addWidget(G);
        box->addWidget(g);
        box->addWidget(B);
        box->addWidget(b);

        wl.push_back(r);
        wl.push_back(g);
        wl.push_back(b);
    }
    else if(d.type == "size")
    {
        QLabel* W=new QLabel("Width:");
        QSpinBox* w=new QSpinBox();
        w->setMinimum(0);
        w->setMaximum(5000);

        QLabel* H=new QLabel("Height:");
        QSpinBox* h=new QSpinBox();
        h->setMinimum(0);
        h->setMaximum(5000);

        box->addWidget(W);
        box->addWidget(w);
        box->addWidget(H);
        box->addWidget(h);

        wl.push_back(w);
        wl.push_back(h);
    }
    else if(d.type == "rect")
    {
        QLabel* X=new QLabel("X:");
        QSpinBox* x=new QSpinBox();
        x->setMinimum(0);
        x->setMaximum(5000);

        QLabel* Y=new QLabel("Y:");
        QSpinBox* y=new QSpinBox();
        y->setMinimum(0);
        y->setMaximum(5000);

        QLabel* W=new QLabel("Width:");
        QSpinBox* w=new QSpinBox();
        w->setMinimum(0);
        w->setMaximum(5000);

        QLabel* H=new QLabel("Height:");
        QSpinBox* h=new QSpinBox();
        h->setMinimum(0);
        h->setMaximum(5000);

        box->addWidget(X);
        box->addWidget(x);
        box->addWidget(Y);
        box->addWidget(y);
        box->addWidget(W);
        box->addWidget(w);
        box->addWidget(H);
        box->addWidget(h);

        wl.push_back(x);
        wl.push_back(y);
        wl.push_back(w);
        wl.push_back(h);
    }
    else if(d.type == "bool")
    {
        QCheckBox* put=new QCheckBox();
        put->setText("");
        box->addWidget(put);

        wl.push_back(put);
    }
    else if(d.type == "int")
    {
        QSpinBox* put=new QSpinBox();
        put->setMinimum(-5000);
        put->setMaximum(5000);
        box->addWidget(put);

        wl.push_back(put);
    }
    else if(d.type == "float")
    {
        QDoubleSpinBox* put=new QDoubleSpinBox();
        put->setMinimum(-5000);
        put->setMaximum(5000);
        box->addWidget(put);

        wl.push_back(put);
    }
    else if(d.type == "double")
    {
        QDoubleSpinBox* put=new QDoubleSpinBox();
        put->setMinimum(-5000);
        put->setMaximum(5000);
        box->addWidget(put);

        wl.push_back(put);
    }
    else
    {
        QLineEdit* put=new QLineEdit();
        box->addWidget(put);

        wl.push_back(put);
    }

    ui->verticalLayout_input->addLayout(box);
    return wl;
}

QList<QWidget*> nsv_tree::add_new_output(data_cross d)
{
    QHBoxLayout* box=new QHBoxLayout();
    QList<QWidget*> wl;
    QLabel* name=new QLabel(d.name);
    box->addWidget(name);

    QString show="";
    for(int i=0;i<d.WhoGiveMe.size();i++)
    {
        QStringList stl=d.WhoGiveMe[i].split("-");
        if(stl.size()>1)
        {
            if(stl[0].toInt()>=200000)
            {
                if(stl[0].toInt()-200000<m_node_list.size())
                {
                    show+=m_node_list[stl[0].toInt()-200000].name;
                    show+=":";
                    show+=m_node_list[stl[0].toInt()-200000].outtype_info[stl[1].toInt()];
                }

                if(stl[0].toInt()==300001)
                {
                    if(stl[1].toInt()==1)
                    {
                        show+="比较值";
                    }
                    else if(stl[1].toInt()==2)
                    {
                        show+="待比值";
                    }
                }

                if(i!=d.WhoGiveMe.size()-1)
                {
                    show+=" ";
                }
            }
            else
            {
                if(stl[0].toInt()<m_param_list.size())
                {
                    show+=m_param_list[stl[0].toInt()].name;
                    show+=":";
                    show+=m_param_list[stl[0].toInt()].outtype_info[stl[1].toInt()];
                }
                if(i!=d.WhoGiveMe.size()-1)
                {
                    show+=" ";
                }
            }
        }
        break;
    }
    QLabel* l_=new QLabel();
    l_->setText(show);
    l_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    box->addWidget(l_);

    if(d.type == "image")
    {
        QComboBox* put=new QComboBox();
        put->addItem("显示");
        put->addItem("隐藏");
        put->addItem("输出");
        box->addWidget(put);

        wl.push_back(put);
    }
    else if(d.type == "color")
    {
        QLabel* R=new QLabel("R:");
        QSpinBox* r=new QSpinBox();
        r->setMinimum(0);
        r->setMaximum(255);

        QLabel* G=new QLabel("G:");
        QSpinBox* g=new QSpinBox();
        g->setMinimum(0);
        g->setMaximum(255);

        QLabel* B=new QLabel("B:");
        QSpinBox* b=new QSpinBox();
        b->setMinimum(0);
        b->setMaximum(255);

        r->setEnabled(false);
        g->setEnabled(false);
        b->setEnabled(false);

        box->addWidget(R);
        box->addWidget(r);
        box->addWidget(G);
        box->addWidget(g);
        box->addWidget(B);
        box->addWidget(b);

        wl.push_back(r);
        wl.push_back(g);
        wl.push_back(b);
    }
    else if(d.type == "size")
    {
        QLabel* W=new QLabel("Width:");
        QSpinBox* w=new QSpinBox();
        w->setMinimum(0);
        w->setMaximum(5000);

        QLabel* H=new QLabel("Height:");
        QSpinBox* h=new QSpinBox();
        h->setMinimum(0);
        h->setMaximum(5000);

        w->setEnabled(false);
        h->setEnabled(false);

        box->addWidget(W);
        box->addWidget(w);
        box->addWidget(H);
        box->addWidget(h);

        wl.push_back(w);
        wl.push_back(h);
    }
    else if(d.type == "rect")
    {
        QLabel* X=new QLabel("X:");
        QSpinBox* x=new QSpinBox();
        x->setMinimum(0);
        x->setMaximum(5000);

        QLabel* Y=new QLabel("Y:");
        QSpinBox* y=new QSpinBox();
        y->setMinimum(0);
        y->setMaximum(5000);

        QLabel* W=new QLabel("Width:");
        QSpinBox* w=new QSpinBox();
        w->setMinimum(0);
        w->setMaximum(5000);

        QLabel* H=new QLabel("Height:");
        QSpinBox* h=new QSpinBox();
        h->setMinimum(0);
        h->setMaximum(5000);

        x->setEnabled(false);
        y->setEnabled(false);
        w->setEnabled(false);
        h->setEnabled(false);

        box->addWidget(X);
        box->addWidget(x);
        box->addWidget(Y);
        box->addWidget(y);
        box->addWidget(W);
        box->addWidget(w);
        box->addWidget(H);
        box->addWidget(h);

        wl.push_back(x);
        wl.push_back(y);
        wl.push_back(w);
        wl.push_back(h);
    }
    else if(d.type == "bool")
    {
        QCheckBox* put=new QCheckBox();
        put->setText("");

        put->setEnabled(false);

        box->addWidget(put);

        wl.push_back(put);
    }
    else if(d.type == "int")
    {
        QSpinBox* put=new QSpinBox();
        put->setMinimum(-5000);
        put->setMaximum(5000);

        put->setEnabled(false);

        box->addWidget(put);

        wl.push_back(put);
    }
    else if(d.type == "float")
    {
        QDoubleSpinBox* put=new QDoubleSpinBox();
        put->setMinimum(-5000);
        put->setMaximum(5000);

        put->setEnabled(false);

        box->addWidget(put);

        wl.push_back(put);
    }
    else if(d.type == "double")
    {
        QDoubleSpinBox* put=new QDoubleSpinBox();
        put->setMinimum(-5000);
        put->setMaximum(5000);

        put->setEnabled(false);

        box->addWidget(put);

        wl.push_back(put);
    }
    else
    {
        QLineEdit* put=new QLineEdit();

        put->setEnabled(false);

        box->addWidget(put);

        wl.push_back(put);
    }

    ui->verticalLayout_output->addLayout(box);
    return wl;
}

QVariant nsv_tree::get_value(data_cross &d,QList<QWidget*> wl)
{
    QVariant vd;

    if(wl.size()>0)
    {
        if(d.type == "image")
        {
            QComboBox* put=qobject_cast<QComboBox*>(wl[0]);
            vd.setValue<QString>(put->currentText());
        }
        else if(d.type == "color")
        {
            QSpinBox* r=qobject_cast<QSpinBox*>(wl[0]);
            QSpinBox* g=qobject_cast<QSpinBox*>(wl[1]);
            QSpinBox* b=qobject_cast<QSpinBox*>(wl[2]);
            vd.setValue<cv::Scalar>(cv::Scalar(b->value(),g->value(),r->value()));
        }
        else if(d.type == "size")
        {
            QSpinBox* w=qobject_cast<QSpinBox*>(wl[0]);
            QSpinBox* h=qobject_cast<QSpinBox*>(wl[1]);
            vd.setValue<cv::Size>(cv::Size(w->value(),h->value()));
        }
        else if(d.type == "rect")
        {
            QSpinBox* x=qobject_cast<QSpinBox*>(wl[0]);
            QSpinBox* y=qobject_cast<QSpinBox*>(wl[1]);
            QSpinBox* w=qobject_cast<QSpinBox*>(wl[2]);
            QSpinBox* h=qobject_cast<QSpinBox*>(wl[3]);
            vd.setValue<cv::Rect>(cv::Rect(x->value(),y->value(),w->value(),h->value()));
        }
        else if(d.type == "bool")
        {
            QCheckBox* put=qobject_cast<QCheckBox*>(wl[0]);
            vd.setValue<bool>(put->isChecked());
        }
        else if(d.type == "int")
        {
            QSpinBox* put=qobject_cast<QSpinBox*>(wl[0]);
            vd.setValue<int>(put->value());
        }
        else if(d.type == "float")
        {
            QDoubleSpinBox* put=qobject_cast<QDoubleSpinBox*>(wl[0]);
            vd.setValue<float>(put->value());
        }
        else if(d.type == "double")
        {
            QDoubleSpinBox* put=qobject_cast<QDoubleSpinBox*>(wl[0]);
            vd.setValue<double>(put->value());
        }
        else
        {
            QLineEdit* put=qobject_cast<QLineEdit*>(wl[0]);
            vd.setValue<QString>(put->text());
        }
        d.data=vd;
    }

    return vd;
}

data_cross nsv_tree::show_value(QVariant da,data_cross d,QList<QWidget*> wl)
{
    if(wl.size()>0)
    {
        if(d.type == "color")
        {
            QSpinBox* r=qobject_cast<QSpinBox*>(wl[0]);
            QSpinBox* g=qobject_cast<QSpinBox*>(wl[1]);
            QSpinBox* b=qobject_cast<QSpinBox*>(wl[2]);
            if(!nsv_image_tree::isNull(da))
            {
                r->setValue(da.value<cv::Scalar>()[2]);
                g->setValue(da.value<cv::Scalar>()[1]);
                b->setValue(da.value<cv::Scalar>()[0]);
            }
        }
        else if(d.type == "size")
        {
            QSpinBox* w=qobject_cast<QSpinBox*>(wl[0]);
            QSpinBox* h=qobject_cast<QSpinBox*>(wl[1]);
            if(!nsv_image_tree::isNull(da))
            {
                w->setValue(da.value<cv::Size>().width);
                h->setValue(da.value<cv::Size>().height);
            }
        }
        else if(d.type == "rect")
        {
            QSpinBox* x=qobject_cast<QSpinBox*>(wl[0]);
            QSpinBox* y=qobject_cast<QSpinBox*>(wl[1]);
            QSpinBox* w=qobject_cast<QSpinBox*>(wl[2]);
            QSpinBox* h=qobject_cast<QSpinBox*>(wl[3]);
            if(!nsv_image_tree::isNull(da))
            {
                x->setValue(da.value<cv::Rect>().x);
                y->setValue(da.value<cv::Rect>().y);
                w->setValue(da.value<cv::Rect>().width);
                h->setValue(da.value<cv::Rect>().height);
            }
        }
        else if(d.type == "bool")
        {
            QCheckBox* put=qobject_cast<QCheckBox*>(wl[0]);
            if(!nsv_image_tree::isNull(da))
            {
                put->setChecked(da.toBool());
            }
        }
        else if(d.type == "int")
        {
            QSpinBox* put=qobject_cast<QSpinBox*>(wl[0]);
            if(!nsv_image_tree::isNull(da))
            {
                put->setValue(da.toInt());
            }
        }
        else if(d.type == "float")
        {
            QDoubleSpinBox* put=qobject_cast<QDoubleSpinBox*>(wl[0]);
            if(!nsv_image_tree::isNull(da))
            {
                put->setValue(da.toFloat());
            }
        }
        else if(d.type == "double")
        {
            QDoubleSpinBox* put=qobject_cast<QDoubleSpinBox*>(wl[0]);
            if(!nsv_image_tree::isNull(da))
            {
                put->setValue(da.toDouble());
            }
        }
        else if(d.type == "image")
        {
            QComboBox* put=qobject_cast<QComboBox*>(wl[0]);
            if(!nsv_image_tree::isNull(da))
            {
                QString das=da.toString();

                if(da=="")
                {
                   da="显示";
                }

                if(das!="显示" && das!="隐藏" && das!="输出" && das!="原图" && das!="")
                {
                    put->addItem(das);
                }
                put->setCurrentText(das);
            }
        }
        else
        {

        }
        d.data=da;
    }

    return d;
}

void nsv_tree::on_pushButton_clicked()
{
    if(isShrink)
    {
        ui->groupBox_right->setMaximumWidth(16777215);
        ui->groupBox_left->setMaximumWidth(800);
        isShrink=false;
    }
    else
    {
        ui->groupBox_right->setMaximumWidth(350);
        ui->groupBox_left->setMaximumWidth(16777215);
        isShrink=true;
    }
}

