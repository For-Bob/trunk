#ifndef TECENTLEAGUE_H
#define TECENTLEAGUE_H

#include "Tecent.h"

class TecentLeague: public Tecent
{
public:
    TecentLeague();
    ~TecentLeague();
    void login(string name, string password);
    void play();
};

#endif // TECENTLEAGUE_H
