// Dungeon.h
#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <windows.h>
using namespace std;

class Dungeon
{

public:
    string a;
    int health = 100;
    int life = 3;
    const string weapons[3] = {"Twin Shadow Blades", "Valiant Defender", "Staff of Arcane"};

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
            break;

        case 2:
            weaponAlloted = weapons[1];
            break;
        case 3:
            weaponAlloted = weapons[2];
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
            a = "Adlein";
            cout << "::: You have selected " << a << " as your character.";
            Sleep(2000);
            cout << "\n:: Keep an eye on your character's health bar which is " << health << "\% .";
            Sleep(2000);
            cout << "\n:: Also Use your " << life << " lifes Carefully.";
            Sleep(2000);
            cout << "\n:: Your Weapon is **" << weaponAlloted << "**.\n";
            break;

        case 2:
            a = "Brian";
            cout << "\n:: You have selected " << a << " as your character.";
            Sleep(2000);
            cout << "\n:: Keep an eye on your character's health bar which is " << health << "\% .";
            Sleep(2000);
            cout << "\n:: Also Use your " << life << " lifes Carefully.";
            cout << "\n:: Your Weapon is **" << weaponAlloted << "**.\n";
            break;

        case 3:
            a = "Cheoron";
            cout << "\n::: You have selected " << a << " as your character.";
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

class GameMechanics
{
public:

};

#endif