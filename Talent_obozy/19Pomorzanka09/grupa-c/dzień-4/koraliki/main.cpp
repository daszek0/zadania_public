#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l = 0;
    scanf("%d", &n);
    string k;

    cin>>k;

    for (int i=0; i<n-1; i++)
    {
        if (k[i] == k[i+1])
            l++;
    }

    if (k[n-1] == k[0])
        l++;

    if (l < 2)
    {
        printf("TAK");
    }

    else
    {
        printf("NIE");
    }

    return 0;
}
