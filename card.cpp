//
// Created by crist on 5/20/2020.
//

#include "card.h"

card::card() : plata(0, "", 0)
{
    nr_card = 0;
    nume_client = "";
    //std::cout<< "ctr card fara param\n";
}

card::card(int nr, int suma, const char *data, int id, std::string nume): plata(suma, data, id) {
    nr_card = nr;
    nume_client = nume;
    //std::cout << "ctr card cu param\n";
}

card::card(const card &other): plata(other)
{
    this->nr_card = other.nr_card;
    this->nume_client = other.nume_client;
    //std::cout << "cpy ctr card \n";
}
card::~card() {}

std::istream & operator >> (std::istream &in, card &c)
{
    in >> dynamic_cast<plata&>(c);
    std::cout << "Introduceti numarul cardului: ";
    in >> c.nr_card;
    std::cout << "Introduceti numele clientului: ";
    in >> c.nume_client;
    return in;
}

void card::afisare() {
    std::cout << "Data platii:" << this->data << "\n";
    std::cout << "Suma achitata: " << this->suma << "\n";
    std::cout << "Nr card: " << this->nr_card << "\n";
    std::cout << "Numele clientului: " << this->nume_client << "\n";
    std::cout<<"\n";
}

std::ostream &operator << (std::ostream &out, card &c)
{
    c.afisare();
    return out;
}

card &card::operator=(const card &other)
{
    strcpy(this->data, other.data);
    this->nume_client = other.nume_client;
    this->suma = other.suma;
    this -> nr_card = other.suma;
    this -> id_plata = other.id_plata;
    return *this;
}