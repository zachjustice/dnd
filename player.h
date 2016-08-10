#pragma once

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include <map>
#include <vector>

#include "weapon.h"
#include "race.h"
#include "klass.h"
#include "die.h"

#include <iostream>
using namespace std;

const int BASE_ARMOR_CLASS = 8;

class Player
{
    public:
        Player() {};
        Player(  std::string name, Race* race, Klass* klass, std::map<std::string, int> abilities, int health );
        ~Player() { delete race; delete klass; }
        // TODO copy and move

        // Player action methods
        void attack( Player &target ) ;
        int attackRoll() ; // The result of rolling a d20 + profficiency bonus if applicable + ability modifier
        int damageRoll() ; // the result of rolling the relevant die for the current weapon + ability modifier
        // TODO movement
        // TODO cast( Spell spell, Player &target )

        // Weapon methods
        Weapon getWeapon() ;
        void setWeapon( Weapon weapon );

        // Player stat methods
        int getArmorClass() ;
        std::string getName() ;
        int getProficiencyBonus() ;

        int getLevel() ;
        int getExperiencePoints() ;
        void giveExperiencePoints( int xp );
        /* TODO add inventory */

        int health; // Should this be private?
    private:
        int getAbilityModifier( std::string ability ) ;
        bool isProficientIn( Weapon w ) ;

        Die                        d20;
        Weapon                     weapon;
        int                        experiencePoints;
        std::string                name;
        std::vector<std::string>   proficiencies;
        std::map<std::string, int> abilities;
        Race*                      race;
        Klass*                     klass;
};

#endif