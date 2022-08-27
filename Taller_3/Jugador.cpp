#include "Jugador.h"

Jugador::Jugador(string nombre)
{
    this->nombre = nombre;
    this->puntaje = 0;
    this->tiempo = 0;
    this->cantidadNodosNormalesPasados = 0;

}

Jugador::~Jugador()
{
}

string Jugador::getNombre()
{
    return this->nombre;
}

int Jugador::getPuntaje()
{
    return this->puntaje;
}

double Jugador::getTiempo()
{
    return this->tiempo;
}

int Jugador::getCantidadNodosNormalesPasados()
{
    return this->cantidadNodosNormalesPasados;
}




void Jugador::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Jugador::setPuntaje(int puntaje)
{
    this->puntaje = puntaje;
}

void Jugador::setTiempo(float timepo)
{
    this->tiempo = timepo;
}

void Jugador::setCantidadNodosNormalesPasados(int nodosPasados)
{
    this->cantidadNodosNormalesPasados = nodosPasados;
}


