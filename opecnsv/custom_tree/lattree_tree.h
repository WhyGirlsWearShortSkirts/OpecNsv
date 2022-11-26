#ifndef LACTTREESOALLAREA_H
#define LACTTREESOALLAREA_H

#include <QScrollArea>
#include <QGroupBox>
#include <QPushButton>
#include <QToolButton>
#include <QMessageBox>
#include <QLayout>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QImage>
#include <QPaintEvent>

#include "custom_tree/lattree_newitem.h"
#include "custom_tree/lattree_newdata.h"
#include "custom_tree/lattree_newnode.h"
#include "custom_tree/lattree_pushbutton.h"
#include "param/lattree_param.h"
#include "param/nsv_image_tree.h"

class LActCross :  public QGroupBox
{
    Q_OBJECT

signals:

    void isYou(int);

    void clearData();

public:

    LActCross(QWidget *parent);

public:
    void setitemlist(QList<param_cross> p_l){m_param_list=p_l;init_item();};//设置算子集

    QList<param_cross> itemlist(){return m_param_list;};//获取算子集

    void setdatalist(QString d_l){m_data=d_l;init_data();};//设置变量表

    QString datalist(){return m_data;};//获取变量表

    void setdefaultType(QList<QString> type);

    tree_param now_Tree();

    void set_Tree(tree_param t);

    void add_Button(QString name, bool isrisk, const QObject *receiver, const char *member);

public slots:

    void addNext(QRect where);

    void tree_clear();

    void dlAllBran();

    void showData(QRect where, int tig);

    void showAct(QRect where, int tig);

    void ShowNode(node_cross node);

    void NowItem();

    void setData(QList<data_cross> datalist);

    void setTree(QString tree);

    void addData(int tig);

    void choData(int tig);

    void DeleteData();

    void SaveAsNode();

    void saveAsPng();

    void DeleteAllData();

    void set_Node(QList<node_cross> n_l);

protected slots:

    void paintEvent(QPaintEvent *event);

    void DeleteItem();

    void reviseData(data_cross d);

private slots:

    void DataLeft();

    void DataRight();

private:

    QList<param_cross> m_param_list;

    QList<data_cross> m_data_list;

    QList<node_cross> m_node_list;

    QList<QString> m_node_name;

    QList<QColor> m_color_list;

    LatTree_NewItem* m_param_ui = new LatTree_NewItem();

    LatTree_NewItem* m_build_ui = new LatTree_NewItem(nullptr,1);

    LatTree_NewItem* m_judge_ui = new LatTree_NewItem(nullptr,2);

    LatTree_NewData* m_data_ui = new LatTree_NewData();

    LatTree_NewNode* m_node_ui = new LatTree_NewNode();

    QString m_tree="";

    QString m_data="";

    QVBoxLayout* root_box=new QVBoxLayout();

    QHBoxLayout* root_box_back=new QHBoxLayout();

    QGroupBox* m_group_param=new QGroupBox();

    QGridLayout* m_param_box=new QGridLayout();

    QLabel* label_tite_=new QLabel();

    QPushButton* label_ico_=new QPushButton();

    QTextBrowser* label_info_=new QTextBrowser();

    QTextBrowser* label_param_=new QTextBrowser();

    QScrollArea* m_group_tree=new QScrollArea();

    QScrollArea* m_group_data=new QScrollArea();

    QScrollBar* m_data_horbar=new QScrollBar(Qt::Horizontal);

    QHBoxLayout* m_data_box_back=new QHBoxLayout();

    QPushButton* m_data_left=new QPushButton();

    QPushButton* m_data_right=new QPushButton();

    QHBoxLayout* m_tree_box=new QHBoxLayout();

    QHBoxLayout* m_data_box=new QHBoxLayout();

    QGroupBox* m_group_do=new QGroupBox();

    QVBoxLayout* m_do_box=new QVBoxLayout();

    QWidget* m_tree_widget=new QWidget();

    QWidget* m_data_widget=new QWidget();

    QSpacerItem herSpacer = QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QSpacerItem verSpacer = QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Expanding);

    QRect m_data_where = QRect(0,0,0,0);

    style_list style_this;

    int m_tree_rows=0;

    int m_tree_cols=0;

    int m_data_cols=0;

    int m_tip_now=0;

    void init_box();

    void init_param();

    void init_tree();

    void init_data();

    void init_do();

    void init_item();

    void addNewItem(QList<param_cross> start_list, int col);

    void addNewData(data_cross d, int col);

    void ClearDataAttr();
};

#endif // LACTTREESOALLAREA_H
