// Jakub Daszkiewicz
// zadanie Pudełka

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, p, s, c = 1, a = 1;
    scanf("%d", &n);
    scanf("%d", &p);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &s);
        if (p == s)
        {
            c++;
        }
        else
        {
            a = max(a, c);
            c = 1;
        }
        p = s;
    }
    printf("%d", a);
    return 0;
}