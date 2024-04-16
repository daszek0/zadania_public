// Jakub Daszkiewicz
// zadanie Dowolna linia

#include <stdio.h>
#include <algorithm>
#include <vector>

#define ff first
#define ss second

using namespace std;

struct dist
{
    int d, a, b, p; // odległość równolegle do osi, punkt od, punkt do, odległość po Pitagorasie²
};

int cd(pair <int, int> p0, pair <int, int> p1) // obliczenie odległości równolegle do osi
{
    return abs(p0.ff - p1.ff) + abs(p0.ss - p1.ss);
}

int cp(pair <int, int> p0, pair <int, int> p1) // obliczenie kwadratu odległości w linii prostej
{
    return abs(p0.ff - p1.ff) * abs(p0.ff - p1.ff) + abs(p0.ss - p1.ss) * abs(p0.ss - p1.ss);
}

bool sv(dist d0, dist d1) // do sortowania połączeń
{
    if (d0.d == d1.d) return d0.p > d1.p; // jeśli odległość równolegle do osi równa, znaczenie ma odległość w linii prostej
    return d0.d > d1.d; // sortowanie po odległości równolegle do osi
}

int main()
{
    int n, a = 0;
    scanf("%d", &n); // liczba punktów
    pair <int, int> p[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &p[i].ff, &p[i].ss); // wczytanie punktów
    }
    vector <dist> d;
    dist t; // do wrzucania na vector
    for (int i=0; i<n; i++) // sprawdzenie odległości każdego z każdym po numerach w kolejności wczytania, wrzucenie na vector
    {
        for (int j=i+1; j<n; j++)
        {
            t.d = cd(p[i], p[j]);
            t.a = i;
            t.b = j;
            t.p = cp(p[i], p[j]);
            d.push_back(t);
        }
    }
    sort(d.begin(), d.end(), sv); // sortowanie
    int b[n], bb[3], c[n], cn = 0, f, s; // kubełki na połączenia z punktu, kubełki na liczbę wystąpień liczby połączeń, spójna punktu, spójna bieżąca, zmienne pomocnicze
    fill(c, c+n, 0);
    fill(b, b+n, 0);
    bb[0] = n;
    bb[1] = 0;
    bb[2] = 0;
    while (bb[0] != 0 || bb[1] != 2 || bb[2] != n-2) // kiedy nie mamy przypisanych po 1 krawędzi do 2 punktów i po 2 do reszty
    {
        f = d[d.size()-1].a;
        s = d[d.size()-1].b;
        if (b[f] < 2 && b[s] < 2 && !(b[f] == 1 && b[s] == 1 && c[f] == c[s])) // jeżeli są <2 połączenia, jeśli po 1, to punkty muszą być w różnych spójnych
        {
            // przypisywanie do spójnych
            if (b[f] == 0 && b[s] == 0) // jeżeli nie ma żadnych połączeń z punktów
            {
                cn++; // nowa spójna
                c[f] = cn;
                c[s] = cn;
            }
            if (c[f] == 0 || c[s] == 0) // nie ma połączenia z 1 punktu, dopisanie do spójnej drugiego
            {
                if (c[f] == 0) c[f] = c[s];
                else c[s] = c[f];
            }
            if (c[f] != c[s]) // różne spójne, połączenie spójnych
            {
                for (int i=0; i<n; i++)
                {
                    if (i == s) continue;
                    if (c[i] == c[s]) c[i] = c[f];
                }
                c[s] = c[f];
            }
            // przypisanie krawędzi, kubełkowanie
            bb[b[f]]--;
            b[f]++;
            bb[b[f]]++;
            bb[b[s]]--;
            b[s]++;
            bb[b[s]]++;
            a += d[d.size()-1].d; // dodanie do wyniku
        }
        d.pop_back();
    }
    printf("%d", a); // wypisanie wyniku
    return 0;
}