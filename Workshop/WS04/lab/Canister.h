// Created by Hyeonjun on 2024-06-08.
// Name: Hyeonjun Son
// Email: hson15@myseneca.ca
// Student ID: 123526238

#ifndef SENECA_CANISTER_H
#define SENECA_CANISTER_H
#define PI 3.14159265
#define MIN_HEIGHT 10
#define MIN_DIAMETER 10
#define MAX_HEIGHT 40
#define MAX_DIAMETER 30

#include <iostream>
namespace seneca {
   class Canister {
      char* m_contentName;
      double m_diameter; // in centimeters 
      double m_height;   // in centimeters
      double m_contentVolume;  // in CCs
      bool m_usable;
      void setToDefault();
      void setName(const char* Cstr);
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const;
   public:
      Canister();
      Canister(const char* contentName);
      Canister(double height, double diameter,
         const char* contentName = nullptr);
      ~Canister();
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister&);
      double volume()const;
      std::ostream& display()const;
      double capacity()const;
      void clear();
   };
}

#endif // !SENECA_BOX_H