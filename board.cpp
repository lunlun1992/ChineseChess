#include "board.h"

Board::Board(QWidget *parent) : QWidget(parent), dis(45)
{
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    p.translate(QPoint(dis, dis));

    for(int i = 0; i < 10; i++)
    {
        p.drawLine(QPoint(dis * 0, dis * i), QPoint(dis * 8, dis * i));
    }
    for(int i = 0; i < 9; i++)
    {
        p.drawLine(QPoint(dis * i, dis * 0), QPoint(dis * i, dis * 4));
        p.drawLine(QPoint(dis * i, dis * 5), QPoint(dis * i, dis * 9));
    }
    p.drawLine(QPoint(dis * 0, dis * 4), QPoint(dis * 0, dis * 5));
    p.drawLine(QPoint(dis * 8, dis * 4), QPoint(dis * 8, dis * 5));

    p.drawLine(QPoint(dis * 3, dis * 7), QPoint(dis * 5, dis * 9));
    p.drawLine(QPoint(dis * 3, dis * 9), QPoint(dis * 5, dis * 7));

    p.drawLine(QPoint(dis * 3, dis * 0), QPoint(dis * 5, dis * 2));
    p.drawLine(QPoint(dis * 3, dis * 2), QPoint(dis * 5, dis * 0));

    p.setFont(QFont("aaa", 25, 350, true));
    p.drawText(QPoint(dis * 1, dis * 4.75), "楚河");
    p.drawText(QPoint(dis * 5.3, dis * 4.75), "汉界");
}



