#include "Item.h"
#include "Living.h"
#include "Spell.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <list>

using namespace std;

#define GRID_DIMENTION 12

enum tiletype{
    _common,
    _notaccesible,
    _market
};

enum moveto{
    m_up,
    m_down,
    m_left,
    m_right
};

class tile{
    private:
        int location_x;
        int location_y;
        tiletype t_type;
    public:
        tile(int, int, tiletype);
        tiletype get_type(){return t_type;};
        int get_x(){return location_x;};
        int get_y(){return location_y;};

};

class market{
    private:
    public:
        list<Spell*> spellList;
        list<Spell*>::iterator itSpell;
        list<Item*> weaponList;
        list<Item*> armorList;
        list<Item*> potionList;
        list<Item*>::iterator itItem;
        market();
        ~market();

        void weaponInitialization();
        void armorInitialization();
        void spellInitialization();
        void potionInitialization();



        void viewitemlist(list<Item*> itemList);
        void viewspelllist();
        void buy(list<Item*>::iterator& ,list<Hero*>::iterator&);
        void buy(list<Spell*>::iterator&, list<Hero*>::iterator&);
        void sell(list<Item*>::iterator& , list<Hero*>::iterator&);
        void sell(list<Spell*>::iterator&, list<Hero*>::iterator&);

};

class battlegrid{
    private:
        tile *bgrid[GRID_DIMENTION][GRID_DIMENTION];

     public:
        list<Monster*> monsterList;
        list<Hero*> heroList;
        market *Market;
        battlegrid();
        void displaygrid();
        tile* move(tile*, moveto);

        void heroInitialization();
        void monsterInitialization(int _level,size_t _numOfMonsters);
        void fight();
};
