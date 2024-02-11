// Dungeon.h
#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Dungeon
{

public:
    // string a;
    int health = 100;
    int life = 3;

    const string weapons[3] = {"Twin Shadow Blades", "Valiant Defender", "Staff of Arcane"};
    string characterSelected, weaponGiven;
    void displayName(void)
    {
        cout << "Please Wait.";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << "." << endl;
        Sleep(2000);
        system("cls");
        std::cout << " ___ \n";
        std::cout << "| . \\ _ _ ._ _  ___  ___  ___ ._ _ \n";
        std::cout << "| | || | || ' |/ . |/ ._>/ . \\| ' |\n";
        std::cout << "|___/`___||_|_|\\_. |\\___.\\___/|_|_|\n";
        std::cout << "               <___'\n"
                  << endl
                  << endl;
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
                 << "Please Reastart";
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
    void Attack(Dungeon &character)
    {
        string super[3] = {"Adlein", "Brian", "Cheoron"};
        int damage[3] = {30, 20, 10};
        int damageToPerform;
        string power[3] = {"Twin Shadow Blades", "Valiant Defender", "Staff of Arcane"};
        if (character.characterSelected == "Adlein")
        {
            damageToPerform = damage[0];
        }
        else if (character.characterSelected == "Brian")
        {
            damageToPerform = damage[1];
        }
        else if (character.characterSelected == "Cheoron")
        {
            damageToPerform = damage[2];
        }
        else
        {
            cout << "Out Of Range...";
            exit(1);
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

        cout << character.characterSelected << " is performing an " << character.weaponGiven << "  Attack!" << endl;
        Sleep(2000);
        character.health -= damageToPerform;

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        if (character.health < 0)
        {
            cout << "Remaining Health ::> 0" << endl;
        }
        else
        {
            cout << "Remaining Health ::> " << character.health << endl;
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
        // while (Player1.health > 0)
        // {
        //     Attackers attacker;
        //     attacker.Attack(Player1);

        //     // Check if player's health is 0 or less
        //     if (Player1.health <= 0)
        //     {
        //         cout << "Game Over! Your character has been defeated." << endl;
        //         break;
        //     }

        //     char choice;
        //     cout << "Do you want to continue attacking? (y/n): ";
        //     cin >> choice;
        //     if (choice != 'y' && choice != 'Y')
        //     {
        //         cout << "You chose to stop attacking." << endl;
        //         break;
        //     }
        // }
    }
};
#endif