#include <iostream>

class Product
{
    void Assign()
    {
        [this](auto& x)
        {

        };
    }
};

int main()
{
    auto fn = []()
    {
        std::cout << "Welcome to Lambda expressions!";
    };
    fn();
    std::cout << typeid(fn).name() << std::endl;

    auto sum = [](int x, int y)->double
    {
        return x + y;
    };

    auto sum1 = [](auto x, auto y)noexcept {
        return x + y;
    };

    int offset = 5;
    [offset](auto& x)
    {
        x += offset;
    };

    [offset](auto& x)mutable
    {
        x += offset;
        ++offset;
    };

    int sum2{};
    [&sum2](auto& x)
    {
        sum2 += x;
    };

    [&](auto& x)
    {

    };

    [=](auto& x)
    {

    };

    atexit([]() {
        std::cout << "Program is exting..." << std::endl;
        });

    int x{ 5 };
    auto f = [y = x](int arg)
    {
        return y + arg;
    };

    std::cout << f(15) << std::endl;

    return 0;
}