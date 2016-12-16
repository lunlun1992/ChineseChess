#include "board.h"

Board::Board(QWidget *parent) : QWidget(parent), dis(45)
{
    _isreddown = true;
    _selected_id = -1;
    initstones(_isreddown);
}

void Board::paintlines(QPainter &p)
{
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



void Board::paintStones(QPainter &p)
{
    for(int i = 0; i < 32; i++)
    {
        drawstone(p, i);
    }
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    p.translate(QPoint(dis, dis));
    p.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    p.save();
    paintlines(p);
    p.restore();

    p.save();
    paintStones(p);
    p.restore();
}

void Board::initstones(bool isred)
{
    if(isred)
    {
        stones[0].init(0, 0, false, JU);
        stones[1].init(0, 1, false, MA);
        stones[2].init(0, 2, false, XIANG);
        stones[3].init(0, 3, false, SHI);
        stones[4].init(0, 4, false, JIANG);
        stones[5].init(0, 5, false, SHI);
        stones[6].init(0, 6, false, XIANG);
        stones[7].init(0, 7, false, MA);
        stones[8].init(0, 8, false, JU);
        stones[9].init(2, 1, false, PAO);
        stones[10].init(2, 7, false, PAO);
        stones[11].init(3, 0, false, BING);
        stones[12].init(3, 2, false, BING);
        stones[13].init(3, 4, false, BING);
        stones[14].init(3, 6, false, BING);
        stones[15].init(3, 8, false, BING);

        stones[16].init(9, 0, true, JU);
        stones[17].init(9, 1, true, MA);
        stones[18].init(9, 2, true, XIANG);
        stones[19].init(9, 3, true, SHI);
        stones[20].init(9, 4, true, JIANG);
        stones[21].init(9, 5, true, SHI);
        stones[22].init(9, 6, true, XIANG);
        stones[23].init(9, 7, true, MA);
        stones[24].init(9, 8, true, JU);
        stones[25].init(7, 1, true, PAO);
        stones[26].init(7, 7, true, PAO);
        stones[27].init(6, 0, true, BING);
        stones[28].init(6, 2, true, BING);
        stones[29].init(6, 4, true, BING);
        stones[30].init(6, 6, true, BING);
        stones[31].init(6, 8, true, BING);
    }
    else
    {
        stones[0].init(0, 0, true, JU);
        stones[1].init(0, 1, true, MA);
        stones[2].init(0, 2, true, XIANG);
        stones[3].init(0, 3, true, SHI);
        stones[4].init(0, 4, true, JIANG);
        stones[5].init(0, 5, true, SHI);
        stones[6].init(0, 6, true, XIANG);
        stones[7].init(0, 7, true, MA);
        stones[8].init(0, 8, true, JU);
        stones[9].init(2, 1, true, PAO);
        stones[10].init(2, 7, true, PAO);
        stones[11].init(3, 0, true, BING);
        stones[12].init(3, 2, true, BING);
        stones[13].init(3, 4, true, BING);
        stones[14].init(3, 6, true, BING);
        stones[15].init(3, 8, true, BING);

        stones[16].init(9, 0, false, JU);
        stones[17].init(9, 1, false, MA);
        stones[18].init(9, 2, false, XIANG);
        stones[19].init(9, 3, false, SHI);
        stones[20].init(9, 4, false, JIANG);
        stones[21].init(9, 5, false, SHI);
        stones[22].init(9, 6, false, XIANG);
        stones[23].init(9, 7, false, MA);
        stones[24].init(9, 8, false, JU);
        stones[25].init(7, 1, false, PAO);
        stones[26].init(7, 7, false, PAO);
        stones[27].init(6, 0, false, BING);
        stones[28].init(6, 2, false, BING);
        stones[29].init(6, 4, false, BING);
        stones[30].init(6, 6, false, BING);
        stones[31].init(6, 8, false, BING);
    }
}

void Board::drawstone(QPainter &p, int id)
{
    Stone s = stones[id];
    if(s._isdead)
        return;
    QColor color;
    if(s._isred)
        color = Qt::red;
    else
        color = Qt::black;
    p.setPen(QPen(QBrush(color), 2));
    p.setFont(QFont("system", dis * 0.6, 700));
    if(_selected_id == id)
        p.setBrush(Qt::gray);
    else
        p.setBrush(Qt::yellow);
    p.drawEllipse(cell(id));
    p.drawText(cell(id), s.ChineseName(), QTextOption(Qt::AlignCenter));
}


QRect Board::cell(int id)
{
    return cell(stones[id]._row, stones[id]._col);
}

QRect Board::cell(int row, int col)
{
    return QRect(QPoint(col * dis - dis / 2, row * dis - dis / 2), QSize(dis, dis));
}
