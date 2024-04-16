#include <stdio.h>
#include <math.h>

#define ull unsigned long long

using namespace std;

int main()
{
    ull n, w, check;
    scanf("%llu%llu", &n, &w);
    if (n/2 < sqrt(w))
    {
        ull begin = 1, end = n/2;
        while (true)
        {
            check = (begin+end)/2;
            if (n-check < w/check)
                begin = check;
            else if (n-check > w/check)
                end = check;
            else
                break;
        }
    }
    else
    {
        ull begin = 1, end = sqrt(w);
        while (true)
        {
            check = (begin+end)/2;
            if (n-check > w/check)
                begin = check;
            else if (n-check < w/check)
                end = check;
            else
                break;
        }
    }
    printf("%llu", check);
    return 0;
}