// Jakub Daszkiewicz
// zadanie K największych

#include <stdio.h>
#include <algorithm>

#define uzywaj using
#define przestrzen_nazw namespace
#define standardowa std
#define liczba_naturalna int
#define glowna main
#define skanujf scanf
#define drukujf printf
#define dla for
#define sortuj sort
#define odwroc reverse
#define zwroc return

uzywaj przestrzen_nazw standardowa;

liczba_naturalna glowna()
{
    liczba_naturalna l, k;
    skanujf("%d %d", &l, &k);
    liczba_naturalna n[l];
    dla (liczba_naturalna i=0; i<l; i++)
    {
        skanujf("%d", &n[i]);
    }
    sortuj(n, n+l);
    odwroc(n, n+l);
    dla (liczba_naturalna i=0; i<k; i++)
    {
        drukujf("%d\n", n[i]);
    }
    zwroc 0;
}