//#include <QApplication>
//#include <QGraphicsScene>
//#include <QGraphicsView>
//#include <QGraphicsRectItem>
//#include "math.h"


QMainWindow{border-image: url(:/new/prefix1/icon/background.png);}

QPushButton{background-color:rgba(0,0,0,0.5);color:rgb(255,255,255);}

QPushButton:hover{background-color:rgba(255,255,255,0.5);}

QPushButton:pressed{background-color: rgba(100,100,100,1);}

QPushButtonGroup{}

QLabel{color: rgb(255, 255, 255);}

QLineEdit{color:rgb(255,255,255);background-color: rgba(0, 0, 0,0.9);}

QCheckBox{color:rgb(255,255,255);}

QSpinBox{color:rgb(255,255,255);background-color: rgba(0, 0, 0,0.9);}

QDoubleSpinBox{color:rgb(255,255,255);background-color: rgba(0, 0, 0,0.9);}

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    QGraphicsScene scene;   // 定义一个场景，设置背景色为红色
////    scene.setBackgroundBrush(Qt::blue);
//    scene.setBackgroundBrush(Qt::)
//    scene.setStyle("border-image: url(:/new/prefix1/E:/备档/图片备档/timg (35).jpg);");

//    QPen pen;   // 定义一个画笔，设置画笔颜色和宽度
//    pen.setColor(QColor(0, 160, 230));
//    pen.setWidth(10);

//    QGraphicsRectItem *m_rectItem = new QGraphicsRectItem();   // 定义一个矩形图元
//    m_rectItem->setRect(0, 0, 80, 80);
//    m_rectItem->setPen(pen);
//    m_rectItem->setBrush(QBrush(QColor(255, 0, 255)));
//    m_rectItem->setFlag(QGraphicsItem::ItemIsMovable);

//    QGraphicsRectItem *m_rect_test = new QGraphicsRectItem();
//    m_rect_test->setRect(10,0,100,10);
//    m_rect_test->setPen(pen);
//    m_rect_test->setBrush(QBrush(QColor(100,0,0)));
//    m_rect_test->setFlag(QGraphicsItem::ItemIsMovable);

//    QGraphicsLineItem *m_lineItem = new QGraphicsLineItem();    // 定义一个直线图元
//    m_lineItem->setLine(QLineF(0, 0, 100, 100));
//    m_lineItem->setPen(pen);
//    m_lineItem->setFlag(QGraphicsItem::ItemIsMovable);

//    QGraphicsPathItem *m_pathItem = new QGraphicsPathItem();    // 定义一个路径图元
//    QPainterPath path;
//    path.moveTo(90, 50);
//    for (int i = 1; i < 5; ++i) {
//        path.lineTo(50 + 40 * cos(0.8 * i * M_PI), 50 + 40 * sin(0.8 * i * M_PI));
//    }
//    path.closeSubpath();
//    m_pathItem->setPath(path);
//    m_pathItem->setPen(pen);
//    m_pathItem->setFlag(QGraphicsItem::ItemIsMovable);

//    QGraphicsPolygonItem *m_polygonItem = new QGraphicsPolygonItem();   // 定义一个多边形图元
//    QPolygonF polygon;

//    polygon << QPointF(-100.0, -150.0) << QPointF(-120.0, 150.0)<< QPointF(320.0, 160.0) << QPointF(220.0, -140.0);
//    m_polygonItem->setPolygon(polygon);
//    m_polygonItem->setPen(pen);
//    m_polygonItem->setFlag(QGraphicsItem::ItemIsMovable);

//    scene.addItem(m_rectItem);      // 把矩形图元添加到场景
//    scene.addItem(m_rect_test);      // 把矩形图元添加到场景
//    scene.addItem(m_lineItem);      // 把直线图元添加到场景
//    scene.addItem(m_pathItem);      // 把路径图元添加到场景
//    scene.addItem(m_polygonItem);   // 把多边形图元添加到场景

//    QGraphicsView view(&scene); // 定义一个视图，并把场景添加到视图
//    view.resize(1024, 768);
//    view.show();

//    return a.exec();
//}

