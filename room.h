#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>

#include "event.h"

using namespace std;


class Room 
{
private:
    int room_val;
    Event* event;
public:
    Room();
    ~Room();

    void make_events();
    void delete_events();
    void encounter();
    void percept();
    void set_room_val(int);
    int get_room_val();
};
#endif