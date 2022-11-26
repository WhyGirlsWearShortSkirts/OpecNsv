/********************************************************************************
** Form generated from reading UI file 'ocr_more_view.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OCR_MORE_VIEW_H
#define UI_OCR_MORE_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "custom/nsv_pushbutton.h"
#include "custom/nsv_view.h"

QT_BEGIN_NAMESPACE

class Ui_Ocr_More_View
{
public:
    QHBoxLayout *horizontalLayout;
    Nshowforimageview *graphicsView;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_48;
    QHBoxLayout *horizontalLayout_40;
    QCheckBox *checkBox_tigging;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_tagging_type_open;
    QFrame *line_5;
    QComboBox *comboBox_tiggtype;
    nlabelchoosepushbutton *pushButton_tagging_now_type;
    QGroupBox *groupBox_tagging_type;
    QVBoxLayout *verticalLayout_49;
    QVBoxLayout *verticalLayout_tagg_type;
    QFrame *line_72;
    QPushButton *pushButton_clear_all;
    QFrame *line_61;
    QFrame *line_62;
    QLabel *label_8;
    QFrame *line_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_labels_show;
    QFrame *line_4;
    QGroupBox *groupBox_nowlabels;
    QVBoxLayout *verticalLayout_48;
    QVBoxLayout *verticalLayout_47;
    QLabel *label_62;
    QFrame *line_24;
    QVBoxLayout *verticalLayout_labels_now;
    QFrame *line_69;
    QSpacerItem *verticalSpacer;
    QFrame *line_48;
    QGridLayout *gridLayout_2;
    QLabel *label_34;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_43;
    QLabel *label_58;
    QLabel *label_44;
    QLabel *label_35;
    QLabel *label_45;
    QLabel *label_42;

    void setupUi(QDialog *Ocr_More_View)
    {
        if (Ocr_More_View->objectName().isEmpty())
            Ocr_More_View->setObjectName(QString::fromUtf8("Ocr_More_View"));
        Ocr_More_View->resize(1050, 708);
        horizontalLayout = new QHBoxLayout(Ocr_More_View);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new Nshowforimageview(Ocr_More_View);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        groupBox = new QGroupBox(Ocr_More_View);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(290, 0));
        groupBox->setMaximumSize(QSize(290, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(5);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setObjectName(QString::fromUtf8("horizontalLayout_48"));
        horizontalLayout_48->setContentsMargins(-1, 0, -1, -1);

        verticalLayout_10->addLayout(horizontalLayout_48);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        horizontalLayout_40->setContentsMargins(-1, 0, -1, -1);
        checkBox_tigging = new QCheckBox(groupBox);
        checkBox_tigging->setObjectName(QString::fromUtf8("checkBox_tigging"));
        checkBox_tigging->setMinimumSize(QSize(0, 20));

        horizontalLayout_40->addWidget(checkBox_tigging);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_40->addItem(horizontalSpacer_7);

        pushButton_tagging_type_open = new QPushButton(groupBox);
        pushButton_tagging_type_open->setObjectName(QString::fromUtf8("pushButton_tagging_type_open"));
        pushButton_tagging_type_open->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        pushButton_tagging_type_open->setFont(font);
        pushButton_tagging_type_open->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgba(255, 255, 255,0);\n"
""));

        horizontalLayout_40->addWidget(pushButton_tagging_type_open);


        verticalLayout_10->addLayout(horizontalLayout_40);

        line_5 = new QFrame(groupBox);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_5);

        comboBox_tiggtype = new QComboBox(groupBox);
        comboBox_tiggtype->addItem(QString());
        comboBox_tiggtype->addItem(QString());
        comboBox_tiggtype->addItem(QString());
        comboBox_tiggtype->addItem(QString());
        comboBox_tiggtype->addItem(QString());
        comboBox_tiggtype->setObjectName(QString::fromUtf8("comboBox_tiggtype"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_tiggtype->sizePolicy().hasHeightForWidth());
        comboBox_tiggtype->setSizePolicy(sizePolicy);

        verticalLayout_10->addWidget(comboBox_tiggtype);

        pushButton_tagging_now_type = new nlabelchoosepushbutton(groupBox);
        pushButton_tagging_now_type->setObjectName(QString::fromUtf8("pushButton_tagging_now_type"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_tagging_now_type->sizePolicy().hasHeightForWidth());
        pushButton_tagging_now_type->setSizePolicy(sizePolicy1);
        pushButton_tagging_now_type->setMinimumSize(QSize(0, 25));
        pushButton_tagging_now_type->setMaximumSize(QSize(16777215, 25));

        verticalLayout_10->addWidget(pushButton_tagging_now_type);

        groupBox_tagging_type = new QGroupBox(groupBox);
        groupBox_tagging_type->setObjectName(QString::fromUtf8("groupBox_tagging_type"));
        verticalLayout_49 = new QVBoxLayout(groupBox_tagging_type);
        verticalLayout_49->setObjectName(QString::fromUtf8("verticalLayout_49"));
        verticalLayout_49->setContentsMargins(0, 0, 0, 0);
        verticalLayout_tagg_type = new QVBoxLayout();
        verticalLayout_tagg_type->setObjectName(QString::fromUtf8("verticalLayout_tagg_type"));
        verticalLayout_tagg_type->setContentsMargins(-1, 0, -1, 0);

        verticalLayout_49->addLayout(verticalLayout_tagg_type);


        verticalLayout_10->addWidget(groupBox_tagging_type);

        line_72 = new QFrame(groupBox);
        line_72->setObjectName(QString::fromUtf8("line_72"));
        line_72->setFrameShape(QFrame::HLine);
        line_72->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_72);

        pushButton_clear_all = new QPushButton(groupBox);
        pushButton_clear_all->setObjectName(QString::fromUtf8("pushButton_clear_all"));
        pushButton_clear_all->setMinimumSize(QSize(0, 30));
        pushButton_clear_all->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_10->addWidget(pushButton_clear_all);

        line_61 = new QFrame(groupBox);
        line_61->setObjectName(QString::fromUtf8("line_61"));
        line_61->setFrameShape(QFrame::HLine);
        line_61->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_61);

        line_62 = new QFrame(groupBox);
        line_62->setObjectName(QString::fromUtf8("line_62"));
        line_62->setFrameShape(QFrame::HLine);
        line_62->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_62);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_10->addWidget(label_8);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_3);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMinimumSize(QSize(0, 0));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));
        verticalLayout_12 = new QVBoxLayout(groupBox_2);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_labels_show = new QVBoxLayout();
        verticalLayout_labels_show->setSpacing(2);
        verticalLayout_labels_show->setObjectName(QString::fromUtf8("verticalLayout_labels_show"));
        verticalLayout_labels_show->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_12->addLayout(verticalLayout_labels_show);


        verticalLayout_10->addWidget(groupBox_2);

        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_4);

        groupBox_nowlabels = new QGroupBox(groupBox);
        groupBox_nowlabels->setObjectName(QString::fromUtf8("groupBox_nowlabels"));
        groupBox_nowlabels->setMinimumSize(QSize(0, 0));
        groupBox_nowlabels->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:0px solid #222;\n"
"background-color: rgba(0, 0, 0, 0);\n"
"}"));
        verticalLayout_48 = new QVBoxLayout(groupBox_nowlabels);
        verticalLayout_48->setObjectName(QString::fromUtf8("verticalLayout_48"));
        verticalLayout_48->setContentsMargins(0, 0, 0, 0);
        verticalLayout_47 = new QVBoxLayout();
        verticalLayout_47->setObjectName(QString::fromUtf8("verticalLayout_47"));
        label_62 = new QLabel(groupBox_nowlabels);
        label_62->setObjectName(QString::fromUtf8("label_62"));

        verticalLayout_47->addWidget(label_62);

        line_24 = new QFrame(groupBox_nowlabels);
        line_24->setObjectName(QString::fromUtf8("line_24"));
        line_24->setFrameShape(QFrame::HLine);
        line_24->setFrameShadow(QFrame::Sunken);

        verticalLayout_47->addWidget(line_24);

        verticalLayout_labels_now = new QVBoxLayout();
        verticalLayout_labels_now->setSpacing(2);
        verticalLayout_labels_now->setObjectName(QString::fromUtf8("verticalLayout_labels_now"));
        verticalLayout_labels_now->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_47->addLayout(verticalLayout_labels_now);

        line_69 = new QFrame(groupBox_nowlabels);
        line_69->setObjectName(QString::fromUtf8("line_69"));
        line_69->setFrameShape(QFrame::HLine);
        line_69->setFrameShadow(QFrame::Sunken);

        verticalLayout_47->addWidget(line_69);


        verticalLayout_48->addLayout(verticalLayout_47);


        verticalLayout_10->addWidget(groupBox_nowlabels);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);

        line_48 = new QFrame(groupBox);
        line_48->setObjectName(QString::fromUtf8("line_48"));
        line_48->setFrameShape(QFrame::HLine);
        line_48->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_48);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_34 = new QLabel(groupBox);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        QFont font1;
        font1.setPointSize(7);
        label_34->setFont(font1);
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(118, 118, 118);"));
        label_34->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_34, 2, 0, 1, 1);

        label_40 = new QLabel(groupBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setFont(font1);
        label_40->setStyleSheet(QString::fromUtf8("color: rgb(118, 118, 118);"));
        label_40->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_40, 1, 1, 1, 1);

        label_41 = new QLabel(groupBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setFont(font1);
        label_41->setStyleSheet(QString::fromUtf8("color: rgb(118, 118, 118);"));
        label_41->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_41, 0, 0, 1, 1);

        label_43 = new QLabel(groupBox);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font1);
        label_43->setStyleSheet(QString::fromUtf8("color: rgb(118, 118, 118);"));
        label_43->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_43, 1, 2, 1, 1);

        label_58 = new QLabel(groupBox);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setFont(font1);
        label_58->setStyleSheet(QString::fromUtf8("color: rgb(118, 118, 118);"));
        label_58->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_58, 0, 1, 1, 1);

        label_44 = new QLabel(groupBox);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font1);
        label_44->setStyleSheet(QString::fromUtf8("color: rgb(118, 118, 118);"));
        label_44->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_44, 2, 1, 1, 1);

        label_35 = new QLabel(groupBox);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setFont(font1);
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(118, 118, 118);"));
        label_35->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_35, 1, 0, 1, 1);

        label_45 = new QLabel(groupBox);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font1);
        label_45->setStyleSheet(QString::fromUtf8("color: rgb(118, 118, 118);"));
        label_45->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_45, 2, 2, 1, 1);

        label_42 = new QLabel(groupBox);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font1);
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(118, 118, 118);"));
        label_42->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_42, 0, 2, 1, 1);


        verticalLayout_10->addLayout(gridLayout_2);


        verticalLayout_2->addLayout(verticalLayout_10);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(Ocr_More_View);

        QMetaObject::connectSlotsByName(Ocr_More_View);
    } // setupUi

    void retranslateUi(QDialog *Ocr_More_View)
    {
        Ocr_More_View->setWindowTitle(QCoreApplication::translate("Ocr_More_View", "Dialog", nullptr));
        groupBox->setTitle(QString());
        checkBox_tigging->setText(QCoreApplication::translate("Ocr_More_View", "\346\240\207\346\263\250(S)", nullptr));
        pushButton_tagging_type_open->setText(QCoreApplication::translate("Ocr_More_View", "\346\240\207\346\263\250\346\226\271\345\274\217\357\274\232\342\227\243 ", nullptr));
        comboBox_tiggtype->setItemText(0, QCoreApplication::translate("Ocr_More_View", "\345\244\232\350\276\271\345\275\242", nullptr));
        comboBox_tiggtype->setItemText(1, QCoreApplication::translate("Ocr_More_View", "\347\237\251\345\275\242", nullptr));
        comboBox_tiggtype->setItemText(2, QCoreApplication::translate("Ocr_More_View", "\345\234\206\345\244\264\347\224\273\347\254\224", nullptr));
        comboBox_tiggtype->setItemText(3, QCoreApplication::translate("Ocr_More_View", "\346\226\271\345\244\264\347\224\273\347\254\224", nullptr));
        comboBox_tiggtype->setItemText(4, QCoreApplication::translate("Ocr_More_View", "\345\214\272\345\237\237\350\222\231\347\211\210", nullptr));

        pushButton_tagging_now_type->setText(QCoreApplication::translate("Ocr_More_View", "\345\244\232\350\276\271\345\275\242", nullptr));
        groupBox_tagging_type->setTitle(QString());
        pushButton_clear_all->setText(QCoreApplication::translate("Ocr_More_View", "\346\270\205\347\251\272\346\240\207\346\263\250(R)", nullptr));
        label_8->setText(QCoreApplication::translate("Ocr_More_View", "\346\240\207\347\255\276\345\210\227\350\241\250\357\274\232", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_nowlabels->setTitle(QString());
        label_62->setText(QCoreApplication::translate("Ocr_More_View", "\345\275\223\345\211\215\346\240\207\347\255\276\357\274\232", nullptr));
        label_34->setText(QCoreApplication::translate("Ocr_More_View", "\345\210\240\351\231\244(Q)", nullptr));
        label_40->setText(QCoreApplication::translate("Ocr_More_View", "\347\262\230\350\264\264(ctrl+V)", nullptr));
        label_41->setText(QCoreApplication::translate("Ocr_More_View", "\346\222\244\345\233\236(ctrl+Z)", nullptr));
        label_43->setText(QCoreApplication::translate("Ocr_More_View", "\344\270\213(\342\206\223)", nullptr));
        label_58->setText(QCoreApplication::translate("Ocr_More_View", "\346\201\242\345\244\215(ctrl+Y)", nullptr));
        label_44->setText(QCoreApplication::translate("Ocr_More_View", "\345\267\246(\342\206\220)", nullptr));
        label_35->setText(QCoreApplication::translate("Ocr_More_View", "\345\244\215\345\210\266(ctrl+C)", nullptr));
        label_45->setText(QCoreApplication::translate("Ocr_More_View", "\345\217\263(\342\206\222)", nullptr));
        label_42->setText(QCoreApplication::translate("Ocr_More_View", "\344\270\212(\342\206\221)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ocr_More_View: public Ui_Ocr_More_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OCR_MORE_VIEW_H
