// TODO:
//  Create a save function and a load function for progress
// --- I will have to make the save and load function read and write to text files ---
//  Add more skills
//  Whatever you craft can go to inventory???
//  When training on skills, the number to make things should change in accordance to lvl
//  Make a armor and weapon equip option.
//  Item stock in market?
//  Boss levels
//  Gender for races
//  Fix health value variable

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;

class game {
  public: 
    game(int health = 20, int smithing = 1, int fletching = 1, int mining = 1, int herblore = 1, int alchemy = 1, int playersCurrency = 0, string playerName = "None", string playerRace = "Nord", int attackLvl = 0, int defenseLvl = 0, string specialAttribute = "None", bool playerCreated = false, int playerOvrLvl = 1, bool wearLeather = true, bool wearBronze = false, bool wearIron = false, bool wearSteel = false, bool wearMithril = false, bool wearAdament = false, bool wearRune = false, bool wearDragon = false, bool wieldBronze = false, bool wieldIron = false, bool wieldSteel = false, bool wieldMithril = false, bool wieldAdament = false, bool wieldRune = false, bool wieldDragon = false);
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
    void goToMarket();
    void createPlayer();
    void trainAtk_and_def();
    void checkCombatLevel();
    void equipItems();

  public:
    string m_playerName;
    string m_playerRace;
    string m_specialAttribute;
    bool m_playerCreated;
    bool m_wearLeather;
    bool m_wearBronze;
    bool m_wearIron;
    bool m_wearSteel;
    bool m_wearMithril;
    bool m_wearAdament;
    bool m_wearRune;
    bool m_wearDragon;
    bool m_wieldBronze;
    bool m_wieldIron;
    bool m_wieldSteel;
    bool m_wieldMithril;
    bool m_wieldAdament;
    bool m_wieldRune;
    bool m_wieldDragon;
    int m_playerOvrLvl;
    int m_attackLvl;
    int m_defenseLvl;
    int m_health;
    int m_smithing;
    int m_fletching;
    int m_mining;
    int m_herblore;
    int m_alchemy;
    int m_playersCurrency;
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
  /*
   Need to fix the save menu function
  */
  int savedHealth = m_health;
  int savedMining = m_mining;
  int savedFletching = m_fletching;
  int savedSmithing = m_smithing;
  int savedAlchemy = m_alchemy;
  int savedHerblore = m_herblore;
  return 0;
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

game::game(int health, int smithing, int fletching, int mining, int herblore, int alchemy, int playersCurrency, string playerName, string playerRace, int attackLvl, int defenseLvl, string specialAttribute, bool playerCreated, int playerOvrLvl, bool wearLeather, bool wearBronze, bool wearIron, bool wearSteel, bool wearMithril, bool wearAdament, bool wearRune, bool wearDragon, bool wieldBronze, bool wieldIron, bool wieldSteel, bool wieldMithril, bool wieldAdament, bool wieldRune, bool wieldDragon):
  m_health(health),
  m_smithing(smithing),
  m_fletching(fletching),
  m_mining(mining),
  m_herblore(herblore),
  m_alchemy(alchemy),
  m_playersCurrency(playersCurrency),
  m_playerName(playerName),
  m_playerRace(playerRace),
  m_specialAttribute(specialAttribute),
  m_attackLvl(attackLvl),
  m_defenseLvl(defenseLvl),
  m_playerCreated(playerCreated),
  m_playerOvrLvl(playerOvrLvl),
  m_wearLeather(wearLeather),
  m_wearBronze(wearBronze),
  m_wearIron(wearIron),
  m_wearSteel(wearSteel),
  m_wearMithril(wearMithril),
  m_wearAdament(wearAdament),
  m_wearRune(wearRune),
  m_wearDragon(wearDragon),
  m_wieldBronze(wieldBronze),
  m_wieldIron(wieldIron),
  m_wieldSteel(wieldSteel),
  m_wieldMithril(wieldMithril),
  m_wieldAdament(wieldAdament),
  m_wieldRune(wieldRune),
  m_wieldDragon(wieldDragon)
{}

void game::createPlayer() {
  string m_playerRace;
  int choice;
  cout << "What is your name?:" << endl;
  cin >> m_playerName;
  cout << "1. Nord" << endl;
  cout << "2. Breton" << endl;
  cout << "3. Orc" << endl;
  cout << "4. Dark Elf" << endl;
  cout << "5. Wood Elf" << endl;
  cout << "6. Dwarf" << endl;
  cout << "Choose your race:" << endl;
  cin >> choice;

  switch(choice) {
    case 1: // Nord
      m_playerRace = "Nord";
      m_attackLvl = 15;
      m_defenseLvl = 10;
      m_specialAttribute = "Strong warrior with strong resistance against cold weather";
      break;

    case 2: // Breton
      m_playerRace = "Breton";
      m_attackLvl = 12;
      m_defenseLvl = 12;
      m_specialAttribute = "Smart warrior with a strength in hand to hand combat";
      break;

    case 3: // Orc
      m_playerRace = "Orc";
      m_attackLvl = 20;
      m_defenseLvl = 15;
      m_specialAttribute = "Strong, big, ruthless. Occasionally will make harsh decisions based on rough mentality";
      break;

    case 4: // Dark elf
      m_playerRace = "Dark Elf";
      m_attackLvl = 10;
      m_defenseLvl = 5;
      m_specialAttribute = "Small, agile, crafty. Strong in dark magic";
      break;

    case 5: // Wood elf
      m_playerRace = "Wood Elf";
      m_attackLvl = 7;
      m_defenseLvl = 5;
      m_specialAttribute = "Small, agile, crafty. Excellent with a bow";
      break;

    case 6: // Dwarf
      m_playerRace = "Dwarf";
      m_attackLvl = 18;
      m_defenseLvl = 12;
      m_specialAttribute = "Small. Tough. Excellent miners. Willing to attack anytime, anywhere";
      break;
  }  
  checkCombatLevel();
  cout << "Congratulations! " << m_playerName << "!" << endl;
  cout << "Race: " << m_playerRace << endl;
  cout << "Starting attack level: " << m_attackLvl << endl;
  cout << "Starting defense level: " << m_defenseLvl << endl;
  cout << "Special attribute: " << m_specialAttribute << endl;
  cout << "Player level: " << m_playerOvrLvl << endl;
  m_playerCreated = true;
}

void game::checkHealth() {
  cout << "Let me check your health..." << endl;
  int health = m_health;
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
  int enemyHealth = 20;
  char playerAttackChoice;
  srand(time(NULL));
  int gpWinnings = rand() % 30 + 1;
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
        cout << "You hit the RAT for " << m_attackLvl / 3 << " damage as he coward with fear!" << endl;
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
      cout << "You are rewarded " << gpWinnings << "gp!" << endl;
      m_playersCurrency += gpWinnings;
      cout << "Now go heal up for another battle!" << endl;
      healPlayer();
      break;
    } 
  }
}

