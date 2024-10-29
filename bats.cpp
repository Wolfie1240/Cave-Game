#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "bats.h"

using namespace std;

Bats::Bats() : Event() {
    this->name = "Super Bats";
    this->type = 4;
}

Bats::Bats(string n, int t) : Event(n, t) {  }

Bats::~Bats() {  }

void Bats::encounter() const {
    cout << "The sound of wings flapping grows louder and louder...\n" 
         << "A group of super large bats fly into view headed directly towards you\n"
         << "They sweep you off your feet and carry you deeper into the cave system\n"
         << "You continue your adventure in a random room of the cave system .... \n" << endl;
}

void Bats::percept() const {
    cout << "You hear wings flapping" << endl;
}

