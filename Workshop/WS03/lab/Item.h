/*
name: Hyeonjun Son
email: hson15@myseneca.ca
Student id: 123526238
*/
#ifndef SENECA_ITEM_H_
#define SENECA_ITEM_H_

namespace seneca {
    class Item {
        char m_itemName[21];
        double m_price;
        bool m_taxed;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, double price, bool taxed);
        void display() const;
        bool isValid() const;
        double price() const;
        double tax() const;
    };
}

#endif // SENECA_ITEM_H_

