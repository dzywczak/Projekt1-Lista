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
    void dodaj(int a);
    void usun(int a);
};


int main()
{
    /*wskaźniki
    int *zmienna = new int;
    *zmienna = 5;
    cout << *zmienna << endl;
    */
    Lista listonosz;
    listonosz.dodaj(4); // <- trzeci element 
    cout << listonosz.pierwszy->wartosc << endl;
    listonosz.dodaj(10); // <- drugi element
    cout << listonosz.pierwszy->wartosc << endl;
    listonosz.dodaj(18);// <- pierwszy element
    cout << listonosz.pierwszy->wartosc << endl;
    listonosz.dodaj(20);
    cout << listonosz.pierwszy->wartosc << endl;
    
    
}

Lista::Lista()
{
    //nie jest nic wskazywane
    pierwszy = nullptr;
    ostatni = nullptr;
}

Lista::~Lista(){};

void Lista::dodaj(int a)
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

void Lista::usun(int a)
{
}
