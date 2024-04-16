// Jakub Daszkiewicz
// zadanie Kolejka do sklepu

#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 100000; // 100000

int n, p[N], inp[N];

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

int offset(int t, int it)
{
    if (check(t) < check(it + check(t))) return offset(t + check(it), it);
    else return check(t);
}



int main()
{
    int q;
    scanf("%d", &q);
    for (int i=0; i<q; i++)
    {
        fill(tree, tree + (1 << 18), 0);
        st = 1;
        // fill(o, o + N, 0);
        scanf("%d", &n);
        while (st < n)
        {
            st <<= 1;
        }
        for (int i=0; i<n; i++)
        {
            scanf("%d", &inp[i]);
        }
        for (int i=n-1; i>=0; i--)
        {
            p[i] = inp[i] + offset(inp[i], inp[i]) /* + check(inp[i]] */;
            // /* if (check(inp[i]] < check(inp[i] + check(inp[i]]])  */p[i] += check(inp[i] + check(inp[i]]]/*  - check(inp[i]] */;
            // for (int j= p[i]/* inp[i] + check(inp[i]] */; j<n; j++) check(j]++;
            move(p[i], n);
        }
        for (int i=0; i<n; i++)
        {
            printf("%d ", p[i] + 1);
        }
        printf("\n");
    }
    return 0;
}