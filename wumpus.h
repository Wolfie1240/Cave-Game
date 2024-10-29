#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "event.h"

using namespace std;

class Wumpus : public Event
{
private:
public:
    Wumpus();
    Wumpus(string, int);

    ~Wumpus();
    void percept() const;
    void encounter() const;
};
#endif