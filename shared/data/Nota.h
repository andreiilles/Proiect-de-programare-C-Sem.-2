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
    Nota();
    Nota(int valoare, Data data);
    Nota(const Nota &n);
    int getValoare();
    Data getData();
    void setValoare(int valoare);
    void setData(Data data);
};


#endif //PROIECT_PP_CPP_NOTA_H
