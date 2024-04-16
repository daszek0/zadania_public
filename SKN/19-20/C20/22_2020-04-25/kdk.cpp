// Jakub Daszkiewicz
// zadanie Kod kreskowe

#include <stdio.h>

using namespace std;

unsigned long long pow10(int n)
{
    switch (n)
    {
        case 0: return 1;
        case 1: return 10;
        case 2: return 100;
        case 3: return 1000;
        case 4: return 10000;
        case 5: return 100000;
        case 6: return 1000000;
        case 7: return 10000000;
    }
}

int main()
{
    char t;
    unsigned long long code;
    int r[3] = {0, 0, 0};
    while (true)
    {
        code = 0;
        for (int i=7; i>=0; i--)
        {
            t = getchar_unlocked();
            if (t < '0' || t > '9')
            {
                printf("%d %d %d", r[0], r[1], r[2]);
                return 0;
            }
            if (i != 0 && i < 5) code += (int)(t - '0') * pow10(i-1);
        }
        if (code % 2 == 0) r[0]++;
        if (code % 3 == 0) r[1]++;
        if (code % 5 == 0) r[2]++;
    }
}