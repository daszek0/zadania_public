#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string number;
    int n = 0, l;
    cin>>number;
    l = number.length();
    if (l == 1)
    {
        n = (int)number[0]-48;
    }
    else
    {
        n += (int)number[l-2]-48;
        n *= 10;
        n += (int)number[l-1]-48;
    }
    if (l == 1 && n == 0) printf("1");
    else
    {
        n %= 4;
        switch (n)
        {
            case 1:
            {
                printf("2");
                break;
            }
            case 2:
            {
                printf("4");
                break;
            }
            case 3:
            {
                printf("8");
                break;
            }
            case 0:
            {
                printf("6");
                break;
            }
        }
    }
    return 0;
}