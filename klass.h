#pragma once

#ifndef __KLASS_H__
#define __KLASS_H__

#include <string>

//enum class className { barbarian, bard, cleric, druid, fighter, paladin,
                     //monk, ranger, rogue, sorcerer, warlock, wizard };

/*
 * @desc A Player has a class (eg bard, cleric, etc)
 * only derived classes should use the race constructor
 *
 */
class Klass
{
    public:
        Klass() = default;

        /*
         * @param string the name of the class
         */
        Klass( const std::string klass ) : klass(klass) {};

        /*
         * @return string the name of the class
         */
        std::string toString() const { return klass; };

    protected:
        std::string klass;
};

/*
 * @desc A paladin- protector of the weak or something
 * TODO should effect hit die used by player, hp @first level, etc
 */
class Paladin : public Klass
{
    public:
        Paladin(): Klass("Paladin") {};
};

#endif