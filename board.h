#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QLine>
#include <QPoint>
#include <QPen>
#include <QFont>
#include <QBrush>
#include <QRect>
#include <QSize>
#include <QDebug>
#include <QMouseEvent>
#include <cstdlib>

#include "stone.h"
class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void paintlines(QPainter &p);
    void paintStones(QPainter &p);
    void drawstone(QPainter &p, int id);
    void initstones(bool isreddown);
    void mouseReleaseEvent(QMouseEvent *ev);
    int findposid(QPoint &p);
    int findrowcolid(int row, int col);

    void move(int id, QPoint &pos);
    void move(int id, int to);
    bool clickinside(int id, QPoint &pos);

    bool canmove(int id, QPoint &pos);
    bool canmoveJU(int id, QPoint &pos);
    bool canmoveMA(int id, QPoint &pos);
    bool canmovePAO(int id, QPoint &pos);
    bool canmoveBING(int id, QPoint &pos);
    bool canmoveSHI(int id, QPoint &pos);
    bool canmoveXIANG(int id, QPoint &pos);
    bool canmoveJIANG(int id, QPoint &pos);
    bool checkTwojiang();

    QRect cell(int row, int col);
    QRect cell(int id);
    QRect cell(QPoint &p);

    int dis;
    int stonedis;
    bool _isreddown;
    bool _isredturn;
    int _selected_id;
    Stone stones[32];
signals:

public slots:
};

#endif // BOARD_H
