#include <iostream>
#include <string>
#include "Nodo.h"
#include "Sistema.h"
#include <queue> // la queue ( queue <"clase"> "nombre"> ) <<<<< este es lista o cola
#include <stack> // el stack ( stack <"clase"> "nombre"> ) <<<<< este es la cosa que parece vaso
// pagina rara para rand
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
Nodo::Nodo()
{
    
}

Nodo::Nodo(int dato)
{
    this->dato = dato;
    this->hijoDer = nullptr;
    this->hijoIzq = nullptr;
}

Nodo::~Nodo()
{
}

int Nodo::getDato()
{
	return this->dato;
}

Nodo* Nodo::getHijoDer()
{
	return this->hijoDer;
}

Nodo* Nodo::getHijoIzq()
{
	return this->hijoIzq;
}

void Nodo::setDato(int dato)
{
	this->dato = dato;
}

void Nodo::setHijoIzq(Nodo* nodoHijoIzq)
{
	this->hijoIzq = nodoHijoIzq;
}

void Nodo::setHijoDer(Nodo* nodoHijoDer)
{
	this->hijoDer = nodoHijoDer;
}

void Nodo::agregar(int dato)
{
    if (this->dato == dato)
    {
        cout << "ERROR El dato " << dato << " ya esta agregado (repetido)" << endl;
        return;
    }

    if (dato < this->dato)// si el dato que intentamos agregar es menor que el dato que tenemos a la izquierda
    {
        if (this->hijoIzq == nullptr)// si es que no tiene hijo izquierdo, lo agregamos
        {
            this->hijoIzq = new Nodo(dato);
            cout << "El dato " << dato << " fue agregado a la izquierda de " << this->dato << endl;
            return;
        }

        else // si es que ya existe un nodocen su izquierda
        {
            this->hijoIzq->agregar(dato); // a ese nodo le intentamos agregar el dato
        }

    }






    if (dato > this->dato)// si el dato que intentamos agregar es mayor que el dato que tenemos a la derecha
    {
        if (this->hijoDer == nullptr)
        {
            this->hijoDer = new Nodo(dato);
            cout << "El dato " << dato << " fue agregado a la derecha de " << this->dato << endl;
            return;
        }

        else
        {
            this->hijoDer->agregar(dato);
        }
    }




}




