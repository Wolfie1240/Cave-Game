#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ncurses.h>

#include "game.h"
#include "room.h"
#include "player.h"

using namespace std;

Game::Game() {
    this->size = 0;
    this->start = 0;
}


Game::Game(int x, string s, int b) {
    this->size = x;
    this->debug = b;
    this->rooms.resize(x*x);
    this->copy.resize(x*x);
    for (int i = 0; i < x*x; i++) {
        this->rooms[i].set_room_val(0);
    }
    this->player.set_name(s);
}

Game::~Game() { 
   
}

void Game::print_board(int z) {
    int loca = 0;
    cout << " ";
    for (int x = 0; x < this->size; x++) {   
        for(int i = 0; i < this->size; i++){
            if (x == 0)
                cout << "_________ ";
        }   cout << endl; // top line


        for(int k = 0; k < this->size; k++) {
            cout << "|         ";
        }   cout << "|" << endl;

        for(int b = 0; b < this->size; b++) {
            this->print_icon(loca, z);
            loca++;
        }   cout << "|" << endl;
         for(int y = 0; y < this->size; y++) {
            cout << "|         ";
        }   cout << "|" << endl;
        
        for(int p = 0; p < this->size; p++){
            cout << "|_________";
            if(p == this->size -1){
                cout << "|";
            }
        }   
    }
    cout << endl << endl;
    this->player.print();
    cout << endl << endl; 
}

void Game::print_icon(int x, int b) {
    cout << "|   ";
    if (this->player.get_location() == x) 
        cout << "**";
    else if (this->rooms[x].get_room_val() == 1 && b == 1) {
            cout << " W";
        }
    else if (this->rooms[x].get_room_val() == 2 && b == 1) {
            cout << " G";
        }
    else if (this->rooms[x].get_room_val() == 3 && b == 1) {
            cout << " P";
        }
    else if (this->rooms[x].get_room_val() == 4 && b == 1) {
            cout << " B";
        }
    else if (this->rooms[x].get_room_val() == 5 && !(this->player.get_location() == x) && b == 1) {
            cout << " S";
        }
    else
        cout << "  ";
    
    cout << "    ";
}


void Game::init_rooms() {
    int ran;
    bool boule = true;
    // Wumpus, Gold, Pits, Bats, Start
    //    1,    2,    3,     4,    5
    int num = this->size * this->size;
    this->start = rand()%num;
    this->rooms[this->start].set_room_val(5);
    this->player.set_location(this->start);
   
    for (int i = 1; i < 3; i++) {
        do{
            ran = rand()%num;
            if (this->rooms[ran].get_room_val() == 0){
                    this->rooms[ran].set_room_val(i);
                    this->rooms[ran].make_events();
                    boule = false;
            }   
        } while(boule == true);
        boule = true;
    }
    // 2 pits and 2 bats
    for (int k = 0; k < 2; k++) {
        for (int j = 3; j < 5; j++) {
            do{
                ran = rand()%num;
                if (this->rooms[ran].get_room_val() == 0){
                    this->rooms[ran].set_room_val(j);
                    this->rooms[ran].make_events();
                    boule = false;
                }
            } while(boule == true);
            boule = true;
        }
    }
    for (int g = 0; g < this->size*this->size; g++) {
        this->copy[g] = this->rooms[g].get_room_val();
    }

}


void Game::move() {
    bool boule;
    initscr();
    noecho();
    cbreak();

    
    do {
        int ch = getch();
        boule = this->check_move(ch);
        if (boule == true) {
            if (ch == 'w')
                this->player.set_location(this->player.get_location() - this->size);
            else if(ch == 's')
                this->player.set_location(this->player.get_location() + this->size);
            else if(ch == 'a')
                this->player.set_location(this->player.get_location() - 1);
            else if(ch == 'd')
                this->player.set_location(this->player.get_location() + 1);
            else
                return move();
        }
        else {
            cout << "You can't move outside the cave system.\tTry again." << endl;
        }
    } while (boule == false);
    
    refresh();
    endwin();
}

