#include "ocr_more_view.h"
#include "ui_ocr_more_view.h"

Ocr_More_View::Ocr_More_View(QWidget *parent) :QDialog(parent),ui(new Ui::Ocr_More_View)
{
    ui->setupUi(this);

    init_UI();
    init_Conn();
}

Ocr_More_View::~Ocr_More_View()
{
    delete ui;
}

void Ocr_More_View::addimage(cv::Mat image)
{
    ui->graphicsView->object_clear();
    ui->graphicsView->image_add(image);
}

QList<Item_save> Ocr_More_View::back_itemlist()
{
    QList<QGraphicsItem*> pl =ui->graphicsView->ploygon_list;

    QList<Item_save> group;
    for(int i=0;i<pl.size();i++)
    {
        if(pl[i]->type()==QGraphicsItem::UserType+10)
        {
            NPolygon *item_c = qgraphicsitem_cast<NPolygon *>(pl[i]);
            if(item_c->getType()!=2)
            {
                Item_save is;
                is.pointlist.append(item_c->getPointlist());
                is.labels.append(item_c->getlabel());
                is.type=item_c->getType();
                is.angle.append(item_c->getangle());
                group.append(is);
            }
        }
    }

    return group;
}

cv::Mat Ocr_More_View::back_image()
{
    cv::Mat image=ui->graphicsView->getimage();
    return image;
}

//初始化UI界面

void Ocr_More_View::init_UI()
{
    this->setWindowTitle("Ocr_Char");
    this->setWindowIcon(QIcon("titg.ico"));
    this->setMouseTracking(1);//鼠标追踪
    this->setMinimumSize(1700,900);
    this->setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);

    init_tagging_type();

    ui->groupBox_nowlabels->setHidden(0);

    ui->groupBox_tagging_type->setHidden(1);

    ui->groupBox_tagging_type->setEnabled(false);
}

void Ocr_More_View::init_tagging_type()
{
    //设置下划线颜色
    button_group->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group->setLineHeight(4);
    //设置下划线位置
    button_group->setButtonPosition(CusButtonGroup::West);

    QPushButton *btn = new QPushButton;
    btn->setCheckable(true);
    btn->setText("多边形");
    btn->setFixedSize(260,25);
    button_group->addButton(btn,0);

    QPushButton *btn1 = new QPushButton;
    btn1->setCheckable(true);
    btn1->setText("矩形");
    btn1->setFixedSize(260,25);
    button_group->addButton(btn1,1);

    QPushButton *btn2 = new QPushButton;
    btn2->setCheckable(true);
    btn2->setText("圆头画笔");
    btn2->setFixedSize(260,25);
    button_group->addButton(btn2,2);

    QPushButton *btn3 = new QPushButton;
    btn3->setCheckable(true);
    btn3->setText("方头画笔");
    btn3->setFixedSize(260,25);
    button_group->addButton(btn3,3);

    QPushButton *btn4 = new QPushButton;
    btn4->setCheckable(true);
    btn4->setText("区域蒙版");
    btn4->setFixedSize(260,25);
    button_group->addButton(btn4,4);

    button_group->onbuttonClicked(0);

    ui->verticalLayout_tagg_type->addWidget(button_group);
    ui->comboBox_tiggtype->setHidden(1);
}

void Ocr_More_View::init_Conn()
{
    connect(ui->graphicsView,SIGNAL(labels_change(QList<QString>)),this,SLOT(labels_show(QList<QString>)));
    connect(ui->graphicsView,SIGNAL(nowlabelschange(QList<QString>)),this,SLOT(nowlabels_show(QList<QString>)));
    connect(ui->graphicsView,SIGNAL(key_event(QKeyEvent *)),this,SLOT(keyPressEvent(QKeyEvent *)));

    connect(button_group,SIGNAL(choose_buttons(int)),ui->comboBox_tiggtype,SLOT(setCurrentIndex(int)));
}

