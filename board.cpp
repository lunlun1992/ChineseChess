#include "board.h"

Board::Board(QWidget *parent) : QWidget(parent), dis(45), stonedis(0.8 * dis)
{
    _isreddown = true;
    _selected_id = -1;
    _isredturn = true;
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

    if(_isredturn)
    {
        p.setPen(QPen(QBrush(Qt::red), 2));
        p.drawText(QPoint(dis * 9, dis * 4), "Red Turn");
    }
    else
    {
        p.setPen(QPen(QBrush(Qt::black), 2));
        p.drawText(QPoint(dis * 9, dis * 4), "Black Turn");
    }

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
    p.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);//抗锯齿
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
    p.setFont(QFont("system", 0.8 * stonedis, 700));
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
    return QRect(QPoint(col * dis - stonedis / 2, row * dis - stonedis / 2), QSize(stonedis, stonedis));
}

QRect Board::cell(QPoint &p)
{
    int col = (p.x() + dis / 2) / dis;
    int row = (p.y() + dis / 2) / dis;
    return cell(row, col);
}

void Board::mouseReleaseEvent(QMouseEvent *ev)
{
    //TODO:redturn
    QPoint pos = ev->pos();
    qDebug() << pos;
    pos.setX(pos.x() - dis);
    pos.setY(pos.y() - dis);
    if(_selected_id == -1)//没有选择棋子
    {
        int id = findposid(pos);
        if(id != -1 && ((_isredturn && stones[id]._isred) || (!_isredturn && !stones[id]._isred)))
            _selected_id = id;
    }
    else//选择了棋子
    {
        int id = findposid(pos);
        if(id != -1 && stones[id]._isred == stones[_selected_id]._isred)
        {
            if(id == _selected_id)//选择了棋子，但是是自己，则取消
                _selected_id = -1;
            else
                _selected_id = id;//不是自己，是本方棋子，就换到那个棋子上去
        }
        else if(canmove(_selected_id, pos))//要走的位置上一定是对方的活棋子或者空地或者死棋子
        {
            if(id == -1 || stones[id]._isdead)
                move(_selected_id, pos);
            else
                move(_selected_id, id);
            _selected_id = -1;
            _isredturn = !_isredturn;
        }
    }
    if(stones[4]._isdead || stones[20]._isdead)
    {
        initstones(_isreddown);
    }
    update();
}

bool Board::canmove(int id, QPoint &pos)
{
    bool ret = false;
    switch(stones[id]._name)
    {
    case JU:
        ret = canmoveJU(id, pos);
        break;
    case MA:
        ret = canmoveMA(id, pos);
        break;
    case PAO:
        ret = canmovePAO(id, pos);
        break;
    case BING:
        ret = canmoveBING(id, pos);
        break;
    case SHI:
        ret = canmoveSHI(id, pos);
        break;
    case XIANG:
        ret = canmoveXIANG(id, pos);
        break;
    case JIANG:
        ret = canmoveJIANG(id, pos);
        break;
    }
    return ret;
}

