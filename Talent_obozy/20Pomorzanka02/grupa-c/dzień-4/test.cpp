// Jakub Daszkiewicz
// zadanie 

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // ram test
    int tab[500000];
    for (int i=0; i<500000; i++)
    {
        tab[i] = i+2137;
    }

    getchar();

    // sort test
    // pair<int, int> tab[10];
    // for (int i=0; i<10; i++)
    // {
    //     scanf("%d %d", &tab[i].first, &tab[i].second);
    // }
    // sort(tab, tab+10);
    // for (int i=0; i<10; i++)
    // {
    //     printf("%d %d\n", tab[i].first, tab[i].second);
    // }
    return 0;
}