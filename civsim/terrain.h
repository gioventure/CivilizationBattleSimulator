#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
using namespace std;

enum StructureType {NONE, CITY, FORTRESS};
static const double RIVER_BONUS = .5;
class Terrain
{
 private:
  string name;
  double defenseBonus;
  bool hasRiver;
  bool hasCityWalls;
  StructureType structType;
  double getStructureDefenseModifier();


 public:
  Terrain(string name, double defenseBonus, bool hasRiver,
	  bool hasCityWalls, StructureType structType); 
  void adjustDefense(double percentage);
  double getTotalDefenseBonus();
};

#endif
