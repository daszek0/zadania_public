#include <vector>
#include <stdio.h>

using namespace std;

int n, t, l;
vector <int> p[2];

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        p[0].push_back(t);
        scanf("%d", &t);
        p[1].push_back(t);
    }
    l = n;
    for (int i=0; i<p[0].size(); i++)
    {
        for (int j=0; j<p[0].size(); j++)
        {
            if (p[0][i] == 0) break;
            if (i != j && p[0][j] != 0)
            {
                if (p[0][i] <= p[0][j] && p[1][i] >= p[1][j]) // opcja 0
                {
                    p[0][j] = 0;
                    p[1][j] = 0;
                    --n;
                }
                else if (p[0][i] <= p[0][j] && p[0][j] <= p[1][i]) // opcja 1
                {
                    p[1][i] = p[1][j];
                    p[0][j] = 0;
                    p[1][j] = 0;
                    --n;
                }
                else if (p[0][j] <= p[0][i] && p[0][i] <= p[1][j]) // opcja 2
                {
                    p[0][i] = p[0][j];
                    p[0][j] = 0;
                    p[1][j] = 0;
                    --n;
                }
            }
        }
    }

    printf("%d\n", n);
    for (int i=0; i<l; i++)
    {
        if (p[0][i] != 0)
            printf("%d %d\n", p[0][i], p[1][i]);
    }

    return 0;
}
