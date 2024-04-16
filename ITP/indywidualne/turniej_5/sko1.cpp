// Jakub Daszkiewicz
// zadanie Skoki narciarskie

#include <stdio.h>

using namespace std;

int a_min(float tab[], int s)
{
    float ch = 1000000;
    int ret;
    for (int i=0; i<s; i++)
    {
        if (tab[i] < ch)
        {
            ch = tab[i];
            ret = i;
        }
    }
    return ret;
}

int a_max(float tab[], int s)
{
    float ch = 0;
    int ret;
    for (int i=0; i<s; i++)
    {
        if (tab[i] > ch)
        {
            ch = tab[i];
            ret = i;
        }
    }
    return ret;
}

int main()
{
    float d;
    int k;
    float n[5];
    int bs, bk;
    float w;
    scanf("%f", &d);
    scanf("%d", &k);
    for (int i=0; i<5; i++) scanf("%f", &n[i]);
    scanf("%d %d", &bs, &bk);
    scanf("%f", &w);
    long double r = 60;
    r += (d-k)*1.8;
    n[a_min(n, 5)] = 0;
    n[a_max(n, 5)] = 0;
    return 0;
}