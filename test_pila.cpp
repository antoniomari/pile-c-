//
// Created by 39347 on 28/10/2021.
//

#include <iostream>
#include "pila_rappr_puntatori.cpp"
#include "pila_rappr_vettore.cpp"
#define A() cout << "dioc";

using namespace std;

int main(){

    // RAPPRESENTAZIONE VETTORE
    Pila_Vett<double> p;


    p.in_pila(1.5);
    p.stampa_pila();

    p.in_pila(3.5);
    p.stampa_pila();

    p.in_pila(4.5);
    p.stampa_pila();

    p.in_pila(2.5);
    p.stampa_pila();

    p.fuori_pila();
    p.stampa_pila();

    p.fuori_pila();
    p.stampa_pila();

    p.in_pila(10);
    p.stampa_pila();

    p.fuori_pila();
    p.stampa_pila();

    p.fuori_pila();
    p.stampa_pila();

    p.fuori_pila();
    p.stampa_pila();


    // RAPPRESENTAZIONE PUNTATORI
    Pila_Punt<double> p1;


    p1.in_pila(1.5);
    p1.stampa_pila();

    p1.in_pila(3.5);
    p1.stampa_pila();

    p1.in_pila(4.5);
    p1.stampa_pila();

    p1.in_pila(2.5);
    p1.stampa_pila();

    p1.fuori_pila();
    p1.stampa_pila();

    p1.fuori_pila();
    p1.stampa_pila();

    p1.in_pila(10);
    auto p2(p1);
    p1.stampa_pila();

    p1.fuori_pila();
    p1.stampa_pila();

    p1.fuori_pila();
    p1.stampa_pila();

    p1.fuori_pila();
    p1.stampa_pila();

    p2.stampa_pila();

    return 0;
}