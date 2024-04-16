// Jakub Daszkiewicz
// zadanie Minusy

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    char c, pc;
    int m = 0, r = 0, tr = 0;
    c = getchar_unlocked();
    vector <char> p;
    while (c != -1)
    {
        if (c == '+')
        {
            if (pc == '-')
            {
                if (m % 2 == 0)
                {
                    for (int i=0; i<m/2; i++) p.push_back('+');
                }
                else
                {
                    for (int i=0; i<m/2; i++) p.push_back('+');
                    p.push_back('|');
                    for (int i=0; i<m/2; i++) p.push_back('+');
                }
                m = 0;
            }
            p.push_back('+');
        }
        else if (c == '-')
        {
            m++;
        }
        pc = c;
        c = getchar_unlocked();
    }
    if (m % 2 == 0)
    {
        for (int i=0; i<m/2; i++) p.push_back('+');
    }
    else
    {
        for (int i=0; i<m/2; i++) p.push_back('+');
        p.push_back('|');
        for (int i=0; i<m/2; i++) p.push_back('+');
    }
    for (int i=0; i<p.size(); i++)
    {
        if (p[i] == '+')
        {
            tr++;
        }
        else
        {
            r = max(r, tr);
            tr = 0;
        }
    }
    r = max(r, tr);
    printf("%d", r);
    return 0;
}