#include "Spell.h"

Spell:: Spell(int _spellLevel,int _debuff,int _price,int _damage,string _name,int _mana){
          debuff=_debuff;
          name=_name;
          price=_price;
          spellLevel=_spellLevel;
          damage=_damage;
          mana=_mana;
          debuffRounds=2;
        }

string Spell:: getName(){
                 return name;
               }

int Spell:: getPrice(){
              return price;
            }

int Spell:: getSpellLevel(){
              return spellLevel;
            }

int Spell:: getDamage(){
              return rand()%(damage/5)+damage;
            }

int Spell:: getMana(){
              return mana;
            }

int Spell:: getDebuffRounds(){
              return debuffRounds;
            }

void Spell:: displayStats(){
               cout<<getName()<<" Level: "<<getSpellLevel()<<endl;
             }

IceSpell:: IceSpell(int _spellLevel,int _debuff,int _price,int _damage,string _name,int _mana):
           Spell(_spellLevel,_debuff,_price,_damage,_name,_mana){}

FireSpell:: FireSpell(int _spellLevel,int _debuff,int _price,int _damage,string _name,int _mana):
           Spell(_spellLevel,_debuff,_price,_damage,_name,_mana){}

LightningSpell:: LightningSpell(int _spellLevel,int _debuff,int _price,int _damage,string _name,int _mana):
                 Spell(_spellLevel,_debuff,_price,_damage,_name,_mana){}

int Spell:: getDebuff(){
              return debuff;
            }