bool Game::check_move(int c) {
    if (c == 'w' && (this->player.get_location() >= 0 && this->player.get_location() <= this->size - 1)) {
        return false;
    }
    if (c == 's' && (this->player.get_location() >= (this->size * (this->size - 1)) && this->player.get_location() <= this->size * this->size - 1)) {
        return false;
    }
    if (c == 'a' && ((this->player.get_location())%this->size == 0)) {
        return false;
    }
    if (c == 'd' && (this->player.get_location() + 1)%this->size == 0) {
        return false;
    }
    else return true;
}

void Game::arrow() {
    int ran;
    string s;
    bool boule;
    cout << "Which direction do you want to fire your arrow?\nEnter a space and your direction: W A S D\nInput: ";
    cin.clear();
    cin.ignore();
    getline(cin, s);

    // for (int i = 0; i < 3; i++) bool = check_arrow(input)   if true --> bool = fire_arrow(input)
    
    for (int i = 0; i < 3; i++) {
        boule = check_arrow(s, i);
        if (boule == true) {
            boule = fire_arrow(s, i);
            if (boule == true) {
                i = 3;
            }
        }
        else i = 3;
    }
    if (boule == true) {
        this->remove_wumpus();
    }
    else{
        this->player.set_num_arr(this->player.get_num_arr() - 1);
        cout << "Sorry your arrow missed\nArrows remaining: " << this->player.get_num_arr() << endl << endl;
        ran = rand()%4;
        if (ran != 2) {
            this->move_wumpus();
        }
    }
}

void Game::remove_wumpus() {
    cout << "Congratulations " << this->player.get_name() << " you have the slain the wumpus!" << endl;
    this->player.set_num_arr(this->player.get_num_arr() - 1);
    this->player.set_wumpus_dead(true); 

    for (int i = 0; i < this->size * this->size; i++) {
        if (this->rooms[i].get_room_val() == 1)
            this->rooms[i].set_room_val(0);
    }
}

bool Game::fire_arrow(string c, int i) {
        if (c == " w") {
            if (this->rooms[this->player.get_location() - this->size - (this->size *i)].get_room_val() == 1) {
                return true;
            }
        }
        if (c == " s") {
            if (this->rooms[this->player.get_location() + this->size + (this->size *i)].get_room_val() == 1) {
                return true;
            }
        }
        if (c == " d") {
            if (this->rooms[this->player.get_location() + 1 + i].get_room_val() == 1) {
                return true;
            }
        }
        if (c == " a") {
            if (this->rooms[this->player.get_location() - 1 - i].get_room_val() == 1) {
                return true; 
            }
        } 
    
}

void Game::move_wumpus() {
    bool boule = true;
    cout << "You've spooked the wumpus by missing your arrow\nIt moves to a random empty cave" << endl;
    
        for (int i = 0; i < this->size * this->size; i++) {

            if (this->rooms[i].get_room_val() == 1){
                this->rooms[i].set_room_val(0);
                    while(boule == true){
                        int ran = rand()%(this->size*this->size);
                        if (this->rooms[ran].get_room_val() == 0 && ran != this->player.get_location()) {
                            this->rooms[ran].set_room_val(1);
                            this->rooms[ran].make_events();
                            boule = false;
                        }   
                    }
                i = this->size*this->size;
            }   
        }
}


bool Game::play_again() {
    char input;
    cin.ignore();
    input = this->repeat_input();
    
    this->player.set_wumpus_dead(false);
    this->player.set_gold(false);
    this->player.set_num_arr(3);

    if (input == 'q') {
        return false;
    }
    else if (input == 'r') {
        cout << "Ok randomizing ...\n\n" << endl;
        for (int k = 0; k < this->size*this->size; k++) {
            this->rooms[k].set_room_val(0);
        }   
        this->init_rooms();
        return true;
    }
    else if (input == 's') {
        cout << "Ok restarting ...\n\n" << endl;
        for (int i = 0; i < this->size*this->size; i++) {
            this->rooms[i].set_room_val(this->copy[i]);
            this->rooms[i].make_events();
        }   this->player.set_location(this->start);
        return true;
    }


}

