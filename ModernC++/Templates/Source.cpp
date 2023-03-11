#include <iostream>
#include "Integer.h"
#include <vector>
#include <list>
//
//int Max(int x, int y)
//{
//    return x > y ? x : y;
//}
//
//float Max(float x, float y)
//{
//    return x > y ? x : y;
//}

template<typename T>
T Max(T x, T y)
{
    std::cout << typeid(T).name() << std::endl;
    return x > y ? x : y;
}

template<typename T>
T Add(T x, T y)
{
    return x + y;
}

template<typename T>
T ArraySum(const T* pArr, size_t arrSize)
{
    T count{ 0 };
    for (size_t i = 0; i < arrSize; ++i)
    {
        int value = pArr[i];

        count += value;
    }
    return count;
}

template<typename T>
T MaxInArray(const T* pArr, size_t arrSize)
{
    T biggest{ pArr[0] };
    for (size_t i = 0; i < arrSize; ++i)
    {
        int value = pArr[i];

        if (biggest < value)
        {
            biggest = value;
        }
    }
    return biggest;
}

template<typename T>
std::pair<T, T> MinMax(const T* pArr, size_t arrSize)
{
    T smallest{ pArr[0] };
    T biggest{ pArr[0] };
    for (size_t i = 0; i < arrSize; ++i)
    {
        int value = pArr[i];

        if (biggest < value)
        {
            biggest = value;
        }

        if (smallest > value)
        {
            smallest = value;
        }
    }
    return std::pair<T, T>{ smallest, biggest};
}

void TemplateBasic()
{
    auto num = Max(3.3f, 5.8f);
    std::cout << num << std::endl;
    auto num2 = Max(38, 12);
    std::cout << num2 << std::endl;
    int arr[]{ 1,2,3,4 };
    auto num3 = MinMax(arr, 4);
    std::cout << num3.first << ":" << num3.second << std::endl;
}

void TemplateDeduction()
{
    Max(static_cast<float>(3), 5.5f);
    Max<double>(3, 6.2);
    int (*pfn)(int, int) = Max;
    pfn(3, 62);
}

//Explicit Instantiation
template char Max(char x, char y);

//Explicit Specialization
template<> const char* Max<const char*>(const char* x, const char* y)
{
    std::cout << "Max<const char*>()" << std::endl;
    return strcmp(x, y) > 0 ? x : y;
}

template<int size>
void Print()
{
    char buffer[size];
    std::cout << size << std::endl;
}

//template<typename T>
//T Sum(T* parr, int size)
//{
//    T sum{};
//    for (int i = 0; i < size; ++i)
//    {
//        sum += parr[i];
//    }
//    return sum;
//}

template<typename T, int size>
T Sum(T(&parr)[size])
{
    T sum{};
    for (int i = 0; i < size; ++i)
    {
        sum += parr[i];
    }
    return sum;
}

void NonTypeTemplate()
{
    int i = 3;
    Print<sizeof(i)>();

    int arr[]{ 3,1,9,7 };
    auto it = std::begin(arr);
    //int(&ref)[4] = arr;
    int sum = Sum(arr);
    std::cout << sum << std::endl;
}

class Employee
{
    std::string m_Name;
    Integer m_id;
public:
    template<typename T1, typename T2>
    Employee(T1&& name, T2&& id) : m_Name{ std::forward<T1>(name) }, m_id{ std::forward<T2>(id) }
    {
        std::cout << "Employee(std::string &&name, Integer &&id)" << std::endl;
    }
};

template<typename T1, typename T2>
Employee* Create(T1&& a, T2&& b)
{
    return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}

void PerfectFowarding()
{
    //// Copy
    //Integer val{ 100 };
    //Employee emp1{ std::string{"Jason"}, val };

    //// Move
    //Employee emp2{ std::string{"Jason"}, Integer{100} };

    auto emp = Create("Umar", Integer{ 100 });

    /*std::string name = "Jason";
    Employee emp2{ name, 100 };
    Integer val{ 100 };
    Employee emp3{ "Jason", val };*/
}

//template<typename T>
//void Print(std::initializer_list<T> args)
//{
//    for (const auto& x : args)
//    {
//        std::cout << x << " ";
//    }
//}

void Print()
{
    std::cout << std::endl;
}

// Template parameter pack
template<typename T, typename...Params>
// Function parameter pack
void Print(T&& a, Params&&... args)
{
    std::cout << a;
    if (sizeof...(args) != 0)
    {
        std::cout << ",";
    }
    Print(std::forward<Params>(args)...);
}

/*
1. Print(1, 2.5, 3, "4");
2. Print(2.5, 3, "4");
3. Print(3, "4");
4. Print("4");
5. Print();
*/

void VariadicTemplate()
{
    Print(1, 2.5, 3, "4");
}

template<typename T, int size>
class Stack
{
    T m_buffer[size]{ 0 };
    int m_Top{ -1 };
public:
    Stack() = default;
    Stack(const Stack<T, size>& obj)
    {
        m_Top = obj.m_Top;
        for (int i = 0; i <= m_Top; ++i)
        {
            m_buffer[i] = obj.m_buffer[i];
        }
    }

    void Push(const T& elem)
    {
        m_buffer[++m_Top] = elem;
    }

    void Pop();

    T Top()const {
        return m_buffer[m_Top];
    }

    bool IsEmpty()
    {
        return m_Top == -1;
    }

    static Stack Create();
};

template<typename T, int size>
void Stack<T, size>::Pop()
{
    --m_Top;
}

template<typename T, int size>
Stack<T, size> Stack<T, size>::Create()
{
    return Stack<T, size>();
}

