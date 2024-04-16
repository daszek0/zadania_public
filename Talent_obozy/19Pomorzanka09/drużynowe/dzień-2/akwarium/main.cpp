#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long V,N;
    scanf("%llu %llu", &V, &N);
    if (V/N>=3)
        cout << "NO";
    else
        cout << "YES" << " "<< (N - (V / 3));
    return 0;
}
