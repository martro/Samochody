#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void funkcja_menu_01();

int menu_glowne();
void podkreslenie(void);
void zatwierdz(void);

void funkcja_menu_01()
{
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
        printf("WYBOR AKCJI PROGRAMU\n"
               " 1 - WYSWIETL BAZE DANYCH\n"
               " 6 - ZAKONCZ\n\n"

               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor==1)||(wybor==6))
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
    case 1:
    {
        funkcja_menu_01();
        break;
    }

    case 6:
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
