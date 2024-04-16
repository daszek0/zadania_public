#include <iostream>
#include <stdio.h>

using namespace std;

int types[26];
int notes;
char type;
int value;

int main()
{
    scanf("%d", &notes);
    for (int i=0; i<notes; i++)
    {
        cin>>type;// scanf("%c", &type);
        scanf("%d", &value);
        types[(int)type-65] += value;
    }

    for (int i=0; i<26; i++)
    {
        if(types[i] != 0)
            printf("%c %d\n", (char)i+65, types[i]);
    }

    return 0;
}
