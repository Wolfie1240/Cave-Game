#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "player.h"


Player::Player() {
    this->num_arr = 3;
    this->gold = false;
    this->wumpus_dead = false;
    this->location = -1;
}

Player::Player(string s) {
    this->name = s;
    this->num_arr = 3;
    this->gold = false;
    this->wumpus_dead = false;
    this->location = -1;
}

Player::~Player() {  }

void Player::set_num_arr(int i) {
    this->num_arr = i;
}

void Player::set_name(string n) {
    this->name = n;
}

void Player::set_location(int n) {
    this->location = n;
}

void Player::set_gold(bool b) {
    this->gold = b;
}

void Player::set_wumpus_dead(bool b) {
    this->wumpus_dead = b;
}

bool Player::get_gold() {
    return this->gold;
}

bool Player::get_wumpus_dead() {
    return this->wumpus_dead;
}

int Player::get_num_arr() {
    return this->num_arr;
}

string Player::get_name() {
    return this->name;
}

int Player::get_location() {
    return this->location;
}


void Player::print() {
    cout << "Backpack: " << endl;
    if (this->gold == true) {
      cout << "Golden Treasure" << endl;
    }


    if (this->wumpus_dead == true) {
        cout << "Wumpus Skull" << endl;
    }

    for (int i = 0; i < this->num_arr; i++) {
        cout << "+---->   ";
    }
}
