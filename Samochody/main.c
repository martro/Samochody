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

    dane=init();


    do
    {

        dzialaj=menu_glowne();
        zatwierdz();
    }
    while (dzialaj);

    if (lista)
    {
        printf("W buforze znajduja sie dane.\nZapisac przed wylaczeniem programu?");
        printf("Aby wyjsc bez zapisywania nacisnij 'n'.\nWybor: ");
        getchar();
        if (getchar()!='n')
        {
            zapisz_bufor(lista,dane);
        }

    }


    lista=clear(lista);

    free(dane->nazwapliku);
    free(dane);
    printf("\nPROGRAM ZAKONCZYL DZIALANIE POPRAWNIE\n\n");
    return 0;
}
