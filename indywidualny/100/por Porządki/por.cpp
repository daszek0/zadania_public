// Jakub Daszkiewicz
// zadanie Porządki

#include <cstdio>
#include <bitset>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int s[200000];
    bitset<200000> r;
    r.reset();
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        s[i]--;
        if (s[i] != i)
            r[i] = true;
    }
    int t, x, y;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        swap(s[x], s[y]);
        if (s[x] != x)
            r[x] = true;
        else
            r[x] = false;
        if (s[y] != y)
            r[y] = true;
        else
            r[y] = false;
        if (r.none())
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}