void Ocr_More_View::on_checkBox_tigging_clicked()
{
    if(ui->graphicsView->scene.is_creating_BPolygon)
    {
        ui->checkBox_tigging->setChecked(true);
        QMessageBox msgBox;
        msgBox.setText("正在绘制时无法开关标定功能。");
        msgBox.setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox.exec();
    }
    else
    {
        if(ui->checkBox_tigging->isChecked())
        {
            on_comboBox_tiggtype_currentIndexChanged(ui->comboBox_tiggtype->currentIndex());

            ui->comboBox_tiggtype->setEnabled(false);
            button_group->setEnabled(false);
            ui->pushButton_tagging_now_type->setEnabled(false);

            ui->graphicsView->object_add_pointlist(true,tag_type,0);
        }
        else
        {

            ui->pushButton_tagging_now_type->setEnabled(true);
            ui->comboBox_tiggtype->setEnabled(true);
            button_group->setEnabled(true);

            ui->graphicsView->object_add_pointlist(false,tag_type,0);
        }
    }
}

void Ocr_More_View::on_comboBox_tiggtype_currentIndexChanged(int index)
{
    tag_type=index;
    ui->pushButton_tagging_now_type->setText(ui->comboBox_tiggtype->currentText());
    ui->groupBox_tagging_type->setHidden(1);
    ui->groupBox_tagging_type->setEnabled(false);
    ui->pushButton_tagging_now_type->setHidden(0);
}

void Ocr_More_View::on_pushButton_tagging_now_type_clicked()
{
    ui->groupBox_tagging_type->setHidden(0);
    ui->pushButton_tagging_now_type->setHidden(1);
    ui->groupBox_tagging_type->setEnabled(true);
}

void Ocr_More_View::on_pushButton_tagging_type_open_clicked()
{
    if(ui->groupBox_tagging_type->isEnabled())
    {
        on_comboBox_tiggtype_currentIndexChanged(tag_type);
        ui->pushButton_tagging_type_open->setText("标注方式：◣ ");
    }
    else
    {
        on_pushButton_tagging_now_type_clicked();
        ui->pushButton_tagging_type_open->setText("标注方式：◢ ");
    }
}

//快捷键

void Ocr_More_View::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_S:
        if(ui->checkBox_tigging->isChecked())
        {
            ui->checkBox_tigging->setChecked(false);
        }
        else
        {
            ui->checkBox_tigging->setChecked(true);
        }
        on_checkBox_tigging_clicked();
        break;
    }
}

//标注标签显示

void Ocr_More_View::labels_show(QList<QString> list)
{
    labels_clear();

    for(int i=0;i<list.size();i++)
    {
        QString text ="";
        switch(i)
        {
        case 0:
            text ="(Z)";
            break;
        case 1:
            text="(X)";
            break;
        case 2:
            text="(C)";
            break;
        case 3:
            text="(V)";
            break;
        case 4:
            text="(B)";
            break;
        case 5:
            text="(N)";
            break;
        default:
            text="";
            break;
        }
        nlabelchoosepushbutton *p = new nlabelchoosepushbutton(this,list[i],text,ui->graphicsView->color_list[i]);
        ui->verticalLayout_labels_show->addWidget(p);
    }
}

void Ocr_More_View::labels_clear()
{
    QLayoutItem *child;
    while ((child = ui->verticalLayout_labels_show->takeAt(0)) != 0)
    {
        if(child->widget())
        {
            ui->verticalLayout_labels_show->removeWidget(child->widget());
            delete child;
            child->widget()->setHidden(1);
        }
    }
}

void Ocr_More_View::nowlabels_clear()
{
    QLayoutItem *child;
    while ((child = ui->verticalLayout_labels_now->takeAt(0)) != 0)
    {
        if(child->widget())
        {
            ui->verticalLayout_labels_now->removeWidget(child->widget());
            delete child;
            child->widget()->setHidden(1);
        }
    }
}

void Ocr_More_View::nowlabels_show(QList<QString> list)
{
    nowlabels_clear();

    for(int i=0;i<list.size();i++)
    {
        QString text ="";
        nlabelchoosepushbutton *p = new nlabelchoosepushbutton(this,list[i],text,QColor(200,100,69));
        ui->verticalLayout_labels_now->addWidget(p);
    }
}


