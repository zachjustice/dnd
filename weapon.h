#pragma once

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>
#include <vector>
#include "die.h"

enum class weaponClasses { simple,   martial };
enum class weaponTypes   { melee,    range   };
enum class damageTypes   { piercing, slashing, bludgeoning };

class Weapon
{
    public:
        Weapon() = default;
        Weapon( std::string str, const int c, const Die d, const damageTypes dt, const int w,
                const std::vector<std::string> v, const weaponClasses wc, const weaponTypes wt ) :
            name(str), cost(c), damageDie(d), dType(dt), weight(w), weaponProperties(v),
            weaponType(wt), weaponClass(wc) {};

        std::string getName()                          { return name; };
        int getCost()                            const { return cost; };
        int use()                                const { return damageDie.roll(); };
        int getWeight()                          const { return weight; };
        damageTypes getDamageType()              const { return dType; };
        std::vector<std::string> getProperties() const { return weaponProperties; };
        weaponClasses getWeaponClass()           const { return weaponClass; };
        weaponTypes getWeaponType()              const { return weaponType; };
        virtual std::string toString()                   ;
    protected:
        std::string              name;
        int                      cost;
        Die                      damageDie;
        damageTypes              dType;
        int                      weight;
        std::vector<std::string> weaponProperties;
        weaponClasses            weaponClass;
        weaponTypes              weaponType;
};

class Lance : public Weapon {
    public:
        Lance(): Weapon( "Big Pointy Stick", 10, Die(12), damageTypes::piercing, 6,
        std::vector<std::string>{ "reach", "special" }, weaponClasses::simple, weaponTypes::melee ) {};
        std::string toString() override;
};

class Shortsword : public Weapon {
    public:
        Shortsword(): Weapon( "Pointy Metal Stick", 10, Die(6), damageTypes::piercing, 2,
         std::vector<std::string>{ "finesse", "light" }, weaponClasses::simple, weaponTypes::melee ) {};
};

/*
class WeaponClass
{
    public:
        WeaponClass() = default;
        WeaponClass( const weaponClass_t c ): wClass(c) {};
        weaponClass_t getWeaponClass() const { return wClass; };
        virtual ~WeaponClass() {};
    protected :
        weaponClass_t wClass;
};

class WeaponType
{
    public:
        WeaponType() = default;
        WeaponType( const weaponType_t t ): wType(t) {};
        weaponType_t getWeaponType() const { return wType; };
    protected :
        weaponType_t wType;
};

class SimpleWeapon : public WeaponClass
{
    public:
        SimpleWeapon(): WeaponClass(weaponClass_t::simple) {};
};

class MartialWeapon : public WeaponClass
{
    public:
        MartialWeapon(): WeaponClass(weaponClass_t::martial) {};
};

class MeleeWeapon : public WeaponType
{
    public:
        MeleeWeapon(): WeaponType(weaponType_t::melee) {};

};

class RangeWeapon : public WeaponType
{
    public:
        RangeWeapon(): WeaponType(weaponType_t::range) {};
};
*/

#endif