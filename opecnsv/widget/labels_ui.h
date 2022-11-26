#ifndef LABELS_UI_H
#define LABELS_UI_H

#include <QDialog>
#include "param/nsv_include.h"
#include "custom/nsv_pushbutton.h"

namespace Ui {
class labels_ui;
}

class labels_ui : public QDialog
{
    Q_OBJECT

signals:
    void labels_updata(QString);

    void push_label(QString);

public:

    QString now_label;

    explicit labels_ui(QWidget *parent = nullptr);

    ~labels_ui();

    void addlistLabel(QList<QString> list);

    void plabel_clear();

    QList<QString> labels;

    virtual void keyPressEvent(QKeyEvent *event) override;

private slots:

    void on_pushButton_addlabel_clicked();

protected slots:

    void chooseLabel(QString label);


private:
    Ui::labels_ui *ui;
};

#endif // LABELS_UI_H






