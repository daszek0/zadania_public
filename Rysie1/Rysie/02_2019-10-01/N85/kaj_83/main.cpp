#include <stdio.h>

using namespace std;

int main()
{
    int w, n;
    scanf("%d", &w);
    scanf("%d", &n);
    int m[w+1], x;
    for (int i=0; i<w+1; i++)
    {
        m[i] = 0;
    }
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        m[x]++;
    }

    int r = 0;

    for (int i=m[w]; i>0; i++)
    {
        r++;
        m[w]--;
    }

    for (int i=w-1; i>=0; i--)
    {
        while (m[i] > 0)
        {
            for (int j=w-i; j>=0; j--)
            {
                if (i == j && m[i] >= 2 && i+j <= w)
                {
                    m[i] -= 2;
                    r++;
                    break;
                }
                else if (m[j] > 0 && i+j <= w)
                {
                    m[i]--;
                    m[j]--;
                    r++;
                    break;
                }
                else if (j == 0)
                {
                    m[i]--;
                    r++;
                }
            }
        }
    }

    printf("%d", r);

    return 0;
}
