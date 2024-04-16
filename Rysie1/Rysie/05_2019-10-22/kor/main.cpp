#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int beads;
    string necklace;
    int result = 0;
    scanf("%d", &beads);
    cin>>necklace;
    if (necklace[0] == necklace[beads-1]) result++;
    for (int i=0; i<beads-1; i++)
    {
        if (necklace[i] == necklace[i+1]) result++;
    }
    if (result > 1) printf("NIE");
    else printf("TAK");
    return 0;
}
