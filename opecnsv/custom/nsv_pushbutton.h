#ifndef NLABELCHOOSEPUSHBUTTON_H
#define NLABELCHOOSEPUSHBUTTON_H

#include <QPushButton>
#include <QButtonGroup>
#include <QPropertyAnimation>
#include <QLayout>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QString>
#include <QColor>
#include <QtDebug>

class nlabelchoosepushbutton: public QPushButton
{
    Q_OBJECT
public:

signals:

    void pushlabel(QString);

public:
    nlabelchoosepushbutton(QWidget *parent);

    nlabelchoosepushbutton(QWidget *parent,QString la,QString lb);

    nlabelchoosepushbutton(QWidget *parent,QString la,QString lb,QColor color);

    virtual void mousePressEvent(QMouseEvent * event) override;

    QString label;
};


class clickpushbutton: public QPushButton
{
    Q_OBJECT
public:

signals:

    void pushlabel(QString);

public:

    bool isClicked();

    clickpushbutton(QWidget *parent);

    clickpushbutton(QWidget *parent,bool _click);

    bool click;

    QColor color_click=QColor(100,60,240);
    QColor color_no_click=QColor(100,100,100);

private slots:

    void click_check();
};


class CusButtonGroup: public QWidget
{
    Q_OBJECT

signals:

    void choose_buttons(int);


public:
    CusButtonGroup(QWidget *parent=nullptr);

    ~CusButtonGroup();

    void setLineHeight(int lineHeight);

    void setButtonPosition(int position);

    void addButton(QPushButton *btn, int id);

    void setButtonColor(QColor color);

    void deleteLayout();

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
#endif // NLABELCHOOSEPUSHBUTTON_H
