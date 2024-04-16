// Jakub Daszkiewicz
// zadanie Najbardziej wartościowa moneta

#include <stdio.h>

using namespace std;

int n;
bool c[201739];
int t;

void push(int a)
{
    if (c[a] == 0) c[a] = 1;
    else 
    {
        c[a] = 0;
        push(a + 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        push(t);
    }
    for (int i=201738; i>=0; i--)
    {
        if (c[i] == 1)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}