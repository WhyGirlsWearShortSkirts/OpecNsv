/********************************************************************************
** Form generated from reading UI file 'lattree_newnode.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LATTREE_NEWNODE_H
#define UI_LATTREE_NEWNODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LatTree_NewNode
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_5;
    QLineEdit *lineEdit_node_name;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit_node_info;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QTextEdit *textEdit_node_param;
    QPushButton *pushButton_add_node;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_now_node;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *LatTree_NewNode)
    {
        if (LatTree_NewNode->objectName().isEmpty())
            LatTree_NewNode->setObjectName(QString::fromUtf8("LatTree_NewNode"));
        LatTree_NewNode->resize(1077, 492);
        verticalLayout_5 = new QVBoxLayout(LatTree_NewNode);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(LatTree_NewNode);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(60, 0));
        label->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(label);

        label_5 = new QLabel(LatTree_NewNode);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(131, 0));
        label_5->setMaximumSize(QSize(131, 16777215));

        horizontalLayout->addWidget(label_5);

        lineEdit_node_name = new QLineEdit(LatTree_NewNode);
        lineEdit_node_name->setObjectName(QString::fromUtf8("lineEdit_node_name"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_node_name->sizePolicy().hasHeightForWidth());
        lineEdit_node_name->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_node_name);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton = new QPushButton(LatTree_NewNode);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(130, 130));
        pushButton->setMaximumSize(QSize(130, 130));
        pushButton->setIconSize(QSize(100, 100));

        horizontalLayout_5->addWidget(pushButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(LatTree_NewNode);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(label_2);

        textEdit_node_info = new QTextEdit(LatTree_NewNode);
        textEdit_node_info->setObjectName(QString::fromUtf8("textEdit_node_info"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEdit_node_info->sizePolicy().hasHeightForWidth());
        textEdit_node_info->setSizePolicy(sizePolicy2);
        textEdit_node_info->setMinimumSize(QSize(0, 60));
        textEdit_node_info->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_2->addWidget(textEdit_node_info);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(LatTree_NewNode);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(label_3);

        textEdit_node_param = new QTextEdit(LatTree_NewNode);
        textEdit_node_param->setObjectName(QString::fromUtf8("textEdit_node_param"));
        sizePolicy2.setHeightForWidth(textEdit_node_param->sizePolicy().hasHeightForWidth());
        textEdit_node_param->setSizePolicy(sizePolicy2);
        textEdit_node_param->setMinimumSize(QSize(0, 60));
        textEdit_node_param->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_3->addWidget(textEdit_node_param);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_5->addLayout(horizontalLayout_5);

        pushButton_add_node = new QPushButton(LatTree_NewNode);
        pushButton_add_node->setObjectName(QString::fromUtf8("pushButton_add_node"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_add_node->sizePolicy().hasHeightForWidth());
        pushButton_add_node->setSizePolicy(sizePolicy3);

        verticalLayout_5->addWidget(pushButton_add_node);

        line = new QFrame(LatTree_NewNode);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(LatTree_NewNode);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(label_4);

        scrollArea = new QScrollArea(LatTree_NewNode);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy4);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1055, 237));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_now_node = new QVBoxLayout();
        verticalLayout_now_node->setObjectName(QString::fromUtf8("verticalLayout_now_node"));

        verticalLayout_3->addLayout(verticalLayout_now_node);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(LatTree_NewNode);

        QMetaObject::connectSlotsByName(LatTree_NewNode);
    } // setupUi

    void retranslateUi(QDialog *LatTree_NewNode)
    {
        LatTree_NewNode->setWindowTitle(QCoreApplication::translate("LatTree_NewNode", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LatTree_NewNode", "\350\212\202\347\202\271\345\220\215\357\274\232", nullptr));
        label_5->setText(QString());
        pushButton->setText(QString());
        label_2->setText(QCoreApplication::translate("LatTree_NewNode", "\350\212\202\347\202\271\344\273\213\347\273\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("LatTree_NewNode", "\350\212\202\347\202\271\345\217\202\346\225\260\357\274\232", nullptr));
        pushButton_add_node->setText(QCoreApplication::translate("LatTree_NewNode", "\345\273\272\347\253\213\350\212\202\347\202\271", nullptr));
        label_4->setText(QCoreApplication::translate("LatTree_NewNode", "\345\267\262\345\255\230\345\234\250\350\212\202\347\202\271\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LatTree_NewNode: public Ui_LatTree_NewNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LATTREE_NEWNODE_H
