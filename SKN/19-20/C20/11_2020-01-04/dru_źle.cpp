// Jakub Daszkiewicz
// zadanie Liczby drugie

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

const int p[4] = {2, 3, 5, 7};

bool exists(int n)
{
    for (int i=0; i<4; i++)
    {
        if (n == p[i]) return true;
    }
    return false;
}

int main()
{
    string n;
    cin>>n;
    for (int i=0; i<n.length(); i++)
    {
        if (!exists((int)n[i]-48))
        {
            printf("NIE");
            exit(0);
        }
    }
    printf("TAK");
    return 0;
}