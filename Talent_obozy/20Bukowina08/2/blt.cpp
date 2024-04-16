// Jakub Daszkiewicz
// zadanie Biblioteka

#include <stdio.h>
#include <map>
#include <algorithm>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

bool pc(string c0, string c1)
{
    int tab[20];
    fill(tab, tab+20, 0);
    for (int i=0; i<c0.length(); i++)
    {
        if (c0[i] >= '0' && c0[i] <= '9')
        {
            tab[c0[i] - '0']++;
        }
        else
        {
            tab[c0[i] - 'a' + 10]++;
        }
        if (c1[i] >= '0' && c1[i] <= '9')
        {
            tab[c1[i] - '0']++;
        }
        else
        {
            tab[c1[i] - 'a' + 10]++;
        }
    }
    int c = 0;
    for (int i=0; i<20; i++)
    {
        if (tab[i] == 1) c++;
    }
    if (c <= 2) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map <string, int> b;
    vector <string> l, a;
    int c, n;
    cin>>c; // scanf("%d", &c);
    cin>>n; // scanf("%d", &n);
    // char t[20];
    string t;
    for (int i=0; i<n; i++)
    {
        // scanf("%s", t);
        cin>>t;
        a.push_back(t);
        // sort(t, t+strlen(t));
        sort(t.begin(), t.end());
        if (b.count(t) == 0)
        {
            b[t] = 1;
            l.push_back(t);
        }
        else b[t]++;
    }
    if (c == 1)
    {
        int r = 1, rv = b[l[0]];
        for (int i=1; i<l.size(); i++)
        {
            if (b[l[i]] > rv)
            {
                r = 1;
                rv = b[l[i]];
            }
            else if (b[l[i]] == rv)
            {
                r++;
            }
        }
        cout<<rv<<"\n"<<r<<"\n"; // printf("%d\n%d", rv, r);
    }
    else
    {
        int r = 0;
        for (int i=0; i<a.size() - 1; i++)
        {
            if (t.length() == a[i].length())
            {
                if (pc(t, a[i]))
                {
                    r++;
                }
            }
        }
        cout<<r<<"\n"; // printf("%d", r);
    }
    return 0;
}