bool Game::call_encounter() {
    int ran;
    
    if (this->rooms[this->player.get_location()].get_room_val() != 0 && this->rooms[this->player.get_location()].get_room_val() != 5){
        this->rooms[this->player.get_location()].encounter();


        if (this->rooms[this->player.get_location()].get_room_val() == 4) {
            this->player.set_location(rand()%(this->size*this->size));
            return this->call_encounter();
        }
        else if (this->rooms[this->player.get_location()].get_room_val() == 2) {
            this->rooms[this->player.get_location()].set_room_val(0);
            this->player.set_gold(true);
            return true;
        }
        else if (this->rooms[this->player.get_location()].get_room_val() == 1 || this->rooms[this->player.get_location()].get_room_val() == 3) {
            return false;
        }
    }
    else if (this->rooms[this->player.get_location()].get_room_val() == 5) {
        if (this->player.get_gold() == true && this->player.get_wumpus_dead() == true) {
            return false;
        }       
        else return true;
    }    
    else if (this->player.get_num_arr() == 0 && this->player.get_wumpus_dead() == false) {
        return false;
    }
    else return true;
}

void Game::call_percept() {
    // check location +1, -1, +size, -size
    // if square value != 0, percept

    if (this->player.get_location() == 0) {
        this->rooms[this->player.get_location() + 1].percept();
        this->rooms[this->player.get_location() + this->size].percept();
    }
    else{ // upwards boundary
        if (!(this->player.get_location() >= 0 && this->player.get_location() <= this->size - 1))
            this->rooms[this->player.get_location() - this->size].percept();
        // downwards
        if (!(this->player.get_location() >= (this->size * (this->size - 1)) && this->player.get_location() <= this->size * this->size - 1))
            this->rooms[this->player.get_location() + this->size].percept();
        // right
        if ( !( (this->player.get_location() + 1)%this->size == 0) )
            this->rooms[this->player.get_location() + 1].percept();
        // left
        if (!( (this->player.get_location())%this->size == 0) )
            this->rooms[this->player.get_location() - 1].percept();
    }
}


void Game::end() {
    if (this->player.get_wumpus_dead() == true && this->player.get_gold() == true) {
        cout << "\n\n\n\nCongratulations " << this->player.get_name() << " you collected the gold and defeated the wumpus!\n"
             << "You wearily climb up the escape rope and are free\n"
             << "\n\t\tYOU WIN!\n" << endl;
    }
    else if (this->player.get_num_arr() == 0 && this->player.get_wumpus_dead() == false) {
        cout << "\n\nYou shot all your arrows without killing the wumpus ... \nGame Over!\n" << endl;
    }
    else{
        cout << "\n\n\n\n\n.......................................................................................................................\n\n"
             << "\t\t\t\t\t\tYOU DIED\n\n\n\n"
             << endl;
    }
}

bool Game::check_arrow(string c, int i) {
   // if on boundary return false
   // else return true
        if (c == " w" && (this->player.get_location() - this->size * i >= 0 && this->player.get_location() <= this->size - 1)) {
            return false;
        }
        else if (c == " s" && (this->player.get_location() + this->size * i >= (this->size * (this->size - 1)) && this->player.get_location() <= this->size * this->size - 1)) {
            return false;
        }
        else if (c == " d" && ((this->player.get_location() + 1 + i)%this->size == 0)) {
            return false;
        }
        else if (c == " a" && ((this->player.get_location() - i)%this->size == 0)) {
            return false;
        }
        else return true;

}

char Game::repeat_input() {
    char input;
    bool boule = true;

    while(boule == true) {
        cout << "Do you want to play again?\nYou can keep the same caves (s), get a new random cave system (r) or quit (q)" << endl;    
        cout << "Input: ";
        cin >> input;
        if (input == 'q' || input == 's' || input == 'r') {
            boule = false;
            return input;
        }
        else {
            cout << "Invalid input\nPlease enter 's', 'r' or 'q'\n\n";
        }
    }
    
}
 

