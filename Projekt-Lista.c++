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

void Lista::dodajk(int a)
{
    zmienna* nodes = new zmienna;
    nodes -> wartosc = a;
    nodes -> nastepny = nullptr;
    if(!pierwszy) {
        pierwszy = nodes;
        ostatni = nodes;
        nodes->poprzedni = nullptr;
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

void Lista::wyswietl()
{
    zmienna* obecna = pierwszy;
    while(obecna != nullptr) {
        cout << obecna->wartosc << " ";
        obecna = obecna->nastepny;
    }
}
