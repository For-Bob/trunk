#pragma once
#include <iostream>
#include "MySweap.h"
// ²Î¿¼£º https://www.cnblogs.com/jyroy/p/11248691.html
void MyBubbleSort(int* data, int length) {
    if (nullptr == data || length < 1)
        return;
    int i = 0, j = 0;
    bool isChange = false;
    for (i = 0; i < length; ++i) {
        isChange = false;
        for (j = 0; j < length - i - 1; ++j)
        {
            if (data[j] > data[j + 1])
            {
                MySweap(data[j], data[j+1]);
                isChange = true;
            }
        }
        if (!isChange)
            return;
    }
}