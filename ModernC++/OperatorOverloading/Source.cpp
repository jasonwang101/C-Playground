#include "Integer.h"
#include <memory>

//Integer operator +(const Integer& a, const Integer& b)
//{
//    Integer temp;
//    temp.SetValue(a.GetValue() + b.GetValue());
//    return temp;
//}

void Overload_basic()
{
    Integer a(1), b(3);
    Integer sum = a + b;
    ++sum;
    std::cout << (sum++).GetValue() << std::endl;
    if (a == b)
    {
        std::cout << "same" << std::endl;
    }
    else
    {
        std::cout << "not same" << std::endl;
    }
}

Integer operator +(int x, const Integer& y)
{
    Integer temp;
    temp.SetValue(x + y.GetValue());
    return temp;
}

std::ostream& operator <<(std::ostream& out, const Integer& a)
{
    out << a.GetValue();
    return out;
}

std::istream& operator >> (std::istream& input, Integer& a)
{
    int x;
    input >> x;
    *a.m_pInt = x;
    return input;
}

void operatorover_more()
{
    Integer a(1), b(3);
    Integer sum1 = a + 5; //a.operator+(5)
    Integer sum2 = 5 + a;
    std::cout << sum1 << std::endl;
    operator << (std::cout, sum1).operator<<(std::endl);

    std::cin >> a;
    std::cout << a << std::endl;

    a();
}

// Smart pointer
class IntPtr
{
    Integer* m_p;
public:
    IntPtr(Integer* p) : m_p(p)
    {

    }
    ~IntPtr()
    {
        delete m_p;
    }

    Integer* operator ->()
    {
        return m_p;
    }

    Integer& operator *()
    {
        return *m_p;
    }
};

void CreateInteger()
{
    IntPtr p = new Integer;
    (*p).SetValue(3);
    std::cout << p->GetValue() << std::endl;
}

void Process(std::shared_ptr<Integer> ptr)
{
    std::cout << ptr->GetValue() << std::endl;
}

void SmartPoitner()
{
    std::shared_ptr<Integer> p(new Integer);
    Process(p);
}

int main()
{
    SmartPoitner();
    return 0;
}