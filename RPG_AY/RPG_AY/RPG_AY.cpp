/*Austin Youngren
* 2/16/22
* Descripton: Dark Rain is an RPG where players can create a character by choosing a race and a character class.
* The first expansion of Dark Rain gives you access to Saurgon's home races and character classes. Players use their
* chosen character's arsenal to fight off the undead spawning from the dirt to protect their home and find the source
* of this dark power.
*
* Dark Rain takes place in an alternative universe, on the planet Saurgon. The races of Saurgon seem to be within
* their Medieval period of development. The Intergalactic Federation often stays out of the business of developing
* civilizations, but the planet has raised concerns through the Intergalactic Federation’s Department of Observation
* for Developing Worlds. Black Clouds seem to be forming in various areas and the rain from these clouds raise all
* corpses of life from the dead. These corpses seem to have no true conscious of their own and slay any living being
* in their wake. Due to the unknown origins of the “supernatural” occurrence, the Intergalactic federation forms a
* team of Soldiers and Scientists to research these happenings to form a consensus for intervention.
*
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// <summary>
/// The shell/parent class for all races
/// </summary>
class Race
{
protected:
    string raceType;
    string origin;

public:
    Race()
    {
        raceType = "None Give";
        origin = "Not found\n";
    }

    Race(string parOrigin, string parRaceType)
    {
        raceType = parRaceType;
        origin = parOrigin;
    }

    void setOrigin(string parOrigin)
    {
        origin = parOrigin;
    }

    string getOrigin()
    {
        return origin;
    }

    void setRaceType(string parRaceType)
    {
        origin = parRaceType;
    }

    string getRaceType()
    {
        return raceType;
    }

   
};

/// <summary>
/// The subclass of Race for Elf
/// </summary>
class Elf : public Race
{
private:
    bool manaDrain;
public:
    Elf()
        : Race("The people of the wood. Elves live in solidarity from the other "
            "\nraces and protect the wood from danger. Elves are know for being "
            "\nblessed with mana, though some still choose to sharpen their dexterity "
            "\nwith more “primitive” weaponry.The woods are their sanctuary, and they "
            "\nwill do all in their power to protect it, even if that means accessing "
            "\nforbidden dark magic.\n", "Elf")
    {
        manaDrain = true;
    }

    /// <summary>
    /// setters & getters
    /// </summary>
    /// <param name="castable"> whether the spell can be cast or not</param>
    void setManaDrain(bool castable)
    {
        manaDrain = castable;
    }

    bool getManaDrain()
    {
        return manaDrain;
    }

    string getRace()
    {
        string raceDescript;
        raceDescript = "Race: Elf\nRace Ability: Mana Drain - Gain 50% of damage dealt as mana, or 25% of damage as Fury";
        return raceDescript;
    }
    //class method for manaDrain functionality
};

/// <summary>
/// The subclass of Race for Elf
/// </summary>
class Dwarf : public Race
{
private:
    bool strenOfMount;
public:
    Dwarf()
        : Race("The people of the Mountain.Dwarven legends state that the Dwarves\n" 
            "moldedand smithed the mountains of Saurgon in the days of Ancients.\n"
            "The Dwarven Capital can be found in the hollowed Mountain of Mauldorand is the pinnacle of Trade.\n"
            "Races of all sorts flock here for goods.Dwarves often stay neutral in quarrels between the other races.\n", "Dwarf")
    {
        strenOfMount = true;
    }

    /// <summary>
    /// setters & getters
    /// </summary>
    /// <param name="castable"> whether the spell can be cast or not</param>
    void setStrenOfMount(bool castable)
    {
        strenOfMount = castable;
    }

    bool getStrenOfMount()
    {
        return strenOfMount;
    }

    string getRace()
    {
        string raceDescript;
        raceDescript = "Race: Dwarf\nRace Ability: Strength of the Mountain - Health Increases by 50% for 3 turns";
        return raceDescript;
    }
    //class method for manaDrain functionality
};

/// <summary>
/// The subclass of Race for Elf
/// </summary>
class Orc : public Race
{
private:
    bool ofThePack;
public:
    Orc()
        : Race("The nomads of the Desert. Orcs band together to protect their own\n"
            " and pillage villages for resources due to the desert’s harsh environment.\n"
            "Within Orc society, the strongest leads the people and is crowned Chieftain.\n", "Orc")
    {
        ofThePack = true;
    }

    /// <summary>
    /// setters & getters
    /// </summary>
    /// <param name="castable"> whether the spell can be cast or not</param>
    void setOfThePack(bool castable)
    {
        ofThePack = castable;
    }

    bool getOfThePack()
    {
        return ofThePack;
    }

    string getRace()
    {
        string raceDescript;
        raceDescript = "Race: Orc\nRace Ability: Of The Pack - Gain 25% increased damage and health for 3 turns";
        return raceDescript;
    }
    //class method for manaDrain functionality
};

/// <summary>
/// The shell/superclass of all Characters
/// </summary>
class Character
{
protected:
    string name;
    float health;
    string armor;
    string weapon;
    Race race;

public:
    Character()
    {
        name = "Unnamed";
        health = 0;
        armor = "Armorless";
        weapon = "Fists";
    }

    Character(float parHealth, string parArmor, string parWeapon)
    {
        name = "Unnamed";
        health = parHealth;
        armor = parArmor;
        weapon = parWeapon;
    }

    /// <summary>
    /// setters and getters
    /// </summary>
    void setName(string parName)
    {
        name = parName;
    }

    string getName()
    {
        return name;
    }

    void setHealth(float parHealth)
    {
        health = parHealth;
    }

    float getHealth()
    {
        return health;
    }

    void setArmor(string parArmor)
    {
        armor = parArmor;
    }

    string getArmor()
    {
        return armor;
    }

    void setWeapon(string parWeapon)
    {
        weapon = parWeapon;
    }

    string getWeapon()
    {
        return weapon;
    }

    /// <summary>
    /// sets race when creating a character
    /// </summary>
    /// <param name="character"></param>
    void setRace(string raceChoice)
    {
        if (raceChoice._Equal("Elf"))
        {
            race = Elf();
        }
        else if (raceChoice._Equal("Dwarf"))
        {
            race = Dwarf();
        }
        else if (raceChoice._Equal("Orc"))
        {
            race = Orc();
        }
    }

    void getCharacterDescript()
    {
        cout << "Creation Did Not Work" << endl;
    }
    //class methods for Paladin Abilities and their functionality
};

/// <summary>
/// Paladin class, magic/tank support roll
/// </summary>
class Paladin : public Character
{
private:
    float mana;
    const bool langOfAnc = true;
    bool invulnerability;   //My thought process will use bool for the use of abilities. 
    bool swordOfL;          //true - it can be used. false - can't be used.
    bool juggernaut;        //This may be temporary as I see this project unfold. Just bool for now, will adjust as needed.

public:
    Paladin() : Character(100, "Heavy", "Sword and Shield")
    {
        mana = 100;
        invulnerability = true;
        swordOfL = true;
        juggernaut = true;
    }

    /// <summary>
    /// setters and getters
    /// </summary>
    /// <param name="castable"> if the ability can be cast</param>
    void setMana(float parMana)
    {
        mana = parMana;
    }

    float getMana()
    {
        return mana;
    }

    void setInvulnerability(bool castable)
    {
        invulnerability = castable;
    }

    bool getInvulnerability()
    {
        return invulnerability;
    }

    void setSwordOfL(bool castable)
    {
        swordOfL = castable;
    }

    bool getSwordOfL()
    {
        return swordOfL;
    }

    void setJuggernaut(bool castable)
    {
        juggernaut = castable;
    }

    bool getJuggernaut()
    {
        return juggernaut;
    }

        /// <summary>
        /// gets description of character and needed data memebers
        /// </summary>
    void getCharacterDescript()
    {
        cout << "Paladin: \nName: " << name << endl << race.getRaceType() << "\nHealth: " << health
            << "\nArmor: " << armor << "\nWeapon: " << weapon << "\nMana: "<< mana << 
            "\nClass passive:\nLanguage of The Ancients - Character can read ancient text\n" 
            "Class Abilities: \n  Invulerability - A chosen player is invulnerable from damage for X turns\n"
            "  Sword of Light - When cast, all party members are buffed.\n"
            "                 - Strength of the buff is dependent on the roll.\n"
            "                 - Effect last 3 turns per character\n"
            "  Juggernaut - When cast the paladin pulls the attention of all enemies and\ngains a health increase\n"
            "               of 250 % for the rolled duration.\n";
    }
};

/// <summary>
/// Paladin class, magic/tank support roll
/// </summary>
class Mage : public Character
{
private:
    float mana;
    const bool foresight = true;
    bool bloodMagic;   //My thought process will use bool for the use of abilities. 
    bool fireball;          //true - it can be used. false - can't be used.
    bool staticField;        //This may be temporary as I see this project unfold. Just bool for now, will adjust as needed.

public:
    Mage() : Character(100, "Cloth", "Staff")
    {
        mana = 100;
        bloodMagic = true;
        fireball = true;
        staticField = true;
    }

    /// <summary>
    /// setters and getters
    /// </summary>
    /// <param name="castable"> if the ability can be cast</param>
    void setMana(float parMana)
    {
        mana = parMana;
    }

    float getMana()
    {
        return mana;
    }

    void setBloodMagic(bool castable)
    {
        bloodMagic = castable;
    }

    bool getBloodMagic()
    {
        return bloodMagic;
    }

    void setFireball(bool castable)
    {
        fireball = castable;
    }

    bool getFireball()
    {
        return fireball;
    }

    void setStaticField(bool castable)
    {
        staticField = castable;
    }

    bool getStaticField()
    {
        return staticField;
    }

    /// <summary>
    /// gets description of character and needed data memebers
    /// </summary>
    void getCharacterDescript()
    {
        cout << "Mage: \nName: " << name << endl << race.getRaceType() << "\nHealth: " << health
            << "\nArmor: " << armor << "\nWeapon: " << weapon << "\nMana: " << mana <<
            "\nClass passive:\nForesight - Mages can randomly foresee 1 incoming attack per attack round.\n"
            "            Mages can also foresee one opponent before entering a room.\n"
            "Class Abilities: \n  Blood Magic - Character sacrifice 25% total health to convert to mana.\n"
            "  Fireball - Character hurls a fireball at an enemy, enemy may get burned for dot damage.\n"
            "  Static Field - Character casts an AoE electric spell that deals damage to all\n"
            "enemies within range for X amount of turns.\n";
    }
};

/// <summary>
/// Paladin class, magic/tank support roll
/// </summary>
class Archer : public Character
{
private:
    float fury;
    const bool nimble = true;
    bool anArrowForAll;   //My thought process will use bool for the use of abilities. 
    bool gameChanger;          //true - it can be used. false - can't be used.
    bool barrierBreaker;        //This may be temporary as I see this project unfold. Just bool for now, will adjust as needed.

public:
    Archer() : Character(100, "Leather", "Bow")
    {
        fury = 0;
        anArrowForAll = true;
        gameChanger = true;
        barrierBreaker = true;
    }

    /// <summary>
    /// setters and getters
    /// </summary>
    /// <param name="castable"> if the ability can be cast</param>
    void setFury(float parFury)
    {
        fury = parFury;
    }

    float getFury()
    {
        return fury;
    }

    void setAnArrowForAll(bool castable)
    {
        anArrowForAll = castable;
    }

    bool getAnArrowForAll()
    {
        return anArrowForAll;
    }

    void setGameChanger(bool castable)
    {
        gameChanger = castable;
    }

    bool getGameChanger()
    {
        return gameChanger;
    }

    void setBarrierBreaker(bool castable)
    {
        barrierBreaker = castable;
    }

    bool getBarrierBreakers()
    {
        return barrierBreaker;
    }

    /// <summary>
    /// gets description of character and needed data memebers
    /// </summary>
    void getCharacterDescript()
    {
        cout << "Archer: \nName: " << name << endl << race.getRaceType() << "\nHealth: " << health
            << "\nArmor: " << armor << "\nWeapon: " << weapon << "\nFury: "
            << fury << "\nClass passive:\nNimble - ): Can access hard to reach areas (squeeze through crevasses, scale walls)" << endl <<
            "\nClass Abilities: \n  An Arrow For All -: Player loads an arrow in their bow for every enemy. Damage varies."
            "\n  Game Changer - : Player Swiftly grabs arrows from their Quiver to launch at an enemy. Each Arrow deals 7 damage."
            "\n  Barrier Breaker - Player Targets an enemy with an arrow that flies fast enough to break the sound barrier." << endl;
    }
};

/// <summary>
/// Paladin class, magic/tank support roll
/// </summary>
class Barbarian : public Character
{
private:
    float fury;
    const bool brutalMight = true;
    bool ragingCyclone;   //My thought process will use bool for the use of abilities. 
    bool guillotineLunge;          //true - it can be used. false - can't be used.
    bool ambidextrous;        //This may be temporary as I see this project unfold. Just bool for now, will adjust as needed.

public:
    Barbarian() : Character(100, "Leather", "Dual Axes")
    {
        fury = 0;
        ragingCyclone = true;
        guillotineLunge = true;
        ambidextrous = true;
    }

    /// <summary>
    /// setters and getters
    /// </summary>
    /// <param name="castable"> if the ability can be cast</param>
    void setFury(float parFury)
    {
        fury = parFury;
    }

    float getFury()
    {
        return fury;
    }

    void setRagingCyclone(bool castable)
    {
        ragingCyclone = castable;
    }

    bool getRagingCyclone()
    {
        return ragingCyclone;
    }

    void setGuillotineLunge(bool castable)
    {
        guillotineLunge = castable;
    }

    bool getGuillotineLunge()
    {
        return guillotineLunge;
    }

    void setAmbidextrous(bool castable)
    {
        ambidextrous = castable;
    }

    bool getAmbidextrous()
    {
        return ambidextrous;
    }

    /// <summary>
    /// gets description of character and needed data memebers
    /// </summary>
    void getCharacterDescript()
    {
        cout << "Barbarian: \nName: " << name << endl << race.getRaceType() << "\nHealth: " << health
            << "\nArmor: " << armor << "\nWeapon: " << weapon << "\nFury: "
            << fury << "\nClass passive:\nBrutal Might - Basic Attacks deal 50% extra damage" << endl <<
            "\nClass Abilities: \n  Raging Cyclone - Player spins in a cyclone dealing burst damage to all enemies."
            "\n  Guillotine Lunge - Player Lunges forward Dealing a large sum of damage possibly stunning the target."
            "\n  Ambidextrous - Basic Attacks Deal 2x Damage for a certain amount of turns." << endl;
    }
};

void fillName(Character& character);
void fillRace(Character& character);
//Character chooseClass();

int main()
{
    /*vector <Character> players;
    vector <Character> :: iterator iter;
    Character* player = new Character;*/
   
    //char addPlayer;
   
    Paladin player1 = Paladin();
    Mage player2 = Mage();
    Barbarian player3 = Barbarian();
    Archer player4 = Archer();

    fillName(player1);
    fillRace(player1);
    fillName(player2);
    fillRace(player2);
    fillName(player3);
    fillRace(player3);
    fillName(player4);
    fillRace(player4);

    player1.getCharacterDescript();
    player2.getCharacterDescript();
    player3.getCharacterDescript();
    player4.getCharacterDescript();

        /*creation.getCharacterDescript();
        *player = creation;
        player->getCharacterDescript();
        cout << "Is there another character to add?" << endl;
        cin >> addPlayer;*/
     
    system("PAUSE");
    return 0;
}


