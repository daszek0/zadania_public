// Jakub Daszkiewicz
// zadanie Trójramienny dźwig

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int p, q, n;
bool wagon[360000], ready;
vector <int> operacja[2];

int main()
{
    scanf("%d %d %d", &p, &q, &n);
    if (p > q) swap(p, q);
    int i = 0, o = 0;
    do
    {
        if (!wagon[i])
        {
            if (!wagon[i+p])
            {
                wagon[i+p] = 1;
                operacja[1].push_back(i+p);
            }
            else
            {
                wagon[i+q] = 1;
                operacja[1].push_back(i+q);
            }
            wagon[i] = 1;
            operacja[0].push_back(i);
            wagon[i+p+q] = 1;
            ++o;
            ready = true;
            for (int j=n-1; j>=0; j--)
            {
                if (!wagon[j])
                {
                    ready = false;
                    break;
                }
            }
        }
        ++i;
    } while (!ready);

    printf("%d\n", o);
    for (int j=0; j<o; j++)
    {
        printf("%d %d %d\n", operacja[0][j]+1, operacja[1][j]+1, operacja[0][j]+p+q+1);
    }
    return 0;
}
