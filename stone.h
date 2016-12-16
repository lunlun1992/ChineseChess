#ifndef STONE_H
#define STONE_H
#include <QString>
enum StoneName
{
    JU,
    MA,
    PAO,
    BING,
    ZU,
    SHI,
    XIANG,
    JIANG,
    SHUAI
};

class Stone
{
public:
    Stone();
    ~Stone();
    void init(int r, int c, bool isred, StoneName n);
    QString ChineseName();

    int _id;
    StoneName _name;
    bool _isred;
    bool _isdead;
    int _row;
    int _col;
};

#endif // STONE_H
