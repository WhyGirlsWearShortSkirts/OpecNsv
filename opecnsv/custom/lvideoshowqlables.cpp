#include "lvideoshowqlables.h"

LVideoshowQLables::LVideoshowQLables(QWidget *parent): QLabel(parent)
{
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    setScaledContents(true);
}

void LVideoshowQLables::add_image(QPixmap image)
{
    image_show=image;
    this->update();
}

void LVideoshowQLables::add_image(cv::Mat image)
{
    QImage qimage=cvMat2QImage(image);
    image_show=QPixmap::fromImage(qimage);
    this->update();
}

void LVideoshowQLables::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawRect(this->rect());
    painter.drawPixmap(this->rect(), image_show);
    emit image_back(image_show);
}

