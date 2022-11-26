#include "nsv_pushbutton.h"

nlabelchoosepushbutton::nlabelchoosepushbutton(QWidget *parent): QPushButton(parent)
{
    this->setStyleSheet("QPushButton{background-color:rgba(255,255,255,1);color:rgb(200,100,69);border:none;}"
                        "QPushButton:hover{background-color:rgba(255,255,255,0.5);}"
                        "QPushButton:pressed{background-color: rgba(100,100,100,1);};");
    this->setMinimumHeight(25);

}

nlabelchoosepushbutton::nlabelchoosepushbutton(QWidget *parent, QString la,QString lb): QPushButton(parent)
{
    label=la;
    this->setText(la+lb);
    this->setStyleSheet("QPushButton{background-color:rgba(0,0,0,0);}"
                        "QPushButton:hover{background-color:rgba(255,255,255,0.5);}"
                        "QPushButton:pressed{background-color: rgba(100,100,100,1);};");
    this->setMinimumHeight(25);

}

nlabelchoosepushbutton::nlabelchoosepushbutton(QWidget *parent, QString la,QString lb, QColor color): QPushButton(parent)
{
    label=la;
    this->setText(la+lb);
    this->setStyleSheet("QPushButton{background-color:rgba(255,255,255,1);"
                        "color:rgb("+QString::number(color.red(),10)+","+QString::number(color.green(),10)+","+QString::number(color.blue(),10)+");border:none;}"
                        "QPushButton:hover{background-color:rgba(255,255,255,0.5);}"
                        "QPushButton:pressed{background-color: rgba(100,100,100,1);};");
    this->setMinimumHeight(25);
}

void nlabelchoosepushbutton::mousePressEvent(QMouseEvent * event)
{
    QPushButton::mousePressEvent(event);
    emit pushlabel(label);
}


clickpushbutton::clickpushbutton(QWidget *parent): QPushButton(parent)
{
    connect(this,SIGNAL(clicked()),this,SLOT(click_check()));
    click=false;
    if(!click)
    {
        this->setStyleSheet("QPushButton{color:rgb("+QString::number(color_no_click.red(),10)+","+QString::number(color_no_click.green(),10)+","+QString::number(color_no_click.blue(),10)+")}");
    }
    else
    {
        this->setStyleSheet("color:rgb("+QString::number(color_click.red(),10)+","+QString::number(color_click.green(),10)+","+QString::number(color_click.blue(),10)+")}");
    }
}

clickpushbutton::clickpushbutton(QWidget *parent, bool _click): QPushButton(parent)
{
    connect(this,SIGNAL(clicked()),this,SLOT(click_check()));
    click=_click;
    if(!click)
    {
        this->setStyleSheet("QPushButton{color:rgb("+QString::number(color_no_click.red(),10)+","+QString::number(color_no_click.green(),10)+","+QString::number(color_no_click.blue(),10)+")}");
    }
    else
    {
        this->setStyleSheet("QPushButton{color:rgb("+QString::number(color_click.red(),10)+","+QString::number(color_click.green(),10)+","+QString::number(color_click.blue(),10)+")}");
    }
}

void clickpushbutton::click_check()
{
    if(click)
    {
        click=false;
        this->setStyleSheet("QPushButton{color:rgb("+QString::number(color_no_click.red(),10)+","+QString::number(color_no_click.green(),10)+","+QString::number(color_no_click.blue(),10)+")}");
    }
    else
    {
        click=true;
        this->setStyleSheet("QPushButton{color:rgb("+QString::number(color_click.red(),10)+","+QString::number(color_click.green(),10)+","+QString::number(color_click.blue(),10)+")}");
    }
}

bool clickpushbutton::isClicked()
{
    return click;
}


CusButtonGroup::CusButtonGroup(QWidget *parent): QWidget(parent)
{
    m_btnPosition=0;
    m_curIndex=0;
    m_preIndex=0;
    m_offset=0;
    m_lineHeight=2;
    m_lineColor=QColor(21, 156, 119);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_btnGroup = new QButtonGroup(this);
    connect(m_btnGroup, SIGNAL(buttonClicked(int)), SLOT(onbuttonClicked(int)));

    m_animation = new QPropertyAnimation(this, "");
    m_animation->setDuration(200);
    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(onvalueChanged(QVariant)));

    //默认在上边
    setButtonPosition(CusButtonGroup::North);
}

