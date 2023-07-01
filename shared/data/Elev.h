#ifndef PROIECT_PP_CPP_ELEV_H
#define PROIECT_PP_CPP_ELEV_H
#include <string>
#include <vector>
#include <iostream>
#include "Materie.h"
#include "Absenta.h"
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

class Elev {
    static int numarElevi;
    int numarMatricol;
    string prenume;
    string nume;
    vector<Materie> materii;
    vector<Absenta> absente;

    friend class Materie;
    friend class Nota;
    friend class Absenta;

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
    void adaugareAbsenta(Absenta absenta);
    void getAbsente();
    friend std::string serializareElevi(const std::vector<Elev>& elevi);
    friend std::vector<Elev> deserializareElevi(const std::string& json);

};
ostream& operator<<(ostream &out, const Elev &e);
std::string serializareElevi(const std::vector<Elev>& elevi);
std::vector<Elev> deserializareElevi(const std::string& json);

#endif //PROIECT_PP_CPP_ELEV_H
