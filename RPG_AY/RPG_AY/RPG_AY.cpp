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
using namespace std;

/// <summary>
/// The shell/parent class for all races
/// </summary>
class Race
{
private:
    string origin;
public:
    Race()
    {
        origin = "Not found\n";
    }

    Race(string parOrigin)
    {
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

    string getRace()
    {
        string raceDescript;
        raceDescript = "Race: Elf\nRace Ability: Mana Drain - Gain 50% of damage dealt as mana, or 25% of damage as Fury";
        return raceDescript;
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
            "\nforbidden dark magic.\n")
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

    //class method for manaDrain functionality
};

/// <summary>
/// The shell/superclass of all Characters
/// </summary>
class Character
{
private:
    string name;
    float health;
    string armor;
    string weapon;
protected:
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
        //other race options here
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
        cout << "Paladin: \nName: " << getName() << endl << race.getRace() << "\nHealth: " << getHealth()
            << "\nArmor: " << getArmor() << "\nWeapon: " << getWeapon() << "\nMana: "
            << getMana() << "\nClass passive:\Language of The Ancients - Character can read ancient text" << endl <<
            "\nClass Abilities: \n  Invulerability - A chosen player is invulnerable from damage for X turns"
            "\n  Sword of Light - When cast, all party members are buffed.\n"
            "                   Strength of the buff is dependent on the roll.\n"
            "                   Effect last 3 turns per character"
            "\n  Juggernaut - When cast the paladin pulls the attention of all enemies and\ngains a health increase "
            "of 250 % for the rolled duration.\n";
    }
};

void fillName(Character& character);
void fillRace(Character character);

int main()
{
    Paladin player1 = Paladin();
    
    fillName(player1);
    fillRace(player1);
    player1.getCharacterDescript();

    system("PAUSE");
    return 0;
}

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
void fillRace(Character character)
{
    int race;
    cout << "Would you like to be an Elf(1), an Orc(2), a Dwarf(3), or a Human(4)." << endl;
    cin >> race;
    if (race == 1)
    {
        character.setRace("Elf");
    }
    //else
    //{
    //    cout << "No other Race options at this time, Race will be elf" << endl;
    //    character.setRace("Elf");
    //}
}
//Problems: The lack of knowledge of inheritance in C++ has made this part of the project extremely difficult for me and my plans.
//          I thought it would work hoping it functioned close to java, I dont know how to make my idea work without the knowledge of 
//          how inheritance works. I'm not sure my RPG-1 fit the criteria for this part of the project.