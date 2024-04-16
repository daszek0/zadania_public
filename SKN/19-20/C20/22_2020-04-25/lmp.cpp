// Jakub Daszkiewicz
// zadanie Lampki

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    bool l[h][w];
    char t;
    for (int x=0; x<h; x++)
    {
        getchar_unlocked();
        for (int y=0; y<w; y++)
        {
            t = getchar_unlocked();
            if (t == '0') l[x][y] = 0;
            else l[x][y] = 1;
        }
    }
    bool cc[w];
    fill(cc, cc+w, 0);
    bool cr;
    int r = 0;
    for (int x=0; x<h; x++)
    {
        cr = 0;
        for (int y=w-1; y>=0; y--)
        {
            if (l[x][y] ^ cc[y] ^ cr == 0)
            {
                r++;
                cc[y] ^= 1;
                cr ^= 1;
            }
        }
    }
    printf("%d", r);
    return 0;
}