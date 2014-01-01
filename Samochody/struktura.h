#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

#define MODEL 12
#define MARKA 12
#define NAZWA_PLIKU 30

typedef struct samochod
{
    char* marka;
    char* model;
    struct samochod *nastepny;
    struct samochod *poprzedni;

    int rok,cena,przebieg;
    int nowyuzywany; //1-nowy;, 2-uzywany
    int paliwo; // 1-benzyna, 2-diesel, 3-gaz
    int wypadek; //1- bezwypadkowy, 2-powypadkowy
    float spalanie;
} samochod;

typedef struct d_prog
{
    char* nazwapliku;
    int czynazwa;
    int czywczytane;
} d_prog;



samochod* clear(samochod *first);
samochod* dodajlos(samochod *first);
samochod* edytuj(samochod *first);
d_prog* init(d_prog* dane);
void podkreslenie(void);
samochod* pozycja(int poz,samochod* first);
samochod* push(samochod *first, samochod *newone);
int rozmiar(samochod* first);
char samogloska();
samochod* sortuj(samochod* lista,samochod*temp);
char spolgloska();
void test(samochod *temp);
samochod* tymczas();
samochod* usun_1(samochod *lista,samochod* temp);
samochod* wczytaj_bufor();
void wyswietl(samochod *first);
samochod* zamien2(samochod* bierz, samochod* temp,int n);
void zapisz_bufor(samochod* temp,d_prog* dane);


samochod* clear(samochod *first)
{
    if (first==NULL)
    {
        printf("W buforze nie ma danych.");
        return NULL;
    }
    clear (first->nastepny);

    free(first->marka);
    free(first->model);
    free(first);
    return NULL;
}

samochod* dodajlos(samochod *temp)
{
    int i,dlugosc;
    char znak;

    znak=spolgloska();
    znak-=32;

    strcpy(temp->marka,&znak);
    temp->marka[1]=0;

    dlugosc=rand()%10;
    dlugosc+=3;
    for (i=2; i<dlugosc; i++)
    {
        if (i%2==0)
            znak=samogloska();
        else
            znak=spolgloska();

        strcat(temp->marka,&znak);
        temp->marka[i]=0;
    }

    znak=spolgloska();
    znak-=32;

    strcpy(temp->model,&znak);
    temp->model[1]=0;

    dlugosc=rand()%10;
    dlugosc+=2;
    for (i=2; i<dlugosc; i++)
    {
        if (i%2==0)
            znak=samogloska();
        else
            znak=spolgloska();

        strcat(temp->model,&znak);
        temp->model[i]=0;
    }

    temp->cena=(rand()%200+1)*1000;
    temp->przebieg=(rand()%350+50)*1000;
    temp->rok=(rand()%64)+1950;
    temp->spalanie=(rand()%150+50)/10.;
    temp->nowyuzywany=rand()%2+1;
    temp->wypadek=rand()%2+1;
    temp->paliwo=rand()%3+1;

    return temp;
}

