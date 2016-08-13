#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "player.h"

using namespace std;

Player::Player( string playerName, Race* r, Klass* k, map<abilities, int> playerAbilities )
{
    name = playerName;
    abilityScores = playerAbilities;
    race = r;
    klass = k;

    d20 = Die( 20 );
    experiencePoints = 0;

    for( auto& iter : abilityScores )
    {
        auto ability = iter.first;
        auto abilityScore = iter.second;

        abilityScores[ability] += race->getAbilityScoreModifier( ability );
    }

    hp = klass->getBaseHitPointsAtFirstLevel() + getAbilityModifier( klass->getBaseHitPointsModifierAtFirstLevel() );
}

int Player::abilityCheck( skills skill )
{
    int roll = d20.roll();
    cout << "----- ability check ----" << endl;

    if( race->isProficientIn( skill ) || klass->isProficientIn( skill ) )
    {
        cout << "    prof bonus " << getProficiencyBonus() << endl;
        roll += getProficiencyBonus();
    }

    roll += getAbilityModifier( skillToAbility[skill] );
    cout << "    getAbilityModifier " << getAbilityModifier(abilities::strength) << endl;

    return roll;
}

void Player::attack( Player &target )
{
    // See if we can hit the target.
    cout << "----- attack roll ----" << endl;
    int attkRoll = attackRoll();

    if( attkRoll < target.getArmorClass() )
    {
        cout << "You rolled " << attkRoll << " which was too low to hit " << target.getName() << std::endl;
        return;
    }

    // Apply damage to target
    // TODO support for damage buffs and debuffs from both player and targets
    cout << "----- damage roll ----" << endl;
    int damage = damageRoll();
    target.hp -= damage;

    std::cout << "You hit " << target.getName() << " for " << damage << " damage." << std::endl;
    return;
}

int Player::getAbilityModifier( abilities ability )
{
    // ability modifier is based on your ability score following this pattern:
    // 6, 7 = -2
    // 8, 9 = -1
    // 10, 11 = 0
    // 12 ,13 = 1
    // 14,15 = 2   <-- subtract 10, divide by 2
    int abilityScore = abilityScores[ability];

    return ( abilityScore - 10 ) / 2;
}

int Player::getArmorClass()
{
    return BASE_ARMOR_CLASS + getAbilityModifier( abilities::dexterity );
}

// attack roll = d20 + proficiency if you are proficient in weapon + relevant ability modifier
int Player::attackRoll()
{
    int attkRoll = d20.roll();

    if( isProficientIn( weapon ) )
    {
        attkRoll += getProficiencyBonus();
        cout << "    prof bonus " << getProficiencyBonus() << endl;
    }

    string str = weapon.getWeaponType() == weaponTypes::melee ? "melee" : "ranged";

    if( weapon.getWeaponType() == weaponTypes::melee )
    {
        attkRoll += getAbilityModifier( abilities::strength );
        cout << "    getAbilityModifier " << getAbilityModifier(abilities::strength) << endl;
    }
    else if( weapon.getWeaponType() == weaponTypes::range )
    {
        attkRoll += getAbilityModifier( abilities::dexterity );
    }

    cout << "    attack roll: " << attkRoll << endl;
    return attkRoll;
}

// damage roll = relevant die based on weapon + relevant ability modifier
int Player::damageRoll()
{
    int weaponDamage = weapon.use();

    cout << "    weaponDamage " << weaponDamage << endl;

    if( weapon.getWeaponType() == weaponTypes::melee )
    {
        weaponDamage += getAbilityModifier(abilities::strength);
        cout << "    getAbilityModifier " << getAbilityModifier(abilities::strength) << endl;
    }
    else if( weapon.getWeaponType() == weaponTypes::range )
    {
        weaponDamage += getAbilityModifier(abilities::dexterity);
    }

    return weaponDamage;
}

Weapon Player::getWeapon()
{
    return weapon;
}

void Player::setWeapon( Weapon newWeapon)
{
    weapon = newWeapon;
}

string Player::getName()
{
    return name;
}

bool Player::isProficientIn( Weapon w )
{
    if( race->isProficientIn( w ) || klass->isProficientIn( w ) )
    {
        return true;
    }

    return false;
}

int Player::getProficiencyBonus()
{
    int level = getLevel();
    int proficiencyBonus;

    if( level % 4 == 0 )
    {
        proficiencyBonus = level / 4 + 1;
    }
    else
    {
        proficiencyBonus = level / 4 + 2;
    }

    return proficiencyBonus;
}

int Player::getExperiencePoints()
{
    return experiencePoints;
}

void Player::giveExperiencePoints( int xp )
{
    experiencePoints += xp;
}

int Player::getLevel()
{
    int level;

    if( experiencePoints >= 335000)
    {
        level = 20;
    }
    else if( experiencePoints >= 305000 )
    {
        level = 19;
    }
    else if( experiencePoints >= 265000 )
    {
        level = 18;
    }
    else if( experiencePoints >= 225000 )
    {
        level = 17;
    }
    else if( experiencePoints >= 195000 )
    {
        level = 16;
    }
    else if( experiencePoints >= 165000 )
    {
        level = 15;
    }
    else if( experiencePoints >= 140000 )
    {
        level = 14;
    }
    else if( experiencePoints >= 120000 )
    {
        level = 13;
    }
    else if( experiencePoints >= 100000 )
    {
        level = 12;
    }
    else if( experiencePoints >= 85000 )
    {
        level = 11;
    }
    else if( experiencePoints >= 64000 )
    {
        level = 10;
    }
    else if( experiencePoints >= 48000 )
    {
        level = 9;
    }
    else if( experiencePoints >= 34000 )
    {
        level = 8;
    }
    else if( experiencePoints >= 23000 )
    {
        level = 7;
    }
    else if( experiencePoints >= 14000 )
    {
        level = 6;
    }
    else if( experiencePoints >= 6500 )
    {
        level = 5;
    }
    else if( experiencePoints >= 2700 )
    {
        level = 4;
    }
    else if( experiencePoints >= 900 )
    {
        level = 3;
    }
    else if( experiencePoints >= 300 )
    {
        level = 2;
    }
    else
    {
        level = 1;
    }

    return level;
}
