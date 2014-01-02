#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

samochod* funkcja_menu_11();
samochod* funkcja_menu_12(samochod*lista, samochod* temp);
samochod* funkcja_menu_21(samochod* temp,samochod* lista);
samochod* funkcja_menu_23();
samochod* funkcja_menu_24(samochod* temp,samochod* lista);
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
 lista=sortuj(lista,temp);
 return lista;
}
samochod* funkcja_menu_13(samochod* lista)
{
    szukaj(lista);
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
    int wybor,error=1,usunieto;
    printf("\nUSUWANIE SAMOCHODU Z BAZY\n\n");
    wyswietl(lista);


    while((lista)&&(usunieto==0))
    {
        usunieto=0;
    do
    {
    printf("\nKtory samochod usunac?\nWybor:");
        error=0;
        scanf("%d",&wybor);
        error=printf("\nwybor: %d\n",wybor);
        if ((wybor<=0)||(wybor>rozmiar(lista)))
            error=0;

        if (error==0)
            printf("Niepoprawny wybor. Wybierz jeszcze raz.\n");
    }
    while (error==0);

    temp=pozycja(wybor,lista);
    printf("%s %s",temp->marka,temp->model);
    if (temp)

{
lista=usun_1(lista,temp);
usunieto=1;
}
    }
    return lista;
}

samochod* funkcja_menu_24(samochod* temp, samochod* lista)
{
    temp=tymczas(temp);
    temp=dodajlos(temp);
    lista=push(lista,temp);

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
               "23 USUN SAMOCHOD\n"
               "24 DODAJ LOSOWY SAMOCHOD (opcja testowa)\n\n"
               "31 ZAPISZ BUFOR\n"
               "32 WCZYTAJ BUFOR\n"
               "33 USUN BUFOR BEZ ZAPISYWANIA\n\n"
               " 0 - ZAKONCZ\n\n"

               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor==11)||(wybor==12)||(wybor==13)||(wybor==21)||(wybor==23)||(wybor==24)||(wybor==31)||
                (wybor==32)||(wybor==33)||(wybor==0))
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
    case 13:
    {

        lista=funkcja_menu_13(lista);
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
    case 24:
    {
        lista=funkcja_menu_24(temp,lista);
        return lista;
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
