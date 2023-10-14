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
    void wyswietl();
    void indeksd(int b, int indeks);
    void usunp();
    void usunk();
    void usunindeks(int indeks);
    void wyswietlodwrtn();
};


int main()
{
    /*wskaźniki
    int *zmienna = new int;
    *zmienna = 5;
    cout << *zmienna << endl;
    */
cout << "Wyswietlenie listy z elementami dodanymi na poczatku listy i koncu:" << endl;

Lista listonosz;
listonosz.dodajk(65); //element dodawany na koniec listy 
listonosz.dodajp(34); //element dodawany na poczatek listy
listonosz.dodajp(12);
listonosz.dodajk(99);
listonosz.wyswietl();

cout << endl;
cout << "Wyswietlenie listy w odwrotnej kolejnosci:" << endl;

listonosz.wyswietlodwrtn();

cout << endl;
cout << "Wyswietlenie listy z elementem dodanym pod wskazany indeks:" << endl;

int wartosci = 98;
int indeks = 1;
listonosz.indeksd(wartosci, indeks); //dodanie elementu pod wskazany indeks
listonosz.wyswietl();

cout << endl;
cout << "Wyswietlenie listy z usunieciem pierwszego i ostatniego elementu:" << endl;

listonosz.usunp(); //usuwanie pierwszego elementu
listonosz.usunk();
listonosz.wyswietl();

cout << endl;
cout << "Wyswietlenie listy z usunieciem elementu po wpisaniu indeksu:" << endl;

int indeksik = 0;
listonosz.usunindeks(indeksik);//usuniecie elementu po wpisaniu indeksu
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
//metoda do dodawania elementu na koniec
void Lista::dodajk(int a)
{
    zmienna* nodes = new zmienna;
    nodes -> wartosc = a;
    nodes->poprzedni = nullptr;
    nodes -> nastepny = nullptr; //nullptr ze nie wskazuje na zaden element
    if(pierwszy == nullptr) { //sprawdzamy czy pierwszy wskazuje na nullptr
        pierwszy = nodes;
        ostatni = nodes;
    }
    else {
        ostatni -> nastepny = nodes;
        nodes->poprzedni = ostatni;
        ostatni = nodes;
    }
    liczenie++;
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

//metoda do dodawaniu elementu listy pod wskazany indeks
void Lista::indeksd(int b, int indeks){

   if(indeks < 0 || indeks > liczenie) { //sprawdzamy czy podany indeks jest prawidłowy              
        cout << "Błąd" << endl;           //ma nie byc mniejszy niz 0 i nie przekraczac liczby elementow w liscie
    }
    zmienna* element = new zmienna; //nowy element dodany do listy
    element->wartosc = b;
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
    }
}
//metoda do usuwania pierwszego elementu listy
void Lista::usunp()
{
if(pierwszy == nullptr)
{
    cout << "Lista aktualnie jest pusta" << endl;
    return;
}
zmienna* usunpoczatek = pierwszy; //tworzenie wskaznika
pierwszy = pierwszy->nastepny; //przesuniecie wskaznika na pierwszy element na nastepny
delete usunpoczatek;
if (pierwszy != nullptr) {
    pierwszy->poprzedni = nullptr; //Ustawienie wskaźnika poprzedniego pierwszego elementu na nullptr
}
}

//metoda do usuwania ostatniego elementu listy
void Lista::usunk()
{ 
    if(ostatni == nullptr)
    {
        cout <<"Brak" << endl;
        return;
    }
    zmienna* usunkoniec = ostatni; //stworzenie wskaźnika
    ostatni = ostatni->poprzedni; //przesuniecie wskaznika z ostatniego na poprzedni
    delete usunkoniec;
    if(ostatni != nullptr)
    {
        ostatni->nastepny = nullptr;
    }
}
//metoda do usuwania elementu po wskazaniu indeksu
void Lista::usunindeks(int indeks)
{
    if (indeks < 0 || indeks >= liczenie)
    {
        cout << "Błąd" << endl;
        return;
    }
    zmienna* element = pierwszy; //wskaznik
    for (int i = 0; i < indeks; i++) //pętla odpowiadajaca za przesuniecie wskaznika na element o podanym indeksie
    {
        element = element->nastepny;
    }

    if (element->poprzedni)
    {
        element->poprzedni->nastepny = element->nastepny; //przypisanie 
    }
    else
    {
        pierwszy = element->nastepny; //przypisanie pierwszy element wskazywany na nastepny
        pierwszy->poprzedni = nullptr; //pierwszy wskazuje na poprzedni i przypisuje mu wartosc nullptr
    }

    if (element->nastepny)
    {
        element->nastepny->poprzedni = element->poprzedni;
    }
    else
    {
        ostatni = element->poprzedni;
    }

    delete element;
    liczenie--;
}
//metoda wyświetlająca liste w odwrotnej kolejnosci
void Lista::wyswietlodwrtn()
{
    zmienna* obecny = ostatni;
    while(obecny != nullptr) {
        cout << obecny->wartosc << " ";
        obecny = obecny->poprzedni;

}
}
