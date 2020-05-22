//
// Created by crist on 5/15/2020.
//

#ifndef TEMA3_PLATA_H
#define TEMA3_PLATA_H

#include <iostream>
#include <cstring>

class plata {
protected:
    char data[256];
    int suma;
    int id_plata;
public:
    plata();
    plata(int x, const char *y, int z);
    plata(const plata &other);
    ~plata();

    virtual void afisare() = 0;

    friend std::istream & operator >> (std::istream &in, plata &p);

    int get_id() const { return id_plata;}
};


#endif //TEMA3_PLATA_H
