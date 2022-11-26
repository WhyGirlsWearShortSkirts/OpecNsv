#include "widget/softencrypdialog.h"
#include "ui_softencrypdialog.h"

SoftEncrypDialog::SoftEncrypDialog(QWidget *parent):QDialog(parent),ui(new Ui::SoftEncrypDialog)
{
    ui->setupUi(this);

    init_ui();
    init_config();
}

SoftEncrypDialog::~SoftEncrypDialog()
{
    delete ui;
}

bool SoftEncrypDialog::init_config()
{
    QString filepath = "./Elic.dll";

    QFile f(filepath,this);
    f.open(QIODevice::ReadOnly);
    QString src = f.readAll();
    f.close();
    QString src2=encry.MoveToRight(src);

    QStringList config=src2.split(",");

    if(config.size()>=5)
    {
        try
        {
            m_NoUseSoft=config[0].toInt();

            m_add = config[1];//读
            m_mask = config[2];//读
            m_upset = config[3];
            m_upset_decode = config[4];

            QSettings father("HKEY_CURRENT_USER\\SOFTWARE",QSettings::NativeFormat);
            if (father.childGroups().contains("esnecil", Qt::CaseInsensitive))
            {
                QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\esnecil",QSettings::NativeFormat);
                QString add = settings.value("ADD", "error").toString();//读
                QString mask = settings.value("MASK", "error").toString();//读
                if(add=="HHHH" || mask=="HHHH")
                {
                    m_add=add;
                    m_mask=mask;
                }
            }
            else
            {
                QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\esnecil",QSettings::NativeFormat);
                settings.setValue("ADD", m_add);//写
                settings.setValue("MASK", m_mask);//写
            }

//            qDebug()<<m_add;
//            qDebug()<<m_mask;
        }
        catch (...)
        {
             m_SoftError=true;
        }

        m_ISlicense=false;
        m_filepath="./license.cxlic";

    }
    else
    {
        m_SoftError=true;
    }

    return m_SoftError;
}

void SoftEncrypDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        whereismouse=event->pos();
    }

}

void SoftEncrypDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        if(isMaximized() || isMinimized())
        {
            return;
        }
        else
        {
            if(!ui->textBrowser_cpu_Encry->underMouse()
            && !ui->textEdit_Encry->underMouse()
            && !ui->pushButton_add_Encry_data->underMouse()
            && !ui->pushButton_add_Encry_file->underMouse()
            && !ui->pushButton_clear_Encry->underMouse()
            && !ui->pushButton_close->underMouse()
            && !ui->pushButton_get_Encry_data->underMouse())
            {
                SoftEncrypDialog::move(SoftEncrypDialog::mapToGlobal(event->pos()-whereismouse));
            }
        }
    }
    event->accept();
}

void SoftEncrypDialog::init_ui()
{
    setWindowFlags(Qt::FramelessWindowHint);//隐藏边框
    setMouseTracking(1);//鼠标追踪

    ui->pushButton_clear_Encry->setHidden(true);
}

bool SoftEncrypDialog::AnalyCipherText(QString license)
{
    this->setEnabled(false);

    bool ISlicense=false;

    if(!m_SoftError)
    {
        if(m_NoUseSoft)
        {
            ISlicense=true;
        }
        else
        {
            if(license!="")
            {
                m_cpu_data=encry.GetCiphertext(m_add,m_upset);

                ui->textBrowser_cpu_Encry->setText(m_cpu_data);

                m_encry_data=encry.GetDecoDe(m_cpu_data,m_mask,m_upset_decode);

                ui->textEdit_Encry->setText(license);

//                qDebug()<<"add"<<m_add<<m_upset;
//                qDebug()<<m_cpu_data;
//                qDebug()<<m_mask<<m_upset_decode;
//                qDebug()<<m_encry_data;
//                qDebug()<<license;

                if(m_encry_data == license)
                {
                    ISlicense=true;
                }
                else
                {
                    ISlicense=false;
                }
            }
        }
    }
    else
    {
        ISlicense=false;
    }

    this->setEnabled(true);

    return ISlicense;
}

void SoftEncrypDialog::on_pushButton_get_Encry_data_clicked()
{
    this->setEnabled(false);

    m_cpu_data=encry.GetCiphertext(m_add,m_upset);

    ui->textBrowser_cpu_Encry->setText(m_cpu_data);

    this->setEnabled(true);
}

