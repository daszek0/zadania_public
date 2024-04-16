// Jakub Daszkiewicz
// zadanie Porcja
//
// test 1: 3 adam 50 55 jan 45 49 julian 54 55 => 3.3333
// test 2: 3 kasia 40 45 basia 44 46 asia 48 49 => 2.6667
// test 3: 3 daniel 60 67 piotr 64 65 pawel 59 60 => 3.0000

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, a, b;
    scanf("%d", &n);
    int s = 0;
    long double average;
    string str;
    for (int i=0; i<n; i++)
    {
        cin>>str>>a>>b;
        s += b-a;
    }
    average = (long double)s/n;
    printf("%.4Lf", average);
    return 0;
}