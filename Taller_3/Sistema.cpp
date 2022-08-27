#include "Sistema.h"
#include <string> // esto permite usar el cout
#include <iostream> // esto permite usar el cout
using namespace std; // esto permite usar el cout
#include <chrono>
#include <thread>
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

Sistema::Sistema()
{
	
}

void Sistema::iniciarSistema()
{

	crearArbol();
	menu();
}





// aca cargar los datos del arbol mencionado en el main
void Sistema::crearArbol()
{
	int datos[71] = { 111,70,33,11,9,4,1,7,10,27,25,20,19,24,29,52,44,56,54,61,65,67,66,69,85,74,71,83,77,76,79,94,91,99,212,188,150,118,115,113,117,122,148,141,144,147,163,177,202,193,190,199,210,207,266,231,224,219,228,256,250,248,243,249,259,257,262,279,271,320,333 };

	for (int i = 0; i < 71; i++)
	{
		this->arbol->agregarDatoAlArbol(datos[i]);
	}

}

void Sistema::menu()
{
	string opcionn;
	int opcion;
	do {
		do {
		cout << "\n============== Diego Aguilera's GAME ==============\n" <<
			"\n Escoge una opcion que desea realizar:\n" <<
			"\n [1] Jugar" <<
			"\n [2] Estadisticas" <<
			"\n [0] Salir" << endl;
		cin >> opcionn;
		} while (validarInt(opcionn));
		opcion = stoi(opcionn);


		switch (opcion) {

		case 1:
			cout << "\n====================== Jugar ======================\n";
			jugar();
			break;
			
		case 2:
			estadisticas();
			break;

		default:
			break;
		}
	} while (opcion != 0);
	cout << "\nLa Familia es lo primero";
	sleep_for(seconds(1));
	cout << ".";
	sleep_for(seconds(1));
	cout << ".";
	sleep_for(seconds(1));
	cout << ".";

	cout << "\nEN ESPECIAL MI MAMITA QUE ME PREPARA CAZUELA MAMITA TE QUIERO MUCHO\n" << endl;
	sleep_for(seconds(1));
	cout << "Se despide ";
	cout << "B";
	sleep_for(seconds(1));
	cout << "T";
	sleep_for(seconds(1));
	cout << "S\n";
	sleep_for(seconds(2));
}

void Sistema::jugar()
{
	string nombre;
	cout << "Ingrese el nombre del jugador: ";
	cin >> nombre;

	for (int i = 0; i < Jugadores.size(); i++)
	{
		if (Jugadores.front().getNombre() == nombre) {
			cout << "El nombre ya existe deve de ingresar uno diferente " << endl;
			return;
		}

		Jugadores.push(Jugadores.front());
		Jugadores.pop();
	}

	Jugador *jugador = new Jugador(nombre);

	*jugador = arbol->recorrerArbol(*jugador);
	Jugadores.push(*jugador);

	if (jugador->getCantidadNodosNormalesPasados() > recordNodosNumero) {
		recordNodos = jugador->getNombre();
		recordNodosNumero = jugador->getCantidadNodosNormalesPasados();
		cout << "\n'" << recordNodos << "' rompio el record de CANTIDAD DE NODOS VISITADOS con un total de " << recordNodosNumero << " nodos!";
	}
	if (jugador->getTiempo() < recordTiempoNumero) {
		recordTiempo = jugador->getNombre();
		recordTiempoNumero = jugador->getTiempo();
	}
	jugador->~Jugador();

}

void Sistema::estadisticas()
{
	string opcionn;
	int opcion;
	do {
		do {
			cout << "\n================== Estadisticas ===================\n" <<
				"\n Escoge una opcion que desea realizar:\n" <<
				"\n [1] Mejores Jugadores" <<
				"\n [2] Peores Jugadores" <<
				"\n [3] Jugador que visito mas nodos normales" <<
				"\n [4] Jugador RECORD" <<
				"\n [0] Salir" << endl;
			cin >> opcionn;
		} while (validarInt(opcionn));
		opcion = stoi(opcionn);


		switch (opcion) {

		case 1:
			cout << "\n================ Mejores Jugadores ================\n";
			ordenar();
			mejoresJugadores();
			break;

		case 2:
			cout << "\n================ Peores Jugadores =================\n";
			ordenar();
			peoresJugadores();
			break;

		case 3:
			cout << "\n====== Jugador que visito mas nodos normales ======\n";
			jugadorNodosVisito();
			break;

		case 4:
			cout << "\n================== Jugador RECORD =================\n";
			jugadorRecord();
			break;

		default:
			break;
		}
	} while (opcion != 0);

}

void Sistema::mejoresJugadores()
{
	int i = 1;
	cout << "\nTOP MEJORES PUNTAJES: \n" << endl;
	while (!Ordenado.empty()) {
		
		cout << "[" << i << "] " << Ordenado.top().getNombre() << " " << Ordenado.top().getPuntaje() << "pts " << Ordenado.top().getTiempo() << " segundos\n";
		Ordenado.pop();
		i++;
	}
}

void Sistema::peoresJugadores()
{
	stack<Jugador> aux;
	int i = 1;

	while (!Ordenado.empty()) {
		aux.push(Ordenado.top());
		Ordenado.pop();
	}

	cout << "\nTOP MEJORES PEORES PUNTAJES (si... igual meresen algo supongo): \n" << endl;

	while (!aux.empty()) {
		cout << "[" << i << "] " << aux.top().getNombre() << " " << aux.top().getPuntaje() << "pts " << aux.top().getTiempo() << " segundos\n";
		aux.pop();
		i++;
	}

}

void Sistema::jugadorNodosVisito()
{
	cout << "\n El jugador que mas nodos visito es '"<< recordNodos << "' con un total de " << recordNodosNumero << " nodos recorridos\n";
}

void Sistema::jugadorRecord()
{
	cout << "\n El jugador mas precoz (en terminar el juego) es '" << recordTiempo << "' en un total de " << recordTiempoNumero << " segundos\n";
}

void Sistema::ordenar()
{
	
	stack<Jugador> datosDesordenados;
	for (int i = 0; i < Jugadores.size(); i++)
	{
		datosDesordenados.push(Jugadores.front());
		Jugadores.push(Jugadores.front());
		Jugadores.pop();
	}

	while (!datosDesordenados.empty()) {// mientras no este vacio

		Jugador temporal = datosDesordenados.top(); // maximo/minimo Temporal

		datosDesordenados.pop();

		while (!Ordenado.empty() && Ordenado.top().getPuntaje() > temporal.getPuntaje()) {
			datosDesordenados.push(Ordenado.top());
			Ordenado.pop();
		}

		Ordenado.push(temporal);
	}

}



bool Sistema::validarInt(string numero)
{
	try {
		int opcionnnnnnn = stoi(numero);
		return false;
	}
	catch (...) {
		cout << "xXxXxXxXxXxXxXxXxXxX El valor ingresado no es un numero XxXxXxXxXxXxXxXxXxXxX \n";
		
	}
	return true;
}


