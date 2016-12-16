#ifndef STONE_H
#define STONE_H

#include <QWidget>
#include <QPainter>

enum StoneName
{
    JU,
    MA,
    PAO,
    BING,
    SHI,
    XIANG,
    JIANG,
    SHUAI
};
class stone : public QWidget
{
    Q_OBJECT
public:
    explicit stone(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void init();

    int id;
    StoneName name;
    bool isred;
    bool isdead;

signals:

public slots:
};

#endif // STONE_H
