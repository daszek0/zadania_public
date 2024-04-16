#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long A;
    vector <int> a;

    scanf("%llu", &A);

    a.push_back(A%10);
    while (A >= 10)
    {
        A /= 10;
        a.push_back(A%10);
    }

    int taken;
    unsigned long long minimal;
    for (int i=0; i<a.size(); i++)
    {
        minimal = a[i];
        for (int j=i+1; j<a.size(); j++)
        {
            if (a[j]<minimal)
            {
                taken = minimal;
                minimal = a[j];
                a[j] = taken;
            }
        }
        a[i] = minimal;
    }

    unsigned long long maximal = 0;
    for (int i=a.size()-1; i>0; i--)
    {
        maximal += a[i];
        maximal *= 10;
    }
    maximal += a[0];

    minimal = 0;
    for (int i=0; i<a.size()-1; i++)
    {
        minimal += a[i];
        minimal *= 10;
    }
    minimal += a.back();

    printf("%d", maximal-minimal);

    return 0;
}
