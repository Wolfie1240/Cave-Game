#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>

#include "game.h"
#include "player.h"
#include "room.h"
#include "event.h"
#include "pit.h"
#include "gold.h"
#include "bats.h"
#include "wumpus.h"
#include "wumpus_game.h"

using namespace std;


int main() {
    srand(time(NULL));
    char input;                      //  0               size - 1
    int size;                        //  size (size-1)    size^2 - 1
    string name;
    int debug;
    bool boule = true;
    



    welcome(size, name, debug); // prints welcome messages and intializes size, name and debug value
    Game g1(size, name, debug); // creates a game object that will control the functionality
    g1.init_rooms(); // create a size x size array of rooms and randomly assigns events to rooms

    while (boule == true) {
        g1.call_percept();
        g1.print_board(debug);
        input = get_input();
        if (input == 'm') { 
            g1.move(); 
        }
        else if (input == 'a') {
            g1.arrow();
        }
        if (boule == true){
            boule = g1.call_encounter();
        }
        if (boule == false) {
            g1.end();
            boule = g1.play_again();
        }
    }
}
// ai turn
// headers / comments  

