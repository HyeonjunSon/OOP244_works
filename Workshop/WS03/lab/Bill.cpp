/*
name: Hyeonjun Son
email: hson15@myseneca.ca
Student id: 123526238
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Bill.h"

using namespace std;

namespace seneca {

    double Bill::totalTax() const {
        double total = 0.0;
        for (int i = 0; i < m_noOfItems; i++) {
            total += m_items[i].tax();
        }
        return total;
    }

    double Bill::totalPrice() const {
        double total = 0.0;
        for (int i = 0; i < m_noOfItems; i++) {
            total += m_items[i].price();
        }
        return total;
    }

    void Bill::Title() const {
        cout << "+--------------------------------------+\n";
        if (isValid()) {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title;
            cout.unsetf(ios::left);
            cout << " |\n";
        }
        else {
            cout << "| Invalid Bill                         |\n";
        }
        cout << "+----------------------+---------+-----+\n";
        cout << "| Item Name            | Price   + Tax |\n";
        cout << "+----------------------+---------+-----+\n";
    }

    void Bill::footer() const {
        cout << "+----------------------+---------+-----+\n";
        if (isValid()) {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalTax() << " |\n";
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
            cout << "|              Total Price: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalPrice() << " |\n";
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << (totalTax() + totalPrice()) << " |\n";
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
        }
        else {
            cout << "| Invalid Bill                         |\n";
        }
        cout << "+--------------------------------------+\n";
    }

    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
    }

    bool Bill::isValid() const {
        if (m_title[0] == '\0' || m_items == nullptr) {
            return false;
        }
        for (int i = 0; i < m_noOfItems; i++) {
            if (!m_items[i].isValid()) {
                return false;
            }
        }
        return true;
    }

    void Bill::init(const char* title, int noOfItems) {
        if (title == nullptr || noOfItems <= 0) {
            setEmpty();
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strncpy(m_title, title, 36);
            m_title[36] = '\0';
            m_items = new Item[noOfItems];
            for (int i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        return false;
    }

    void Bill::display() const {
        Title();
        for (int i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }
}
