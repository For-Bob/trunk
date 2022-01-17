#pragma once
#include <iostream>

template<typename T>
void MySweap(T& a, T& b)
{
    if (a == b)
        return;
    a = a + b;
    b = a - b;
    a = a - b;
}