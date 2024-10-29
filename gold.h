#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "event.h"

using namespace std;

class Gold : public Event
{
private:
public:
    Gold();
    Gold(string, int);

    ~Gold();
    void percept() const;
    void encounter() const;
};
#endif