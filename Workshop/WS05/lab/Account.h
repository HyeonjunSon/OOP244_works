//
// Created by Hyeonjun Son on 2024-06-15
// Name: Hyeonjun Son
// Email: hson15@myseneca.ca
// Student ID: 123526238

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_

#include <iostream>

namespace seneca {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();

    public:
        Account();
        Account(int number, double balance);
        std::ostream &display() const;

        /* Convertor operators */
        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator~() const;

        /* Binary member operators */
        Account &operator=(const int accountNumber);
        Account &operator=(Account &account);
        Account &operator+=(const double balance);
        Account &operator-=(const double balance);
        Account &operator<<(Account &account);
        Account &operator>>(Account &account);
    };
    /* Binary helper operators */
    double operator+(const Account &left, const Account &right);
    double& operator+=(double &left, const Account &right);
}
#endif // SENECA_ACCOUNT_H_