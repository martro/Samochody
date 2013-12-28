/**
*Laboratorium Programowanie w C
*Baza danych
*Prowadzacy: mgr inz. Mariusz Ostrowski
*Marcin Trojan 205608 MTR W-10
    */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struktura.h"
#include "menu.h"

int main()
{
    int dzialaj=1;
    char znak;

    samochod *lista=NULL;
    samochod *temp=NULL;
    d_prog* dane=NULL;
    dane=init(dane);

    printf("Laboratorium Programowanie w C\n"
           "Baza danych komisu samochodowego\n"
           "Prowadzacy: mgr inz. Mariusz Ostrowski\n"
           "Marcin Trojan 205608 MTR W-10\n");

    dane=init(dane);

    do
    {
        lista=menu_glowne(lista,temp,dane,&dzialaj);
        zatwierdz();
    }
    while (dzialaj);

    if (lista)
    {
        printf("W buforze znajduja sie dane.\nZapisac przed wylaczeniem programu?");
        printf("Aby wyjsc bez zapisywania nacisnij 'n'.\nWybor: ");
        znak=getchar();
        if (znak!='n')
            zapisz_bufor(lista,dane);
    }


    lista=clear(lista);
    free(dane->nazwapliku);
    free(dane);
    printf("\nPROGRAM ZAKONCZYL DZIALANIE POPRAWNIE\n\n");
    return 0;
}
