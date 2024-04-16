// Jakub Daszkiewicz
// zadanie Korale

#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    char b[n];
    scanf("%s", b);
    for (int i = 1; i < n; i++)
    {
        if (b[i - 1] == b[i])
        {
            printf("NIE");
            return 0;
        }
    }
    if (b[0] == b[n - 1])
    {
        printf("NIE");
        return 0;
    }
    printf("TAK");
    return 0;
}