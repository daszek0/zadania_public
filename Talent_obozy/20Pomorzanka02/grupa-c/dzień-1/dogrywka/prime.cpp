// generator liczb pierwszych

#include <stdio.h>

using namespace std;

int primenumber[100001];

int prime(int index)
{
    if (index == 0)
    {
        primenumber[0] = 2;
        return 2;
    }
    else if (index == 1)
    {
        primenumber[1] = 3;
        return 3;
    }
    bool f;
    for (int j=primenumber[index-1]+2; true; j+=2)
    {
        f = true;
        for (int i=3; i<j; i+=2)
        {
            if (j%i == 0)
            {
                f = false;
                break;
            }
        }
        if (f) primenumber[index] = j;
        if (f == true)
            return j;
    }
}

int main()
{
    for (int i=0; prime(i)<=22361; i++)
    {
        printf("%d, ", prime(i));
    }
    return 0;
}