#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    int k;
    bool a[10];
    for(int i=0; i<10; i++)
    {
        a[i] = true;
    }
    int c, d[30], ilosc;
    for (int i=0; i<30; i++)
        d[i] = 10;
    scanf("%d", &k);
    scanf("%d", &c);

    for(int i=0; ; i++)
    {
        d[i] = c%10;
        c /= 10;
        if(c/10 < 10)
        {
            break;
            ilosc = i;
        }

    }

    for(int j=0; j<ilosc; j++)
    {
        a[d[j]] = false;
    }

    for (int i=0; i<10; i++)
        cout<<a[i];

    return 0;
}
