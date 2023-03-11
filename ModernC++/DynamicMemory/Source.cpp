#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void NewArrays()
{
    int* p = new int[5]{ 1, 2, 3, 4, 5 };
    for (int i = 0; i < 5; ++i)
    {
        p[i] = i;
    }
    delete[] p;
    p = nullptr;
}

void Strings() {
    char* p = new char[4];
    strcpy_s(p, 4, "C++");
    std::cout << p << std::endl;
    delete[] p;
}

void TwoD() {
    int* p1 = new int[3];
    int* p2 = new int[3];

    int** pData = new int* [2];
    pData[0] = p1;
    pData[1] = p2;

    pData[0][1] = 2;

    delete[]p1;
    delete[]p2;

    delete[]pData;
}

void Array2D()
{
    int data[2][3] = { 1,2,3, 4,5,6 };
    data[0][1];
}

int main() {
    /*int *p = (int*) malloc(sizeof(int));
    *p = 5;
    printf("%d", *p);
    free(p);
    p = NULL;*/
    //int *p = (int*) calloc(1, sizeof(int));
    // allocate array of 5 int
    /*int* p = (int*) malloc(5 * sizeof(int));
    if (p == NULL)
    {
        printf("Failed to allocate memory\n");
        return -1;
    }
    *p = 5;
    printf("%d", *p);
    free(p);
    p = NULL;*/

    /*int *p = new int(5);
    *p = 6;
    std::cout << *p << std::endl;
    delete p;*/

    Strings();

    return 0;
}