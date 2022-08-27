#include "Arbol.h"
#include "Arbol.h"
#include <string> // esto permite usar el cout
#include <iostream> // esto permite usar el cout

#include <ctime> // calcular tiempo de ejecucion


// para pausar el sistema
#include <chrono>
#include <thread>
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

using namespace std; // esto permite usar el cout

// pagina rara para rand
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
queue<int> NodosGanadores;

Arbol::Arbol()
{
    this->raiz = nullptr;
    this->actual = nullptr;
}

Arbol::~Arbol()
{
}

Nodo* Arbol::getRaiz()
{
    return this->raiz;
}

Nodo* Arbol::getActual()
{
    return this->actual;
}

void Arbol::setActual(Nodo nuevoActual)
{
    this->actual = &nuevoActual; // preguntar si es que esto en realidad funciona
}

void Arbol::agregarDatoAlArbol(int dato)
{
    if (this->raiz == nullptr) // si es que aun no tenemos una raiz
    {

        this->raiz = new Nodo(dato);
        this->actual = this->raiz;

        cout << "El dato " << dato << " fue asignado como raiz" << endl;
    }
    else {
        this->raiz->agregar(dato);
    }
}

Jugador Arbol::recorrerArbol(Jugador jugador)
{
    unsigned t0, t1; // calcular tiempo ejecucion
    
    buscarNodosHojas(this->raiz);
    int puntaje = 0;
    int nodosPasados = 0;
    Nodo* aux = this->actual;
    srand(time(NULL));

    cout << "Bienvenido " << jugador.getNombre() << endl;
    sleep_for(seconds(1));
    cout << "El juego consiste en que te puedes mover a la derecha o a la izquierda" <<
           "\nhasta llegar al nodo ganador donde terminara el juego"<< endl;
    sleep_for(seconds(4));
    cout << "Si el numero del nodo es PAR tu puntaje se MULTIPLICA POR 2" << endl;
    sleep_for(seconds(3));
    cout << "Pero si el numero del nodo IMPAR tu PUNTAJE SE DIVIDIRA EN 2" << endl;
    sleep_for(seconds(3));
    definirNodoGanador();
    cout << "El nodo ganador en esta partida sera " << nodoGanador << " suerte" << endl;
    sleep_for(seconds(3));


    t0 = clock();

    while (true) { 
        cout << "\n///////////////////////////////////////////////////" << endl;
        if (aux->getDato() % 2 == 0) {// es par
            cout << jugador.getNombre() << " Estas en " << aux->getDato()
                << "\nEl puntaje aumento en " << aux->getDato() <<
                "\nEL PUNTAJE SE A DUPLICADO DEBIDO A QUE ES PAR :] " << endl;
            puntaje = puntaje + aux->getDato();
            puntaje = puntaje * 2;
            nodosPasados = nodosPasados + 1;
            

        }
        else { // es impar
            cout << jugador.getNombre() << " Estas en " << aux->getDato()
                << "\nEl puntaje aumento en " << aux->getDato() <<
                "\nEL PUNTAJE SE A DIVIDIDO A LA MITAD DEBIDO A QUE ES IMPAR :[ " << endl;
            puntaje = puntaje + aux->getDato();
            puntaje = puntaje / 2;
            nodosPasados = nodosPasados + 1;
        }
        cout << "Puntaje actual " << puntaje << endl;





        if (aux->getDato() == nodoGanador) { 
            cout << "\n///////////////////////////////////////////////////" << endl;
            cout << "HAZ  FINALIZADO EL RECORRIDO FELICITACIONES\n\nESTADISTICOS:\n" << endl
                << "Puntaje total de: " << puntaje << endl;
            t1 = clock();

            float time = (float(t1 - t0) / CLOCKS_PER_SEC);
            cout << "Tiempo de ejecucion: " << time << " segundos" << endl;
            cout << "Cantidad de nodos visitados: " << nodosPasados << endl;


            jugador.setPuntaje(puntaje);
            jugador.setTiempo(time);
            jugador.setCantidadNodosNormalesPasados(nodosPasados);
            return jugador; // no hay mas nodos hojas
        }

        if (aux->getHijoDer() == nullptr && aux->getHijoIzq() == nullptr) {// si no hay mas caminos
            cout << "te moviste a la RAIZ ya que no es el nodo ganador\n";
            aux = this->raiz;
        }
        else if (aux->getHijoDer() != nullptr && aux->getHijoIzq() == nullptr) { // si el unico camino es la derecha
            // aux = this->raiz;
            aux = aux->getHijoDer();
            cout << "te moviste a la DERECHA ya que no te puedes mover a la IZQUIERDA\n";
        }
        else if (aux->getHijoDer() == nullptr && aux->getHijoIzq() != nullptr) { // si el unico camino es la izquierda
            // aux = this->raiz;
            aux = aux->getHijoIzq();
            cout << "te moviste a la IZQUIERDA ya que no te puedes mover a la DERECHA\n";
        }
        else {

            int random = rand() % 100 + 1; // 0 a 100

            if (random <= 45) { // si esta entre 0 y 45 me muevo a la derecha 45%
                if (aux->getHijoDer() != nullptr) {
                    aux = aux->getHijoDer();
                    cout << "te moviste a la DERECHA \n";
                }
            }

            if (random > 45) {// si esta entre 46 y 100 me muevo a la izquierda 55%
                if (aux->getHijoIzq() != nullptr) {
                    aux = aux->getHijoIzq();
                    cout << "te moviste a la IZQUIERDA \n";
                }
            }
        }
        sleep_for(seconds(0));

        
    }
}






void Arbol::buscarNodosHojas(Nodo *raiz)
{
   
    if (this->raiz == nullptr)
    {
        cout << "\n\nel arbol aun no tiene elementos\n" << endl;
        return;
    }

    if (raiz->getHijoIzq()) {
        buscarNodosHojas(raiz->getHijoIzq());
        
    }
    if (raiz->getHijoDer()) {
        buscarNodosHojas(raiz->getHijoDer());
    }

    if (raiz->getHijoDer() == nullptr && raiz->getHijoIzq() == nullptr) {

        
        NodosGanadores.push(raiz->getDato());
        
    }

    

}

void Arbol::definirNodoGanador()
{
    srand(time(NULL));
    int random = rand() % 50; // 0 a 100



    for (int i = 0; i < random; i++)
    {
        NodosGanadores.push(NodosGanadores.front());
        NodosGanadores.pop();
    }
    nodoGanador = NodosGanadores.front();
    
}


