// Jakub Daszkiewicz
// zadanie Okuyasu i ciąg

#include <stdio.h>
#include <iostream>

#define infinity 1000000000000000001

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long l = infinity, r;
    char c;
    unsigned long long t = 0;
    bool m = 0;
    int i = 0, j = 0;
    string s;
    getline(cin, s);
    int it = -1;
    long long check[2] = {infinity, infinity};
    while (true)
    { 
        it++;
        c = s[it];
        // c = getchar_unlocked();
        if (c == ' ' || c == '\n')
        {
            if (j != -1)
            {
                if (i == 0)
                {
                    if (m == 1)
                    {
                        l = -t;
                    }
                    else
                    {
                        l = t;
                    }
                }
                if (m == 1)
                {
                    check[j] = -t;
                }
                else
                {
                    check[j] = t;
                }
                if (j == 1)
                {
                    r = check[1] - check[0];
                    l = check[1] - (i - 1) * r;
                    break;
                }
            }
            t = 0;
            j++;
            i++;
            continue;
        }
        if (c == '*')
        {
            j = -1;
            check[0] = infinity;
            check[1] = infinity;
            // t = infinity;
        }
        else
        {
            if (c == '-')
            {
                m = 1;
            }
            else
            {
                t *= 10;
                t += (int)(c - '0');
            }
        }
    }
    printf("%lld %lld", l, r);
    return 0;
}