// Jakub Daszkiewicz
// zadanie Orzeł czy reszka?

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    pair<int, int> t;
    int b = 0, w = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &t.first, &t.second);
        if (t.first%2 == t.second%2) w++;
        else b++;
    }
    printf("%d %d\n", w, b);
    return 0;
}