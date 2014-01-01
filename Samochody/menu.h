#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

samochod* funkcja_menu_11();
samochod* funkcja_menu_12(samochod*lista, samochod* temp);
samochod* funkcja_menu_21(samochod* temp,samochod* lista);
samochod* funkcja_menu_23();
samochod* funkcja_menu_31();
samochod* funkcja_menu_32();
samochod* funkcja_menu_33();
samochod* menu_glowne(samochod* lista,samochod* temp,d_prog* dane,int* dzialaj);
void zatwierdz(void);



samochod* funkcja_menu_11(samochod* lista)
{
    wyswietl(lista);
    return lista;
}

samochod* funkcja_menu_12(samochod* lista,samochod*temp)
{
    int i,n,error,wybor;
    n=rozmiar(lista);
    do
    {
        printf("Sortowanie wg:\n");
        printf("\n1 - Ceny rosnaco\n2-Ceny malejaco\n");
        printf("\n3 - Marki rosnaco\n4-Marki malejaco\n");
        printf("\n5 - Modelu rosnaco\n6-Modelu malejaco\n");
        printf("Wybor: ");
        error=0;
        if (scanf("%d",&wybor)==0)
        {
            error=1;
            printf("W.\n");
            getchar();
        }
        else if ((wybor<1)||(wybor>6))
        {
            printf("Nieprawidlowy wybor.\n");
            error=1;
            getchar();
        }
    }
    while(error==1);



    if (wybor==1)//cena rosnaco
    {
        do
        {
            for (i=1; i<n; i++)
            {
                temp=pozycja(i,lista);
                if ((temp->nastepny->cena)<(temp->cena))
                {
                    printf("\n%d %d",temp->nastepny->cena,temp->cena);
                    lista=zamien2(lista,temp,i);
                }
            }
            n--;
        }
        while(n>0);
    }

    if (wybor==2)//cena malejaco
    {
        do
        {
            for (i=1; i<n; i++)
            {
                temp=pozycja(i,lista);
                if ((temp->nastepny->cena)>(temp->cena))
                {
                    printf("\n%d %d",temp->nastepny->cena,temp->cena);
                    lista=zamien2(lista,temp,i);
                }
            }
            n--;
        }
        while(n>0);
    }

   if (wybor==3)//marka rosnaco
    {
        do
        {
            for (i=1; i<n; i++)
            {
                temp=pozycja(i,lista);
                if (strcmp(temp->nastepny->marka,temp->marka)<0)
                {
                    printf("\n%d %d",temp->nastepny->cena,temp->cena);
                    lista=zamien2(lista,temp,i);
                }
            }
            n--;
        }
        while(n>0);
    }


    if (wybor==4)//marka malejaco
    {
        do
        {
            for (i=1; i<n; i++)
            {
                temp=pozycja(i,lista);
                if (strcmp(temp->nastepny->marka,temp->marka)>0)
                {
                    printf("\n%d %d",temp->nastepny->cena,temp->cena);
                    lista=zamien2(lista,temp,i);
                }
            }
            n--;
        }
        while(n>0);
    }

   if (wybor==5)//model rosnaco
    {
        do
        {
            for (i=1; i<n; i++)
            {
                temp=pozycja(i,lista);
                if (strcmp(temp->nastepny->model,temp->model)<0)
                {
                    lista=zamien2(lista,temp,i);
                }
            }
            n--;
        }
        while(n>0);
    }


    if (wybor==6)//model malejaco
    {
        do
        {
            for (i=1; i<n; i++)
            {
                temp=pozycja(i,lista);
                if (strcmp(temp->nastepny->model,temp->model)>0)
                {
                    lista=zamien2(lista,temp,i);
                }
            }
            n--;
        }
        while(n>0);
    }

    return lista;
}

samochod* funkcja_menu_21(samochod* temp, samochod* lista)
{
    temp=tymczas(temp);
    temp=edytuj(temp);
    printf("\ntest: %s\n",temp->marka);
    lista=push(lista,temp);

    return lista;
}

samochod* funkcja_menu_23(samochod* lista,samochod* temp)
{
    int wybor,error=1;
    printf("\nUSUWANIE SAMOCHODU Z BAZY\n\n");
    wyswietl(lista);
    printf("\nKtory samochod usunac?\nWybor:");

    do
    {
        error=0;
        scanf("%d",&wybor);
        error=printf("\nwybor: %d\n",wybor);

        if (error==0)
            printf("Niepoprawny wybor. Wybierz jeszcze raz.\n");
    }
    while (error==0);

    temp=pozycja(wybor,lista);
    printf("%s",temp->model);
    lista=usun_1(lista,temp);

    return lista;
}

samochod* funkcja_menu_31(samochod* lista,d_prog* dane)
{
    zapisz_bufor(lista,dane);
    printf("\nZapisano pomyslnie.\n\nCzy usunac dane z bufora?\n");
    printf("Aby usunac nacisnij 't'.\nWybor: ");
    getchar();
    if (getchar()=='t')
        lista=clear(lista);
    return lista;
}

samochod* funkcja_menu_32(samochod* lista,d_prog* dane, samochod* temp)
{
    lista=wczytaj_bufor(dane, lista, temp);
    return lista;
}

samochod* funkcja_menu_33(samochod* lista)
{
    lista=clear(lista);
    return lista;
}

samochod* menu_glowne(samochod* lista,samochod* temp,d_prog* dane,int* dzialaj)
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
            if ((wybor==11)||(wybor==12)||(wybor==21)||(wybor==23)||(wybor==31)||(wybor==32)||(wybor==33)||(wybor==0))
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

        lista=funkcja_menu_11(lista);
        return lista;
        break;
    }
    case 12:
    {

        lista=funkcja_menu_12(lista,temp);
        return lista;
        break;
    }
    case 21:
    {
        lista=funkcja_menu_21(temp,lista);
        return lista;
        break;
    }
    case 23:
    {
        lista=funkcja_menu_23(lista,temp);
        break;
    }
    case 31:
    {
        lista=funkcja_menu_31(lista,dane);
        break;
    }
    case 32:
    {
        lista=funkcja_menu_32(lista,dane,temp);
        return lista;
        break;
    }
    case 33:
    {
        lista=funkcja_menu_33(lista);
        return lista;
        break;
    }

    case 0:
    {
        *dzialaj=0;
        break;
    }

    default:
        break;
    }
    return lista;
}

void zatwierdz(void)
{
    printf("\nNacisnij enter.\n");
    while((getchar()) != '\n');
}

#endif // MENU_H_INCLUDED
