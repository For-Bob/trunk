#pragma once
char* MyStrCopy(char* dest, char* source)
{
    if (nullptr == dest || nullptr == source)
        return nullptr;

    int len = strlen(source);//������'/0',source[0]���ǵ�һλ��source+24���൱��ƫ������ַ������Ⱦ���'/0'
    len = len + 1;//n���ַ����ƣ�Ҫ+1�������'/0'������,���Լ���Ҫ��1

    std::cout << "len: " << *(source + len) << std::endl;//'/0����һλ'
    std::cout << "len-1: " << *(source + len - 1) << std::endl;//'/0'
    std::cout << "len-2: " << *(source + len - 2) << std::endl;//'?'
    std::cout << "len-1 -24 : " << *(source + len - 1 - 24) << std::endl;//'��һλ'

    char* temp = dest;
    if (dest > source && dest < source + len -1)//source[0]���ǵ�һλ��source+len���൱��ƫ������ַ������Ⱦ���'/0',��ȥ֮ǰ���ϵ�һλ
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