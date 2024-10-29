#include <iostream>
#include <vector>
#include <string>

#include "event.h"


Event::Event() {
    this->type = 0;
}

Event::Event(string n, int i) {
    this->type = i;
    this->name = n;
}

Event::~Event() {  }

void Event::percept() const {  }

void Event::encounter() const {  }


