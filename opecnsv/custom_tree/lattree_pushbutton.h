#ifndef LATTREE_PUSHBUTTON_H
#define LATTREE_PUSHBUTTON_H

#include <QScrollArea>
#include <QGroupBox>
#include <QPushButton>
#include <QToolButton>
#include <QLayout>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QImage>
#include <QPaintEvent>
#include <opencv2/opencv.hpp>

#include "custom_tree/lattree_newitem.h"
#include "param/lattree_param.h"
#include "param/nsv_image_tree.h"

//针对各类中使用的where说明。where.x指代控件所在的行数，where.y指代控件的类型，where.width指代控件的列数

//附录函数
namespace cq
{
    inline QImage cvMat2QImage(const cv::Mat& mat)
    {
        if(mat.type() == CV_8UC1)
        {
            QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
            image.setColorCount(256);
            for(int i = 0; i < 256; i++)
            {
                image.setColor(i, qRgb(i, i, i));
            }
            uchar *pSrc = mat.data;
            for(int row = 0; row < mat.rows; row ++)
            {
                uchar *pDest = image.scanLine(row);
                memcpy(pDest, pSrc, mat.cols);
                pSrc += mat.step;
            }
            return image;
        }
        else if(mat.type() == CV_8UC3)
        {
            const uchar *pSrc = (const uchar*)mat.data;
            QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
            return image.rgbSwapped();
        }
        else if(mat.type() == CV_8UC4)
        {
            const uchar *pSrc = (const uchar*)mat.data;
            QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
            return image.copy();
        }
        else
        {
            qDebug() << "ERROR: Mat could not be converted to QImage.";
            return QImage();
        }
    }

    inline cv::Mat QImage2cvMat(QImage image)
    {
        cv::Mat mat;
        switch(image.format())
        {
        case QImage::Format_ARGB32:
        case QImage::Format_RGB32:
        case QImage::Format_ARGB32_Premultiplied:
            mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
            break;
        case QImage::Format_RGB888:
            mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
            cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
            break;
        case QImage::Format_Indexed8:
            mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
            break;
        default: break;
        }
        return mat;
    }
};

class LPushButton : public QPushButton
{
    Q_OBJECT
signals:

    void isClick(int);

public:
    LPushButton(QWidget* parent,int tip);

    void setTip(int tipp){m_tip=tipp;};

    int tip(){return m_tip;};

private:

    int m_tip=999999999;

protected slots:

    void ISclick();
};

class LToolButton : public QToolButton
{
    Q_OBJECT

signals:

    void isClick(QRect);

    void isClick(QRect,int);

    void isClick(int);

public:

    LToolButton(QWidget* parent,int type,QRect where);

    LToolButton(QWidget* parent,int type);

    LToolButton(QWidget* parent,int type,QRect where,int tig);

    QRect itswhere(){return m_where;};

    int itstig(){return m_tig;};

    void setWhere(QRect point){m_where=point;};

    void setTig(int tig){m_tig=tig;};

public slots:

    void isMe(int tig);

private:

    QRect m_where=QRect(0,0,0,0);

    style_list style_this;

    int m_tig=1000000;

protected slots:

    void ISclick();
};

class LLabel : public QLabel
{
    Q_OBJECT
public:

    LLabel(QWidget* parent);

public slots:

    void sethidd();

    void addImg(QImage img);
};

class LView : public QGraphicsView
{   Q_OBJECT

public:

    LView(QWidget *parent = nullptr);

    float scene_scale(float size);

    void setImageList(std::vector<cv::Mat> list){imagelist=list;};

    void clearImageList(){imagelist.clear();};

    std::vector<cv::Mat> getImageList(){return imagelist;};

    bool LongPress_ctrl=false;

    std::vector<cv::Mat> imagelist;

    QPoint widthandheight;

    float scaleValue=1;

    float size_min_scale=0.25;

    float size_max_scale=4;

    QGraphicsScene m_scene;

    QGraphicsPixmapItem *imageshow = new QGraphicsPixmapItem();

public slots:

    void item_image(cv::Mat image, QGraphicsPixmapItem *item);

    virtual void wheelEvent(QWheelEvent *) override;

    virtual void keyPressEvent(QKeyEvent *) override;

    virtual void keyReleaseEvent(QKeyEvent *) override;

    float image_add(cv::Mat image);

    float image_add(int tig);

};

class LButtonGroup: public QWidget
{
    Q_OBJECT

signals:

    void choose_buttons(int);

public:
    LButtonGroup(QWidget *parent=nullptr);

    ~LButtonGroup();

    void setLineHeight(int lineHeight);

    void setButtonPosition(int position);

    void addButton(QPushButton *btn, int id);

    void setButtonColor(QColor color);

    void deleteLayout();

    int size(){return m_buttonLst.size();};

protected slots:

    void onvalueChanged(QVariant variant);

    virtual void paintEvent(QPaintEvent *event) override;

public slots:

    void onbuttonClicked(int index);

public:

    enum where
    {
        North,
        South,
        West,
        East,
        Grid,
    };

    int m_btnPosition;

    QButtonGroup* m_btnGroup;

    QPropertyAnimation* m_animation;

    QList<QPushButton*> m_buttonLst;

    QSize m_btnSize;

    int m_offset;

    int m_lineHeight;

    int m_curIndex;

    int m_preIndex;

    QColor m_lineColor;

};

class LDataCard : public QGroupBox
{
    Q_OBJECT

signals:

    void isClick(QRect);

    void isClick(QRect,int);

    void isClick(int);

    void data_back(data_cross);

public:

    LDataCard(QWidget* parent,QRect where,data_cross d);

    QRect itswhere(){return m_where;};

    int itstig(){return m_data.tig;};

    void setWhere(QRect point){m_where=point;};

    void setTig(int tig){m_data.tig=tig;};

public slots:

    void isMe(int tig);

private:

    QRect m_where=QRect(0,0,0,0);

    style_list style_this;

    data_cross m_data;

    QPushButton* m_main_button=new QPushButton();

    QPushButton* m_check_button=new QPushButton();

    QLabel* m_type_label=new QLabel();

    void init_show();

protected slots:

    void ISclick();

    void SetCheck();
};

class LParamCard : public QGroupBox
{
    Q_OBJECT

signals:

    void isClick(QRect,int);

    void isYou(int);

    void DataClick(QRect,int);

public:

    LParamCard(QWidget* parent,QRect where,int type,QList<param_cross> p,QList<data_cross> data_list);

    LParamCard(QWidget *parent, QRect where, int type, param_cross p, QList<data_cross> data_list);

    QRect itswhere(){return m_where;};

    void setWhere(QRect point){m_where=point;};

public slots:

    void show_this();

private:

    QRect m_where=QRect(0,0,0,0);

    style_list style_this;

    QList<param_cross> m_param;

    QList<data_cross> p_data_list;

    QVBoxLayout* item_box = new QVBoxLayout();

    LToolButton* start_ico=new LToolButton(this,0);

    void init_Compare();

    void init_Param();

    void init_Param_input();

    void init_Param_output();

    void init_Param_Type();

protected slots:

    void IcoClick();
};

#endif // LATTREE_PUSHBUTTON_H
