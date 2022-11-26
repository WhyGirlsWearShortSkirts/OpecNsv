#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_UI();
    init_CONN();
    init_CONFIG();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//初始化软件配置

void MainWindow::init_CONFIG()
{
    m_config=json.json_read_config();

    if(m_config.imagelist_path!="")
    {
        imagelist_get(m_config.imagelist_path,m_config.tip);

        scale_size=m_config.scale;
        ui->pushButton_scale_size->setText(QString::number(scale_size*100,'f',0)+" %");
        ui->graphicsView->scene_scale(scale_size);
    }
}

void MainWindow::make_Easy()
{
    button_group1->setHidden(1);//禁用模式转换
//    button_group14->setHidden(1);//禁用标注类型转换
//    ui->pushButton_tagging_now_from->setEnabled(0);//禁用标注类型切换
    ui->pushButton_nsv_single_2->setHidden(1);//禁用预标注按钮
//    ui->pushButton_2->setHidden(1);//禁用设置按钮
}

//初始化UI界面

void MainWindow::init_UI()
{
    this->setWindowTitle("Opecnsv");
    this->setWindowIcon(QIcon("titg.ico"));
    this->setMouseTracking(1);//鼠标追踪

    ocr_widget->show();

    ocr_widget->close();

    init_tagging_type();

    init_nsv_type();

    init_point_type();

    init_file_type();

    init_rename_type();

    init_erdi_type();

    init_erdido_type();

    init_clane_type();

    init_angle_type();

    init_split_type();

    init_gradient_type();

    init_morphdo_type();

    init_morph_type();

    init_other_do();

    init_tagging_from();

    ui->groupBox_split->setHidden(1);

//    ui->pushButton_USE_TREE->setHidden(1);

    ui->pushButton_save_json->setHidden(1);

    ui->tabWidget->tabBar()->hide();//隐藏tab

    ui->tabWidget->setCurrentIndex(0);

    ui->tabWidget_other_do->tabBar()->hide();//隐藏tab

    ui->tabWidget_other_do->setCurrentIndex(0);

    ui->groupBox_other->setHidden(1);

    ui->pushButton_left->setEnabled(0);

    ui->pushButton_right->setEnabled(0);

    ui->groupBox_sort_label->setHidden(1);

    ui->groupBox_nowlabels->setHidden(0);

    ui->groupBox_tagging_type->setHidden(1);

    ui->groupBox_tagging_type->setEnabled(false);

    ui->groupBox_tagging_from->setHidden(1);

    ui->groupBox_tagging_from->setEnabled(false);

    ui->pushButton_scale_narrow->setEnabled(0);

    ui->pushButton_scale_enlarge->setEnabled(0);

    ui->pushButton_scale_size->setEnabled(0);

    ui->groupBox_initNSV->setEnabled(false);

    ui->pushButton_more_ErDi->setHidden(1);

    ui->pushButton_Clane->setHidden(1);

    ui->pushButton_more_morph->setHidden(1);

    ui->pushButton_more_limit->setHidden(1);

    ui->pushButton_more_Color->setHidden(1);

    ui->spinBox_Grad_clear_D->setHidden(1);

    ui->label_53->setHidden(1);

    ui->checkBox_Grad_colour_add->setEnabled(0);

    ui->label_rename_show->setText(rename.name+"_0."+rename.filetype);

    ui->comboBox_split->setHidden(1);

    ui->groupBox_thresholdsize_inv->setHidden(1);

    ui->spinBox_erdi_size->setHidden(1);

    ui->spinBox_image_clustering_size->setHidden(1);

    ui->doubleSpinBox_alpha->setHidden(1);

    ui->spinBox_beta->setHidden(1);

    ui->spinBox_poingtforcentersize->setHidden(1);

    ui->pushButton_maxroi->setHidden(1);

    ui->label_roi_x->setHidden(1);
    ui->label_roi_y->setHidden(1);
    ui->label_roi_w->setHidden(1);
    ui->label_roi_h->setHidden(1);

    ui->label->setText(QString::number(100,10));
    ui->label_7->setText(QString::number(200,10));

    ui->spinBox_tipimage->setHidden(true);
    ui->spinBox_tipimage->setEnabled(false);

    ui->groupBox_rename->setEnabled(false);
    ui->groupBox_expan->setEnabled(false);
    ui->groupBox_replace->setEnabled(false);
    button_group13->setEnabled(false);

    make_Easy();
}

void MainWindow::init_tagging_type()
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

void MainWindow::init_tagging_from()
{
    //设置下划线颜色
    button_group14->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group14->setLineHeight(4);
    //设置下划线位置
    button_group14->setButtonPosition(CusButtonGroup::West);

    QPushButton *btn = new QPushButton;
    btn->setCheckable(true);
    btn->setText("目标检测");
    btn->setFixedSize(260,25);
    button_group14->addButton(btn,0);

    QPushButton *btn1 = new QPushButton;
    btn1->setCheckable(true);
    btn1->setText("OCR标注");
    btn1->setFixedSize(260,25);
    button_group14->addButton(btn1,1);

    QPushButton *btn2 = new QPushButton;
    btn2->setCheckable(true);
    btn2->setText("图像分类");
    btn2->setFixedSize(260,25);
    button_group14->addButton(btn2,2);

    button_group14->onbuttonClicked(0);

    ui->verticalLayout_tagg_from->addWidget(button_group14);
    ui->comboBox_tiggfrom->setHidden(1);
}

void MainWindow::init_nsv_type()
{
    //设置下划线颜色
    button_group1->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group1->setLineHeight(4);
    //设置下划线位置
    button_group1->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn2 = new QPushButton;
    btn2->setCheckable(true);
    btn2->setText("手动标注");
    btn2->setFixedSize(88,25);
    button_group1->addButton(btn2,0);

    btn3->setCheckable(true);
    btn3->setText("预标注");
    btn3->setFixedSize(88,25);
    button_group1->addButton(btn3,1);
    button_group1->onbuttonClicked(0);

    QPushButton *btn20 = new QPushButton;
    btn20->setCheckable(true);
    btn20->setText("数据集");
    btn20->setFixedSize(90,25);
    button_group1->addButton(btn20,2);

    ui->horizontalLayout_NSV->addWidget(button_group1);
    btn3->setEnabled(false);
}

void MainWindow::init_point_type()
{
    //设置下划线颜色
    button_group2->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group2->setLineHeight(4);
    //设置下划线位置
    button_group2->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn7 = new QPushButton;
    btn7->setCheckable(true);
    btn7->setText("外接矩");
    btn7->setFixedSize(66,25);
    button_group2->addButton(btn7,0);

    QPushButton *btn4 = new QPushButton;
    btn4->setCheckable(true);
    btn4->setText("最少点");
    btn4->setFixedSize(66,25);
    button_group2->addButton(btn4,1);

    QPushButton *btn5 = new QPushButton;
    btn5->setCheckable(true);
    btn5->setText("无缺陷");
    btn5->setFixedSize(66,25);
    button_group2->addButton(btn5,2);

    QPushButton *btn6 = new QPushButton;
    btn6->setCheckable(true);
    btn6->setText("正矩形");
    btn6->setFixedSize(66,25);
    button_group2->addButton(btn6,3);

    button_group2->onbuttonClicked(0);

    ui->horizontalLayout_miaoshu->addWidget(button_group2);
    ui->comboBox_poingtforcenter->setHidden(1);
}

void MainWindow::init_file_type()
{
    //设置下划线颜色
    button_group3->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group3->setLineHeight(4);
    //设置下划线位置
    button_group3->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn8 = new QPushButton;
    btn8->setCheckable(true);
    btn8->setText("bmp");
    btn8->setFixedSize(80,25);
    button_group3->addButton(btn8,0);

    QPushButton *btn9 = new QPushButton;
    btn9->setCheckable(true);
    btn9->setText("jpg");
    btn9->setFixedSize(80,25);
    button_group3->addButton(btn9,1);

    QPushButton *btn10 = new QPushButton;
    btn10->setCheckable(true);
    btn10->setText("png");
    btn10->setFixedSize(80,25);
    button_group3->addButton(btn10,2);

    button_group3->onbuttonClicked(0);

    ui->horizontalLayout_rename_filetype->addWidget(button_group3);
    ui->comboBox_rename_filetype->setHidden(1);
}

void MainWindow::init_rename_type()
{
    //设置下划线颜色
    button_group4->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group4->setLineHeight(4);
    //设置下划线位置
    button_group4->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn11 = new QPushButton;
    btn11->setCheckable(true);
    btn11->setText("跳帧");
    btn11->setFixedSize(80,25);
    button_group4->addButton(btn11,0);

    QPushButton *btn12 = new QPushButton;
    btn12->setCheckable(true);
    btn12->setText("规范抽帧");
    btn12->setFixedSize(80,25);
    button_group4->addButton(btn12,1);

    QPushButton *btn13 = new QPushButton;
    btn13->setCheckable(true);
    btn13->setText("随机抽帧");
    btn13->setFixedSize(80,25);
    button_group4->addButton(btn13,2);

    button_group4->onbuttonClicked(0);

    ui->horizontalLayout_rename_type->addWidget(button_group4);
    ui->comboBox_rename_type->setHidden(1);
}

void MainWindow::init_erdi_type()
{
    //设置下划线颜色
    button_group5->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group5->setLineHeight(4);
    //设置下划线位置
    button_group5->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn14 = new QPushButton;
    btn14->setCheckable(true);
    btn14->setText("矩形");
    btn14->setFixedSize(88,25);
    button_group5->addButton(btn14,0);

    QPushButton *btn15 = new QPushButton;
    btn15->setCheckable(true);
    btn15->setText("星形");
    btn15->setFixedSize(88,25);
    button_group5->addButton(btn15,1);

    QPushButton *btn16 = new QPushButton;
    btn16->setCheckable(true);
    btn16->setText("椭圆");
    btn16->setFixedSize(90,25);
    button_group5->addButton(btn16,2);

    button_group5->onbuttonClicked(0);

    ui->horizontalLayout_ErDi_type->addWidget(button_group5);
    ui->comboBox_ErDi_type->setHidden(1);
}

void MainWindow::init_erdido_type()
{
    //设置下划线颜色
    button_group6->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group6->setLineHeight(4);
    //设置下划线位置
    button_group6->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn17 = new QPushButton;
    btn17->setCheckable(true);
    btn17->setText("腐蚀");
    btn17->setFixedSize(66,25);
    button_group6->addButton(btn17,0);

    QPushButton *btn18 = new QPushButton;
    btn18->setCheckable(true);
    btn18->setText("膨胀");
    btn18->setFixedSize(66,25);
    button_group6->addButton(btn18,1);

    QPushButton *btn19 = new QPushButton;
    btn19->setCheckable(true);
    btn19->setText("开操作");
    btn19->setFixedSize(66,25);
    button_group6->addButton(btn19,2);

    QPushButton *btn21 = new QPushButton;
    btn21->setCheckable(true);
    btn21->setText("闭操作");
    btn21->setFixedSize(66,25);
    button_group6->addButton(btn21,3);

    button_group6->onbuttonClicked(0);

    ui->horizontalLayout_ErDi_do->addWidget(button_group6);
    ui->comboBox_ErDi_do->setHidden(1);
}

void MainWindow::init_clane_type()
{
    //设置下划线颜色
    button_group7->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group7->setLineHeight(4);
    //设置下划线位置
    button_group7->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn22 = new QPushButton;
    btn22->setCheckable(true);
    btn22->setText("有限");
    btn22->setFixedSize(134,25);
    button_group7->addButton(btn22,0);

    QPushButton *btn23 = new QPushButton;
    btn23->setCheckable(true);
    btn23->setText("全局");
    btn23->setFixedSize(134,25);
    button_group7->addButton(btn23,1);

    button_group7->onbuttonClicked(0);

    ui->horizontalLayout_Clane->addWidget(button_group7);
    ui->comboBox_Clane->setHidden(1);
}

void MainWindow::init_angle_type()
{
    //设置下划线颜色
    button_group8->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group8->setLineHeight(4);
    //设置下划线位置
    button_group8->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn24 = new QPushButton;
    btn24->setCheckable(true);
    btn24->setText("长边");
    btn24->setFixedSize(52,25);
    button_group8->addButton(btn24,0);

    QPushButton *btn25 = new QPushButton;
    btn25->setCheckable(true);
    btn25->setText("缺陷");
    btn25->setFixedSize(52,25);
    button_group8->addButton(btn25,1);

    QPushButton *btn26 = new QPushButton;
    btn26->setCheckable(true);
    btn26->setText("特征");
    btn26->setFixedSize(52,25);
    button_group8->addButton(btn26,2);

    QPushButton *btn27 = new QPushButton;
    btn27->setCheckable(true);
    btn27->setText("重心");
    btn27->setFixedSize(52,25);
    button_group8->addButton(btn27,3);

    QPushButton *btn28 = new QPushButton;
    btn28->setCheckable(true);
    btn28->setText("复杂");
    btn28->setFixedSize(54,25);
    button_group8->addButton(btn28,4);

    button_group8->onbuttonClicked(0);

    ui->horizontalLayout_Angle_type->addWidget(button_group8);
    ui->comboBox_Angle_type->setHidden(1);
}

void MainWindow::init_split_type()
{
    //设置下划线颜色
    button_group9->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group9->setLineHeight(4);
    //设置下划线位置
    button_group9->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn1 = new QPushButton;
    btn1->setCheckable(true);
    btn1->setText("红色");
    btn1->setFixedSize(88,25);
    button_group9->addButton(btn1,0);

    QPushButton *btn2 = new QPushButton;
    btn2->setCheckable(true);
    btn2->setText("绿色");
    btn2->setFixedSize(88,25);
    button_group9->addButton(btn2,1);

    QPushButton *btn3 = new QPushButton;
    btn3->setCheckable(true);
    btn3->setText("蓝色");
    btn3->setFixedSize(90,25);
    button_group9->addButton(btn3,2);

    button_group9->onbuttonClicked(0);

    ui->horizontalLayout_split->addWidget(button_group9);
    ui->comboBox_split->setHidden(1);
}

void MainWindow::init_gradient_type()
{
    //设置下划线颜色
    button_group10->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group10->setLineHeight(4);
    //设置下划线位置
    button_group10->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn1 = new QPushButton;
    btn1->setCheckable(true);
    btn1->setText("Sobel");
    btn1->setFixedSize(88,25);
    button_group10->addButton(btn1,0);

    QPushButton *btn2 = new QPushButton;
    btn2->setCheckable(true);
    btn2->setText("Scharr");
    btn2->setFixedSize(88,25);
    button_group10->addButton(btn2,1);

    QPushButton *btn3 = new QPushButton;
    btn3->setCheckable(true);
    btn3->setText("Laplacion");
    btn3->setFixedSize(90,25);
    button_group10->addButton(btn3,2);

    button_group10->onbuttonClicked(0);

    ui->horizontalLayout_Grad_type->addWidget(button_group10);
    ui->comboBox_Grad_type->setHidden(1);
}

