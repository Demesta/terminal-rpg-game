#include "battlegrid.h"


int randomnum(int min, int max){         //random number generator
    int retval=0;
    int factor = max-min;

    retval = rand()%(factor + 1);
    retval = min + retval;
    return retval;
}


tile::tile(int x, int y, tiletype t){
    location_x = x;
    location_y = y;
    t_type = t;
}

battlegrid::battlegrid(){
  int i,j;
    int x = 0;
    int y = 0;
    int tt[] = {0,2,0,0,0,1,0,0,0,0,0,0,
                0,0,0,0,2,0,1,0,0,0,0,2,
                0,0,2,0,0,0,0,0,0,0,2,0,
                0,0,0,0,1,1,1,0,2,0,2,0,
                2,0,1,0,1,0,1,0,0,0,0,0,
                0,0,0,0,1,1,1,0,0,0,0,1,
                0,0,2,0,0,0,0,0,2,0,0,1,
                0,0,1,0,0,2,0,0,0,0,1,0,
                0,1,0,0,0,0,1,0,0,0,2,0,
                0,0,0,0,1,0,0,0,0,0,1,0,
                2,1,0,0,0,0,2,0,0,0,0,0,
                0,1,0,0,2,0,0,0,0,0,0,2};



    for(i=0;i<GRID_DIMENTION;i++){
        for(j=0;j<GRID_DIMENTION;j++){
            //x = randomnum(0,100);
            x = tt[y];
            y++;
            tiletype t;
            if(x==1)
                t=_notaccesible;
            else if(x==0)
                t=_common;
            else
                t=_market;
            bgrid[i][j] = new tile(i,j,t);
        }
    }

    heroInitialization();
    Market = new market();

}

void battlegrid::displaygrid(){
    int i,j,x,y;

    for(i=0;i<GRID_DIMENTION;i++){
        for(j=0;j<GRID_DIMENTION;j++){
          x=heroList.front()->currentTile->get_x();
          y=heroList.front()->currentTile->get_y();
          if(x==i && y==j){
            cout<<"H  ";
            continue;
          }

            tile* g = bgrid[i][j];
            switch(g->get_type()){
                case _common:
                    cout << "#  ";
                    break;
                 case _notaccesible:
                    cout << "N  ";
                    break;
                 case _market:
                    cout << "M  ";
                    break;
                default:
                    break;

            }
        }
        cout  << endl << endl;
    }
}

tile* battlegrid::move(tile *current, moveto m_next){
    int x = current->get_x();
    int y = current->get_y();
    tile *newloc = current;
    tile *temploc = NULL;
    switch(m_next){
        case m_left:
                  if(y==0){
                    cout << "Move can not be made, unless you want to fall outside the world" << endl;
                    return current;
                  }
                  else{
                    y = y-1;
                    temploc = bgrid[x][y];
                  }
                  break;
        case m_right:
                    if(y==GRID_DIMENTION-1){
                      cout << "Move can not be made, unless you want to fall outside the world" << endl;
                      return current;
                    }
                    else{
                      y = y+1;
                      temploc = bgrid[x][y];
                    }
                    break;
        case m_up:
                    if(x==0){
                      cout << "Move can not be made, unless you want to fall outside the world" << endl;
                      return current;
                    }
                    else{
                      x = x-1;
                      temploc = bgrid[x][y];
                    }
                    break;
        case m_down:
                     if(x==GRID_DIMENTION-1){
                       cout << "Move can not be made, unless you want to fall outside the world" << endl;
                       return current;
                     }
                     else{
                       x = x+1;
                       temploc = bgrid[x][y];
                     }
                     break;
        default:
                break;
   }

   if(temploc->get_type()==_notaccesible){
       cout << "This place is forbidden by the world's Master" << endl;
       return current;
   }
   else{
       newloc = temploc;
   }
   return newloc;
}

market::market(){
    string iname;
    Item *itemtoadd;
    Spell *spelltoadd;

    weaponInitialization();
    armorInitialization();
    spellInitialization();
    potionInitialization();
}

market::~market(){

}

