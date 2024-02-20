// Dungeon.h
#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void txtRed()
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
}
void txtGreen()
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}
void txtWhite()
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

class Dungeon
{

public:
    // string a;
    int health = 100;
    int life = 3;
    int demonHealth = 100;
    string demonName = "Dev";
    string demonWeapon = "Shin Sword";
    int demonDamage = 20;
    int damageToPerform;

    const string weapons[3] = {"Twin Shadow Blades", "Valiant Defender", "Staff of Arcane"};
    string characterSelected, weaponGiven;

    void drawArt()
    {
        txtGreen();
        std::cout << " ___ \n";
        std::cout << "| . \\ _ _ ._ _  ___  ___  ___ ._ _ \n";
        std::cout << "| | || | || ' |/ . |/ ._>/ . \\| ' |\n";
        std::cout << "|___/`___||_|_|\\_. |\\___.\\___/|_|_|\n";
        std::cout << "               <___'\n"
                  << endl
                  << endl;
        txtWhite();
    }

    void displayName(void)
    {
        cout << "Please Wait.";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << "." << endl;
        Sleep(2000);
        system("cls");

        drawArt();

        Sleep(2000);
    }
    void selectCharacter(void)
    {
        int choice;
        string weaponAlloted;
        cout << "::::::::::::::::::::::::::::::" << endl
             << endl;

        cout << "=== Select Your Character ===" << endl
             << endl;

        cout << "::::::::::::::::::::::::::::::" << endl
             << endl;

        cout << "1. Adlein" << endl
             << "2. Brian" << endl
             << "3. Cheoron" << endl;
        Sleep(2000);
        cout << "Select from the above 3: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            weaponAlloted = weapons[0];
            weaponGiven = weapons[0];
            break;

        case 2:
            weaponAlloted = weapons[1];
            weaponGiven = weapons[1];
            break;
        case 3:
            weaponAlloted = weapons[2];
            weaponGiven = weapons[2];
            break;
        default:
            cout << "Unknown Error Occured!" << endl
                 << "Please Restart";
            exit(1);
            break;
        }

        switch (choice)
        {
        case 1:
            characterSelected = "Adlein";
            cout << "::: You have selected " << characterSelected << " as your character.";
            Sleep(2000);
            cout << "\n:: Keep an eye on your character's health bar which is " << health << "\% .";
            Sleep(2000);
            cout << "\n:: Also Use your " << life << " lifes Carefully.";
            Sleep(2000);
            cout << "\n:: Your Weapon is **" << weaponAlloted << "**.\n";
            break;

        case 2:
            characterSelected = "Brian";
            cout << "\n:: You have selected " << characterSelected << " as your character.";
            Sleep(2000);
            cout << "\n:: Keep an eye on your character's health bar which is " << health << "\% .";
            Sleep(2000);
            cout << "\n:: Also Use your " << life << " lifes Carefully.";
            cout << "\n:: Your Weapon is **" << weaponAlloted << "**.\n";
            break;

        case 3:
            characterSelected = "Cheoron";
            cout << "\n::: You have selected " << characterSelected << " as your character.";
            Sleep(2000);
            cout << "\n::: Keep an eye on your character's health bar which is " << health << "\% .";
            Sleep(2000);
            cout << "\n::: Also Use your " << life << " lifes Carefully.";
            Sleep(2000);
            cout << "\n:: Your Weapon is **" << weaponAlloted << "**.\n";
            break;
        default:
            cout << "Invalid Choice!";
            break;
        }
    }
};

class Attackers
{
public:
    void demonAttack(Dungeon &character)
    {
        system("cls");
        character.drawArt();
        txtGreen();
        cout << "::]> A Demon named " << character.demonName << " has just appeared!";
        cout << "\n::]> Be Carefull about " << character.demonName << "'s Weapon which is " << character.demonWeapon << ".\n";
        cout << "::]>" << character.demonName << "'s Health is " << character.demonHealth << "%." << endl;

        txtRed();
        cout << "::]> The Demon is Attacking on " << character.characterSelected << endl;
        txtGreen();

        cout << "::]> BE PREPARED!!! ";
        txtWhite();
    }

    void Attack(Dungeon &character)
    {
        system("cls");
        character.drawArt();

        int damage[3] = {30, 20, 10};
        // int damageToPerform;
        string power[3] = {"Twin Shadow Blades", "Valiant Defender", "Staff of Arcane"};
        if (character.characterSelected == "Adlein")
        {
            character.damageToPerform = damage[0];
        }
        else if (character.characterSelected == "Brian")
        {
            character.damageToPerform = damage[1];
        }
        else if (character.characterSelected == "Cheoron")
        {
            character.damageToPerform = damage[2];
        }
        else
        {
            cout << "Out Of Range...";
            exit(1);
        }

        txtRed();
        cout << character.characterSelected << " is performing an " << character.weaponGiven << "  Attack!" << endl;
        Sleep(2000);
        // character.demonHealth -= damageToPerform;

        txtWhite();
        if (character.demonHealth < 0)
        {
            cout << character.demonName << "'s Remaining Health ::> " << character.demonHealth << endl;
            txtGreen();
            cout << character.demonName << " Has been Defeated." << endl;
        }
        else
        {
            cout << character.demonName << "'s Remaining Health ::> " << character.demonHealth << endl;
        }
    }
};

class Game
{
public:
    Dungeon Player1;
    Attackers Attack;
    void startGameFromScratch()
    {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset to default color

        Player1.displayName();
        Player1.selectCharacter();
        while (Player1.demonHealth > 0)
        {
            Attackers attacker;
            attacker.Attack(Player1);
            attacker.demonAttack(Player1);
            Player1.demonHealth -= Player1.damageToPerform;

            // Check if player's health is 0 or less
            if (Player1.demonHealth <= 0)
            {
                txtGreen();
                cout << "Game Over! " << Player1.demonName << " has been defeated." << endl;
                txtWhite();
                break;
            }

            char choice;
            cout << "Do you want to continue attacking? (y/n): ";
            cin >> choice;
            txtRed();
            cout << "::]> " << Player1.demonName << " is Attacking!!" << endl;
            Player1.health -= 10;
            txtWhite();
            cout << Player1.characterSelected << "'s Health is now :> " << Player1.health << "%." << endl;
            Sleep(3000);
            if (choice != 'y' && choice != 'Y')
            {
                if (Player1.health < 0)
                {
                    txtRed();
                    cout << "You Have been Defeated." << endl;
                    break;
                    txtWhite();
                }
                else
                {

                    cout << "You chose to Quit." << endl;
                    break;
                }
            }
        }
    }
};
#endif