void MainWindow::init_morphdo_type()
{
    //设置下划线颜色
    button_group11->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group11->setLineHeight(4);
    //设置下划线位置
    button_group11->setButtonPosition(CusButtonGroup::West);

    QPushButton *btn1 = new QPushButton;
    btn1->setCheckable(true);
    btn1->setText("腐蚀");
    btn1->setFixedSize(270,25);
    button_group11->addButton(btn1,0);

    QPushButton *btn2 = new QPushButton;
    btn2->setCheckable(true);
    btn2->setText("膨胀");
    btn2->setFixedSize(270,25);
    button_group11->addButton(btn2,1);

    QPushButton *btn3 = new QPushButton;
    btn3->setCheckable(true);
    btn3->setText("开操作");
    btn3->setFixedSize(270,25);
    button_group11->addButton(btn3,2);

    QPushButton *btn4 = new QPushButton;
    btn4->setCheckable(true);
    btn4->setText("闭操作");
    btn4->setFixedSize(270,25);
    button_group11->addButton(btn4,3);

    QPushButton *btn5 = new QPushButton;
    btn5->setCheckable(true);
    btn5->setText("形态学梯度");
    btn5->setFixedSize(270,25);
    button_group11->addButton(btn5,4);

    QPushButton *btn6 = new QPushButton;
    btn6->setCheckable(true);
    btn6->setText("顶帽");
    btn6->setFixedSize(270,25);
    button_group11->addButton(btn6,5);

    QPushButton *btn7 = new QPushButton;
    btn7->setCheckable(true);
    btn7->setText("黑帽");
    btn7->setFixedSize(270,25);
    button_group11->addButton(btn7,6);

    QPushButton *btn8 = new QPushButton;
    btn8->setCheckable(true);
    btn8->setText("击中击不中");
    btn8->setFixedSize(270,25);
    button_group11->addButton(btn8,7);

    button_group11->onbuttonClicked(0);

    ui->horizontalLayout_Morph_do->addWidget(button_group11);
    ui->comboBox_Morph_do->setHidden(1);
}

void MainWindow::init_morph_type()
{
    //设置下划线颜色
    button_group12->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group12->setLineHeight(4);
    //设置下划线位置
    button_group12->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn1 = new QPushButton;
    btn1->setCheckable(true);
    btn1->setText("矩形");
    btn1->setFixedSize(88,25);
    button_group12->addButton(btn1,0);

    QPushButton *btn2 = new QPushButton;
    btn2->setCheckable(true);
    btn2->setText("星形");
    btn2->setFixedSize(88,25);
    button_group12->addButton(btn2,1);

    QPushButton *btn3 = new QPushButton;
    btn3->setCheckable(true);
    btn3->setText("椭圆");
    btn3->setFixedSize(90,25);
    button_group12->addButton(btn3,2);

    button_group12->onbuttonClicked(0);

    ui->horizontalLayout_Morph_type->addWidget(button_group12);
    ui->comboBox_Morph_type->setHidden(1);
}

void MainWindow::init_other_do()
{
    //设置下划线颜色
    button_group13->setButtonColor(QColor(255, 163, 69));
    //设置下划线高度
    button_group13->setLineHeight(4);
    //设置下划线位置
    button_group13->setButtonPosition(CusButtonGroup::South);

    QPushButton *btn1 = new QPushButton;
    btn1->setCheckable(true);
    btn1->setText("扩充");
    btn1->setFixedSize(88,25);
    button_group13->addButton(btn1,0);

    QPushButton *btn2 = new QPushButton;
    btn2->setCheckable(true);
    btn2->setText("规整");
    btn2->setFixedSize(88,25);
    button_group13->addButton(btn2,1);

    QPushButton *btn3 = new QPushButton;
    btn3->setCheckable(true);
    btn3->setText("标签替换");
    btn3->setFixedSize(90,25);
    button_group13->addButton(btn3,2);

    button_group13->onbuttonClicked(0);

    ui->horizontalLayout_other_do->addWidget(button_group13);
    ui->comboBox_other_do->setHidden(1);
}

//导入配置

void MainWindow::init_analy(nsv nsv)
{
    ui->lineEdit_objectname->setText(nsv.objectname);

    ui->groupBox_initNSV->setEnabled(false);

    ui->doubleSpinBox_alpha->setValue(nsv.image_alpha);

    ui->spinBox_beta->setValue(nsv.image_beta);

    ui->checkBox_alpha_beta->setChecked(nsv.image_alpha_beta_enable);

    on_checkBox_alpha_beta_clicked();

    ui->spinBox_image_clustering_size->setValue(nsv.image_clur);

    ui->checkBox_image_clustering->setChecked(nsv.image_clur_enable);

    on_checkBox_image_clustering_clicked();

    ui->horizontalSlider_thresholdsize_inv->setValue(nsv.image_thresold_inv);

    ui->horizontalSlider_thresholdsize->setValue(nsv.image_thresold);

    if(nsv.image_split_type!=0)
    {
        ui->checkBox_split->setChecked(true);
        ui->comboBox_split->setCurrentIndex(nsv.image_split_type-1);
    }
    else
    {
        ui->checkBox_split->setChecked(false);
    }

    on_checkBox_split_clicked();

    ui->checkBox_thresold_tureornot->setChecked(nsv.image_thresold_inv_enable);

    on_checkBox_thresold_tureornot_clicked();

    ui->checkBox_reverse_color->setChecked(nsv.image_re_color);

    on_checkBox_reverse_color_clicked();

    ui->checkBox_roi->setChecked(nsv.image_roi_enable);

    on_checkBox_roi_clicked();

    roi_show(nsv.rect_cut);

    ui->checkBox_roi->setChecked(false);

    on_checkBox_roi_clicked();

    ui->spinBox_erdi_size->setValue(nsv.image_erdi);

    ui->checkBox_erode->setChecked(nsv.image_erdi_enable);

    on_checkBox_erode_clicked();

    ui->spinBox_min_area->setValue(nsv.min_size);

    ui->spinBox_max_area->setValue(nsv.max_size);

    ui->comboBox_poingtforcenter->setCurrentIndex(nsv.contours_type);

    ui->spinBox_poingtforcentersize->setValue(nsv.contours_size);

    ui->checkBox_other_limit->setChecked(nsv.other_enable);

    on_checkBox_other_limit_clicked();

    ui->checkBox_legth->setChecked(nsv.legth_enable);

    ui->checkBox_width->setChecked(nsv.width_enable);

    ui->checkBox_cir->setChecked(nsv.cir_enable);

    ui->checkBox_pyl->setChecked(nsv.pyl_enable);

    ui->checkBox_rectsize->setChecked(nsv.rectsize_enable);

    ui->checkBox_hullnum->setChecked(nsv.hullnum_enable);

    ui->spinBox_min_hullnum->setValue(nsv.min_hullnum);

    ui->spinBox_max_hullnum->setValue(nsv.max_hullnum);

    ui->spinBox_min_legth->setValue(nsv.min_legth);

    ui->spinBox_max_legth->setValue(nsv.max_legth);

    ui->spinBox_min_width->setValue(nsv.min_width);

    ui->spinBox_max_width->setValue(nsv.max_width);

    ui->doubleSpinBox_min_cir->setValue(nsv.min_cir);

    ui->doubleSpinBox_max_cir->setValue(nsv.max_cir);

    ui->doubleSpinBox_min_pyl->setValue(nsv.min_pyl);

    ui->doubleSpinBox_max_pyl->setValue(nsv.max_pyl);

    ui->doubleSpinBox_min_rectsize->setValue(nsv.min_rectsize);

    ui->doubleSpinBox_max_rectsize->setValue(nsv.max_rectsize);

    ui->groupBox_initNSV->setEnabled(true);
}

//初始化信号槽

void MainWindow::init_CONN()
{
    connect(this,SIGNAL(NSV_backtoshow(result_for_findC,cv::Mat,QString,int)),this,SLOT(Nsv_show(result_for_findC,cv::Mat,QString,int)));
    connect(this,SIGNAL(NSV_stop()),this,SLOT(Nsv_finish()));
    connect(this,SIGNAL(CLU_stop()),this,SLOT(Clu_finish()));
    connect(this,SIGNAL(EXPAN_backtoshow(cv::Mat,QString,int)),this,SLOT(Expan_show(cv::Mat,QString,int)));
    connect(this,SIGNAL(EXPAN_stop()),this,SLOT(Expan_stop()));
    connect(this,SIGNAL(REPLACE_stop(int,QString,QString)),this,SLOT(Replace_stop(int,QString,QString)));
    connect(this,SIGNAL(RENAME_backtoshow(cv::Mat,QString,int)),this,SLOT(Expan_show(cv::Mat,QString,int)));
    connect(this,SIGNAL(RENAME_stop()),this,SLOT(Expan_stop()));
    connect(this,SIGNAL(ALINE_stop()),this,SLOT(Expan_stop()));
    connect(this,SIGNAL(ALINE_backtoshow(cv::Mat,QString,int)),this,SLOT(Expan_show(cv::Mat,QString,int)));
    connect(this,SIGNAL(Labels_clear()),this,SLOT(labels_clear()));
    connect(this,SIGNAL(NowLabels_clear()),this,SLOT(nowlabels_clear()));

//    connect(tree,SIGNAL(TreeRunFinish(cv::Mat)),this,SLOT(FindPointOnlyStats(cv::Mat)));

    connect(ui->graphicsView,SIGNAL(labels_change(QList<QString>)),this,SLOT(labels_show(QList<QString>)));
    connect(ui->graphicsView,SIGNAL(nowlabelschange(QList<QString>)),this,SLOT(nowlabels_show(QList<QString>)));
    connect(ui->graphicsView,SIGNAL(sortlabelchange(QString)),this,SLOT(sortlabel_show(QString)));
    connect(ui->graphicsView,SIGNAL(returnbackroi(QPointF,QPointF)),this,SLOT(roi_show(QPointF,QPointF)));
    connect(ui->graphicsView,SIGNAL(key_event(QKeyEvent *)),this,SLOT(keyPressEvent(QKeyEvent *)));
    connect(ui->graphicsView,SIGNAL(color_back(QColor,QPointF)),this,SLOT(Color_more(QColor,QPointF)));
    connect(ui->graphicsView,SIGNAL(ocr_show(cv::Mat,cv::Rect,QString)),this,SLOT(ocr_image_show(cv::Mat,cv::Rect,QString)));

    connect(button_group,SIGNAL(choose_buttons(int)),ui->comboBox_tiggtype,SLOT(setCurrentIndex(int)));
    connect(button_group1,SIGNAL(choose_buttons(int)),this,SLOT(Nsv_check(int)));
    connect(button_group2,SIGNAL(choose_buttons(int)),ui->comboBox_poingtforcenter,SLOT(setCurrentIndex(int)));
    connect(button_group3,SIGNAL(choose_buttons(int)),ui->comboBox_rename_filetype,SLOT(setCurrentIndex(int)));
    connect(button_group4,SIGNAL(choose_buttons(int)),ui->comboBox_rename_type,SLOT(setCurrentIndex(int)));
    connect(button_group5,SIGNAL(choose_buttons(int)),ui->comboBox_ErDi_type,SLOT(setCurrentIndex(int)));
    connect(button_group6,SIGNAL(choose_buttons(int)),ui->comboBox_ErDi_do,SLOT(setCurrentIndex(int)));
    connect(button_group5,SIGNAL(choose_buttons(int)),this,SLOT(ErDi_more()));
    connect(button_group6,SIGNAL(choose_buttons(int)),this,SLOT(ErDi_more()));
    connect(button_group7,SIGNAL(choose_buttons(int)),ui->comboBox_Clane,SLOT(setCurrentIndex(int)));
    connect(button_group7,SIGNAL(choose_buttons(int)),this,SLOT(Clane_more()));
    connect(button_group8,SIGNAL(choose_buttons(int)),ui->comboBox_Angle_type,SLOT(setCurrentIndex(int)));
    connect(button_group9,SIGNAL(choose_buttons(int)),ui->comboBox_split,SLOT(setCurrentIndex(int)));
    connect(button_group10,SIGNAL(choose_buttons(int)),ui->comboBox_Grad_type,SLOT(setCurrentIndex(int)));
    connect(button_group11,SIGNAL(choose_buttons(int)),ui->comboBox_Morph_do,SLOT(setCurrentIndex(int)));
    connect(button_group12,SIGNAL(choose_buttons(int)),ui->comboBox_Morph_type,SLOT(setCurrentIndex(int)));
    connect(button_group11,SIGNAL(choose_buttons(int)),this,SLOT(Morph_more()));
    connect(button_group12,SIGNAL(choose_buttons(int)),this,SLOT(Morph_more()));
    connect(button_group13,SIGNAL(choose_buttons(int)),ui->comboBox_other_do,SLOT(setCurrentIndex(int)));
    connect(button_group14,SIGNAL(choose_buttons(int)),ui->comboBox_tiggfrom,SLOT(setCurrentIndex(int)));
}

void MainWindow::Nsv_check(int key)
{
    ui->checkBox_roi->setChecked(false);
    if(key==0)
    {
        ui->tabWidget->setCurrentIndex(0);
        ui->graphicsView->showornot(false);
    }
    else if(key==1)
    {
        ui->tabWidget->setCurrentIndex(1);
        ui->graphicsView->showornot(true);
    }
    else if(key==2)
    {
        ui->tabWidget->setCurrentIndex(2);
    }
}

//标注标签显示

void MainWindow::labels_show(QList<QString> list)
{
    labels_clear();

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
        nlabelchoosepushbutton *p = new nlabelchoosepushbutton(this,list[i],text,ui->graphicsView->color_list[i]);
        ui->verticalLayout_labels_show->addWidget(p);
    }
}

void MainWindow::labels_clear()
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

void MainWindow::nowlabels_clear()
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

void MainWindow::nowlabels_show(QList<QString> list)
{
    nowlabels_clear();

    for(int i=0;i<list.size();i++)
    {
        QString text ="";
        nlabelchoosepushbutton *p = new nlabelchoosepushbutton(this,list[i],text,QColor(200,100,69));
        ui->verticalLayout_labels_now->addWidget(p);
    }
}

void MainWindow::sortlabel_show(QString label)
{
    ui->pushButton_sortlabels->setText(label);
}

//快捷键

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_A:
        if(imagelist.size()>0)
        {
            on_pushButton_left_clicked();
        }
        break;

    case Qt::Key_D:
        if(imagelist.size()>0)
        {
            on_pushButton_right_clicked();
        }
        break;

    case Qt::Key_S:
        if(ui->tabWidget->currentIndex()==0)
        {
            if(ui->checkBox_tigging->isChecked())
            {
                ui->checkBox_tigging->setChecked(false);
            }
            else
            {
                ui->checkBox_tigging->setChecked(true);
            }
            on_checkBox_tigging_clicked();
        }
        break;

    case Qt::Key_O:
        if(imagelist.size()>0 && !image_now.empty())
        {
            on_pushButton_stats_clicked();
        }
        break;

    case Qt::Key_P:
        if(imagelist.size()>0 && !image_backup.empty())
        {
            image_show(image_backup);
        }
        break;

    case Qt::Key_W:
        if(!is_tagging  && tag_from!=2)
        {
            if(tag_type<ui->comboBox_tiggtype->count()-1)
            {
                tag_type+=1;
                ui->comboBox_tiggtype->setCurrentIndex(tag_type);
            }
            else
            {
                tag_type=0;
                ui->comboBox_tiggtype->setCurrentIndex(tag_type);
            }

        }
        break;

    case Qt::Key_F:
        on_pushButton_quote_clicked();
        break;

    case Qt::Key_R:
        on_pushButton_clear_all_clicked();
        break;
    }
}

//感兴趣区域显示

void MainWindow::roi_show(QPointF i1,QPointF i2)
{
    ui->label_roi_x->setText("x:"+QString::number(int(min(i1.x(),i2.x())),10));
    ui->label_roi_y->setText("y:"+QString::number(int(min(i1.y(),i2.y())),10));
    ui->label_roi_w->setText("w:"+QString::number(int(abs(i1.x()-i2.x())),10));
    ui->label_roi_h->setText("h:"+QString::number(int(abs(i1.y()-i2.y())),10));
    Nsv.rect_cut=cv::Rect(int(min(i1.x(),i2.x())),int(min(i1.y(),i2.y())),int(abs(i1.x()-i2.x())),int(abs(i1.y()-i2.y())));
}

