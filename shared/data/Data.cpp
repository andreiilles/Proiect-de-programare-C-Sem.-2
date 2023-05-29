//
// Created by mario on 5/28/2023.
//

#include "Data.h"




Data::Data(int zi, int luna, int an) {
    this->zi = zi;
    this->luna = luna;
    this->an = an;
}

Data::Data(const Data &d) {
    this->zi = d.zi;
    this->luna = d.luna;
    this->an = d.an;
}

Data::Data() {
    this->zi = 0;
    this->luna = 0;
    this->an = 0;
}

Data::Data(string txt) {
    auto txt_vector = splitString(txt, ".");
    this->zi = stoi(txt_vector[0]);
    this->luna = stoi(txt_vector[1]);
    this->an = stoi(txt_vector[2]);
}