CusButtonGroup::~CusButtonGroup()
{

}

void CusButtonGroup::onvalueChanged(QVariant variant)
{
    m_offset = variant.toInt();
    update();
}

void CusButtonGroup::setLineHeight(int lineHeight)
{
    m_lineHeight = lineHeight;
}

void CusButtonGroup::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(m_lineColor);
    if (m_btnPosition == CusButtonGroup::North)
    {
        painter.drawRect(m_offset, 0, m_btnSize.width(), m_lineHeight);
    }
    else if (m_btnPosition == CusButtonGroup::South)
    {
        painter.drawRect(m_offset, this->height() - m_lineHeight, m_btnSize.width(), m_lineHeight);
    }
    else if (m_btnPosition == CusButtonGroup::West)
    {
        painter.drawRect(0, m_offset, m_lineHeight, m_btnSize.height());
    }
    else if (m_btnPosition == CusButtonGroup::East)
    {
        painter.drawRect(this->width() - m_lineHeight, m_offset, m_lineHeight, m_btnSize.height());
    }
}

void CusButtonGroup::setButtonPosition(int position)
{
    deleteLayout();
    m_btnPosition = position;
    if (position == CusButtonGroup::North)
    {
        QHBoxLayout* layout = new QHBoxLayout(this);
        layout->setContentsMargins(0, m_lineHeight, 0, 0);
        layout->setSpacing(2);
        this->setLayout(layout);
    }
    else if (position == CusButtonGroup::South)
    {
        QHBoxLayout* layout = new QHBoxLayout(this);
        layout->setContentsMargins(0, 0, 0, m_lineHeight);
        layout->setSpacing(2);
        this->setLayout(layout);
    }
    else if (position == CusButtonGroup::West)
    {
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->setContentsMargins(m_lineHeight, 0, 0, 0);
        layout->setSpacing(2);
        this->setLayout(layout);
    }
    else if (position == CusButtonGroup::East)
    {
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->setContentsMargins(0, 0, m_lineHeight, 0);
        layout->setSpacing(2);
        this->setLayout(layout);
    }
    else
    {
        Q_ASSERT(false && "no match position!");
    }
}

void CusButtonGroup::addButton(QPushButton* btn, int id)
{
    m_btnGroup->addButton(btn, id);
    m_buttonLst.append(btn);
    layout()->addWidget(btn);
    m_btnSize = btn->size();

    QString style = QString("QPushButton{color:rgb(0,0,0);background-color:rgba(255,255,255,1);border:none;}"
        "QPushButton:hover{background-color:rgba(%1, %2, %3, 40);}"
        "QPushButton:pressed, "
        "QPushButton:checked{background-color:rgba(%1, %2, %3, 80);}")
        .arg(m_lineColor.red()).arg(m_lineColor.green()).arg(m_lineColor.blue());

    btn->setStyleSheet(style);
}

void CusButtonGroup::setButtonColor(QColor color)
{
    m_lineColor = color;
}

void CusButtonGroup::onbuttonClicked(int index)
{
    m_btnGroup->button(index)->setChecked(true);
    m_preIndex = m_curIndex;
    m_curIndex = index;
    emit choose_buttons(index);
    if (m_btnPosition == CusButtonGroup::North || m_btnPosition == CusButtonGroup::South)
    {
        m_animation->setStartValue(m_preIndex * (m_btnSize.width()+2));
        m_animation->setEndValue(index * (m_btnSize.width()+2));
    }
    else if (m_btnPosition == CusButtonGroup::West || m_btnPosition == CusButtonGroup::East)
    {
        m_animation->setStartValue(m_preIndex * (m_btnSize.height()+2));
        m_animation->setEndValue(index * (m_btnSize.height()+2));
    }
    m_animation->start();
}

void CusButtonGroup::deleteLayout()
{
    //清除布局，包括布局内控件
    if (this->layout() != nullptr)
    {
        QLayoutItem *child;
        while ((child = this->layout()->takeAt(0)) != 0)
        {
            delete child->widget();
            delete child;
            child = nullptr;
        }
        m_buttonLst.clear();
        delete this->layout();
    }
}
