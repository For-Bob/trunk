#include "MyString.h"
#include "MyStrCopy.h"
#include "MyQuickSort.h"
#include "MyBubbleSort.h"
#include "MySelectSort.h"
#include "MyInsertSort.h"
#include "MyMergeSort.h"

void MyPrint(const int* data, int lenght)
{
    std::cout << "data: ";
    for (int i = 0; i < lenght; ++i) {
        std::cout << " " << data[i];
    }
    std::cout << std::endl;
}


int main()
{
    /*MyString str("hello world");
    str.printData();
    MyString strOne = "yoyo";
    strOne.printData();
    str = strOne;
    str.printData();
*/
    //char* dest =      "hello china, are you ok?";
    //std::cout << "strlen(dest): " << strlen(dest) << std::endl;
    //char source[48] = "11111111111111111111111111111" ;
    //MyStrCopy(source, dest);
    //std::cout << "source :" << source << std::endl;
    int data[] = { 8,4,5,36,2,7,1,2,3 };
    int len = sizeof(data) / sizeof(data[0]);
    //MyQuickSort(data, 0, len - 1);
    //MyBubbleSort(data,  len);
    //MySelectSort(data, len);
    //MyInsertSort(data, len);
    MyMergeSort(data, 0, len - 1);
    MyPrint(data, len);
    

    getchar();
    return 0;
}