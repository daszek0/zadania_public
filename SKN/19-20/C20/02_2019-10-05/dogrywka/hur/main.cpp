#include <iostream>
#include <stdio.h>

using namespace std;

int types[26];
int notes;
char type;
int value;
bool has_been[26];

int main()
{
    scanf("%d", &notes);
    for (int i=0; i<notes; i++)
    {
        cin>>type;// scanf("%c", &type);
        scanf("%d", &value);
        types[(int)type-65] += value;
        has_been[(int)type-65] = true;
    }

    for (int i=0; i<26; i++)
    {
        if(has_been[i] == true)
            printf("%c %d\n", (char)i+65, types[i]);
    }

    return 0;
}