void market::viewitemlist(list<Item*> itemList){
    itItem=itemList.begin();
    int a = 1;
    while(itItem != itemList.end()){
        cout <<endl<< a << ". ";
        (*itItem)->displayItem(); cout<< endl;
        itItem++;
        a++;
    }

}

void market::viewspelllist(){
    itSpell = spellList.begin();
    int a = 1;
    while(itSpell != spellList.end()){
        cout << a << ". " << (*itSpell)->getName() <<endl<< "Price ->  " << (*itSpell)->getPrice() <<endl<< "Damage ->  " << (*itSpell)->getDamage()
              <<endl<< "Level ->  " << (*itSpell)->getSpellLevel() <<endl <<endl;
        itSpell++;
        a++;
    }

}

void market::buy(list<Item*>::iterator &itemtobuy, list<Hero*>::iterator &buyer){
    int moneytospend = (*buyer)->getMoney();
    int moneycost = (*itemtobuy)->getPrice();
    if(moneycost<=moneytospend){
        (*buyer)->itemList.push_back(*itemtobuy);
        (*buyer)->setMoney(moneytospend-moneycost);
    }
    else{
        cout << "Not enough money" << endl;
    }
}

void market::buy(list<Spell*>::iterator& spelltobuy,list<Hero*>::iterator &buyer){
    int moneytospend = (*buyer)->getMoney();
    int moneycost = (*spelltobuy)->getPrice();
    if(moneycost<=moneytospend){
        (*buyer)->spellList.push_back(*spelltobuy);
        (*buyer)->setMoney(moneytospend-moneycost);
    }
    else{
        cout << "Not enough money" << endl;
    }
}

void market::sell(list<Item*>::iterator& itemtosell,list<Hero*>::iterator &seller){
    int moneytoget = (*itemtosell)->getPrice();
    moneytoget = moneytoget/2;
    (*seller)->addMoney(moneytoget);
    (*seller)->itemList.remove(*itemtosell);
}

void market::sell(list<Spell*>::iterator& spelltosell,list<Hero*>::iterator &seller){
    int moneytoget = (*spelltosell)->getPrice();
    moneytoget = moneytoget/2;
    (*seller)->addMoney(moneytoget);
    (*seller)->spellList.remove(*spelltosell);
}

void market::weaponInitialization(){
       ifstream infile("Weapon.txt");
       string name;
       int damage,price;
       bool onehanded;
       Weapon* weapon;

       for(int level=1;level<=10;level++){
         getline(infile,name);
         damage=200*level;
         price=100*level;
         onehanded=rand()%2;
         weapon= new Weapon(name,price,level,damage,onehanded);
         weaponList.push_back(weapon);
       }
}

void market::armorInitialization(){
       ifstream infile("Armor.txt");
       string name;
       int defence,price;
       Armor* armor;

       for(int level=1;level<=10;level++){
         getline(infile,name);
         defence=50*level;
         price=100*level;

         armor= new Armor(name,price,level,defence);
         armorList.push_back(armor);
       }

}

void market::spellInitialization(){
       IceSpell* iceSpell;
       FireSpell* fireSpell;
       LightningSpell* lightningSpell;
       int damage,price,debuff;
       for(int level=1;level<=10;level++){
         damage=100*level;
         price=100*level;

         debuff=20*level;
         iceSpell= new IceSpell(level,debuff,price,damage);
         spellList.push_back(iceSpell);

         debuff=10*level;
         fireSpell= new FireSpell(level,debuff,price,damage);
         spellList.push_back(fireSpell);

         debuff=30+(10*level);
         lightningSpell= new LightningSpell(level,debuff,price,damage);
         spellList.push_back(lightningSpell);
       }

}

void market::potionInitialization(){
       ifstream infile("Potion.txt");
       string name;
       int buff,price;
       Potion* potion;
       bool used=0;

       for(int level=1;level<=10;level++){
         getline(infile,name);
         buff=10*level;
         price=100*level;

         potion= new Potion(name,price,level,buff,used);
         potionList.push_back(potion);
       }
}

