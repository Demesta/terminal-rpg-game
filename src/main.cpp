#include "battlegrid.h"

int main(void){

  srand(time(NULL));
  list<Hero*>::iterator itHero;
  list<Item*>::iterator itItem;
  list<Spell*>::iterator itSpell;
  battlegrid *bgrid = new battlegrid;
  moveto moveToTile;
  int exitGame=0,choice=0,choice2,choice3,doFight;

  itHero=bgrid->heroList.begin();
  for(int i=0;i<bgrid->heroList.size();i++){
    (*itHero)->currentTile= new tile(0,0,_common);
    itHero++;
  }

  while(1){
    choice2=0;
    choice3=0;
    if(choice!=5){
      cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
      cout<<"| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | "<<endl;
      cout<<"-------------------------------------------------------------------------------"<<endl;
      bgrid->displaygrid();
    }
    cout<<endl<<"1.Move to a new tile."<<endl<<"2.Check Invetory"<<endl<<"3.Display Hero Stats"<<endl<<"4.Exit Game"<<endl;
    do{
      cout<<"Enter your choice: ";
      cin>>choice;cout<<endl;
      if(cin.fail()){
          char dummy;
          cin.clear();
          dummy= '\0';
          while(dummy != '\n')
          cin.get(dummy);
      }
    }while(choice<1 || choice>4);

      switch (choice) {
        case 1:
               cout<<"Where you would like to move?"<<endl;
               cout<<"1.Move Up"<<endl<<"2.Move Right"<<endl<<"3.Move Down"<<endl<<"4.Move Left"<<endl;
               do{
                 cout<<"Enter your choice: ";
                 cin>>choice3;cout<<endl;
                 if(cin.fail()){
                   char dummy;
                   cin.clear();
                   dummy= '\0';
                   while(dummy != '\n')
                   cin.get(dummy);
                 }
               }while(choice3<1 || choice3>4);
               break;
        case 2:
               itHero=bgrid->heroList.begin();
               cout<<endl;
               for(int i=1;i<=bgrid->heroList.size();i++){
               cout<<i<<"."<<(*itHero)->getName()<<"'s Invetory"<<endl;
               (*itHero)->checkInvetory();
               itHero++;
               }
               choice=5;
               break;
        case 3:
               itHero=bgrid->heroList.begin();
               for(int k=0;k<bgrid->heroList.size();k++){
                 (*itHero)->displayStats();
                 itHero++;
               }
               choice=5;
               break;
        case 4:
               cout<<"It was a wild run. May the force be with you."<<endl;
               exitGame=1;
               break;
      }

      if(choice==5)
        continue;

      if(exitGame==1)
        break;

      switch (choice3) {
        case 1:
               moveToTile=m_up;
               itHero=bgrid->heroList.begin();
               for(int i=1;i<=bgrid->heroList.size();i++){
               (*itHero)->currentTile=bgrid->move((*itHero)->currentTile,moveToTile);
               itHero++;
               }
               break;
        case 2:
               moveToTile=m_right;
               itHero=bgrid->heroList.begin();
               for(int i=1;i<=bgrid->heroList.size();i++){
                 (*itHero)->currentTile=bgrid->move((*itHero)->currentTile,moveToTile);
                 itHero++;
               }

               break;
        case 3:
               moveToTile=m_down;
               itHero=bgrid->heroList.begin();
               for(int i=1;i<=bgrid->heroList.size();i++){
                 (*itHero)->currentTile=bgrid->move((*itHero)->currentTile,moveToTile);
                 itHero++;
               }
               break;
        case 4:
               moveToTile=m_left;
               itHero=bgrid->heroList.begin();
               for(int i=1;i<=bgrid->heroList.size();i++){
                 (*itHero)->currentTile=bgrid->move((*itHero)->currentTile,moveToTile);
                 itHero++;
               }
               break;
        default:
                break;

      }
      itHero=bgrid->heroList.begin();
      if((*itHero)->currentTile->get_type()==_market){
        for(int i=1;i<=bgrid->heroList.size();i++){
          while(1){
            cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
            cout<<"| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | "<<endl;
            cout<<"-------------------------------------------------------------------------------"<<endl;
            cout<<(*itHero)->getName()<<" is on the Market."<<endl;
            cout<<"You have "<<(*itHero)->getMoney()<<" gold to spend"<<endl;
            do{
              cout<<"1.Buy Weapon"<<endl<<"2.Buy Armor"<<endl<<"3.Buy Potion"<<endl<<"4.Buy Spell"<<endl<<"5.Sell Item"<<endl
              <<"6.Sell Spell"<<endl<<"7.Check Your Invetory"<<endl<<"8.Exit Market"<<endl<<"Enter your choice: ";
              cin>>choice;cout<<endl;
              if(cin.fail()){
                char dummy;
                cin.clear();
                dummy= '\0';
                while(dummy != '\n')
                cin.get(dummy);
              }
            }while(choice<1 || choice>8);

            switch (choice) {
                case 1:
                       bgrid->Market->viewitemlist(bgrid->Market->weaponList);
                       do{
                         cout<<"Enter your choice: "; cin>>choice2; cout<<endl;
                         if(cin.fail()){
                           char dummy;
                           cin.clear();
                           dummy= '\0';
                           while(dummy != '\n')
                             cin.get(dummy);
                         }
                       }while(choice2<1 || choice2>bgrid->Market->weaponList.size());
                       bgrid->Market->itItem=bgrid->Market->weaponList.begin();
                       for(int k=1;k<choice2;k++)
                         bgrid->Market->itItem++;
                       bgrid->Market->buy(bgrid->Market->itItem,itHero);
                       break;
                case 2:
                       bgrid->Market->viewitemlist(bgrid->Market->armorList);
                       do{
                         cout<<"Enter your choice: "; cin>>choice2; cout<<endl;
                         if(cin.fail()){
                           char dummy;
                           cin.clear();
                           dummy= '\0';
                           while(dummy != '\n')
                             cin.get(dummy);
                         }
                       }while(choice2<1 || choice2>bgrid->Market->armorList.size());
                       bgrid->Market->itItem=bgrid->Market->armorList.begin();
                       for(int k=1;k<choice2;k++)
                         bgrid->Market->itItem++;
                       bgrid->Market->buy(bgrid->Market->itItem,itHero);
                       break;
                case 3:
                       bgrid->Market->viewitemlist(bgrid->Market->potionList);
                       do{
                         cout<<"Enter your choice: "; cin>>choice2; cout<<endl;
                         if(cin.fail()){
                           char dummy;
                           cin.clear();
                           dummy= '\0';
                           while(dummy != '\n')
                             cin.get(dummy);
                         }
                       }while(choice2<1 || choice2>bgrid->Market->potionList.size());
                       bgrid->Market->itItem=bgrid->Market->potionList.begin();
                       for(int k=1;k<choice2;k++)
                         bgrid->Market->itItem++;
                       bgrid->Market->buy(bgrid->Market->itItem,itHero);
                       break;

                case 4:
                       bgrid->Market->viewspelllist();
                       do{
                         cout<<"Enter your choice: "; cin>>choice2; cout<<endl;
                         if(cin.fail()){
                           char dummy;
                           cin.clear();
                           dummy= '\0';
                           while(dummy != '\n')
                             cin.get(dummy);
                         }
                       }while(choice2<1 || choice2>bgrid->Market->spellList.size());
                       bgrid->Market->itSpell=bgrid->Market->spellList.begin();
                       for(int k=1;k<choice2;k++)
                         bgrid->Market->itSpell++;
                       bgrid->Market->buy(bgrid->Market->itSpell,itHero);
                       break;
                case 5:
                       if((*itHero)->itemList.size()==0){
                         cout<<"You don't have any item to sell."<<endl;
                         break;
                       }

                       itItem=(*itHero)->itemList.begin();

                       for(int k=1;k<=(*itHero)->itemList.size();k++){
                         cout<<k<<".";
                         (*itItem)->displayItem();
                         itItem++;
                       }

                       do{
                         cout<<"Enter your choice: "; cin>>choice2; cout<<endl;
                         if(cin.fail()){
                           char dummy;
                           cin.clear();
                           dummy= '\0';
                           while(dummy != '\n')
                             cin.get(dummy);
                           }
                       }while(choice2<1 || choice2>(*itHero)->itemList.size());
                       itItem=(*itHero)->itemList.begin();
                       for(int k=1;k<choice2;k++)
                         itItem++;
                       bgrid->Market->sell(itItem,itHero);
                       break;
                case 6:
                       if((*itHero)->spellList.size()==0){
                         cout<<"You don't have any spell to sell"<<endl;
                         break;
                       }
                       itSpell=(*itHero)->spellList.begin();

                       for(int k=1;k<=(*itHero)->spellList.size();k++){
                         cout<<k<<".";
                         (*itSpell)->displayStats();
                         itSpell++;
                       }

                       do{
                         cout<<"Enter your choice: "; cin>>choice2; cout<<endl;
                         if(cin.fail()){
                           char dummy;
                           cin.clear();
                           dummy= '\0';
                           while(dummy != '\n')
                             cin.get(dummy);  
                         }
                       }while(choice2<1 || choice2>(*itHero)->spellList.size());
                       itSpell=(*itHero)->spellList.begin();
                       for(int k=1;k<choice2;k++)
                         itSpell++;
                       bgrid->Market->sell(itSpell,itHero);
                       break;
                case 7:
                       (*itHero)->checkInvetory();
                       break;
                case 8:
                       choice2=1;
                       cout<<"Byee!!"<<endl;
                       break;
                default:
                        break;
            }
            if(choice==8)
              break;
          }
          itHero++;
        }
      }

      itHero=bgrid->heroList.begin();
      if((*itHero)->currentTile->get_type()==_common){
        doFight=rand()%100;
        if(doFight<=20){
          bgrid->fight();
        }
      }
  }

  return 0;
}
