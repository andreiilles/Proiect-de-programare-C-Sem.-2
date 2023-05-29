//
// Created by mario on 5/28/2023.
//

#ifndef PROIECT_PP_CPP_ABSENTA_H
#define PROIECT_PP_CPP_ABSENTA_H
#include <string>
#include <vector>
#include <iostream>
#include "Data.h"
using namespace std;

class Absenta {
    Data data;
    bool motivata;

public:
    Absenta(Data data);
    Absenta(const Absenta &a);
};


#endif //PROIECT_PP_CPP_ABSENTA_H
