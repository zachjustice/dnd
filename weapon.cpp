#include <string>
#include "weapon.h"

using namespace std;

string Weapon::toString()
{
    string str = "";

    switch( getWeaponClass() )
    {
        case weaponClasses::simple :
        str += "simple ";
        break;
        case weaponClasses::martial :
        str += "martial ";
        break;
    }

    switch( getWeaponType() )
    {
        case weaponTypes::melee :
        str += "melee ";
        break;
        case weaponTypes::range :
        str += "range ";
        break;
    }

    return str;
}

string Lance::toString()
{
    return Weapon::toString() + "Lance";
}