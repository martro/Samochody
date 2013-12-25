#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void funkcja_menu_11();
void funkcja_menu_21();
void funkcja_menu_31();

int menu_glowne();
void podkreslenie(void);
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

void funkcja_menu_31(char* nazwapliku)
{
    zapisz_bufor(temp,nazwapliku);
}

int menu_glowne(char* nazwapliku)
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
               "32 WCZYTAJ BUFOR\n\n"
               "41 STATYSTYKI\n\n"
               " 0 - ZAKONCZ\n\n"

               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor==11)||(wybor==21)||(wybor==31)||(wybor==0))
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
        funkcja_menu_31(nazwapliku);
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

void podkreslenie(void)
{
    printf("\n-------------------\n");
}

void zatwierdz(void)
{
    printf("\nNacisnij enter.\n");
    while((getchar()) != '\n');
}

#endif // MENU_H_INCLUDED