void MainWindow::roi_show(cv::Rect rect)
{
    if(rect!=cv::Rect(0,0,0,0))
    {
        ui->label_roi_x->setText("x:"+QString::number(int(rect.x),10));
        ui->label_roi_y->setText("y:"+QString::number(int(rect.y),10));
        ui->label_roi_w->setText("w:"+QString::number(int(rect.width),10));
        ui->label_roi_h->setText("h:"+QString::number(int(rect.height),10));

        image_thresold=image_thresold_backup.clone();
        image_thresold=image_Rect(image_thresold,rect);
        image_show(image_thresold);
        ui->graphicsView->roi_BeMax(rect);
    }
    else
    {
        image_thresold=image_thresold_backup.clone();
        image_show(image_thresold);
    }
}

//图像获取

void MainWindow::on_pushButton_addiamge_clicked()
{
    QString ns=QFileDialog::getExistingDirectory(this,"图像文件路径","./");
    imagelist_get(ns,0);
    m_config.imagelist_path=ns;
    m_config.scale=scale_size;
    json.json_create_config(m_config);
}

void MainWindow::imagelist_get(QString path,int tip)
{
    imagelist=GetFileList(path);
    path_now=path;
    if(!imagelist.empty())
    {
        ui->pushButton_left->setEnabled(1);
        ui->pushButton_right->setEnabled(1);
        ui->pushButton_scale_narrow->setEnabled(1);
        ui->pushButton_scale_enlarge->setEnabled(1);
        ui->pushButton_scale_size->setEnabled(1);
        ui->groupBox_initNSV->setEnabled(1);
        ui->groupBox_rename->setEnabled(1);
        ui->groupBox_expan->setEnabled(1);
        ui->groupBox_replace->setEnabled(1);
        button_group13->setEnabled(1);
        ui->graphicsView->object_clear();
        btn3->setEnabled(1);
        if(tip<imagelist.size())
        {
            tipforimage=tip;
            image_show(imagelist[tip].filePath(),tip);
        }
        else
        {
            tipforimage=0;
            image_show(imagelist[0].filePath(),0);
        }
    }
}

cv::Mat MainWindow::image_get(QString imagepath)
{
    cv::Mat image=cv::imread(imagepath.toLocal8Bit().toStdString());
    return image;
}

void MainWindow::on_pushButton_saveimage_clicked()
{
    cv::Mat image_out=ui->graphicsView->getimage();
    if(!image_out.empty())
    {
        QString ns=QFileDialog::getSaveFileName(this,"save image path",path_now,"(*.bmp)");

        qDebug()<<ns;
        if(ns!="")
        {
            cv::imwrite(ns.toLocal8Bit().toStdString(),image_out);
        }
    }
}

//图片及标注文件组切换

void MainWindow::image_show(QString imagepath,int tip)
{
    m_config.tip=tip;
    json.json_create_config(m_config);
    ui->graphicsView->object_clear();
    image_now=image_get(imagepath);
    image_backup=image_now.clone();
    tree->setNowImage(image_now);
    image_gray=cv::Mat();
    image_thresold=cv::Mat();
    image_thresold_backup=cv::Mat();
    scale_size=ui->graphicsView->image_add(image_now);
    ui->pushButton_saveimage->setText("文件名称:"+imagepath);
    ui->label_image_size->setText("宽("+QString::number(image_now.cols)+"),高("+QString::number(image_now.rows)+")");
    ui->label_tipimage->setText(QString::number(tip,10)+"/"+QString::number(imagelist.size()-1,10));
    ui->pushButton_scale_size->setText(QString::number(scale_size*100,'f',0)+" %");

    QList<QString> listI=json.imagename_getfrompath(imagepath);
    QString name=listI[3]+listI[1]+".json";

    nsv_objects_image objects_read=json.json_read_nsv(name);
    if(objects_read.flags_use)
    {
        ui->pushButton_saveimage->setStyleSheet("color:rgb(0,120,0);background-color: rgba(255, 255, 255,0);font: 10pt '宋体';");
        objects_now=objects_read;
        for(int i=0;i<objects_now.objects.size();i++)
        {
            if(objects_now.objects[i].shape_type=="polygon")
            {
                ui->graphicsView->object_add_pointlist(QList<QList<QPointF>>{objects_now.objects[i].points},QList<QString>{objects_now.objects[i].lables},QList<double>{objects_now.objects[i].angle},0,0);
            }
            else if(objects_now.objects[i].shape_type=="rectangle")
            {
                ui->graphicsView->object_add_pointlist(QList<QList<QPointF>>{objects_now.objects[i].points},QList<QString>{objects_now.objects[i].lables},QList<double>{objects_now.objects[i].angle},1,0);
            }
            else if(objects_now.objects[i].shape_type=="sort")
            {
                ui->graphicsView->object_add_pointlist(QList<QList<QPointF>>{},QList<QString>{objects_now.objects[i].lables},QList<double>{objects_now.objects[i].angle},0,2);
            }
            else if(objects_now.objects[i].shape_type=="charline")
            {
                ui->graphicsView->object_add_pointlist(QList<QList<QPointF>>{objects_now.objects[i].points},QList<QString>{objects_now.objects[i].lables},QList<double>{objects_now.objects[i].angle},0,1);
            }
        }
        objects_now.objects=QList<nsv_object>();
    }
    else
    {
        ui->pushButton_saveimage->setStyleSheet("color:rgb(120,0,0);background-color: rgba(255, 255, 255,0);font: 10pt '宋体';");
        objects_now.path=imagepath;
        objects_now.path_json=listI[3]+listI[1]+".json";
        objects_now.version="4.6.0";
        objects_now.image=image_now;
        objects_now.image_width=image_now.cols;
        objects_now.image_height=image_now.rows;
        objects_now.objects=QList<nsv_object>();
        if(save_image_data)
        {
            objects_now.image_data=QByteArray::fromStdString(Mat2Base64(image_now,listI[2].toStdString()));
        }
        else
        {
            objects_now.image_data="";
        }
        objects_now.image_file=listI[0];
    }
    if(button_group1->m_curIndex==1)
    {
        ui->graphicsView->showornot(false);
        ui->graphicsView->showornot(true);
    }
}

void MainWindow::image_show(cv::Mat image)
{
    scale_size=ui->graphicsView->image_add(image);
    ui->pushButton_scale_size->setText(QString::number(scale_size*100,'f',0)+" %");
}

void MainWindow::on_pushButton_right_clicked()
{
    tipforimage++;
    if(tipforimage<imagelist.size() && tipforimage>=0)
    {
        SortLabels_set();
        Nsv_addobject();
        json.json_create_nsv(objects_now);
        ui->graphicsView->object_clear();
        image_show(imagelist[tipforimage].filePath(),tipforimage);
    }
    else
    {
        if(tipforimage>=imagelist.size())
        {
            tipforimage=0;
        }
        if(tipforimage<0)
        {
            tipforimage=imagelist.size()-1;
        }
        SortLabels_set();
        Nsv_addobject();
        json.json_create_nsv(objects_now);
        ui->graphicsView->object_clear();
        image_show(imagelist[tipforimage].filePath(),tipforimage);
    }
}

void MainWindow::on_pushButton_left_clicked()
{
    tipforimage=tipforimage-1;
    if(tipforimage<imagelist.size() && tipforimage>=0)
    {
        SortLabels_set();
        Nsv_addobject();
        json.json_create_nsv(objects_now);
        ui->graphicsView->object_clear();
        image_show(imagelist[tipforimage].filePath(),tipforimage);
    }
    else
    {
        if(tipforimage>=imagelist.size())
        {
            tipforimage=0;
        }
        if(tipforimage<0)
        {
            tipforimage=imagelist.size()-1;
        }
        SortLabels_set();
        Nsv_addobject();
        json.json_create_nsv(objects_now);
        ui->graphicsView->object_clear();
        image_show(imagelist[tipforimage].filePath(),tipforimage);
    }
}

void MainWindow::on_label_tipimage_clicked()
{
    ui->label_tipimage->setHidden(true);
    ui->spinBox_tipimage->setEnabled(true);
    ui->spinBox_tipimage->setValue(0);
    ui->spinBox_tipimage->setHidden(false);
}

void MainWindow::on_spinBox_tipimage_editingFinished()
{
    ui->spinBox_tipimage->setEnabled(false);
    if(ui->spinBox_tipimage->value()<imagelist.size())
    {
        SortLabels_set();
        Nsv_addobject();
        json.json_create_nsv(objects_now);
        ui->graphicsView->object_clear();
        tipforimage=ui->spinBox_tipimage->value();
        image_show(imagelist[ui->spinBox_tipimage->value()].filePath(),tipforimage);
    }
    ui->spinBox_tipimage->setHidden(true);
    ui->label_tipimage->setHidden(false);
    ui->spinBox_tipimage->setEnabled(false);
}

//OCR标注显示

void MainWindow::ocr_image_show(cv::Mat image,cv::Rect roi,QString label)
{
    try
    {
        this->setEnabled(false);
        ui->checkBox_tigging->setChecked(false);
        ui->graphicsView->showornot(true);
        ocr_widget->addimage(image);
        ocr_widget->exec();
        QList<Item_save> pl=ocr_widget->back_itemlist();
        ocr_json_save(pl,image,roi,label);
        ui->graphicsView->showornot(false);
        ui->checkBox_tigging->setChecked(true);
        this->setEnabled(true);
    }
    catch (...)
    {
        qDebug()<<"OCR标注显示！";
    }
}

void MainWindow::ocr_json_save(QList<Item_save> pl,cv::Mat img,cv::Rect roi,QString label)
{
    QDir dir;
    QList<QString> listI=json.imagename_getfrompath(imagelist[tipforimage].filePath());
    if (!dir.exists(listI[3]+"/ocr"))
    {
        dir.mkpath(listI[3]+"/ocr");
    }
    if(pl.size()>0)
    {
        QString path=listI[3]+"ocr/"+listI[1]+"_"+QString::number(roi.x)+"_"+QString::number(roi.y)+"_"+QString::number(roi.width)+"_"+QString::number(roi.height);
        nsv_objects_image objects_image;
        cv::Mat image=img.clone();
        cv::imwrite((path+"."+listI[2]).toUtf8().toStdString(),image);
        objects_image.path=path+"."+listI[2];
        objects_image.path_json=path+".json";
        objects_image.version="4.6.0";
        objects_image.image=image;
        objects_image.image_width=image.cols;
        objects_image.image_height=image.rows;
        if(save_image_data)
        {
            objects_image.image_data=QByteArray::fromStdString(Mat2Base64(image,listI[2].toStdString()));
        }
        else
        {
            objects_image.image_data="";
        }
        objects_image.image_file=listI[1]+"_"+QString::number(roi.x)+"_"+QString::number(roi.y)+"_"+QString::number(roi.width)+"_"+QString::number(roi.height)+"."+listI[2];
        for(int i=0;i<pl.size();i++)
        {
            nsv_object object;
            if(pl[i].labels.size()>0)
            {
                object.lables=pl[i].labels[0];
            }
            else
            {
                object.lables="";
            }
            if(pl[i].pointlist.size()>0)
            {
                object.points=pl[i].pointlist[0];
            }
            else
            {
                object.points=QList<QPointF>{};
            }
            if(pl[i].angle.size()>0)
            {
                object.angle=pl[i].angle[0];
            }
            else
            {
                object.angle=0;
            }
            if(pl[i].type==1)
            {
                object.shape_type="rectangle";
            }
            else
            {
                object.shape_type="polygon";
            }
            objects_image.objects.append(object);
        }
        nsv_object sort;
        sort.lables=label;
        sort.shape_type="sort";
        objects_image.objects.append(sort);

        json.json_create_nsv(objects_image);
    }
}

//画面缩放

void MainWindow::on_pushButton_scale_narrow_clicked()
{
    if(scale_size>=0.25)
    {
        scale_size=scale_size-0.01;
        ui->pushButton_scale_size->setText(QString::number(scale_size*100,'f',0)+"%");
        ui->graphicsView->scene_scale(scale_size);
    }
}

void MainWindow::on_pushButton_scale_enlarge_clicked()
{
    if(scale_size<=4)
    {
        scale_size=scale_size+0.01;
        ui->pushButton_scale_size->setText(QString::number(scale_size*100,'f',0)+" %");
        ui->graphicsView->scene_scale(scale_size);
    }
}

void MainWindow::on_pushButton_scale_size_clicked()
{
    scale_size=1;
    ui->pushButton_scale_size->setText(QString::number(scale_size*100,'f',0)+" %");
    ui->graphicsView->scene_scale(scale_size);
}

void MainWindow::on_graphicsView_scalechange(float arg1)
{
    scale_size=arg1;
    ui->pushButton_scale_size->setText(QString::number(scale_size*100,'f',0)+" %");
}

//预标注配置

void MainWindow::on_checkBox_split_clicked()
{
    if(ui->checkBox_split->isChecked())
    {
        ui->groupBox_split->setHidden(0);
        ui->pushButton_more_Color->setHidden(0);
        Nsv.image_split_type=1+ui->comboBox_split->currentIndex();
    }
    else
    {
        ui->groupBox_split->setHidden(1);
        ui->pushButton_more_Color->setHidden(1);
        Nsv.image_split_type=0;
    }
    Nsv.color_extract=ui->checkBox_Color_extract->isChecked();
    if(Nsv.color_extract)
    {
        image_gray=image_diff_color_gray(image_now,extract_color,30);
    }
    else
    {
        image_gray=image_Gray(image_now,Nsv.image_split_type);
    }
    image_show(image_gray);
}

void MainWindow::on_checkBox_roi_clicked()
{
    if(ui->checkBox_roi->isChecked())
    {
        Nsv.image_roi_enable=true;
        if(image_thresold.empty())
        {
            on_horizontalSlider_thresholdsize_valueChanged(ui->horizontalSlider_thresholdsize->value());
            image_show(image_thresold);
        }
        else
        {
            image_thresold=image_thresold_backup.clone();
            image_show(image_thresold);
        }
        ui->graphicsView->roi_PaintEnable(true);
        ui->pushButton_maxroi->setHidden(0);
        ui->label_roi_x->setHidden(0);
        ui->label_roi_y->setHidden(0);
        ui->label_roi_w->setHidden(0);
        ui->label_roi_h->setHidden(0);
        ui->graphicsView->roi_BeMax(Nsv.rect_cut);
    }
    else
    {
        if(Nsv.rect_cut==cv::Rect(0,0,image_now.cols,image_now.rows))
        {
            Nsv.image_roi_enable=false;
            image_thresold=image_thresold_backup.clone();
            image_show(image_thresold);
        }
        if(ui->label_roi_w->text()=="w:max")
        {
            Nsv.rect_cut=cv::Rect(0,0,image_now.cols,image_now.rows);
            ui->graphicsView->roi_BeMax(Nsv.rect_cut);
        }
        roi_show(Nsv.rect_cut);
        ui->graphicsView->roi_PaintEnable(false);
        ui->pushButton_maxroi->setHidden(1);
        ui->label_roi_x->setHidden(1);
        ui->label_roi_y->setHidden(1);
        ui->label_roi_w->setHidden(1);
        ui->label_roi_h->setHidden(1);
    }
}

void MainWindow::on_horizontalSlider_thresholdsize_valueChanged(int value)
{
    ui->label->setText(QString::number(value,10));
    Nsv.image_thresold=value;
    Nsv.image_thresold_inv=ui->horizontalSlider_thresholdsize_inv->value();
    Nsv.image_thresold_inv_enable=ui->checkBox_thresold_tureornot->isChecked();
    Nsv.image_re_color=ui->checkBox_reverse_color->isChecked();
    on_checkBox_split_clicked();
    image_thresold=image_Thresold(image_gray,Nsv.image_thresold_inv_enable,Nsv.image_thresold,Nsv.image_thresold_inv);
    if(Nsv.image_re_color)
    {
        cv::bitwise_not(image_thresold,image_thresold);
    }
    image_thresold_backup=image_thresold.clone();
    image_show(image_thresold);
}