samochod* edytuj(samochod *temp)
{
    int error;
    printf("Podaj dane samochodu.\n\nMarka: ");
    scanf("%s",temp->marka);
    printf("\nModel: ");
    scanf("%s",temp->model);
    do
    {
        podkreslenie();
        printf("\nCena: ");
        error=0;
        if (scanf("%d",&temp->cena)==0)
        {
            error=1;
            printf("Wprowadzona cena jest nieprawidlowa.\n");
            getchar();
        }
        else if (temp->cena<0)
        {
            printf("Cena nie moze byc ujemna.\n");
            error=1;
            getchar();
        }
    }
    while(error==1);


    do
    {
        podkreslenie();
        printf("\nPrzebieg: ");
        error=0;
        if (scanf("%d",&temp->przebieg)==0)
        {
            error=1;
            printf("Wprowadzony przebieg jest nieprawidlowy.\n");
            getchar();
        }
        else if (temp->przebieg<0)
        {
            printf("Przebieg nie moze byc ujemny.\n");
            error=1;
            getchar();
        }
    }
    while(error==1);

    do
    {
        podkreslenie();
        printf("\nRok produkcji: ");
        error=0;
        if (scanf("%d",&temp->rok)==0)
        {
            error=1;
            printf("Wprowadzony rok produkcji jest nieprawidlowy.\n");
            getchar();
        }
        else if ((temp->rok)<1950)
        {
            printf("Rok produkcji nie moze byc mniejszy niz 1950.\n");
            error=1;
            getchar();
        }
        else if ((temp->rok)>2014)
        {
            printf("Rok produkcji nie moze byc wiekszy niz 2014.\n");
            error=1;
            getchar();
        }
    }
    while(error==1);

    do
    {
        podkreslenie();
        printf("\nSpalanie");
        error=0;
        if (scanf("%f",&temp->spalanie)==0)
        {
            error=1;
            printf("Wprowadzone spalanie jest nieprawidlowe.\n");
            getchar();
        }
        else if ((temp->spalanie)<=0)
        {
            printf("Spalanie nie moze byc ujemne.\n");
            error=1;
            getchar();
        }
        else if ((temp->spalanie)>25)
        {
            printf("Spalanie nie moze byc wieksze niz 25.\n");
            error=1;
            getchar();
        }
    }
    while(error==1);

    do
    {
        podkreslenie();
        printf("Samochod nowy czy uzywany?\n");
        printf("\n1 - Nowy\n2-Uzywany\n");
        printf("Wybor: ");
        error=0;
        if (scanf("%d",&temp->nowyuzywany)==0)
        {
            error=1;
            printf("Wprowadzony parametr jest nieprawidlowy.\n");
            getchar();
        }
        else if (((temp->nowyuzywany)!=1)&&((temp->nowyuzywany)!=2))
        {
            printf("Nieprawidlowy wybor.\n");
            error=1;
            getchar();
        }
    }
    while(error==1);

    do
    {
        podkreslenie();
        printf("Samochod bezwypadkowy czy powypadkowy?\n");
        printf("\n1 - Bezwypadkowy\n2-Powypadkowy\n");
        printf("Wybor: ");
        error=0;
        if (scanf("%d",&temp->wypadek)==0)
        {
            error=1;
            printf("Wprowadzony parametr jest nieprawidlowy.\n");
            getchar();
        }
        else if (((temp->wypadek)!=1)&&((temp->wypadek)!=2))
        {
            printf("Nieprawidlowy wybor.\n");
            error=1;
            getchar();
        }
    }
    while(error==1);

    do
    {
        podkreslenie();
        printf("Rodzaj paliwa\n");
        printf("\n1 - Benzyna\n2-Diesel\n3-Gaz\n");
        printf("Wybor: ");
        error=0;
        if (scanf("%d",&temp->paliwo)==0)
        {
            error=1;
            printf("Wprowadzony rodzaj paliwa jest nieprawidlowy.\n");
            getchar();
        }
        else if (((temp->paliwo)!=1)&&((temp->paliwo)!=2)&&((temp->paliwo)!=3))
        {
            printf("Nieprawidlowy wybor paliwa.\n");
            error=1;
            getchar();
        }
    }
    while(error==1);
    return temp;
}

d_prog* init(d_prog* dane)
{
    dane=(d_prog *)malloc(sizeof(d_prog));
    dane->nazwapliku=(char*)malloc(sizeof(char)*NAZWA_PLIKU);
    dane->czynazwa=0;
    return dane;
}

void podkreslenie(void)
{
    printf("\n-------------------\n");
}

samochod* pozycja(int poz, samochod* first)
{
    int maks,i;
    maks=rozmiar(first)-1;

    poz--;

    if (poz>maks)
    {
        printf("Podana liczba jest za duza.\n");
        return NULL;
    }
    else if(poz<0)
    {
        printf("Blad. Pozycja musi byc dodatnia.\n");
        return NULL;
    }

    for (i=0; i<poz; i++)
        first = first->nastepny;
    return first;
}

samochod* push(samochod *first, samochod *newone)
{
    samochod *temp=first;

    if (first==NULL)
        return newone;

    while (temp->nastepny!=NULL)
    {
        temp->nastepny->poprzedni=temp;
        temp=temp->nastepny;
    }
    temp->nastepny=newone;
    temp->nastepny->poprzedni=temp;
    return first;
}

