#include <iostream>

using namespace std;

#ifndef __ITEM_H_INCLUDED__
#define __ITEM_H_INCLUDED__

class Item{
  private:
    string name;
    int price;
    int itemLevel;
  public:
    Item(string _name,int _price,int _itemLevel);
    void printName();
    int getPrice();
    int getItemLevel();
    virtual void displayItem()=0;
    virtual int getDamage(){return 0;}
    virtual int getBuff(){return 0;}
    virtual int getDefence(){return 0;}
};

class Weapon: public Item{
  private:
    int damage;
    bool oneHanded;
  public:
    Weapon(string _name,int _price,int _itemLevel,int _damage,bool _oneHanded);
    int getDamage();
    bool getOneHanded();
    void displayItem();
};

class Armor: public Item{
  private:
    int defence;
  public:
    Armor(string _name,int _price,int _itemLevel,int _defence);
    int getDefence();
    void displayItem();
};

class Potion: public Item{
  private:
    int buff;
    bool used;
  public:
    Potion(string _name,int _price,int _itemLevel,int _buff,bool _used);
    int getBuff();
    bool getUsed();
    void displayItem();
};

#endif
