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
    int getZi();
    int getLuna();
    int getAn();
    void setZi(int zi);
    void setLuna(int luna);
    void setAn(int an);
};


#endif //PROIECT_PP_CPP_DATA_H
