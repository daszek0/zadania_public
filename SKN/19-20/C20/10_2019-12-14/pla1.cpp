// Jakub Daszkiewicz
// zadanie Plansza

#include <stdio.h>

using namespace std;

int main()
{
    int n, m;
    unsigned long long r = 0;
    scanf("%d%d", &n, &m); getchar_unlocked();
    bool board[n][m] = {};
    char t;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            t = getchar_unlocked();
            if (t == '#')
            {
                board[i][j] = 1;
            }
        }
        getchar_unlocked();
    }
    int k, l;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (!board[i][j])
            {
                r++;
                k = j;
                l = i;
                
            }
        }
    }
    return 0;
}