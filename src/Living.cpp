#include "Living.h"

Living:: Living(string _name){
           name=_name;
           level=1;
           healthPoints=1000;
         }

void Living:: setLevel(int _level){
                level=_level;
              }

void Living:: setHealthPoints(int _healthPoints){
               healthPoints=_healthPoints;
             }

int Living:: getLevel(){
                return level;
              }

string Living:: getName(){
                  return name;
                }

int Living:: getHealthPoints(){
               return healthPoints;
             }

Hero:: Hero(string _name,int _strength,int _dexterity,int _agility):
       Living(_name){
         magicPoints=100;
         strength=_strength;
         dexterity=_dexterity;
         agility=_agility;
         money=400;
         experience=0;
         weapon=NULL;
         armor=NULL;
         currentTile= NULL;
       }

void Hero:: addMoney(int _money){
              money+=_money;
            }

void Hero:: setStrength(int nStrength){
              strength=nStrength;
            }

void Hero:: setDexterity(int nDexterity){
              dexterity=nDexterity;
            }

void Hero:: setAgility(int nAgility){
              agility=nAgility;
            }

void Hero:: setExperience(int _experience){
              experience=_experience;
            }

void Hero:: setMoney(int _money){
              money=_money;
            }

int Hero:: getMagicPoints(){
             return magicPoints;
           }

int Hero:: getStrength(){
             return strength;
           }

int Hero:: getDexterity(){
             return dexterity;
           }

int Hero:: getAgility(){
             return agility;
           }

int Hero:: getMoney(){
             return money;
           }

int Hero:: getExperience(){
             return experience;
           }

int Hero:: attackDamage(){
             if(weapon==NULL)
               return strength;
             else
               return strength+weapon->getDamage();
             }

int Hero:: spellDamage(){
             return spell->getDamage()+dexterity;
           }

void Hero:: spellCast(){
             itSpell=spellList.begin();
             int num;

             while(1){
               for(int i=1;i<=spellList.size();i++){
                cout<<i;(*itSpell)->displayStats();
               }

               cout<<endl<<"Select your spell: ";
               cin>>num;cout<<endl;
               if(num<1||num>spellList.size()){
                 cout<<"Invalid Input. Please try again"<<endl;
                 continue;
               }
               break;
             }

             itSpell=spellList.begin();
             for(int i=1;i<=num;i++){
               itSpell++;
             }

             spell=(*itSpell);

           }

void Hero:: addExperience(int _experience){
              int tempXP;
              tempXP=experience+_experience;

              if(tempXP<1000){
                experience=tempXP;
              }
              else{
                if(getLevel()==10){
                  cout<<"You have already achieved the maximum Level."<<endl;
                  experience=0;
                  return;
                }
                levelUp();
                experience=tempXP-1000;
              }
           }

bool Hero:: dodgedAttack(){
              if(rand()%1000>agility)
                return 0;
              else
                return 1;
            }

int Hero:: receivedDamage(int _damage){
             bool dodged;
             dodged= dodgedAttack();
             if(dodged==1)
               return 0;
             else if(armor!=NULL)
               return _damage-armor->getDefence();
             else
               return _damage;
           }

void Hero:: displayStats(){
              cout<<endl<<"Hero's name: "<<getName()<<endl;
              cout<<"Level: "<<getLevel()<<endl;
              cout<<"Health Points: "<<getHealthPoints()<<endl;
              cout<<"Magic Points: "<<getMagicPoints()<<endl;
              cout<<"Strength: "<<getStrength()<<endl;
              cout<<"Dexterity: "<<getDexterity()<<endl;
              cout<<"Agility: "<<getAgility()<<endl;
              cout<<"Money: "<<getMoney()<<endl;
              cout<<"Experience: "<<getExperience()<<endl;
            }

