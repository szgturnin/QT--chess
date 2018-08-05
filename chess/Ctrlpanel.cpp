#include "Ctrlpanel.h"
#include <QGridLayout>
#include <QVBoxLayout>
CtrlPanel::CtrlPanel(QWidget *parent) : QWidget(parent)
{
    QGridLayout* grid = new QGridLayout(this);//qt的格栅布局
    QVBoxLayout* vLay = new QVBoxLayout;
    grid->setColumnStretch(0, 1);//设置行/列的伸缩空间
    grid->setColumnStretch(2, 1);
    grid->setRowStretch(0, 1);
    grid->setRowStretch(2, 1);
    grid->addLayout(vLay, 1, 1);

    vLay->addWidget(this->_back = new QPushButton("Back"));
    connect(this->_back, SIGNAL(clicked()), this, SIGNAL(sigBack()));
}