void MainWindow::on_spinBox_min_area_valueChanged(int arg1)
{
    Nsv.min_size=min(arg1,ui->spinBox_max_area->value());
}

void MainWindow::on_spinBox_max_area_valueChanged(int arg1)
{
    Nsv.max_size=max(arg1,ui->spinBox_min_area->value());
}

void MainWindow::on_pushButton_stats_clicked()
{
    this->setEnabled(false);
    Nsv.contours_type=ui->comboBox_poingtforcenter->currentIndex();
    Nsv.contours_size=ui->spinBox_poingtforcentersize->value();
    Nsv.min_size=ui->spinBox_min_area->value();
    Nsv.max_size=ui->spinBox_max_area->value();
    image_now=image_backup;
    contours_image=image_FindPointstoStats(image_now,Nsv,ui->checkBox_info_show->isChecked());
    image_show(contours_image.image_out);
//    tree->RunTree(image_now);
    this->setEnabled(true);
}

void MainWindow::FindPointOnlyStats(cv::Mat image)
{
    contours_image=image_FindPointsOnlyStats(image,image_now,Nsv,ui->checkBox_info_show->isChecked());
    image_show(contours_image.image_out);
}

void MainWindow::on_comboBox_split_currentTextChanged(const QString &)
{
    button_group9->onbuttonClicked(ui->comboBox_split->currentIndex());
    on_checkBox_split_clicked();
}

void MainWindow::on_pushButton_maxroi_clicked()
{
    ui->graphicsView->roi_BeMax();
}

void MainWindow::on_checkBox_erode_clicked()
{
    if(ui->checkBox_erode->isChecked())
    {
        Nsv.image_erdi_enable=true;
        ui->spinBox_erdi_size->setHidden(0);
        ui->pushButton_more_ErDi->setHidden(0);
        ui->pushButton_more_morph->setHidden(0);
        if(image_thresold.empty())
        {
            on_horizontalSlider_thresholdsize_valueChanged(ui->horizontalSlider_thresholdsize->value());
        }
        Nsv.image_erdi=ui->spinBox_erdi_size->value();
        if(Nsv.image_erdi!=0)
        {
            image_thresold=image_thresold_backup.clone();
            image_thresold=image_ErDi(image_thresold,Nsv.image_erdi);
        }
        image_show(image_thresold);
    }
    else
    {
        Nsv.image_erdi_enable=false;
        Nsv.image_erdi=0;
        image_thresold=image_thresold_backup.clone();
        image_show(image_thresold);
        ui->spinBox_erdi_size->setHidden(1);
        ui->pushButton_more_ErDi->setHidden(1);
        ui->pushButton_more_morph->setHidden(1);
    }
}

void MainWindow::on_spinBox_erdi_size_valueChanged(int arg1)
{
    if(ui->checkBox_erode->isChecked())
    {
        if(image_thresold.empty())
        {
            on_horizontalSlider_thresholdsize_valueChanged(ui->horizontalSlider_thresholdsize->value());
        }
        Nsv.image_erdi=arg1;
        if(Nsv.image_erdi!=0)
        {
            image_thresold=image_thresold_backup.clone();
            image_thresold=image_ErDi(image_thresold,Nsv.image_erdi);
        }
        image_show(image_thresold);
    }
}

void MainWindow::on_checkBox_image_clustering_clicked()
{
    if(ui->checkBox_image_clustering->isChecked())
    {
        Nsv.image_clur_enable=true;
        ui->spinBox_image_clustering_size->setHidden(0);
        Nsv.image_clur=ui->spinBox_image_clustering_size->value();
        image_now=image_backup.clone();
        this->setEnabled(false);
//        Clu_th();
        QFuture<void> f2 = QtConcurrent::run(this,&MainWindow::Clu_th);
    }
    else
    {
        Nsv.image_clur_enable=false;
        image_now=image_backup.clone();
        image_show(image_now);
        ui->spinBox_image_clustering_size->setHidden(1);
    }
}

void MainWindow::on_spinBox_image_clustering_size_valueChanged(int arg1)
{
    if(ui->checkBox_image_clustering->isChecked())
    {
        Nsv.image_clur=arg1;
        image_now=image_backup.clone();
        this->setEnabled(false);
        QFuture<void> f2 = QtConcurrent::run(this,&MainWindow::Clu_th);
    }
}

void MainWindow::on_checkBox_alpha_beta_clicked()
{
    if(ui->checkBox_alpha_beta->isChecked())
    {
        Nsv.image_alpha_beta_enable=true;
        ui->doubleSpinBox_alpha->setHidden(0);
        ui->spinBox_beta->setHidden(0);
        Nsv.image_alpha=ui->doubleSpinBox_alpha->value();
        Nsv.image_beta=ui->spinBox_beta->value();
        ui->pushButton_Clane->setHidden(0);
        image_now=image_backup.clone();
        image_now=image_AlphaBeta(image_now,Nsv.image_alpha,Nsv.image_beta);
        image_show(image_now);
    }
    else
    {
        Nsv.image_alpha_beta_enable=false;
        ui->pushButton_Clane->setHidden(1);
        ui->doubleSpinBox_alpha->setHidden(1);
        ui->spinBox_beta->setHidden(1);
        image_now=image_backup.clone();
        image_show(image_now);
    }
}

void MainWindow::on_doubleSpinBox_alpha_valueChanged(double arg1)
{
    if(ui->checkBox_alpha_beta->isChecked())
    {
        Nsv.image_alpha=arg1;
        Nsv.image_beta=ui->spinBox_beta->value();
        image_now=image_backup.clone();
        image_now=image_AlphaBeta(image_now,Nsv.image_alpha,Nsv.image_beta);
        image_show(image_now);
    }
}

void MainWindow::on_spinBox_beta_valueChanged(int arg1)
{
    if(ui->checkBox_alpha_beta->isChecked())
    {
        Nsv.image_alpha=ui->doubleSpinBox_alpha->value();
        Nsv.image_beta=arg1;
        image_now=image_backup.clone();
        image_now=image_AlphaBeta(image_now,Nsv.image_alpha,Nsv.image_beta);
        image_show(image_now);
    }
}

void MainWindow::on_comboBox_poingtforcenter_currentIndexChanged(int index)
{
    button_group2->onbuttonClicked(index);
    if(index==1)
    {
        ui->spinBox_poingtforcentersize->setHidden(0);
    }
    else if(index==2)
    {
        ui->spinBox_poingtforcentersize->setHidden(0);
    }
    else
    {
        ui->spinBox_poingtforcentersize->setHidden(1);
    }
    Nsv.contours_type=index;
}

void MainWindow::on_spinBox_poingtforcentersize_valueChanged(int arg1)
{
    Nsv.contours_size=arg1;
}

void MainWindow::on_checkBox_reverse_color_clicked()
{
    if(ui->checkBox_reverse_color->isChecked())
    {
        Nsv.image_re_color=true;
    }
    else
    {
        Nsv.image_re_color=false;
    }
    on_horizontalSlider_thresholdsize_valueChanged(ui->horizontalSlider_thresholdsize->value());
}

void MainWindow::on_checkBox_thresold_tureornot_clicked()
{
    if(ui->checkBox_thresold_tureornot->isChecked())
    {
        ui->groupBox_thresholdsize_inv->setHidden(0);
        Nsv.image_thresold_inv=ui->horizontalSlider_thresholdsize_inv->value();
        Nsv.image_thresold=ui->horizontalSlider_thresholdsize->value();
        Nsv.image_thresold_inv_enable=true;
    }
    else
    {
        ui->groupBox_thresholdsize_inv->setHidden(1);
        Nsv.image_thresold_inv=ui->horizontalSlider_thresholdsize_inv->value();
        Nsv.image_thresold=ui->horizontalSlider_thresholdsize->value();
        Nsv.image_thresold_inv_enable=false;
    }
    on_horizontalSlider_thresholdsize_valueChanged(ui->horizontalSlider_thresholdsize->value());
}

void MainWindow::on_horizontalSlider_thresholdsize_inv_valueChanged(int)
{
    Nsv.image_thresold_inv=ui->horizontalSlider_thresholdsize_inv->value();
    ui->label_7->setText(QString::number(ui->horizontalSlider_thresholdsize_inv->value(),10));
    on_horizontalSlider_thresholdsize_valueChanged(ui->horizontalSlider_thresholdsize->value());
}

void MainWindow::on_lineEdit_objectname_textChanged(const QString &arg1)
{
    Nsv.objectname=arg1;
}

//读写预标注配置

void MainWindow::on_pushButton_save_config_clicked()
{
    nsv Nsv_save;
    Nsv_save.objectname=ui->lineEdit_objectname->text();
    Nsv_save.image_beta=ui->spinBox_beta->value();
    Nsv_save.image_clur=ui->spinBox_image_clustering_size->value();
    Nsv_save.image_erdi=ui->spinBox_erdi_size->value();
    Nsv_save.image_alpha=ui->doubleSpinBox_alpha->value();
    Nsv_save.image_re_color=ui->checkBox_reverse_color->checkState();
    Nsv_save.image_thresold=ui->horizontalSlider_thresholdsize->value();
    Nsv_save.image_roi_enable=Nsv.image_roi_enable;
    if(ui->checkBox_split->isChecked())
    {
        Nsv_save.image_split_type=ui->comboBox_split->currentIndex()+1;
    }
    else
    {
        Nsv_save.image_split_type=0;
    }
    Nsv_save.image_clur_enable=ui->checkBox_image_clustering->checkState();
    Nsv_save.image_erdi_enable=ui->checkBox_erode->checkState();
    Nsv_save.image_thresold_inv=ui->horizontalSlider_thresholdsize_inv->value();
    Nsv_save.image_alpha_beta_enable=ui->checkBox_alpha_beta->checkState();
    Nsv_save.image_thresold_inv_enable=ui->checkBox_thresold_tureornot->checkState();
    Nsv_save.min_size=ui->spinBox_min_area->value();
    Nsv_save.max_size=ui->spinBox_max_area->value();
    Nsv_save.rect_cut=Nsv.rect_cut;
    Nsv_save.contours_size=ui->spinBox_poingtforcentersize->value();
    Nsv_save.contours_type=ui->comboBox_poingtforcenter->currentIndex();
    Nsv_save.other_enable=ui->checkBox_other_limit->checkState();
    Nsv_save.legth_enable=ui->checkBox_legth->checkState();
    Nsv_save.width_enable=ui->checkBox_width->checkState();
    Nsv_save.cir_enable=ui->checkBox_cir->checkState();
    Nsv_save.pyl_enable=ui->checkBox_pyl->checkState();
    Nsv_save.rectsize_enable=ui->checkBox_rectsize->checkState();
    Nsv_save.min_legth=ui->spinBox_min_legth->value();
    Nsv_save.max_legth=ui->spinBox_max_legth->value();
    Nsv_save.min_width=ui->spinBox_min_width->value();
    Nsv_save.max_width=ui->spinBox_max_width->value();
    Nsv_save.min_cir=ui->doubleSpinBox_min_cir->value();
    Nsv_save.max_cir=ui->doubleSpinBox_max_cir->value();
    Nsv_save.min_pyl=ui->doubleSpinBox_min_pyl->value();
    Nsv_save.max_pyl=ui->doubleSpinBox_max_pyl->value();
    Nsv_save.min_rectsize=ui->doubleSpinBox_min_rectsize->value();
    Nsv_save.max_rectsize=ui->doubleSpinBox_max_rectsize->value();
    json.json_create_analy(Nsv_save);
}

void MainWindow::on_pushButton_read_config_clicked()
{
    nsv Nsv_read=json.json_read_analy();
    if(Nsv_read.flags_use==true)
    {
        Nsv=Nsv_read;
        init_analy(Nsv_read);
        Nsv=Nsv_read;
    }
}

void MainWindow::on_pushButton_save_json_clicked()
{
    QList<QList<QPointF>> jj;
    QList<QPointF> j1{QPointF(10,10),QPointF(10,200),QPointF(200,200),QPointF(200,10)};
    QList<QPointF> j2{QPointF(20,20),QPointF(20,50),QPointF(50,50),QPointF(50,20)};
    QList<QPointF> j3{QPointF(20,60),QPointF(60,60),QPointF(60,100),QPointF(20,100)};

    jj.append(j1);
    jj.append(j2);
    jj.append(j3);

    QList<QString> js{"assd","1","2"};

    ui->graphicsView->object_add_pointlist(jj,js,QList<double>{0},0,1);
}

//启用标注模式

void MainWindow::on_checkBox_tigging_clicked()
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
            on_comboBox_tiggfrom_currentIndexChanged(ui->comboBox_tiggfrom->currentIndex());

            button_group1->setEnabled(false);

            button_group14->setEnabled(false);
            ui->comboBox_tiggfrom->setEnabled(false);
            ui->pushButton_tagging_now_from->setEnabled(false);

            ui->comboBox_tiggtype->setEnabled(false);
            button_group->setEnabled(false);
            ui->pushButton_tagging_now_type->setEnabled(false);

            ui->graphicsView->object_add_pointlist(true,tag_type,tag_from);
            is_tagging=true;
        }
        else
        {
            button_group1->setEnabled(true);

            button_group14->setEnabled(true);
            ui->comboBox_tiggfrom->setEnabled(true);
            ui->pushButton_tagging_now_from->setEnabled(true);

            if(tag_from!=2)
            {
                ui->pushButton_tagging_now_type->setEnabled(true);
                ui->comboBox_tiggtype->setEnabled(true);
                button_group->setEnabled(true);
            }

            ui->graphicsView->object_add_pointlist(false,tag_type,tag_from);
            is_tagging=false;
        }
    }
}

//设置标注类型

void MainWindow::on_comboBox_tiggtype_currentIndexChanged(int index)
{
    tag_type=index;
    ui->pushButton_tagging_now_type->setText(ui->comboBox_tiggtype->currentText());
    ui->groupBox_tagging_type->setHidden(1);
    ui->groupBox_tagging_type->setEnabled(false);
    ui->pushButton_tagging_now_type->setHidden(0);
}

void MainWindow::on_pushButton_tagging_now_type_clicked()
{
    ui->groupBox_tagging_type->setHidden(0);
    ui->pushButton_tagging_now_type->setHidden(1);
    ui->groupBox_tagging_type->setEnabled(true);
}

void MainWindow::on_pushButton_tagging_type_open_clicked()
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

void MainWindow::on_comboBox_tiggfrom_currentIndexChanged(int index)
{
    tag_from=index;
    ui->pushButton_tagging_now_from->setText(ui->comboBox_tiggfrom->currentText());
    ui->groupBox_tagging_from->setHidden(1);
    ui->groupBox_tagging_from->setEnabled(false);
    ui->pushButton_tagging_now_from->setHidden(0);

    if(tag_from==2)
    {
        ui->pushButton_tagging_type_open->setEnabled(false);
        ui->pushButton_tagging_now_type->setEnabled(false);
        button_group->setEnabled(false);

        ui->pushButton_tagging_now_type->setText("- - -");
        ui->groupBox_tagging_type->setHidden(1);
        ui->groupBox_tagging_type->setEnabled(false);
        ui->pushButton_tagging_now_type->setHidden(0);

        ui->groupBox_sort_label->setHidden(0);
        ui->groupBox_nowlabels->setHidden(1);
    }
    else
    {
        ui->pushButton_tagging_type_open->setEnabled(true);
        ui->pushButton_tagging_now_type->setEnabled(true);
        button_group->setEnabled(true);

        ui->pushButton_tagging_now_type->setText(ui->comboBox_tiggtype->currentText());
        ui->groupBox_tagging_type->setHidden(1);
        ui->groupBox_tagging_type->setEnabled(false);
        ui->pushButton_tagging_now_type->setHidden(0);

        ui->groupBox_sort_label->setHidden(1);
        ui->groupBox_nowlabels->setHidden(0);
    }
}

