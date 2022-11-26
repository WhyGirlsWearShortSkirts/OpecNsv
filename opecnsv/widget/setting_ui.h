#ifndef SETTING_UI_H
#define SETTING_UI_H

#include <QDialog>
#include <QTabBar>

namespace Ui {
class setting_ui;
}

class setting_ui : public QDialog
{
    Q_OBJECT

public:
    explicit setting_ui(QWidget *parent = nullptr);
    ~setting_ui();

protected:
    void init_manual();

private:
    Ui::setting_ui *ui;

    void init_ui();
};

#endif // SETTING_UI_H
