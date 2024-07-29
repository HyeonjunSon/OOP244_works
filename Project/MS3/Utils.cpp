//
// Created by Hyeonjun Son on 2024-07-17.
// Name: Hyeonjun Son
// Email: hson15@myseneca.ca
// Student ID: 123526238

//

#include "Utils.h"

using namespace std;

namespace seneca {
    int getIntMM(int min, int max) {
        int input = -1;
        do {
            cin >> input;
            if (cin.fail() || input < min || input > max) {
                cout << "Invalid Selection, try again: ";
                input = -1;
            }

            cin.clear();
        
            char ch = 'x';
            while (ch != '\n') {
                ch = cin.get();
            }
        } while (cin.fail() || input < min || input > max);

        return input;
    }
}