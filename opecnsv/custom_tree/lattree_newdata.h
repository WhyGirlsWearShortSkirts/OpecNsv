#ifndef LATTREE_NEWDATA_H
#define LATTREE_NEWDATA_H

#include <QDialog>
#include <param/lattree_param.h>
#include <custom_tree/lattree_pushbutton.h>

namespace Ui
{
    class LatTree_NewData;
}

class LatTree_NewData : public QDialog
{
    Q_OBJECT

public:
    explicit LatTree_NewData(QWidget *parent = nullptr);

    ~LatTree_NewData();

    void setData(QList<data_cross> data_list){m_data_list=data_list;init_type();};

    QList<data_cross> getData(){return m_data_list;};

    void setNowData(data_cross data){m_now_data=data;};

    data_cross getNowData(){return m_now_data;};

    void setdefaultType(QList<QString> type){m_type_list=type;show_type_show();};

    void show_type_show();

private slots:
    void ChoType(int type);

    void on_pushButton_clicked();

private:
    Ui::LatTree_NewData *ui;

    QList<data_cross> m_data_list;

    QList<QString> m_type_list;

    QList<QString> m_name_list;

    data_cross m_now_data;

    style_list style_this;

    void init_type();
};

#endif // LATTREE_NEWDATA_H
