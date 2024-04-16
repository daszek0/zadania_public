#include <stdio.h>

using namespace std;

bool coin[202001];

void push_tab(int index)
{
    if (coin[index] == 1)
    {
        coin[index] = 0;
        push_tab(index+1);
    }
    else
    {
        coin[index] = 1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        int t;
        scanf("%d", &t);
        push_tab(t);
    }
    for (int i=202000; i>=0; --i)
    {
        if (coin[i] == 1)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}