#ifndef BOARD_H
#define BOARD_H
#include <QFrame>
#include "Stone.h"
#include "Step.h"
#include <QVector>

class Board: public QFrame
{
    Q_OBJECT
public:
     explicit Board(QWidget *parent = 0);





    /*游戏数据*/
   Stone _s[32];//32颗棋子
   int _r;//半径
   QPoint _off;
   bool _bSide;//

   QVector<Step*> _steps;//存放step的动态数组

     /*游戏状态*/
   int _selectid;//选择的棋子ID
   bool _bRedTurn;//棋子的颜色区分
   void init(bool bRedSide);

  /*绘图 功能*/
   void paintEvent(QPaintEvent *);
   void drawPlate(QPainter& p);//绘制棋盘的边框是粗的线，内部是细的线
   void drawPlace(QPainter& p);
   void drawInitPosition(QPainter& p);
   void drawInitPosition(QPainter& p, int row, int col);
   void drawStone(QPainter& p);
   void drawStone(QPainter& p, int id);

       /*绘制坐标函数*/
   QPoint center(int row, int col);
   QPoint center(int id);
   QPoint topLeft(int row, int col);
   QPoint topLeft(int id);
   QRect cell(int row, int col);
   QRect cell(int id);

   bool getClickRowCol(QPoint pt, int& row, int& col);

  /*判断棋子，判定棋子状态的函数*/
   QString name(int id);
   bool red(int id);
   bool sameColor(int id1, int id2);
   int getStoneId(int row, int col);
   void killStone(int id);
   void reliveStone(int id);
   void moveStone(int moveid, int row, int col);
   bool isDead(int id);

    /*移动棋子*/
   void mouseReleaseEvent(QMouseEvent *);
   void click(QPoint pt);
   virtual void click(int id, int row, int col);
   void trySelectStone(int id);
   void tryMoveStone(int killid, int row, int col);
   void moveStone(int moveid, int killid, int row, int col);
   void saveStep(int moveid, int killid, int row, int col, QVector<Step*>& steps);
   void backOne();
   void back(Step* step);
   virtual void back();

/*移动棋子的规则*/
   bool canMove(int moveid, int killid, int row, int col);
   bool canMoveChe(int moveid, int killid, int row, int col);
   bool canMoveMa(int moveid, int killid, int row, int col);
   bool canMovePao(int moveid, int killid, int row, int col);
   bool canMoveBing(int moveid, int killid, int row, int col);
   bool canMoveJiang(int moveid, int killid, int row, int col);
   bool canMoveShi(int moveid, int killid, int row, int col);
   bool canMoveXiang(int moveid, int killid, int row, int col);

   bool canSelect(int id);

   /* rule helper */
   int getStoneCountAtLine(int row1, int col1, int row2, int col2);
   int relation(int row1, int col1, int row, int col);
   bool isBottomSide(int id);

signals:

public slots:
   void slotBack();

};

#endif // BOARD_H
