#include <iostream>
#include "Integer.h"

// Returns r-value
int Add(int x, int y)
{
    return x + y;
}

// Return l-value
int& Transform(int& x)
{
    x *= x;
    return x;
}

void Print(int& x)
{
    std::cout << "Print(int&)" << std::endl;
}

void Print(const int& x)
{
    std::cout << "Print(const int&)" << std::endl;
}

void Print(int&& x)
{
    std::cout << "Print(const int&&)" << std::endl;
}

void RReferences()
{
    // r-value references
    int&& r1 = 10;
    int&& r2 = Add(3, 2);
    int&& r3 = 7 + 2;

    int x = 0;

    int& ref = Transform(x);
    const int& ref2 = 3;
}

Integer Add(const Integer& a, const Integer& b)
{
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

void MoveSemantics()
{
    Integer a(1), b(3);
    a.SetValue(Add(a, b).GetValue());
}

class Number {
    Integer m_Value{};
public:
    Number() = default;
    Number(int value) : m_Value{ value }
    {
    }

    /*Number(const Number& n) :m_Value{ n.m_Value }
    {
    }*/

    /*~Number()
    {

    }*/

    Number(const Number& n) = default;
    Number(Number&& n) = default;
    Number& operator=(const Number&) = default;
    Number& operator=(Number&&) = default;
};

Number CreateNumber(int num)
{
    Number n{ num };
    return n;
}

void MoveCopy()
{
    Number n1{ 1 };
    auto n2{ n1 };
    n2 = n1;

    auto n3{ CreateNumber(3) };
    n3 = CreateNumber(3);
}

Integer AddInt(int a, int b)
{
    // Integer temp(a + b);
    // return temp;// Naed return value optimization

    return Integer(a + b); // return value optimization
}

void Print(Integer val)
{

}

int main()
{
    Integer a = AddInt(3, 5);
    a.SetValue(3);
    auto b{ std::move(a) };

    Print(std::move(a));
    a.SetValue(5);
    std::cout << a.GetValue() << std::endl;

    return 0;
}