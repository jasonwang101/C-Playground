#include <iostream>
#include "func.h"

inline int Square(int x)
{
    return x * x;
}

//#define Square(x) x*x



void CreateWindow(const char* title, int x, int y, int width, int height);

void CreateWindow(const char* title, int x = -1, int y = -1, int width = -1, int height = -1) {
    using namespace std;
    cout << "Title : " << title << endl;
    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
    cout << "Width : " << width << endl;
    cout << "Height : " << height << endl;
}

int main()
{
    //CreateWindow("Notepad", 100, 200);

    /*using namespace std;
    int result = Add(3, 5);
    std::cout << result << std::endl;
    Add(3.1, 6.2);
    int x = 1;*/

    using namespace std;
    int val = 5;
    int result = Square(val + 1);
    cout << result << endl;
    return 0;
}