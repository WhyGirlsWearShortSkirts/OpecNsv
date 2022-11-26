/********************************************************************************
** Form generated from reading UI file 'labels_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELS_UI_H
#define UI_LABELS_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_labels_ui
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_label;
    QPushButton *pushButton_addlabel;
    QGroupBox *groupBox_labels;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_labels;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *labels_ui)
    {
        if (labels_ui->objectName().isEmpty())
            labels_ui->setObjectName(QString::fromUtf8("labels_ui"));
        labels_ui->resize(218, 275);
        verticalLayout_2 = new QVBoxLayout(labels_ui);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_label = new QLineEdit(labels_ui);
        lineEdit_label->setObjectName(QString::fromUtf8("lineEdit_label"));
        lineEdit_label->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(lineEdit_label);

        pushButton_addlabel = new QPushButton(labels_ui);
        pushButton_addlabel->setObjectName(QString::fromUtf8("pushButton_addlabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_addlabel->sizePolicy().hasHeightForWidth());
        pushButton_addlabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_addlabel);


        verticalLayout->addLayout(horizontalLayout);

        groupBox_labels = new QGroupBox(labels_ui);
        groupBox_labels->setObjectName(QString::fromUtf8("groupBox_labels"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_labels->sizePolicy().hasHeightForWidth());
        groupBox_labels->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_labels);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_labels = new QVBoxLayout();
        verticalLayout_labels->setObjectName(QString::fromUtf8("verticalLayout_labels"));

        verticalLayout_4->addLayout(verticalLayout_labels);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox_labels);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(labels_ui);

        QMetaObject::connectSlotsByName(labels_ui);
    } // setupUi

    void retranslateUi(QDialog *labels_ui)
    {
        labels_ui->setWindowTitle(QCoreApplication::translate("labels_ui", "Dialog", nullptr));
        pushButton_addlabel->setText(QCoreApplication::translate("labels_ui", "+", nullptr));
        groupBox_labels->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class labels_ui: public Ui_labels_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELS_UI_H
