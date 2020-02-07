// TODO:
// 1. Create a save function and a load function for progress
// 2. Add more skills
// 3. Add money to inventory
// 4. Whatever you craft can go to inventory???
// 5. When training on skills, the number to make things should change in accordance to lvl

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class game {
  public: 
    game(int health = 10, int smithing = 1, int fletching = 1, int mining = 1, int herblore = 1, int alchemy = 1);
    void checkHealth();
    void attackEnemy();
    void forgeItem();
    void checkSkills();
    void trainSkill();
    void healPlayer();
    void checkInventory();

  public:
    int m_health;
    int m_smithing;
    int m_fletching;
    int m_mining;
    int m_herblore;
    int m_alchemy;
    int getHealth() const;
    int getSkills() const;
};

inline int game::getHealth() const {
  return (m_health);
}

inline int game::getSkills() const {
  /*
  All skills are known, just at level 1
  IF ANY OTHER SKILLS WANT TO BE ADDED, DO IT HERE
  */
  vector<string> skillsList;
  vector<string>::iterator changeIter;
  vector<string>::const_iterator readIter;
  skillsList.push_back("Smithing");
  skillsList.push_back("Fletching");
  skillsList.push_back("Mining");
  skillsList.push_back("Herblore");
  skillsList.push_back("Alchemy");
  int m_smithing = 1;
  int m_fletching = 1;
  int m_mining = 1;
  int m_herblore = 1;
  int m_alchemy = 1;
  for (readIter = skillsList.begin(); readIter < skillsList.end(); readIter++) {
    cout << *readIter << endl;
  }  
  return 0;
}

game::game(int health, int smithing, int fletching, int mining, int herblore, int alchemy):
  m_health(health),
  m_smithing(smithing),
  m_fletching(fletching),
  m_mining(mining),
  m_herblore(herblore),
  m_alchemy(alchemy)
{}

void game::checkHealth() {
  cout << "Let me check your health..." << endl;
  int health = getHealth();
  if (health <= 0) {
    cout << "You are dead." << endl;
  } else if (health >= 10) {
    cout << "You are doing well!\nYour health level is " << health << endl;
  } else if(health < 10 && health > 0) {
    cout << "Yikes, better take care of yourself\nYour health level is " << health << endl;
  } else {
    cout << "Your health level is " << health << endl;
  }
}

void game::attackEnemy() {
  int enemyPicker = rand() % 3 + 1;
  int enemy1_Rat = 1;
  int enemy2_Snake = 2;
  int enemy3_Lionheart = 3;
  if (enemyPicker == 1) {
    cout << "Enemy is Rat!" << endl;
  } else if(enemyPicker == 2) {
    cout << "Enemy is Snake!" << endl;
  } else {
    cout << "Enemy is Lionheart!" << endl;
  }
  cout << "Attack!" << endl;
}

void game::forgeItem() {
  int smithing = m_smithing;
  if (smithing == 0) {
    cout << "You are not able to smith anything at this time.\nCome back later when you are level " << smithing + 1 << endl;
  } else if (smithing < 5 && smithing > 0) {
    cout << "You are able to make bronze daggers!" << endl;
  } else {
    // Do nothing
  }
}

void game::checkSkills() {
  /*
  int smithing = getSkills();
  int fletching = getSkills();
  int herblore = getSkills();
  int mining = getSkills();
  int alchemy = getSkills();
  */
  cout << "Lets check your skills!" << endl;
  cout << "Smithing: " << m_smithing << endl;
  cout << "Fletching: " << m_fletching << endl;
  cout << "Herblore: " << m_herblore << endl;
  cout << "Mining: " << m_mining << endl;
  cout << "Alchemy: " << m_alchemy << endl;
}

void game::trainSkill() {
  int skills = getSkills();
  string userChoice;
  cout << "Which skill would you like to train?:" << endl;
  cin >> userChoice;
  if (userChoice == "smithing") {
    cout << "You forge 10 bronze daggers to advance in smithing!" << endl;
    m_smithing++;
  } else if (userChoice == "fletching") {
    cout << "You craft 10 bows and 50 arrows to advance in fletching!" << endl;
    m_fletching++;
  } else if (userChoice == "herblore") {
    cout << "You brew 10 potions to advance in herblore!" << endl;
    m_herblore++;
  } else if (userChoice == "mining") {
    cout << "You mine 10 iron ores to advance in mining!" << endl;
    m_mining++;
  } else if (userChoice == "alchemy") {
    cout << "You create 10 pieces of gold to advance in alchemy!" << endl;
    m_alchemy++;
  }
}

void game::healPlayer() {
  int health = getHealth();
  char heal;
  if (health < 10) {
    cout << "Press 'H' to heal player." << endl;
    cin >> heal;
    cout << "Your health is now at 10!" << endl;
  } else if (health >= 10) {
    cout << "You are healthy and do not need healing.\n" << endl;
  }
}

void game::checkInventory() {
  vector<string> inventory;
  vector<string>::iterator changeInv;
  vector<string>::const_iterator readInv;

  inventory.push_back("Apple");
  inventory.push_back("Water Jug");
  inventory.push_back("Axe");
  cout << "Inventory:" << endl;
  for (readInv = inventory.begin(); readInv < inventory.end(); readInv++) {
    cout << *readInv << endl;
  }
}

int main() {
  game Crusader_Craft;
  cout << "Welcome to the World of Crusader-Craft!!\n\n" << endl;
  int choice;
  do {
    cout << "\nWhat would you like to do?:" << endl;
    cout << "1. Attack an enemy" << endl;
    cout << "2. Forge an item" << endl;
    cout << "3. Check your health" << endl; 
    cout << "4. Check your skills" << endl;
    cout << "5. Train a skill" << endl;
    cout << "6. Heal player" << endl;
    cout << "7. Check inventory" << endl;
    cin >> choice; 
    switch(choice) {
      case 1:
        cout << "You embark on an adventure to go kill something..." << endl;
        Crusader_Craft.attackEnemy();
        break;

      case 2:
        cout << "You approach the smelter and anvil to create something special" << endl;
        Crusader_Craft.forgeItem();
        break;

      case 3:
        Crusader_Craft.checkHealth();
        break;

      case 4:
        Crusader_Craft.checkSkills();
        break;

      case 5:
        Crusader_Craft.trainSkill();
        break;

      case 6:
        Crusader_Craft.healPlayer();
        break;

      case 7:
        Crusader_Craft.checkInventory();
        break;

      default:
        cout << "You did not select anything valid. You are banished." << endl;
        return 0;
    } 
  } while(choice != 0);
}
