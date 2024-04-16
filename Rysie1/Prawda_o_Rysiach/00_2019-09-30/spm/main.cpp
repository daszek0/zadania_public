#include <stdio.h>

using namespace std;

int nwd(int a, int b)
{
    int r;
    if (a == b)
    {
        return a;
    }
    else if (a>b)
    {
        do
        {
            r = a%b;
            a = b;
            b = r;
        } while (r != 0);
        return a;
    }
    else if (a<b)
    {
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
    int n;
    scanf("%d", &n);

    printf("%d/%d", n/nwd(n,1440), 1440/nwd(n,1440));
    return 0;
}
