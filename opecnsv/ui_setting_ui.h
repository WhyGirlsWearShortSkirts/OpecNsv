/********************************************************************************
** Form generated from reading UI file 'setting_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_UI_H
#define UI_SETTING_UI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setting_ui
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QTreeView *treeView;
    QWidget *tab_2;

    void setupUi(QDialog *setting_ui)
    {
        if (setting_ui->objectName().isEmpty())
            setting_ui->setObjectName(QString::fromUtf8("setting_ui"));
        setting_ui->resize(1104, 675);
        verticalLayout = new QVBoxLayout(setting_ui);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(setting_ui);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget{border :0 pix;background-color: rgba(255, 255, 255,0);}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, -1, 0);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icon/20150729102447597_easyicon_net_48.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        treeView = new QTreeView(tab);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout_2->addWidget(treeView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(setting_ui);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(setting_ui);
    } // setupUi

    void retranslateUi(QDialog *setting_ui)
    {
        setting_ui->setWindowTitle(QCoreApplication::translate("setting_ui", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("setting_ui", "\346\223\215\344\275\234\350\257\264\346\230\216\357\274\232", nullptr));
        pushButton_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("setting_ui", "\346\223\215\344\275\234\350\257\264\346\230\216", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("setting_ui", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setting_ui: public Ui_setting_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_UI_H
