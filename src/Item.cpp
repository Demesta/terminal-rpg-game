#include "Item.h"

Item:: Item(string _name, int _price, int _itemLevel){
         name= _name;
         price= _price;
         itemLevel= _itemLevel;
       }

void Item:: printName(){
              cout<<"Item name: "<<name<<endl;
            }

int Item:: getPrice(){
             return price;
           }

int Item:: getItemLevel(){
             return itemLevel;
           }

void Weapon:: displayItem(){
                cout<<endl;
                printName();
                cout<<"Damage: "<<getDamage()<<endl<<"Item Level: "<<getItemLevel()<<endl;
              }

Weapon:: Weapon(string _name,int _price,int _itemLevel,int _damage,bool _oneHanded):
           Item(_name,_price,_itemLevel){
             damage=_damage;
             oneHanded=_oneHanded;
           }

int Weapon:: getDamage(){
               return damage;
             }

bool Weapon:: getOneHanded(){
                return oneHanded;
              }

Armor:: Armor(string _name,int _price,int _itemLevel,int _defence):
          Item(_name,_price,_itemLevel){
            defence=_defence;
          }

int Armor:: getDefence(){
              return defence;
            }

void Armor:: displayItem(){
               cout<<endl;
               printName();
               cout<<"Defence: "<<getDefence()<<endl<<"Item Level: "<<getItemLevel()<<endl;
             }

Potion:: Potion(string _name,int _price,int _itemLevel,int _buff,bool _used):
           Item(_name,_price,_itemLevel){
             buff=_buff;
             used=_used;
           }

int Potion:: getBuff(){
              return buff;
             }

bool Potion:: getUsed(){
               return used;
              }

void Potion:: displayItem(){
                cout<<endl;
                printName();
                cout<<"Buff: "<<getBuff()<<endl<<"Item Level: "<<getItemLevel()<<endl;
             }
