#include <iostream>
#include <ncurses.h>

using namespace std;



int main() {


/*cbreak();
    noecho();
    nodelay(stdscr, TRUE);*/
    initscr();
    
    noecho();
    
    for (int i = 0; i < 5; i++) {
        int ch = getch();
        if (ch == 'w')
            printw("forward");
        else if(ch == 's')
            printw("backwards");
        else if(ch == 'a')
            printw("left");
        else if(ch == 'd')
            printw("right");
        else
            return main();
    }
    getch();

    refresh();
    endwin();

    return 0;
}