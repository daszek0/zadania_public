// Jakub Daszkiewicz
// zadanie Ładny łańcuch
//
// test 1: 7 3 2 1 1 1 2 3 4 2 1 3 1 2 5 => 2

#include <stdio.h>

using namespace std;

bool exists_in_a(int a[], int l, int check)
{
    for (int i=0; i<l; i++)
        if (a[i] == check) return true;
    return false;
}

bool array_comp(int a1[], int a2[], int l)
{
    for (int i=0; i<l; i++)
    {
        if (a1[i] != a2[i]) return false;
    }
    return true;
}

void zero_a(int a[], int l)
{
    for (int i=0; i<l; i++)
    {
        a[i] = 0;
    }
}

int main()
{
    int n, m;
    unsigned long long r = 0;
    scanf("%d %d", &n, &m);
    int l[m], c[m], sl = 0, a[n], cl[1000001] = {0}, cl_check[1000001] = {0};
    for (int i=0; i<m; i++)
    {
        scanf("%d", &l[i]);
        sl += l[i];
    }
    for (int i=0; i<m; i++)
    {
        scanf("%d", &c[i]);
    }

    for (int i=0; i<m; i++)
    {
        cl[c[i]] = l[i];
    }

    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    int begin = -1;

    /*
    // wypisywanie tablicy
    for (int i=0; i<=10; i++)
    {
        printf("%d ", cl[i]);
    }
    printf("\n");
    */
    
    // trzeba zapętlić
    while (begin+sl < n)
    {
        for (int i=begin+1; i<n; i++)
        {
            if (exists_in_a(c, m, a[i]))
            {
                begin = i;
                break;
            }
        }
        for (int i=begin; i-begin<sl; i++)
        {
            cl_check[a[i]]++;
        }

        if (array_comp(cl, cl_check, 1000001)) r++;

        zero_a(cl_check, 1000001); // cl_check[1000001] = {0};

    }
    // koniec

    printf("%llu", r);

    return 0;
}