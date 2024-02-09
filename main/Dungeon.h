// Dungeon.h
#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <windows.h>
using namespace std;

class Dungeon
{

private:
    string a;
    int health = 100;
    int life = 3;

public:
    void displayName(void)
    {
        cout << "Please Wait.";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << "." << endl;
        Sleep(2000);
        system("cls");
        cout << "Welcome to the " << endl
             << endl;
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
        // system("cls");

        // system("cls");

        // displayName();
        int choice;
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
            a = "Adlein";
            cout << "::: \tYou have selected " << a << " as your character.";
            Sleep(2000);
            cout << "\n::: \tKeep an eye on your character's health bar which is " << health << "\% for now.";
            Sleep(2000);
            cout << "\n::: \tAlso Use your " << life << " lifes Carefully.";

            break;

        case 2:
            a = "Brian";
            cout << "\n::: \tYou have selected " << a << " as your character.";
            Sleep(2000);
            cout << "\n::: \tKeep an eye on your character's health bar which is " << health << "\% for now.";
            Sleep(2000);
            cout << "\n::: \tAlso Use your " << life << " lifes Carefully.";
            break;

        case 3:
            a = "Cheoron";
            cout << "\n::: \tYou have selected " << a << " as your character.";
            Sleep(2000);
            cout << "\n::: \tKeep an eye on your character's health bar which is " << health << "\% for now.";
            Sleep(2000);
            cout << "\n::: \tAlso Use your " << life << " lifes Carefully.";
            break;
        default:
            cout << "Invalid Choice!";
            break;
        }
    }
};

#endif