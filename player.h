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
        /*
         * @param name Name of the player-- "Richard"
         * @param race A pointer to a race of the player-- Dragonborn
         * @param klass A pointer to a klass of the player-- Paladin
         * @param abilities a map of ability->ability scores
         * @param health how much hp the player has TODO make a current and max hp
         */
        Player(  std::string name, Race* race, Klass* klass, std::map<std::string, int> abilities, int health );
        ~Player() { delete race; delete klass; }
        // TODO copy and move

        /*
         * @desc Roll to see if you beat target's AC then roll for damage. Subtract damage from targets health.
         * see attackRoll() and damageRoll()
         * @param target reference to a player object of who you are attacking
         */
        void attack( Player &target ) ;

        /*
         * @desc Use to check if you beat a target's AC
         * @return int The result of rolling a d20 + profficiency bonus if applicable + ability modifier
         */
        int attackRoll();

        /*
         * @desc Used to apply damage to characters.
         * @return int the result of rolling the relevant die for the current weapon + ability modifier
         */
        int damageRoll();
        // TODO movement
        // TODO cast( Spell spell, Player &target )

        /*
         * @return Weapon the currect weapon weilded by our player
         */
        Weapon getWeapon() ;

        /*
         * @param weapon The weapon to be weilded by this player
         */
        void setWeapon( Weapon weapon );

        /*
         * @return int the AC of this player. 8 + dexterity mod
         */
        int getArmorClass();

        /*
         * @return string The name of the player-- "Eli"
         */
        std::string getName() ;

        /*
         * @desc Added to ability checks on weapons, tools, etc for things your player is proficient in.
         * @return int 8 + dexterity modifier
         */
        int getProficiencyBonus() ;

        /*
         * @desc NOTE: We don't actually track your level, just xp.
         * @return int the player's level based on xp.
         */
        int getLevel() ;

        /*
         * @return int your accumulated xp
         */
        int getExperiencePoints() ;

        /*
         * @desc used to give you xp, level up, and increase your prof bonus
         * @param xp Amount of xp to give
         */
        void giveExperiencePoints( int xp );
        /* TODO add inventory */

        int health; // Should this be private?
    private:

        /*
         * @desc Ability modifer is your ( ability score - 10 ) / 2. Round down.
         * @param ability An ability in the abilities hash like "Charisma"
         */
        int getAbilityModifier( std::string ability ) ;

        /*
         * @desc Whether or not a player is proficient in a weapon. Calls the
         * race's and class's isProficientIn() methods to check this. Proficiency
         * is based on if the weapon is simple/martial, melee/ranged, and the exact
         * weapon.
         * @return bool Whether or not the player is proficient in the weapon.
         */
        bool isProficientIn( Weapon w ) ;

        Die                        d20; // used for ability checks.
        Weapon                     weapon; // used for when the player attacks things
        int                        experiencePoints;
        std::string                name;
        std::vector<std::string>   proficiencies;
        std::map<std::string, int> abilities;
        Race*                      race; // pointers so we can use virtual methods effectively
        Klass*                     klass; // pointers so we can use virtual methods effectively
};

#endif