#include <cstdlib>
#include <iostream>
#include "listaReproduccion.hpp"
using namespace std;

void menu();

listaReproduccion *lista = new listaReproduccion();
int main()
{
    menu();
    system("PAUSE");
    return 0;
}

void menu()
{
    int opc;
    string auxTitulo, auxArtista, auxAlbum;
    lista->insertaInicio("Watsky", "New kind of sexy", "Danger");
    lista->insertarFinal("Watsky", "New kind of sexy", "They are not ready");
    lista->insertaInicio("Watsky", "New kind of sexy", "Kidnap your boyfriend");
    lista->inicializa();
    do
    {
        system("cls");
        lista->printQueue();
        cout << "\n=======================================================================================================================";
        cout << "\n\n\t\t\t1)Cancion anterior\t\t\t\t2)Cancion siguiente\n\n\t3)Buscar cancion\n\t4)Eliminar cancion\n\t5)Agregar cancion\n\t0)Salir del programa\n";
        cin >> opc;

        switch (opc)
        {
        case 1:
            lista->cancionAnteriorSiguiente(1);
            break;
        case 2:
            lista->cancionAnteriorSiguiente(2);
            break;
        case 3:
            system("cls");
            cout << "Ingresa el titulo de la cancion a buscar\n";
            cin.sync();
            getline(cin, auxTitulo);
            lista->buscarElemento(auxTitulo);
            break;
        case 4:
            system("cls");
            cout << "Ingresa el titulo de la cancion a eliminar\n";
            cin.sync();
            getline(cin, auxTitulo);
            lista->eliminarElemento(auxTitulo);
            break;
        case 5:
            system("cls");
            cout << "Ingresa el titulo de la cancion a agregar\n";
            cin.sync();
            getline(cin, auxTitulo);
            cout << "Ingresa el album de la cancion a agregar\n";
            cin.sync();
            getline(cin, auxAlbum);
            cout << "Ingresa el artista de la cancion a agregar\n";
            cin.sync();
            getline(cin, auxArtista);
            lista->insertarFinal(auxArtista, auxAlbum, auxTitulo);
            lista->asignarIDs();
            break;
        case 0:
            cout << "Gracias por su preferencia" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (opc != 0);
}