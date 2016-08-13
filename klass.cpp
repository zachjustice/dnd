#include "klass.h"

using namespace std;

bool Klass::isProficientIn( skills skill )
{
    for( skills klassSkillProficiency : skillProficiencies )
    {
        if( skill == klassSkillProficiency )
        {
            return true;
        }
    }
    return false;
}
bool Klass::isProficientIn( Weapon w )
{
    for( weaponTypes weaponType : weaponTypeProficiencies )
    {
        if( w.getWeaponType() == weaponType )
        {
            return true;
        }
    }

    for( weaponClasses weaponClass : weaponClassProficiencies )
    {
        if( w.getWeaponClass() == weaponClass )
        {
            return true;
        }
    }

    for( string weaponLabel : weaponProficiencies )
    {
        if( w.getName() == weaponLabel )
        {
            return true;
        }
    }

    return false;
}

Paladin::Paladin( const vector<skills> classSkills )
{
    const vector<skills> allowedSkillProficiencies = {
     skills::athletics,
     skills::insight,
     skills::intimidation,
     skills::medicine,
     skills::persuasion,
     skills::religion
    };

    for( skills skill : classSkills )
    {
        if( find( allowedSkillProficiencies.begin(), allowedSkillProficiencies.end(), skill ) == allowedSkillProficiencies.end() )
        {
            // User passed in a skill proficiency that does not exist in the possible skill proficiency for a Paladin.
            throw skillProficiencyMismatch(
                "User passed in a skill proficiency that does not exist in the possible skill proficiencies for a Paladin.",
                allowedSkillProficiencies,
                skill
            );
        }
    }

    baseHitPointsAtFirstLevel = 10;
    baseHitPointsModifierAtFirstLevel = abilities::constitution;
    name = "Paladin";
    weaponTypeProficiencies = {};
    weaponClassProficiencies = { weaponClasses::simple, weaponClasses::martial };
    weaponProficiencies = {};
    savingThrowProficiencies = { abilities::wisdom, abilities::charisma };
    skillProficiencies = classSkills;
    hitDie = Die( 10 );
    altHitDie = Die( 6 );
}
