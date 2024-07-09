/*
name: Hyeonjun Son
email: hson15@myseneca.ca
Student id: 123526238
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

namespace seneca {

    void Item::setName(const char* name) {
        if (name && name[0] != '\0') {
            if (strlen(name) <= 20) {
                strcpy(m_itemName, name);
            }
            else {
                strncpy(m_itemName, name, 20);
                m_itemName[20] = '\0';
            }
        }
    }

    void Item::setEmpty() {
        m_price = 0.0;
        m_taxed = false;
        m_itemName[0] = '\0';
    }

    void Item::set(const char* name, double price, bool taxed) {
        if (price < 0 || name == nullptr) {
            setEmpty();
        }
        else {
            m_price = price;
            m_taxed = taxed;
            setName(name);
        }
    }

    void Item::display() const {
        if (isValid()) {
            cout << "| ";
            cout.setf(ios::left);
            cout.fill('.');
            cout.width(20);
            cout << m_itemName;
            cout.unsetf(ios::left);
            cout << " | ";
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout.fill(' ');
            cout.width(7);
            cout << m_price;
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
            cout << " | ";
            cout << (m_taxed ? "Yes" : "No ");
            cout << " |\n";
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |\n";
        }
    }

    bool Item::isValid() const {
        return m_price > 0 && m_itemName[0] != '\0';
    }

    double Item::price() const {
        return m_price;
    }

    double Item::tax() const {
        return m_taxed ? m_price * 0.13 : 0.0;
    }
}
