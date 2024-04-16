// Jakub Daszkiewicz
// zadanie Mieszanie kolorów [B]

#include <stdio.h>

const int N = 1 << 21;
int st = 1;
int t[3][N];

void add(int tree[], int s, int e) // color, start bucket, end bucket
{
    s += st;
    e += st;
    while (s < e)
    {
        if (s & 1)
        {
            tree[s]++;
            s >>= 1;
            s++;
        }
        else
            s >>= 1;
        if (e & 1)
            e >>= 1;
        else
        {
            tree[e]++;
            e >>= 1;
            e--;
        }
    }
    if (s == e)
    {
        tree[s]++;
    }
}

int check(int tree[], int i) // color, bucket
{
    int r = 0;
    i += st;
    while (i)
    {
        r += tree[i];
        i >>= 1;
    }
    return r;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    while (st < n)
        st <<= 1;
    int l, r, k;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &l, &r, &k);
        add(t[k - 1], l - 1, r - 1);
    }
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (check(t[0], i) > 0 && check(t[1], i) > 0 && check(t[2], i) <= 0)
            a++;
    }
    printf("%d", a);
    return 0;
}