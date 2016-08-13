#include "race.h"

using namespace std;

bool Race::isProficientIn( skills skill )
{
    for( skills racialSkillProficiency : skillProficiencies )
    {
        if( skill == racialSkillProficiency )
        {
            return true;
        }
    }
    return false;
}
bool Race::isProficientIn( Weapon w )
{
    for( weaponTypes weaponType : weaponTypeProficiencies )
    {
        if( w.getWeaponType() == weaponType )
        {
            return true;
        }
    }

    for( weaponClasses weaponClass : weaponClassProficiencies )
    {
        if( w.getWeaponClass() == weaponClass )
        {
            return true;
        }
    }

    for( string weaponLabel : weaponProficiencies )
    {
        if( w.getName() == weaponLabel )
        {
            return true;
        }
    }

    return false;
}

int Race::getAbilityScoreModifier( abilities ability )
{
    auto abilityScoreSearch = abilityScoreModifiers.find( ability );
    int  abilityScore = 0;

    if( abilityScoreSearch != abilityScoreModifiers.end() )
    {
        abilityScore = abilityScoreModifiers[abilityScoreSearch->first];
    }
    return abilityScore;
}

Dragonborn::Dragonborn()
{
    name = "Dragonborn";
    weaponTypeProficiencies = {};
    weaponClassProficiencies = {};
    weaponProficiencies = {};
    skillProficiencies = {};
    abilityScoreModifiers =
    {
        { abilities::charisma, 1 },
        { abilities::strength, 2 }
    };
}
