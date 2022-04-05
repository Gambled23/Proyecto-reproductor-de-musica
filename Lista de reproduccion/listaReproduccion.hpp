#ifndef LISTAREPRODUCCION_H
#define LISTAREPRODUCCION_H
#include <iostream>
#include <cstdlib>
#include "nodo.hpp"
#include "gotoxy.hpp"
#pragma once

using namespace std;
/*
TODO Cosas para hacer en el reproductor
//Buscar una manera de asignarles numero de fila
//Mostrar "Reproduciendo ahora"
//Mostrar fila de reproduccion (Numero en la fila, titulo, artista, album)
//Buscar y desplegar datos de cancion
//Insertar canciones en siguiente (insertar inicio)
//Insertar canciones al final de la fila (insertar final)
//Quitar cancion de lista (eliminar)
//Siguiente cancion
//Cancion anterior
Mover canciones de posicion usando su numero en la fila
Crear un modo aleatorio (nomás si me aburro no le voy a meter esfuerzo a esto la vida ya me está cogiendo)
Ser feliz
//Arreglar que si una cancion es muy larga se desfazan lo de titulo|album|artista (Interfaz)
*/

int numeroCanciones;
class listaReproduccion
{
public:
    listaReproduccion();
    nodo *h;
    nodo *t;
    nodo *currentSong;
    // Operaciones logicas
    void inicializa();
    void insertaInicio(string, string, string);
    void insertarFinal(string, string, string);
    void buscarElemento(string);
    void eliminarElemento(string);
    void eliminarLista();
    void calcularCanciones();
    void cancionAnteriorSiguiente(int);
    void asignarIDs();
    // Operaciones visuales
    void printNowPlaying();
    void printQueue();
};
listaReproduccion::listaReproduccion()
{
    h = nullptr;
    t = nullptr;
}
void listaReproduccion::inicializa()
{
    currentSong = h;
    listaReproduccion::asignarIDs();
}
//* *OPERACIONES
void listaReproduccion::insertaInicio(string art, string alb, string tit)
{
    nodo *nuevo_nodo = new nodo(art, alb, tit); // crear nuevo nodo dinamico
    if (h == nullptr)                           // Si la lista esta vacia
    {
        h = nuevo_nodo;
        t = nuevo_nodo;
        currentSong = h;
    }
    else // Si no esta vacia
    {
        h->anterior = nuevo_nodo;
        nuevo_nodo->siguiente = h;
        h = nuevo_nodo;
    }
}

void listaReproduccion::insertarFinal(string art, string alb, string tit)
{
    nodo *nuevo_nodo = new nodo(art, alb, tit); // crear nuevo nodo dinamico
    if (h == nullptr)
    {
        h = nuevo_nodo;
        t = nuevo_nodo;
        currentSong = h;
    }
    else
    {
        t->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = t;
        t = nuevo_nodo;
    }
}

void listaReproduccion::buscarElemento(string n)
{
    bool bandera = true;
    nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
    actual = h;                // Apuntar el nodo actual al inicio, para recorrer desde el 1er elemento

    while ((actual != nullptr) and (bandera)) // Mientras sigamos apuntando a un dato, y no al NULL, significa que seguimos en la lista
    {
        if (actual->titulo == n)
        {
            system("cls");
            cout << "Titulo: " << actual->titulo << endl
                 << "Artista: " << actual->artista << endl
                 << "Album: " << actual->album << endl;
            bandera = false;
        }
        actual = actual->siguiente; // Recorrer un nodo
    }
    if (bandera) // Si bandera sigue true es porque no encontro el elemento
    {
        cout << "La cancion no existe en la lista" << endl;
    }
    system("PAUSE");
}

