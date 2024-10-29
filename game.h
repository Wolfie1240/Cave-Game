#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>

#include "room.h"
#include "player.h"


using namespace std;


class Game
{
private:
    Player player;
    int size;
    int start;
    vector <Room> rooms;
    vector <int> copy;
    int debug;
public:
    
    Game();
    Game(int, string, int);
    ~Game();

    bool check_move(int);
    bool check_arrow(string, int);
    void print_board(int);
    void print_icon(int, int);
    void init_rooms();
    void move();
    void move_wumpus();
    void remove_wumpus();
    void arrow();
    bool play_again();
    void end();
    bool fire_arrow(string, int);
    bool call_encounter();
    void call_percept();
    char repeat_input();
    // randomly select start
};
#endif