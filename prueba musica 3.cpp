#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
    string cancion = "Music.wav";
    cout<<PlaySound((LPCSTR)cancion.c_str(),NULL, SND_FILENAME|SND_ASYNC);
    system("PAUSE");
    cout<<PlaySound(NULL,NULL, SND_FILENAME|SND_ASYNC);
    system("PAUSE");
    return 0;
}