void  battlegrid::heroInitialization(){
       int numOfHeroes,heroRace;
       string name;
       while(1){
         cout<<"Enter the number of heroes in your party(1-3): ";
         cin>>numOfHeroes;
         cout<<endl;
         if(cin.fail()){
           char dummy;
           cin.clear();
           dummy= '\0';
           while(dummy != '\n')
            cin.get(dummy);
         }
         if(numOfHeroes<1||numOfHeroes>3){
           cout<<"Really???... Is it so hard? 1 OR 2 OR 3!!! Lets try again :)"<<endl;
           continue;
         }
         break;
       }
       for(int i=1;i<=numOfHeroes;i++){
         cout<<"1.Warrior(high strength and agility)"<<endl;
         cout<<"2.Mage(high dexterity and agility)"<<endl;
         cout<<"3.Paladin(high strength and dexterity)"<<endl;
         do{
           cout<<"Choose race for your hero No"<<i<<": ";
           cin>>heroRace; cout<<endl;
           if(cin.fail()){
             char dummy;
             cin.clear();
             dummy= '\0';
             while(dummy != '\n')
               cin.get(dummy);
           }
         }while(heroRace<1 || heroRace>3);
         switch (heroRace) {

           case 1:
                  cout<<"Enter Warrior's name: ";
                  cin>>name;cout<<endl;
                  Warrior* warrior;
                  warrior= new Warrior(name);
                  heroList.push_back(warrior);
                  break;

           case 2:
                  cout<<"Enter Mage's name: ";
                  cin>>name;cout<<endl;
                  Mage* mage;
                  mage= new Mage(name);
                  heroList.push_back(mage);
                  break;

           case 3:
                  cout<<"Enter Paladin's name: ";
                  cin>>name;cout<<endl;
                  Paladin* paladin;
                  paladin= new Paladin(name);
                  heroList.push_back(paladin);
                  break;

         }
       }
}

void  battlegrid::monsterInitialization(int _level,size_t _numOfMonsters){
       int species;
       Monster* monster;
       for(int i=0;i<_numOfMonsters;i++){
         species=rand()%3;
         switch (species){
           case 0:
                  monster= new Dragon(_level);
                  monsterList.push_back(monster);
                  break;
           case 1:
                  monster= new Exoskeleton(_level);
                  monsterList.push_back(monster);
                  break;
           case 2:
                  monster= new Spirit(_level);
                  monsterList.push_back(monster);
                  break;
         }
       }
}


