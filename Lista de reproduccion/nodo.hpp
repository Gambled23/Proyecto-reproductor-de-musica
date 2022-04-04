#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class nodo
{
public:
    nodo *anterior;
    nodo *siguiente;
    string artista;
    string album;
    string titulo;
    int id;
    nodo();
    nodo(string, string, string);
};

nodo::nodo()
{
    id = 0;
    artista = "";
    album = "";
    titulo = "";
    anterior = nullptr;
    siguiente = nullptr;
}
nodo::nodo(string art, string alb, string tit)
{
    id = 0;
    artista = art;
    album = alb;
    titulo = tit;
    anterior = nullptr;
    siguiente = nullptr;
}
#endif