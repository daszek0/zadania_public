#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int z;
    scanf("%d", &z);
    string w;
    long long r, l;
    bool kot;
    for (int i=0; i<z; i++)
    {
        cin>>w;
        l = w.length();
        r = 1;
        kot = 0;
        if (w.length()>3)
        {
            for (int j=1; j<l-3; j++)
            {
                if (w.substr(j, 3) == "kot" && !kot)
                {
                    ++r;
                    j += 2;
                    kot = 1;
                }
                else
                    kot = 0;
            }
        }
        printf("%lld\n", r);
    }

    return 0;
}
