//
// Created by crist on 5/20/2020.
//

#include "cec.h"

cec::cec():plata(0, "", 0)
{
    strcpy(nume, "");
}

cec::cec(int suma, const char* data, int id, const char* _nume):plata(suma, data, id)
{
    strcpy(nume, _nume);
}

cec::cec(const cec &other):plata(other)
{
    strcpy(this->nume, other.nume);
}

cec::~cec(){}

std::istream & operator >> (std::istream &in, cec &c)
{
    in >> dynamic_cast<plata&>(c);
    std::cout << "Introduceti numele clientului: ";
    in >> c.nume;
    return in;
}

void cec::afisare() {
    std::cout << "ID plata: " << this->id_plata << "\n";
    std::cout << "Data platii:" << this->data << "\n";
    std::cout << "Suma achitata: " << this->suma << "\n";
    std::cout << "Nume: " << this->nume << "\n";

    std::cout<<"\n";
}

std::ostream & operator << (std::ostream &out, cec&c)
{
    c.afisare();
    return out;
}

cec &cec::operator=(const cec &other)
{
    strcpy(this->data, other.data);
    this->suma = other.suma;
    strcpy(this->nume, other.nume);
    this->id_plata = other.id_plata;
    return *this;
}