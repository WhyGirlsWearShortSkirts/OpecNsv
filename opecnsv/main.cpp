#include <QApplication>
#include "mainwindow.h"
#include "param/nsv_include.h"
#include "widget/softencrypdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoftEncrypDialog encry;
    encry.setWindowModality(Qt::ApplicationModal);
    encry.setModal(true);
    MainWindow w;
    if(!encry.issofterror())
    {
        if(!encry.AnalyCipherTextForDefaultFile())
        {
            encry.exec();
        }

        if(encry.islicense())
        {
            w.showMaximized();
//            w.show();
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "", "配置文件缺失 \n建议联系厂商解决");
    }
    return a.exec();
}


//for(int i=0;i<treelist.size();i++)
//{
//    param_cross p;

//    QStringList actlist=treelist[i].split("){");

//    if(actlist.size()==2)
//    {
//        QString input=actlist[0].replace("(",",");

//        QString output=actlist[1].replace("}","");

//        QStringList inputlist=input.split(",");

//        QStringList outputlist=output.split(",");

//        p.tig=inputlist[0].toInt();

//        if(p.tig<m_param_list.size())
//        {
//            p.name=m_param_list[p.tig].name;
//            p.ico=m_param_list[p.tig].ico;
//            p.intype=m_param_list[p.tig].intype;
//            p.outtype=m_param_list[p.tig].outtype;

//            if(inputlist.size()>1)
//            {
//                for(int j=1;j<inputlist.size();j++)
//                {
//                    if(inputlist[j]!="")
//                    {
//                        if(inputlist[j].toInt()-100000<m_data_list.size())
//                        {
//                            if(m_data_list[inputlist[j].toInt()-100000].type==p.intype[j-1])
//                            {
//                                p.inList.append(inputlist[j].toInt());

//                                m_data_list[inputlist[j].toInt()-100000].isUseLast=true;
//                                if(m_data_list[inputlist[j].toInt()-100000].isGiveBefore)
//                                {
//                                    if(m_data_list[inputlist[j].toInt()-100000].attr==1)
//                                    {
//                                        m_data_list[inputlist[j].toInt()-100000].attr=1;
//                                    }
//                                    else
//                                    {
//                                        m_data_list[inputlist[j].toInt()-100000].attr=3;
//                                    }
//                                }
//                                else
//                                {
//                                    m_data_list[inputlist[j].toInt()-100000].attr=1;
//                                }
//                            }
//                            else
//                            {
//                                p.inList.append(2000000);
//                            }
//                        }
//                        else
//                        {
//                            p.inList.append(1000000);
//                        }
//                    }
//                }
//            }

//            if(outputlist.size()>0)
//            {
//                for(int j=0;j<outputlist.size();j++)
//                {
//                    if(outputlist[j]!="")
//                    {
//                        if(outputlist[j].toInt()-100000<m_data_list.size())
//                        {
//                            if(m_data_list[outputlist[j].toInt()-100000].type==p.outtype[j])
//                            {
//                                p.outList.append(outputlist[j].toInt());
//                                m_data_list[outputlist[j].toInt()-100000].isGiveBefore=true;
//                                if(m_data_list[outputlist[j].toInt()-100000].attr!=1)
//                                {
//                                    m_data_list[outputlist[j].toInt()-100000].attr=2;
//                                }

//                            }
//                            else
//                            {
//                                p.outList.append(2000000);
//                            }
//                        }
//                        else
//                        {
//                            p.outList.append(1000000);
//                        }
//                    }
//                }
//            }

//            addNewItem(p,i+1);
//        }

//        if(p.tig>=200000 && p.tig-200000<m_node_list.size())
//        {
//            p.name=m_node_list[p.tig-200000].name;
//            p.ico=m_node_list[p.tig-200000].ico;
//            p.intype=m_node_list[p.tig-200000].intype;
//            p.outtype=m_node_list[p.tig-200000].outtype;

//            if(inputlist.size()>1)
//            {
//                for(int j=1;j<inputlist.size();j++)
//                {
//                    if(inputlist[j]!="")
//                    {
//                        if(inputlist[j].toInt()-100000<m_data_list.size())
//                        {
//                            if(m_data_list[inputlist[j].toInt()-100000].type==p.intype[j-1])
//                            {
//                                p.inList.append(inputlist[j].toInt());
//                                m_data_list[inputlist[j].toInt()-100000].isUseLast=true;
//                                if(m_data_list[inputlist[j].toInt()-100000].isGiveBefore)
//                                {
//                                    if(m_data_list[inputlist[j].toInt()-100000].attr==1)
//                                    {
//                                        m_data_list[inputlist[j].toInt()-100000].attr=1;
//                                    }
//                                    else
//                                    {
//                                        m_data_list[inputlist[j].toInt()-100000].attr=3;
//                                    }
//                                }
//                                else if(!m_data_list[inputlist[j].toInt()-100000].isGiveBefore)
//                                {
//                                    m_data_list[inputlist[j].toInt()-100000].attr=1;
//                                }
//                            }
//                            else
//                            {
//                                p.inList.append(2000000);
//                            }
//                        }
//                        else
//                        {
//                            p.inList.append(1000000);
//                        }
//                    }
//                }
//            }

