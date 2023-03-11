#include "Car.h"
#include <iostream>
#include "Integer.h"
#include "Integer2.h"

void CarClass() {
    Car car(4);
    //car.FillFuel(6);
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Dashboard();
}

void CarDash()
{
    Car::ShowCount();
    const Car c(5);
    c.Dashboard();

    Car c1, c2;
    c.Dashboard();

    Car::ShowCount();
}

struct Point {
    int x;
    int y;
};

void DrawLine(int x1, int y1, int x2, int y2)
{

}

void DrawLine(Point start, Point end)
{
    std::cout << start.x << std::endl;
}

void Printer(Integer i)
{

}

Integer Add(int x, int y)
{
    return Integer(x + y);
}

void ShallowCopyDeepCopy()
{
    int* p1 = new int(5);
    // Shallow copy
    int* p2 = p1;

    //Deep copy
    int* p3 = new int(*p1);

    Integer i(5);
    Integer i2(i);
    i = i2;
    std::cout << i.GetValue() << std::endl;
}

int main()
{
    return 0;
}