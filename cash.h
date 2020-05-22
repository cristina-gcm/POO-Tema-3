//
// Created by crist on 5/20/2020.
//

#ifndef TEMA3_CASH_H
#define TEMA3_CASH_H

#include <iostream>
#include <cstring>
#include "plata.h"

class cash: public plata {
public:
    cash();
    cash(int x, const char *y, int z);
    cash(const cash &other);
    ~cash();

    void afisare();

    friend std::istream & operator >> (std::istream &in, cash &c);
    friend std::ostream & operator << (std::ostream &out, cash &c);
    cash& operator =(const cash &other);
};


#endif //TEMA3_CASH_H
