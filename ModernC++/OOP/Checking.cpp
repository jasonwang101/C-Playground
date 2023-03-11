#include "Checking.h"
#include <iostream>

Checking::Checking(const std::string& name, float balance, float minbalance) : Account(name, balance), m_MinimumBalance{ minbalance }
{
}

Checking::~Checking()
{
}

void Checking::Withdraw(float amount)
{
    if ((m_Balance - amount) > 50)
    {
        Account::Withdraw(amount);
    }
    else
    {
        std::cout << "Invalid amount" << std::endl;
    }
}

float Checking::GetMinimumBalance() const
{
    return m_MinimumBalance;
}
