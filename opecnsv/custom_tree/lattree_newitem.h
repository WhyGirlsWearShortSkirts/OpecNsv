#ifndef LATTREE_NEWITEM_H
#define LATTREE_NEWITEM_H

#include <QDialog>
#include <QLabel>
#include <QIcon>
#include <QApplication>
#include <QPushButton>
#include <QtWidgets>

#include "param/lattree_param.h"
#include "custom_tree/lattree_pushbutton.h"

namespace Ui
{
    class LatTree_NewItem;
}

class LatTree_NewItem : public QDialog
{
    Q_OBJECT
public:
    explicit LatTree_NewItem(QWidget *parent = nullptr, int type=0);

    ~LatTree_NewItem();

protected slots:

    void paintEvent(QPaintEvent *event);

public slots:

    void setCroItem(QList<param_cross> p);

    void setNode(QList<node_cross> dolist);

    void setTip(int tip){m_tip_now=tip;};

    int getTip(){return m_tip_now;};

    void setHow(int tip);

    int getHow(){return m_how_now;};

    void showHow(bool show);

    void clear_Action();

    void hiddHow(bool show);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::LatTree_NewItem *ui;

    QList<param_cross> m_param_c_list;
    QList<node_cross> m_node_list;
    QList<QColor> m_color_list;

    QColor m_howcolor;

    style_list style_this;

    int m_tip_now=0;

    int m_how_now=100000;

    bool itemlist_color_diffent=false;
};

#endif // LATTREE_NEWITEM_H
