#ifndef BATS_H
#define BATS_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "event.h"

using namespace std;

class Bats : public Event
{
private:
public:
    Bats();
    Bats(string, int);

    ~Bats();
    void percept() const;
    void encounter() const;
};
#endif