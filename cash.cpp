//
// Created by crist on 5/20/2020.
//

#include "cash.h"

cash::cash():plata() {}

cash::cash(int x, const char *y, int z):plata(x, y, z) {}

cash::cash(const cash &other):plata(other) {}

cash::~cash() {}

void cash::afisare()
{
    std::cout << "Data platii:" << this->data << "\n";
    std::cout << "Suma achitata: " << this->suma << "\n";
    std::cout<< "ID-ul platii:" << this->id_plata << "\n";
}

std::istream & operator >> (std::istream &in, cash &c)
{
    in >> dynamic_cast<plata&>(c);
    return in;
}
std::ostream & operator << (std::ostream &out, cash &c)
{
    c.afisare();
    return out;
}

cash &cash::operator=(const cash &other)
{
    this->suma = other.suma;
    this->id_plata = other.id_plata;
    strcpy(this->data, other.data);
    return *this;
}
