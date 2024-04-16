// Jakub Daszkiewicz
// zadanie Licznik długu

#include <stdio.h>
#include <algorithm>

using namespace std;

void qinp(int *n)
{
    int i = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9')
        c = getchar_unlocked();
    while (c >= '0' && c <= '9')
    {
        i = (i << 3) + (i << 1) + c - '0';
        c = getchar_unlocked();
    }
    *n = i;
}

int main()
{
    int n, q;
    qinp(&n);
    qinp(&q);
    int w[n - 1], z[n - 1], s[n], a[n - 1];
    char t;
    t = getchar_unlocked();
    while (t < '0' || t > '9')
        t = getchar_unlocked();
    for (int i = n - 2; i >= 0; i--)
    {
        w[i] = t - '0';
        t = getchar_unlocked();
    }
    while (t < '0' || t > '9')
        t = getchar_unlocked();
    for (int i = n - 2; i >= 0; i--)
    {
        z[i] = t - '0';
        t = getchar_unlocked();
    }
    int p, d, qq = 0, minp, maxp, imaxp;
    while (true)
    {
        qq++;
        t = getchar_unlocked();
        if (t == 'S')
        {
            qinp(&p);
            p--;
            break;
        }
        qinp(&p);
        qinp(&d);
        p--;
        if (t == 'W')
            w[p] = d;
        else
            z[p] = d;
    }
    fill(s, s + n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        s[i] += w[i] + z[i];
        if (s[i] > 9)
        {
            s[i + 1]++;
            s[i] -= 10;
        }
    }
    putchar_unlocked(s[p] + '0');
    putchar_unlocked('\n');
    fill(a, a + n - 1, 0);
    minp = n;
    maxp = 0;
    for (; qq < q; qq++)
    {
        t = getchar_unlocked();
        qinp(&p);
        p--;
        if (t == 'W' || t == 'Z')
        {
            qinp(&d);
            if (t == 'W')
            {
                a[p] += d - w[p];
                w[p] = d;
            }
            else
            {
                a[p] += d - z[p];
                z[p] = d;
            }
            minp = min(minp, p);
            maxp = max(maxp, p);
        }
        else
        {
            imaxp = maxp;
            for (int i = minp; i < n - 1 && i <= maxp; i++)
            {
                s[i] += a[i];
                if (s[i] < 0)
                {
                    s[i + 1] += s[i] / 10 - 1;
                    s[i] %= 10;
                    s[i] += 10;
                }
                if (s[i] > 9)
                {
                    s[i + 1] += s[i] / 10;
                    s[i] %= 10;
                }
                if (i == maxp && (s[i + 1] < 0 || s[i + 1] > 9))
                    maxp++;
            }
            putchar_unlocked(s[p] + '0');
            putchar_unlocked('\n');
            if (minp < imaxp + 1)
                fill(a + minp, a + imaxp + 1, 0);
            minp = n;
            maxp = 0;
        }
    }
    return 0;
}