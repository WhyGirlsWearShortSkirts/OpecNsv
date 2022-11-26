#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMoveEvent>
#include "param/nsv_include.h"
#include "param/nsv_global_param.h"
#include "param/nsv_image_tree.h"

#include "widget/nsv_tree.h"
#include "widget/ocr_more_view.h"
#include "widget/setting_ui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:

    void NSV_backtoshow(result_for_findC contour, cv::Mat image, QString imagepath, int tip);

    void NSV_stop();

    void CLU_stop();

    void EXPAN_stop();

    void REPLACE_stop(int num,QString ago,QString last);

    void EXPAN_backtoshow(cv::Mat image,QString imagepath,int tip);

    void RENAME_stop();

    void RENAME_backtoshow(cv::Mat image,QString imagepath,int tip);

    void ALINE_stop();

    void ALINE_backtoshow(cv::Mat image,QString imagepath,int tip);

    void Labels_clear();

    void NowLabels_clear();

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    bool save_image_data=false;

    nsv Nsv;

    config m_config;

    nsv_json_analy json;

    QString path_now="./";

    QFileInfoList imagelist;

    QList<expan_size> expan_list;

    bool expan_recolor=false;

    rename_size rename;

    QString replace_ago="";

    QString replace_after="";

    int tipforimage=0;

    float scale_size=1;

    bool is_tagging=false;

    int tag_type=0;

    int tag_from=0;

    cv::Mat image_now;//原图

    cv::Mat image_backup;//原图备份

    cv::Mat image_gray;//灰度图

    cv::Mat image_thresold;//二值化图

    cv::Mat image_thresold_backup;//二值化图备份

    cv::Scalar extract_color=cv::Scalar(255,255,255);

    result_for_stats object_image;

    result_for_findC contours_image;

    nsv_objects_image objects_now;

    int Key_press=0;

public slots:

    virtual void keyPressEvent(QKeyEvent *) override;

    void FindPointOnlyStats(cv::Mat image);

protected slots:

    QList<expan_size> expan();

    void image_show(QString imagepath, int tip);

    void image_show(cv::Mat image);

    void ocr_image_show(cv::Mat image,cv::Rect roi,QString label);

    void imagelist_get(QString path,int tip);

    cv::Mat image_get(QString imagepath);

    void roi_show(QPointF i1, QPointF i2);

    void roi_show(cv::Rect rect);

    void labels_show(QList<QString> list);

    void labels_clear();

    void Nsv_th(QFileInfoList imagelist, nsv Nsv);

    void Nsv_show(result_for_findC contour, cv::Mat image, QString imagepath, int tip);

    void Nsv_finish();

    void Clu_th();

    void Clu_finish();

    void Nsv_addobject();

    void Nsv_delete_object(QList<QPointF> pointlist);

    void Nsv_check(int key);

    void Expan_th();

    void Expan_stop();

    void Expan_show(cv::Mat image,QString imagepath,int tip);

    void Rename_th();

    void Rxpan_Aline_th(QFileInfoList imglist, QFileInfoList jsonlist);

    void ErDi_more();

    void Clane_more();

    void Color_more(QColor color,QPointF point);

    void Color_more();

    void Grad_more();

    void Morph_more();

    void Replace_th();

    void Replace_stop(int num, QString ago, QString after);

    void nowlabels_show(QList<QString> list);

    void nowlabels_clear();

    void sortlabel_show(QString label);

    void SortLabels_set();

    void ocr_json_save(QList<Item_save> pl,cv::Mat img,cv::Rect roi,QString label);

