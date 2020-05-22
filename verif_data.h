//
// Created by crist on 5/20/2020.
//

#ifndef TEMA3_VERIF_DATA_H
#define TEMA3_VERIF_DATA_H
#include <iostream>
using namespace std;

class verif_data:public exception {
public: const char* what() {
        return "Data trebuie nu are formatul corespunzator!\n";
}
};


#endif //TEMA3_VERIF_DATA_H
