#include "Transact.h"
#include <iostream>
#include "Checking.h"

void Transact(Account* pAccount)
{
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance:" << pAccount->GetBalance() << std::endl;
    pAccount->Deposit(100);
    pAccount->AccumulateInterest();
    Checking* pChecking = dynamic_cast<Checking*>(pAccount);
    if (pChecking != nullptr)
    {
        Checking* pChecking = static_cast<Checking*>(pAccount);
        std::cout << "Minimum balance of checking: " << pChecking->GetMinimumBalance() << std::endl;
    }
    pAccount->Withdraw(170);
    std::cout << "Interest rate:" << pAccount->GetInterestRate() << std::endl;
    std::cout << "Final balance:" << pAccount->GetBalance() << std::endl;
}


void Transact(Account& pAccount)
{
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance:" << pAccount.GetBalance() << std::endl;
    pAccount.Deposit(100);
    pAccount.AccumulateInterest();
    Checking& pChecking = dynamic_cast<Checking&>(pAccount);
    std::cout << "Minimum balance of checking: " << pChecking.GetMinimumBalance() << std::endl;
    pAccount.Withdraw(170);
    std::cout << "Interest rate:" << pAccount.GetInterestRate() << std::endl;
    std::cout << "Final balance:" << pAccount.GetBalance() << std::endl;
}