// Jakub Daszkiewicz
// zadanie Kolejka do sklepu
// czas O(n²)

#include <stdio.h>
#include <algorithm>

using namespace std;

void fastinput(int *i) // szybkie wczytywańsko
{
    int r = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked();
    while (c >= '0' && c <= '9')
    {
        r = (r << 3) + (r << 1) + c - '0';
        c = getchar_unlocked();
    }
    *i = r;
}

int main()
{
    int q;
    fastinput(&q);
    int n, t;
    for (int p=0; p<q; p++)
    {
        fastinput(&n);
        int pos[n];
        fill(pos, pos + n, -1);
        for (int i=0; i<n; i++)
        {
            fastinput(&t);
            for (int j=0; j<n; j++)
            {
                if (pos[j] >= t) pos[j]++;
            }
            pos[i] = t;
        }
        for (int i=0; i<n; i++)
        {
            printf("%d ", pos[i] + 1);
        }
        printf("\n");
    }
    return 0;
}