void MainWindow::on_pushButton_tagging_now_from_clicked()
{
    ui->groupBox_tagging_from->setHidden(0);
    ui->pushButton_tagging_now_from->setHidden(1);
    ui->groupBox_tagging_from->setEnabled(true);
}

void MainWindow::on_pushButton_tagging_from_open_clicked()
{
    if(ui->groupBox_tagging_from->isEnabled())
    {
        on_comboBox_tiggfrom_currentIndexChanged(tag_from);
        ui->pushButton_tagging_from_open->setText("标注类型：◣ ");
    }
    else
    {
        on_pushButton_tagging_now_from_clicked();
        ui->pushButton_tagging_from_open->setText("标注类型：◢ ");
    }
}

//引用上一帧标注情况

void MainWindow::on_pushButton_quote_clicked()
{
    if(tipforimage<imagelist.size() && tipforimage>0 && tag_from==0)
    {
        ui->graphicsView->object_clear();
        QString imagepath=imagelist[tipforimage-1].filePath();

        QList<QString> listI=json.imagename_getfrompath(imagepath);
        QString name=listI[3]+listI[1]+".json";

        nsv_objects_image objects_read=json.json_read_nsv(name);

        if(objects_read.flags_use)
        {
            for(int i=0;i<objects_read.objects.size();i++)
            {
                if(objects_read.objects[i].shape_type=="polygon")
                {
                    ui->graphicsView->object_add_pointlist(QList<QList<QPointF>>{objects_read.objects[i].points},QList<QString>{objects_read.objects[i].lables},QList<double>{objects_read.objects[i].angle},0,0);
                }
                else if(objects_read.objects[i].shape_type=="rectangle")
                {
                    ui->graphicsView->object_add_pointlist(QList<QList<QPointF>>{objects_read.objects[i].points},QList<QString>{objects_read.objects[i].lables},QList<double>{objects_read.objects[i].angle},1,0);
                }
            }
        }
    }
}

//清空所有标注

void MainWindow::on_pushButton_clear_all_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("该操作将清空所有标注区域，且无法撤回，是否清空？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if(ret==QMessageBox::Yes)
    {
        ui->graphicsView->object_clear();
    }
}

//修改图像分类标签

void MainWindow::SortLabels_set()
{
    if(tag_from==2 && is_tagging)
    {
        bool haveSort=false;
        for(int i=0;i<ui->graphicsView->ploygon_list.size();i++)
        {
            if(ui->graphicsView->ploygon_list[i]->type()==QGraphicsItem::UserType+10)
            {
                NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ui->graphicsView->ploygon_list[i]);
                if(item_b->getType()==NGraphicsItem::ItemType::Sort)
                {
                    haveSort=true;
                    break;
                }
            }
        }

        if(!haveSort)
        {
            ui->graphicsView->scene.ui_labels->exec();

            QString label=ui->graphicsView->scene.ui_labels->now_label;

            if(label!="")
            {
                ui->graphicsView->object_add_pointlist(QList<QList<QPointF>>{},QList<QString>{label},QList<double>{0},5,2);
            }
        }
    }
}

void MainWindow::on_pushButton_sortlabels_clicked()
{
    if(tag_from==2 && is_tagging)
    {
        ui->graphicsView->scene.ui_labels->exec();

        QString label=ui->graphicsView->scene.ui_labels->now_label;

        if(label!="")
        {
            ui->graphicsView->reset_sortlabel(label);
        }
    }
}

//更多限制

void MainWindow::on_checkBox_other_limit_clicked()
{
    if(ui->checkBox_other_limit->isChecked())
    {
        ui->groupBox_other->setHidden(0);
        ui->pushButton_more_limit->setHidden(0);
        Nsv.other_enable=true;
    }
    else
    {
        Nsv.other_enable=false;
        ui->pushButton_more_limit->setHidden(1);
        ui->groupBox_other->setHidden(1);
        ui->checkBox_pyl->setChecked(0);
        ui->checkBox_legth->setChecked(0);
        ui->checkBox_width->setChecked(0);
        ui->checkBox_cir->setChecked(0);
        ui->checkBox_rectsize->setChecked(0);
    }
}

void MainWindow::on_checkBox_legth_clicked()
{
    if(ui->checkBox_legth->isChecked())
    {
        Nsv.legth_enable=true;
    }
    else
    {
        Nsv.legth_enable=false;
    }
}

void MainWindow::on_checkBox_width_clicked()
{
    if(ui->checkBox_width->isChecked())
    {
        Nsv.width_enable=true;
    }
    else
    {
        Nsv.width_enable=false;
    }
}

void MainWindow::on_checkBox_cir_clicked()
{
    if(ui->checkBox_cir->isChecked())
    {
        Nsv.cir_enable=true;
    }
    else
    {
        Nsv.cir_enable=false;
    }
}

void MainWindow::on_checkBox_pyl_clicked()
{
    if(ui->checkBox_pyl->isChecked())
    {
        Nsv.pyl_enable=true;
    }
    else
    {
        Nsv.pyl_enable=false;
    }
}

void MainWindow::on_checkBox_rectsize_clicked()
{
    if(ui->checkBox_rectsize->isChecked())
    {
        Nsv.rectsize_enable=true;
    }
    else
    {
        Nsv.rectsize_enable=false;
    }
}

void MainWindow::on_checkBox_hullnum_clicked()
{
    if(ui->checkBox_hullnum->isChecked())
    {
        Nsv.hullnum_enable=true;
    }
    else
    {
        Nsv.hullnum_enable=false;
    }
}

void MainWindow::on_spinBox_min_hullnum_valueChanged(int arg1)
{
    Nsv.min_hullnum=arg1;
}

void MainWindow::on_spinBox_max_hullnum_valueChanged(int arg1)
{
    Nsv.max_hullnum=arg1;
}

void MainWindow::on_spinBox_min_legth_valueChanged(int arg1)
{
    Nsv.min_legth=arg1;
}

void MainWindow::on_spinBox_max_legth_valueChanged(int arg1)
{
    Nsv.max_legth=arg1;
}

void MainWindow::on_spinBox_min_width_valueChanged(int arg1)
{
    Nsv.min_width=arg1;
}

void MainWindow::on_spinBox_max_width_valueChanged(int arg1)
{
    Nsv.max_width=arg1;
}

void MainWindow::on_doubleSpinBox_min_pyl_valueChanged(double arg1)
{
    Nsv.min_pyl=arg1;
}

void MainWindow::on_doubleSpinBox_max_pyl_valueChanged(double arg1)
{
    Nsv.max_pyl=arg1;
}

void MainWindow::on_doubleSpinBox_min_cir_valueChanged(double arg1)
{
    Nsv.min_cir=arg1;
}

void MainWindow::on_doubleSpinBox_max_cir_valueChanged(double arg1)
{
    Nsv.max_cir=arg1;
}

void MainWindow::on_doubleSpinBox_min_rectsize_valueChanged(double arg1)
{
    Nsv.min_rectsize=arg1;
}

void MainWindow::on_doubleSpinBox_max_rectsize_valueChanged(double arg1)
{
    Nsv.max_rectsize=arg1;
}

//更多限制（界面）

void MainWindow::on_pushButton_stats_2_clicked()
{
    on_pushButton_stats_clicked();
}

void MainWindow::on_pushButton_more_limit_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}

//颜色量化

void MainWindow::Clu_finish()
{
    image_show(image_now);
    this->setEnabled(true);
}

void MainWindow::Clu_th()
{
    image_now=image_Cluster(image_now,Nsv.image_clur);
    emit CLU_stop();
}

//预标注

