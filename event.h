#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;


class Event
{
protected:
    int type;
    string name;
public:
    Event();
    Event(string, int);

    virtual ~Event();

    virtual void percept() const = 0;
    virtual void encounter() const = 0;

};
#endif