#include "terrain.h"

Terrain::Terrain(string name, double defenseBonus, bool hasRiver,
		 bool hasCityWalls, StructureType structType) : name(name),
								defenseBonus(defenseBonus),
								hasRiver(hasRiver),
								hasCityWalls(hasCityWalls),
								structType(structType)
							       
{
  adjustDefense(getStructureDefenseModifier());
  if(hasRiver) adjustDefense(RIVER_BONUS);
}	 

void Terrain::adjustDefense(double percentage)
{ defenseBonus += percentage; }

double Terrain::getTotalDefenseBonus()
{ return defenseBonus; }

double Terrain::getStructureDefenseModifier()
{
  switch(structType)
    {
    case NONE:
      return 0;
    case CITY:
      return .5;
    case FORTRESS:
      return 1;
    }
}
