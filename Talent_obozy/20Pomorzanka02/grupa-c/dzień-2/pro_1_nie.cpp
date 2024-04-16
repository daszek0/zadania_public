// Jakub Daszkiewicz
// zadanie Liczba prostokątów

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    vector<int> f;
    while (true)
    {
        scanf("%d", &n);
        if (n == 0) break;
        m = n;
        f.push_back(1);
        if (m % 2 == 0)
        {
            m /= 2;
            f.push_back(2);
            while (m % 2 == 0)
            {
                m /= 2;
            }
        }
        if (m % 3 == 0)
        {
            m /= 3;
            f.push_back(3);
            while (m % 3 == 0)
            {
                m /= 3;
            }
        }
        for (int i=1; (6*i-1)*(6*i-1)<=n; i++)
        {
            if (m % (6*i-1) == 0)
            {
                m /= (6*i-1);
                f.push_back(6*i-1);
                while (m % (6*i-1) == 0)
                {
                    m /= (6*i-1);
                }
            }
            if (m % (6*i+1) == 0)
            {
                m /= (6*i+1);
                f.push_back(6*i+1);
                while (m % (6*i+1) == 0)
                {
                    m /= (6*i+1);
                }
            }
        }
        printf("%d\n", f.size());
        f.clear();
    }
    return 0;
}