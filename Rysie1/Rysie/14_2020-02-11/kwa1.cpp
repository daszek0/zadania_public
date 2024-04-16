// Jakub Daszkiewicz
// zadanie Kwadrat

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector <int> d;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    int N = n;
    while (n % 2 == 0)
    {
        n /= 2;
        d.push_back(2);
    }
    for (int i=3; i*i<=N; i+=2)
    {
        while (n % i == 0)
        {
            n /= i;
            d.push_back(i);
        }
    }
    if (n != 1) d.push_back(n);
    int D = d.size();
    int t = 1;
    for (int i=1; i<D; i++)
    {
        if (d[i-1] == d[i])
        {
            t++;
        }
        else
        {
            if (t % 2 == 1)
            {
                d.push_back(d[i-1]);
            }
            t = 1;
        }
        
    }
    if (t % 2 == 1)
    {
        d.push_back(d[D-1]);
    }
    unsigned long long r = 1;
    for (int i=0; i<d.size(); i++)
    {
        r *= d[i];
    }
    printf("%llu", r);
    return 0;
}