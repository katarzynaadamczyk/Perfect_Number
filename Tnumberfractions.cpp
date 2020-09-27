#include "Tnumberfractions.h"

using namespace std;

//*****************************************************************************
//to dodal kompilator

Tnumberfractions::Tnumberfractions()
{
    //ctor
}

Tnumberfractions::~Tnumberfractions()
{
    //dtor
}


//*****************************************************************************
//*****************************************************************************
//ustawienie poczatkowej wartosci danej liczby iteracji

unsigned long long Tnumberfractions::licz_iter = 0;

//*****************************************************************************
//najpierw definicje wspolnych funkcji / prywatnych funkcji

//*****************************************************************************
//funkcje wypisujace wektory na ekran - pomocnicze funkcje


void Tnumberfractions::wypisz_wektor(const vector<long long> & wektor)
{

    cout << "oto wektor: " << endl ;
    for (auto & a : wektor)
        cout << setw(10) << a << endl ;
    cout << "koniec, a wektor.size() = " << wektor.size() << endl ;
}

void Tnumberfractions::wypisz_wektor(const vector<size_t> & wektor)
{

    cout << "oto wektor: " << endl ;
    for (auto & a : wektor)
        cout << setw(10) << a << endl ;
    cout << "koniec, a wektor.size() = " << wektor.size() << endl ;
}

void Tnumberfractions::wypisz_wektor(const vector<vector<long long>> & wektor)
{

    cout << "oto wektor: " << endl ;
    for (size_t i = 0; i<wektor.size(); i++)
    {
        cout << setw(5) << i <<": ";
        for (auto & a : wektor[i])
            cout << setw(10) << a << "\t" ;
        cout << endl;
    }
    cout << "koniec" << endl ;
}

//*****************************************************************************
//funkcja sumujaca zawartosc wektora 1D

long long Tnumberfractions::vector_sum(vector<long long> && wektor)
{
    long long sum {};
    for (auto & a : wektor)
        sum += a;
    return sum;
}

long long Tnumberfractions::vector_sum(vector<size_t> & wektor)
{
    long long sum {};
    for (auto & a : wektor)
        sum += a;
    return sum;
}

//*****************************************************************************
//funkcja zwracajaca wszystkie dzielniki danej liczby a w formie wektora
//wersja 1 - najpierw funkcja robi wektor 2D dzielnikow bedacych liczbami pierwszymi i ich potegami a potem mnozy je przez siebie w odpowiedni sposob
//i wypluwa wektor dzielnikow

vector<long long> Tnumberfractions::divisors_v1(const long long a)
{
    vector<long long> pom;
    pom.push_back(1);
    vector<vector<long long>> data;
    data.push_back(pom);

    long long n {a};
    for (long long div = 2; div<4; div++)
    {
        if (n % div == 0)
        {
            int ile {1};
            pom.clear();
            pom.push_back(1);
            while (n % div == 0)
            {
                if (power(div,ile)<a)
                {
                    pom.push_back(power(div,ile));
                }
                n /= div;
                ile++;
            }
            data.push_back(pom);
        }
    } // w tym miejscu w wektorze mamy dodane wszystkie potegi 2 i 3, przez ktore dzieli sie n w wektorze 2D

    //teraz dodajemy pozostale liczby pierwsze
    long long maks {}, pop {1}, div{};
    while (n>1)
    {
        div = squareroot(n);
        maks = div / 6 + 1;
        for (long long k = pop; pop <= maks; k++)
        {
            if (n % (6 * k - 1) == 0)
            {
                pop = k;
                div = 6 * k - 1;
                break;
            }
            if (n % (6 * k + 1) == 0)
            {
                pop = k;
                div = 6 * k + 1;
                break;
            }
        }
        if (n % div == 0)
        {
            int ile {1};
            pom.clear();
            pom.push_back(1);
            while (n % div == 0)
            {
                if (power(div,ile)<a)
                {
                    pom.push_back(power(div,ile));
                }
                n /= div;
                ile++;
            }
            data.push_back(pom);
        }
        else
        {
            if (n<a)
            {
                pom.clear();
                pom.push_back(1);
                pom.push_back(n);
                data.push_back(pom);
            }
            n /= n;
        }
    } // tutaj mamy wszystkie liczby pierwsze i ich potegi w wektorze

     // mnozenie co najmniej dwoch liczb
    size_t maks_st {data.size()}, it;
    vector<size_t> xx(maks_st,0); // ustawienie wszystkich liczb na 1
    pom.clear();

    while (true)
    {
        long long wynik {1};
        for (size_t i = 0; i<maks_st; i++)
        {
            wynik *= data[i][xx[i]];
        }
        if (wynik < a && a % wynik == 0)
            pom.push_back(wynik);

        it = maks_st - 1;
        while (it < maks_st && xx[it] == data[it].size()-1)
        {
            xx[it] = 0;
            it--;
        }
        if (it>=maks_st || it == 0)
            break;
        xx[it]++;
    }
/*
    cout << "pod koniec funkcji : " << endl;
    cout << "wektor pom: " <<endl;
    wypisz_wektor(pom);
*/
    return pom;
}

