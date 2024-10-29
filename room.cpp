#include <iostream>
#include <vector>
#include <string>

#include "room.h"
#include "event.h"
#include "pit.h"
#include "gold.h"
#include "wumpus.h"
#include "bats.h"

using namespace std;


Room::Room() {
    this->room_val = 0;
    this->event = NULL;
}

Room::~Room() { 
    if(this->event != NULL) {
        delete this->event;
        this->event = NULL;
    }
}

void Room::set_room_val(int x) {
    this->room_val = x;
}

int Room::get_room_val() {
    return this->room_val;
}

void Room::make_events() {
    if (this->event != NULL) {
        delete this->event;
        this->event = NULL;
    }
    if (this->room_val == 0) {
        this->event = NULL;
    }
    else if (this->room_val == 1) {
        this->event = new Wumpus();
    }
    else if (this->room_val == 2) {
        this->event = new Gold();
    }
    else if (this->room_val == 3) {
        this->event = new Pit();
    }
    else if (this->room_val == 4) {
        this->event = new Bats();
    }
}


void Room::encounter() {
    if (this->event != NULL && this->room_val !=0)
        this->event->encounter();
}

void Room::percept() {
    if (this->event != NULL && this->room_val != 0)
        this->event->percept();
}



