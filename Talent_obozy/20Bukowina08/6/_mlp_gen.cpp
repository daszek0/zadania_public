// Jakub Daszkiewicz
// zadanie mlp generator

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    printf("20000000\n");
    char* c = new char[10000000];
    for (int i=0; i<10000000; i++)
    {
        c[i] = char(rand() % 26) + 'a';
    }
    for (int i=0; i<10000000; i++)
    {
        printf("%c", c[i]);
    }
    for (int i=9999999; i>=0; i--)
    {
        printf("%c", c[i]);
    }
    delete[] c;
    return 0;
}