#ifndef UNIT_H
#define UNIT_H

#include <string>
using namespace std;

enum VeteranStatus {ROOKIE, VETERAN, HARDENED, ELITE};

class Unit
{
 private:
  double attack;
  double defense;
  int hitpoints;
  int defaultHitpoints;
  int firepower;
  string name;
  bool isFortified;
  VeteranStatus skill;
  double getVeteranSkillModifier();


 public:
  Unit(double attack, double defense, int hitpoints,
       int firepower, string name, bool isFortified, VeteranStatus skill);
  void adjustAttack(double percentage);
  void adjustDefense(double percentage);
  int getHitpoints();
  double getAttack();
  double getDefense();
  void damageHealth(int enemyFirepower);
  int getFirepower();
  string getName();
  void resetHitpoints();
  
  
};

#endif
