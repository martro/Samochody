#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void funkcja_menu_11();
void funkcja_menu_21();
void funkcja_menu_23();
void funkcja_menu_31();
void funkcja_menu_32();
void funkcja_menu_33();

int menu_glowne();
void zatwierdz(void);

void funkcja_menu_11(samochod* lista)
{
    wyswietl(lista);
}

void funkcja_menu_21(samochod* temp, samochod* lista)
{
    temp=tymczas(temp);
    temp=edytuj(temp);
    printf("\ntest: %s\n",temp->marka);
    lista=push(lista,temp);
    printf("\ntest: %s\n",lista->marka);
}
void funkcja_menu_23()
{
//funkcja usun
}

void funkcja_menu_31(samochod* lista,d_prog* dane)
{
    zapisz_bufor(lista,dane);
    printf("\nZapisano pomyslnie.\n\nCzy usunac dane z bufora?\n");
    printf("Aby usunac nacisnij 't'.\nWybor: ");
    getchar();
    if (getchar()=='t')
        lista=clear(lista);

}

void funkcja_menu_32(samochod* lista,d_prog* dane, samochod* temp)
{
    lista=wczytaj_bufor(dane, lista, temp);
}
void funkcja_menu_33(samochod* lista)
{
    lista=clear(lista);
}

int menu_glowne(samochod* lista,samochod* temp,d_prog* dane)
{
    int wybor;
    char blad_odczytu;


    do
    {
        blad_odczytu=1;
        while((getchar()) != '\n');
        podkreslenie();
        printf("WYBOR AKCJI PROGRAMU\n\n"
               "BAZA DANYCH:\n"
               "11 WYSWIETL\n"
               "12 SORTUJ\n"
               "13 SZUKAJ\n\n"
               "21 DODAJ NOWY SAMOCHOD\n"
               "22 EDYTUJ DANE SAMOCHODU\n"
               "23 USUN SAMOCHOD\n\n"
               "31 ZAPISZ BUFOR\n"
               "32 WCZYTAJ BUFOR\n"
               "33 USUN BUFOR BEZ ZAPISYWANIA\n\n"
               "41 STATYSTYKI\n\n"
               " 0 - ZAKONCZ\n\n"

               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor==11)||(wybor==21)||(wybor==23)||(wybor==31)||(wybor==32)||(wybor==33)||(wybor==0))
            {
                printf("Poprawnie odczytano. Twoj wybor to: %d\n",wybor);
                blad_odczytu=0;
                podkreslenie();
            }
            else
            {
                printf("Blad wyboru akcji. Wybierz ponownie.");
                blad_odczytu=1;
            }

        }
        else
        {
            printf("Blad wyboru akcji. Wybierz ponownie.");
            blad_odczytu=1;
        }
    }
    while (blad_odczytu==1);

    switch (wybor)
    {
    case 11:
    {
        funkcja_menu_11(lista);
        break;
    }
    case 21:
    {
        funkcja_menu_21(temp,lista);
        break;
    }
    case 23:
    {
        funkcja_menu_23();
        break;
    }
    case 31:
    {
        funkcja_menu_31(lista,dane);
        break;
    }
    case 32:
    {
        funkcja_menu_32(lista,dane,temp);
        break;
    }
    case 33:
    {
        funkcja_menu_33(lista);
        break;
    }

    case 0:
    {
        return 0;
        break;
    }

    default:
    {
        break;
    }
    }

    return wybor;
}

void zatwierdz(void)
{
    printf("\nNacisnij enter.\n");
    while((getchar()) != '\n');
}

#endif // MENU_H_INCLUDED
