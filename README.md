# dnd

run using this command: `g++ main.cpp die.cpp player.cpp race.cpp weapon.cpp -o a.out -std=c++11  && ./a.out`

`main.cpp` shows intended usuage of code.

This code exists to solve the problem of:
* When in battle, what do I roll and when?
  * We first roll to see if we can attack. For this roll to succeed we must roll higher than the target's AC (Armor Class)
  * If we can attack, we roll for damage.
* What is added to my rolls and where does that come from?
  *  The attack roll is your d20 + relevant proficiency bonus + relevant ability modifier
  *  The damge roll is the relevant die + relevant ability modifier

Specifically I need to figure out:
* What is my target's AC?
* What do I need to roll to beat this AC? 
  * d20 + proficiency bonus if you are proficient in the weapon + str/dex ability modifier based on weapon
* Subsequently, am I proficient in this weapon?
  * This comes from your race and class
* What is my proficiency bonus? 
  * This is based on your level
* What ability score modifier do I add to the attack roll? 
  * Melee weapons use strength. Range weapons use dexterity. Except where noted otherwise (e.g. finesse melee weapons use your dexterity modifier)
* What ability score modifier do I apply to the damage roll? 
  * The ability modifier applied here is the same ability modifier as applied to the attack roll

To solve these problems I use these classes: Weapon, Race, Klass, and Player.

Players have a weapon, race and klass member. The weapon class has the job of holding the information about the weapon and a .use() method for getting (random, of course) base damage for the weapon. The Race and Klass members determine if a player is proficient in the weapon via the isProficientIn(Weapon) method.
