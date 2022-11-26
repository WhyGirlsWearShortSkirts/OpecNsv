#ifndef LATTREE_PARAM_H
#define LATTREE_PARAM_H

#include<QString>
#include<QIcon>
#include<QLayout>
#include<QWidget>
#include<QtDebug>
#include<QPainter>
#include<QCoreApplication>

//变量
struct data_cross
{
    int tig=1000000;//变量标号，从100000开始至200000结束。

    QString name;//变量名

    QString type;//变量类型

    QVariant data;//变量值

    int attr=0;//变量属性(1 输入,2 输出,3 节点,0 未使用)

    bool isGiveBefore=false;//是否提前给出

    bool isUseLast=false;//是否后续使用

    QList<QString> WhoGiveMe;//卖家集合

    QList<QString> WhoUseMe;//买家集合

    bool isFixed=false;//是否为定值
};

//算子
struct param_cross
{
    int tig=1000000;//算法编号，从0开始至100000结束。

    QString name="";//算法名

    QString info="";//算法描述

    QString param="";//输入输出描述

    QIcon ico;//算法图标

    QList<QString> intype;//算法输入（类型）

    QList<QString> outtype;//算法输出（类型）

    QList<QString> intype_info;//算法输入（描述）

    QList<QString> outtype_info;//算法输出（描述）

    QList<int> inList;//输入赋值（变量）

    QList<int> outList;//输出赋值（变量）

    bool canrun=false;
};

//节点
struct node_cross
{
    int tig=1000000;//节点编号，从200000开始至300000结束。

    QString name="";//节点名

    QString info="";//节点描述

    QString param="";//输入输出描述

    QIcon ico;//节点图标

    QList<QString> intype;//节点输入（类型）

    QList<QString> outtype;//节点输出（类型）

    QList<QString> intype_info;//节点输入（描述）

    QList<QString> outtype_info;//节点输出（描述）

    QList<int> inList;//输入赋值（变量）

    QList<int> outList;//输出赋值（变量）

    QString tree="";//节点内树形图

    QImage tree_img;//节点内树形图显示

    QString data="";//节点内变量表

    QImage data_img;//节点内变量表显示

    QList<data_cross> dataList;//节点内变量表（与整体变量表不吻合)

    QList<int> inList_inside;//节点内输入变量赋值

    QList<int> outList_inside;//节点内输出变量赋值
};

//流程树外观控制
struct style_list
{
    QString item="color:rgba(255,255,255,1);background-color:rgba(0,0,0,0.2);";

    QString back="color:rgba(0,0,0,1);background-color:rgba(0,0,0,0.0);";

    QString group="color:rgba(0,0,0,1); background-color:rgba(0,0,0,0.2);"
                  "QTextBrowser{color:rgba(255,255,255,1);background-color:rgba(255,255,255,0.3);}";

    QString widget="color:rgba(0,0,0,1); background-color:rgba(0,0,0,0.0);";

    QString ui="color:rgba(255,255,255,1); background-color:rgba(200,200,200,0.6);";

    QString pushButton="QPushButton{color:rgba(0,0,0,1); background-color:rgba(80,80,80,0.5);}"
                       "QToolButton{color:rgba(255,255,255,1); background-color:rgba(80,80,80,0.5);}"
                       "QGroupBox{background-color:rgba(255,255,255,0.3);border:0 pix;}";

    QString pushButton_click="QPushButton{color:rgba(0,255,0,1); background-color:rgba(255,30,100,0.7);}"
                             "QToolButton{color:rgba(0,255,0,1); background-color:rgba(255,30,100,0.7);}"
                             "QGroupBox{background-color:rgba(255,255,255,0.3);border:0 pix;}";

    QString pushButton_error="background-color:rgba(255,0,0,0.5)";

    QString pushButton_type_error="background-color:rgba(255,255,0,0.5)";

    QString data_input="QLabel{color:rgba(255,255,0,1); background-color:rgba(50,50,50,0.3);}";

    QString data_output="QLabel{color:rgba(150,255,150,1); background-color:rgba(50,50,50,0.3);}";

    QString data_link="QLabel{color:rgba(0,0,0,1); background-color:rgba(50,50,50,0.3);}";

    QString data_nouse="QLabel{color:rgba(255,255,255,1); background-color:rgba(50,50,50,0.3);}";

    QString tite="color:rgba(0,0,0,1);";

    QString param="QToolButton{color:rgba(255,255,255,1);}"
                  "QLabel{color:rgba(255,255,255,1);}"
                  "QTextBrowser{color:rgba(255,255,255,1);}"
                  "QGroupBox{color:rgba(255,255,255,1); background-color:rgba(80,150,150,0.1);}";

    QString node ="QToolButton{color:rgba(255,255,255,1);}"
                  "QLabel{color:rgba(255,255,255,1);}"
                  "QTextBrowser{color:rgba(255,255,255,1);}"
                  "QGroupBox{color:rgba(255,255,255,1); background-color:rgba(80,110,150,0.1);}";

    QString Compare ="QToolButton{color:rgba(255,255,255,1);}"
                     "QLabel{color:rgba(255,255,255,1);}"
                     "QTextBrowser{color:rgba(255,255,255,1);}"
                     "QGroupBox{color:rgba(255,255,255,1); background-color:rgba(150,80,150,0.1);}";

    QString name = "QToolButton{color:rgba(255,255,255,1); background-color:rgba(50,50,50,0);font: 23pt 'Microsoft YaHei UI';}";
};

//流程树
struct tree_param
{
    QString tree="";//流程树
    QString data="";//变量表

    QImage tree_img;//树形图显示
    QImage data_img;//变量表显示

    QList<data_cross> d_l;//变量表
    QList<node_cross> n_l;//节点表
    QList<param_cross> p_l;//算法表
};

Q_DECLARE_METATYPE(data_cross)
Q_DECLARE_METATYPE(node_cross)
Q_DECLARE_METATYPE(tree_param)

inline bool StrinList_tree(QString str,QList<QString> labels)
{
    bool flag=false;
    for(int i=0;i<labels.size();i++)
    {
        if(labels[i]==str)
        {
            flag=true;
        }
    }
    return flag;
}

inline QList<QColor> init_color_label()
{
    QList<QColor> color_list;

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

    return color_list;
}

inline void deleteAllitemsOfLayout(QLayout* layout)
{
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr)
    {
        if(child->widget())
        {
            child->widget()->setParent(nullptr);
        }
        else if(child->layout())
        {
            deleteAllitemsOfLayout(child->layout());
        }
        delete child;
    }
}

inline void setHiddAllitemsOfLayout(QLayout* layout)
{
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr)
    {
        if(child->widget())
        {
            child->widget()->setHidden(1);
        }
        else if(child->layout())
        {
            setHiddAllitemsOfLayout(child->layout());
        }
        delete child;
    }
}

inline QImage getScrollArea(QWidget* widget)
{
    QPixmap pix=widget->grab();

    QImage img=pix.toImage();

    return img;
}

#endif // LATTREE_PARAM_H
