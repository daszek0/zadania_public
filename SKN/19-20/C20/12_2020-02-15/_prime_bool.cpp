// sprawdzacz liczb pierwszych

#include <stdio.h>

using namespace std;

bool pierwsza(int n)
{
    for (int i=3; i*i<=n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    printf("false, false");
    for (int i=3; i<=1000000; i+=2)
    {
        if (pierwsza(i))
        {
            printf(", true");
        }
        else
        {
            printf(", false");
        }
        
    }
    return 0;
}