// Jakub Daszkiewicz
// zadanie Biblioteka

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int c, n;
    cin>>c>>n;
    int h[n];
    fill(h, h+n, 0);
    char t;
    string s;
    for (int i=0; i<n; i++)
    {
        cin>>s;
        for (int j=0; j<s.length(); j++)
        {
            t = s[j];
            if (t >= '0' && t <= '9')
            {
                h[i] += 1 << int(t - '0');
            }
            else if (t >= 'a' && t <= 'j')
            {
                h[i] += 1 << int(t - 'a' + 10);
            }
        }
    }
    if (c == 1)
    {
        sort(h, h+n);
        int rm = 1, r = 1, rt = 1;
        for (int i=1; i<n; i++)
        {
            if (h[i] == h[i-1]) rt++;
            else
            {
                if (rt > rm)
                {
                    r = 1;
                    rm = rt;
                }
                else if (rt == rm)
                {
                    r++;
                }
                rt = 1;
            }
        }
        if (rt > rm)
        {
            r = 1;
            rm = rt;
        }
        else if (rt == rm)
        {
            r++;
        }
        rt = 1;
        // printf("%d\n%d\n", rm, r);
        cout<<rm<<"\n"<<r<<"\n";
        // int b[1048576];
        // fill(b, b+1048576, 0);
        // for (int i=0; i<n; i++)
        // {
        //     b[h[i]]++;
        // }
        // int r = 0, rv = 0;
        // for (int i=0; i<1048576; i++)
        // {
        //     if (b[i] > rv)
        //     {
        //         r = 1;
        //         rv = b[i];
        //     }
        //     else if (b[i] == rv)
        //     {
        //         r++;
        //     }
        // }
        // printf("%d\n%d", rv, r);
    }
    else
    {
        int r = 0;
        for (int i=0; i<n-1; i++)
        {
            if (__builtin_popcount(h[n-1] ^ h[i]) == 2 && __builtin_popcount(h[n-1]) == __builtin_popcount(h[i])) r++;
        }
        // printf("%d", r);
        cout<<r<<"\n";
    }
    return 0;
}