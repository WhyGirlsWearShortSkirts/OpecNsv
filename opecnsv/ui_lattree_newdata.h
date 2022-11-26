/********************************************************************************
** Form generated from reading UI file 'lattree_newdata.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LATTREE_NEWDATA_H
#define UI_LATTREE_NEWDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LatTree_NewData
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_data_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_data_type;
    QPushButton *pushButton;
    QLabel *label_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *now_type;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *LatTree_NewData)
    {
        if (LatTree_NewData->objectName().isEmpty())
            LatTree_NewData->setObjectName(QString::fromUtf8("LatTree_NewData"));
        LatTree_NewData->resize(274, 535);
        verticalLayout_3 = new QVBoxLayout(LatTree_NewData);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(LatTree_NewData);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(label_3);

        lineEdit_data_name = new QLineEdit(LatTree_NewData);
        lineEdit_data_name->setObjectName(QString::fromUtf8("lineEdit_data_name"));

        horizontalLayout->addWidget(lineEdit_data_name);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(LatTree_NewData);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_data_type = new QLineEdit(LatTree_NewData);
        lineEdit_data_type->setObjectName(QString::fromUtf8("lineEdit_data_type"));

        horizontalLayout_2->addWidget(lineEdit_data_type);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(LatTree_NewData);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        label_5 = new QLabel(LatTree_NewData);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        scrollArea = new QScrollArea(LatTree_NewData);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 252, 399));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        now_type = new QVBoxLayout();
        now_type->setObjectName(QString::fromUtf8("now_type"));

        verticalLayout->addLayout(now_type);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(LatTree_NewData);

        QMetaObject::connectSlotsByName(LatTree_NewData);
    } // setupUi

    void retranslateUi(QDialog *LatTree_NewData)
    {
        LatTree_NewData->setWindowTitle(QCoreApplication::translate("LatTree_NewData", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("LatTree_NewData", "\345\217\230\351\207\217\345\220\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("LatTree_NewData", "\345\217\230\351\207\217\347\261\273\345\236\213\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("LatTree_NewData", "\346\263\250\345\206\214\345\217\230\351\207\217", nullptr));
        label_5->setText(QCoreApplication::translate("LatTree_NewData", "\345\275\223\345\211\215\345\267\262\345\255\230\345\234\250\347\232\204\347\261\273\345\236\213\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LatTree_NewData: public Ui_LatTree_NewData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LATTREE_NEWDATA_H
