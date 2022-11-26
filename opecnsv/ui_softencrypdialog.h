/********************************************************************************
** Form generated from reading UI file 'softencrypdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOFTENCRYPDIALOG_H
#define UI_SOFTENCRYPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SoftEncrypDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QFrame *line;
    QTextBrowser *textBrowser_cpu_Encry;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QFrame *line_2;
    QTextEdit *textEdit_Encry;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_get_Encry_data;
    QPushButton *pushButton_add_Encry_data;
    QPushButton *pushButton_add_Encry_file;
    QPushButton *pushButton_clear_Encry;
    QPushButton *pushButton_close;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_Encry_file_path;
    QFrame *line_3;
    QLabel *label_error_show;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SoftEncrypDialog)
    {
        if (SoftEncrypDialog->objectName().isEmpty())
            SoftEncrypDialog->setObjectName(QString::fromUtf8("SoftEncrypDialog"));
        SoftEncrypDialog->resize(711, 295);
        SoftEncrypDialog->setMinimumSize(QSize(0, 0));
        SoftEncrypDialog->setMaximumSize(QSize(16777215, 16777215));
        SoftEncrypDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(SoftEncrypDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(SoftEncrypDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 5));
        label_5->setMaximumSize(QSize(16777215, 5));

        verticalLayout->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        label = new QLabel(SoftEncrypDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(40, 0));
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(label);

        line = new QFrame(SoftEncrypDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout);

        textBrowser_cpu_Encry = new QTextBrowser(SoftEncrypDialog);
        textBrowser_cpu_Encry->setObjectName(QString::fromUtf8("textBrowser_cpu_Encry"));
        textBrowser_cpu_Encry->setMinimumSize(QSize(0, 80));
        textBrowser_cpu_Encry->setMaximumSize(QSize(16777215, 80));

        verticalLayout_3->addWidget(textBrowser_cpu_Encry);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 0);
        label_2 = new QLabel(SoftEncrypDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(40, 0));
        label_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_4->addWidget(label_2);

        line_2 = new QFrame(SoftEncrypDialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        textEdit_Encry = new QTextEdit(SoftEncrypDialog);
        textEdit_Encry->setObjectName(QString::fromUtf8("textEdit_Encry"));
        textEdit_Encry->setMinimumSize(QSize(0, 80));
        textEdit_Encry->setMaximumSize(QSize(16777215, 80));

        verticalLayout_2->addWidget(textEdit_Encry);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_get_Encry_data = new QPushButton(SoftEncrypDialog);
        pushButton_get_Encry_data->setObjectName(QString::fromUtf8("pushButton_get_Encry_data"));

        horizontalLayout->addWidget(pushButton_get_Encry_data);

        pushButton_add_Encry_data = new QPushButton(SoftEncrypDialog);
        pushButton_add_Encry_data->setObjectName(QString::fromUtf8("pushButton_add_Encry_data"));

        horizontalLayout->addWidget(pushButton_add_Encry_data);

        pushButton_add_Encry_file = new QPushButton(SoftEncrypDialog);
        pushButton_add_Encry_file->setObjectName(QString::fromUtf8("pushButton_add_Encry_file"));

        horizontalLayout->addWidget(pushButton_add_Encry_file);

        pushButton_clear_Encry = new QPushButton(SoftEncrypDialog);
        pushButton_clear_Encry->setObjectName(QString::fromUtf8("pushButton_clear_Encry"));

        horizontalLayout->addWidget(pushButton_clear_Encry);

        pushButton_close = new QPushButton(SoftEncrypDialog);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));

        horizontalLayout->addWidget(pushButton_close);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        label_4 = new QLabel(SoftEncrypDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(label_4);

        label_Encry_file_path = new QLabel(SoftEncrypDialog);
        label_Encry_file_path->setObjectName(QString::fromUtf8("label_Encry_file_path"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_Encry_file_path->sizePolicy().hasHeightForWidth());
        label_Encry_file_path->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_Encry_file_path);

        line_3 = new QFrame(SoftEncrypDialog);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        label_error_show = new QLabel(SoftEncrypDialog);
        label_error_show->setObjectName(QString::fromUtf8("label_error_show"));
        sizePolicy.setHeightForWidth(label_error_show->sizePolicy().hasHeightForWidth());
        label_error_show->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_error_show);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(SoftEncrypDialog);

        QMetaObject::connectSlotsByName(SoftEncrypDialog);
    } // setupUi

    void retranslateUi(QDialog *SoftEncrypDialog)
    {
        SoftEncrypDialog->setWindowTitle(QCoreApplication::translate("SoftEncrypDialog", "Dialog", nullptr));
        label_5->setText(QString());
        label->setText(QCoreApplication::translate("SoftEncrypDialog", "\346\234\254\346\234\272\347\240\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("SoftEncrypDialog", "\350\247\243\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_get_Encry_data->setText(QCoreApplication::translate("SoftEncrypDialog", "\350\216\267\345\217\226\346\234\254\346\234\272\347\240\201", nullptr));
        pushButton_add_Encry_data->setText(QCoreApplication::translate("SoftEncrypDialog", "\345\212\240\350\275\275\350\247\243\345\257\206\347\240\201", nullptr));
        pushButton_add_Encry_file->setText(QCoreApplication::translate("SoftEncrypDialog", "\345\212\240\350\275\275\350\247\243\345\257\206\346\226\207\344\273\266", nullptr));
        pushButton_clear_Encry->setText(QCoreApplication::translate("SoftEncrypDialog", "\346\270\205\351\231\244\350\256\270\345\217\257", nullptr));
        pushButton_close->setText(QCoreApplication::translate("SoftEncrypDialog", "\345\205\263\351\227\255", nullptr));
        label_4->setText(QCoreApplication::translate("SoftEncrypDialog", "\350\247\243\345\257\206\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        label_Encry_file_path->setText(QString());
        label_error_show->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SoftEncrypDialog: public Ui_SoftEncrypDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOFTENCRYPDIALOG_H
