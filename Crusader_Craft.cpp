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
#include <unistd.h>
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
    void attackRAT();
    void attackSNAKE();
    void attackLIONHEART();
    void saveGame();
    void loadGame();

  public:
    int m_health;
    int m_smithing;
    int m_fletching;
    int m_mining;
    int m_herblore;
    int m_alchemy;
    int savedHealth;
    int savedMining;
    int savedFletching;
    int savedSmithing;
    int savedAlchemy;
    int savedHerblore;
    int getHealth() const;
    int getSkills() const;
    int savingMenu() const;
};

inline int game::getHealth() const {
  return (m_health);
}

inline int game::savingMenu() const {
  int savedHealth = m_health;
  int savedMining = m_mining;
  int savedFletching = m_fletching;
  int savedSmithing = m_smithing;
  int savedAlchemy = m_alchemy;
  int savedHerblore = m_herblore;
  return(savedSmithing);
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

void game::attackRAT() {
  int enemyHealth = 10;
  char playerAttackChoice;
  cout << "Player health: " << m_health << endl;
  cout << "Enemy health: " << enemyHealth << endl;
  cout << "Attack!" << endl;
  sleep(2);
  while (enemyHealth >= 0 || m_health >= 0) {
    int enemyFightAction = rand() % 3 + 1;
    cout << "What will you do? (a = attack, d = defend, r = run):" << endl;
    cin >> playerAttackChoice;
    if (playerAttackChoice == 'a') {
      if (enemyFightAction == 1) {
        cout << "Both attacks result in a 1 point health loss to both players!" << endl;
        enemyHealth -= 1;
        m_health -= 1;
      } else if (enemyFightAction == 2) {
        cout << "The RAT has blocked your attack! No damage dealt or taken!" << endl;
      } else {
        cout << "You hit the RAT for 2 damage as he coward with fear!" << endl;
        enemyHealth -= 2;
      }
    } else if (playerAttackChoice == 'd') {
      if (enemyFightAction == 1) {
        cout << "You have blocked the RAT's attack!" << endl;
      } else if (enemyFightAction == 2) {
        cout << "Nothing happened! Both players chose defend!" << endl;
      } else {
        cout << "The RAT has hit you for 1 damage because you forgot to build up your defenses!" << endl;
        m_health -= 1;
      }
    } else if (playerAttackChoice == 'r') {
      cout << "You have successfully run away you coward!" << endl;
      break;
    }
    if (m_health <= 0) {
      cout << "You have been defeated by the RAT. Head to the hospital wing to heal up and fight again!" << endl;
      healPlayer();
      break;
    } else if (enemyHealth <= 0) {
      cout << "Congratulations! You defeated the RAT!!" << endl;
      cout << "Now go heal up for another battle!" << endl;
      healPlayer();
      break;
    } 
  }
}

void game::attackSNAKE() {
  int enemyHealth = 10;
  char playerAttackChoice;
  cout << "Player health: " << m_health << endl;
  cout << "Enemy health: " << enemyHealth << endl;
  cout << "Attack!" << endl;
  sleep(2);
  while (enemyHealth >= 0 || m_health >= 0) {
    int enemyFightAction = rand() % 3 + 1;
    cout << "What will you do? (a = attack, d = defend, r = run):" << endl;
    cin >> playerAttackChoice;
    if (playerAttackChoice == 'a') {
      if (enemyFightAction == 1) {
        cout << "Both attacks result in a 1 point health loss to both players!" << endl;
        enemyHealth -= 1;
        m_health -= 1;
      } else if (enemyFightAction == 2) {
        cout << "The SNAKE has blocked your attack! No damage dealt or taken!" << endl;
      } else {
        cout << "You hit the SNAKE for 2 damage as he coward with fear!" << endl;
        enemyHealth -= 2;
      }
    } else if (playerAttackChoice == 'd') {
      if (enemyFightAction == 1) {
        cout << "You have blocked the SNAKES's attack!" << endl;
      } else if (enemyFightAction == 2) {
        cout << "Nothing happened! Both players chose defend!" << endl;
      } else {
        cout << "The SNAKE has hit you for 1 damage because you forgot to build up your defenses!" << endl;
        m_health -= 1;
      }
    } else if (playerAttackChoice == 'r') {
      cout << "You have successfully run away you coward!" << endl;
      break;
    }
    if (m_health <= 0) {
      cout << "You have been defeated by the SNAKE. Head to the hospital wing to heal up and fight again!" << endl;
      healPlayer();
      break;
    } else if (enemyHealth <= 0) {
      cout << "Congratulations! You defeated the SNAKE!!" << endl;
      cout << "Now go heal up for another battle!" << endl;
      healPlayer();
      break;
    } 
  }
}

void game::attackLIONHEART() {
  int enemyHealth = 10;
  char playerAttackChoice;
  cout << "Player health: " << m_health << endl;
  cout << "Enemy health: " << enemyHealth << endl;
  cout << "Attack!" << endl;
  sleep(2);
  while (enemyHealth >= 0 || m_health >= 0) {
    int enemyFightAction = rand() % 3 + 1;
    cout << "What will you do? (a = attack, d = defend, r = run):" << endl;
    cin >> playerAttackChoice;
    if (playerAttackChoice == 'a') {
      if (enemyFightAction == 1) {
        cout << "Both attacks result in a 1 point health loss to both players!" << endl;
        enemyHealth -= 1;
        m_health -= 1;
      } else if (enemyFightAction == 2) {
        cout << "The LIONHEART has blocked your attack! No damage dealt or taken!" << endl;
      } else {
        cout << "You hit the LIONHEART for 2 damage as he coward with fear!" << endl;
        enemyHealth -= 2;
      }
    } else if (playerAttackChoice == 'd') {
      if (enemyFightAction == 1) {
        cout << "You have blocked the LIONHEART's attack!" << endl;
      } else if (enemyFightAction == 2) {
        cout << "Nothing happened! Both players chose defend!" << endl;
      } else {
        cout << "The LIONHEART has hit you for 1 damage because you forgot to build up your defenses!" << endl;
        m_health -= 1;
      }
    } else if (playerAttackChoice == 'r') {
      cout << "You have successfully run away you coward!" << endl;
      break;
    }
    if (m_health <= 0) {
      cout << "You have been defeated by the LIONHEART. Head to the hospital wing to heal up and fight again!" << endl;
      healPlayer();
      break;
    } else if (enemyHealth <= 0) {
      cout << "Congratulations! You defeated LIONHEART!!" << endl;
      cout << "Now go heal up for another battle!" << endl;
      healPlayer();
      break;
    } 
  }
}

void game::attackEnemy() {
  int enemyPicker = rand() % 3 + 1;
  int enemy1_Rat = 1;
  int enemy2_Snake = 2;
  int enemy3_Lionheart = 3;
  if (enemyPicker == 1) {
    cout << "Enemy is Rat!" << endl;
    attackRAT();
  } else if(enemyPicker == 2) {
    cout << "Enemy is Snake!" << endl;
    attackSNAKE();
  } else {
    cout << "Enemy is Lionheart!" << endl;
    attackLIONHEART();
  }
}

void game::forgeItem() {
  int smithing = m_smithing;
  if (smithing == 0) {
    cout << "You are not able to smith anything at this time.\nCome back later when you are level " << smithing + 1 << endl;
  } else if (smithing < 5 && smithing > 0) {
    cout << "You are able to make bronze daggers!" << endl;
  } else if (smithing >= 5 && smithing < 10) {
    cout << "You are able to make iron daggers!" << endl;
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
    m_health = 10;
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

void game::saveGame() {
  char userKey;
  cout << "Press 'S' to save your game" << endl;
  cin >> userKey;
  savingMenu();
  sleep(3);
  cout << "Game saved!" << endl;
  
}

void game::loadGame() {
  cout << "Your previous SMITHING LEVEL is " << savedSmithing << endl;
  cout << "Your previous MINING LEVEL is " << savedMining << endl;
  cout << "Your previous HEALTH LEVEL is " << savedHealth << endl;
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
    cout << "8. Save game" << endl;
    cout << "9. Load game" << endl;
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

      case 8:
        Crusader_Craft.saveGame();
        break;

      case 9:
        Crusader_Craft.loadGame();
        break;

      default:
        cout << "You did not select anything valid. You are banished." << endl;
        return 0;
    } 
  } while(choice != 0);
}
