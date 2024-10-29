#include <iostream>

#include "wumpus_game.h"

using namespace std;

void start_if_enter(){
    string enter;
    cin.ignore();
    cin.clear();
    //while ((getchar()) != '\n');
    getline(cin, enter);
}  

void welcome(int& i, string& s, int& b) {
    string c;
    bool boule = false;
    cout << "\n\n----------------------------------------------------------" << endl;
    cout << "                WELCOME TO THE WUMPUS GAME                \n\n" << endl;
    cout << "You must:\n(1) retrieve the golden treasure lost within the caves"
         << "\n(2) Slay the mighty wumpus with your bow and arrows" 
         <<"\n(3) Escape up the rope you started at" << endl;

    cout << "\n\nWhat is your name?\nName: ";
    cin >> s;

 
    cout << "\nOk " << s << " how big do you want the cave system to be? Side length must be at least 4\n";
    while (boule == false) {
        cout << "Board Size: ";
        cin >> i;
        if (i < 4) {
            cout << "This board size is too small\nTry again" << endl;
        }
        else
            boule = true;
    }

    cout << "\nGreat a " << i << " x " << i << " board has been created.\nDo you want to play in debug mode? Enter 'true' or 'false'\nInput: ";
    cin >> c;
       if (c == "true")
        b = 1;
    else if (c == "false")
        b = 0;    

    cout << "Ready to begin ---- Good luck " << s << "\n\n... Press enter to continue ..." << endl;
    start_if_enter();
    cin.clear();
}


char get_input() {
    char c;
    bool boule = false;
    while(boule == false) {
        cin.ignore();
        cout << "Do you wish to move(m) or shoot an arrow(a)\nInput: ";
        cin >> c;
        if (c == 'm' || c == 'a') {
            return c;
            boule = true;
        }
        else
            cout << "Invalid input\nPlease enter 'm' or 'a'" << endl;
    }
}


