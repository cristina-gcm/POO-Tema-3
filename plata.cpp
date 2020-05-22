//
// Created by crist on 5/15/2020.
//

#include "plata.h"
#include "verif_data.h"

plata::plata()
{
    strcpy(data, "");
    suma = 0;
    //std::cout<<"ctr fara param";
}

plata::plata(int x, const char *y, int z)
{
    strcpy(data, y);
    suma = x;
    id_plata = z;
    //std::cout<<"ctr cu param\n";
}

plata::plata(const plata &other)
{
    strcpy(this->data, other.data);
    this->suma = other. suma;
    this->id_plata = other.id_plata;
    //std::cout << "ctr de copiere\n";
}
plata::~plata()
{
    suma = 0;
    strcpy(data, "");
    std::cout<<"destructor\n";
}

std::istream & operator >> (std::istream &in, plata &p)
{   try {

    std::cout << "Data platii(zz.ll.an): "; in >> p.data;
    if (strlen(p.data) < 8)
        throw verif_data();}
    catch (verif_data e) {
        cout<<e.what();
        in >> p.data;
        while (strlen(p.data) < 8)
            in >> p.data;}

    std::cout << "\n" << "Suma achitata:"; in >> p.suma;
    std::cout << "\n" << "ID-ul platii:"; in>> p.id_plata;
    return in;
}