void ClassTemplate()
{
    Stack<float, 10> s = Stack<float, 10>::Create();
    s.Push(3);
    s.Push(1);
    s.Push(6);
    s.Push(9);
    auto s2(s);

    while (!s2.IsEmpty())
    {
        std::cout << s2.Top() << " ";
        s2.Pop();
    }
}

template<typename T>
class PrettyPrinter {
    T* m_pData;
public:
    PrettyPrinter(T* data) : m_pData(data)
    {

    }

    void Print()
    {
        std::cout << "{" << *m_pData << "}" << std::endl;
    }

    T* GetData()
    {
        return m_pData;
    }
};

template<>
void PrettyPrinter<std::vector<int>>::Print()
{
    std::cout << "{";
    for (const auto& x : *m_pData)
    {
        std::cout << x;
    }
    std::cout << "}" << std::endl;
}

template<>
void PrettyPrinter<std::vector<std::vector<int>>>::Print()
{
    std::cout << "{" << std::endl;
    for (const auto& x : *m_pData)
    {
        std::cout << "{";
        for (const auto& y : x)
        {
            std::cout << y;
        }
        std::cout << "}" << std::endl;;
    }
    std::cout << "}" << std::endl;
}

template<>
class PrettyPrinter<const char*> {
    const char* m_pData;
public:
    PrettyPrinter(const char* data) : m_pData(data)
    {

    }

    void Print()
    {
        std::cout << "{" << m_pData << "}" << std::endl;
    }

    const char* GetData()
    {
        return m_pData;
    }
};

void ExplictTemplateClass()
{
    int data = 5;
    float f = 0.2f;
    PrettyPrinter<int> p1(&data);
    p1.Print();
    PrettyPrinter<float> p2(&f);
    p2.Print();

    const char* p{ "Hello World" };
    PrettyPrinter<const char*> p3(p);
    p3.Print();
    const char* pData = p3.GetData();
    std::vector<int> v{ 1,2,3,4,5,6 };
    PrettyPrinter<std::vector<int>> p4(&v);
    p4.Print();
    std::vector<std::vector<int>> y{ {1,2,3}, {4,5,6} };
    PrettyPrinter<std::vector<std::vector<int>>> p5(&y);
    p5.Print();
}

template<typename T, int columns>
class PrettyPrinter1
{
    T* m_pData;
public:
    PrettyPrinter1(T* data) :m_pData{ data }
    {

    }

    void Print()
    {
        std::cout << "Columns:" << columns << std::endl;
        std::cout << "{" << *m_pData << "}" << std::endl;
    }

    T* GetData()
    {
        return m_pData;
    }
};

template<typename T>
class PrettyPrinter1<T, 80>
{

    T* m_pData;
public:
    PrettyPrinter1(T* data) :m_pData{ data }
    {

    }

    void Print()
    {
        std::cout << "Using 80 Columns" << std::endl;
        std::cout << "{" << *m_pData << "}" << std::endl;
    }

    T* GetData()
    {
        return m_pData;
    }
};

template<typename T>
class SmartPointer
{
    T* m_ptr;
public:
    SmartPointer(T* ptr) : m_ptr(ptr)
    {

    }

    T* operator ->()
    {
        return m_ptr;
    }

    T& operator *()
    {
        return *m_ptr;
    }

    ~SmartPointer()
    {
        delete m_ptr;
    }
};

template<typename T>
class SmartPointer<T[]>
{
    T* m_ptr;
public:
    SmartPointer(T* ptr) : m_ptr(ptr)
    {

    }

    T& operator [](int index)
    {
        return m_ptr[index];
    }

    ~SmartPointer()
    {
        delete[] m_ptr;
    }
};

void PartialTemplate()
{
    int data = 800;
    PrettyPrinter1<int, 80> p{ &data };
    p.Print();

    SmartPointer<int[]> s1{ new int[5] };
    s1[0] = 5;
    std::cout << s1[0] << std::endl;
}

const char* GetErrorMessage(int errorNO)
{
    return "Empty";
}

//typedef const char* (*PFN)(int);
using PFN = const char* (*)(int);
void ShowError(PFN pfn)
{

}

//typedef std::vector<std::initializer_list<std::string>> Names;
template<typename T>
using Names = std::vector<std::list<T>>;

void AliasTemplate()
{
    PFN pfn = GetErrorMessage;
    ShowError(pfn);

    Names<std::string> name;
    Names<Names<std::string>> nnames;
}

template<typename T>
T Divide(T a, T b)
{
    static_assert(std::is_floating_point<T>::value, "Only floating point type supported");
    if (std::is_floating_point<T>::value == false)
    {
        std::cout << "Use floating point types only\n";
        return 0;
    }

    return a / b;
}

template<typename T>
void Check(T&&)
{
    std::cout << std::boolalpha;
    std::cout << "Is reference?" << std::is_reference<T>::value << std::endl;

    std::cout << "After removing:" << std::is_reference<typename std::remove_reference<T>::type>::value << std::endl;
}

void TypeTraits()
{
    std::cout << std::boolalpha << "Is integer?" << std::is_integral<int>::value << std::endl;
    std::cout << Divide(5.1, 7.3) << std::endl;

    Check(5);
    int value{};
    Check(value);

}

void StaticAssert()
{
    static_assert(sizeof(void*) == 4, "Compile in 32-bit mode only");
    if (sizeof(void*) != 4)
    {
        std::cout << "Not 32-bit mode\n";
    }
    else
    {

    }
}

int main()
{
    TypeTraits();
    return 0;
}