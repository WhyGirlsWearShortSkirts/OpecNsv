/********************************************************************************
** Form generated from reading UI file 'lattree_newitem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LATTREE_NEWITEM_H
#define UI_LATTREE_NEWITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LatTree_NewItem
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_all_action;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_HowToDo;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QPushButton *pushButton_2;
    QFrame *line_7;
    QPushButton *pushButton;
    QFrame *line_8;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QFrame *line;
    QPushButton *pushButton_5;
    QFrame *line_2;
    QPushButton *pushButton_8;
    QFrame *line_3;
    QPushButton *pushButton_7;
    QFrame *line_4;
    QPushButton *pushButton_6;
    QFrame *line_5;
    QPushButton *pushButton_3;
    QFrame *line_6;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *LatTree_NewItem)
    {
        if (LatTree_NewItem->objectName().isEmpty())
            LatTree_NewItem->setObjectName(QString::fromUtf8("LatTree_NewItem"));
        LatTree_NewItem->resize(342, 632);
        horizontalLayout = new QHBoxLayout(LatTree_NewItem);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        tabWidget = new QTabWidget(LatTree_NewItem);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(150, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 148, 577));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_all_action = new QVBoxLayout();
        verticalLayout_all_action->setSpacing(10);
        verticalLayout_all_action->setObjectName(QString::fromUtf8("verticalLayout_all_action"));

        verticalLayout->addLayout(verticalLayout_all_action);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(tab);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        sizePolicy.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy);
        scrollArea_2->setMinimumSize(QSize(150, 0));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 148, 577));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_HowToDo = new QVBoxLayout();
        verticalLayout_HowToDo->setSpacing(10);
        verticalLayout_HowToDo->setObjectName(QString::fromUtf8("verticalLayout_HowToDo"));

        verticalLayout_2->addLayout(verticalLayout_HowToDo);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_2->addWidget(scrollArea_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLabel{background-color:rgba(0,0,0,0.0);}"));

        verticalLayout_3->addWidget(label);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setStrikeOut(false);
        font.setKerning(false);
        pushButton_2->setFont(font);

        verticalLayout_3->addWidget(pushButton_2);

        line_7 = new QFrame(tab_2);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_7);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setKerning(false);
        pushButton->setFont(font1);

        verticalLayout_3->addWidget(pushButton);

        line_8 = new QFrame(tab_2);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_5->addWidget(label_2);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_5->addWidget(pushButton_4);

        line = new QFrame(tab_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout_5->addWidget(pushButton_5);

        line_2 = new QFrame(tab_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        pushButton_8 = new QPushButton(tab_3);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout_5->addWidget(pushButton_8);

        line_3 = new QFrame(tab_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_3);

        pushButton_7 = new QPushButton(tab_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout_5->addWidget(pushButton_7);

        line_4 = new QFrame(tab_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_4);

        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout_5->addWidget(pushButton_6);

        line_5 = new QFrame(tab_3);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_5);

        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_5->addWidget(pushButton_3);

        line_6 = new QFrame(tab_3);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);


        verticalLayout_6->addLayout(verticalLayout_5);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(LatTree_NewItem);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LatTree_NewItem);
    } // setupUi

    void retranslateUi(QDialog *LatTree_NewItem)
    {
        LatTree_NewItem->setWindowTitle(QCoreApplication::translate("LatTree_NewItem", "Dialog", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LatTree_NewItem", "Tab 1", nullptr));
        label->setText(QCoreApplication::translate("LatTree_NewItem", "\347\273\223\346\236\204\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LatTree_NewItem", "\346\265\201\347\250\213\357\274\210\357\274\236\357\274\236\357\274\211", nullptr));
        pushButton->setText(QCoreApplication::translate("LatTree_NewItem", "\345\210\244\346\226\255\357\274\210\342\226\262\342\226\275\357\274\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("LatTree_NewItem", "Tab 2", nullptr));
        label_2->setText(QCoreApplication::translate("LatTree_NewItem", "\345\210\244\346\226\255\346\226\271\345\274\217\357\274\232", nullptr));
        pushButton_4->setText(QCoreApplication::translate("LatTree_NewItem", "\357\274\236", nullptr));
        pushButton_5->setText(QCoreApplication::translate("LatTree_NewItem", "\342\211\245", nullptr));
        pushButton_8->setText(QCoreApplication::translate("LatTree_NewItem", "\357\274\234", nullptr));
        pushButton_7->setText(QCoreApplication::translate("LatTree_NewItem", "\342\211\244", nullptr));
        pushButton_6->setText(QCoreApplication::translate("LatTree_NewItem", "\357\274\235", nullptr));
        pushButton_3->setText(QCoreApplication::translate("LatTree_NewItem", "\342\211\240", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("LatTree_NewItem", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LatTree_NewItem: public Ui_LatTree_NewItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LATTREE_NEWITEM_H
