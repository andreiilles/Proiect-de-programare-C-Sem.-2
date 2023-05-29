//
// Created by mario on 5/28/2023.
//

#ifndef PROIECT_PP_CPP_NOTA_H
#define PROIECT_PP_CPP_NOTA_H
#include <string>
#include <vector>
#include <iostream>
#include "Data.h"
using namespace std;

class Nota {
    int valoare;
    Data data;

public:
    Nota(int valoare, Data data);
    Nota(const Nota &n);
};


#endif //PROIECT_PP_CPP_NOTA_H
