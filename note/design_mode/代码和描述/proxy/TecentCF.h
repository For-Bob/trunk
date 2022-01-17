#ifndef TECENTCF_H
#define TECENTCF_H

#include "Tecent.h"

class TecentCF: public Tecent
{
public:
    TecentCF();
    ~TecentCF();
    void login(string name, string password);
    void play();
};

#endif // TECENTCF_H
