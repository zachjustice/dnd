#pragma once

#ifndef __KLASS_H__
#define __KLASS_H__

#include <string>
#include "weapon.h"
#include "skills.h"
#include "die.h"

//enum class className { barbarian, bard, cleric, druid, fighter, paladin,
                     //monk, ranger, rogue, sorcerer, warlock, wizard };

/*
 * @desc A Player has a class (eg bard, cleric, etc)
 * only derived classes should use the klass constructor
 *
 */
class Klass
{
    public:
        virtual ~Klass() {};

        Klass() = default;
        /*
         * @param name the name of the klass
         * @param v vector<string> of the proficiencies of this klass
         */
        Klass(
            int                        baseHitPointsAtFirstLevel,
            abilities                  baseHitPointsModifierAtFirstLevel,
            std::string                name,
            std::vector<weaponTypes>   weaponTypeProficiencies,
            std::vector<weaponClasses> weaponClassProficiencies,
            std::vector<std::string>   weaponProficiencies,
            std::vector<abilities>     savingThrowProficiencies,
            std::vector<skills>        skillProficiencies,
            Die                        hitDie,
            Die                        altHitDie
        );

        /*
         * @return string the name of the klass
         */
        std::string toString() const { return name; };

        /*
         * @param a weapon to check for klass proficiency in.
         * @return bool whether or not the klass is proficient in the weapon
         */
        bool isProficientIn( Weapon w );

        /*
         * @param a skill to check for klass proficiency in.
         * @return bool whether or not the klass is proficient in the skill
         */
        bool isProficientIn( skills s );

        /*
         * @return int the base hp its provided to a player of this klass at the first level.
         */
        int                        getBaseHitPointsAtFirstLevel() { return baseHitPointsAtFirstLevel; };

        /*
         * @return abilities the modifier to add to your base hit points at the first level for a player of this klass at the first level.
         */
        abilities                  getBaseHitPointsModifierAtFirstLevel() { return baseHitPointsModifierAtFirstLevel; };
    protected:
        int                        baseHitPointsAtFirstLevel;
        abilities                  baseHitPointsModifierAtFirstLevel;
        std::string                name;
        std::vector<weaponTypes>   weaponTypeProficiencies;
        std::vector<weaponClasses> weaponClassProficiencies;
        std::vector<std::string>   weaponProficiencies;
        std::vector<abilities>     savingThrowProficiencies;
        std::vector<skills>        skillProficiencies;
        Die                        hitDie;
        Die                        altHitDie;
};

/*
 * @desc A paladin- protector of the weak or something
 * TODO should effect hit die used by player, hp @first level, etc
 */
class Paladin : public Klass
{
    public:
        Paladin( const std::vector<skills> skillProficiencies );
};

#endif