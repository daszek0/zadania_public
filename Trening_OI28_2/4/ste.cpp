// Jakub Daszkiewicz
// zadanie Łuk triumfalny

#include <cstdio>
#include <algorithm>

using namespace std;

int n[300000];

int main()
{
    int c;
    scanf("%d", &c);
    int a, b;
    for (int i = 0; i < c - 1; i++)
    {
        scanf("%d %d", &a, &b);
        n[a - 1]++;
        n[b - 1]++;
    }
    printf("%d", *max_element(n, n + 300000) - 1);
    return 0;
}