#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transact.h"
#include <typeinfo>

class Animal
{
public:
    void Eat()
    {
        std::cout << "Animal eating" << std::endl;
    }
    void Run()
    {
        std::cout << "Animal running" << std::endl;
    }
    void Speak()
    {
        std::cout << "Animal speaking" << std::endl;
    }
};
class Dog : public Animal
{
public:
    void Eat()
    {
        std::cout << "Dog eating" << std::endl;
    }
    void Speak()
    {
        std::cout << "Dog barking" << std::endl;
    }
};

void DogSample()
{
    Dog d;
    d.Eat();
    d.Run();
    d.Speak();
}

namespace Banking
{
    void AccountSample()
    {
        Savings acc("Bob", 1000, 0.5f);
        std::cout << "Initial balance:" << acc.GetBalance() << std::endl;
        acc.Deposit(200);
        acc.AccumulateInterest();
        acc.Withdraw(380);
        std::cout << "Balance : " << acc.GetBalance() << std::endl;
    }

    void CheckingSample()
    {
        Checking acc("Bob", 50);
        std::cout << "Initial balance:" << acc.GetBalance() << std::endl;
        acc.Withdraw(380);
        std::cout << "Balance : " << acc.GetBalance() << std::endl;
    }

    void TransactionSimple()
    {
        Account* acc1 = new Checking("Bob", 100, 0.05f);
        delete acc1;
        Savings acc("Bob", 100, 0.05f);
        try
        {
            Transact(&acc);
        }
        catch (std::exception& ex)
        {
            std::cout << "Exception:" << ex.what() << std::endl;
        }
        std::cout << "Size of Account " << sizeof(acc) << std::endl;
    }
}

class Zip final
{
public:
    Zip()
    {
    }
};

class Document
{
public:
    virtual void Serialize(float version) = 0;
};
class Text : public Document
{
public:
    void Serialize(float version) override final
    {
        std::cout << "Text::Serialize" << std::endl;
    }
};

void ObjectSlicing()
{
    Checking ch("Bob", 100);

    // Bad! Object slicing
    //Account pAccount = ch;

    Account* pAccount = &ch;

    Checking* pChecking = static_cast<Checking*>(pAccount);
}

void TypeIdSample()
{
    Savings ch{ "Bob", 100, 0.05f };
    Account* p = &ch;

    int i{};
    float f{};
    const std::type_info& ti = typeid(*p);
    if (ti == typeid(Savings))
    {
        std::cout << "p points to saving object" << std::endl;
    }
    else
    {
        std::cout << "Not pointing to savings object" << std::endl;
    }
    std::cout << ti.name() << std::endl;
}

class XML : public Document
{
public:
    void Serialize(float version) override
    {
        std::cout << "XML:Serialize" << std::endl;
    }
};

void Write(Document* p)
{
    p->Serialize(1.1f);
}

class Stream
{
    std::string m_FileName;
public:
    Stream(const std::string& filename) : m_FileName{ filename }
    {
        std::cout << "Stream()" << std::endl;
    }

    ~Stream()
    {
        std::cout << "~Stream()" << std::endl;
    }

    const std::string GetFileName() const {
        return m_FileName;
    }
};

class OutputStream : virtual public Stream
{
    std::ostream& out;
public:
    OutputStream(std::ostream& o, const std::string& filename) : out(o), Stream(filename)
    {
        std::cout << "OutputStream" << std::endl;
    }

    ~OutputStream()
    {
        std::cout << "~OutputStream" << std::endl;
    }

    std::ostream& operator << (const std::string& data)
    {
        out << data;
        return out;
    }
};

class InputStream : virtual public Stream
{
    std::istream& in;
public:
    InputStream(std::istream& o, const std::string& filename) : in(o), Stream(filename)
    {
        std::cout << "InputStream" << std::endl;
    }

    ~InputStream()
    {
        std::cout << "~InputStream" << std::endl;
    }

    std::istream& operator >> (std::string& data)
    {
        in >> data;
        return in;
    }
};

class IOStream : public OutputStream, public InputStream
{
public:
    IOStream(const std::string& filename) : OutputStream(std::cout, filename), InputStream(std::cin, filename), Stream(filename)
    {
        std::cout << "IOStream" << std::endl;
    }

    ~IOStream()
    {
        std::cout << "~IOStream" << std::endl;
    }
};

int main()
{
    IOStream stream("filename.doc");
    std::string data;
    stream >> data;
    stream << data;
    stream << stream.GetFileName() << std::endl;
    return 0;
}