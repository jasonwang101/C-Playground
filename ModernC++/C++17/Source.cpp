#ifdef __has_include
#if __has_include(<filesystem>)
#include<filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif
#include <iostream>
#endif
#include <variant>
#include <any>
#include <execution>


[[deprecated("Use the new version instead")]]
void Deprecate()
{

}

template<typename T>
[[nodiscard]]
T* CreateArray(size_t size)
{
    return new T[size];
}

class [[deprecated("This class is replaced by NewTest clas")]] Test
{

};

namespace [[deprecated("DO NOT USE")]] A
{

}

void FileSystem()
{
    fs::path p{ "C:" };

    std::cout << __cpp_inline_variables << std::endl;
    std::cout << __cpp_capture_star_this << std::endl;
}

void SwitchWithInitialization()
{
    if (int* p = (int*)malloc(sizeof(int)); p != nullptr)
    {
        *p = 50;
        free(p);
    }
    else
    {

    }

    switch (int i = 0; i)
    {
    case 0:
        break;
    }
}

extern int global;
inline int global;

class Test
{
    inline static int m_Data = 50;
};

namespace A
{
    namespace B
    {
        namespace C {

        }
    }
}

namespace A::B::C
{
    void Foo()
    {
    }
}

class ConstexprLambda {
    auto GetDescription()
    {
        return[*this]()
        {
        };
    };
};

void ConstexprLambda1()
{
    auto f = [](int x, int y)
    {
        return x + y;
    };
    constexpr auto sum = f(3, 5);
}

struct Person
{
    std::string m_Name;
    int m_Age;
};

void StructuredBindings()
{
    Person p{ "Ayann", 14 };
    const auto& [name, age] = p;

    std::pair<int, int> p1{ 3,5 };
    auto [key, value] = p;
    int arr[] = { 1,2,3 };
    auto [a, b, c] = arr;
    auto arr2 = arr;
}

class EvaluationOrder
{
public:
    EvaluationOrder& First(int)
    {
    }
};

void MandatoryCopyElision()
{

}

template<typename T>
class Data {
public:
    Data(const T& t)
    {

    }
};

Data(const char*)->Data<std::string>;

class TemplateArgumentDeduction
{

};

void TemplateArgumentDeduction()
{
    std::pair<int, int> p1{ 2,5 };
    std::pair p3{ p1 };

    Data data{ "Hello World" };
}

auto Sum()
{
    return 0;
}

template<typename T, typename ...Args>
auto Sum(T a, Args...args)
{
    return a + Sum(args...);
}

template<typename ...Args>
auto Sum2(Args...args)
{
    return (args + ...); //Unary right fold
    return { ... + args } // Unary left fold
}

template<typename ...Args>
auto Sum3(Args...args)
{
    return (args + ... + 0); // Binary right fold
    return { 0 + ... + args } // Binary left fold
}

template<typename ...Args>
bool AnyOf(Args...args)
{
    return (... || (args % 2 == 0));
}

template<typename ...Args>
bool AllOf(Args...args)
{
    return (... && (args % 2 == 0));
}

template<typename T>
void IfConstexpr(const T& value)
{
    if constexpr (std::is_pointer_v<T>)
    {
        std::cout << *vallue << std::endl;
    }
    else constexpr if (std::is_array_v<T>)
    {
        for (auto v : value)
        {
            std::cout << v << ' ';
        }
    }
    else
    {
        std::cout << value << std::endl;
    }
}

void Optional(int errorNo)
{
    std::optional<int> value = std::nullopt;
    if (value.has_value())
    {

    }

    if (value)
    {

    }

    auto result = value.value_or(1);
}

void Variant()
{
    std::variant<std::string, int> v{ 5 };
    auto val = std::get<int>(v);
    val = std::get<1>(v);

    auto val1 = std::get_if<1>(&v);

    std::get<int>(v) = 100;
    v.emplace<int>(500);

    auto activeIndex = v.index();
}

void Any()
{
    std::any v1 = 5;
    v1 = "Hello";
    v1.reset();
    auto p2 = std::make_any<int>(5);
}

void StringView()
{
    using namespace std::string_view_literals;
    std::string_view sv1 = "Hello world";
    std::string str1{ "Hello" };
    std::string_view sv2 = str1;

    auto sv3 = "Using\0literals"sv;

    std::cout << sv3 << std::endl;
    std::cout << "data() " << sv3.data() << std::endl;
};

void FileSystem()
{
    fs::path selectedPath(R"(E:\Data)");
    std::cout << selectedPath << std::endl;
    std::cout << selectedPath.string() << std::endl;
}

void List(std::string_view file)
{
    fs::path currentPath{ file };
    fs::directory_iterator begin{ currentPath };
    fs::directory_iterator end{};
    for (const auto& dir_entry : fs::directory_iterator{ currentPath })
    {
        std::cout << dir_entry.path() << std::endl;
    }
}

void Directory(std::string_view file)
{
    fs::path currentPath(file);
    if (fs::exists(currentPath))
    {
        std::cout << currentPath.string() << std::endl;
    }
    fs::current_path();
}

void Permission()
{
    fs::status(fs::path{ "" });
    fs::permissions(fs::path{ "" }, fs::perms::owner_exec, fs::perm_options::add);
}

void ParallelAlgorithms()
{
    std::vector arr{ 0 };
    // overhead slow for small data
    std::sort(std::execution::par, arr.begin(), arr.end());
}

int main()
{

}