#include "drinks.h"

ostream& operator<<(ostream& out, drinks* dri)
{

    out << "[" << dri->name << "($" << dri->price << "),剩余" << dri->num<<"]";
    return out;
    // TODO: 在此处插入 return 语句
}
