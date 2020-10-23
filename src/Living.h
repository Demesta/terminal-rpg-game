#include "Spell.h"
#include "Item.h"


#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

#ifndef __LIVING_H_INCLUDED__
#define __LIVING_H_INCLUDED__

class tile;

class Living{
  private:
    string name;
    int level;
    int healthPoints; //At 0 HP the Living loses its consiousness
  public:
    Living(string _name);
    void setLevel(int _level);
    void setHealthPoints(int _healthPoints);
    int getLevel();
    string getName();
    int getHealthPoints();
    virtual void levelUp()=0;
};

class Hero: public Living{
  private:
    int magicPoints;
    int strength;
    int dexterity;
    int agility;
    int money;
    int experience;

  public:
    list<Item*> itemList;
    list<Item*>::iterator itItem;
    list<Spell*> spellList;
    list<Spell*>::iterator itSpell;
    Item* weapon;
    Item*  armor;
    Spell* spell;
    tile*  currentTile;
    Hero(string _name,int _strength,int _dexterity,int _agility);
    virtual void levelUp()=0;
    void addMoney(int _money);
    void addExperience(int _experience);
    void spellCast();

    void setStrength(int nStrength);
    void setDexterity(int nDexterity);
    void setAgility(int nAgility);
    void setExperience(int _experience);
    void setMoney(int _money);

    int getMagicPoints();
    int getStrength();
    int getDexterity();
    int getAgility();
    int getMoney();
    int getExperience();

    int attackDamage();
    int spellDamage();
    int receivedDamage(int _damage);
    void checkInvetory();
    bool dodgedAttack();
    void displayStats();
};

class Warrior: public Hero{
  public:
    Warrior(string _name,int _strength=150,int _dexterity=75,int _agility=100);
      void levelUp();
};

class Mage: public Hero{
  public:
    Mage(string _name,int _strength=75,int _dexterity=150,int _agility=100);
      void levelUp();
};

class Paladin: public Hero{
  public:
    Paladin(string _name,int _strength=150,int _dexterity=150,int _agility=50);
      void levelUp();
};

class Monster: public Living{
  private:
    int strength;
    int defence;
    int agility;
    int debuffRounds;
  public:
    Spell* spell;
    Monster(string _name);

    void setStrength(int _strength);
    void setDefence(int _defence);
    void setAgility(int _agility);
    void setDebuffRounds(int _rounds);
    void minusDebuffRounds();

    int getStrength();
    int getDefence();
    int getAgility();
    int getDebuffRounds();

    int attackDamage();
    int receivedDamage(int _damage);
    bool dodgedAttack();
    void displayStats();
    virtual void levelUp(){};
};

class Dragon: public Monster{
  public:
    Dragon(int _heroLevel);
};

class Exoskeleton: public Monster{
  public:
    Exoskeleton(int _heroLevel);
};

class Spirit: public Monster{
  public:
    Spirit(int _heroLevel);
};

#endif
