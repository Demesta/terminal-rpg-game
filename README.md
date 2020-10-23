# Contributors 

- Qwerkykk
- Demesta

# About
This project is a university assignment for the course "Introduction to OOP" where we were called to create a simple terminal RPG game.


# Compile and Run
- Compile: run "make"
- Run: run "./rpg"


# More details about the game 
Max Level: 10

Max experience per Level: 1000

Map: 'H' for heroes, 'M' for market , Empty tiles for possible encounter

Classes

- Warrior:

        Health=1000
        magicPower=50
        strength=150xLevel
        dexterity+=75
        agility=100-->10% to dodge an attack(+20[2%] on each level. Cant be more than 400[40%])
        money=400 gold

- Mage:

        Health=1000
        magicPower=50
        strength+=75
        dexterity=150xLevel
        agility=100-->10% to dodge an attack(+20[2%] on each level. Cant be more than 400[40%])
        money=400 gold

- Paladin:

        Health=1000
        magicPower=50
        strength150xLevel
        dexterity=150xLevel
        agility=50-->5% to dodge an attack(+10[1%] on each level. Cant be more than 400[40%])
        money=400 gold



ITEMS

    Price: 100xItemLevel
    Damage: 200xItemLevel
    Defence: 50xItemLevel
    Potion Buff:10xItemLevel


SPELLS

    Damage:100xSpellLevel(max+20%)
    Price: 100xSpellLevel
    Mana cost: 25
    Debuff rounds:2

- Ice Spell: Attack Damage Debuff:20*spellLevel

- Fire Spell: Defence debuff: 10*spellLevel

- Lightning Spell: Agility debuff: 30+(10*spellLevel)


Monsters

Attack Damage range: (strength + random 0-20%)


Dragon

    Strength:80xHeroLevel
    Defence:25xHeroLevel
    Agility:100(+15 For each HeroLevel)

Exoskeleton

    Strength:40xHeroLevel
    Defence:50xHeroLevel
    Agility:100(+15 for each HeroLevel)

Spirit

    Strength:40xHeroLevel
    Defence:25xHeroLevel
    Agility:200(+15 for each HeroLevel)


