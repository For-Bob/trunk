#pragma once
//²Î¿¼£ºhttps://www.cnblogs.com/tojian/p/10106152.html

void merge(int*data, int begin, int mid, int end)
{
    char temp[128] = { 0 };
    int i = begin;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
        temp[k++] = (data[i] < data[j]) ? data[i++] : data[j++];
    
    while (i <= mid)
        temp[k++] = data[i++];
    
    while (j <= end)
        temp[k++] = data[j++];
    
    for (int i = 0; i < (end - begin + 1); ++i)
        data[begin + i] = temp[i];
}

void MyMergeSort(int* data, int begin, int end)
{
    if (nullptr == data || begin < 0 || (end - begin) < 1)
        return;
    int mid = (begin + end) >> 1;
    MyMergeSort(data, begin, mid);
    MyMergeSort(data, mid + 1, end);
    merge(data, begin, mid, end);
}