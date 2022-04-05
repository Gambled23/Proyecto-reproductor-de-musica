#include <iostream>
#include <cstdlib>
#include "gotoxy.hpp"

using namespace std;
void prueba();
void pruebareproductor();
int main()
{
    pruebareproductor();
    system("PAUSE ");
    return 0;
}
void prueba()
{
    prueba();
    gotoxy(1,1);
    cout<<"1,1";
    gotoxy(100,1);
    cout<<"100,1";
    gotoxy(1,25);
    cout<<"1,25";
    gotoxy(100,25);
    cout<<"100,25\n";
}
void pruebareproductor()
{
    gotoxy(50,1);
    cout<<"Reproduciendo ahora";
    gotoxy(10,2);
    cout<<"Posicion";
    gotoxy(30,2);
    cout<<"Titulo";
    gotoxy(60,2);
    cout<<"Artista";
    gotoxy(90,2);
    cout<<"Album";
    gotoxy(1,4);
    cout<<"---------------------------------------------------------------------------------------";
    gotoxy(50,5);
    cout<<"Siguientes en la fila";
    int i = 6;
    gotoxy(10, i);
    cout<<i;
    i++;
    gotoxy(10, i);
    cout<<i;
    i++;
    gotoxy(10, i);
    cout<<i;
    i++;
    gotoxy(10, i);
    cout<<i;
    i++;
    gotoxy(10, i);
    cout<<i;
    i++;
    gotoxy(10, i);
    cout<<i;
    i++;
}