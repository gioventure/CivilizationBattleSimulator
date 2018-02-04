#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "unit.h"
#include "terrain.h"


void readTroops(vector<Unit> &allUnits);
void readTerrain(vector<Terrain> &allUnits);
bool combat(Unit attacker, Unit defender); //add terrain later!

int main()
{
  vector<Unit> allUnits;
  vector<Terrain> allTerrain;
  readTroops(allUnits);
  readTerrain(allTerrain);
  combat(allUnits[1], allUnits[0]);
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

bool combat(Unit attacker, Unit defender)
{
  srand((unsigned)time(0));
  int i;
  i = (rand()%6) + 1;
  cout << i << endl;
}
