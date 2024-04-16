// Jakub Daszkiewicz
// zadanie Dziesiętny na dziewiątkowy

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int p;
    vector <int> r;
    scanf("%d", &p);
    while (p ^ 0)
    {
        r.push_back(p % 9);
        p /= 9;
    }
    for (int i=r.size()-1; i>=0; i--)
    {
        printf("%d", r[i]);
    }
    return 0;
}