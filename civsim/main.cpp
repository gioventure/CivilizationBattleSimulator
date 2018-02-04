#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "unit.h"
#include "terrain.h"


void readTroops(vector<Unit> &allUnits);
void readTerrain(vector<Terrain> &allUnits);
int combat(Unit attacker, Unit defender); //add terrain later!
int promptUnit(vector<Unit> allUnits, bool attacker);

/**
   Terrains have all been implemented, but I had not
   enough time to make them influence the units and 
   affect the battle
*/
int main()
{
  srand((unsigned)time(0));  
  vector<Unit> allUnits;
  readTroops(allUnits);
  vector<Unit> allUnitsDefender(allUnits);
  vector<Terrain> allTerrain;
  readTerrain(allTerrain);
  
  int attackUnitID = promptUnit(allUnits, true);
  int defendUnitID = promptUnit(allUnits, false);
  int victories = combat(allUnits[attackUnitID],
		   allUnitsDefender[defendUnitID]);
  cout << "Out of 100 simulated battles, the attacker won " <<
    victories << " battles\n" << endl;
  
  
  return 0;
}

void readTroops(vector<Unit> &allUnits)
{
  ifstream inputFile("unittypes");
  int unitAmount;
  inputFile >> unitAmount;
  
  double attack;
  double defense;
  int hitpoints;
  int firepower;
  string name;
  for(int i = 0; i < unitAmount; i++)
    {
      inputFile >> attack;
      inputFile >> defense;
      inputFile >> hitpoints;
      inputFile >> firepower;
      inputFile >> name;
      allUnits.push_back(Unit(attack, defense, hitpoints,
			      firepower, name, false, ROOKIE));
      
    }
  inputFile.close();
}

void readTerrain(vector<Terrain> &allTerrain)
{
  ifstream inputFile("terraintypes");
  int terrainAmount;
  inputFile >> terrainAmount;
  
  string name;
  double baseDefense;
  for(int i = 0; i < terrainAmount; i++)
    {
      inputFile >> name;
      inputFile >> baseDefense;
      allTerrain.push_back(Terrain(name, baseDefense, false, false, NONE));
    }
  inputFile.close();
}

int combat(Unit attacker, Unit defender)
{
  //  cout << "attacker strength: " << attacker.getAttack() << endl;
  //  cout << "defender strength: " << defender.getDefense() << endl;
  int i;
  int wins = 0;
  for(int j = 0; j < 100; j++)
    {
  do
    {
      i = (rand()%static_cast<int>(attacker.getAttack() + defender.getDefense())) + 1;
      
      (i > attacker.getAttack()) ? attacker.damageHealth(defender.getFirepower()) :
	defender.damageHealth(attacker.getFirepower());
    }while( attacker.getHitpoints() > 0 &&
	    defender.getHitpoints() > 0);
  if(attacker.getHitpoints() > 0) wins++;
  attacker.resetHitpoints();
  defender.resetHitpoints();
    }
  

 
  
  
  return wins;
    
}

int promptUnit(vector<Unit> allUnits, bool attacker)
{

  
  if(attacker)
  for(int i = 0; i < allUnits.size(); i++)
    cout << (i + 1) << ". " << allUnits[i].getName() << endl;
  cout << "Choose the " << ((attacker) ? "attacking unit\n" : "defending unit\n");
  int choice;
  cin >> choice;
  while(choice <= 0 || choice > 28)
    {
      cout << "Choose the " << ((attacker) ? "attacking unit\n" : "defending unit\n");
      cin >> choice;
    }
  return choice - 1;
}
