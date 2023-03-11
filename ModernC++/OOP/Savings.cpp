#include "Savings.h"
#include <iostream>

Savings::Savings(const std::string& name, float balance, float rate) : Account(name, balance), m_Rate{ rate }
{
    std::cout << "Savings(const std::string &, float)" << std::endl;
}

Savings::~Savings()
{
    std::cout << "~Savings()" << std::endl;
}

void Savings::AccumulateInterest()
{
    m_Balance += (m_Balance * m_Rate);
}

float Savings::GetInterestRate() const
{
    return m_Rate;
}
