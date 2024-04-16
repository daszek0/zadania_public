#include <stdio.h>

using namespace std;

int main()
{
    int a[4];
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    bool checked[4] = {0};
    if ((a[0] == a[1] && a[2] == a[3]) || (a[0] == a[2] && a[1] == a[3]) || (a[0] == a[3] && a[2] == a[1]))
    {
        printf("TAK");
    }
    else
    {
        printf("NIE");
    }
    // int i, j;
    // for (i=1; i<4; i++)
    // {
    //     if (a[0] == a[i])
    //     {
    //         for (j=1; j<4; j++)
    //         {
    //             if (j != i)
    //             {

    //             }
    //         }
    //     }
    // }
    return 0;
}