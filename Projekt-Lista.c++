#include <iostream>
using namespace std;

class Lista{
    public:
    struct zmienna{
        int wartosc;
        zmienna* nastepny;
        zmienna* poprzedni;
        //wskazniki na nastepny i poprzedni element
    };
    //wskaźniki na pierwszy i ostatni element listy
    zmienna* pierwszy;
    zmienna* ostatni;
    
    int liczenie;

    public:
    Lista();
    ~Lista();
    void dodajp(int a);
    void dodajk(int a);
    void usun(int a);
    void wyswietl();
    void indeksd(int b, int indeks);
};


int main()
{
    /*wskaźniki
    int *zmienna = new int;
    *zmienna = 5;
    cout << *zmienna << endl;
    */

Lista listonosz;
listonosz.dodajk(65); //element dodawany na koniec listy 
listonosz.dodajp(34); //element dodawany na poczatek listy
listonosz.dodajp(12);
listonosz.wyswietl();


int wartosci = 90;
int indeks = 1;

listonosz.indeksd(wartosci, indeks);






return 0;

    
}

Lista::Lista()
{
    //nie jest nic wskazywane
    pierwszy = nullptr;
    ostatni = nullptr;
}

Lista::~Lista(){};

//dodawanie na poczatek listy
void Lista::dodajp(int a)
{
    //element listy na stercie
    zmienna* node = new zmienna;
    node -> wartosc = a;
    node -> nastepny = pierwszy;
    node -> poprzedni = nullptr;
    //odniesienie

    //lista nie jest pusta
    if (pierwszy != nullptr) 
    {
        //pierwszy element musi sie przesunac w prawo i wchodzi node
        pierwszy -> poprzedni = node;
    }
    else {
        ostatni = node;
    }
    pierwszy = node;
    liczenie++;
}
//metoda do dodawania elementu na koniec
void Lista::dodajk(int a)
{
    zmienna* nodes = new zmienna;
    nodes -> wartosc = a;
    nodes -> nastepny = nullptr; //nullptr ze nie wskazuje na zaden element
    if(pierwszy != nullptr) { //sprawdzamy czy pierwszy wskazuje na nullptr
        pierwszy = nodes;
        ostatni = nodes;
        nodes->poprzedni = nullptr; //przypisanie wskaznikowi poprzedni wartosc nullptr
    }
    else {
        nodes -> poprzedni = ostatni;
        ostatni -> nastepny = nodes;
        ostatni = nodes;
    }
    liczenie++;
}

void Lista::usun(int a)
{
}

//metoda do wyswietlania
void Lista::wyswietl()
{
    zmienna* obecna = pierwszy;
    while(obecna != nullptr) {
        cout << obecna->wartosc << " ";
        obecna = obecna->nastepny;
    }
}


void Lista::indeksd(int b, int indeks){};

   /* if(indeks < 0 || indeks > liczenie) { //sprawdzamy czy podany indeks jest prawidłowy              
        cout << "Błąd" << endl;           //ma nie byc mniejszy niz 0 i nie przekraczac liczby elementow w liscie
    }
    zmienna* element = new zmienna; //nowy element dodany do listy
    element->wartosc = a;
    if (indeks == 0) {
        element->nastepny = pierwszy; //wskazanie na obecnie pierwszy element
        element->poprzedni = nullptr; //ustawienie wskaznika nowego elementu na nullptr bo ten element nie ma poprzednika
        pierwszy -> poprzedni = element; //uaktualnienie wskaźnika pierwszy na nowy element aby wskazywał na nowy pierwszy element listy
        pierwszy = element; //element jest teraz pierwszy 
        liczenie++;
        return;
    }
    else {
        zmienna* obecna = pierwszy;
        for(int i=0; i < indeks -1; i++)
        {
            obecna = obecna -> nastepny;
        }
        element -> nastepny = obecna -> nastepny;
        element -> poprzedni = obecna;
        if (obecna->nastepny)
        {
            obecna->nastepny->poprzedni = element;
        }
        obecna->nastepny = element;
        liczenie++;
        return;
    }*/

