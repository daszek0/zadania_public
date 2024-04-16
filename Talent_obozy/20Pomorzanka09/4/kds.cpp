// Jakub Daszkiewicz
// zadanie Kolejka do sklepu

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10; // 100000
int tree[1 << 18];
int st;

void move(int a, int b)
{
    if (a > b) swap(a, b);
    a += st;
    b += st;
    while (a < b)
    {
        if (a & 1)
        {
            tree[a]++;
            a >>= 1;
            a++;
        }
        else a >>= 1;
        if (b & 1) b >>= 1;
        else
        {
            tree[b]++;
            b >>= 1;
            b--;
        }
    }
    if (a == b) tree[a]++;
}

int check(int p)
{
    int r = 0;
    p += st;
    while (p)
    {
        r += tree[p];
        p >>= 1;
    }
    return r;
}

int main()
{
    int q;
    scanf("%d", &q);
    int n;
    int pip[N]; // person - initial position
    vector <int> ipp[N]; // initial position - person
    for (int p=0; p<q; p++)
    {
        fill(tree, tree + (1 << 18), 0);
        st = 1;
        scanf("%d", &n);
        while (st < n)
        {
            st <<= 1;
        }
        for (int i=0; i<n; i++)
        {
            scanf("%d", &pip[i]);
            // tree[st + i] = pip[i];
            if (!ipp[pip[i]].empty()) move(ipp[pip[i]].back(), i - 1);
            ipp[pip[i]].push_back(i);
        }
        for (int i=0; i<n; i++)
        {
            printf("%d ", check(pip[i]) + pip[i]);
        }
        printf("\n");
    }
    return 0;
}