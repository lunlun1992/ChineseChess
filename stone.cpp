#include "stone.h"

Stone::Stone()
{}

Stone::~Stone()
{}

void Stone::init(int r, int c, bool isred, StoneName n)
{
    _row = r;
    _col = c;
    _isred = isred;
    _name = n;
    _isdead = false;

}

QString Stone::ChineseName()
{
    switch(_name)
    {
    case JU:
    {
        if(_isred)
            return "车";
        else
            return "車";
    }
    case MA:
        if(_isred)
            return QString("馬");
        else
            return QString("馬");
    case PAO:
        if(_isred)
            return QString("炮");
        else
            return QString("砲");
    case BING:
        if(_isred)
            return QString("兵");
        else
            return QString("卒");
    case SHI:
        if(_isred)
            return QString("仕");
        else
            return QString("士");
        break;
    case XIANG:
        if(_isred)
            return QString("相");
        else
            return QString("象");
    case JIANG:
        if(_isred)
            return QString("帅");
        else
            return QString("将");

    }
}
