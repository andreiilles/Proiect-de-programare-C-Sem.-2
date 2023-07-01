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
    bool operator == (const Data& data);
    friend ostream& operator<<(ostream output, const Data& data);
    int getZi();
    int getLuna();
    int getAn();
};


#endif //PROIECT_PP_CPP_DATA_H