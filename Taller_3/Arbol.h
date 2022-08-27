#pragma once
#include "Nodo.h"
#include "Jugador.h"

class Arbol
{
private:
	Nodo *raiz;
	Nodo *actual;
	int nodoGanador;


public:
	/// <summary>
	/// constructor del arbol, no recive nada como parametro
	/// </summary>
	Arbol();

	
	~Arbol();

	/// <summary> 
	/// funcion que devuelve la raiz del arbol (primer nodo en ser agregado / el primero) , siendo ese un nodo
	/// </summary>
	/// <returns>Nodo raiz(primero)</returns>
	Nodo *getRaiz();

	/// <summary>
	/// funcion que devuele como parametro el nodo actual, siendo este un nodo
	/// </summary>
	/// <returns>nodo actual</returns>
	Nodo *getActual();

	/// <summary>
	/// cambia el nodo actual reciviendo como parametro el nodo actual actualizad
	/// </summary>
	/// <param name="nuevoActual">actiualizado</param>
	void setActual(Nodo nuevoActual);

	/// <summary>
	/// funcion que permite agregar valores (nodos) al arbol reciviendo como parametro el dato que este nodo contendra primero corroborando si es que existe una raix, de no
	/// existir esta definira ese nodo como su nueva raiz, luego llama a la funcion agregar nodo de la clase Nodo para funalizar de agregar el Nodo
	/// </summary>
	/// <param name="dato">dato a agegar</param>
	void agregarDatoAlArbol(int dato);

	/// <summary>
	/// esta funcion hace que el jugador rrecorra el nodo con las reglas indicadas, (ejecuta en si el juego)
	/// </summary>
	/// <param name="jugador">jgador a agregar al arbol</param>
	/// <returns></returns>
	Jugador recorrerArbol(Jugador jugador);

	/// <summary>
	/// esta funcion encuentra todos los Nodos hoja reciviendo la raiz de el arbol para comenzar
	/// guardandolos en el stack detras syo
	/// </summary>
	/// <param name="raiz"></param>
	void buscarNodosHojas(Nodo* raiz);

	/// <summary>
	/// esta funcion  defne cual sera el nodo ganador para que el juego pueda finalizar , lo seleciona de manera aleatoria
	/// </summary>
	void definirNodoGanador();
};

