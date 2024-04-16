// Jakub Daszkiewicz
// zadanie Płyta CD

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ms = 0, ss = 0, m, s;
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d", &m, &s);
        ms += m;
        ss += s;
    }
    ms += ss / 60;
    ss %= 60;
    printf("%02d:%02d", ms, ss);
    return 0;
}