#pragma once

#ifndef __SKILL_H__
#define __SKILL_H__ 1

#include <map>
#include <vector>

enum class skills { athletics, acrobatics, sleightOfHand, stealth, arcana, history,
                    investigation, nature, religion, animalHandling, insight,
                    medicine, perception, survival, deception, intimidation,
                    persuasion, performance };

enum class abilities { charisma, strength, dexterity, wisdom, constitution, intelligence };

class skillProficiencyMismatch: public std::runtime_error
{
    public:
        skillProficiencyMismatch(
            const std::string &s,
            const std::vector<skills> &allowedSkills,
            const skills &givenSkill
        ):
         std::runtime_error(s),
         allowedSkills(allowedSkills),
         givenSkill(givenSkill) { }

        const std::vector<skills> allowedSkills;
        const skills givenSkill;
};
#endif