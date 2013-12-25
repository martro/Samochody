/**
*Laboratorium Programowanie w C
*Baza danych
*Prowadzacy: mgr inz. Mariusz Ostrowski
*Marcin Trojan 205608 MTR W-10
    */
#include <stdio.h>
#include <stdlib.h>
#include "struktura.h"
#include "menu.h"

int main()
{
    int dzialaj;
    printf("Laboratorium Programowanie w C\n"
           "Baza danych komisu samochodowego\n"
           "Prowadzacy: mgr inz. Mariusz Ostrowski\n"
           "Marcin Trojan 205608 MTR W-10\n");

    char *nazwapliku;
    nazwapliku=(char*)malloc(sizeof(char)*NAZWA_PLIKU);

    do
    {

        dzialaj=menu_glowne(nazwapliku);
        zatwierdz();
    }
    while (dzialaj);

    getchar();
    return 0;
    free(nazwapliku);
}