bool Board::canmoveJU(int id, QPoint &pos)
{
    int desx = (pos.x() + dis / 2) / dis;
    int desy = (pos.y() + dis / 2) / dis;
    int srcx = stones[id]._col;
    int srcy = stones[id]._row;
    if(desx < 0 || desy < 0 || desx > 8 || desy > 9)
        return false;

    if(desx == srcx)
    {
        int mini = std::min(desy, srcy);
        int maxi = std::max(desy, srcy);
        for(int i = mini + 1; i < maxi; i++)//不能有障碍物
            if(findrowcolid(i, desx) != -1)
                return false;
        return true;
    }
    else if(desy == srcy)
    {
        int mini = std::min(desx, srcx);
        int maxi = std::max(desx, srcx);
        for(int i = mini + 1; i < maxi; i++)//不能有障碍物
            if(findrowcolid(desy, i) != -1)
                return false;
        return true;
    }
    return false;
}
bool Board::canmoveMA(int id, QPoint &pos)
{
    int desx = (pos.x() + dis / 2) / dis;
    int desy = (pos.y() + dis / 2) / dis;
    int srcx = stones[id]._col;
    int srcy = stones[id]._row;
    if(desx < 0 || desy < 0 || desx > 8 || desy > 9)
        return false;
    const int step[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
    const int block[8][2] = {{0, -1}, {-1, 0}, {-1, 0}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {0, -1}};

    for(int i = 0; i < 8; i++)
    {
        int probdesx = srcx + step[i][0];
        int probdesy = srcy + step[i][1];
        int blockx = srcx + block[i][0];
        int blocky = srcy + block[i][1];
        int id = findrowcolid(blocky, blockx);
        if(probdesx == desx && probdesy == desy && (id == -1 || stones[id]._isdead))
            return true;
    }
    return false;
}
bool Board::canmovePAO(int id, QPoint &pos)
{
    int desx = (pos.x() + dis / 2) / dis;
    int desy = (pos.y() + dis / 2) / dis;
    int srcx = stones[id]._col;
    int srcy = stones[id]._row;
    if(desx < 0 || desy < 0 || desx > 8 || desy > 9)
        return false;
    if(desx == srcx)
    {
        int mini = std::min(desy, srcy);
        int maxi = std::max(desy, srcy);
        int iblocks = 0;
        int id = findrowcolid(desy, desx);
        for(int i = mini + 1; i < maxi; i++)//不能有障碍物
            if(findrowcolid(i, desx) != -1)
                iblocks++;
        if(iblocks == 0)
        {
            if(id == -1 || stones[id]._isdead)
                return true;
            else
                return false;
        }
        else if(iblocks == 1)
        {
            if(id == -1 || stones[id]._isdead)
                return false;
            else
                return true;
        }
        else
            return false;
    }
    else if(desy == srcy)
    {
        int mini = std::min(desx, srcx);
        int maxi = std::max(desx, srcx);
        int iblocks = 0;
        int id = findrowcolid(desy, desx);
        for(int i = mini + 1; i < maxi; i++)//不能有障碍物
            if(findrowcolid(desy, i) != -1)
                iblocks++;
        if(iblocks == 0)
        {
            if(id == -1 || stones[id]._isdead)
                return true;
            else
                return false;
        }
        else if(iblocks == 1)
        {
            if(id == -1 || stones[id]._isdead)
                return false;
            else
                return true;
        }
        else
            return false;
    }
    return false;
}
bool Board::canmoveBING(int id, QPoint &pos)
{
    int desx = (pos.x() + dis / 2) / dis;
    int desy = (pos.y() + dis / 2) / dis;
    int srcx = stones[id]._col;
    int srcy = stones[id]._row;
    if(desx < 0 || desy < 0 || desx > 8 || desy > 9)
        return false;
    if(_isreddown)
    {
        if(stones[id]._isred)
        {
            if(srcy < 5)
                return (desy == srcy && (desx == srcx - 1 || desx == srcx + 1)) || (desx == srcx && desy == srcy - 1);
            else
                return (desx == srcx && desy == srcy - 1);
        }
        else
        {
            if(srcy < 5)
                return (desx == srcx && desy == srcy + 1);
            else
                return (desy == srcy && (desx == srcx - 1 || desx == srcx + 1)) || (desx == srcx && desy == srcy + 1);
        }
    }
    else
    {
        if(stones[id]._isred)
        {
            if(srcy < 5)
                return (desx == srcx && desy == srcy + 1);
            else
                return (desy == srcy && (desx == srcx - 1 || desx == srcx + 1)) || (desx == srcx && desy == srcy + 1);
        }
        else
        {
            if(srcy < 5)
                return (desy == srcy && (desx == srcx - 1 || desx == srcx + 1)) || (desx == srcx && desy == srcy - 1);
            else
                return (desx == srcx && desy == srcy - 1);
        }
    }
}
bool Board::canmoveSHI(int id, QPoint &pos)
{
    int desx = (pos.x() + dis / 2) / dis;
    int desy = (pos.y() + dis / 2) / dis;
    int srcx = stones[id]._col;
    int srcy = stones[id]._row;
    if(desx < 3 || desx > 5)
        return false;
    if(_isreddown)
    {
        if(stones[id]._isred)
        {
            return desy >= 7 && desy <= 9 && std::abs(desx - srcx) == 1 && std::abs(desy - srcy) == 1;
        }
        else
        {
            return desy >= 0 && desy <= 2 && std::abs(desx - srcx) == 1 && std::abs(desy - srcy) == 1;
        }
    }
    else
    {
        if(stones[id]._isred)
        {
            return desy >= 0 && desy <= 2 && std::abs(desx - srcx) == 1 && std::abs(desy - srcy) == 1;
        }
        else
        {
            return desy >= 7 && desy <= 9 && std::abs(desx - srcx) == 1 && std::abs(desy - srcy) == 1;
        }
    }
}
bool Board::canmoveXIANG(int id, QPoint &pos)
{
    int desx = (pos.x() + dis / 2) / dis;
    int desy = (pos.y() + dis / 2) / dis;
    int srcx = stones[id]._col;
    int srcy = stones[id]._row;
    if(desx < 0 || desx > 8 || desy < 0 || desy > 9)
        return false;
    if(_isreddown)
    {
        if(stones[id]._isred)
        {
            bool ret = desy >= 5 && std::abs(desx - srcx) == 2 && std::abs(desy - srcy) == 2;
            if(ret)
            {
                int id = findrowcolid((desy + srcy) >> 1, (desx + srcx) >> 1);
                ret &= (id == -1 || stones[id]._isdead);
            }
            return ret;
        }
        else
        {
            bool ret = desy < 5 && std::abs(desx - srcx) == 2 && std::abs(desy - srcy) == 2;
            if(ret)
            {
                int id = findrowcolid((desy + srcy) >> 1, (desx + srcx) >> 1);
                ret &= (id == -1 || stones[id]._isdead);
            }
            return ret;
        }
    }
    else
    {
        if(stones[id]._isred)
        {
            bool ret = desy < 5 && std::abs(desx - srcx) == 2 && std::abs(desy - srcy) == 2;
            if(ret)
            {
                int id = findrowcolid((desy + srcy) >> 1, (desx + srcx) >> 1);
                ret &= (id == -1 || stones[id]._isdead);
            }
            return ret;
        }
        else
        {
            bool ret = desy >= 5 && std::abs(desx - srcx) == 2 && std::abs(desy - srcy) == 2;
            if(ret)
            {
                int id = findrowcolid((desy + srcy) >> 1, (desx + srcx) >> 1);
                ret &= (id == -1 || stones[id]._isdead);
            }
            return ret;
        }
    }
}
bool Board::canmoveJIANG(int id, QPoint &pos)
{
    int desx = (pos.x() + dis / 2) / dis;
    int desy = (pos.y() + dis / 2) / dis;
    int srcx = stones[id]._col;
    int srcy = stones[id]._row;
    if(desx < 3 || desx > 5)
        return false;
    bool ret = false;
    if(_isreddown)
    {
        if(stones[id]._isred)
        {
            ret = (desy >= 7 && desy <= 9
                    && ((desx == srcx && std::abs(srcy - desy) == 1) || (desy == srcy && std::abs(srcx - desx) == 1)));
        }
        else
        {
            ret = (desy >= 0 && desy <= 2
                    && ((desx == srcx && std::abs(srcy - desy) == 1) || (desy == srcy && std::abs(srcx - desx) == 1)));
        }
    }
    else
    {
        if(stones[id]._isred)
        {
            ret = (desy >= 0 && desy <= 2
                    && ((desx == srcx && std::abs(srcy - desy) == 1) || (desy == srcy && std::abs(srcx - desx) == 1)));
        }
        else
        {
            ret = (desy >= 7 && desy <= 9
                    && ((desx == srcx && std::abs(srcy - desy) == 1) || (desy == srcy && std::abs(srcx - desx) == 1)));
        }
    }
    return ret;
}

void Board::move(int id, QPoint &p)
{
    int col = (p.x() + dis / 2) / dis;
    int row = (p.y() + dis / 2) / dis;
    stones[id]._col = col;
    stones[id]._row = row;
}

//
void Board::move(int id, int to)
{
    stones[id]._col = stones[to]._col;
    stones[id]._row = stones[to]._row;
    stones[to]._isdead = true;
    stones[to]._row = -1;
    stones[to]._col = -1;
}
int Board::findposid(QPoint &p)
{
    for(int i = 0; i < 32; i++)
    {
        if(clickinside(i, p) && !stones[i]._isdead)
            return i;
    }
    return -1;
}

bool Board::clickinside(int id, QPoint &pos)
{
    return cell(id).contains(pos);
}

int Board::findrowcolid(int row, int col)
{
    for(int i = 0; i < 32; i++)
    {
        if(!stones[i]._isdead && stones[i]._col == col && stones[i]._row == row)
        {
            return i;
        }
    }
    return -1;
}
