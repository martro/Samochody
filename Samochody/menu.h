#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void funkcja_menu_11();
void funkcja_menu_21();

int menu_glowne();
void podkreslenie(void);
void zatwierdz(void);

void funkcja_menu_11()
{
    wyswietl(lista);
}

void funkcja_menu_21()
{
    printf("wskaznik stary: %d\n\n",temp);
    temp=tymczas();
    printf("wskaznik: %d\n\n",temp);
    temp=edytuj(temp);
    printf("wskaznik: %d\n\n",temp);
    printf("test, marka: %s\n\n",temp->marka);
    lista=push(lista,temp);
    printf("wskaznik: %d\n\n",temp);
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
               "31 STATYSTYKI\n"
               " 0 - ZAKONCZ\n\n"

               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor==11)||(wybor==21)||(wybor==0))
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
