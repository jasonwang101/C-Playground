#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <initializer_list>
#include <cassert>
#include <vector>

namespace enumsample
{
    enum class Color : long { RED = 5, GREEN, BLUE };

    void FillColor(Color color)
    {
        // Fill background with some color
        if (color == Color::RED)
        {
        }
        else if (color == Color::GREEN)
        {
        }
        else if (color == Color::BLUE)
        {

        }
    }

    enum class TrafficLight : char { RED = 'c', GREEN, YELLOW };

    void enumsample()
    {
        Color c = Color::RED;
        FillColor(c);
        FillColor(Color::GREEN);
        FillColor(static_cast<Color>(2));
        int x = static_cast<int>(Color::RED);
    }
}

const char* Combine(const char* pFirst, const char* pLast)
{
    char* fullname = new char[strlen(pFirst) + strlen(pLast) + 1];
    strcpy(fullname, pFirst);
    strcat(fullname, pLast);
    return fullname;
}

void rawstring()
{
    char first[10];
    char last[10];
    std::cin.getline(first, 10);
    std::cin.getline(last, 10);

    const char* pFullName = Combine(first, last);

    std::cout << pFullName << std::endl;

    delete[] pFullName;
}

void stdstring()
{
    //Initialize & assign
    std::string s{ "Hello" };
    s = "Hello";

    //Access
    s[0] = 'W';
    char ch = s[0];

    std::cout << s << std::endl;
    std::cin >> s;

    std::getline(std::cin, s);
    //Size
    s.length();

    //Insert & concatenate
    std::string s1{ "Hello" }, s2{ "World" };
    s = s1 + s2;

    s += s1;

    s.insert(6, "World");

    //Comparison
    if (s1 != s2)
    {

    }

    //Removal
    s.erase();
    s.erase(0, 5);
    s.clear();

    //Search
    auto pos = s.find("World", 0);

    if (pos != std::string::npos)
    {
        // Found
    }
}

std::string Combine(const std::string& first, const std::string& last)
{
    std::string fullname = first + last;
    return fullname;
}

void stdstringexample()
{
    std::string first;
    std::string last;

    std::getline(std::cin, first);
    std::getline(std::cin, last);

    std::string fullname = Combine(first, last);
    printf("%s", fullname.c_str());

    std::cout << fullname << std::endl;

    std::string first1 = "Umar";
    std::string last1("Lone");

    std::string name{ "Umar Lone" };

    using namespace std::string_literals;
    auto n2 = "Umar Lone"s;

    unsigned int value = 100u;
}

std::string ToUpper(const std::string& str)
{
    std::string upper;
    for (auto character : str)
    {
        upper += toupper(character);
    }
    return upper;
}

std::string ToLower(const std::string& str)
{
    std::string lower;
    for (auto character : str)
    {
        lower += tolower(character);
    }
    return lower;
}

void stringstreamsample()
{
    int a{ 5 }, b{ 6 };
    int sum = a + b;
    std::stringstream ss;
    ss << "Sum of " << a << " & " << b << " is : " << sum << std::endl;
    std::string s = ss.str();
    std::cout << s << std::endl;
    ss.str("");
    ss << sum;
    auto ssum = std::to_string(sum);
    std::cout << ssum << std::endl;
}

void stringstreamsample1()
{
    std::string data = "12 89 21";
    int a;
    std::stringstream ss;
    ss.str(data);
    while (ss >> a)
    {
        std::cout << a << std::endl;
    }
    int x = std::stoi("54");
}

class Distance {
    long double m_Kilometres;
public:
    Distance(long double km) : m_Kilometres{ km }
    {
    };

    long double GetKm() const {
        return m_Kilometres;
    }

    void SetKm(long double val)
    {
        m_Kilometres = val;
    }
};

Distance operator"" _mi(long double val)
{
    return Distance{ val * 16 };
}

Distance operator"" _metres(long double val)
{
    return Distance(val / 1000);
}