//*****************************************************************************
//funkcja zwracajaca wszystkie dzielniki danej liczby a w formie wektora
//wersja 2 - funkcja leci po liczbach az do pierwiastka z liczby a i w ten sposob robi liste dzielnikow

vector<long long> Tnumberfractions::divisors_v2(const long long a)
{
    long long maks {squareroot(a)};
    vector<long long> wynik;
    for (long long i = 1; i<=maks; i++)
    {
        if (a % i == 0 && i<a)
        {
            wynik.push_back(i);
            if (a/i<a && i*i!=a)
                wynik.push_back(a/i);
        }
    }
/*
    cout<<"Wypis wektora z funkcji v2" <<endl;
    wypisz_wektor(wynik);
*/
    return wynik;
}


//*****************************************************************************
//funkcja dodajaca liczby do wektora w odpowiednie miejsce - na razie niepotrzebna

void Tnumberfractions::sort_vector(vector<long long> & wektor)
{

}

//*****************************************************************************
//funkcja potegujaca

long long Tnumberfractions::power(long long p, int how)
{
    long long wynik {1};
    for (int i = 0; i<how; ++i)
        wynik *=p;
    return wynik;
}

//*****************************************************************************
//funkcja pierwiastkujaca

long long Tnumberfractions::squareroot (long long n)
{
    unsigned short int ile_zer {};
    long long wn {n};
    while (wn)
    {
        ile_zer++;
        wn /= 10;
    }
    long long minimum {1};
    for (unsigned short int i = 0; i<(ile_zer /2 - 1); ++i)
    {
        minimum *= 10;
    }
    long long maks {minimum * 100};
    long long srednia = (minimum + maks)/2;

    if (srednia * srednia == n)
        {
            return srednia;
        }
        else if (minimum * minimum == n)
            {
                return minimum;
            }
            else if (maks * maks == n)
                {
                    return maks;
                }
    while (!(((srednia * srednia) <= n) && (((srednia + 1) * (srednia + 1)) > n)))
    {

        if (n > srednia * srednia)
        {
          minimum = srednia;
        }
        else
        {
            maks = srednia;
        }
        srednia = (minimum + maks)/2;
       // cout << "srednia : " << srednia << ", min : " << minimum <<", maks : "<<maks << endl;
    }
    return srednia;
}

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//zadanie Daily Interview - PERFECT NUMBER

bool Tnumberfractions::perfect_number_v1(long long n)
{
    if (vector_sum(divisors_v1(n)) == n)
        return true;
    return false;
}

bool Tnumberfractions::perfect_number_v2(long long n)
{
    if (vector_sum(divisors_v2(n)) == n)
        return true;
    return false;
}

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//zadanie KATA - BUDDY PAIR
//- moze to tez zrobic tak, zeby wynikiem byla para


string Tnumberfractions::buddy_pair(long long a, long long b)
{
    //ustawienie odpowiednich zakresow
    if (a>b)
    {
        long long pom = b;
        b = a;
        a = pom;
    }

    //wektor dla memoization
    vector<long long> data;
    data.resize(b+1,0);

    bool znaleziono {false};
    long long i {a}, suma1, suma2;
    string wynik;
    while (!znaleziono && i <= b)
    {
  //      cout<<"i = "<<i<<endl;
        if (data[i]==0)
        {
            data[i] = vector_sum(divisors_v2(i));
        }
  //      cout<<"data[i] = "<<data[i]<<endl;
        if (data[i]>data.size())
        {
            data.resize(data[i]+1,0);
        }
        if (data[i]-1>0 && data[data[i]-1]==0)
            data[data[i]-1] = vector_sum(divisors_v2(data[i]-1));

   //     cout<<"data[data[i]-1]  = "<<data[data[i]-1] <<endl;
        if ((data[data[i]-1]==(i+1)))
            znaleziono = true;
        ++i;
    }

    if (znaleziono)
    {
        if ((i-1)<(data[i-1]-1))
            wynik = "(" + to_string(i-1) + " " + to_string(data[i-1]-1) + ")";
        else
            wynik = "(" + to_string(data[i-1]-1) + " " + to_string(i-1) + ")";
    }
    else
    {
        wynik = "Nothing";
    }

    return wynik;
}