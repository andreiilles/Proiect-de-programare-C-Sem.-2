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

bool Data::operator==(const Data &data) {
    if (this->zi==data.zi)
        if(this->luna==data.luna)
            if(this->an==data.an)
                return true;
            else
                return false;
}

ostream &operator<<(ostream output, const Data &data) {
    output << data.zi << "." << data.luna << "." << data.an;
    return output;
}

int Data::getZi() {
    return this->zi;
}

int Data::getLuna()
{
    return this->luna;
}

int Data::getAn() {
    return this->an;
}