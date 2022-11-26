#ifndef NSV_TREE_H
#define NSV_TREE_H

#include <QDialog>
#include <QLayout>
#include <QThread>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include "param/nsv_image_tree.h"
#include "custom_tree/lattree_pushbutton.h"

namespace Ui {
class nsv_tree;
}

class nsv_tree : public QDialog
{
    Q_OBJECT

signals:

    void TreeRunFinish(cv::Mat);

public:

    explicit nsv_tree(QWidget *parent = nullptr);

    ~nsv_tree();

public slots:

    void GetTree();

    void TreeRun();

    void AddNode();

    void AddNodeToDefault();

    void SaveTree();

    void ReadTree();

    void setNowImage(cv::Mat image){m_image_now=image.clone();};

    QList<QWidget*> add_new_input(data_cross d);

    QList<QWidget*> add_new_output(data_cross d);

    QVariant get_value(data_cross &d, QList<QWidget *> wl);

    data_cross show_value(QVariant da, data_cross d, QList<QWidget *> wl);

    void RunTree(cv::Mat image_now);

protected slots:

    void init_item();

    void init_node();

    void result_show(QList<QVariant> result);

    void error_show(QString error);

private slots:

    void init_ui();

    void on_pushButton_torun_clicked();

    void on_pushButton_back_tree_clicked();

    void on_pushButton_clicked();

private:

    Ui::nsv_tree *ui;

    QList<QList<QWidget*>> m_widge_list;

    tree_param m_tree;

    nsv_image_tree* m_tree_run=new nsv_image_tree();

    QList<QVariant> m_exec_data;

    QList<QVariant> m_exec_data_c;

    QList<param_cross> m_param_list;

    QList<node_cross> m_node_list;

    cv::Mat m_image_now;

    cv::Mat m_image_result;

    LButtonGroup* button_group=new LButtonGroup(this);

    bool isShrink=true;

    DWORD Start;

    QFuture<void> f3;
};

#endif // NSV_TREE_H
