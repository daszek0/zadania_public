// Jakub Daszkiewicz
// zadanie Literki Rosnąco

#include <stdio.h>

using namespace std;

int main()
{
    char begin, end;
    scanf("%c %c", &begin, &end);
    for (char i=begin; i<=end; i++)
    {
        printf("%c", i);
    }
    return 0;
}