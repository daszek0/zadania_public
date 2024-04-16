// Jakub Daszkiewicz
// zadanie Palindromiczny podział

#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int q;
    cin>>q;// scanf("%d", &q);
    string s, l = "", r = "";
    int f, t, len, a;
    for (int p=0; p<q; p++)
    {
        cin>>s;// scanf("%s", s);
        len = s.length();
        f = 0;
        t = 0;
        a = 0;
        l = s[0];
        r = s[len - 1];
        while (f < len/2 && t < len/2)
        {
            if (l == r)
            {
                f = ++t;
                l = s[f];
                r = s[len - 1 - f];
                a += 2;
            }
            else
            {
                t++;
                l += s[t];
                r = s[len - 1 - t] + r;
            }
        }
        if (len % 2 && f == t) a++;
        if (f != t) a++;
        cout<<a<<"\n";
    }
    return 0;
}