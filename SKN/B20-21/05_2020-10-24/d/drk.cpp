// Jakub Daszkiewicz
// zadanie Uszkodzona drukarka

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int c[1000001];

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
    sort(s, s+n);
    c[s[0].size() - 1] = 1;
    int m = 1, j;
    for (int i=1; i<n; i++)
    {
        j = 0;
        while (s[i][j] == s[i - 1][j]) j++;
        for (j; j<s[i].size(); j++)
        {
            if (j == 0) c[j] = 0;
            else c[j] = c[j - 1];
        }
        c[s[i].size() - 1]++;
        m = max(m, c[s[i].size() - 1]);
    }
    cout << m;
    return 0;
}