void MainWindow::on_pushButton_clicked()
{
    Nsv.contours_type=ui->comboBox_poingtforcenter->currentIndex();
    Nsv.contours_size=ui->spinBox_poingtforcentersize->value();
    Nsv.min_size=ui->spinBox_min_area->value();
    Nsv.max_size=ui->spinBox_max_area->value();
    Nsv.objectname=ui->lineEdit_objectname->text();
    this->setEnabled(false);
    ui->graphicsView->object_clear();
    QMessageBox msgBox;
    msgBox.setText("图像预标注即使用传统视觉方法，对能够简单区分的物料进行边缘标注，标注时若存在json文件，则在原有文件上进行操作，若不存在json文件，则会创建json文件。\n"
                   "\n--即使图像未识别到物体，预标注也会创建对应json文件。\n"
                   "\n--预标注中如选择正矩形标注，则标注类型注名为rectangle，其他则注名为polygon，已有文件中若存在其他注名，请不要使用预标注。\n"
                   "\n--预标注中无法判断识别区域是否与已存在标注区域重叠，请不要连续两次使用相近的参数进行预标注，预标注后请检查标注集。\n"
                   "\n--预标注中对图像操作不会覆盖至原图像文件，预标注中请不要操作当前文件夹。\n");
    msgBox.setInformativeText("是否开始预标注?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if(ret==QMessageBox::Yes)
    {
        QFuture<void> f1 = QtConcurrent::run(this,&MainWindow::Nsv_th,imagelist,Nsv);
    }
    else
    {
        this->setEnabled(true);
        ui->graphicsView->object_clear();
        tipforimage=0;
        image_show(imagelist[0].filePath(),0);
    }
}

void MainWindow::on_pushButton_nsv_single_clicked()
{
    Nsv.contours_type=ui->comboBox_poingtforcenter->currentIndex();
    Nsv.contours_size=ui->spinBox_poingtforcentersize->value();
    Nsv.min_size=ui->spinBox_min_area->value();
    Nsv.max_size=ui->spinBox_max_area->value();
    Nsv.objectname=ui->lineEdit_objectname->text();
    this->setEnabled(false);

    if(imagelist.size()>0 && tag_type==0)
    {
        if(Nsv.objectname=="")
        {
            QMessageBox msgBox;
            msgBox.setText("当前没有预标注标签，是否使用前次标注标签作为预标注标签？");
            msgBox.setInformativeText("前次标注标签为："+ui->graphicsView->scene.ui_labels->now_label);
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();
            if(ret == QMessageBox::Yes)
            {
                if(ui->graphicsView->scene.ui_labels->now_label=="")
                {
                    QMessageBox msgBox;
                    msgBox.setText("前次标注标签也为空，放弃标注。");
                    msgBox.setStandardButtons(QMessageBox::Close);
                    msgBox.setDefaultButton(QMessageBox::Close);
                    int ret = msgBox.exec();
                    if(ret == QMessageBox::Close)
                    {
                        this->setEnabled(true);
                    }
                }
                else
                {
                    QList<QString> listI=json.imagename_getfrompath(imagelist[tipforimage].filePath());
                    QString name=listI[3]+listI[1]+".json";
                    nsv_objects_image objects_image;
                    nsv_objects_image objects_read=json.json_read_nsv(name);
                    if(objects_read.flags_use)
                    {
                        objects_image=objects_read;
                    }
                    cv::Mat image=image_get(imagelist[tipforimage].filePath());
                    result_for_findC contours=image_FindPointstoStats(image,Nsv,ui->checkBox_info_show->isChecked());

                    objects_image.path=imagelist[tipforimage].filePath();
                    objects_image.path_json=listI[3]+listI[1]+".json";
                    objects_image.version="4.6.0";
                    objects_image.image=image;
                    objects_image.image_width=image.cols;
                    objects_image.image_height=image.rows;
                    if(save_image_data)
                    {
                        objects_image.image_data=QByteArray::fromStdString(Mat2Base64(image,listI[2].toStdString()));
                    }
                    else
                    {
                        objects_image.image_data="";
                    }
                    objects_image.image_file=listI[0];

                    for(int i=0;i<contours.point_list.size();i++)
                    {
                        nsv_object object;
                        object.lables=ui->graphicsView->scene.ui_labels->now_label;
                        object.points=contours.point_list[i];
                        object.angle=0;
                        if(contours.list_type==3)
                        {
                            object.shape_type="rectangle";
                        }
                        else
                        {
                            object.shape_type="polygon";
                        }
                        objects_image.objects.append(object);
                    }
                    json.json_create_nsv(objects_image);

                    ui->graphicsView->object_clear();
                    image_show(imagelist[tipforimage].filePath(),tipforimage);
                }
            }
            else
            {
                this->setEnabled(true);
            }
        }
        else
        {
            QList<QString> listI=json.imagename_getfrompath(imagelist[tipforimage].filePath());
            QString name=listI[3]+listI[1]+".json";
            nsv_objects_image objects_image;
            nsv_objects_image objects_read=json.json_read_nsv(name);
            if(objects_read.flags_use)
            {
                objects_image=objects_read;
            }
            cv::Mat image=image_get(imagelist[tipforimage].filePath());
            result_for_findC contours=image_FindPointstoStats(image,Nsv,ui->checkBox_info_show->isChecked());

            objects_image.path=imagelist[tipforimage].filePath();
            objects_image.path_json=listI[3]+listI[1]+".json";
            objects_image.version="4.6.0";
            objects_image.image=image;
            objects_image.image_width=image.cols;
            objects_image.image_height=image.rows;
            if(save_image_data)
            {
                objects_image.image_data=QByteArray::fromStdString(Mat2Base64(image,listI[2].toStdString()));
            }
            else
            {
                objects_image.image_data="";
            }
            objects_image.image_file=listI[0];

            for(int i=0;i<contours.point_list.size();i++)
            {
                nsv_object object;
                object.lables=Nsv.objectname;
                object.points=contours.point_list[i];
                object.angle=0;
                if(contours.list_type==3)
                {
                    object.shape_type="rectangle";
                }
                else
                {
                    object.shape_type="polygon";
                }
                objects_image.objects.append(object);
            }
            json.json_create_nsv(objects_image);

            ui->graphicsView->object_clear();
            image_show(imagelist[tipforimage].filePath(),tipforimage);
        }
    }
    this->setEnabled(true);
}

void MainWindow::on_pushButton_nsv_single_2_clicked()
{
    on_pushButton_nsv_single_clicked();
}

void MainWindow::Nsv_th(QFileInfoList imagelist,nsv Nsv)
{
    qRegisterMetaType<result_for_findC>("result_for_findC");
    qRegisterMetaType<cv::Mat>("cv::Mat");
    for(int i=0;i<imagelist.size();i++)
    {
        QList<QString> listI=json.imagename_getfrompath(imagelist[i].filePath());
        QString name=listI[3]+listI[1]+".json";
        nsv_objects_image objects_image;
        nsv_objects_image objects_read=json.json_read_nsv(name);
        if(objects_read.flags_use)
        {
            objects_image=objects_read;
        }
        cv::Mat image=image_get(imagelist[i].filePath());
        result_for_findC contours=image_FindPointstoStats(image,Nsv,false);
        emit NSV_backtoshow(contours,image,imagelist[i].filePath(),i);
        objects_image.path=imagelist[i].filePath();
        objects_image.path_json=listI[3]+listI[1]+".json";
        objects_image.version="4.6.0";
        objects_image.image=image;
        objects_image.image_width=image.cols;
        objects_image.image_height=image.rows;
        if(save_image_data)
        {
            objects_image.image_data=QByteArray::fromStdString(Mat2Base64(image,listI[2].toStdString()));
        }
        else
        {
            objects_image.image_data="";
        }
        objects_image.image_file=listI[0];
        for(int i=0;i<contours.point_list.size();i++)
        {
            nsv_object object;
            object.lables=Nsv.objectname;
            object.points=contours.point_list[i];
            object.angle=0;
            if(contours.list_type==3)
            {
                object.shape_type="rectangle";
            }
            else
            {
                object.shape_type="polygon";
            }
            objects_image.objects.append(object);
        }
        json.json_create_nsv(objects_image);
    }
    emit NSV_stop();
}

void MainWindow::Nsv_addobject()
{
    for(int i=0;i<ui->graphicsView->ploygon_list.size();i++)
    {
        if(ui->graphicsView->ploygon_list[i]->type()==QGraphicsItem::UserType+10)
        {
            NPolygon *item_b = qgraphicsitem_cast<NPolygon *>(ui->graphicsView->ploygon_list[i]);
            nsv_object object;
            object.lables=item_b->getlabel();
            object.points=item_b->getPointlist();
            object.angle=item_b->getangle();
            if(item_b->getType()==NGraphicsItem::ItemType::Polygon)
            {
                object.shape_type="polygon";
            }
            else if(item_b->getType()==NGraphicsItem::ItemType::Rectangle)
            {
                object.shape_type="rectangle";
            }
            else if(item_b->getType()==NGraphicsItem::ItemType::Sort)
            {
                object.shape_type="sort";
            }
            objects_now.objects.append(object);
        }
        else if(ui->graphicsView->ploygon_list[i]->type()==QGraphicsItem::UserType+20)
        {
            NPolygon_Group *item_b = qgraphicsitem_cast<NPolygon_Group *>(ui->graphicsView->ploygon_list[i]);
            nsv_object object;
            QList<QList<QPointF>> pl=item_b->getgrouplist();
            if(pl.size()>0)
            {
                if(pl[0].size()>2)
                {
                    object.points=item_b->getgrouplist()[0];
                    object.angle=0;
                    QList<QString> ll=item_b->getlabellist();
                    if(ll.size()>0)
                    {
                        object.lables=ll[0];
                    }
                    else
                    {
                        object.lables=" ";
                    }
                    object.shape_type="charline";
                    objects_now.objects.append(object);
                }
            }
        }
    }
}

void MainWindow::Nsv_delete_object(QList<QPointF> pointlist)
{
    for(int i=0;i<objects_now.objects.size();i++)
    {
        if(objects_now.objects[i].points==pointlist)
        {
            objects_now.objects.removeAt(i);
        }
    }
}

void MainWindow::Nsv_show(result_for_findC contour,cv::Mat image,QString imagepath,int tip)
{
    ui->graphicsView->object_clear();
    scale_size=ui->graphicsView->image_add(image);
    for(int i=0;i<contour.point_list.size();i++)
    {
        if(ui->comboBox_poingtforcenter->currentIndex()==3)
        {
            ui->graphicsView->object_add_pointlist(QList<QList<QPointF>>{contour.point_list[i]},QList<QString>{""},QList<double>{0},1,0);
        }
        else
        {
            ui->graphicsView->object_add_pointlist(QList<QList<QPointF>>{contour.point_list[i]},QList<QString>{""},QList<double>{0},0,0);
        }
    }
    ui->pushButton_saveimage->setText("文件名称:"+imagepath);
    ui->label_image_size->setText("宽("+QString::number(image.cols)+"),高("+QString::number(image.rows)+")");
    ui->label_tipimage->setText(QString::number(tip,10)+"/"+QString::number(imagelist.size()-1,10));
    ui->pushButton_scale_size->setText(QString::number(scale_size*100,'f',0)+" %");
}

void MainWindow::Nsv_finish()
{
    ui->graphicsView->object_clear();
    tipforimage=0;
    image_show(imagelist[0].filePath(),0);
    this->setEnabled(true);
}

//数据集操作

void MainWindow::on_comboBox_other_do_currentIndexChanged(int index)
{
    ui->tabWidget_other_do->setCurrentIndex(index);
}

//数据集扩展

QList<expan_size> MainWindow::expan()
{
    QList<float> alphe_expan;
    QList<float> beta_expan;
    QList<float> scale_expan;
    if(ui->checkBox_expan_alpha->isChecked())
    {
        float i=ui->doubleSpinBox_expan_min_alpha->value();
        while(i<ui->doubleSpinBox_expan_max_alpha->value()+ui->doubleSpinBox_expan_single_alpha->value())
        {
            if(i<-1 || i>=1)
            {
                if(i>0)
                {
                    alphe_expan.append(i);
                }
                else
                {
                    alphe_expan.append(1/abs(i));
                }
            }
            i+=ui->doubleSpinBox_expan_single_alpha->value();
        }
    }

//    qDebug()<<alphe_expan;

    if(ui->checkBox_expan_scale->isChecked())
    {
        float i=ui->doubleSpinBox_expan_min_scale->value();
        while(i<ui->doubleSpinBox_expan_max_scale->value()+ui->doubleSpinBox_expan_single_scale->value())
        {
            if(i<-1 || i>=1)
            {
                if(i>0)
                {
                    scale_expan.append(i);
                }
                else
                {
                    scale_expan.append(1/abs(i));
                }
            }
            i+=ui->doubleSpinBox_expan_single_scale->value();
        }
    }

//    qDebug()<<scale_expan;

    if(ui->checkBox_expan_beta->isChecked())
    {
        int j=ui->spinBox_expan_min_beta->value();
        while(j<ui->spinBox_expan_max_beta->value()+ui->spinBox_expan_single_beta->value())
        {
            beta_expan.append(j);
            j+=ui->spinBox_expan_single_beta->value();
        }
    }

//    qDebug()<<beta_expan;


    QList<expan_size> expa_list;
    QList<expan_size> expa_list_alpha;

    if(alphe_expan.size()>0)
    {   
        if(expa_list.size()>0)
        {
            for (int j=0;j<expa_list.size();j++)
            {
                for (int i=0;i<alphe_expan.size();i++)
                {
                    expan_size epan;
                    epan.alpha_size=alphe_expan[i];
                    epan.beta_size=expa_list[j].beta_size;
                    epan.scale_size=expa_list[j].scale_size;
                    expa_list_alpha.append(epan);
                }
            }
        }
        else
        {
            for (int i=0;i<alphe_expan.size();i++)
            {
                expan_size epan;
                epan.alpha_size=alphe_expan[i];
                expa_list_alpha.append(epan);
            }
        }
        expa_list=expa_list_alpha;
    }

    QList<expan_size> expa_list_alpha_beta;

    if(beta_expan.size()>0)
    {
        if(expa_list.size()>0)
        {
            for (int j=0;j<expa_list.size();j++)
            {
                for (int i=0;i<beta_expan.size();i++)
                {
                    expan_size epan;
                    epan.alpha_size=expa_list[j].alpha_size;
                    epan.beta_size=beta_expan[i];
                    epan.scale_size=expa_list[j].scale_size;
                    expa_list_alpha_beta.append(epan);
                }
            }
        }
        else
        {
            for (int i=0;i<beta_expan.size();i++)
            {
                expan_size epan;
                epan.beta_size=beta_expan[i];
                expa_list_alpha_beta.append(epan);
            }
        }

        expa_list=expa_list_alpha_beta;
    }

    QList<expan_size> expa_list_alpha_beta_scale;

    if(scale_expan.size()>0)
    {
        if(expa_list.size()>0)
        {
            for (int j=0;j<expa_list.size();j++)
            {
                for (int i=0;i<scale_expan.size();i++)
                {
                    expan_size epan;
                    epan.alpha_size=expa_list[j].alpha_size;
                    epan.beta_size=expa_list[j].beta_size;
                    epan.scale_size=scale_expan[i];
                    expa_list_alpha_beta_scale.append(epan);
                }
            }
        }
        else
        {
            for (int i=0;i<scale_expan.size();i++)
            {
                expan_size epan;
                epan.scale_size=scale_expan[i];
                expa_list_alpha_beta_scale.append(epan);
            }
        }

        expa_list=expa_list_alpha_beta_scale;
    }

    ui->label_expan_size->setText(QString::number(expa_list.size()));

    return expa_list;
}

void MainWindow::on_checkBox_expan_alpha_clicked()
{
    expan_list=expan();
}

void MainWindow::on_checkBox_expan_beta_clicked()
{
    expan_list=expan();
}

void MainWindow::on_doubleSpinBox_expan_min_alpha_valueChanged(double)
{
    expan_list=expan();
}

void MainWindow::on_doubleSpinBox_expan_max_alpha_valueChanged(double)
{
    expan_list=expan();
}

void MainWindow::on_doubleSpinBox_expan_single_alpha_valueChanged(double)
{
    expan_list=expan();
}

void MainWindow::on_checkBox_expan_scale_clicked()
{
    expan_list=expan();
}

void MainWindow::on_doubleSpinBox_expan_min_scale_valueChanged(double)
{
    expan_list=expan();
}

void MainWindow::on_doubleSpinBox_expan_max_scale_valueChanged(double)
{
    expan_list=expan();
}

void MainWindow::on_doubleSpinBox_expan_single_scale_valueChanged(double)
{
    expan_list=expan();
}

void MainWindow::on_spinBox_expan_min_beta_valueChanged(int)
{
    expan_list=expan();
}

void MainWindow::on_spinBox_expan_max_beta_valueChanged(int)
{
    expan_list=expan();
}

void MainWindow::on_spinBox_expan_single_beta_valueChanged(int)
{
    expan_list=expan();
}

void MainWindow::on_pushButton_expan_start_clicked()
{
    this->setEnabled(false);
    QString imagepath=imagelist[0].filePath();
    QList<QString> listI=json.imagename_getfrompath(imagepath);
    QDir dir;
    if (!dir.exists(listI[3]+"/expan"))
    {
        bool res = dir.mkpath(listI[3]+"/expan");

        if(res)
        {
            QMessageBox msgBox;
            msgBox.setText("数据集扩展针对图像及json文件，当仅有图像没有json文件时，该图像不会参与扩展。\n"
                           "\n--扩展不会对原文件夹产生影响，扩展后文件会在尾部添加扩展序号。\n"
                           "\n--扩展后文件会存放在当前目录下expan文件夹中。\n"
                           "\n--扩展前请根据扩展倍数及源文件大小检查磁盘剩余空间，防止磁盘过满。\n"
                           "\n--扩展中请不要操作expan文件夹。\n");
            msgBox.setInformativeText("当前扩展倍数为："+QString::number(expan_list.size())+"，是否开始扩展?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();
            if(ret==QMessageBox::Yes)
            {
                ui->graphicsView->object_clear();
                QFuture<void> f2 = QtConcurrent::run(this,&MainWindow::Expan_th);
            }
            else
            {
                this->setEnabled(true);
                ui->graphicsView->object_clear();
                tipforimage=0;
                image_show(imagelist[0].filePath(),0);
            }
        }
        else
        {
            QMessageBox::about(NULL, "提示", "新建目录失败 "+listI[3]+"/expan");
            qDebug() << "新建目录是否成功" << res <<" "<<listI[3]+"/expan";
            this->setEnabled(true);
            ui->graphicsView->object_clear();
            tipforimage=0;
            image_show(imagelist[0].filePath(),0);
        }
    }
    else
    {
        QMessageBox::about(NULL, "提示", "已存在 "+listI[3]+"/expan"+" 请重命名原有该路径" );
        qDebug() << "已存在 "<<listI[3]+"/expan"<< "请重命名原有该路径";
        this->setEnabled(true);
        ui->graphicsView->object_clear();
        tipforimage=0;
        image_show(imagelist[0].filePath(),0);
    }
}

void MainWindow::Expan_th()
{
    qRegisterMetaType<cv::Mat>("cv::Mat");
    for(int i=0;i<imagelist.size();i++)
    {
        QString imagepath=imagelist[i].filePath();
        QList<QString> listI=json.imagename_getfrompath(imagepath);
        QString name=listI[3]+listI[1]+".json";

        nsv_objects_image objects_read=json.json_read_nsv(name);
        QList<nsv_object> objects=objects_read.objects;
        if(objects_read.flags_use)
        {
            cv::Mat img=image_get(imagepath);
            for(int j=0;j<expan_list.size();j++)
            {
                cv::Mat img_c=image_AlphaBeta(img,expan_list[j].alpha_size,expan_list[j].beta_size);
                img_c=image_Scale(img_c,expan_list[j].scale_size);
                if(expan_recolor)
                {
                    img_c=image_Gray(img_c,0);
                }
                cv::imwrite((listI[3]+"expan/"+listI[1]+"_"+QString::number(j)+"."+listI[2]).toUtf8().toStdString(),img_c);
                objects_read.path=listI[3]+"expan/"+listI[1]+"_"+QString::number(j)+"."+listI[2];
                objects_read.path_json=listI[3]+"expan/"+listI[1]+"_"+QString::number(j)+".json";
                if(save_image_data)
                {
                    objects_read.image_data=QByteArray::fromStdString(Mat2Base64(img_c,listI[2].toStdString()));
                }
                else
                {
                    objects_read.image_data="";
                }
                objects_read.image_file=listI[1]+"_"+QString::number(j)+"."+listI[2];
                objects_read.image_height=img_c.rows;
                objects_read.image_width=img_c.cols;
                for(int t=0;t<objects_read.objects.size();t++)
                {
                    objects_read.objects[t].points=pointlist2k(objects[t].points,expan_list[j].scale_size);
                }
                json.json_create_nsv(objects_read);

                cv::Mat img_test=cv::imread((listI[3]+"expan/"+listI[1]+"_"+QString::number(j)+"."+listI[2]).toUtf8().toStdString());
                nsv_objects_image objects_test=json.json_read_nsv(listI[3]+"expan/"+listI[1]+"_"+QString::number(j)+".json");
                if(!img_test.empty() && objects_test.flags_use==false)
                {
                    QFile fileTemp(listI[3]+"expan/"+listI[1]+"_"+QString::number(j)+"."+listI[2]);
                    fileTemp.remove();
                }
                else if(img_test.empty() && objects_test.flags_use==true)
                {
                    QFile fileTemp(listI[3]+"expan/"+listI[1]+"_"+QString::number(j)+".json");
                    fileTemp.remove();
                }

                emit EXPAN_backtoshow(img_c,objects_read.path,i);
            }
            if(expan_list.size()==0 && expan_recolor)
            {
                cv::Mat img_c=image_Gray(img,0);
                cv::imwrite((listI[3]+"expan/"+listI[1]+"_"+QString::number(i)+"."+listI[2]).toUtf8().toStdString(),img_c);
                objects_read.path=listI[3]+"expan/"+listI[1]+"_"+QString::number(i)+"."+listI[2];
                objects_read.path_json=listI[3]+"expan/"+listI[1]+"_"+QString::number(i)+".json";
                if(save_image_data)
                {
                    objects_read.image_data=QByteArray::fromStdString(Mat2Base64(img_c,listI[2].toStdString()));
                }
                else
                {
                    objects_read.image_data="";
                }
                objects_read.image_file=listI[1]+"_"+QString::number(i)+"."+listI[2];
                json.json_create_nsv(objects_read);

                cv::Mat img_test=cv::imread((listI[3]+"expan/"+listI[1]+"_"+QString::number(i)+"."+listI[2]).toUtf8().toStdString());
                nsv_objects_image objects_test=json.json_read_nsv(listI[3]+"expan/"+listI[1]+"_"+QString::number(i)+".json");
                if(!img_test.empty() && objects_test.flags_use==false)
                {
                    QFile fileTemp(listI[3]+"expan/"+listI[1]+"_"+QString::number(i)+"."+listI[2]);
                    fileTemp.remove();
                }
                else if(img_test.empty() && objects_test.flags_use==true)
                {
                    QFile fileTemp(listI[3]+"expan/"+listI[1]+"_"+QString::number(i)+".json");
                    fileTemp.remove();
                }

                emit EXPAN_backtoshow(img_c,objects_read.path,i);
            }
        }
        else
        {
            qDebug()<<"no found json "+name;
        }
        objects_read.flags_use=false;
    }

    emit EXPAN_stop();
}

void MainWindow::Expan_stop()
{
    this->setEnabled(true);
    ui->graphicsView->object_clear();
    tipforimage=0;
    image_show(imagelist[0].filePath(),0);
}

void MainWindow::Expan_show(cv::Mat image,QString imagepath,int tip)
{
    ui->graphicsView->object_clear();
    if(!image.empty())
    {
        scale_size=ui->graphicsView->image_add(image);
    }
    ui->pushButton_saveimage->setText("文件名称:"+imagepath);
    ui->label_image_size->setText("宽("+QString::number(image.cols)+"),高("+QString::number(image.rows)+")");
    ui->label_tipimage->setText(QString::number(tip,10)+"/"+QString::number(imagelist.size()-1));
    ui->pushButton_scale_size->setText(QString::number(scale_size*100,'f',0)+" %");
}

void MainWindow::on_checkBox_expan_recolor_clicked()
{
    if(ui->checkBox_expan_recolor->isChecked())
    {
        expan_recolor=true;
    }
    else
    {
        expan_recolor=false;
    }
}

void MainWindow::on_pushButton_expan_aline_clicked()
{
    QString ns=QFileDialog::getExistingDirectory(this,"待对齐文件夹","./");
    this->setEnabled(false);
    QFileInfoList imglist=GetFileList(ns);
    QFileInfoList jsonlist=GetFileList_json(ns);
    if(imglist.size()>0 && jsonlist.size()>0)
    {
        QString imagepath=imglist[0].filePath();
        QList<QString> listI=json.imagename_getfrompath(imagepath);
        QDir dir;
        if (!dir.exists(listI[3]+"/caline"))
        {
            bool res = dir.mkpath(listI[3]+"/caline");

            if(res)
            {
                QMessageBox msgBox;
                msgBox.setText("文件对齐仅针对图像及json文件，对齐依据为文件名称，即数据集图像与json文件根文件名必须相同。\n"
                               "\n--未对齐文件将转存至原路径calign文件夹。\n"
                               "\n--对齐时会对原文件夹产生影响。\n"
                               "\n--对齐前请预先做好备份。\n"
                               "\n--对齐中请不要操作文件夹。\n");
                if(jsonlist.size()>imglist.size())
                {
                    msgBox.setInformativeText("当前文件夹json文件多于图像，是否开始对齐?");
                }
                else
                {
                    msgBox.setInformativeText("当前文件夹图像多于或等于json文件，是否开始对齐?");
                }
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::No);
                int ret = msgBox.exec();
                if(ret==QMessageBox::Yes)
                {
                    ui->graphicsView->object_clear();
                    QFuture<void> f4 = QtConcurrent::run(this,&MainWindow::Rxpan_Aline_th,imglist,jsonlist);
                }
                else
                {
                    this->setEnabled(true);
                    ui->graphicsView->object_clear();
                    tipforimage=0;
                    image_show(imagelist[0].filePath(),0);
                }
            }
            else
            {
                QMessageBox::about(NULL, "提示", "新建目录失败 "+listI[3]+"/caline");
                qDebug() << "新建目录是否成功" << res <<" "<<listI[3]+"/caline";
                this->setEnabled(true);
                ui->graphicsView->object_clear();
                tipforimage=0;
                image_show(imagelist[0].filePath(),0);
            }
        }
        else
        {
            QMessageBox::about(NULL, "提示", "已存在 "+listI[3]+"/caline"+" 请重命名原有该路径" );
            qDebug() << "已存在 "<<listI[3]+"/caline"<< "请重命名原有该路径";
            this->setEnabled(true);
            ui->graphicsView->object_clear();
            tipforimage=0;
            image_show(imagelist[0].filePath(),0);
        }
    }
    else
    {
        if(imglist.size()==0 && jsonlist.size()>0)
        {
            QMessageBox::about(NULL, "提示", "目录中不包含图像文件，请检查后重新对齐");
        }
        else if(jsonlist.size()==0 && imglist.size()>0)
        {
            QMessageBox::about(NULL, "提示", "目录中不包含json文件，请检查后重新对齐");
        }
        else
        {
            QMessageBox::about(NULL, "提示", "目录中不包含json及图像文件，请检查后重新对齐");
        }
        this->setEnabled(true);
        ui->graphicsView->object_clear();
        tipforimage=0;
        image_show(imagelist[0].filePath(),0);
    }

}

//数据集对齐

void MainWindow::Rxpan_Aline_th(QFileInfoList imglist,QFileInfoList jsonlist)
{
    qRegisterMetaType<cv::Mat>("cv::Mat");
    for(int i=0;i<jsonlist.size();i++)
    {
        QString jsonpath=jsonlist[i].filePath();
        QList<QString> listI=json.imagename_getfrompath(jsonpath);

        nsv_objects_image objects_test=json.json_read_nsv(jsonpath);
        QString imgname=listI[3]+objects_test.image_file;
        cv::Mat img_test=cv::imread(imgname.toUtf8().toStdString());
        qDebug()<<imgname<<" "<<jsonpath;
        if(!img_test.empty() && objects_test.flags_use==false)
        {
            QFile fileTemp(imgname);
            fileTemp.copy(listI[3]+"caline/"+objects_test.image_file);
            fileTemp.remove();
        }
        else if(img_test.empty() && objects_test.flags_use==true)
        {
            QFile fileTemp(jsonpath);
            fileTemp.copy(listI[3]+"caline/"+listI[1]+"."+"json");
            fileTemp.remove();
        }
        emit ALINE_backtoshow(img_test,imgname+" "+jsonpath,tipforimage);
    }

    for(int i=0;i<imglist.size();i++)
    {
        QString imagepath=imglist[i].filePath();
        QList<QString> listI=json.imagename_getfrompath(imagepath);
        QString jsonname=listI[3]+listI[1]+".json";

        nsv_objects_image objects_test=json.json_read_nsv(jsonname);
        cv::Mat img_test=cv::imread(imagepath.toUtf8().toStdString());
        qDebug()<<imagepath<<" "<<jsonname;
        if(!img_test.empty() && objects_test.flags_use==false)
        {
            QFile fileTemp(imagepath);
            fileTemp.copy(listI[3]+"caline/"+listI[1]+"."+listI[2]);
            fileTemp.remove();
        }
        else if(img_test.empty() && objects_test.flags_use==true)
        {
            QFile fileTemp(jsonname);
            fileTemp.copy(listI[3]+"caline/"+listI[1]+"."+"json");
            fileTemp.remove();
        }
        emit ALINE_backtoshow(img_test,imagepath+" "+jsonname,tipforimage);
    }

    emit ALINE_stop();
}

//图像集规整

void MainWindow::on_lineEdit_rename_name_textChanged(const QString &arg1)
{
    rename.name=arg1;
    ui->label_rename_show->setText(rename.name+"_0."+rename.filetype);
}

void MainWindow::on_comboBox_rename_type_currentIndexChanged(int index)
{
    rename.type=index;
}

void MainWindow::on_spinBox_rename_single_valueChanged(int arg1)
{
    if(arg1>imagelist.size())
    {
        ui->spinBox_rename_single->setValue(imagelist.size());
    }
    else
    {
        rename.single=arg1;
    }
}

void MainWindow::on_comboBox_rename_filetype_currentTextChanged(const QString &arg1)
{
    rename.filetype=arg1;
    ui->label_rename_show->setText(rename.name+"_0."+rename.filetype);
}

void MainWindow::on_pushButton_rename_clicked()
{
    this->setEnabled(false);
    QString imagepath=imagelist[0].filePath();
    QList<QString> listI=json.imagename_getfrompath(imagepath);
    QDir dir;
    if (!dir.exists(listI[3]+"/rename"))
    {
        bool res = dir.mkpath(listI[3]+"/rename");

        if(res)
        {
            if(rename.single<imagelist.size())
            {
                QMessageBox msgBox;
                msgBox.setText("图像集规整主要针对图像文件，当存在json文件时，会连同json文件一起操作。\n"
                               "\n--规整不会对原文件夹产生影响，规整后文件会损失原有命名规律。\n"
                               "\n--规整后文件会存放在当前目录下rename文件夹中。\n"
                               "\n--规整中请不要操作rename文件夹。\n");
                msgBox.setInformativeText("当前根名称为："+rename.name+"，是否开始规整?");
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::No);
                int ret = msgBox.exec();
                if(ret==QMessageBox::Yes)
                {
                    ui->graphicsView->object_clear();
                    QFuture<void> f3 = QtConcurrent::run(this,&MainWindow::Rename_th);
                }
                else
                {
                    this->setEnabled(true);
                    ui->graphicsView->object_clear();
                    tipforimage=0;
                    image_show(imagelist[0].filePath(),0);
                }
            }
            else
            {
                QMessageBox::about(NULL, "提示", "步长大于文件夹内图片数量"+listI[3]);
                qDebug() << "步长大于文件夹内图片数量";
                this->setEnabled(true);
                ui->graphicsView->object_clear();
                tipforimage=0;
                image_show(imagelist[0].filePath(),0);
            }
        }
        else
        {
            QMessageBox::about(NULL, "提示", "新建目录失败 "+listI[3]+"/rename");
            qDebug() << "新建目录是否成功" << res <<" "<<listI[3]+"/rename";
            this->setEnabled(true);
            ui->graphicsView->object_clear();
            tipforimage=0;
            image_show(imagelist[0].filePath(),0);
        }
    }
    else
    {
        QMessageBox::about(NULL, "提示", "已存在 "+listI[3]+"/rename"+" 请重命名原有该路径" );
        qDebug() << "已存在 "<<listI[3]+"/rename"<< "请重命名原有该路径" ;
        this->setEnabled(true);
        ui->graphicsView->object_clear();
        tipforimage=0;
        image_show(imagelist[0].filePath(),0);
    }
}

