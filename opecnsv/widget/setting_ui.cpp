#include "setting_ui.h"
#include "ui_setting_ui.h"

#include <QProcess>
#include <QFileSystemModel>

setting_ui::setting_ui(QWidget *parent) :QDialog(parent),ui(new Ui::setting_ui)
{
    ui->setupUi(this);
    init_ui();

    init_manual();
}

setting_ui::~setting_ui()
{
    delete ui;
}

void setting_ui::init_ui()
{
    this->setWindowTitle("Setting");
    this->setWindowIcon(QIcon("titg.ico"));

    ui->tabWidget->tabBar()->hide();//隐藏tab
    ui->tabWidget->setCurrentIndex(0);
}

void setting_ui::init_manual()
{
//    QProcess* process=new QProcess(this);
    QString appPath=QCoreApplication::applicationDirPath();
    QFileSystemModel* model = new QFileSystemModel();
    model->setRootPath(appPath);
    //treeview显示文件
    QString filePath=appPath;
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(filePath));
}