void battlegrid::fight(){
       list<Hero*>::iterator itHero;

       list<Monster*>::iterator itMonster;
       int choice,receivedDamage,xp,gold=20,flag=0;

       for(int i=0;i<100;i++)
        cout<<endl;

       itHero=heroList.begin();
       monsterInitialization((*itHero)->getLevel(),heroList.size());
       itMonster=monsterList.begin();

       cout<<"Some monsters appeared.";
       for(int i=0;i<monsterList.size();i++){
         (*itMonster)->displayStats();
         itMonster++;
       }

       while(1){
         cout<<"**************************************"<<endl;
         itHero=heroList.begin();
         for(int j=0;j<heroList.size();j++){
           (*itHero)->displayStats();
           itHero++;
         }

         itHero=heroList.begin();
         for(int j=0;j<heroList.size();j++){
           if((*itHero)->getHealthPoints()==0){
             itHero++;
             continue;
           }

           while(1){

               cout<<endl<<endl<<"It's "<<(*itHero)->getName()<<" turn."<<endl<<endl;
               cout<<"1.Basic Attack"<<endl<<"2.Cast Spell"<<endl<<"3.Go to Inventory"<<endl;
               cout<<"Choose your action:";
               cin>>choice;cout<<endl;
               if(cin.fail()){
                 char dummy;
                 cin.clear();
                 dummy= '\0';
                 while(dummy != '\n')
                   cin.get(dummy);
                 }
               if(choice>3||choice<1){
                 cout<<"Invalid Input. Please try again."<<endl;
                 continue;
               }
               break;
           }

           switch (choice) {

             case 1:
                    itMonster=monsterList.begin();
                    for(int k=0;k<monsterList.size();k++){
                      if((*itMonster)->getHealthPoints()!=0)
                        break;
                        itMonster++;
                    }

                    if((*itMonster)->dodgedAttack()==1){
                      cout<<"The Monster dodged your attack. May the force be with you on the next try."<<endl;
                      break;
                    }

                    if( (*itMonster)->receivedDamage((*itHero)->attackDamage()) > (*itMonster)->getHealthPoints() ){
                      cout<<"Congratulations you have killed the monster."<<endl;
                      (*itMonster)->setHealthPoints(0);
                    }
                    else{
                      receivedDamage=(*itMonster)->receivedDamage((*itHero)->attackDamage());
                      (*itMonster)->setHealthPoints((*itMonster)->getHealthPoints()-receivedDamage);
                    }
                    cout<<"**************************************"<<endl;
                    cout<<"Monster's stats"<<endl<<endl;
                    itMonster=monsterList.begin();
                    for(int k=0;k<monsterList.size();k++){
                      (*itMonster)->displayStats();
                      itMonster++;
                    }
                    break;

              case 2:
                     itMonster=monsterList.begin();
                     for(int k=0;k<monsterList.size();k++){
                       if((*itMonster)->getHealthPoints()!=0)
                       break;
                       itMonster++;
                     }

                     if((*itMonster)->dodgedAttack()==1){
                       cout<<"The Monster dodged your attack. May the force be with you on the next try."<<endl;
                       break;
                     }

                     (*itHero)->spellCast();

                     if( (*itMonster)->receivedDamage((*itHero)->spellDamage()) > (*itMonster)->getHealthPoints() ){
                       cout<<"Congratulations you have killed the monster."<<endl;
                       (*itMonster)->setHealthPoints(0);
                     }
                     else{
                       receivedDamage=(*itMonster)->receivedDamage((*itHero)->spellDamage());
                       (*itMonster)->setHealthPoints((*itMonster)->getHealthPoints()-receivedDamage);
                       if((*itMonster)->spell==NULL){            /*If the monster isn't effected by any spell */
                         (*itMonster)->spell=(*itHero)->spell;
                         (*itMonster)->setDebuffRounds((*itMonster)->spell->getDebuffRounds());
                         if((*itMonster)->spell->getName()=="Ice Spell"){
                           (*itMonster)->setStrength((*itMonster)->getStrength()-(*itMonster)->spell->getDebuff());
                         }
                         else if((*itMonster)->spell->getName()=="Fire Spell"){
                           (*itMonster)->setDefence((*itMonster)->getDefence()-(*itMonster)->spell->getDebuff());
                         }
                         else if((*itMonster)->spell->getName()=="Lightning Spell"){
                           (*itMonster)->setAgility((*itMonster)->getAgility()-(*itMonster)->spell->getDebuff());
                         }
                       }
                       else{ /*If the monster is effected by a spell, first we have to remove the debuff of the existed spell*/
                             /*and only then we can cast the new spell on the monster*/
                         if((*itMonster)->spell->getName()=="Ice Spell"){
                           (*itMonster)->setStrength( (*itMonster)->getStrength() + (*itMonster)->spell->getDebuff());
                         }
                         else if((*itMonster)->spell->getName()=="Fire Spell"){
                           (*itMonster)->setDefence( (*itMonster)->getDefence() + (*itMonster)->spell->getDebuff());
                         }
                         else if((*itMonster)->spell->getName()=="Lightning Spell"){
                           (*itMonster)->setAgility( (*itMonster)->getAgility() + (*itMonster)->spell->getDebuff());
                         }

                         (*itMonster)->spell=(*itHero)->spell;
                         (*itMonster)->setDebuffRounds( (*itMonster)->spell->getDebuffRounds());
                         if((*itMonster)->spell->getName()=="Ice Spell"){
                           (*itMonster)->setStrength( (*itMonster)->getStrength() - (*itMonster)->spell->getDebuff());
                         }
                         else if((*itMonster)->spell->getName()=="Fire Spell"){
                           (*itMonster)->setDefence( (*itMonster)->getDefence() - (*itMonster)->spell->getDebuff());
                         }
                         else if((*itMonster)->spell->getName()=="Lightning Spell"){
                           (*itMonster)->setAgility( (*itMonster)->getAgility() - (*itMonster)->spell->getDebuff());
                         }
                       }
                     }

                     cout<<"**************************************"<<endl;
                     cout<<"Monster's stats"<<endl<<endl;
                     itMonster=monsterList.begin();
                     for(int k=0;k<monsterList.size();k++){
                       (*itMonster)->displayStats();
                       itMonster++;
                     }
                     break;

              case 3:
                     (*itHero)->checkInvetory();
                     break;
           }
           itMonster=monsterList.begin();
           for(int k=0;k<monsterList.size();k++){
             if((*itMonster)->getHealthPoints()==0){
               flag=1;
               itMonster++;
               continue;
             }
             else{
               flag=0;
               break;
             }
           }

           if(flag==1)
            break;

           itHero++;
         }


         if(flag==1){
           itHero=heroList.begin();
           gold= 20*(*itHero)->getLevel()+10*monsterList.size();
           xp=100+20*monsterList.size();
           for(int k=0;k<heroList.size();k++){
             if((*itHero)->getHealthPoints()==0){
               (*itHero)->setHealthPoints(500);
               (*itHero)->addExperience(xp);
               (*itHero)->addMoney(gold);
             }
             else{
               (*itHero)->addExperience(xp);
               (*itHero)->addMoney(gold);
             }
             itHero++;
           }
           cout<<endl<<endl<<"Well done you won the fight!"<<endl;
           break;
         }

         /*Monster's turn*/
         itMonster=monsterList.begin();
         for(int i=0;i<monsterList.size();i++){
           if((*itMonster)->getHealthPoints()==0){
             itMonster++;
             continue;
           }

           if((*itMonster)->spell!=NULL){
             if((*itMonster)->getDebuffRounds()==0){

               if((*itMonster)->spell->getName()=="Ice Spell"){
                 (*itMonster)->setStrength( (*itMonster)->getStrength() + (*itMonster)->spell->getDebuff());
               }
               else if((*itMonster)->spell->getName()=="Fire Spell"){
                 (*itMonster)->setDefence( (*itMonster)->getDefence() + (*itMonster)->spell->getDebuff());
               }
               else if((*itMonster)->spell->getName()=="Lightning Spell"){
                 (*itMonster)->setAgility( (*itMonster)->getAgility() + (*itMonster)->spell->getDebuff());
               }

               (*itMonster)->spell=NULL;
             }
             else{
               (*itMonster)->minusDebuffRounds();
             }
           }

           itHero=heroList.begin();
           for(int k=0;k<heroList.size();k++){
             if((*itHero)->getHealthPoints()!=0)
               break;
               itHero++;
           }

           if((*itHero)->dodgedAttack()==1){
             cout<<"The force is strong in you, the attack you dodged."<<endl;
             break;
           }

           if( (*itHero)->receivedDamage((*itMonster)->attackDamage()) > (*itHero)->getHealthPoints() ){
             cout<<"Sad story bro. You died."<<endl;
             (*itHero)->setHealthPoints(0);
           }
           else{
             receivedDamage=(*itHero)->receivedDamage((*itMonster)->attackDamage());
             (*itHero)->setHealthPoints((*itHero)->getHealthPoints()-receivedDamage);
           }

           itMonster++;
         }


         itHero=heroList.begin();
         for(int k=0;k<heroList.size();k++){
           if((*itHero)->getHealthPoints()==0){
             flag=1;
             itHero++;
             continue;
           }
           else{
             flag=0;
             break;
           }
         }

         if(flag==1){
           itHero=heroList.begin();
           for(int k=0;k<heroList.size();k++){
             (*itHero)->setHealthPoints(500);
             (*itHero)->setMoney((*itHero)->getMoney()/2);
             itHero++;
           }
           cout<<"You lost the fight. May the force be with you the next time."<<endl;
           break;
         }

       }
}