void MainWindow::Rename_th()
{
    qRegisterMetaType<cv::Mat>("cv::Mat");

    int single=rename.single;

    qDebug()<<rename.single<<" "<<rename.filetype<<" "<<rename.name<<" "<<rename.type;

    if(rename.type==2)
    {
        QList<int> imgtiplist;
        for(int j=0;j<rename.single;j++)
        {
            bool will=true;
            while (will)
            {
                int tip=int(rand()%imagelist.size());
                if(!intinList(tip,imgtiplist))
                {
                    imgtiplist.append(tip);
                    will=false;
                }
            }
        }

        for(int i=0;i<imgtiplist.size();i++)
        {
            if(rename.type==2)
            {
                QString imagepath=imagelist[i].filePath();
                QList<QString> listI=json.imagename_getfrompath(imagepath);
                QString name=listI[3]+listI[1]+".json";
//                qDebug()<<listI;

                nsv_objects_image objects_read=json.json_read_nsv(name);
                cv::Mat img=image_get(imagepath);
                cv::imwrite((listI[3]+"rename/"+rename.name+"_"+QString::number(i)+"."+rename.filetype).toUtf8().toStdString(),img);
                if(objects_read.flags_use)
                {
                    objects_read.path=listI[3]+"rename/"+rename.name+"_"+QString::number(i)+"."+rename.filetype;
                    objects_read.path_json=listI[3]+"rename/"+rename.name+"_"+QString::number(i)+".json";
                    objects_read.image_file=rename.name+"_"+QString::number(i)+"."+rename.filetype;
                    json.json_create_nsv(objects_read);
                }
                else
                {
                    qDebug()<<"no found json "+name;
                }
                emit RENAME_backtoshow(img,imagepath,i);
            }
        }
    }
    else
    {
        if(rename.type==1)
        {
            single=int(imagelist.size()/rename.single);
        }

        for(int i=0;i<imagelist.size();i++)
        {
            if(i%single==0)
            {
                QString imagepath=imagelist[i].filePath();
                QList<QString> listI=json.imagename_getfrompath(imagepath);
                QString name=listI[3]+listI[1]+".json";

                nsv_objects_image objects_read=json.json_read_nsv(name);
                cv::Mat img=image_get(imagepath);
                cv::imwrite((listI[3]+"rename/"+rename.name+"_"+QString::number(i)+"."+rename.filetype).toUtf8().toStdString(),img);
                if(objects_read.flags_use)
                {
                    objects_read.path=listI[3]+"rename/"+rename.name+"_"+QString::number(i)+"."+rename.filetype;
                    objects_read.path_json=listI[3]+"rename/"+rename.name+"_"+QString::number(i)+".json";
                    objects_read.image_file=rename.name+"_"+QString::number(i)+"."+rename.filetype;
                    json.json_create_nsv(objects_read);
                }
                else
                {
                    qDebug()<<"no found json "+name;
                }
                emit RENAME_backtoshow(img,imagepath,i);
            }
        }
    }
    emit RENAME_stop();
}

//数据集标签替换

void MainWindow::Replace_th()
{
    qRegisterMetaType<cv::Mat>("cv::Mat");

    int replace_num=0;

    for(int i=0;i<imagelist.size();i++)
    {
        QString imagepath=imagelist[i].filePath();
        QList<QString> listI=json.imagename_getfrompath(imagepath);
        QString name=listI[3]+listI[1]+".json";

        nsv_objects_image objects_read=json.json_read_nsv(name);
        QList<nsv_object> objects=objects_read.objects;
        if(objects_read.flags_use)
        {
            cv::Mat img=image_get(imagepath);
            cv::imwrite((listI[3]+"replace/"+listI[1]+"."+listI[2]).toUtf8().toStdString(),img);
            objects_read.path=listI[3]+"replace/"+listI[1]+"."+listI[2];
            objects_read.path_json=listI[3]+"replace/"+listI[1]+".json";
            for(int t=0;t<objects_read.objects.size();t++)
            {
                if(objects_read.objects[t].lables==replace_ago)
                {
                    objects_read.objects[t].lables=replace_after;
                    replace_num+=1;
                }
            }
            json.json_create_nsv(objects_read);

            //检验对齐
            cv::Mat img_test=cv::imread((listI[3]+"replace/"+listI[1]+"."+listI[2]).toUtf8().toStdString());
            nsv_objects_image objects_test=json.json_read_nsv(listI[3]+"replace/"+listI[1]+".json");
            if(!img_test.empty() && objects_test.flags_use==false)
            {
                QFile fileTemp(listI[3]+"replace/"+listI[1]+"."+listI[2]);
                fileTemp.remove();
            }
            else if(img_test.empty() && objects_test.flags_use==true)
            {
                QFile fileTemp(listI[3]+"replace/"+listI[1]+".json");
                fileTemp.remove();
            }

            emit EXPAN_backtoshow(img,objects_read.path,i);
        }
        else
        {
            qDebug()<<"no found json "+name;
        }
        objects_read.flags_use=false;
    }

    emit REPLACE_stop(replace_num,replace_ago,replace_after);
}

