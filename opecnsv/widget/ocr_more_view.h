#ifndef OCR_MORE_VIEW_H
#define OCR_MORE_VIEW_H

#include <QDialog>
#include <QCloseEvent>
#include "param/nsv_include.h"


namespace Ui {
class Ocr_More_View;
}

class Ocr_More_View : public QDialog
{
    Q_OBJECT

signals:

    void isclose();

public:
    explicit Ocr_More_View(QWidget *parent = nullptr);

    ~Ocr_More_View();

public slots:
    void addimage(cv::Mat image);

    QList<Item_save> back_itemlist();

    cv::Mat back_image();

protected slots:
    void on_comboBox_tiggtype_currentIndexChanged(int index);

    void on_pushButton_tagging_now_type_clicked();

    void on_pushButton_tagging_type_open_clicked();

    void labels_show(QList<QString> list);

    void labels_clear();

    void nowlabels_clear();

    void nowlabels_show(QList<QString> list);

private slots:
    void on_checkBox_tigging_clicked();

    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Ocr_More_View *ui;

    CusButtonGroup* button_group = new CusButtonGroup(this);

    int tag_type=0;

    void init_tagging_type();

    void init_UI();

    void init_Conn();
};

#endif // OCR_MORE_VIEW_H
