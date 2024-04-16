// Jakub Daszkiewicz
// zadanie Najwcześniejsza leksykograficznie

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);
    char w[n];
    for (int i=0; i<n; i++)
    {
        scanf("%c", &w[i]);
    }
    sort(w, w+n);
    for (int i=0; i<n; i++)
    {
        printf("%c", w[i]);
    }
    return 0;
}