#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string word;
    scanf("%d", &n);
    cin>>word;

    int r = 1, temp = 1;
    for (int i=0; i<n-1; i++)
    {
        if (word[i] != word[i+1])
            temp++;
        else if (word[i] == word[i+1])
            if (temp > r)
            {
                r = temp;
                temp = 1;
            }
    }

    if (temp > r) r = temp;

    printf("%d", r);

    return 0;
}
