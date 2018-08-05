#ifndef STONE_H
#define STONE_H


#include <QRect>
#include <QPainter>

class Stone
{
public:
    Stone();


    enum TYPE{CHE, MA, PAO, BING, JIANG, SHI, XIANG};

    void init(int id);

    int _row;//棋子的各个属性
    int _col;
    TYPE _type;
    bool _dead;
    bool _red;
    int _id;

    QString name();

    void rotate();//this->_col，_row通过数学关系式，进行变化，达到旋转棋盘的目的
};

#endif // STONE_H
