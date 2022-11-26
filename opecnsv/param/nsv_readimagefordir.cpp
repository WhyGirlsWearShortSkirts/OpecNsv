#include "nsv_readimagefordir.h"

QFileInfoList GetFileList(QString path)
{
    QDir dir(path);
    QStringList filters;
    filters << QString("*.bmp");
    filters << QString("*.png");
    filters << QString("*.jpg");
    dir.setNameFilters(filters);
    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
//    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

//    for(int i = 0; i != folder_list.size(); i++)
//    {
//         QString name = folder_list.at(i).absoluteFilePath();
//         QFileInfoList child_file_list = GetFileList(name);
//         file_list.append(child_file_list);
//    }

    return file_list;
}

QFileInfoList GetFileList_json(QString path)
{
    QDir dir(path);
    QStringList filters;
    filters << QString("*.json");
    dir.setNameFilters(filters);
    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
//    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

//    for(int i = 0; i != folder_list.size(); i++)
//    {
//         QString name = folder_list.at(i).absoluteFilePath();
//         QFileInfoList child_file_list = GetFileList(name);
//         file_list.append(child_file_list);
//    }

    return file_list;
}


