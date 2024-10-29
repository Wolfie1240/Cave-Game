#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <vector>
#include <string>

using namespace std;

class Player
{
private:
    string name;
    int num_arr;
    int location;
    bool gold;
    bool wumpus_dead;
public:
    Player();
    Player(string);
    ~Player();

    void print();
    void set_wumpus_dead(bool);
    void set_gold(bool);
    void set_name(string);
    void set_num_arr(int);
    void set_location(int);
    bool get_wumpus_dead();
    bool get_gold();
    int get_location();
    string get_name();
    int get_num_arr();

};
#endif