void SoftEncrypDialog::on_pushButton_add_Encry_file_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, tr("Open license file"), "../", tr("license file(*.cxlic)"));

    QFile f(filepath,this);
    f.open(QIODevice::ReadWrite);
    QString src = f.readAll();
    f.close();
    ui->textEdit_Encry->setText(src);

    QFile fp(m_filepath,this);
    fp.open(QIODevice::WriteOnly);

    m_ISlicense=AnalyCipherText(src);

    if(m_ISlicense)
    {
        char* src_= encry.StrToChar(src);
        fp.write("");
        fp.write(src_);
        ui->label_error_show->setText("license file is ready");
        ui->label_Encry_file_path->setText(filepath);
        fp.remove(filepath);
        ui->label_error_show->setStyleSheet("color:rgb(0,255,0)");
        ui->label_Encry_file_path->setStyleSheet("color:rgb(0,255,0)");
        on_pushButton_close_clicked();
    }
    else
    {
        ui->label_error_show->setText("license file is error");
        ui->label_Encry_file_path->setText("-/-/-/-");
        ui->label_error_show->setStyleSheet("color:rgb(255,0,0)");
        ui->label_Encry_file_path->setStyleSheet("color:rgb(255,0,0)");

    }

    fp.close();
}

void SoftEncrypDialog::on_pushButton_add_Encry_data_clicked()
{
    if(ui->textEdit_Encry->toPlainText()!="")
    {
        QString src=ui->textEdit_Encry->toPlainText();

        QFile fp(m_filepath,this);
        fp.open(QIODevice::WriteOnly);

        m_ISlicense=AnalyCipherText(src);

        if(m_ISlicense)
        {
            char* src_= encry.StrToChar(src);
            fp.write("");
            fp.write(src_);
            ui->label_error_show->setText("license file is ready");
            ui->label_Encry_file_path->setText(m_filepath);
            ui->label_error_show->setStyleSheet("color:rgb(0,255,0)");
            ui->label_Encry_file_path->setStyleSheet("color:rgb(0,255,0)");
            on_pushButton_close_clicked();
        }
        else
        {
            ui->label_error_show->setText("license file is error");
            ui->label_Encry_file_path->setText("-/-/-/-");
            ui->label_error_show->setStyleSheet("color:rgb(255,0,0)");
            ui->label_Encry_file_path->setStyleSheet("color:rgb(255,0,0)");
        }

        fp.close();
    }
}

bool SoftEncrypDialog::AnalyCipherTextForDefaultFile()
{
    QFile f(m_filepath,this);
    f.open(QIODevice::ReadWrite);
    QString src = f.readAll();
    f.close();
    ui->textEdit_Encry->setText(src);

    QFile fp(m_filepath,this);
    fp.open(QIODevice::ReadWrite);

    m_ISlicense=AnalyCipherText(src);

    if(m_ISlicense)
    {
        char* src_= encry.StrToChar(src);
        fp.write(src_);

        ui->label_error_show->setText("license file is ready");
        ui->label_Encry_file_path->setText(m_filepath);
        ui->label_error_show->setStyleSheet("color:rgb(0,255,0)");
        ui->label_Encry_file_path->setStyleSheet("color:rgb(0,255,0)");
        on_pushButton_close_clicked();
    }
    else
    {
        ui->label_error_show->setText("license file is error");
        ui->label_Encry_file_path->setText("-/-/-/-");
        ui->label_error_show->setStyleSheet("color:rgb(255,0,0)");
        ui->label_Encry_file_path->setStyleSheet("color:rgb(255,0,0)");
    }

    fp.close();

    return m_ISlicense;
}

void SoftEncrypDialog::on_pushButton_clear_Encry_clicked()
{
    this->setEnabled(false);

    QFile fp(m_filepath,this);
//    qDebug()<<m_filepath;
    fp.open(QIODevice::WriteOnly);
    fp.write(" ");
    fp.close();

    QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\esnecil",QSettings::NativeFormat);
    settings.setValue("ADD", "HHHH");//写
    settings.setValue("MASK", "HHHH");//写

    ui->textEdit_Encry->setText("");

    this->setEnabled(true);
}

void SoftEncrypDialog::on_pushButton_close_clicked()
{
    this->close();
}

