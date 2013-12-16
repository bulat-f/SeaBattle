#include "hit.h"

#include <string>

Hit::Hit(Info iValue, Ship *sValue): HitInfo(iValue), destroyed(sValue)
{

}

Hit::~Hit()
{

}

bool Hit::valid()
{
    return HitInfo != INVALID;
}

bool Hit::target()
{
    return HitInfo == KILL || HitInfo == HIT;
}

ostream &operator<< (ostream &out, const Hit info)
{
    string str = "";
    switch (info.HitInfo)
    {
    case Hit::KILL:
        str = "KILL!!! =)";
        break;
    case Hit::HIT:
        str = "Hit!!! =)";
        break;
    case Hit::MISS:
        str = "Miss :-(";
        break;
    case Hit::INVALID:
        str = "Invalid. Please, try again";
        break;
    }
    out << str;
    return out;
}
