#pragma once

#ifndef __KLASS_H__
#define __KLASS_H__

enum class className { barbarian, bard, cleric, druid, fighter, paladin,
                     monk, ranger, rogue, sorcerer, warlock, wizard };

class Klass
{
    public:
        Klass() = default;
        Klass( const className r ) : klass(r) {};
        className getKlass() const { return klass; };
    private:
        className klass;
};

class Paladin : public Klass
{
    public:
        Paladin(): Klass(className::paladin) {};
};

#endif