void game::attackSNAKE() {
  int enemyHealth = 20;
  char playerAttackChoice;
  srand(time(NULL));
  int gpWinnings = rand() % 30 + 1;
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
        cout << "You hit the SNAKE for " << m_attackLvl / 3 << " damage as he coward with fear!" << endl;
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
      cout << "You are rewarded " << gpWinnings << "gp!" << endl;
      m_playersCurrency += gpWinnings;
      cout << "Now go heal up for another battle!" << endl;
      healPlayer();
      break;
    } 
  }
}

void game::attackLIONHEART() {
  int enemyHealth = 20;
  char playerAttackChoice;
  srand(time(NULL));
  int gpWinnings = rand() % 30 + 1;
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
        cout << "You hit the LIONHEART for " << m_attackLvl / 3 << " damage as he coward with fear!" << endl;
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
      cout << "You are rewarded " << gpWinnings << "gp!" << endl;
      m_playersCurrency += gpWinnings;
      cout << "Now go heal up for another battle!" << endl;
      healPlayer();
      break;
    } 
  }
}

void game::attackEnemy() {
  srand(time(NULL));
  int enemyPicker = rand() % 3 + 1;
  int enemy1_Rat = 1;
  int enemy2_Snake = 2;
  int enemy3_Lionheart = 3;
  if (enemyPicker == enemy1_Rat) {
    cout << "Enemy is Rat!" << endl;
    attackRAT();
  } else if (enemyPicker == enemy2_Snake) {
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
  } else if (smithing >= 10 && smithing < 15) {
    cout << "You are able to make steel daggers!" << endl;
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
  cout << "Attack: " << m_attackLvl << endl;
  cout << "Defense: " << m_defenseLvl << endl;
  cout << "Special attribute: " << m_specialAttribute << endl;
  cout << "Combat level: " << m_playerOvrLvl << endl;
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
    m_playersCurrency += 10;
  }
}