int rozmiar(samochod* first)
{
    int i=0;
    while(first!=NULL)
    {
        i++;
        first = first->nastepny;
    }
    return i;
}

char spolgloska()
{
    char znak;
    do
    {
        znak=(rand()%25+97);
    }
    while((znak=='a')||(znak=='e')||(znak=='i')||(znak=='o')||(znak=='u')
            ||(znak=='y')||(znak=='x')||(znak=='v')||(znak=='q'));
    return znak;
}

samochod* tymczas(samochod* temp)
{
    temp=(samochod *)malloc(sizeof(samochod));
    temp->model=(char*)malloc(sizeof(char)*MODEL);
    temp->marka=(char*)malloc(sizeof(char)*MARKA);
    temp->nastepny=NULL;
    temp->poprzedni=NULL;
    return temp;
}

samochod* sortuj(samochod* lista,samochod*temp)
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

char samogloska()
{
    char znak;
    do
    {
        znak=(rand()%25+97);
    }
    while((znak!='a')&&(znak!='e')&&(znak!='i')&&(znak!='o')&&(znak!='u'));
    return znak;
}

samochod* usun_1(samochod* first,samochod *temp)
{
    if (temp->nastepny)
        temp->nastepny->poprzedni=temp->poprzedni; //nastepnemu (jezeli jest) przypisuje poprzedni

    if (temp->poprzedni)
        temp->poprzedni->nastepny=temp->nastepny;//poprzedniemu (jezeli jest) przypisuje nastepny
    else
        first=temp->nastepny;

    free(temp->marka);
    free(temp->model);
    free(temp);
    return first;
}

samochod* wczytaj_bufor(d_prog* dane, samochod* lista,samochod* temp)
{
    char wybor;
    char znak;
    FILE * pFile;

    if (lista==NULL)
    {
        printf("\nWczytywanie pliku %s",dane->nazwapliku);
        printf("\nWybierz akcje:"
               "\n1 - domyslna lokalizacja\n"
               "\n2 - wybrana nazwa\n");
        while((getchar()) != '\n');
        wybor=getchar();
        printf("\nwybor: %d\n",wybor);

        if (wybor=='1')

            strcpy (dane->nazwapliku,"data.dat");

        if (wybor=='2')
        {
            printf("\nPODAJ NAZWE PLIKU (rozszerzenie: .dat): ");
            scanf("%s",dane->nazwapliku);
            printf("\nNAZWa PLIKU: %s",dane->nazwapliku);
        }

        printf("\nWczytywanie pliku: %s",dane->nazwapliku);
        pFile = fopen (dane->nazwapliku,"r");

        if (pFile!=NULL)
        {
            dane->czynazwa=1;
            do
            {
                znak=fgetc(pFile);

                if (znak=='+')
                {
                    // fseek(pFile,1,SEEK_CUR);
                    temp=tymczas(temp);
                    fscanf(pFile,"%s %s %d %d",temp->marka,temp->model,&temp->cena,&temp->przebieg);
                    fscanf(pFile,"%d %f %d %d %d",&temp->rok,&temp->spalanie,&temp->nowyuzywany,&temp->wypadek,&temp->paliwo);
                    lista=push(lista,temp);
                }
            }
            while(znak!=EOF);

            fclose (pFile);
            printf("\nZAPISANO\n");
        }
    }
    else
    {
        printf("W buforze znajduja sie juz dane.\nPrzed wgraniem nowych nalezy usunac badz zapisac poprzednie.\n");
    }
    return lista;
}

