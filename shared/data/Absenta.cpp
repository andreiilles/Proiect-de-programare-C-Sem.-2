#include "Absenta.h"

Absenta::Absenta() {
    this->data.setZi(1);
    this->data.setLuna(1);
    this->data.setAn(2023);
}


Absenta::Absenta(Data data) {
    this->data = data;
    this->motivata = false;
}

Absenta::Absenta(const Absenta &a) {
    this->data = a.data;
    this->motivata = a.motivata;
}

Data Absenta::getData() {
    return this->data;
}

bool Absenta::getMotivata() {
    return this->motivata;
}

void Absenta::setData(Data data) {
    this->data = data;
}

void Absenta::setMotivata(bool motivata)
{
    this->motivata = motivata;
}