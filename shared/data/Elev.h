#ifndef PROIECT_PP_CPP_ELEV_H
#define PROIECT_PP_CPP_ELEV_H
#include <string>
#include <vector>
#include <iostream>
#include "Materie.h"
#include "Absenta.h"
using namespace std;

class Elev {
    static int numarElevi;
    int numarMatricol;
    string prenume;
    string nume;
    vector<Materie> materii;
    vector<Absenta> absente;

private:
    void init(string prenume, string nume, vector<Materie> materii, vector<Absenta> absente);

public:
    Elev(string prenume, string nume);
    Elev(string prenume, string nume, vector<Materie> materii, vector<Absenta> absente);
    Elev(int numarMatricol, string prenume, string nume, vector<Materie> materii, vector<Absenta> absente);
    Elev(const Elev &e);
    int getNumarMatricol();
    string getPrenume();
    string getNume();
    static void setNumarElevi(int n);
    static int getNumarElevi();
    friend ostream& operator<<(ostream &out, const Elev &e);

};
ostream& operator<<(ostream &out, const Elev &e);

#endif //PROIECT_PP_CPP_ELEV_H