void wyswietl(samochod *first)
{
    int i=0,ilosc,j;
    if (first==NULL)
    {
        printf("\nLista jest pusta.");
    }

    else
    {
        printf("\n                                      1-paliwo 2-wypadek/bezwypadkowy\n");
        printf("BAZA DANYCH KOMISU SAMOCHODOWEGO      3-nowy/uzywany\n");
        printf("Nr   Marka          Model          cena      przebieg  spalanie   1   2   3\n");
        printf("---------------------------------------------------------------------------");
        do
        {
            i++;
            ilosc=0;
            printf("\n%3d  ",i);
            ilosc=printf("%s",first->marka);

            for(j=0; j<(15-ilosc); j++)
                printf(" ");
            ilosc=printf("%s",first->model);
            for(j=0; j<(15-ilosc); j++)
                printf(" ");
            ilosc=printf("%d",first->cena);
            for(j=0; j<(10-ilosc); j++)
                printf(" ");
            ilosc=printf("%d",first->przebieg);
            for(j=0; j<(10-ilosc); j++)
                printf(" ");
            if (first->spalanie/10<1)
            printf(" %.2f",first->spalanie);
            else
            printf("%.2f",first->spalanie);
            for(j=0; j<(3-ilosc); j++)
                printf(" ");

            printf("      ");
            if (first->paliwo==1)
                printf("B   ");
            else if (first->paliwo==2)
                printf("D   ");
            else if (first->paliwo==3)
                printf("G   ");

            if (first->wypadek==1)
                printf("B   ");
            else if (first->wypadek==2)
                printf("W   ");

            if (first->nowyuzywany==1)
                printf("N");
            else if (first->nowyuzywany==2)
                printf("U");



            for(j=0; j<(10-ilosc); j++)
                printf(" ");

            first=first->nastepny;
        }
        while(first!=NULL);
        printf("\n---------------------------------------------------------\n");
    }
}

samochod* zamien2(samochod* bierz,samochod *temp,int n)
{
    bierz=pozycja(n,bierz);

    if (bierz->nastepny)
    {
        temp=bierz->nastepny->nastepny;  //kopia pozycji D
        if (bierz->nastepny->nastepny)
            bierz->nastepny->nastepny->poprzedni=bierz;  //zamianna poprzD z C na B
        bierz->nastepny->nastepny=bierz;  //zamiana nastC z D na B
        bierz->nastepny->poprzedni=bierz->poprzedni;  //zamiana poprzC z B na A
        if (bierz->poprzedni) //jezeli B jest pierwszym el.
            bierz->poprzedni->nastepny=bierz->nastepny;  //zamiana nastA z B na C
        bierz->poprzedni=bierz->nastepny;
        bierz->nastepny=temp;
    }


    /* free(temp->marka);
     free(temp->model);
     free(temp);*/

    while (bierz->poprzedni)
        bierz=bierz->poprzedni;
    return bierz;
}

void zapisz_bufor(samochod* first,d_prog* dane)
{
    int i,roz,error;
    char wybor;
    FILE * pFile;

    if (first!=NULL)
    {
        printf("\nZapis pliku %s",dane->nazwapliku);
        do
        {
            error=1;
            printf("\nWybierz akcje:"
                   "\n1 - domyslna nazwa"
                   "\n2 - bierzaca nazwa"
                   "\n3 - nowa nazwa\n");

            wybor=getchar();
            printf("\nwybor: %c\n",wybor);

            if (wybor=='1')
            {
                strcpy(dane->nazwapliku,"data.dat");
                error=0;
            }
            else if (wybor=='2')
            {
                if (dane->czynazwa==1)
                    error=0;
                else
                    printf("Nie ma bierzacej nazwy w buforze.\n");
            }
            else if (wybor=='3')
            {
                getchar();
                printf("\nPODAJ NAZWE PLIKU (rozszerzenie: .dat): ");
                scanf("%s",dane->nazwapliku);
                printf("\nNAZWa PLIKU: %s",dane->nazwapliku);
                error=0;
            }

            if (error==1)
                printf("Niepoprawny wybor. Wybierz jeszcze raz.\n");
        }
        while (error==1);

        printf("\nZapisywanie pod nazwa: %s",dane->nazwapliku);
        pFile = fopen (dane->nazwapliku,"w");

        if (pFile!=NULL)
        {
            roz=rozmiar(first);
            for(i=0; i<roz; i++)
            {
                fprintf(pFile,"+%s %s %d %d ",first->marka,first->model,first->cena,first->przebieg);
                fprintf(pFile,"%d %f %d %d %d\n",first->rok,first->spalanie,first->nowyuzywany,first->wypadek,first->paliwo);
                first=first->nastepny;
            }

            if (fclose (pFile))
                printf("\nZAPISANO\n");
        }
    }
    else
        printf("Nie ma danych w buforze.");
}

#endif // STRUKTURA_H_INCLUDED
