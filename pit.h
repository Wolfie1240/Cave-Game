#ifndef PIT_H
#define PIT_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "event.h"

using namespace std;

class Pit : public Event
{
private:
public:
    Pit();
    Pit(string, int);

    ~Pit();
    void percept() const;
    void encounter() const;
};
#endif