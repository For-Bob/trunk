#pragma once
char* MyStrCopy(char* dest, char* source)
{
    if (nullptr == dest || nullptr == source)
        return nullptr;

    int len = strlen(source);//不计算'/0',source[0]就是第一位，source+24就相当于偏移这个字符串长度就是'/0'
    len = len + 1;//n个字符复制，要+1，方便把'/0'复制上,所以记数要加1

    std::cout << "len: " << *(source + len) << std::endl;//'/0后面一位'
    std::cout << "len-1: " << *(source + len - 1) << std::endl;//'/0'
    std::cout << "len-2: " << *(source + len - 2) << std::endl;//'?'
    std::cout << "len-1 -24 : " << *(source + len - 1 - 24) << std::endl;//'第一位'

    char* temp = dest;
    if (dest > source && dest < source + len -1)//source[0]就是第一位，source+len就相当于偏移这个字符串长度就是'/0',减去之前加上的一位
    {
        dest = dest + len - 1;
        source = source + len - 1;
        while (len--)
            *dest-- = *source--;
    }
    else
    {
        while (len--)
            *dest++ = *source++;
    }

    return temp;
}