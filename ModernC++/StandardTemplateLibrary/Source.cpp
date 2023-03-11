#include <array>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

void Array()
{
    std::array<int, 5> arr{ 1,2 };
    for (int i = 0; i < arr.size(); ++i)
    {
        arr[i] = i;
    }
    auto itr = arr.begin();

    for (auto x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    arr.data();
}

void Vector()
{
    std::vector<int> coll{ 1, 2, 3, 4 };
    for (int i = 0; i < 5; ++i)
    {
        coll.push_back(i + 10);
        std::cout << coll.size() << std::endl;
    }

    coll[0] = 100;
    auto itr = coll.begin();
    while (itr != coll.end())
    {
        std::cout << *itr++ << " ";
    }
    coll.insert(coll.begin(), 700);
    coll.erase(coll.end() - 5);
    coll.pop_back();
}

void Deque()
{
    std::deque<int> coll{ 1, 2, 3, 4 };
    for (int i = 0; i < 5; ++i)
    {
        coll.push_back(i + 10);
        std::cout << coll.size() << std::endl;
    }
    for (int i = 0; i < 5; ++i)
    {
        coll.push_front(i + 10);
        std::cout << coll.size() << std::endl;
    }

    coll[0] = 100;
    auto itr = coll.begin();
    while (itr != coll.end())
    {
        std::cout << *itr++ << " ";
    }
    coll.insert(coll.begin(), 700);
    coll.erase(coll.end() - 5);
    coll.pop_back();
    coll.pop_front();
}

void List()
{
    std::list<int> coll;
    for (int i = 0; i < 5; ++i)
    {
        coll.push_back(i * 10);
    }
    auto itr = coll.begin();
    coll.insert(itr, 800);
    coll.erase(itr);
}

void ForwardList()
{
    std::forward_list<int> coll;
    for (int i = 0; i < 10; ++i)
    {
        coll.push_front(i);
    }
    coll.insert_after(coll.begin(), 10);
    coll.erase_after(coll.begin());
}

void Set()
{
    std::set<int> s{ 8,2,0,9,5 };
    s.insert(1);
    s.insert(3);

    auto itr = s.begin();
    while (itr != s.end())
    {
        std::cout << *itr++ << " ";
    }
    s.erase(0);
    s.erase(s.begin());
    itr = s.find(9);
    if (itr != s.end())
    {
        std::cout << "Element found" << std::endl;
    }
}

void MutiSet()
{
    std::multiset<int> s{ 8,2,0,9,5 };
    s.insert(1);
    s.insert(3);

    auto itr = s.begin();
    while (itr != s.end())
    {
        std::cout << *itr++ << " ";
    }
    s.erase(0);
    s.erase(s.begin());
    itr = s.find(9);
    if (itr != s.end())
    {
        std::cout << "Element found" << std::endl;
    }
    auto found = s.equal_range(3);
    while (found.first != found.second)
    {
        std::cout << *found.first++ << " ";
    }
}

void Map()
{
    std::map<int, std::string> m
    {
        {1, "Superman"},
        {2, "Batman"}
    };
    m.insert(std::pair<int, std::string>(8, "Aquaman"));
    m.insert(std::make_pair(6, "Wonder Woman"));

    m[0] = "Flash";

    auto itr = m.begin();
    std::cout << itr->first << ":" << itr->second << std::endl;
    for (const auto& x : m)
    {
        std::cout << x.first << ":" << x.second << std::endl;
    }
    itr = m.find(1);
    if (itr != m.end())
    {
        std::cout << "Found:" << itr->second << std::endl;
    }
    std::cout << "10:" << m[10] << std::endl;
}

void MultiMap()
{
    std::multimap<int, std::string> m
    {
        {1, "Superman"},
        {2, "Batman"},
        {2, "Batman"}
    };
    m.insert(std::pair<int, std::string>(8, "Aquaman"));
    m.insert(std::make_pair(6, "Wonder Woman"));

    auto found = m.equal_range(2);
    while (found.first != found.second)
    {
        std::cout << found.first->first << std::endl;
        found.first++;
    }

    auto itr = m.begin();
    std::cout << itr->first << ":" << itr->second << std::endl;
    for (const auto& x : m)
    {
        std::cout << x.first << ":" << x.second << std::endl;
    }
    itr = m.find(1);
    if (itr != m.end())
    {
        std::cout << "Found:" << itr->second << std::endl;
    }
}

void Unordered()
{
    std::unordered_set<std::string> coll;
    coll.insert("Hulk");
    coll.insert("Batman");
    for (const auto x : coll)
    {
        std::cout << coll.bucket(x) << "contians:" << std::endl;
    }

    coll.bucket_count();
    coll.size();
    coll.load_factor();
}

void UnorderedMap()
{
    std::unordered_map<std::string, std::string> coll;
    coll["Yes"] = "Hulk";
    coll["No"] = "Batman";
    for (const auto x : coll)
    {
        std::cout << coll.bucket(x.first) << "contians:" << std::endl;
    }

    coll.bucket_count();
    coll.size();
    coll.load_factor();
}

class Employee {
    std::string m_Name;
    int m_Id;
public:
    Employee(const std::string& n, int id) :m_Name(n), m_Id(id) {

    }
    const std::string& GetName()const {
        return m_Name;
    }
    int GetId()const {
        return m_Id;
    }
};

//Custom hash function
struct EmployeeHash {
    size_t operator()(const Employee& emp)const {
        auto s1 = std::hash<std::string>{}(emp.GetName());
        auto s2 = std::hash<int>{}(emp.GetId());
        return s1 ^ s2;
    }
};
//Custom function object for equality
struct EmpEquality {
    bool operator()(const Employee& e1, const Employee e2)const {
        return e1.GetId() == e2.GetId();
    }
};
void Hashes() {
    std::hash<std::string> h;
    //Hash is computed by the function object
    std::cout << "Hash:" << h("Hello") << std::endl;

    std::unordered_set<Employee, EmployeeHash, EmpEquality> coll;
    coll.insert(Employee("Umar", 123));
    coll.insert(Employee("Bob", 678));
    coll.insert(Employee("Joey", 612));

    for (const auto& x : coll) {
        std::cout << x.GetId() << ":" << x.GetName() << std::endl;
    }
}

class Employee1 {
    std::string m_Name;
    int m_Id;
    std::string m_ProgLang;
public:
    Employee1(const std::string& n, int id, const std::string& pl) :
        m_Name(n),
        m_Id(id),
        m_ProgLang(pl) {

    }
    const std::string& GetName()const {
        return m_Name;
    }
    int GetId()const {
        return m_Id;
    }
    const std::string& GetProgrammingLanguage()const {
        return m_ProgLang;
    }
    //bool operator <(const Employee &e)const {
    //	return m_Id < e.m_Id;
    //}
};
struct EmpIds {
    std::vector<int> m_Ids;
    void operator()(const Employee1& emp) {
        if (emp.GetProgrammingLanguage() == "C++")
            m_Ids.push_back(emp.GetId());
    }
};
void UserDefined() {
    std::vector<Employee1> v{
        Employee1{ "Umar", 101, "C++" },
        Employee1{ "Bob", 202, "Java"},
        Employee1{ "Joey", 200, "C++"}
    };
    //Use callback to avoid overloading comparison operators
    std::sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {
        return e1.GetName() < e2.GetName();
        });
    for (const auto& e : v) {
        std::cout
            << "Id:" << e.GetId()
            << " | Name:" << e.GetName()
            << " | Language:" << e.GetProgrammingLanguage() << std::endl;
    }

    int cppCount{};
    //for (const auto &e : v) {
    //	if (e.GetProgrammingLanguage() == "C++")
    //		++cppCount;
    //}

    //Terse, but gives more information to the reader as compared to a for loop
    cppCount = std::count_if(v.begin(), v.end(), [](const auto& e) {
        return e.GetProgrammingLanguage() == "C++";
        });
    std::cout << "Count:" << cppCount << std::endl;

    //Find if any employee knows Java
    auto itr = std::find_if(v.begin(), v.end(), [](const auto& e) {
        return e.GetProgrammingLanguage() == "Java";
        });
    if (itr != v.end()) {
        std::cout << "Found:" << itr->GetName() << " is a Java programmer" << std::endl;
    }
    //Print all employee names
    std::for_each(v.begin(), v.end(), [](const auto& e) {
        std::cout << e.GetName() << std::endl;
        });

    //Get ids of all employees that know C++
    auto foundIds = std::for_each(v.begin(), v.end(), EmpIds());
    for (int id : foundIds.m_Ids) {
        std::cout << "Id:" << id << std::endl;
    }

}
int main()
{

}