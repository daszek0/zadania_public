// Jakub Daszkiewicz
// zadanie Uszkodzona drukarka

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    for (int i=0; i<n; i++)
    {
        cin >> s[i];
    }
    sort(s, s+n, less<string>());
    string c = s[0];
    int ca = 1, a = 1;
    for (int i=1; i<n; i++)
    {
        if (s[i].substr(0, c.length()) == c)
        {
            ca++;
        }
        else
        {
            a = max(a, ca);
            ca = 1;
            c = s[i];
        }
    }
    cout << a;
    return 0;
}