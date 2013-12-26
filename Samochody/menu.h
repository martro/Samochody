#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void funkcja_menu_11();
void funkcja_menu_21();
void funkcja_menu_31();
void funkcja_menu_32();
void funkcja_menu_33();

int menu_glowne();
void zatwierdz(void);

void funkcja_menu_11()
{
    wyswietl(lista);
}

void funkcja_menu_21()
{
    temp=tymczas();
    temp=edytuj(temp);
    lista=push(lista,temp);
}

void funkcja_menu_31()
{
    zapisz_bufor(lista,dane);
    printf("\nZapisano pomyslnie.\n\nCzy usunac dane z bufora?\n");
    printf("Aby usunac nacisnij 't'.\nWybor: ");
    getchar();
    if (getchar()=='t')
        lista=clear(lista);

}

void funkcja_menu_32()
{
    lista=wczytaj_bufor(dane);
}
void funkcja_menu_33()
{
    lista=clear(lista);
}

int menu_glowne()
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
               "21 EDYTUJ DANE SAMOCHODU\n"
               "23 USUN SAMOCHOD\n\n"
               "31 ZAPISZ BUFOR\n"
               "32 WCZYTAJ BUFOR\n"
               "33 USUN BUFOR BEZ ZAPISYWANIA\n\n"
               "41 STATYSTYKI\n\n"
               " 0 - ZAKONCZ\n\n"

               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor==11)||(wybor==21)||(wybor==31)||(wybor==32)||(wybor==33)||(wybor==0))
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
        funkcja_menu_11();
        break;
    }
    case 21:
    {
        funkcja_menu_21();
        break;
    }
    case 31:
    {
        funkcja_menu_31();
        break;
    }
    case 32:
    {
        funkcja_menu_32();
        break;
    }
    case 33:
    {
        funkcja_menu_33();
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
