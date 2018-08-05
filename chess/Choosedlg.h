#ifndef CHOOSEDLG_H
#define CHOOSEDLG_H

#include <QDialog>
#include <QPushButton>

class ChooseDlg : public QDialog//初始化进入界面，选择对话框
{
    Q_OBJECT
public:
    explicit ChooseDlg(QWidget *parent = 0);
    QPushButton* _buttons[4];
    int _selected;
signals:

public slots:
    void slotClicked();
};

#endif // CHOOSEDLG_H
