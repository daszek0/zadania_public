// Jakub Daszkiewicz
// zadanie Gra

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n, t, sum = 0;
    scanf("%d", &n);
    vector <int> s;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        if (t < 0)
        {
            s.push_back(sum);
            sum = 0;
        }
        else sum += t;
    }
    return 0;
}