//Character chooseClass()
//{
//    int choice;
//    
//    cout << "Would you like to be an Paladin(1), an Archer(2), a Mage(3), or a Barbarian(4)." << endl;
//    cin >> choice;
//    
//    while ((choice < 1) || (choice > 4))
//    {
//        cout << "That is not a valid choice, use the numbers associated with the class choices as input." << endl;
//        cout << "Would you like to be an Paladin(1), an Archer(2), a Mage(3), or a Barbarian(4)." << endl;
//        cin >> choice;
//    }
//    if (choice == 1)
//    {
//        Paladin character = Paladin();
//        return character;
//    }
//    else if (choice == 2)
//    {
//        Archer character = Archer();
//        return character;
//    }
//    else if (choice == 3)
//    {
//        Mage character = Mage();
//        return character;
//        
//    }
//    else 
//    {
//        Barbarian character = Barbarian();
//        return character;
//    }
//    
//}

/// <summary>
/// Allows player to set their character name
/// </summary>
/// <param name="character"> a player's character</param>
void fillName(Character& character)
{
    string name;
    cout << "What is your name?" << endl;
    cin >> name;
    character.setName(name);
}

/// <summary>
/// Allows player to set their race
/// </summary>
/// <param name="character"> a player's character </param>
void fillRace(Character& character)
{
    int race;
    cout << character.getName() <<" Would you like to be an Elf(1), an Orc(2), or a Dwarf(3)." << endl;
    cin >> race;
    if (race == 1)
    {
        character.setRace("Elf");
    }
    else if (race == 2)
    {
        character.setRace("Orc");
    }
    else if (race == 3)
    {
        character.setRace("Dwarf");
    }
    else
    {
        cout << "No other Race options at this time, Race will be elf" << endl;
        character.setRace("Elf");
    }
}
//Problems: I am having a very hard time with pointers, I plan on talking with you about them Monday when I am in your office.