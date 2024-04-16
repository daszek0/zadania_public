// Jakub Daszkiewicz
// zadanie Ulubiona 13-stka

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, r = 0;
    scanf("%d", &n);
    bool t1;
    for (int p=0; p<n; ++p)
    {
        t1 = false;
        string w;
        cin>>w;
        for (int i=0; i<w.length(); ++i)
        {
            if (w[i] == '1')
                t1 = true;
            if (w[i] == '3' && t1 == true)
            {
                ++r;
                t1 = false;
                break;
            }
        }
    }
    if (r == 0) printf("NIE");
    else printf("%d", r);
    return 0;
}