void userdefinedliteral()
{
    Distance dist{ 32.0_mi };
    Distance d2{ 7123.0_metres };
    std::cout << d2.GetKm() << std::endl;
}

constexpr int GetNumber()
{
    return 42;
}

constexpr int Add(int x, int y)
{
    return x + y;
}

constexpr int Max(int x, int y)
{
    return x > y ? x : y;
}

void ConstantExpression()
{
    // Behaves as a constexpr function
    constexpr int i = GetNumber();
    int arr[i];

    // Behaves as a constexpr function
    const int j = GetNumber();

    int arr1[j];

    // Behaves as a normal function
    int x = GetNumber();

    constexpr int sum = Add(3, 5);

    int sum2 = Add(3, 5);

    // Should accept and return literal types only
}

class Bag {
    int arr[10];
    int m_Size{};
public:
    Bag(std::initializer_list<int> values)
    {
        assert(values.size() < 10);
        auto it = values.begin();
        while (it != values.end())
        {
            Add(*it);
            ++it;
        }
    }

    void Add(int value)
    {
        assert(m_Size < 10);
        arr[m_Size++] = value;
    }

    void Remove()
    {
        --m_Size;
    }

    int operator [](int index)
    {
        return arr[index];
    }

    int GetSize()const
    {
        return m_Size;
    }
};

void Print(std::initializer_list<int> values)
{
    /*auto it = values.begin();
    while (it != values.end())
    {
        std::cout << *it++ << " ";
    }*/
    for (auto x : values)
    {
        std::cout << x << " ";
    }
}

void initializerlist()
{
    int x{ 0 };
    float y{ 3.1f };
    int arr[5]{ 3, 1 ,3 ,8 ,2 };
    std::string s{ "Hello C++" };
    std::initializer_list<int> data = { 1, 2, 3, 4 };
    auto values = { 1,2,3,4 };
    Bag b{ 3, 1, 8 };
    for (int i = 0; i < b.GetSize(); ++i)
    {
        std::cout << b[i] << " ";
    }

    Print({ 8,2,6,7 });

    for (auto x : { 8,2,6,7 })
    {
        std::cout << x << " ";
    }
}

void stdvector()
{
    int arr[10];
    int* ptr = new int[10];
    for (int i = 0; i < 10; ++i)
    {
        ptr[i] = i * 10;
    }

    std::vector<int> data{ 1,2,3 };
    for (int i = 0; i < 5; ++i)
    {
        data.push_back(i * 10);
    }

    // Access
    data[0] = 100;
    for (int i = 0; i < data.size(); ++i)
    {
        std::cout << data[i] << " ";
    }

    for (auto& x : data)
    {
        std::cout << x << " ";
    }
    auto it = data.begin();
    ++it;

    --it;

    it = it + 5;

    *it = 5;

    // Delete
    it = data.begin();
    data.erase(it);
    std::cout << std::endl;
    for (auto& x : data)
    {
        std::cout << x << " ";
    }

    // Insert
    it = data.begin() + 5;
    data.insert(it, 500);
    std::cout << std::endl;
    for (auto& x : data)
    {
        std::cout << x << " ";
    }
}

union Test {
    int x;
    char ch;
    double d;
    Test() : ch{ 'a' }
    {
        std::cout << __FUNCSIG__ << std::endl;
    }

    ~Test()
    {
        std::cout << __FUNCSIG__ << std::endl;
    }
};

void UnionSample()
{
    std::cout << sizeof(Test) << std::endl;
    Test t;
    std::cout << t.ch << std::endl;
    t.x = 1000;
    std::cout << t.ch << std::endl;
}

struct A
{

};

struct B
{

};

union UDT
{
    A a;
    B b;
    std::string s;
    UDT()
    {

    }
    ~UDT()
    {

    }
};

void MoreUnionSample()
{
    UDT udt;
    //new(&udt.s) std::string{ "Hello Worlds" };
    new(&udt.a) A{};
}

int main()
{
    return 0;
}