//#include <QApplication>
//#include <QGraphicsView>
//#include <QGraphicsScene>
//#include <QGraphicsRectItem>
//#include <QDialog>
//#include <QVBoxLayout>
//#include <QPushButton>

//class MyGraphicsView : public QGraphicsView	// 自定义视图类，实现对视图的缩放和旋转
//{
//public:
//    MyGraphicsView() {}

//public slots:
//    void zoomIn() { scale(1.2, 1.2); }
//    void zoomOut() { scale(1/1.2, 1/1.2); }
//    void rotateLeft() { rotate(-30); }
//    void rotateRight() { rotate(30); }
//};

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    QGraphicsScene scene;   // 定义一个场景，设置背景色为红色
//    scene.setBackgroundBrush(Qt::red);

//    QPen pen;   // 定义一个画笔，设置画笔颜色和宽度
//    pen.setColor(QColor(0, 160, 230));
//    pen.setWidth(10);

//    QGraphicsRectItem *m_rectItem = new QGraphicsRectItem();   // 定义一个矩形图元
//    m_rectItem->setRect(0, 0, 80, 80);
//    m_rectItem->setPen(pen);
//    m_rectItem->setBrush(QBrush(QColor(255, 255, 255)));
//    m_rectItem->setFlag(QGraphicsItem::ItemIsMovable);
//    scene.addItem(m_rectItem);      // 把矩形图元添加到场景

//    QDialog *dialog = new QDialog(nullptr, Qt::CustomizeWindowHint | Qt::WindowTitleHint);
//    dialog->setWindowOpacity(0.8);
//    dialog->setWindowTitle("operation");
//    dialog->setLayout(new QVBoxLayout);
//    QPushButton *m_zoomInBtn = new QPushButton("zoomIn");
//    QPushButton *m_zoomOutBtn = new QPushButton("zoomOut");
//    QPushButton *m_rotateLeftBtn = new QPushButton("rotateLeft");
//    QPushButton *m_rotateRightBtn = new QPushButton("rotateRight");
//    dialog->layout()->addWidget(m_zoomInBtn);
//    dialog->layout()->addWidget(m_zoomOutBtn);
//    dialog->layout()->addWidget(m_rotateLeftBtn);
//    dialog->layout()->addWidget(m_rotateRightBtn);
//    scene.addWidget(dialog);

//    MyGraphicsView view; // 定义一个视图，并把场景添加到视图
//    view.setScene(&scene);
//    view.resize(1024, 768);
//    view.show();

//    // 点击按钮实现视图的缩放和旋转
//    QObject::connect(m_zoomInBtn, &QPushButton::clicked, [&]() { view.zoomIn(); });
//    QObject::connect(m_zoomOutBtn, &QPushButton::clicked, [&]() { view.zoomOut(); });
//    QObject::connect(m_rotateLeftBtn, &QPushButton::clicked, [&]() { view.rotateLeft(); });
//    QObject::connect(m_rotateRightBtn, &QPushButton::clicked, [&]() { view.rotateRight(); });

//    return a.exec();
//}



cv::convexHull(contours[0],hulli);
cv::convexityDefects(contours[0],hulli,defects);

int max_deep=0;
cv::Point max_pointA=cv::Point(0,0);
cv::Point max_pointB=cv::Point(0,0);
cv::Point max_pointC=cv::Point(0,0);
for(unsigned long long int j=0 ;j<defects.size();j++)
{
    int a=defects[j][0];
    int b=defects[j][1];
    int c=defects[j][2];
    int d=defects[j][3];
    if(d>max_deep)
    {
        max_deep=d;
        max_pointA=contours[0][a];
        max_pointB=contours[0][b];
        max_pointC=contours[0][c];
    }
}

mean_point=cv::Point(int(stats.x+(max_pointA.x+max_pointB.x+max_pointC.x)/3),int(stats.y+(max_pointA.y+max_pointB.y+max_pointC.y)/3));



////新增树流程
//void LActCross::addNewItem(param_cross start,int col)
//{
//    QGroupBox* item_start=new QGroupBox();

//    item_start->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

//    QVBoxLayout* item_box = new QVBoxLayout();

//    item_start->setLayout(item_box);

//    item_box->setContentsMargins(9,5,9,9);