void game::healPlayer() {
  int health = getHealth();
  char heal;
  if (health < 10) {
    cout << "Press 'H' to heal player or press 'L' to leave the hospital wing." << endl;
    cin >> heal;
    if (heal == 'h') {
      cout << "Your health is now at 10!" << endl;
      m_health = m_attackLvl + 5;
    } else {
      // Do nothing...heading back to main
    }
  } else if (health >= 10) {
    cout << "You are healthy and do not need healing.\n" << endl;
  }
}

void game::checkInventory() {
  string choice;
  vector<string> inventory;
  vector<string>::iterator changeInv;
  vector<string>::const_iterator readInv;

  inventory.push_back("Fishing Net");
  inventory.push_back("Tinderbox");
  inventory.push_back("Iron Axe");
  cout << "Inventory:" << endl;
  for (readInv = inventory.begin(); readInv < inventory.end(); readInv++) {
    cout << *readInv << endl;
  }
  cout << "Would you like to check how much gold you have to spend?:" << endl;
  cin >> choice;
  if (choice == "yes") {
    cout << "Gold: " << m_playersCurrency << "gp" << endl;
  } else {
    // Do nothing
  }
}

void game::checkCombatLevel() {
  int total = m_attackLvl + m_defenseLvl;
  if (total == 25) {
    m_playerOvrLvl++;
  } 
  if (total == 30) {
    m_playerOvrLvl++;
  } 
  if (total == 35) {
    m_playerOvrLvl++;
  } 
  if (total == 40) {
    m_playerOvrLvl++;
  }
  if (total == 45) {
    m_playerOvrLvl++;
  } 
  if (total == 50) {
    m_playerOvrLvl++;
  }
  if (total == 55) {
    m_playerOvrLvl++;
  } 
  if (total == 60) {
    m_playerOvrLvl++;
  }
  if (total == 65) {
    m_playerOvrLvl++;
  } 
  if (total == 70) {
    m_playerOvrLvl++;
  } 
  if (total == 75) {
    m_playerOvrLvl++;
  } 
  if (total == 80) {
    m_playerOvrLvl++;
  } 
  if (total == 85) {
    m_playerOvrLvl++;
  } 
}

