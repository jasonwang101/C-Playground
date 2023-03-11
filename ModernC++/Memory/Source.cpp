#include "Integer.h"
#include <memory>

void Display(Integer* p)
{
    if (!p)
    {
        return;
    }
    std::cout << p->GetValue() << std::endl;
}

Integer* GetPointer(int value) {
    Integer* p = new Integer{ value };
    return p;
}

void Store(std::unique_ptr<Integer>& p)
{
    std::cout << "Storing data into a file:" << p->GetValue() << std::endl;
}

void Operate(int value) {
    std::unique_ptr<Integer> p{ GetPointer(value) };
    if (p == nullptr)
    {
        p.reset(new Integer{ value });
    }
    p->SetValue(100);
    Display(p.get());
    // delete p;
    //p = nullptr;
    p.reset(new Integer{});
    *p = __LINE__;
    Display(p.get());
    Store(p);
    *p = 200;
    //delete p;
}

class Project {
    std::string m_Name;
public:
    void SetName(const std::string& name)
    {
        m_Name = name;
    }
    void ShowProjectDetails() const
    {
        std::cout << "[Project Name]" << m_Name << std::endl;
    }
};

class Employee {
    std::shared_ptr<Project> m_pProject{};
public:
    void SetProject(const std::shared_ptr<Project>& prj)
    {
        m_pProject = prj;
    }
    const std::shared_ptr<Project>& GetProject() const
    {
        return m_pProject;
    }
};

void ShowInfo(const std::shared_ptr <Employee>& emp)
{
    std::cout << "Employee project details:" << std::endl;
    emp->GetProject()->ShowProjectDetails();
}

void SharePointer()
{
    std::shared_ptr<Project> prj{ new Project{} };
    prj->SetName("Video Decoder");
    std::shared_ptr <Employee> e1{ new Employee{} };
    e1->SetProject(prj);
    std::shared_ptr <Employee> e2{ new Employee{} };
    e2->SetProject(prj);
    std::shared_ptr <Employee> e3{ new Employee{} };
    e3->SetProject(prj);

    e3.reset(new Employee{});
    if (e3)
    {
        //Valid
    }
    else
    {
        // Not valid
    }

    std::cout << "Reference count: " << prj.use_count() << "\n";
    ShowInfo(e1);
    ShowInfo(e2);
    prj->ShowProjectDetails();
}

class Printer
{
    std::weak_ptr<int> m_pValue{};
public:
    void SetValue(std::weak_ptr<int> p)
    {
        m_pValue = p;
    }

    void Print()
    {
        std::cout << "Ref count" << m_pValue.use_count() << std::endl;
        if (m_pValue.expired())
        {
            std::cout << "Resource is no longer available" << std::endl;
            return;
        }

        auto sp = m_pValue.lock();
        std::cout << "Value is:" << *sp << std::endl;
        std::cout << "Ref count" << sp.use_count() << std::endl;
    }
};

void weak_point()
{
    Printer prn;
    int num{};
    std::cin >> num;
    std::shared_ptr<int> p{ new int{ num } };
    prn.SetValue(p);

    if (*p > 10)
    {
        p = nullptr;
    }

    prn.Print();
}

namespace WeakPointer {

    class Employee1;
    class Project1
    {
    public:
        std::weak_ptr<Employee1> m_emp;
        Project1()
        {
            std::cout << "Project1()" << std::endl;
        }

        ~Project1()
        {
            std::cout << "~Project1()" << std::endl;
        }
    };

    class Employee1
    {
    public:
        std::weak_ptr<Project1> m_prj;
        Employee1()
        {
            std::cout << "Employee1()" << std::endl;
        }
        ~Employee1()
        {
            std::cout << "~Employee1()" << std::endl;
        }
    };

    void weakpointer()
    {
        std::shared_ptr<Employee1> emp{ new Employee1{} };
        std::shared_ptr<Project1> prj{ new Project1{} };

        emp->m_prj = prj;
        prj->m_emp = emp;
    }
}

struct Free {
    void operator()(int* p)
    {
        free(p);
        std::cout << "pointer free\n";
    }
};

void MallocFree(int* p)
{
    free(p);
    std::cout << "MallocFree free\n";
}

void unique()
{
    //std::unique_ptr<int, Free> p{ (int*)malloc(4), Free{} };
    std::unique_ptr<int, void (*)(int*)> p{ (int*)malloc(4), MallocFree };
    *p = 100;
    std::cout << *p << '\n';
}

void shared()
{
    std::shared_ptr<int> p{ (int*)malloc(4), Free{} };
    //std::shared_ptr<int> p{ (int*)malloc(4), MallocFree };
    *p = 100;
    std::cout << *p << '\n';
}

void DynamicArrays()
{
    std::shared_ptr<int[]> p{ new int[5]{1,2,3,4,5} };
    p[0] = 100;
}

class Point
{
public:
    Point(int x, int y)
    {

    }
};

void make_unique()
{
    auto p = std::make_unique<int>(5);
    auto pt = std::make_unique<Point>(3, 5);

    auto pArr = std::make_unique<int[]>(5);
    pArr[0] = 0;
}

void make_shared()
{
    auto p = std::make_shared<int>(5);
    auto pt = std::make_shared<Point>(3, 5);
}

int main()
{
}