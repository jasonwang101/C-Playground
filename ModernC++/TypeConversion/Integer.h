#pragma once
#include <iostream>

class Integer {
    int* m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer& obj);
    Integer(Integer&& obj);
    int GetValue()const;
    void SetValue(int value);
    ~Integer();

    Integer operator +(const Integer& a) const;
    Integer& operator ++();
    Integer operator ++(int);
    bool operator ==(const Integer& obj) const;
    Integer& operator=(const Integer& obj);
    Integer& operator=(Integer&& obj);

    void operator ()();
    friend std::istream& operator >> (std::istream& input, Integer& a);
    friend class Printer;

    explicit operator int();
};

class Printer {

};