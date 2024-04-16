// Jakub Daszkiewicz
// zadanie Potęga

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    string N;
    cin>>N;
    int n = 0, r;
    if (N.length() > 1)
    {
        n += (int)N[N.length()-2]-48;
        n *= 10;
    }
    n += (int)N[N.length()-1]-48;
    if (n == 0 && N.length() <= 2)
        r = 1;
    else
    {
        n %= 4;
        switch(n)
        {
            case 1:
            {
                r = 2;
                break;
            }
            case 2:
            {
                r = 4;
                break;
            }
            case 3:
            {
                r = 8;
                break;
            }
            case 0:
            {
                r = 6;
                break;
            }
        }
    }
    printf("%d", r);
    return 0;
}