void game::goToMarket() {
  int ironArmor = 100;
  int ironSword = 35;
  int bronzeSword = 15;
  int dragonArmor = 1000;
  int steelSword = 50;
  int steelArmor = 175;
  int mithrilSword = 75;
  int runeSword = 100;
  int dragonSword = 150;
  int shopItem;

  cout << "Items to buy at the market:" << endl;
  cout << "1. Iron armor: " << ironArmor << "gp" << endl;
  cout << "2. Iron sword: " << ironSword << "gp" << endl;
  cout << "3. Bronze sword: " << bronzeSword << "gp" << endl;
  cout << "4. Dragon armor: " << dragonArmor << "gp" << endl;
  cout << "5. Steel sword: " << steelSword << "gp" << endl;
  cout << "6. Steel armor: " << steelArmor << "gp" << endl;
  cout << "7. Mithril sword: " << mithrilSword << "gp" << endl;
  cout << "8. Rune sword: " << runeSword << "gp" << endl;
  cout << "9. Dragon sword: " << dragonSword << "gp" << endl;
  cout << "\nYour gold: " << m_playersCurrency << "gp" << endl;
  cout << "\n\nWhat would you like to buy?:" << endl;
  cin >> shopItem;
  if (shopItem == 1) {
    if (m_playersCurrency < ironArmor) {
      cout << "You cannot afford this item. You need " << ironArmor - m_playersCurrency << " more gold to buy this." << endl;
    } else {
      m_playersCurrency -= ironArmor;
      cout << "You have purchased Iron Armor!" << endl;
    }
  } else if (shopItem == 2) {
    if (m_playersCurrency < ironSword) {
      cout << "You cannot afford this item. You need " << ironSword - m_playersCurrency << " more gold to buy this." << endl;
    } else {
      m_playersCurrency -= ironSword;
      cout << "You have purchased a Iron Sword!" << endl;
    }
  } else if (shopItem == 3) {
    if (m_playersCurrency < bronzeSword) {
      cout << "You cannot afford this item. You need " << bronzeSword - m_playersCurrency << " more gold to buy this." << endl;
    } else {
      m_playersCurrency -= bronzeSword;
      cout << "You have purchased a Bronze Sword!" << endl;
    }
  } else if (shopItem == 4) {
    if (m_playersCurrency < dragonArmor) {
      cout << "You cannot afford this item. You need " << dragonArmor - m_playersCurrency << " more gold to buy this." << endl;
    } else {
      m_playersCurrency -= dragonArmor;
      cout << "You have purchased Dragon Armor!" << endl;
    }
  } else if (shopItem == 5) {
    if (m_playersCurrency < steelSword) {
      cout << "You cannot afford this item. You need " << steelArmor - m_playersCurrency << " more gold to buy this." << endl;
    } else {
      m_playersCurrency -= steelSword;
      cout << "You have purchased a Steel Sword!" << endl;
    }
  } else if (shopItem == 6) {
    if (m_playersCurrency < steelArmor) {
      cout << "You cannot afford this item. You need " << steelArmor - m_playersCurrency << " more gold to buy this." << endl;
    } else {
      m_playersCurrency -= steelArmor;
      cout << "You have purchased Steel Armor!" << endl;
    }
  } else if (shopItem == 7) {
    if (m_playersCurrency < mithrilSword) {
      cout << "You cannot afford this item. You need " << mithrilSword - m_playersCurrency << " more gold to buy this." << endl;
    } else {
      m_playersCurrency -= mithrilSword;
      cout << "You have purchased a Mithril Sword!" << endl;
    }
  } else if (shopItem == 8) {
    if (m_playersCurrency < runeSword) {
      cout << "You cannot afford this item. You need " << runeSword - m_playersCurrency << " more gold to buy this." << endl;
    } else {
      m_playersCurrency -= runeSword;
      cout << "You have purchased a Rune Sword!" << endl;
    }
  } else if (shopItem == 9) {
    if (m_playersCurrency < dragonSword) {
      cout << "You cannot afford this item. You need " << dragonSword - m_playersCurrency << " more gold to buy this." << endl;
    } else {
      m_playersCurrency -= dragonSword;
      cout << "You have purchased a Dragon Sword!" << endl;
    }
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

void game::equipItems() {
  if (m_defenseLvl < 20) {
    m_wearLeather = true;
    m_wearBronze = true;
    m_wearIron = false;
    m_wearSteel = false;
    m_wearMithril = false;
    m_wearAdament = false;
    m_wearRune = false;
    m_wearDragon = false;

    m_wieldBronze = true;
    m_wieldIron = false;
    m_wieldSteel = false;
    m_wieldMithril = false;
    m_wieldAdament = false;
    m_wieldRune = false;
    m_wieldDragon = false;
  } else if (m_defenseLvl >= 20 && m_defenseLvl < 30) {
    m_wearLeather = true;
    m_wearBronze = true;
    m_wearIron = true;
    m_wearSteel = false;
    m_wearMithril = false;
    m_wearAdament = false;
    m_wearRune = false;
    m_wearDragon = false;

    m_wieldBronze = true;
    m_wieldIron = true;
    m_wieldSteel = false;
    m_wieldMithril = false;
    m_wieldAdament = false;
    m_wieldRune = false;
    m_wieldDragon = false;
  } else if (m_defenseLvl >= 30 && m_defenseLvl < 40) {
    m_wearLeather = true;
    m_wearBronze = true;
    m_wearIron = true;
    m_wearSteel = true;
    m_wearMithril = false;
    m_wearAdament = false;
    m_wearRune = false;
    m_wearDragon = false;

    m_wieldBronze = true;
    m_wieldIron = true;
    m_wieldSteel = true;
    m_wieldMithril = false;
    m_wieldAdament = false;
    m_wieldRune = false;
    m_wieldDragon = false;
  } else if (m_defenseLvl >= 40 && m_defenseLvl < 50) {
    m_wearLeather = true;
    m_wearBronze = true;
    m_wearIron = true;
    m_wearSteel = true;
    m_wearMithril = true;
    m_wearAdament = false;
    m_wearRune = false;
    m_wearDragon = false;

    m_wieldBronze = true;
    m_wieldIron = true;
    m_wieldSteel = true;
    m_wieldMithril = true;
    m_wieldAdament = false;
    m_wieldRune = false;
    m_wieldDragon = false;
  } else if (m_defenseLvl >= 50 && m_defenseLvl < 60) {
    m_wearLeather = true;
    m_wearBronze = true;
    m_wearIron = true;
    m_wearSteel = true;
    m_wearMithril = true;
    m_wearAdament = true;
    m_wearRune = false;
    m_wearDragon = false;

    m_wieldBronze = true;
    m_wieldIron = true;
    m_wieldSteel = true;
    m_wieldMithril = true;
    m_wieldAdament = true;
    m_wieldRune = false;
    m_wieldDragon = false;
  } else if (m_defenseLvl >= 60 && m_defenseLvl < 70) {
    m_wearLeather = true;
    m_wearBronze = true;
    m_wearIron = true;
    m_wearSteel = true;
    m_wearMithril = true;
    m_wearAdament = true;
    m_wearRune = true;
    m_wearDragon = false;

    m_wieldBronze = true;
    m_wieldIron = true;
    m_wieldSteel = true;
    m_wieldMithril = true;
    m_wieldAdament = true;
    m_wieldRune = true;
    m_wieldDragon = false;
  } else if (m_defenseLvl >= 70 && m_defenseLvl < 80) {
    m_wearLeather = true;
    m_wearBronze = true;
    m_wearIron = true;
    m_wearSteel = true;
    m_wearMithril = true;
    m_wearAdament = true;
    m_wearRune = true;
    m_wearDragon = true;

    m_wieldBronze = true;
    m_wieldIron = true;
    m_wieldSteel = true;
    m_wieldMithril = true;
    m_wieldAdament = true;
    m_wieldRune = true;
    m_wieldDragon = true;
  }
}

void game::trainAtk_and_def() {
  int choice;
  cout << "Which would you like to train?:" << endl;
  cout << "1. Attack" << endl;
  cout << "2. Defense" << endl;
  cin >> choice;
  float time_a = m_attackLvl / 2;
  float time_b = m_defenseLvl / 2;
  if (choice == 1) {
    cout << "You embark on a journey to level up your attack level..." << endl;
    sleep(time_a);
    m_attackLvl++;
    cout << "Congratulations! You are now attack level " << m_attackLvl << "!" << endl;
  } else {
    cout << "You embark on a journey to level up your defense level..." << endl;
    sleep(time_b);
    m_defenseLvl++;
    cout << "Congratulations! You are now attack level " << m_defenseLvl << "!" << endl;
  }
}

int main() {
  game Crusader_Craft;
  cout << "Welcome to the World of Crusader-Craft!!\n\n" << endl;
  int choice;
  bool m_playerCreated;
  if (m_playerCreated == false) {
    Crusader_Craft.createPlayer();
  }
  do {
    Crusader_Craft.checkCombatLevel();
    cout << "\nWhat would you like to do?:" << endl;
    cout << "1. Attack an enemy" << endl;
    cout << "2. Forge an item" << endl;
    cout << "3. Check your health" << endl; 
    cout << "4. Check your skills" << endl;
    cout << "5. Train a skill" << endl;
    cout << "6. Heal player" << endl;
    cout << "7. Check inventory" << endl;
    cout << "8. Go to the market" << endl;
    cout << "9. Train attack and defense" << endl;
    cout << "10. Equip items" << endl;
    // cout << "9. Save game" << endl;
    // cout << "10. Load game" << endl;
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
        Crusader_Craft.goToMarket();
        break;

      case 9:
        Crusader_Craft.trainAtk_and_def();
        break;

      case 10:
        Crusader_Craft.equipItems();
        break;

      default:
        cout << "You did not select anything valid. You are banished." << endl;
        return 0;
    } 
  } while(choice != 0);
}
