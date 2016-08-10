#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "player.h"
#include "race.h"
#include "klass.h"
#include "weapon.h"
#include "die.h"

using namespace std;

int main()
{
    map<std::string, int> abilities =
    {
        { "charisma", 10 },
        { "wisdom", 10 },
        { "intelligence", 10 },
        { "dexterity", 10 },
        { "strength", 19 },
        { "constitution", 10 }
    };

    Lance l = Lance();

    string a = l.getWeaponClass() == weaponClasses::simple ? "simple " : "martial ";
    string b = l.getWeaponType() == weaponTypes::melee ? "melee " : "range ";

    cout << "I'm a " << a << b << "weapon." << endl;

    Weapon lance = Lance();
    Weapon sword = Shortsword();

    Player me = Player( "Zach", new Dragonborn(), new Paladin(), abilities, 34 );
    me.setWeapon( lance );
    me.giveExperiencePoints( 34000 );

    Player contortedAboration = Player( "Azulboth the Slimy", new Dragonborn(), new Paladin(), abilities, 20 );
    contortedAboration.setWeapon( sword );

    me.attack( contortedAboration );

    cout << me.getName() << " has " << me.health << " health." << endl;
    cout << contortedAboration.getName() << " has " << contortedAboration.health << " health." << endl;

    return 0;
}
