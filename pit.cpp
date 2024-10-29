#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "pit.h"

using namespace std;


Pit::Pit() : Event() {
    this->name = "Bottomless Pit";
    this->type = 3;
}

Pit::Pit(string n, int t) : Event(n, t) {

}

Pit::~Pit() {  }

void Pit::encounter() const {
    Event::encounter();
    cout << "You stumble through the hallway and see the entire floor is covered in darkness...\n"
         << "Too late you notice it's a giant pit\n"
         << "The breeze hits you ... you lose your footing and you're falling ....\n" << endl;
}

void Pit::percept() const {
    Event::percept();
    cout << "You feel a breeze" << endl;
}

