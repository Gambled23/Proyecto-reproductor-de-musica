#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

typedef BOOL(PlaySoundA_ptr)(char, HMODULE, DWORD);
PlaySoundA_ptr fn_PlaySound = 0;

int main()
{
    HMODULE Lib = LoadLibrary("winmm.dll");
    if (Lib)
    {
        fn_PlaySound = (PlaySoundA_ptr)GetProcAddress(Lib, "PlaySoundA");
        if (fn_PlaySound)
        {
            fn_PlaySound("Music.wav", NULL, SND_FILENAME | SND_ASYNC);
        }
        else
        {
            MessageBox(0, "Error", "No se encontro la función PlaySoundA", 0);
        }
        getch();
        getch();
        FreeLibrary(Lib);
    }
    else
    {
        MessageBox(0, "Error", "No se pudo cargar winmm.dll", 0);
    }
    return 0;
    system("PAUSE");
}