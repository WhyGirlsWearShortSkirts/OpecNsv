/********************************************************************************
** Form generated from reading UI file 'nsv_tree.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NSV_TREE_H
#define UI_NSV_TREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <custom_tree/lattree_pushbutton.h>
#include "custom_tree/lattree_tree.h"

QT_BEGIN_NAMESPACE

class Ui_nsv_tree
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    LActCross *groupBox;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_left;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QLabel *label_runtime;
    QLabel *label_7;
    QLabel *label_6;
    LView *View_image;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_8;
    QFrame *line_2;
    QVBoxLayout *button_group;
    QFrame *line;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QFrame *line_3;
    QPushButton *pushButton;
    QFrame *line_4;
    QGroupBox *groupBox_right;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_input;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_output;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_torun;
    QPushButton *pushButton_back_tree;

    void setupUi(QDialog *nsv_tree)
    {
        if (nsv_tree->objectName().isEmpty())
            nsv_tree->setObjectName(QString::fromUtf8("nsv_tree"));
        nsv_tree->resize(1696, 971);
        nsv_tree->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(nsv_tree);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(nsv_tree);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new LActCross(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        verticalLayout->addWidget(groupBox);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, 0, -1);
        groupBox_left = new QGroupBox(tab_2);
        groupBox_left->setObjectName(QString::fromUtf8("groupBox_left"));
        groupBox_left->setStyleSheet(QString::fromUtf8("QGroupBox{border:0 pix;}"));
        verticalLayout_5 = new QVBoxLayout(groupBox_left);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 0);
        label_4 = new QLabel(groupBox_left);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_5 = new QLabel(groupBox_left);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        label_runtime = new QLabel(groupBox_left);
        label_runtime->setObjectName(QString::fromUtf8("label_runtime"));

        horizontalLayout_4->addWidget(label_runtime);

        label_7 = new QLabel(groupBox_left);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        label_6 = new QLabel(groupBox_left);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);


        verticalLayout_5->addLayout(horizontalLayout_4);

        View_image = new LView(groupBox_left);
        View_image->setObjectName(QString::fromUtf8("View_image"));
        View_image->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"border:0 pix"));

        verticalLayout_5->addWidget(View_image);


        horizontalLayout_2->addWidget(groupBox_left);

        line_5 = new QFrame(tab_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_5);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        line_2 = new QFrame(tab_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_2);

        button_group = new QVBoxLayout();
        button_group->setObjectName(QString::fromUtf8("button_group"));
        button_group->setContentsMargins(-1, 0, -1, 0);

        verticalLayout_8->addLayout(button_group);

        line = new QFrame(tab_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line);

        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(62, 0));

        verticalLayout_8->addWidget(label);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_8);

        line_3 = new QFrame(tab_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(10, 0));
        pushButton->setMaximumSize(QSize(15, 16777215));
        QFont font;
        font.setPointSize(9);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));

        horizontalLayout_2->addWidget(pushButton);

        line_4 = new QFrame(tab_2);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_4);

        groupBox_right = new QGroupBox(tab_2);
        groupBox_right->setObjectName(QString::fromUtf8("groupBox_right"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_right->sizePolicy().hasHeightForWidth());
        groupBox_right->setSizePolicy(sizePolicy1);
        groupBox_right->setMinimumSize(QSize(400, 0));
        groupBox_right->setMaximumSize(QSize(400, 16777215));
        groupBox_right->setStyleSheet(QString::fromUtf8("QGroupBox{border : 0 pix;}\n"
"QScrollArea{border : 0 pix;}"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_right);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_2 = new QLabel(groupBox_right);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_7->addWidget(label_2);

        scrollArea = new QScrollArea(groupBox_right);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 369));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_input = new QVBoxLayout();
        verticalLayout_input->setObjectName(QString::fromUtf8("verticalLayout_input"));

        verticalLayout_3->addLayout(verticalLayout_input);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_7->addWidget(scrollArea);

        label_3 = new QLabel(groupBox_right);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_7->addWidget(label_3);

        scrollArea_2 = new QScrollArea(groupBox_right);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 398, 369));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_output = new QVBoxLayout();
        verticalLayout_output->setObjectName(QString::fromUtf8("verticalLayout_output"));

        verticalLayout_4->addLayout(verticalLayout_output);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_7->addWidget(scrollArea_2);

        pushButton_torun = new QPushButton(groupBox_right);
        pushButton_torun->setObjectName(QString::fromUtf8("pushButton_torun"));
        pushButton_torun->setMinimumSize(QSize(0, 50));
        pushButton_torun->setMaximumSize(QSize(16777215, 50));

        verticalLayout_7->addWidget(pushButton_torun);

        pushButton_back_tree = new QPushButton(groupBox_right);
        pushButton_back_tree->setObjectName(QString::fromUtf8("pushButton_back_tree"));
        pushButton_back_tree->setMinimumSize(QSize(0, 50));
        pushButton_back_tree->setMaximumSize(QSize(16777215, 50));

        verticalLayout_7->addWidget(pushButton_back_tree);


        horizontalLayout_3->addLayout(verticalLayout_7);


        horizontalLayout_2->addWidget(groupBox_right);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(nsv_tree);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(nsv_tree);
    } // setupUi

    void retranslateUi(QDialog *nsv_tree)
    {
        nsv_tree->setWindowTitle(QCoreApplication::translate("nsv_tree", "Dialog", nullptr));
        groupBox->setTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("nsv_tree", "\347\256\227\346\263\225\346\255\245\351\252\244", nullptr));
        groupBox_left->setTitle(QString());
        label_4->setText(QCoreApplication::translate("nsv_tree", "\350\277\220\350\241\214\345\233\276\345\203\217\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("nsv_tree", "\350\277\220\350\241\214\346\227\266\351\227\264\357\274\232", nullptr));
        label_runtime->setText(QCoreApplication::translate("nsv_tree", "0", nullptr));
        label_7->setText(QCoreApplication::translate("nsv_tree", "ms", nullptr));
        label_6->setText(QString());
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("nsv_tree", "\342\200\226/n\342\200\226/n\342\200\226/n\342\200\226/n\342\200\226/n\342\200\226/n\342\200\226/n\342\200\226/n\342\200\226/n\342\200\226/n\342\200\226", nullptr));
        groupBox_right->setTitle(QString());
        label_2->setText(QCoreApplication::translate("nsv_tree", "\350\276\223\345\205\245\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("nsv_tree", "\350\276\223\345\207\272\357\274\232", nullptr));
        pushButton_torun->setText(QCoreApplication::translate("nsv_tree", "\345\260\235\350\257\225\350\277\220\350\241\214", nullptr));
        pushButton_back_tree->setText(QCoreApplication::translate("nsv_tree", "\350\277\224\345\233\236\346\265\201\347\250\213\346\240\221", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("nsv_tree", "\347\256\227\346\263\225\350\277\220\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nsv_tree: public Ui_nsv_tree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NSV_TREE_H
