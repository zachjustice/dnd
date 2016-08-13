#pragma once

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include <map>
#include <vector>

#include "weapon.h"
#include "race.h"
#include "klass.h"
#include "skills.h"
#include "die.h"

const int BASE_ARMOR_CLASS = 8;

class Player
{
    public:
        /*
         * @param name Name of the player-- "Richard"
         * @param race A pointer to a race of the player-- Dragonborn
         * @param klass A pointer to a klass of the player-- Paladin
         * @param abilities a map of ability->ability scores
         */
        Player(  std::string name, Race* race, Klass* klass, std::map<abilities, int> abilityScores );
        ~Player() { delete race; delete klass; }
        // TODO copy and move

        /*
         * @desc Rolls a d20 + proficiency bonus if applicable + relevant ability modifier
         * @param skill The skill being performed
         * @return int the result of the ability check
         */
        int abilityCheck( skills skill );

        /*
         * @desc Roll to see if you beat target's AC then roll for damage. Subtract damage from targets hp.
         * see attackRoll() and damageRoll()
         * @param target reference to a player object of who you are attacking
         */
        void attack( Player &target );

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
         * @return Weapon the current weapon weilded by our player
         */
        Weapon getWeapon();

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
        std::string getName();

        /*
         * @desc Added to ability checks on weapons, tools, etc for things your player is proficient in.
         * @return int 8 + dexterity modifier
         */
        int getProficiencyBonus();

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

        int hp; // Should this be private?
    private:

        /*
         * @desc Ability modifer is your ( ability score - 10 ) / 2. Round down.
         * @param ability An ability in the abilities hash like "Charisma"
         */
        int getAbilityModifier( abilities ability ) ;

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
        std::map<abilities, int>   abilityScores;
        Race*                      race; // pointers so we can use virtual methods effectively
        Klass*                     klass; // pointers so we can use virtual methods effectively

        std::map<skills, abilities> skillToAbility =
        {
            { skills::athletics , abilities::strength },
            { skills::acrobatics , abilities::dexterity },
            { skills::sleightOfHand , abilities::dexterity },
            { skills::stealth , abilities::dexterity },
            { skills::arcana , abilities::intelligence },
            { skills::history , abilities::intelligence },
            { skills::investigation , abilities::intelligence },
            { skills::nature , abilities::intelligence },
            { skills::religion , abilities::intelligence },
            { skills::animalHandling , abilities::wisdom },
            { skills::insight , abilities::wisdom },
            { skills::medicine , abilities::wisdom },
            { skills::perception , abilities::wisdom },
            { skills::survival , abilities::wisdom },
            { skills::deception , abilities::charisma },
            { skills::intimidation , abilities::charisma },
            { skills::persuasion , abilities::charisma },
            { skills::performance , abilities::charisma }
        };
};

#endif