//    QLabel* direction = new QLabel();

//    if(start.tig>=200000 && start.tig<300000)
//    {
//        direction->setText("节点 |>");
//        item_start->setStyleSheet(style_this.node);
//    }
//    else
//    {
//        direction->setText("算子 |>");
//        item_start->setStyleSheet(style_this.param);
//    }

//    QFont font;
//    font.setPointSize(9);
//    direction->setFont(font);
//    direction->setMinimumHeight(15);
//    direction->setMaximumHeight(15);

//    item_box->addWidget(direction);

//    LToolButton* start_ico=new LToolButton(this,0,QRect(0,1,col,0),start.tig);

//    connect(start_ico,SIGNAL(isClick(QRect,int)),this,SLOT(showAct(QRect,int)));

//    start_ico->setText(start.name);

//    if(start.ico.isNull())
//    {
//        start.ico = QApplication::style()->standardIcon(QStyle::StandardPixmap(33));
//    }

//    start_ico->setIcon(start.ico);

//    start_ico->setIconSize(QSize(80,80));

//    start_ico->setToolTip(start_ico->text());

//    item_box->addWidget(start_ico);

//    QLabel* input = new QLabel();

//    input->setText("input:");

//    item_box->addWidget(input);

//    for(int i=0;i<start.intype.size();i++)
//    {
//        if(start.intype[i]!="")
//        {
//            LToolButton* start_input=new LToolButton(this,3,QRect(i,0,col,0));

//            connect(start_input,SIGNAL(isClick(QRect,int)),this,SLOT(showData(QRect,int)));

//            connect(this,SIGNAL(isYou(int)),start_input,SLOT(isMe(int)));

//            start_input->setToolTip(start.intype_info[i]);

//            if(i<start.inList.size())
//            {
//                if(start.inList[i]-100000<m_data_list.size())
//                {
//                    data_cross d=m_data_list[start.inList[i]-100000];
//                    start_input->setText(d.name);
//                    start_input->setTig(d.tig);
//                }
//                else
//                {
//                    start_input->setText("-- "+start.intype[i]+" --");
//                    if(start.inList[i]==2000000)
//                    {
//                        start_input->setStyleSheet(style_this.pushButton_type_error);
//                    }
//                    else
//                    {
//                        start_input->setStyleSheet(style_this.pushButton_error);
//                    }
//                }
//            }
//            else
//            {
//                start_input->setText("-- "+start.intype[i]+" --");
//                start_input->setStyleSheet(style_this.pushButton_error);
//            }

//            item_box->addWidget(start_input);
//        }
//    }

//    QLabel* output = new QLabel();

//    output->setText("output:");

//    item_box->addWidget(output);

//    for(int i=0;i<start.outtype.size();i++)
//    {
//        if(start.outtype[i]!="")
//        {
//            LToolButton* start_output=new LToolButton(this,3,QRect(i,2,col,0));

//            connect(start_output,SIGNAL(isClick(QRect,int)),this,SLOT(showData(QRect,int)));

//            connect(this,SIGNAL(isYou(int)),start_output,SLOT(isMe(int)));

//            start_output->setToolTip(start.outtype_info[i]);

//            if(i<start.outList.size())
//            {
//                if(start.outList[i]-100000<m_data_list.size())
//                {
//                    data_cross d=m_data_list[start.outList[i]-100000];
//                    start_output->setText(d.name);
//                    start_output->setTig(d.tig);
//                }
//                else
//                {
//                    start_output->setText("== "+start.outtype[i]+" ==");
//                    if(start.outList[i]==2000000)
//                    {
//                        start_output->setStyleSheet(style_this.pushButton_type_error);
//                    }
//                    else
//                    {
//                        start_output->setStyleSheet(style_this.pushButton_error);
//                    }
//                }
//            }
//            else
//            {
//                start_output->setText("== "+start.outtype[i]+" ==");
//                start_output->setStyleSheet(style_this.pushButton_error);
//            }

//            item_box->addWidget(start_output);
//        }
//    }

//    QSpacerItem* ver=new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Expanding);

//    item_box->addItem(ver);

//    m_tree_box->addWidget(item_start);
//}
