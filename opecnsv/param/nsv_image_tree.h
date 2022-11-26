#ifndef NSV_IMAGE_TREE_H
#define NSV_IMAGE_TREE_H

#include "lattree_param.h"
#include "nsv_include.h"
#include <QDebug>
#include <QObject>
#include <QPixmap>

class nsv_image_tree : public QObject
{
    Q_OBJECT

signals:

    void run_back(QList<QVariant>);

    void error_back(QString);

public:
    nsv_image_tree();

public:
    static QList<param_cross> init_Param();

    static QList<QString> init_Type();

    static QList<QVariant> GetDataList(QList<data_cross> data_list);

    static QList<QVariant> item_an(QList<QVariant> input, param_cross param);

    static void LDebug(param_cross p);

    static QList<QList<param_cross>> ListAsTree(QString tree, QList<data_cross> &data_list, QList<param_cross> param_list, QList<node_cross> node_list);

    static inline bool isNull(QVariant value)
    {
        static QVariant nullVariant = QVariant::fromValue((QObject * const)nullptr);
        return value == nullVariant;
    }

    QList<QVariant> item_run(tree_param tree, QList<QVariant> exec_data);

    QList<QVariant> item_run_an(param_cross p, tree_param tree, QList<QVariant> exec_data);

    int item_run_judge(int type, data_cross d1, data_cross d2);

    void item_th();

    static QString special_data_save(QString type, QVariant da);

    static QVariant special_data_read(QString type, QString da);

    static bool judge_type_enable(int tip, QString type);

    static QList<data_cross> ListAsData(QString data);

    static QString DataAsList(QList<data_cross> dl);

    static QString SaveNode(node_cross n,QString where);

    static node_cross ReadNode(QString path);

    tree_param now_tree;

    QList<QVariant> now_exec_data;

    static node_cross TreeToNode(node_cross info, QList<param_cross> p_l, QList<node_cross> n_l);

    static QString AddParamToTree(int tip, QList<param_cross> p_l, QList<node_cross> n_l, QString tree);

    static QString DelParamAsTree(QString last_tree);

    static QString AddJudgeToTree(int tip1, int tip2, QList<param_cross> p_l, QList<node_cross> n_l, QString tree);

    static param_cross ParamAsTree(QString tree, QList<param_cross> p_l, QList<data_cross> &d_l);

    static param_cross NodeAsTree(QString tree, QList<node_cross> n_l, QList<data_cross> &d_l);

    static QList<param_cross> JudgeAsTree(QString tree, QList<param_cross> p_l, QList<node_cross> n_l, QList<data_cross> &d_l);

    static int TigForTree(QString tree);

    static QString ParamToTree(param_cross p, QList<param_cross> p_l, QList<data_cross> d_l);

    static QString NodeToTree(param_cross p, QList<node_cross> n_l, QList<data_cross> d_l);

    static QString JudgeToTree(QList<param_cross> pl, QList<param_cross> p_l, QList<node_cross> n_l, QList<data_cross> d_l);

    static QString ListToTree(QList<QList<param_cross> > pl, QList<param_cross> p_l, QList<node_cross> n_l, QList<data_cross> d_l);

    static QString ChoParamData(QRect where, int tig, QString last_tree, QList<param_cross> p_l, QList<node_cross> n_l, QList<data_cross> d_l);
};

#endif // NSV_IMAGE_TREE_H
