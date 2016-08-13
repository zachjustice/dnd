#pragma once

#ifndef __RACE_H__
#define __RACE_H__

#include <string>
#include <vector>
#include <map>

#include "weapon.h"
#include "skills.h"
#include "die.h"

// only derived classes should use the race constructor
class Race
{
    public:
        virtual ~Race() {};

        Race() = default;

        /*
         * @param name the name of the race
         * @param v vector<string> of the proficiencies of this race
         */
        Race(
            std::string                name,
            std::vector<weaponTypes>   weaponTypeProficiencies,
            std::vector<weaponClasses> weaponClassProficiencies,
            std::vector<std::string>   weaponProficiencies,
            std::vector<skills>        skillProficiencies,
            std::map<abilities, int>        abilityScoreModifiers
        );

        /*
         * @return string the name of the race
         */
        std::string toString() const { return name; };

        /*
         * @param a weapon to check for racial proficiency in.
         * @return bool whether or not the race is proficient in the weapon
         */
        bool isProficientIn( Weapon w );

        /*
         * @param a skill to check for racial proficiency in.
         * @return bool whether or not the race is proficient in the skill
         */
        bool isProficientIn( skills s );

        /*
         * @desc return the ability score modifier provided by this race. Used when constructing a new player.
         * @return int the ability score modifier provided by this race
         */
        int getAbilityScoreModifier( abilities ability );

    protected:
        std::string                name;
        std::vector<weaponTypes>   weaponTypeProficiencies;
        std::vector<weaponClasses> weaponClassProficiencies;
        std::vector<std::string>   weaponProficiencies;
        std::vector<skills>        skillProficiencies;
        std::map<abilities, int>   abilityScoreModifiers;
};

class Dragonborn : public Race
{
    public:
        Dragonborn();
        ~Dragonborn() {};
};

#endif