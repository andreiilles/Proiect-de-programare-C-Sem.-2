
/*
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

void writeAbsente()
{
    ofstream w("../shared/files/absente.txt");
    bool first = false;
    for (int i =0;i<elevi.size();i++)
    {
        if (!elevi[i].getAbsente().empty())
        {

            vector <Absenta> absente = elevi[i].getAbsente();
            for (int j = 0;j<absente.size();j++)
            {
                if(first == false) {
                    w << elevi[i].getNumarMatricol();
                    first = true;
                }
                else
                    w << endl << elevi[i].getNumarMatricol();

                w << endl << absente[j].getData().getZi() << "." << absente[j].getData().getLuna() << "." << absente[j].getData().getAn() <<
                  "/" << absente[j].getMotivata();
            }
        }
    }
    w.close();
}

void adaugaAbsenta(int numarMatricol, Absenta absenta)
{
    for (auto iter = elevi.begin(); iter != elevi.end(); iter++)
    {
        if (iter->getNumarMatricol()==numarMatricol)
            iter->adaugareAbsenta(absenta);
    }
}

void stergeAbsenta(int numarMatricol, Absenta absenta)
{
    for (auto iter = elevi.begin(); iter!=elevi.end();iter++)
    {
        if (iter->getNumarMatricol()==numarMatricol)
            iter->stergereAbsenta(absenta);
    }
}

int main(int argc, char* argv[])
{
    readElevi();
    readAbsente();
    if (strcmp("adauga_absenta",argv[1])==0)
    {
        adaugaAbsenta(stoi(argv[2]),Absenta(Data(argv[3])));
    }
    if(strcmp("sterge_absenta", argv[1])==0) {
        stergeAbsenta(stoi(argv[2]),Absenta(Data(argv[3])));
    }
    writeAbsente();
    return 0;
}

*/
