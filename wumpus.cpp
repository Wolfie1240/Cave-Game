#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "wumpus.h"

using namespace std;

Wumpus::Wumpus() : Event() {
    this->name = "Wumpus";
    this->type = 1;
}

Wumpus::Wumpus(string n, int t) : Event(n, t) {

}

Wumpus::~Wumpus() {  }

void Wumpus::encounter() const {
    Event::encounter();
    cout << "You hear a noise from the room and peer around the end of the hallway...\n"
         << "You enter the room and are met with a terrible smell\n"
         << "Before you can move, the Wumpus attacks" << endl;
}

void Wumpus::percept() const {
    Event::percept();
    cout << "You smell a terrible stench" << endl;
}