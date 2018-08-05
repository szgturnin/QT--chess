#include "ChooseDlg.h"
#include <QVBoxLayout>

ChooseDlg::ChooseDlg(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout* lay = new QVBoxLayout(this);
    lay->addWidget(_buttons[0] = new QPushButton(QStringLiteral("人机对战")));
    lay->addWidget(_buttons[1] = new QPushButton(QStringLiteral("人人对战")));
    lay->addWidget(_buttons[2] = new QPushButton(QStringLiteral("网络对战(服务端)")));
    lay->addWidget(_buttons[3] = new QPushButton(QStringLiteral("网络对战(客户端)")));

    for(int i=0; i<4; ++i)
    {
        connect(_buttons[i], SIGNAL(clicked()), this, SLOT(slotClicked()));
    }
}

void ChooseDlg::slotClicked()
{
    QObject* s = sender();//接受鼠标点击的动作
    for(int i=0; i<4; ++i)
    {
        if(_buttons[i] == s)
        {
            this->_selected = i;
            break;
        }
    }
    accept();//传递结果给accepted
}
