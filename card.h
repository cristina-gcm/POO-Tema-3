//
// Created by crist on 5/20/2020.
//

#ifndef TEMA3_CARD_H
#define TEMA3_CARD_H
#include "plata.h"
#include <string>

class card: public plata {
    int nr_card;
    std::string nume_client;
public:
    card();
    card(int nr, int suma, const char *data, int id, std::string nume);
    card( const card &other);
    ~card();
    void afisare();

    std::string get_nume_client() const {return nume_client;}

    friend std::istream & operator >> (std::istream &in, card &c);
    friend std::ostream &operator << (std::ostream &out, card &c);
    card& operator =(const card &other);
};


#endif //TEMA3_CARD_H
