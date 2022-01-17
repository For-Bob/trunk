#pragma once
#include <iostream>
//²Î¿¼£º https://www.cnblogs.com/nicaicai/p/12689403.html
void MyQuickSort(int* data, int left, int right)
{
    if (nullptr == data || (right - left) <= 0 || left < 0)
        return;
    if (left < right)
    {
        int bPos = left;
        int ePos = right;
        int key = data[bPos];
        while (bPos < ePos)
        {
            while (bPos < ePos && data[ePos] > key)
                --ePos;
            data[bPos] = data[ePos];
            while (bPos < ePos && data[bPos] < key)
                ++bPos;
            data[ePos] = data[bPos];
        }
        data[bPos] = key;
        MyQuickSort(data, left, bPos - 1);
        MyQuickSort(data, bPos + 1, right);
    }
}