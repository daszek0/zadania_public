// Jakub Daszkiewicz
// zadanie Rzymski na arabski

#include <cstdio>

using namespace std;

int rta(char x)
{
    switch(x)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int main()
{
    int a = 0;
    char pc, c = getchar_unlocked();
    a += rta(c);
    pc = c;
    c = getchar_unlocked();
    while (c != EOF)
    {
        if (rta(c) > rta(pc))
        {
            a -= (rta(pc) << 1);
        }
        a += rta(c);
        pc = c;
        c = getchar_unlocked();
    }
    printf("%d", a);
    return 0;
}