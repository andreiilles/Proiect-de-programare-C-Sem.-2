#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include "../shared/data/Elev.h"
#include "../shared/data/UsefulFunctions.h"
using namespace std;

vector <Elev> elevi;

void readElevi() {
    ifstream f("../shared/files/elevi.txt");
    int numarElevi;
    f >> numarElevi;
    Elev::setNumarElevi(numarElevi);

    for(int i=1;i<=numarElevi;i++) {
        int nrMatricol;
        string prenume, nume;
        f >> nrMatricol;
        f >> prenume >> nume;
        elevi.push_back(Elev(nrMatricol, prenume, nume, vector<Materie>(), vector<Absenta>()));
    }

    f.close();
}

void writeElevi() {
    ofstream w("../shared/files/elevi.txt");
    w << Elev::getNumarElevi() << endl;
    for(auto it = elevi.begin(); it < elevi.end(); it++) {
        w << it->getNumarMatricol() << endl;
        w << it->getPrenume() << " " << it->getNume() << endl;
    }
    w.close();
}

void readAbsente()
{
    ifstream f("../shared/files/absente.txt");
    while(!f.eof())
    {
        int tempMatricol;
        string tempString;
        f >> tempMatricol >> tempString;
        vector<string> params= splitString(tempString,"/");
        for(auto it = elevi.begin();it!=elevi.end();it++)
        {
            if (it->getNumarMatricol()==tempMatricol)
            {
                Absenta tempAbsenta(params[0]);
                it->adaugareAbsenta(tempAbsenta);
                break;
            }
        }
    }
    f.close();
}

int main(int argc, char* argv[])
{
    readElevi();
    readAbsente();
    return 0;
}