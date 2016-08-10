#pragma once

#ifndef __RACE_H__
#define __RACE_H__

#include <vector>
#include "weapon.h"

enum class raceName { dwarf, elf, halfling, human, dragonborn, gnome, halfElf, halfOrc, tiefling };

class Race
{
    public:
        Race() = default;
        Race( const raceName r, const std::vector<std::string> v ) : name(r), raceProficiencies(v) {};
        raceName getRaceName() const { return name; };
        virtual bool isProficientIn( Weapon w ) { return false; };
        virtual ~Race() {};
    private:
        raceName                 name;
        std::vector<std::string> raceProficiencies;
        std::vector<std::string> savingThrowProficiencies;
        std::vector<std::string> primaryAbilities;
        Die                      hitDie;
};

class Dragonborn : public Race
{
    public:
        Dragonborn(): Race(raceName::dragonborn, std::vector<std::string>{"simple", "martial", "armor", "shields"}) {};
        ~Dragonborn() {};
        bool isProficientIn( Weapon w ) override;
};

#endif