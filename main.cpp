#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>

using namespace std;

struct DaneDoSformatowania {
    int id;
    string imie, nazwisko, email, adres, nrTelefonu;
};

int funkcjaWczytujaca(string nazwa, vector<DaneDoSformatowania>&tablicaDanych, int licznik){
        string linia;
    int nrLinii = 1;

    fstream plik;
    plik.open(nazwa.c_str(), ios::in);

    if(plik.good() == false) {
        cout << "Brak pliku tekstowego.";
        Sleep(1500);
        exit(0);
    }
    DaneDoSformatowania strukturaDanych;

    while(getline(plik,linia)) {
        switch(nrLinii) {
        case 1:
            strukturaDanych.id = atoi(linia.c_str());
            break;
        case 2:
            strukturaDanych.imie = linia;
            break;
        case 3:
            strukturaDanych.nazwisko = linia;
            break;
        case 4:
            strukturaDanych.adres = linia;
            break;
        case 5:
            strukturaDanych.email = linia;
            break;
        case 6:
            strukturaDanych.nrTelefonu = linia;
            break;
        }
        if(nrLinii == 6) {
            licznik++;
            nrLinii = 0;
            tablicaDanych.push_back(strukturaDanych);
        }
        nrLinii++;
    }
    plik.close();
    return licznik;
}

void funkcjaZapisujaca(DaneDoSformatowania strukturaDanych, string nazwa){
    fstream plik2;
    plik2.open(nazwa.c_str(), ios::out | ios::app);

    plik2 << strukturaDanych.id << "|";
    plik2 << strukturaDanych.imie << "|";
    plik2 << strukturaDanych.nazwisko << "|";
    plik2 << strukturaDanych.adres << "|";
    plik2 << strukturaDanych.email << "|";
    plik2 << strukturaDanych.nrTelefonu << "|" << endl;

    plik2.close();
}

int main() {
    vector<DaneDoSformatowania>tablicaDanychPrzyjaciol;
    int licznik = 0;
    string nazwaPliku;
    string nazwaNowegoPliku;

    cout << "Podaj nazwe pliku zrodlowego: ";
    getline(cin, nazwaPliku);
    nazwaNowegoPliku = nazwaPliku;
    nazwaPliku = nazwaPliku + ".txt";

    licznik = funkcjaWczytujaca(nazwaPliku,tablicaDanychPrzyjaciol, licznik);

    nazwaNowegoPliku = nazwaNowegoPliku + " (nowy format).txt";

    fstream plik2;
    plik2.open(nazwaNowegoPliku.c_str(), ios::out);
    plik2 << "";
    plik2.close();

    for(int i = 0; i < licznik; i++)
        funkcjaZapisujaca(tablicaDanychPrzyjaciol[i], nazwaNowegoPliku);

    cout << "Dane zostaly poprawnie sformatowane.";
    Sleep(2000);
    return 0;
}
