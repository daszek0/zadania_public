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
                    for (int i=0; i<(m/2); i++) s.pb('+');
                    s.pb('|');
                    for (int i=0; i<(m/2); i++) s.pb('+');
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
        for (int i=0; i<(m/2); i++) s.pb('+');
        s.pb('|');
        for (int i=0; i<(m/2); i++) s.pb('+');
    }
    else
    {
        for (int i=0; i<(m/2); i++) s.pb('+');
    }
    int l = s.size(), a = 0, ta = 0;
    for (int i=0; i<l; i++)
    {
        if (s[i] == '+') ta++;
        else
        {
            a = max(a, ta);
            ta = 0;
        }
    }
    a = max(a, ta);
    printf("%d", a);
    return 0;
}