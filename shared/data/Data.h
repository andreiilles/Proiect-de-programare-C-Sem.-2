//
// Created by mario on 5/28/2023.
//

#ifndef PROIECT_PP_CPP_DATA_H
#define PROIECT_PP_CPP_DATA_H
#include <string>
#include <vector>
#include <iostream>
#include "UsefulFunctions.h"
using namespace std;

class Data {
    int zi, luna, an;

public:
    Data();
    Data(string txt);
    Data(int zi, int luna, int an);
    Data(const Data &d);
};


#endif //PROIECT_PP_CPP_DATA_H
