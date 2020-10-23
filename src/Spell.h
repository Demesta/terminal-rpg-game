#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef __SPELL_H_INCLUDED__
#define __SPELL_H_INCLUDED__

class Spell{
  private:
    string name;
    int price;
    int spellLevel;
    int damage; //escalates with dexterity, doesn't overcome a certain value
    int mana;
    int debuff;
    int debuffRounds;
  public:
    Spell(int _spellLevel,int _debuff,int _price,int _damage,string _name,int _mana);
    string getName();
    int getPrice();
    int getSpellLevel();
    int getDamage();
    int getMana();
    int getDebuff();
    int getDebuffRounds();
    void displayStats();
};

class IceSpell: public Spell{
  public:
    IceSpell(int _spellLevel,int _debuff,int _price,int _damage,string _name="Ice Spell",int _mana=25);
};

class FireSpell: public Spell{
  public:
    FireSpell(int _spellLevel,int _debuff,int _price,int _damage,string _name="Fire Spell",int _mana=25);
};

class LightningSpell: public Spell{
  public:
    LightningSpell(int _spellLevel,int _debuff,int _price,int _damage,string _name="Lightning Spell",int _mana=25);
};

#endif
