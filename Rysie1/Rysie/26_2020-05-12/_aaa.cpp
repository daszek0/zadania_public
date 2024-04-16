// Jakub Daszkiewicz
// zadanie 

#include <stdio.h>

using namespace std;

int main()
{
    for (int i=0; i<2962717; i++)
    {
        if (i % 3 == 0) printf("%d\n", i);
    }
    return 0;
}