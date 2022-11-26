#include "labels_ui.h"
#include "ui_labels_ui.h"

labels_ui::labels_ui(QWidget *parent) :QDialog(parent),ui(new Ui::labels_ui)
{
    ui->setupUi(this);
    this->setWindowTitle("labels");
    now_label="";
    this->setFocus();
}

labels_ui::~labels_ui()
{
    delete ui;
}

void labels_ui::addlistLabel(QList<QString> list)
{
    labels=list;

    plabel_clear();

    for(int i=0;i<list.size();i++)
    {
        QString text ="";

        switch(i)
        {
        case 0:
            text = "(Z)";
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
        nlabelchoosepushbutton* p = new nlabelchoosepushbutton(this,list[i],text);
        ui->verticalLayout_labels->addWidget(p);
        connect(p,SIGNAL(pushlabel(QString)),this,SLOT(chooseLabel(QString)));
    }
}

void labels_ui::plabel_clear()
{
    QLayoutItem *child;
    while ((child = ui->verticalLayout_labels->takeAt(0)) != 0)
    {
        if(child->widget())
        {
            ui->verticalLayout_labels->removeWidget(child->widget());
            child->widget()->setParent(NULL);
        }
        delete child;
    }
}

void labels_ui::chooseLabel(QString label)
{
    close();
    ui->lineEdit_label->setText(label);
    now_label=label;
    emit push_label(label);
}

void labels_ui::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Z:
        if(labels.size()>0)
        {
            chooseLabel(labels[0]);
        }
        break;
    case Qt::Key_X:
        if(labels.size()>1)
        {
            chooseLabel(labels[1]);
        }
        break;
    case Qt::Key_C:
        if(labels.size()>2)
        {
            chooseLabel(labels[2]);
        }
        break;
    case Qt::Key_V:
        if(labels.size()>3)
        {
            chooseLabel(labels[3]);
        }
        break;
    case Qt::Key_B:
        if(labels.size()>4)
        {
            chooseLabel(labels[4]);
        }
        break;
    case Qt::Key_N:
        if(labels.size()>5)
        {
            chooseLabel(labels[5]);
        }
        break;
    case 16777220:
        on_pushButton_addlabel_clicked();
        break;
    case 16777216:
        chooseLabel(labels[0]);
        break;
    }
}

void labels_ui::on_pushButton_addlabel_clicked()
{
    QString label=ui->lineEdit_label->text();
    if(label!="" && !StrinList(label,labels))
    {
        labels.append(label);
        QString text ="";
        switch(labels.size()-1)
        {
        case 0:
            text="(Z)";
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
        nlabelchoosepushbutton *p = new nlabelchoosepushbutton(this,label,text);
        ui->verticalLayout_labels->addWidget(p);
        connect(p,SIGNAL(pushlabel(QString)),this,SLOT(chooseLabel(QString)));
        emit labels_updata(label);
    }
}
