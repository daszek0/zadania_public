// Daszek
// Nesting Depth 

#include <stdio.h>

using namespace std;

int main()
{
    int t;
    char c, pc;
    scanf("%d\n", &t);
    for (int i=1; i<=t; i++)
    {
        printf("\nCase #%d: ", i);
        pc = getchar_unlocked();
        for (char j = pc; j > '0'; j--) putchar_unlocked('(');
        putchar_unlocked(pc);
        c = getchar_unlocked();
        while (c != '\n')
        {
            for (char j = pc; j > c; j--) putchar_unlocked(')');
            for (char j = c; j > pc; j--) putchar_unlocked('(');
            putchar_unlocked(c);
            pc = c;
            c = getchar_unlocked();
        }
        for (char j = pc; j > '0'; j--) putchar_unlocked(')');
    }
    return 0;
}