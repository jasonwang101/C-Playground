#include <iostream>
#include <fstream>
#include <string>

void RawStringLiterals()
{
    std::string filename{ R"(C:\temp\newfile.txt)" };
    std::cout << filename << std::endl;
    std::string message{ R"MSG(C++ introduced filesystem API "(In C++11))MSG" };
    std::cout << message << std::endl;
}

void Write()
{
    std::ofstream out{ "data.txt" };
    out << "Hello world" << std::endl;
    out << 10 << std::endl;

    std::string message{ "C++ was invented by Bjarne" };
    for (char ch : message)
    {
        out.put(ch);
    }
    out.seekp(5);
    out.put('#');
    out.close();

}

void Read()
{
    std::ifstream input{ "data.txt" };
    if (!input.is_open())
    {
        std::cout << "Could not open the file" << std::endl;
        return;
    }

    if (input.fail())
    {
        std::cout << "Could not open the file" << std::endl;
        return;
    }

    std::cout << "Current position is: " << input.tellg() << std::endl;
    input.seekg(5, std::ios::beg);
    std::cout << "Current position is: " << input.tellg() << std::endl;
    char ch{};
    while (input.get(ch))
    {
        std::cout << ch;
    }
    input.close();

    input.open("data.txt");

    std::string message;
    std::getline(input, message);
    int value{};
    input >> value;
    if (input.eof())
    {
        std::cout << "End of file encountered" << std::endl;
    }
    if (input.good())
    {
        std::cout << "I/O operations are successful" << std::endl;
    }
    else
    {
        std::cout << "Some I/O operations failed" << std::endl;
    }
    input.setstate(std::ios::failbit);
    input.clear();
    input.close();
    std::cout << message << ":" << value << std::endl;
}

void UsingFStream()
{
    std::fstream stream{ "file.txt" };
    if (!stream)
    {
        std::cout << "FILE DOES NOT EXIST. CREATING ONE..." << std::endl;
        std::ofstream out{ "file.txt" };
        out.close();
        stream.open("file.txt");
    }
    stream << "Hello World" << std::endl;

    stream.seekg(0);
    std::string line;
    std::getline(stream, line);
    std::cout << line << std::endl;
}

struct Record
{
    int id;
    char name[10];
};

void WriteRecord(Record* p)
{
    std::ofstream binstream{ "records", std::ios::binary | std::ios::out };
    binstream.write((const char*)p, sizeof(Record));
}

Record GetRecord()
{
    std::ifstream input{ "records", std::ios::binary | std::ios::in };
    Record r;
    input.read((char*)&r, sizeof(Record));
    return r;
}

void UsingIBinary()
{
    std::ofstream textStream{ "data" };
    textStream << 12345678;

    std::ofstream binStream("binary", std::ios::binary | std::ios::out);
    int num{ 12345678 };
    binStream.write((const char*)&num, sizeof(num));
    binStream.close();
    num = 0;
    std::ifstream input{ "binary", std::ios::binary | std::ios::in };
    input.read((char*)&num, sizeof(num));

    std::cout << num << std::endl;
}

int main()
{
    Record r;
    r.id = 1001;
    strcpy_s(r.name, "Jason");
    WriteRecord(&r);

    Record r2 = GetRecord();
    std::cout << r2.id << ":" << r2.name << std::endl;
    return 0;
}