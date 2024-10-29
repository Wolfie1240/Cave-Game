#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "gold.h"

using namespace std;


Gold::Gold() : Event() {
    this->name = "Golden Treasure";
    this->type = 2;
}

Gold::Gold(string n, int t) : Event(n, t) {

}

Gold::~Gold() {  }





void Gold::encounter() const {
    Event::encounter();
    cout << "You enter the room and see a shining pile of golden bars and coins in the center of the room\n"
         << "You fill your backpack with the treasure and are ready to continue .... \n" << endl;
}

void Gold::percept() const {
    Event::percept();
    cout << "You see a glimmer nearby" << endl;
}