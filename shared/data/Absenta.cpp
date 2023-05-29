//
// Created by mario on 5/28/2023.
//

#include "Absenta.h"

Absenta::Absenta(Data data) {
    this->data = data;
    this->motivata = false;
}

Absenta::Absenta(const Absenta &a) {
    this->data = a.data;
    this->motivata = a.motivata;
}
