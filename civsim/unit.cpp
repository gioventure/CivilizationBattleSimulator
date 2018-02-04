#include "unit.h"


Unit::Unit(double attack, double defense, int hitpoints,
	   int firepower, string name, bool isFortified,
	   VeteranStatus skill) : attack(attack),
				  defense(defense),
				  hitpoints(hitpoints),
				  defaultHitpoints(hitpoints),
				  firepower(firepower),
				  name(name),
				  isFortified(isFortified),
				  skill(skill)
{
  adjustAttack(getVeteranSkillModifier()); 
}

void Unit::adjustAttack(double percentage)
{ attack += attack + (attack * percentage); }

void Unit::adjustDefense(double percentage)
{ defense += (defense * percentage); }

int Unit::getHitpoints() { return hitpoints; }

double Unit::getVeteranSkillModifier()
{
  switch(skill)
    {
    case ROOKIE:
      return 0;
    case VETERAN:
      return .5;
    case HARDENED:
      return .75;
    case ELITE:
      return 1;
    }
}

double Unit::getAttack() { return attack; }

double Unit::getDefense() { return defense; }

void Unit::damageHealth(int enemyFirepower)
{ hitpoints -= enemyFirepower; }

int Unit::getFirepower()
{ return firepower; }

string Unit::getName()
{ return name; }

void Unit::resetHitpoints()
{ hitpoints = defaultHitpoints; }

void Unit::setExperience(VeteranStatus rank)
{
  skill = rank;
  adjustAttack(getVeteranSkillModifier());
}
