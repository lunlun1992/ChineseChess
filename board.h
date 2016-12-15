#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QLine>
#include <QPoint>
#include <QFont>
class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);


    int dis;
signals:

public slots:
};

#endif // BOARD_H
