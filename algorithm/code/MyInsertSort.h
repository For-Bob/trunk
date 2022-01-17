#pragma once
//²Î¿¼£º https://blog.csdn.net/xzw_itcast/article/details/78993469
void MyInsertSort(int* data, int length)
{
    if (nullptr == data || length < 1)
    {
        return;
    }
    int i, j, temp = 0;

    for (i = 1; i < length; ++i) {
        temp = data[i];
        for ( j = i - 1; j >= 0; --j)
        {
            if (data[j] > temp) {
                data[j + 1] = data[j];
            }
            else
            {
                break;
            }
        }
        data[j + 1] = temp;
    }
}