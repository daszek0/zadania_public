#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int firstnumber[3000];

int first(int index)
{
    if (index == 0)
    {
        firstnumber[0] = 2;
        return 2;
    }
    else if (index == 1)
    {
        firstnumber[1] = 3;
        return 3;
    }
    bool f;
    for (int j=firstnumber[index-1]+2; true; j+=2)
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
        if (f) firstnumber[index] = j;
        if (f == true)
            return j;
    }
}

int main()
{
    string number;
    int sum = 0;
    cin>>number;
    for (int i=0; i<number.length(); ++i)
    {
        if (number[i] == '1')
        {
            sum += first(i);
        }
        else first(i);
    }
    printf("%d", sum);

    return 0;
}
