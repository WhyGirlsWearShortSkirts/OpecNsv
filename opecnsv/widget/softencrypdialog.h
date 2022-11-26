#ifndef SOFTENCRYPDIALOG_H
#define SOFTENCRYPDIALOG_H

#include <QDialog>
#include <QString>
#include <QtDebug>
#include <QFile>
#include <QFileDialog>
#include <QCloseEvent>
#include <QSettings>
#include <QMouseEvent>

#include "param/soft_encryption.h"

namespace Ui {
class SoftEncrypDialog;
}

class SoftEncrypDialog : public QDialog
{
    Q_OBJECT

signals:

    void isclose(bool);

public:
    explicit SoftEncrypDialog(QWidget *parent = nullptr);

    ~SoftEncrypDialog();

    bool AnalyCipherText(QString license);

    bool AnalyCipherTextForDefaultFile();

    bool issofterror(){return m_SoftError;};

    bool islicense(){return m_ISlicense;};

    void setadd(QString str){m_add=str;};

    void setmask(QString mask){m_mask=mask;};

    void clearEncry(){on_pushButton_clear_Encry_clicked();};

public:

    QString m_filepath="";

protected:
    bool init_config();

    void init_ui();

    void mouseMoveEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_pushButton_get_Encry_data_clicked();

    void on_pushButton_add_Encry_file_clicked();

    void on_pushButton_add_Encry_data_clicked();

    void on_pushButton_clear_Encry_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::SoftEncrypDialog *ui;

private:
    Soft_Encryption encry;

    bool m_SoftError=false;

    bool m_NoUseSoft=false;

    bool m_ISlicense=false;

    QPoint whereismouse;

    QString m_add="";

    QString m_upset="";

    QString m_mask="";

    QString m_upset_decode="";

    QString m_cpu_data="";

    QString m_encry_data="";
};

#endif // SOFTENCRYPDIALOG_H
