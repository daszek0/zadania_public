// Jakub Daszkiewicz
// zadanie Wyprawa

#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
long long vp, v;
int res = 1, c = 1, i = 1;
bool r;

void check()
{
    do
    {
        vp = v;
        scanf("%lld", &v);
        i++;
        if (v > vp)
        {
            r = 1;
            c++;
            res = max(res, c);
        }
        else if (v < vp)
        {
            r = 0;
            c++;
            res = max(res, c);
        }
    } while (v == vp && i < n);
    while (i < n)
    {
        vp = v;
        scanf("%lld", &v);
        i++;
        if (v == vp || (!r && v > vp))
        {
            res = max(res, c);
            c = 2;
            if (i < n) check();
        }
        else if (r)
        {
            if (v > vp)
            {
                c++;
                res = max(res, c);
            }
            else if (v < vp)
            {
                r = 0;
                c++;
                res = max(res, c);
            }
        } 
        else if (!r && v < vp) c++;
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%lld", &v);
    if (n > 1)
    {
        check();
    }
    printf("%d", res);
    return 0;
}