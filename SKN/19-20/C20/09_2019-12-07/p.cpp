// generetor liczb pierwszych

#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    unsigned long long check = 2;
    unsigned long long end = 30000;
    bool p;
    while (check <= end)
    {
        p = true;
        for (unsigned long long i = 2; i < check; i++)
        {
            if (check % i == 0)
            {
                p = false;
                break;
            }
        }
        if (p) printf("%llu, ", check);
        check++;
    }
    return 0;
}