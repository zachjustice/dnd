#include <iostream>

#include "race.h"
#include "weapon.h"

using namespace std;

bool Dragonborn::isProficientIn( Weapon w )
{
    if( w.getWeaponClass() == weaponClasses::simple || w.getWeaponClass() == weaponClasses::martial )
    {
        return true;
    }

    return false;
}
