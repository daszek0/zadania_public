// Jakub Daszkiewicz
// zadanie Ciąg malejący

#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=n; i>0; i--)
    {
        printf("%d ", i);
    }
    return 0;
}