void listaReproduccion::eliminarElemento(string n)
{
    if (h != nullptr)
    {
        nodo *aux_borrar;
        aux_borrar = h;
        if (currentSong->titulo == n)
        {
            currentSong = h;
        }
        while ((aux_borrar != nullptr) && (aux_borrar->titulo != n)) // Recorrer lista
        {
            aux_borrar = aux_borrar->siguiente;
        }
        if (aux_borrar == nullptr) // Si el elemento no se encuentra en la lista(no se elimina)
        {
            cout << "La ID no existe en la lista\n";
        }
        else if ((aux_borrar == h) and (aux_borrar == t) and (t == h)) // Si es el unico elemento en la lista
        {
            h = nullptr;
            t = h;
            currentSong = h;
            cout << "El elemento con la ID '" << n << "' ha sido borrado\n";
            delete aux_borrar;
        }
        else if (aux_borrar->anterior == nullptr) // El primer elemento es el que se elimina
        {
            h = h->siguiente; // el inicio de la lista se cambia, pues se elimino el inicio
            h->anterior = nullptr;
            cout << "El elemento con la ID '" << n << "' ha sido borrado\n";
            delete aux_borrar;
        }
        else if (aux_borrar->siguiente == nullptr) // El elemento que se elimina es del final
        {
            t = t->anterior;
            t->siguiente = nullptr;
            cout << "El elemento con la ID '" << n << "' ha sido borrado\n";
            delete aux_borrar;
        }
        else // El elemento que se elimina esta en medio
        {
            aux_borrar->anterior->siguiente = aux_borrar->siguiente;
            aux_borrar->siguiente->anterior = aux_borrar->anterior;
            cout << "El elemento con la ID '" << n << "' ha sido borrado\n"; // Imprimir el elemento a borrar
            delete aux_borrar;
        }
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}

void listaReproduccion::eliminarLista()
{
    while (h != nullptr) // Para hacer la eliminacion de cada nodo hasta que este vacia
    {
        nodo *aux = h; // Crear auxiliar que apunte al inicio de la lista
        h = aux->siguiente;
        delete aux;
    }
    cout << "La lista ha sido vaciada\n";
    t = nullptr;
    h = nullptr;
}
void listaReproduccion::calcularCanciones()
{
    numeroCanciones = 0;
    nodo *aux = currentSong;
    while (aux != nullptr)
    {
        numeroCanciones++;
        aux = aux->siguiente;
    }
}
void listaReproduccion::asignarIDs()
{
    int ID = 0;
    nodo *aux = currentSong;
    while (aux != nullptr)
    {
        aux->id = ID;
        ID++;
        aux = aux->siguiente;
    }
}
void listaReproduccion::printQueue()
{
    gotoxy(50, 1);
    cout << "Reproduciendo ahora";
    gotoxy(10, 2);
    cout << "Posicion";
    gotoxy(30, 2);
    cout << "Titulo";
    gotoxy(60, 2);
    cout << "Artista";
    gotoxy(90, 2);
    cout << "Album";
    gotoxy(10, 3);
    cout << currentSong->id;
    gotoxy(30, 3);
    cout << currentSong->titulo;
    gotoxy(60, 3);
    cout << currentSong->artista;
    gotoxy(90, 3);
    cout << currentSong->album;
    gotoxy(1, 4);
    cout << "----------------------------------------------------------------------------------------------------------------------";
    gotoxy(50, 5);
    cout << "Siguientes en la fila";

    nodo *aux = currentSong->siguiente;
    int i = 6;
    while (aux != nullptr)
    {
        gotoxy(10, i);
        cout << aux->id;
        gotoxy(30, i);
        cout << aux->titulo;
        gotoxy(60, i);
        cout << aux->artista;
        gotoxy(90, i);
        cout << aux->album;
        aux = aux->siguiente;
        i++;
    }
}
void listaReproduccion::cancionAnteriorSiguiente(int modo)
{
    if (modo == 1) // Cancion anterior
    {
        if (currentSong->anterior)
        {
            currentSong = currentSong->anterior;
            listaReproduccion::asignarIDs();
        }
        else
        {
            cout << "Estas al inicio de la lista\n";
            system("PAUSE");
        }
    }
    else if (modo == 2) // Cancion siguiente
    {
        if (currentSong->siguiente)
        {
            currentSong = currentSong->siguiente;
            listaReproduccion::asignarIDs();
        }
        else
        {
            cout << "Estas al final de la lista\n";
            system("PAUSE");
        }
    }
}
#endif