#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

#define MODEL 30
#define MARKA 30

typedef struct samochod
{
    char* marka;
    char* model;
    struct samochod *nastepny;
    struct samochod *poprzedni;

    int rok,spalanie,cena,przebieg;
    int nowyuzywany; //1-nowy;, 2-uzywany
    int paliwo; // 1-benzyna, 2-diesel, 3-gaz
    int wypadek; //0- bezwypadkowy, 1-powypadkowy
} samochod;

samochod *lista=NULL;
samochod *temp=NULL;


samochod* clear(samochod *first);
samochod* edytuj(samochod *first);
samochod* pozycja(int poz,samochod* first);
samochod* push(samochod *first, samochod *newone);
int rozmiar(samochod* first);
samochod* tymczas();
void wyswietl(samochod *first);


samochod* clear(samochod *first)
{
    if (first==NULL)
        return NULL;

    clear (first->nastepny);

    free(first->marka);
    free(first->model);
    free(first);
    return NULL;
}

samochod* edytuj(samochod *temp)
{
    printf("Dodawanie nowego samochodu.\n\n"
           "Marka: ");
    scanf("%s",temp->marka);
    printf("\nModel: ");
    scanf("%s",temp->model);
    printf("\nCena");
    scanf("%d",&temp->cena);
    printf("\nPrzebieg");
    scanf("%d",&temp->przebieg);
    return temp;
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

    //printf("\n\nNazwa pliku: %s\n", first->nazwa_pliku);


    return first;
}

samochod* push(samochod *first, samochod *newone)
{
    samochod *temp=first;

    if (first==NULL)
        return newone;

    while (temp->nastepny!=NULL)
    {
        temp=temp->nastepny;
    }
    temp->nastepny=newone;
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

samochod* tymczas()
{
    temp=(samochod *)malloc(sizeof(samochod));
    temp->model=(char*)malloc(sizeof(char)*MODEL);
    temp->marka=(char*)malloc(sizeof(char)*MARKA);
    temp->nastepny=NULL;
    return temp;
}

void wyswietl(samochod *first)
{
    if (first==NULL)
    {
        printf("\nLista jest pusta.");
    }

    else
    {
        printf("Marka\tmodel\tcena\tprzebieg\n");
        printf("-------------------------\n");
        do
        {
            printf("%d\t%s\t%s\t%d\t%d\n",first,first->marka,first->model,first->cena,first->przebieg);
            first=first->nastepny;
        }
        while(first!=NULL);
        printf("-------------------------\n");
    }
}

#endif // STRUKTURA_H_INCLUDED