void MainWindow::Replace_stop(int num,QString ago,QString after)
{
    this->setEnabled(true);
    ui->graphicsView->object_clear();
    tipforimage=0;
    image_show(imagelist[0].filePath(),0);

    QMessageBox msgBox;
    msgBox.setText("本次操作共替换:"+QString::number(num)+"个标签。\n"
                   "\n替换标签后的数据集存放在本目录replace文件夹下。\n"
                   "\n替换前标签为:"+ago+"。\n"
                   "\n替换后标签为:"+after+"。\n");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::on_lineEdit_replace_ago_textChanged(const QString &arg1)
{
    replace_ago=arg1;
    replace_after=ui->lineEdit_replace_after->text();
}

void MainWindow::on_lineEdit_replace_after_textChanged(const QString &arg1)
{
    replace_ago=ui->lineEdit_replace_ago->text();
    replace_after=arg1;
}

void MainWindow::on_pushButton_replace_clicked()
{
    this->setEnabled(false);
    QString imagepath=imagelist[0].filePath();
    QList<QString> listI=json.imagename_getfrompath(imagepath);
    QDir dir;
    if (!dir.exists(listI[3]+"/replace"))
    {
        bool res = dir.mkpath(listI[3]+"/replace");

        if(res)
        {
            QMessageBox msgBox;
            msgBox.setText("图像集标签替换主要针对json文件，在保存json文件时，会复制其对应图像。\n"
                           "\n--替换不会对原文件夹产生影响，替换仅针对标签。\n"
                           "\n--替换后文件会存放在当前目录下replace文件夹中。\n"
                           "\n--替换时请不要操作replace文件夹。\n");
            msgBox.setInformativeText("替换前标签为："+replace_ago+" 替换后标签为："+replace_after+"，是否开始替换?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();
            if(ret==QMessageBox::Yes)
            {
                ui->graphicsView->object_clear();
                QFuture<void> f3 = QtConcurrent::run(this,&MainWindow::Replace_th);
            }
            else
            {
                this->setEnabled(true);
                ui->graphicsView->object_clear();
                tipforimage=0;
                image_show(imagelist[0].filePath(),0);
            }
        }
        else
        {
            QMessageBox::about(NULL, "提示", "新建目录失败 "+listI[3]+"/replace");
            qDebug() << "新建目录是否成功" << res <<" "<<listI[3]+"/replace";
            this->setEnabled(true);
            ui->graphicsView->object_clear();
            tipforimage=0;
            image_show(imagelist[0].filePath(),0);
        }
    }
    else
    {
        QMessageBox::about(NULL, "提示", "已存在 "+listI[3]+"/replace"+" 请重命名原有该路径" );
        qDebug() << "已存在 "<<listI[3]+"/replace"<< "请重命名原有该路径" ;
        this->setEnabled(true);
        ui->graphicsView->object_clear();
        tipforimage=0;
        image_show(imagelist[0].filePath(),0);
    }
}

//腐蚀膨胀（因子调制）

void MainWindow::on_pushButton_more_ErDi_clicked()
{
    ui->tabWidget->setCurrentIndex(3);

    if(image_thresold.empty())
    {
        on_horizontalSlider_thresholdsize_valueChanged(ui->horizontalSlider_thresholdsize->value());
    }
    cv::Mat image_thresold_ErDi=image_thresold_backup.clone();

    image_show(image_thresold_ErDi);
}

void MainWindow::ErDi_more()
{
    if(image_thresold.empty())
    {
        on_horizontalSlider_thresholdsize_valueChanged(ui->horizontalSlider_thresholdsize->value());
    }
    cv::Mat image_thresold_ErDi=image_thresold_backup.clone();
    Nsv.erdi_legth=ui->spinBox_ErDi_legth->value();
    Nsv.erdi_width=ui->spinBox_ErDi_width->value();
    Nsv.erdi_type=ui->comboBox_ErDi_type->currentIndex();
    Nsv.erdi_dowhat=ui->comboBox_ErDi_do->currentIndex();
    QList<cv::Mat> image_list=image_ErDi_more(image_thresold_ErDi,ui->spinBox_ErDi_legth->value(),ui->spinBox_ErDi_width->value(),ui->comboBox_ErDi_type->currentIndex(),ui->comboBox_ErDi_do->currentIndex());
    if(image_list.size()>0)
    {
        image_show(image_list[0]);
        ui->label_ErDi_show->add_image(image_list[1]);
        ui->label_ErDi_show_2->add_image(image_list[2]);
    }
}

void MainWindow::on_spinBox_ErDi_legth_valueChanged(int)
{
    ErDi_more();
}

void MainWindow::on_spinBox_ErDi_width_valueChanged(int)
{
    ErDi_more();
}

void MainWindow::on_checkBox_ErDi_Enable_clicked()
{
    Nsv.erdi_more=ui->checkBox_ErDi_Enable->isChecked();
}

//直方图均衡

void MainWindow::on_pushButton_Clane_clicked()
{
    param_cross a;
    a.tig=0;

    QList<QVariant> input;

    QVariant b;

    cv::Mat image_c;
    cv::cvtColor(image_now,image_c,cv::COLOR_BGR2GRAY);

    b.setValue<cv::Mat>(image_c);

    input.append(b);
    input.append(false);
    input.append(100);
    input.append(255);

    QList<QVariant> list_out=nsv_image_tree::item_an(input,a);

    cv::Mat image=list_out[0].value<cv::Mat>();

    image_show(image);
//    ui->tabWidget->setCurrentIndex(4);
}

void MainWindow::Clane_more()
{
    cv::Size size_clane=cv::Size(ui->spinBox_CLane_tile->value(),ui->spinBox_CLane_tile->value());
    if(ui->comboBox_Clane->currentIndex()==0)
    {
        ui->groupBox_Clane_size->setEnabled(true);
    }
    else if(ui->comboBox_Clane->currentIndex()==1)
    {
        ui->groupBox_Clane_size->setEnabled(false);
    }
    Nsv.clane_clsize=ui->doubleSpinBox_Clane_size->value();
    Nsv.clane_type=ui->comboBox_Clane->currentIndex();
    Nsv.clane_size=size_clane;
    Nsv.clane_colour=ui->checkBox_Clane_colour->isChecked();
    if(ui->checkBox_Clane_colour->isChecked())
    {
        cv::Mat image_input=image_now.clone();
        cv::Mat image_clane=image_Clane_colour(image_input,ui->comboBox_Clane->currentIndex(),ui->doubleSpinBox_Clane_size->value(),size_clane);
        image_show(image_clane);
    }
    else
    {
        if(image_gray.empty())
        {
            on_checkBox_split_clicked();
        }
        cv::Mat image_gray_Clane=image_gray.clone();
        cv::Mat image_clane=image_Clane(image_gray_Clane,ui->comboBox_Clane->currentIndex(),ui->doubleSpinBox_Clane_size->value(),size_clane);
        image_show(image_clane);
    }
}

void MainWindow::on_doubleSpinBox_Clane_size_valueChanged(double)
{
    Clane_more();
}

void MainWindow::on_spinBox_CLane_tile_valueChanged(int)
{
    Clane_more();;
}

void MainWindow::on_pushButton_Clane_last_clicked()
{
    if(ui->checkBox_Clane_colour->isChecked())
    {
        cv::Mat image_input=image_now.clone();
        image_show(image_input);
    }
    else
    {
        if(image_gray.empty())
        {
            on_checkBox_split_clicked();
        }
        cv::Mat image_gray_Clane=image_gray.clone();
        image_show(image_gray_Clane);
    }
}

void MainWindow::on_checkBox_Clane_enable_clicked()
{
    Nsv.clane=ui->checkBox_Clane_enable->isChecked();
}

//角度计算

void MainWindow::on_comboBox_Angle_type_currentIndexChanged(int index)
{
    Nsv.angle_type=index;
}

void MainWindow::on_doubleSpinBox_Angle_com_valueChanged(double arg1)
{
    Nsv.angle_com=arg1;

}

void MainWindow::on_checkBox_Angle_left_clicked()
{
    if(ui->checkBox_Angle_left->isChecked())
    {
        Nsv.angle_left=true;
    }
    else
    {
        Nsv.angle_left=false;
    }
}

//色差提取

void MainWindow::on_pushButton_more_Color_clicked()
{
    ui->tabWidget->setCurrentIndex(6);
    image_show(image_backup);
}

void MainWindow::Color_more(QColor color,QPointF)
{
    if(ui->checkBox_Color_getfromimage->isChecked())
    {
        extract_color=cv::Scalar(color.blue(),color.green(),color.red());
        ui->label_Color_b->setText("B："+QString::number(color.blue()));
        ui->label_Color_g->setText("G："+QString::number(color.green()));
        ui->label_Color_r->setText("R："+QString::number(color.red()));
        ui->horizontalSlider_Color_b->setValue(color.blue());
        ui->horizontalSlider_Color_g->setValue(color.green());
        ui->horizontalSlider_Color_r->setValue(color.red());
    }
    else
    {
        extract_color=cv::Scalar(ui->horizontalSlider_Color_b->value(),ui->horizontalSlider_Color_g->value(),ui->horizontalSlider_Color_r->value());
        ui->label_Color_b->setText("B："+QString::number(ui->horizontalSlider_Color_b->value()));
        ui->label_Color_g->setText("G："+QString::number(ui->horizontalSlider_Color_g->value()));
        ui->label_Color_r->setText("R："+QString::number(ui->horizontalSlider_Color_r->value()));
    }
    Nsv.extract_color=extract_color;
    cv::Mat image=cv::Mat(cv::Size(61,61),CV_8UC3,extract_color);
    ui->label_Color_show->add_image(image);
}

void MainWindow::Color_more()
{
    if(!ui->checkBox_Color_getfromimage->isChecked())
    {
        extract_color=cv::Scalar(ui->horizontalSlider_Color_b->value(),ui->horizontalSlider_Color_g->value(),ui->horizontalSlider_Color_r->value());
        ui->label_Color_b->setText("B："+QString::number(ui->horizontalSlider_Color_b->value()));
        ui->label_Color_g->setText("G："+QString::number(ui->horizontalSlider_Color_g->value()));
        ui->label_Color_r->setText("R："+QString::number(ui->horizontalSlider_Color_r->value()));
    }
    Nsv.extract_color=extract_color;
    cv::Mat image=cv::Mat(cv::Size(61,61),CV_8UC3,extract_color);
    ui->label_Color_show->add_image(image);
}

void MainWindow::on_horizontalSlider_Color_r_valueChanged(int)
{
    Color_more();
}

void MainWindow::on_horizontalSlider_Color_g_valueChanged(int)
{
    Color_more();
}

void MainWindow::on_horizontalSlider_Color_b_valueChanged(int)
{
    Color_more();
}

void MainWindow::on_pushButton_Color_extract_clicked()
{
    if(image_backup.channels()>=3)
    {
        cv::Mat image=image_diff_color_gray(image_backup,extract_color,30);
        image_show(image);
    }
}

void MainWindow::on_pushButton_Color_scatter_clicked()
{
    if(image_backup.channels()>=3)
    {
        cv::Mat image=image_diff_color(image_backup,extract_color);
        image_show(image);
    }
}

void MainWindow::on_pushButton_Color_backup_clicked()
{
    image_show(image_backup);
}

void MainWindow::on_checkBox_Color_extract_clicked()
{
    if(ui->checkBox_Color_extract->isChecked())
    {
        Nsv.color_extract=true;
        Nsv.extract_color=extract_color;
        ui->checkBox_Color_getfromimage->setChecked(false);
        ui->groupBox_Color_extract->setEnabled(false);
    }
    else
    {
        Nsv.color_extract=false;
        Nsv.extract_color=extract_color;
        ui->groupBox_Color_extract->setEnabled(true);
    }
}

//梯度化

void MainWindow::on_pushButton_more_gradient_clicked()
{
    ui->tabWidget->setCurrentIndex(7);

    image_show(image_now);
}

void MainWindow::Grad_more()
{
    if(!ui->checkBox_Grad_colour->isChecked())
    {
        if(image_gray.empty())
        {
            on_checkBox_split_clicked();
        }
        cv::Mat image_gray_Clane=image_gray.clone();

        cv::Mat image_grad=image_Gradient(image_gray_Clane,ui->comboBox_Grad_type->currentIndex(),ui->spinBox_Grad_D->value());

        cv::Mat image_grad_thres=image_grad.clone();

        if(ui->checkBox_Grad_thres->isChecked())
        {
            image_grad_thres=image_Thresold(image_grad,true,ui->spinBox_Grad_thres_min->value(),ui->spinBox_Grad_thres_max->value());
        }

        if(ui->checkBox_Grad_clear->isChecked())
        {
            image_grad_thres=image_Stats_clear(image_grad_thres,ui->spinBox_Grad_clear_D->value());
        }

        image_show(image_grad_thres);
    }
    else
    {
        cv::Mat image_input=image_now.clone();

        cv::Mat image_grad_colour=image_Gradient_colour(image_input,
                                                        ui->comboBox_Grad_type->currentIndex(),
                                                        ui->spinBox_Grad_D->value(),
                                                        ui->checkBox_Grad_thres->isChecked(),
                                                        ui->spinBox_Grad_thres_min->value(),
                                                        ui->spinBox_Grad_thres_max->value(),
                                                        !ui->checkBox_Grad_colour_add->isChecked());

        if(ui->checkBox_Grad_clear->isChecked())
        {
            image_grad_colour=image_Stats_clear_colour(image_grad_colour,ui->spinBox_Grad_clear_D->value());
        }

        image_show(image_grad_colour);
    }

}

void MainWindow::on_pushButton_Grad_clicked()
{
    Grad_more();
}

void MainWindow::on_comboBox_Grad_type_currentIndexChanged(int arg1)
{
    if(arg1==1)
    {
        ui->spinBox_Grad_D->setEnabled(false);
    }
    else
    {
        ui->spinBox_Grad_D->setEnabled(true);
    }

    Grad_more();
}

void MainWindow::on_spinBox_Grad_D_valueChanged(int arg1)
{
    if(arg1%2==0)
    {
        ui->spinBox_Grad_D->setValue(arg1+1);
    }

    Grad_more();
}

void MainWindow::on_spinBox_Grad_thres_min_valueChanged(int)
{
     Grad_more();
}

void MainWindow::on_spinBox_Grad_thres_max_valueChanged(int)
{
     Grad_more();
}

void MainWindow::on_checkBox_Grad_colour_clicked(bool checked)
{
    ui->checkBox_Grad_colour_add->setEnabled(checked);

    ui->checkBox_Grad_colour_add->setChecked(false);

    Grad_more();
}

void MainWindow::on_checkBox_Grad_clear_clicked()
{
    if(ui->checkBox_Grad_clear->isChecked())
    {
        ui->spinBox_Grad_clear_D->setHidden(0);
        ui->label_53->setHidden(0);
    }
    else
    {
        ui->spinBox_Grad_clear_D->setHidden(1);
        ui->label_53->setHidden(1);
    }

    Grad_more();
}

void MainWindow::on_spinBox_Grad_clear_D_valueChanged(int)
{
    Grad_more();
}

void MainWindow::on_checkBox_Grad_thres_clicked()
{
    Grad_more();
}

void MainWindow::on_pushButton_showback_clicked()
{
    if(!ui->checkBox_Grad_colour->isChecked())
    {
        if(image_gray.empty())
        {
            on_checkBox_split_clicked();
        }
        cv::Mat image_gray_Clane=image_gray.clone();

        image_show(image_gray_Clane);
    }
    else
    {
        cv::Mat image_input=image_now.clone();
        image_show(image_input);
    }
}

//形态学操作

void MainWindow::Morph_more()
{
    if(image_thresold.empty())
    {
        on_horizontalSlider_thresholdsize_valueChanged(ui->horizontalSlider_thresholdsize->value());
    }
    cv::Mat image_thresold_ErDi=image_thresold_backup.clone();

    cv::Mat image_morph=image_thresold_ErDi.clone();

    int Morph_D=ui->spinBox_Morph_D->value();

    cv::Mat kernel = cv::getStructuringElement(ui->comboBox_Morph_type->currentIndex(),cv::Size(2*Morph_D+1,2*Morph_D+1),cv::Point(-1,-1));

    cv::morphologyEx(image_thresold_ErDi,image_morph,ui->comboBox_Morph_do->currentIndex(),kernel);

    image_show(image_morph);
}

void MainWindow::on_pushButton_more_morph_clicked()
{
    ui->tabWidget->setCurrentIndex(8);

    if(image_thresold.empty())
    {
        on_horizontalSlider_thresholdsize_valueChanged(ui->horizontalSlider_thresholdsize->value());
    }
    cv::Mat image_thresold_ErDi=image_thresold_backup.clone();

    image_show(image_thresold_ErDi);
}

void MainWindow::on_spinBox_Morph_D_valueChanged(int)
{
    Morph_more();
}

//自定义图像处理

void MainWindow::on_pushButton_USE_TREE_clicked()
{
//    tree->setWindowFlags(Qt::WindowStaysOnTopHint);
    tree->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    setting->exec();
}