private slots:

    void on_pushButton_addiamge_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_left_clicked();

    void on_checkBox_split_clicked();

    void on_checkBox_roi_clicked();

    void on_horizontalSlider_thresholdsize_valueChanged(int value);

    void on_comboBox_split_currentTextChanged(const QString &arg1);

    void on_pushButton_maxroi_clicked();

    void on_pushButton_scale_narrow_clicked();

    void on_pushButton_scale_enlarge_clicked();

    void on_pushButton_scale_size_clicked();

    void on_checkBox_erode_clicked();

    void on_spinBox_erdi_size_valueChanged(int arg1);

    void on_checkBox_image_clustering_clicked();

    void on_spinBox_image_clustering_size_valueChanged(int arg1);

    void on_checkBox_alpha_beta_clicked();

    void on_doubleSpinBox_alpha_valueChanged(double arg1);

    void on_spinBox_beta_valueChanged(int arg1);

    void on_pushButton_stats_clicked();

    void on_spinBox_min_area_valueChanged(int arg1);

    void on_spinBox_max_area_valueChanged(int arg1);

    void on_graphicsView_scalechange(float arg1);

    void on_comboBox_poingtforcenter_currentIndexChanged(int index);

    void on_pushButton_save_json_clicked();

    void on_checkBox_reverse_color_clicked();

    void on_checkBox_thresold_tureornot_clicked();

    void on_pushButton_save_config_clicked();

    void on_horizontalSlider_thresholdsize_inv_valueChanged(int value);

    void on_pushButton_read_config_clicked();

    void on_pushButton_clicked();

    void on_spinBox_poingtforcentersize_valueChanged(int arg1);

    void on_lineEdit_objectname_textChanged(const QString &arg1);

    void on_checkBox_tigging_clicked();

    void on_pushButton_quote_clicked();

    void on_comboBox_tiggtype_currentIndexChanged(int index);

    void on_checkBox_other_limit_clicked();

    void on_checkBox_legth_clicked();

    void on_checkBox_width_clicked();

    void on_checkBox_cir_clicked();

    void on_checkBox_pyl_clicked();

    void on_checkBox_rectsize_clicked();

    void on_spinBox_min_legth_valueChanged(int arg1);

    void on_spinBox_max_legth_valueChanged(int arg1);

    void on_spinBox_min_width_valueChanged(int arg1);

    void on_spinBox_max_width_valueChanged(int arg1);

    void on_doubleSpinBox_min_pyl_valueChanged(double arg1);

    void on_doubleSpinBox_max_pyl_valueChanged(double arg1);

    void on_doubleSpinBox_min_cir_valueChanged(double arg1);

    void on_doubleSpinBox_max_cir_valueChanged(double arg1);

    void on_doubleSpinBox_min_rectsize_valueChanged(double arg1);

    void on_doubleSpinBox_max_rectsize_valueChanged(double arg1);

    void on_checkBox_expan_alpha_clicked();

    void on_checkBox_expan_beta_clicked();

    void on_doubleSpinBox_expan_min_alpha_valueChanged(double);

    void on_doubleSpinBox_expan_max_alpha_valueChanged(double);

    void on_doubleSpinBox_expan_single_alpha_valueChanged(double);

    void on_spinBox_expan_min_beta_valueChanged(int);

    void on_spinBox_expan_max_beta_valueChanged(int);

    void on_spinBox_expan_single_beta_valueChanged(int);

    void on_checkBox_expan_recolor_clicked();

    void on_checkBox_expan_scale_clicked();

    void on_doubleSpinBox_expan_min_scale_valueChanged(double);

    void on_doubleSpinBox_expan_single_scale_valueChanged(double);

    void on_doubleSpinBox_expan_max_scale_valueChanged(double);

    void on_pushButton_expan_start_clicked();

    void on_lineEdit_rename_name_textChanged(const QString &arg1);

    void on_comboBox_rename_type_currentIndexChanged(int index);

    void on_spinBox_rename_single_valueChanged(int arg1);

    void on_comboBox_rename_filetype_currentTextChanged(const QString &arg1);

    void on_pushButton_rename_clicked();

    void on_checkBox_hullnum_clicked();

    void on_spinBox_min_hullnum_valueChanged(int arg1);

    void on_spinBox_max_hullnum_valueChanged(int arg1);

    void on_pushButton_expan_aline_clicked();

    void on_pushButton_more_ErDi_clicked();

    void on_spinBox_ErDi_legth_valueChanged(int arg1);

    void on_spinBox_ErDi_width_valueChanged(int arg1);

    void on_pushButton_Clane_clicked();

    void on_doubleSpinBox_Clane_size_valueChanged(double arg1);

    void on_spinBox_CLane_tile_valueChanged(int arg1);

    void on_pushButton_Clane_last_clicked();

    void on_pushButton_stats_2_clicked();

    void on_pushButton_more_limit_clicked();

    void on_comboBox_Angle_type_currentIndexChanged(int index);

    void on_doubleSpinBox_Angle_com_valueChanged(double arg1);

    void on_checkBox_Angle_left_clicked();

    void on_pushButton_more_Color_clicked();

    void on_horizontalSlider_Color_r_valueChanged(int value);

    void on_horizontalSlider_Color_g_valueChanged(int value);

    void on_horizontalSlider_Color_b_valueChanged(int value);

    void on_pushButton_Color_extract_clicked();

    void on_pushButton_Color_scatter_clicked();

    void on_pushButton_Color_backup_clicked();

    void on_pushButton_nsv_single_clicked();

    void on_pushButton_nsv_single_2_clicked();

    void on_checkBox_Color_extract_clicked();

    void on_label_tipimage_clicked();

    void on_checkBox_ErDi_Enable_clicked();

    void on_checkBox_Clane_enable_clicked();

    void on_spinBox_tipimage_editingFinished();

    void on_pushButton_more_gradient_clicked();

    void on_pushButton_Grad_clicked();

    void on_comboBox_Grad_type_currentIndexChanged(int index);

    void on_spinBox_Grad_D_valueChanged(int arg1);

    void on_spinBox_Grad_thres_min_valueChanged(int arg1);

    void on_spinBox_Grad_thres_max_valueChanged(int arg1);

    void on_checkBox_Grad_colour_clicked(bool checked);

    void on_pushButton_more_morph_clicked();

    void on_spinBox_Morph_D_valueChanged(int arg1);

    void on_pushButton_showback_clicked();

    void on_pushButton_saveimage_clicked();

    void on_checkBox_Grad_clear_clicked();

    void on_spinBox_Grad_clear_D_valueChanged(int arg1);

    void on_checkBox_Grad_thres_clicked();

    void on_lineEdit_replace_ago_textChanged(const QString &arg1);

    void on_lineEdit_replace_after_textChanged(const QString &arg1);

    void on_pushButton_replace_clicked();

    void on_pushButton_clear_all_clicked();

    void on_comboBox_other_do_currentIndexChanged(int index);

    void on_pushButton_USE_TREE_clicked();

    void on_pushButton_sortlabels_clicked();

    void on_pushButton_tagging_now_type_clicked();

    void on_pushButton_tagging_type_open_clicked();

    void on_pushButton_tagging_from_open_clicked();

    void on_comboBox_tiggfrom_currentIndexChanged(int index);

    void on_pushButton_tagging_now_from_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    nsv_tree* tree = new nsv_tree();

    Ocr_More_View* ocr_widget = new Ocr_More_View();;

    setting_ui* setting = new setting_ui();

    CusButtonGroup* button_group = new CusButtonGroup(this);

    CusButtonGroup* button_group1 = new CusButtonGroup(this);

    CusButtonGroup* button_group2 = new CusButtonGroup(this);

    CusButtonGroup* button_group3 = new CusButtonGroup(this);

    CusButtonGroup* button_group4 = new CusButtonGroup(this);

    CusButtonGroup* button_group5 = new CusButtonGroup(this);

    CusButtonGroup* button_group6 = new CusButtonGroup(this);

    CusButtonGroup* button_group7 = new CusButtonGroup(this);

    CusButtonGroup* button_group8 = new CusButtonGroup(this);

    CusButtonGroup* button_group9 = new CusButtonGroup(this);

    CusButtonGroup* button_group10 = new CusButtonGroup(this);

    CusButtonGroup* button_group11 = new CusButtonGroup(this);

    CusButtonGroup* button_group12 = new CusButtonGroup(this);

    CusButtonGroup* button_group13 = new CusButtonGroup(this);

    CusButtonGroup* button_group14 = new CusButtonGroup(this);

    QPushButton *btn3 = new QPushButton;

    void init_CONFIG();

    void init_UI();

    void init_CONN();

    void init_analy(nsv nsv);

    void init_tagging_type();

    void init_nsv_type();

    void init_point_type();

    void init_file_type();

    void init_rename_type();

    void init_erdi_type();

    void init_erdido_type();

    void init_clane_type();

    void init_angle_type();

    void init_split_type();

    void init_gradient_type();

    void init_morphdo_type();

    void init_morph_type();

    void init_other_do();

    void init_tagging_from();

    void make_Easy();
};
#endif // MAINWINDOW_H
