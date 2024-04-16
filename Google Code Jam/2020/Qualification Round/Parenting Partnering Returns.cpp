// Daszek
// Parenting Partnering Returns

#include <stdio.h>
#include <algorithm>

using namespace std;

struct activity
{
    int start;
    int end;
    char parent;
    int index;
};

bool activity_comp(activity a, activity a1)
{
    if (a.start == a1.start && a.end < a1.end) return true;
    else if (a.start < a1.start) return true;
    return false;
}

bool free_time(bool tab[], int start, int end)
{
    for (int i=start; i<end; i++)
    {
        if (tab[i] == 1) return false;
    }
    return true;
}

int main()
{
    int t, n;
    bool impossible, C[1440], J[1440];
    scanf("%d", &t);
    for (int p=1; p<=t; p++)
    {
        impossible = 0;
        fill(C, C+1440, 0);
        fill(J, J+1440, 0);
        scanf("%d", &n);
        activity a[n];
        for (int i=0; i<n; i++)
        {
            scanf("%d %d", &a[i].start, &a[i].end);
            a[i].index = i;
        }
        sort(a, a+n, activity_comp);
        for (int i=0; i<n; i++)
        {
            if (free_time(C, a[i].start, a[i].end))
            {
                fill(C+a[i].start, C+a[i].end, 1);
                a[i].parent = 'C';
            }
            else if (free_time(J, a[i].start, a[i].end))
            {
                fill(J+a[i].start, J+a[i].end, 1);
                a[i].parent = 'J';
            }
            else
            {
                impossible = 1;
                break;
            }
        }
        printf("Case #%d: ", p);
        if (impossible)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for (int i=0; i<n; i++)
        {
            for (int ii=0; ii<n; ii++)
            {
                if (a[ii].index == i)
                {
                    putchar_unlocked(a[ii].parent);
                    break;
                }
            }
        }
        putchar_unlocked('\n');
    }
    return 0;
}