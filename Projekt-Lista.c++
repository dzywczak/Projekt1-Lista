#include <iostream>
using namespace std;

class Lista{
    private:
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
        pierwszy = node;
    }
    pierwszy = node;
    liczenie++;
}

void Lista::usun(int a)
{
}
