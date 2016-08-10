#pragma once

#ifndef __RACE_H__
#define __RACE_H__

#include <string>
#include <vector>
#include "weapon.h"

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
        Race( const std::string name, const std::vector<std::string> v ) : name(name), proficiencies(v) {};

        /*
         * @return string the name of the race
         */
        std::string toString() const { return name; };

        /*
         * @param a weapon to check for racial proficiency in.
         * @return bool whether or not the race is proficient in the weapon
         */
        virtual bool isProficientIn( Weapon w ) { return false; };
    protected:
        std::string              name;
        // TODO these aren't used anywhere yet.
        std::vector<std::string> proficiencies;
        std::vector<std::string> savingThrowProficiencies;
        std::vector<std::string> primaryAbilities;
        Die                      hitDie;
};

class Dragonborn : public Race
{
    public:
        Dragonborn(): Race("Dragonborn", std::vector<std::string>{"simple", "martial", "armor", "shields"}) {};
        ~Dragonborn() {};
        bool isProficientIn( Weapon w ) override;
};

#endif