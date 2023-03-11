#include <iostream>
#include "Integer.h"

void basic_cast()
{
    int a = 5, b = 2;
    float f = static_cast<float>(a) / b;
    char* p1 = reinterpret_cast<char*>(&a);
    const int x = 1;
    int* p2 = const_cast<int*>(&x);
    std::cout << p1 << std::endl;
}

void Print(const Integer a)
{

}

class Product
{
    Integer m_Id;
    int x;
public:
    Product(const Integer& id) :m_Id{ id }, x(id.GetValue())
    {
        std::cout << "Product(const Integer &)" << std::endl;
    }

    ~Product()
    {
        std::cout << "~";
    }

    const Integer& GetInteger() const {
        return m_Id;
    }
    operator Integer()
    {
        return m_Id;
    }
};

void user_cast()
{
    Product p{ 5 };
    Integer id{ 5 };
    //id = p; // id = p.operator Integer();

    if (id == p)
    {
        std::cout << "Id matches with the product\n";
    }
}

int main()
{
    Integer a1{ 5 };
    // Initialization

    Integer a2 = 5;
    // Assignment

    a1 = 7;
    int x = static_cast<int>(a1);

    return 0;
}