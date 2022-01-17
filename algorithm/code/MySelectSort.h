#pragma once
#include <iostream>
#include "MySweap.h"
//²Î¿¼: https://www.cnblogs.com/nicaicai/p/12563962.html
void MySelectSort(int* data, int length) {
    if (nullptr == data || length < 1) {
        return;
    }
    int index = 0;
    for (int i = 0; i < length - 1; ++i) {
        index = i;
        for (int j = i + 1; j < length; ++j) {
            if (data[index] > data[j])
                index = j;
        }
        MySweap(data[index], data[i]);
    }
}