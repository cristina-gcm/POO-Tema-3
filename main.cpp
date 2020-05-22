#include <iostream>
#include "plata.h"
#include "card.h"
#include "cash.h"
#include "cec.h"
#include <unordered_map>
#include <vector>
using namespace std;

template <class Ttype> class Gestiune {
    static int nr_plati;
    unordered_map<int, Ttype> plati;
public:
    Gestiune() ;
    ~Gestiune();
    Gestiune<Ttype>& operator+=(const Ttype& ob);
};

template <class Ttype> int Gestiune<Ttype>::nr_plati = 0;

template <class Ttype>
Gestiune<Ttype>::Gestiune() {}

template <class Ttype>
Gestiune <Ttype>::
~Gestiune() {}

template <class Ttype>
Gestiune<Ttype>& Gestiune<Ttype>::operator+=(const Ttype& ob) {
    //cout << nr_plati;
    plati.insert(make_pair(ob.get_id(), ob));
    nr_plati++;
    //cout << nr_plati;
    //cout << "l am pus";
    return *this;
}

template <> class Gestiune <card> {
      static int nr_clienti;
      static int nr_plati;
      vector <string> clienti;
      unordered_map <int, card> plati;
    public:
        Gestiune();
        ~Gestiune();
        Gestiune<card>& operator+=(const card& ob);

    };

int Gestiune<card>::nr_clienti = 0;
int Gestiune<card>::nr_plati = 0;

Gestiune<card>::Gestiune() {}
Gestiune<card>::~Gestiune() {}

Gestiune<card> & Gestiune<card>::operator+=(const card &ob) {
    nr_plati ++;
    bool ok = 0;
    plati.insert(make_pair(ob.get_id(), ob));
    for (int i=0; i < clienti.size() && ok ==0; i++)
        if (clienti[i] == ob.get_nume_client())
            ok = 1;
    if (ok==0)
        {
        clienti.push_back(ob.get_nume_client());
        nr_clienti ++;
        }
    return *this;
}

void afisare_meniu()
{
    cout<<"SELECTATI TIPUL DE PLATA \n";
    cout<<"1. Plata cash.\n";
    cout<<"2. Plata cu cardul. \n";
    cout<<"3. Plata prin cec. \n";
    cout<<"APASATI 0 PENTRU INCHEIERE\n";
}
int main() {
    /*plata x;
    plata y(100, "12dec2019");
    plata z(y);
    cin >> x;
    cout<<"\n" << x;
    card c1;
    card c2(100, 54, "15dec2000");
    card c3(c2);
    c2.afisare();
    cin >> c1;
    cout << c1;
    c2 = c1;
    cout << c1;

    cash s1;
    cash s2(100, "25.02");
    cash s3(s2);
    cin >> s1;
    cout << s1;
    s2 = s1;
    cout << s2;*/

    /*cec c1;
    cec c2(100, "15.02", 250, "Ionel");
    cec c3(c2);
    c2.afisare();
    cin >> c1;
    cout << c1;
    c2 = c1;
    cout << c1;
    card a(254, 200, "21.03.2000", 111, "Miau");
    cout << a.get_nume_client();*/


    Gestiune <cash> A;
    Gestiune <card> B;
    Gestiune <cec> C;

    int optiune;

    afisare_meniu();

    cin >> optiune;

    while (optiune!=0)
    {if (optiune == 1)
        {
            cash ob1;
            cin >> ob1;
            A+= ob1;
        }

        else if (optiune == 2)
        {
            card ob2;
            cin >> ob2;
            B+=ob2;
        }

        else if (optiune == 3)
        {
            cec ob3;
            cin >> ob3;
            C+=ob3;
        }
     cout << "Inserati urmatoarea optiune: ";
     cin >> optiune;}

}
