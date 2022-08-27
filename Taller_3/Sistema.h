#pragma once
#include "Nodo.h"
#include "Arbol.h"
#include "Jugador.h"
#include <string> // esto permite usar el cout
#include <iostream> // esto permite usar el cout
#include <queue> // la queue ( queue <"clase"> "nombre"> ) <<<<< este es lista o cola
#include <stack> // el stack ( stack <"clase"> "nombre"> ) <<<<< este es la cosa que parece vaso
using namespace std; // esto permite usar el cout

class Sistema
{
public:
	/// <summary>
	/// constructor de la clase sistema , es la que contiene el sistema en si
	/// </summary>
	Sistema();

	/// <summary>
	/// con esto estoy creando el arbol en e sistema
	/// </summary>
	Arbol* arbol = new Arbol();

	/// <summary>
	/// queque o fila que contiene a los jugadores que juegan en el juego
	/// </summary>
	queue <Jugador> Jugadores;

	/// <summary>
	/// stacko pila de los jugadores pero ordenados de menor a mayor
	/// </summary>
	stack <Jugador> Ordenado;

	/// <summary>
	/// string que contiene el nombre del jugador que mas nodos a recorrido
	/// </summary>
	string recordNodos = "";

	/// <summary>
	/// numero de nodos que recorrio el jugador que obtiene el record de nodos recorridos
	/// </summary>
	int recordNodosNumero = 0;

	/// <summary>
	/// string que contiene el nombre del jugador que se paso el juego en menos tiempo 
	/// </summary>
	string recordTiempo = "";

	/// <summary>
	/// funcion que contiene el tiempo que demoro el jugador que recorrio el juego en el menor tiempo
	/// </summary>
	float recordTiempoNumero = 999;

	/// <summary>
	/// funcion que sirve para corroborar si lo que entra 
	/// </summary>
	/// <param name="numero"></param>
	/// <returns></returns>
	bool validarInt(string numero);


	/// <summary>
	/// funcion que se encarga de iniciar el sistema , esta ejecuta la funcion de menu y la de crear arbol
	/// </summary>
	void iniciarSistema();

	/// <summary>
	/// funcio contenedora del menu en si
	/// </summary>
	void menu();

	/// <summary>
	/// funcion que se encarga de crear el arbon en el que se van a almacenar los nodos
	/// </summary>
	void crearArbol();

	/// <summary>
	/// sub funcion del menu que se encarga de iniciar el juego , ejecuta la fucnion del de recorrer el arbol del arbol
	/// </summary>
	void jugar();

	/// <summary>
	/// sub funcion del menu que se encarga de mostrar el menu de las estaisticas (contiene la funciond e mejores jugadores, peores jugadores, jugador que mas nodos viito
	/// y el jugadpr record )
	/// </summary>
	void estadisticas();

	/// <summary>
	/// sub fucnion de la funcion de estadisticas que contienen a los mejores jugadores
	/// </summary>
	void mejoresJugadores();

	/// <summary>
	/// sub fucnion de la funcion de estadistica que depliega a los peores jugadores
	/// </summary>
	void peoresJugadores();

	/// <summary>
	/// sub funcion de la funcion de estadistica que depliega al jugador que mas nodos visito
	/// </summary>
	void jugadorNodosVisito();

	/// <summary>
	/// sub funcion de la funcion de estadistica que despliega al jugadr que demoro mentos tiempo en terminar el juego
	/// </summary>
	void jugadorRecord();

	/// <summary>
	/// fucnion que sirve para ordenar la queque de jugadores segun el puntaje obtenido
	/// </summary>
	void ordenar();


	
};

