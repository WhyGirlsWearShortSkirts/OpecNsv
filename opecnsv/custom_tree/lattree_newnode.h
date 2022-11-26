#ifndef LATTREE_NEWNODE_H
#define LATTREE_NEWNODE_H

#include <QDialog>

#include "param/lattree_param.h"
#include "custom_tree/lattree_pushbutton.h"

namespace Ui {
class LatTree_NewNode;
}

class LatTree_NewNode : public QDialog
{
    Q_OBJECT

public:
    explicit LatTree_NewNode(QWidget *parent = nullptr);
    ~LatTree_NewNode();

    void setNodeList(QList<node_cross> list){m_node_list=list;};

    QList<node_cross> AllNode(){return m_node_list;};

    void setNodeItem(QList<node_cross> p_l);

    node_cross NowNode(){return m_now_node;};

    void setNodeNow(node_cross p){m_now_node=p;};

    QList<QString> NodeName(){return m_name_list;};

private slots:
    void on_pushButton_add_node_clicked();

private:
    Ui::LatTree_NewNode *ui;

    QList<node_cross> m_node_list;

    QList<QString> m_name_list;

    style_list style_this;

    node_cross m_now_node;
};

#endif // LATTREE_NEWNODE_H
