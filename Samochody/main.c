/**
*Laboratorium Programowanie w C
*Baza danych
*Prowadzacy: mgr inz. Mariusz Ostrowski
*Marcin Trojan 205608 MTR W-10
    */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
{
    int dzialaj;
    printf("Laboratorium Programowanie w C\n"
           "Baza danych\n"
           "Prowadzacy: mgr inz. Mariusz Ostrowski\n"
           "Marcin Trojan 205608 MTR W-10\n");

    do
    {

        dzialaj=menu_glowne();
        zatwierdz();
    }
    while (dzialaj);

    getchar();
    return 0;
}
