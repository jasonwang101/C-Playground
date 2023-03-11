#include <iostream>
#include "math.h"
#include <string>

//void Print(char ch)
//{
//    for (int i = 0; i < 10; ++i)
//    {
//        std::cout << ch;
//    }
//    std::cout << std::endl;
//}

//int Add(int* a, int* b)
//{
//    return *a + *b;
//}
//
//void AddVal(int* a, int* b, int* result)
//{
//    *result = *a + *b;
//}
//
//void Swap(int* a, int* b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void Factorial(int* a, int* result)
//{
//    int output = 1;
//    for (int i = 1; i <= *a; ++i)
//    {
//        output *= i;
//    }
//    *result = output;
//}

//void Swap(int* x, int* y)
//{
//    int temp = *x;
//    *x = *y;
//    *y = temp;
//}

//void Swap(int& x, int& y)
//{
//    int temp = x;
//    x = y;
//    y = temp;
//}
//
//void Print(int& ptr)
//{
//    std::cout << ptr << std::endl;
//}

//void Print(const int& ptr)
//{
//    std::cout << ptr << std::endl;
//}

int main() {
    ///*using namespace std;
    //cout << "Hello World\n" << 45 << " " << 8.2f << endl;
    //char buff[512];
    //cout << "What is your name?";
    //cin.getline(buff, 64, '\n');
    //cout << "Your name is:" << buff << endl;*/

    ////int x, y;
    ////std::cin >> x >> y;
    /////*int result = x+ y;
    ////std::cout << "Result is:" << result << std::endl;*/

    ////int result = Add(x, y);

    ////Print('#');

    //int a1; //Unitialized
    //int a2 = 0;//Copy initialization
    //int a3(5); // Direct Initialization
    //std::string s1; 
    //std::string s2("C++");  // Direct Initialization

    //char d1[8]; // Unitialized
    //char d2[8] = {'\0'};
    //char d3[8] = {'a', 'b', 'c', 'd'}; // Aggregate initialization
    //char d4[8] = {"abcd"};

    //int b1{}; // Value initialization
    ////int b2(); // Most vexing parse
    //int b3{5}; // Direct Initialization

    //int b4 = 0;

    //char e1[8]{};
    //char e2[8]{"Hello"};

    //int *p1 = new int{};

    //char *p2 = new char[8]{};
    //char *p3 = new char[8]{"Hello"};

    //float f{};

    /*int x = 10;
    int *ptr = &x;
    *ptr = 5;
    std::cout << x << std::endl;
    int y = *ptr;
    std::cout << y << std::endl;*/

    /*int sum = Add(1, 2);
    int a = 5;
    int b = 1;
    int result = 0;
    AddVal(&a, &b, &result);
    Swap(&a, &b);
    Factorial(&b, &result);*/

    //// Referent
    //int x = 10;

    //// Reference
    //int& ref = x;

    //int y = 20;

    //ref = y;

    //std::cout << "x:" << x << std::endl;
    //std::cout << "ref:" << ref << std::endl;

    /*int a = 5, b = 10;
    Swap(a, b);
    std::cout << "a:" << a << std::endl;
    std::cout << "b:" << b << std::endl;*/

    /*int x = 5;
    Print(x);*/

    /*float radius = 0;
    std::cin >> radius;
    const float PI = 3.14159f;
    float area = PI * radius * radius;
    float circumference = PI * 2 * radius;
    std::cout << "Area is : " << area << std::endl;
    std::cout << "Circumference is : " << circumference << std::endl;*/

    //const int CHUNK_SIZE = 512;
    //const int *ptr = &CHUNK_SIZE;
    ////*ptr = 1;
    //int x = 10;
    ////ptr = &x;
    ////*ptr = 1;

    //Print(x);
    //std::cout << "main->x" << x << std::endl;

    /*auto i = 10;
    auto j = 5;
    auto sum = i + 4.3f;

    auto result = Sum(i, j);

    static auto y = 2;
    const int x = 10;
    const auto var = x;
    auto& var1 = x;
    auto ptr = &x;
    auto list = { 1, 2, 3, 4 };*/

    /*int arr[] = { 1, 2, 3, 4, 6 };
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }

    for (auto& x : arr)
    {
        std::cout << x << " ";
    }

    for (auto x : { 1,2,3,4 })
    {
        std::cout << x;
    }*/

    //int arr[] = { 1, 2, 3, 4, 6 };
    ///* int* beg = std::begin(arr);
    // int* end = std::end(arr);*/

    //auto&& range = arr;
    //auto begin = std::begin(range);
    //auto end = std::end(range);

    //for (; begin != end; ++begin)
    //{
    //    auto v = *begin;
    //    std::cout << v << ' ';
    //}

    /*while (beg != end)
    {
        std::cout << *beg << ' ';
        ++beg;
    }*/

    return 0;
}

int Sum(int x, int y)
{
    return x + y;
}

/*
1. Value initialization => T obj{};
2. Direction initalization => T obj{v};
3. Copy initialization => T obj = v;
*/

/*
1. It forces initialization
2. You can use direct initialization for array types
3. It prevents narrowing conversions
4. Uniform syntax for all types
*/