#ifndef TNUMBERFRACTIONS_H
#define TNUMBERFRACTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>

class Tnumberfractions
{
    public:
        Tnumberfractions();
        virtual ~Tnumberfractions();

        //zadanie Daily Interview - PERFECT NUMBER
        static bool perfect_number_v1(long long n);
        static bool perfect_number_v2(long long n);

        //zadanie KATA - BUDDY PAIR - to moge tez zrobic zwracajac cos innego - na przyklad jakis set czy cos
        static std::string buddy_pair(long long a, long long b);

    protected:

    private:
        //wspolne funkcje

        //funkcja podajaca wszystkie dzielniki danej liczby
        static std::vector<long long> divisors_v1(const long long a);
        static std::vector<long long> divisors_v2(const long long a);

        //funkcja sumujaca wektor
        static long long vector_sum(std::vector<long long> && wektor);
        static long long vector_sum(std::vector<size_t> & wektor);

        //funkcja wypisujaca wektor na ekran
        static void wypisz_wektor(const std::vector<long long> & wektor);
        static void wypisz_wektor(const std::vector<std::vector<long long>> & wektor);
        static void wypisz_wektor(const std::vector<size_t> & wektor);

        //funkcja potegujaca liczbe
        static long long power(long long p, int how);

        //funkcja pierwiastkujaca liczbe
        static long long squareroot (long long n);

        //funkcja dodajaca w odpowiednie miejsce wektora dana liczbe
        static void insert_to_vector(long long add, std::vector<long long> & wektor);

        //funkcja sortujaca wektor
        static void sort_vector(std::vector<long long> & wektor);

        //liczba iteracji dla sprawdzenia
        static unsigned long long licz_iter;
};

#endif // TNUMBER