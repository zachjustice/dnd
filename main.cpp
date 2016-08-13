#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "player.h"
#include "race.h"
#include "klass.h"
#include "skills.h"
#include "weapon.h"
#include "die.h"

using namespace std;

int main()
{
    map<abilities, int> abilityScores =
    {
        { abilities::charisma, 10 },
        { abilities::wisdom, 10 },
        { abilities::intelligence, 10 },
        { abilities::dexterity, 10 },
        { abilities::strength, 10 },
        { abilities::constitution, 10 }
    };

    Lance l = Lance();

    string a = l.getWeaponClass() == weaponClasses::simple ? "simple " : "martial ";
    string b = l.getWeaponType() == weaponTypes::melee ? "melee " : "range ";

    cout << "I'm a " << a << b << "weapon." << endl;

    Weapon lance = Lance();
    Weapon sword = Shortsword();

    std::vector<skills> skillProficiencies { skills::athletics, skills::persuasion };

    Player me = Player( "Zach", new Dragonborn(), new Paladin(skillProficiencies), abilityScores );
    me.setWeapon( lance );
    me.giveExperiencePoints( 34000 );

    Player contortedAboration = Player( "Azulboth the Slimy", new Dragonborn(), new Paladin(skillProficiencies), abilityScores );
    contortedAboration.setWeapon( sword );

    me.attack( contortedAboration );

    cout << me.getName() << " has " << me.hp << " health." << endl;
    cout << contortedAboration.getName() << " has " << contortedAboration.hp << " health." << endl << endl;

    int roll = me.abilityCheck( skills::athletics );

    cout << "You roll a " << roll << "." << endl;

    return 0;
}
