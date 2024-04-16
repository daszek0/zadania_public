#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, r = 0;
    scanf ("%d", &n);
    int k[n];
    vector <int> used;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &k[i]);
    }
    for (int i=0; i<n; i++)
    {
        bool y = false;
        for (int j=0; j<used.size(); j++)
        {
            if (k[i] == used[j])
                y = true;

        }
        if (y == false)
        {
            r++;
            used.push_back(k[i]);
        }

    }

    printf("%d", r);
    return 0;
}
