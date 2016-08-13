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
        /*
         * Constructor
         * @param name The name of the weapon like "Shining Metal Stick of Great Exuberance"
         * @param cost The cost of the weapon in gold pieces (gp)
         * @param damageDie The die used to roll base damage for this weapon (ex: a lance uses a d12)
         * @param dType Peircing, slashing, etc
         * @param weight Weight in pounds
         * @param weaponProperties a vector of strings describing the weapon (i.e. finesse, special, etc)
         * @param weaponClass whether the weapon is simple or martial
         * @param weaponType  whether the weapon is melee or range
         */
        Weapon( std::string name, const int cost, const Die damageDie, const damageTypes dType, const int weight,
                const std::vector<std::string> weaponProperties, const weaponClasses weaponClass, const weaponTypes weaponType ) :
            name(name), cost(cost), damageDie(damageDie), dType(dType), weight(weight), weaponProperties(weaponProperties),
            weaponType(weaponType), weaponClass(weaponClass) {};

        /*
         * @return string Name of the Weapon
         */
        std::string getName()                          { return name; };

        /*
         * @return int The cost of the weapon in gp
         */
        int getCost()                            const { return cost; };

        /*
         * Rolls the damage die associated with this weapon and returns the result
         * @return int how much damage using the weapon causes
         */
        int use()                                const { return damageDie.roll(); };

        /*
         * @return int How much the weapon weighs
         */
        int getWeight()                          const { return weight; };

        /*
         * @return damageTypes the type of damage this weapon does (eg piercing, slashing, etc)
         */
        damageTypes getDamageType()              const { return dType; };

        /*
         * @return vector<string> Vector properties for the weapon (eg finesse)
         */
        std::vector<std::string> getProperties() const { return weaponProperties; };

        /*
         * @return simple or martial
         */
        weaponClasses getWeaponClass()           const { return weaponClass; };

        /*
         * @return melee or range
         */
        weaponTypes getWeaponType()              const { return weaponType; };

        /*
         * @return string representation of the weapon for debugging purposes
         */
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
        Lance(): Weapon( "lance", 10, Die(12), damageTypes::piercing, 6,
        std::vector<std::string>{ "reach", "special" }, weaponClasses::simple, weaponTypes::melee ) {};
        std::string toString() override;
};

class Shortsword : public Weapon {
    public:
        Shortsword(): Weapon( "shortsword", 10, Die(6), damageTypes::piercing, 2,
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