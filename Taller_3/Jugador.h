#pragma once
#include <string>
using namespace std;

class Jugador
{
private:
	string nombre;
	int puntaje;
	float tiempo;
	int cantidadNodosNormalesPasados;

public:
	/// <summary>
	/// constructor de la clase Jugador, recive como parametro el nombre del jugador,
	/// luego al jugador se le asignara un puntaje, tiempo y cantidad de nodos normales 
	/// pasados con valor de 0 para mas adelante ser usados
	/// </summary>
	/// <param name="nombre">del jugador</param>
	Jugador(string nombre);

	
	~Jugador();

	/// <summary>
	/// fucnion que retorna el nombre del jugador 
	/// </summary>
	/// <returns>nombre del jugador</returns>
	string getNombre();

	/// <summary>
	/// funcion que retorna el puntaje del jugador
	/// </summary>
	/// <returns>puntaje del jugador</returns>
	int getPuntaje();

	/// <summary>
	/// funcion que retorna el tiempo de juego del jugador
	/// </summary>
	/// <returns>tiempo del jugador</returns>
	double getTiempo();

	/// <summary>
	/// funcion que retorna la cantidad de nodos normales que el jugador a traspasado (no nodo raizes)
	/// </summary>
	/// <returns>nodos normales que a pasado</returns>
	int getCantidadNodosNormalesPasados();

	/// <summary>
	/// esta funcion sirve para cambiarle el nombre al jugador reciviendo como parametro el nuevo nombre que este tendra
	/// </summary>
	/// <param name="nombre">nuevo nombre</param>
	void setNombre(string nombre);

	/// <summary>
	/// fucnion que sirve para cambiar el puntaje que este jugador tiene reciviendo como parametro el uevo puntaje al que devemos cambiar
	/// </summary>
	/// <param name="puntaje">nuevo puntaje</param>
	void setPuntaje(int puntaje);

	/// <summary>
	/// funcion quesirve para cambiar el tiempo en juego del jugador reciviendo como parametro el nuevo tiempo
	/// </summary>
	/// <param name="timepo">tiempo nuevo</param>
	void setTiempo(float timepo);
	
	/// <summary>
	/// fuancion que sirve para camiar los odos normales qe el jugador a cruzado (nodos que no sean raiz) reciviendo como parametro
	/// la neuva cantidad de nodos
	/// </summary>
	/// <param name="nodosPasados">cantodad de nodos nueva</param>
	void setCantidadNodosNormalesPasados(int nodosPasados);



};

