// Jakub Daszkiewicz
// zadanie Minusy

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define pb push_back

using namespace std;

int main()
{
    char c, pc = 0;
    vector <char> s;
    c = getchar_unlocked();
    int m = 0;
    while (c != EOF)
    {
        if (c == '+')
        {
            if (pc == '-')
            {
                if (m % 2)
                {
                    for (int i=0; i<m; i++) s.pb('-');
                }
                else
                {
                    for (int i=0; i<(m/2); i++) s.pb('+');
                }
                m = 0;
            }
            s.pb('+');
        }
        else if (c == '-')
        {
            m++;
        }
        pc = c;
        c = getchar_unlocked();
    }
    if (m % 2)
    {
        for (int i=0; i<m; i++) s.pb('-');
    }
    else
    {
        for (int i=0; i<(m/2); i++) s.pb('+');
    }
    m = 0;
    int l = s.size(), i = 0, a = 0, ta = 0, ms;
    bool cm = 0, con = 0;
    while (i < l)
    {
        if (s[i] == '+')
        {
            if (con == 1)
            {
                cm = 0;
                ta += m / 2;
                con = 0;
                m = 0;
            }
            if (cm == 1)
            {
                ta += m / 2;
                i = ms;
                m = 0;
                a = max(a, ta);
                ta = 0;
                con = 1;
                continue;
            }
            cm = 0;
            ta++;
            a = max(a, ta);
        }
        else if (s[i] == '-')
        {
            if (cm == 0)
            {
                ms = i;
            }
            m++;
            cm = 1;
        }
        i++;
    }
    ta += m / 2;
    a = max(a, ta);
    printf("%d", a);
    return 0;
}