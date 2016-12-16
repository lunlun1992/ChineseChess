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

    int dis;
    bool _isreddown;
    Stone stones[32];
signals:

public slots:
};

#endif // BOARD_H