//            if(outputlist.size()>0)
//            {
//                for(int j=0;j<outputlist.size();j++)
//                {
//                    if(outputlist[j]!="")
//                    {
//                        if(outputlist[j].toInt()-100000<m_data_list.size())
//                        {
//                            if(m_data_list[outputlist[j].toInt()-100000].type==p.outtype[j])
//                            {
//                                p.outList.append(outputlist[j].toInt());
//                                m_data_list[outputlist[j].toInt()-100000].isGiveBefore=true;
//                                m_data_list[outputlist[j].toInt()-100000].attr=2;
//                            }
//                            else
//                            {
//                                p.outList.append(2000000);
//                            }
//                        }
//                        else
//                        {
//                            p.outList.append(1000000);
//                        }
//                    }
//                }
//            }

//            addNewItem(p,i+1);
//        }
//    }
//}


//for(int i=0;i<treelist.size();i++)
//{
//    param_cross p;

//    QStringList actlist=treelist[i].split("){");

//    if(actlist.size()==2)
//    {
//        QString input=actlist[0].replace("(",",");

//        QString output=actlist[1].replace("}","");

//        QStringList inputlist=input.split(",");

//        QStringList outputlist=output.split(",");

//        p.tig=inputlist[0].toInt();

//        if(p.tig<m_param_list.size())
//        {
//            p.name=m_param_list[p.tig].name;
//            p.ico=m_param_list[p.tig].ico;
//            p.intype=m_param_list[p.tig].intype;
//            p.outtype=m_param_list[p.tig].outtype;

//            if(inputlist.size()>1)
//            {
//                for(int j=1;j<inputlist.size();j++)
//                {
//                    if(inputlist[j]!="")
//                    {
//                        if(inputlist[j].toInt()-100000<m_data_list.size())
//                        {
//                            if(m_data_list[inputlist[j].toInt()-100000].type==p.intype[j-1])
//                            {
//                                p.inList.append(inputlist[j].toInt());
//                                m_data_list[inputlist[j].toInt()-100000].isUseLast=true;
//                                if(m_data_list[inputlist[j].toInt()-100000].isGiveBefore)
//                                {
//                                    if(m_data_list[inputlist[j].toInt()-100000].attr==1)
//                                    {
//                                        m_data_list[inputlist[j].toInt()-100000].attr=1;
//                                    }
//                                    else
//                                    {
//                                        m_data_list[inputlist[j].toInt()-100000].attr=3;
//                                    }
//                                }
//                                else if(!m_data_list[inputlist[j].toInt()-100000].isGiveBefore)
//                                {
//                                    m_data_list[inputlist[j].toInt()-100000].attr=1;
//                                }
//                            }
//                            else
//                            {
//                                p.inList.append(2000000);
//                            }
//                        }
//                    }
//                }
//            }

//            if(outputlist.size()>0)
//            {
//                for(int j=0;j<outputlist.size();j++)
//                {
//                    if(outputlist[j]!="")
//                    {
//                        if(outputlist[j].toInt()-100000<m_data_list.size())
//                        {
//                            if(m_data_list[outputlist[j].toInt()-100000].type==p.outtype[j])
//                            {
//                                p.outList.append(outputlist[j].toInt());
//                                m_data_list[outputlist[j].toInt()-100000].isGiveBefore=true;
//                                m_data_list[outputlist[j].toInt()-100000].attr=2;
//                            }
//                            else
//                            {
//                                p.outList.append(2000000);
//                            }
//                        }
//                    }
//                }
//            }

//            addNewItem(p,i+1);
//        }

//        if(p.tig>=200000 && p.tig-200000<m_node_list.size())
//        {
//            p.name=m_node_list[p.tig-200000].name;
//            p.ico=m_node_list[p.tig-200000].ico;
//            p.intype=m_node_list[p.tig-200000].intype;
//            p.outtype=m_node_list[p.tig-200000].outtype;

//            if(inputlist.size()>1)
//            {
//                for(int j=1;j<inputlist.size();j++)
//                {
//                    if(inputlist[j]!="")
//                    {
//                        if(inputlist[j].toInt()-100000<m_data_list.size())
//                        {
//                            if(m_data_list[inputlist[j].toInt()-100000].type==p.intype[j-1])
//                            {
//                                p.inList.append(inputlist[j].toInt());
//                                m_data_list[inputlist[j].toInt()-100000].isUseLast=true;
//                                if(m_data_list[inputlist[j].toInt()-100000].isGiveBefore)
//                                {
//                                    if(m_data_list[inputlist[j].toInt()-100000].attr==1)
//                                    {
//                                        m_data_list[inputlist[j].toInt()-100000].attr=1;
//                                    }
//                                    else
//                                    {
//                                        m_data_list[inputlist[j].toInt()-100000].attr=3;
//                                    }
//                                }
//                                else if(!m_data_list[inputlist[j].toInt()-100000].isGiveBefore)
//                                {
//                                    m_data_list[inputlist[j].toInt()-100000].attr=1;
//                                }
//                            }
//                            else
//                            {
//                                p.inList.append(2000000);
//                            }
//                        }
//                    }
//                }
//            }

//            if(outputlist.size()>0)
//            {
//                for(int j=0;j<outputlist.size();j++)
//                {
//                    if(outputlist[j]!="")
//                    {
//                        if(outputlist[j].toInt()-100000<m_data_list.size())
//                        {
//                            if(m_data_list[outputlist[j].toInt()-100000].type==p.outtype[j])
//                            {
//                                p.outList.append(outputlist[j].toInt());
//                                m_data_list[outputlist[j].toInt()-100000].isGiveBefore=true;
//                                m_data_list[outputlist[j].toInt()-100000].attr=2;
//                            }
//                            else
//                            {
//                                p.outList.append(2000000);
//                            }
//                        }
//                    }
//                }
//            }

//            addNewItem(p,i+1);
//        }
//    }
//}
