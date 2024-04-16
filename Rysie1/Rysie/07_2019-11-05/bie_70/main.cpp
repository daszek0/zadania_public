#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int liczba, r = 2, r1 = 2;
    scanf("%d", &liczba);

    vector<int> bierka;
    vector<int> bierka1;
    for (int i=0; i<liczba; i++)
    {
        int t;
        scanf("%d", &t);
        bierka.push_back(t);
        bierka1.push_back(t);
    }
    sort(bierka.begin(), bierka.end());
    sort(bierka1.begin(), bierka1.end());
    //for (int i=0; i<liczba; i++) printf("%d\n", bierka[i]); // sprawdzenie sorta
    for (int i=0; i<liczba-2; i++) // od normalnej strony
    {
        if (bierka[0] + bierka[1] > bierka[bierka.size()-1])
        {
            bierka.erase(bierka.begin());
            ++r;
        }
        else
        {
            bierka.erase(bierka.begin());
        }
    }

    for (int i=0; i<liczba-2; i++) // od dupy strony
    {
        if (bierka1[0] + bierka1[1] > bierka1[bierka1.size()-1])
        {
            bierka1.pop_back();
            ++r1;
        }
        else
        {
            bierka1.pop_back();
        }
    }

    printf("%d", max(r, r1));

    return 0;
}
