#include <iostream>
#include <memory>
#include <vector>
#include <random>

class A
{
public:
    A()
    {
        std::cout << "A()" << std::endl;
    }

    ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};

class B
{
public:
    B()
    {
        std::cout << "B()" << std::endl;
    }

    ~B()
    {
        std::cout << "~B()" << std::endl;
    }
};

class Test
{
    std::unique_ptr<A> pA{};
    B b{};
    std::unique_ptr<int> pInt{};
    std::string pStr{};
    std::vector<int> pArr{};
public:
    Test()
    {
        std::cout << "Test()" << std::endl;
        pA.reset(new A);
        throw std::runtime_error("Failed to initialize");
    }

    ~Test()
    {
        std::cout << "~Test()" << std::endl;
    }
};

int ProcessRecords(int count)
{
    std::unique_ptr<Test> t(new Test);
    if (count < 10)
        throw std::out_of_range("Count should be greater than 10");

    std::vector<int> p;
    p.reserve(count);

    std::vector<int> pArray;
    pArray.reserve(count);

    for (int i = 0; i < count; i++)
    {
        pArray.push_back(i);
    }

    /*int* p = new int[count];
    int* pArray = (int*)malloc(count * sizeof(int));
    if (pArray == nullptr)
    {
        throw std::runtime_error("Failed to allocate memory");
    }
    for (int i = 0; i < count; i++)
    {
        pArray[i] = 1;
    }
    free(pArray);*/

    std::default_random_engine eng;
    std::bernoulli_distribution dist;

    int errors{};
    for (int i = 0; i < count; ++i)
    {
        try
        {
            std::cout << "Processing record # : " << i << " ";
            if (!dist(eng))
            {
                ++errors;
                throw std::runtime_error("Could not process the record");
            }
            std::cout << std::endl;
        }
        catch (std::runtime_error& ex)
        {
            std::cout << ex.what() << std::endl;
            if (errors > 4)
            {
                std::runtime_error err("Too many errors. Abandoning operation");
                ex = err;
                throw;
            }
        }
    }
    return 0;
}

void MulitpleCatchException()
{
    try
    {
        //ProcessRecords(std::numeric_limits<int>::max());
        ProcessRecords(10);
    }
    catch (std::runtime_error& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::out_of_range& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Exception" << std::endl;
    }
}

void ConstructorException()
{
    try
    {
        Test t;
    }
    catch (std::runtime_error& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void Test1(int x)
{
    throw x;
}

int Sum(int x, int y) noexcept(noexcept(Test1(x)))
{
    Test1(x);
    return x + y;
}

void NoexceptSample()
{
    try {
        Sum(3, 5);
    }
    catch (int x)
    {
        std::cout << x << std::endl;
    }
}

int main()
{
    return 0;
}