#include <stdio.h>

using namespace std;

int nwd(int a, int b)
{
    if (a == b)
        return a;
    else if (a > b)
    {
        int r;
        do
        {
            r = a%b;
            a = b;
            b = r;
        } while (r != 0);
        return a;
    }
    else if (a < b)
    {
        int r;
        do
        {
            r = b%a;
            b = a;
            a = r;
        } while (r != 0);
        return b;
    }
}

int main()
{
    float fraction;
    int l;
    scanf("%f", &fraction);
    l = fraction*1000;
    printf("%d/%d", l/nwd(l,1000), 1000/nwd(l,1000));

    return 0;
}
