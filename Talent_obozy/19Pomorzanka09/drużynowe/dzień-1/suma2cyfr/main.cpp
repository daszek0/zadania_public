#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, suma;
    int a[3], b[3], c[3];
    scanf("%d+%d", &x, &y);
    suma = x+y;
    a[0] = x%10;
    x /= 10;
    a[1] = x%10;
    x /= 10;
    a[2] = x%10;
    x /= 10;
    b[0] = y%10;
    y /= 10;
    b[1] = y%10;
    y /= 10;
    b[2] = y%10;
    y /= 10;

    for (int i=0; i<2; i++)
    {
        c[i] = a[i]+b[i];
        if (c[i]>9)
            c[i] -= 10;
    }
    c[2] = a[2]+b[2];

    cout<<c[2]<<c[1]<<c[0]<<endl;
    cout<<suma;

    /*for (int i=0; i<3; i++)
    {
        cout<<a[i]<<endl;
        cout<<b[i]<<endl;

    }*/

    return 0;
}
