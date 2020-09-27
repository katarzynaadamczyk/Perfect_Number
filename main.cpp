#include "Tnumberfractions.h"

#include <time.h>
#include <stdio.h>

using namespace std;

int main()
{
    cout << "Witaj w programie PERFECT NUMBER & BUDDY PAIR" << endl;
    long long a {}, n {1000};
    clock_t czaspocz, czaskonc;
    while (n>0)
    {
        cout << "Podaj liczbe, ktora mam sprawdzic czy jest \"perfect number\"" <<endl;
        cin >> n;
        cout << endl;
        if (n > 0)
        {
            czaspocz = clock();
            Tnumberfractions::perfect_number_v1(n);
            czaskonc = clock();
            cout << "Czas trwania algorytmu 1 to: " << (czaskonc - czaspocz) << endl;
            if (Tnumberfractions::perfect_number_v1(n))
            {
                cout << "Liczba " << n << " jest \"perfect number\"" << endl;
            }
            else
            {
                cout << "Liczba " << n << " nie jest \"perfect number\"" << endl;
            }

            czaspocz = clock();
            Tnumberfractions::perfect_number_v2(n);
            czaskonc = clock();
            cout << "Czas trwania algorytmu 2 to: " << (czaskonc - czaspocz) << endl;
            if (Tnumberfractions::perfect_number_v2(n))
            {
                cout << "Liczba " << n << " jest \"perfect number\"" << endl;
            }
            else
            {
                cout << "Liczba " << n << " nie jest \"perfect number\"" << endl;
            }


            cout << "Szukamy przyjaciol. Podaj dolna czesc zakresu" <<endl;
            cin >> a;
            cout << "Szukamy przyjaciol. Podaj gorna czesc zakresu" <<endl;
            cin >> n;
            string wynik = Tnumberfractions::buddy_pair(a,n);
            cout<<"Dla a = "<<a<<" i b = "<<n<<" wynkiem jest: \""<<wynik<<"\"."<<endl;

            //tutaj cialo petli - dalsza czesc do uzupelnienia po zrobieniu funkcji buddy pair
        }

    }
    return 0;
}