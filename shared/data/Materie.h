#ifndef PROIECT_PP_CPP_MATERIE_H
#define PROIECT_PP_CPP_MATERIE_H
#include <string>
#include <vector>
#include <iostream>
#include "Nota.h"
#include "Absenta.h"
using namespace std;

class Materie {
    string nume;
    vector<Nota> note;
    vector<Absenta> absente;
    int teza;

private:
    void init(string nume, vector<Nota> note, vector<Absenta> absente, int teza);

public:
    Materie();
    Materie(string nume);
    Materie(string nume, vector<Nota> note, vector<Absenta> absente);
    Materie(string nume, vector<Nota> note, vector<Absenta> absente, int teza);
    Materie(const Materie &m);
    string getNume();
    vector<Nota> getNote();
    vector<Absenta> getAbsente();
    int getTeza();
    void setNume(string nume);
    void setNote(vector<Nota> note);
    void setAbsente(vector<Absenta> absente);
    void setTeza(int teza);

};


#endif //PROIECT_PP_CPP_MATERIE_H
