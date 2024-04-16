#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int liczba, r = 2;
    scanf("%d", &liczba);

    vector<int> bierka;
    for (int i=0; i<liczba; i++)
    {
        int t;
        scanf("%d", &t);
        bierka.push_back(t);
    }
    sort(bierka.begin(), bierka.end());
    int p = liczba-2;
    //for (int i=0; i<liczba; i++) printf("%d\n", bierka[i]); // sprawdzenie sorta
    for (int i=liczba-1; i>=0; i--)
    {
        while (bierka[p]+bierka[p-1] > bierka[i])
        {
            if (p-1 < 0)
            {
                break;
            }
            --p;
            if (i-p+1 > r)
                r = i-p+1;
        }
    }

    printf("%d", r);

    return 0;
}