void Hero:: checkInvetory(){
              int choice,itemNumber=0;

              while(1){
                if(itemList.size()==0){
                  cout<<"Your Inventory is empty"<<endl<<endl;
                  break;
                }
                cout<<endl<<"1.Equip Weapon/Armor"<<endl<<"2.Use Potion"<<endl<<"3.Exit Inventory"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice;
                for(int i=0;i<100;i++)
                  cout<<endl;
                if(choice==3)
                  break;
                cout<<endl<<endl<<"Inventory Items:"<<endl;
                itItem=itemList.begin();
                for(int i=1;i<=itemList.size();i++){
                  cout<<endl<<i<<".";
                  (*itItem)->displayItem();
                  itItem++;
                }

                switch (choice){

                  case 1:
                         cout<<endl<<"Enter the number of the weapon you want to equip:";
                         cin>>itemNumber;
                         cout<<endl;
                         if(itemNumber<1 || itemNumber>itemList.size()){
                           for(int i=0;i<100;i++)
                           cout<<endl;
                           cout<<"Invalid Input.Please try again"<<endl;
                           break;
                         }
                         itItem=itemList.begin();
                         for(int i=1;i<itemNumber;i++)
                           itItem++;

                         if(dynamic_cast<Weapon*>((*itItem))!=NULL){
                           for(int i=0;i<100;i++)
                             cout<<endl;
                           weapon=(*itItem);
                           weapon->printName();
                           cout<<" Equiped"<<endl;
                           break;
                         }
                         else if(dynamic_cast<Armor*>((*itItem))!=NULL){
                           for(int i=0;i<100;i++)
                             cout<<endl;
                           armor=(*itItem);
                           armor->printName();
                           cout<<" Equiped"<<endl;
                           break;
                         }
                         else{
                           for(int i=0;i<100;i++)
                             cout<<endl;
                           cout<<"You can only Use a Potion.Try again!"<<endl;
                           break;
                         }

                  case 2:
                        int attribute;
                        cout<<endl<<"Enter the number of the potion you want to use:";
                        cin>>itemNumber;
                        cout<<endl;
                        if(itemNumber<1 || itemNumber>itemList.size()){
                          for(int i=0;i<100;i++)
                            cout<<endl;
                            cout<<"Invalid Input.Please try again."<<endl;
                            break;
                          }
                          itItem=itemList.begin();
                          for(int i=1;i<itemNumber;i++)
                          itItem++;

                        if(dynamic_cast<Potion*>((*itItem))!=NULL){
                          for(int i=0;i<100;i++)
                            cout<<endl;
                          cout<<"1.Strength"<<endl<<"2.Dexterity"<<endl<<"3.Agility"<<endl;
                          cout<<"Select the attribute that you want to buff:";
                          cin>>attribute;
                          cout<<endl;
                          if(attribute==1){
                            strength+=(*itItem)->getBuff();
                            itemList.erase(itItem);
                          }
                          else if(attribute==2){
                            dexterity+=(*itItem)->getBuff();
                            itemList.erase(itItem);
                          }
                          else if(attribute==3){
                            if(getAgility()+(*itItem)->getBuff()>400){
                              setAgility(400);
                              itemList.erase(itItem);
                              break;
                            }
                            agility+=(*itItem)->getBuff();
                            itemList.erase(itItem);
                          }
                        }
                        else{
                          for(int i=0;i<100;i++)
                            cout<<endl;
                          cout<<"Invalid Input.Please try again.";
                        }
                        break;


                  default:

                          cout<<"Invalid input. Please try again."<<endl<<endl;
                          break;
                }

              }
            }

Warrior:: Warrior(string _name,int _strength,int _dexterity,int _agility)
          :Hero(_name,_strength,_dexterity,_agility){};

void Warrior:: levelUp(){
                 setLevel(getLevel()+1);
                 cout<<"Well Done! Warrior achieved level "<<getLevel()<<endl;
                 setStrength(150*getLevel());
                 setDexterity(getDexterity()+75);
                 if(getAgility()+20>400){
                   setAgility(400);
                   return;
                 }
                 setAgility(getAgility()+20);

               }

void Mage:: levelUp(){
              setLevel(getLevel()+1);
              cout<<"Well Done! Mage achieved level "<<getLevel()<<endl;
              setStrength(getStrength()+75);
              setDexterity(150*getLevel());
              if(getAgility()+20>400){
                setAgility(400);
                return;
              }
              setAgility(getAgility()+20);
            }

void Paladin:: levelUp(){
                 setLevel(getLevel()+1);
                 cout<<"Well Done! Paladin achieved level "<<getLevel()<<endl;
                 setStrength(150*getLevel());
                 setDexterity(150*getLevel());
                 if(getAgility()+10>400){
                   setAgility(400);
                   return;
                 }
                 setAgility(getAgility()+10);
               }

Mage:: Mage(string _name,int _strength,int _dexterity,int _agility)
          :Hero(_name,_strength,_dexterity,_agility){}

Paladin:: Paladin(string _name,int _strength,int _dexterity,int _agility)
          :Hero(_name,_strength,_dexterity,_agility){}

Monster:: Monster(string _name):Living(_name){
            spell=NULL;
          }

void Monster:: setStrength(int _strength){
                 strength=_strength;
               }

void Monster:: setDefence(int _defence){
                 defence=_defence;
               }

void Monster:: setAgility(int _agility){
                 agility=_agility;
               }

void Monster:: setDebuffRounds(int _rounds){
                 debuffRounds=_rounds;
               }

void Monster:: minusDebuffRounds(){
                 debuffRounds--;
               }

int Monster:: getStrength(){
                return strength;
              }

int Monster:: getDefence(){
                return defence;
              }

int Monster:: getAgility(){
                return agility;
              }

int Monster:: getDebuffRounds(){
                return debuffRounds;
              }

int Monster:: attackDamage(){
                int extraDamage;
                extraDamage= rand()%(strength/5);
                return strength+extraDamage;
              }

int Monster:: receivedDamage(int _damage){
                bool dodged;
                dodged= dodgedAttack();
                if(dodged==1)
                return 0;
                else
                return _damage-defence;
              }

bool Monster:: dodgedAttack(){
              if(rand()%1000>agility)
                return 0;
              else
                return 1;
            }

void Monster:: displayStats(){
                 cout<<endl<<"Monster's Species: "<<getName()<<endl;
                 cout<<"Health Points: "<<getHealthPoints()<<endl;
                 cout<<"Strength: "<<getStrength()<<endl;
                 cout<<"Defence: "<<getDefence()<<endl;
                 cout<<"Agility: "<<getAgility()<<endl;
               }

Dragon:: Dragon(int _heroLevel):Monster("Dragon"){
           setStrength(80*_heroLevel);
           setDefence(25*_heroLevel);
           setAgility(100+15*_heroLevel);
         }

Exoskeleton:: Exoskeleton(int _heroLevel):Monster("Exoskeleton"){
                setStrength(40*_heroLevel);
                setDefence(50*_heroLevel);
                setAgility(100+15*_heroLevel);
              }

Spirit:: Spirit(int _heroLevel):Monster("Spirit"){
           setStrength(40*_heroLevel);
           setDefence(25*_heroLevel);
           setAgility(200+15*_heroLevel);
         }
