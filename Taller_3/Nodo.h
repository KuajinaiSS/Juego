#pragma once
#include <queue> // la queue ( queue <"clase"> "nombre"> ) <<<<< este es lista o cola
#include <stack> // el stack ( stack <"clase"> "nombre"> ) <<<<< este es la cosa que parece vaso

class Nodo
{
private:
	Nodo *hijoIzq;
	Nodo* hijoDer;
	int dato;
public:
	Nodo();
	/// <summary>
	/// Constructor de la clase Nodo que recive como parametro un dato
	/// ,por defecto los hijos (izquierdo y derecho) apuntan a nullptr
	/// </summary>
	/// <param name="dato"> el dato debe de ser un valor entero</param>
	Nodo(int dato);

	
	~Nodo();
	/// <summary>
	/// regresa al valor del nodo que sera un entero
	/// </summary>
	/// <returns>int</returns>
	int getDato();

	/// <summary>
	/// regresa el nodo derecho de este nodo
	/// </summary>
	/// <returns>Nodo derecho</returns>
	Nodo* getHijoDer();

	/// <summary>
	/// regresa el nodo derecho de este nodo
	/// </summary>
	/// <returns>Nodo izquierdo</returns>
	Nodo* getHijoIzq();

	/// <summary>
	/// regresa el dato que contiene este nodo;
	/// </summary>
	/// <param name="dato">entero</param>
	void setDato(int dato);

	/// <summary>
	/// cambia el hijo Izquierdo del nodo por el nuemvo hijo izquierdo que recive como variable
	/// </summary>
	/// <param name="nodoHijoIzq"></param>
	void setHijoIzq(Nodo* nodoHijoIzq);

	/// <summary>
	/// cambia el hijo Derecho del nodo por el nuemvo hijo izquierdo que recive como variable
	/// </summary>
	/// <param name="nodoHijoIzq"></param>
	void setHijoDer(Nodo* nodoHijoDer);


	/// <summary>
	/// agrega un dato al arbol creando este solo con el dato ingresado, enlazandolo a su nodo padre o definiendolo como raiz
	/// al igual que detecta si es que el nodo esta repetido no para no agregar este
	/// </summary>
	/// <param name="dato"> con el que se creara el nodo</param>
	void agregar(int dato);


};

