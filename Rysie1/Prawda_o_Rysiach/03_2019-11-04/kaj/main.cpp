#include <stdio.h>

using namespace std;

int main()
{
    int m_max, people_amount, r = 0;
    bool f;
    int people[201] = {0};
    scanf("%d", &m_max);
    scanf("%d", &people_amount);
    for (int i=0; i<people_amount; i++)
    {
        int x;
        scanf("%d", &x);
        people[x]++;
    }
    for (int i=m_max; i>=5; i--)
    {
        while (people[i] > 0)
        {
            f = false;
            for (int j=5; j<=i; j++)
            {
                if (people[j]>0 && i+j <= m_max)
                {
                    people[i]--;
                    people[j]--;
                    r++;
                    f = true;
                    break;
                }
            }
            if (f == false)
            {
                people[i]--;
                r++;
            }
        }
    }
    printf("%d", r);

    return 0;
}
