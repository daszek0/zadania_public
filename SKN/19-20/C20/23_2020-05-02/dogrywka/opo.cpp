// Jakub Daszkiewicz
// zadanie Opowieść

#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, r = 0;
    scanf("%d\n", &n);
    char c;
    bool uppercase[26], lowercase[26];
    fill(uppercase, uppercase + 26, 0);
    fill(lowercase, lowercase + 26, 0);
    for (int i=0; i<n; i++)
    {
        scanf("%c", &c);
        if (c < 96)
        {
            if (lowercase[(int)c - 65]) r++;
            uppercase[(int)c - 65] = 1;
        }
        else
        {
            if (uppercase[(int)c - 97]) r++;
            lowercase[(int)c - 97] = 1;
        }
    }
    printf("%d", r);
    return 0;
}