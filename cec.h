//
// Created by crist on 5/20/2020.
//

#ifndef TEMA3_CEC_H
#define TEMA3_CEC_H

#include "plata.h"

class cec: public plata {
    char nume[256];
public:
    cec();
    cec(int suma, const char* data, int id, const char* nume);
    cec(const cec &other);
    ~cec();

    void afisare();

    friend std::istream & operator >> (std::istream &in, cec &c);
    friend std::ostream & operator << (std::ostream &out, cec &c);
    cec& operator =(const cec &other);

};


#endif //TEMA3_CEC_H
