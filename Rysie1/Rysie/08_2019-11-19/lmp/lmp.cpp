#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    bool board[n][m];
    string t;
    for (int i=0; i<n; ++i)
    {
        cin>>t;
        for (int ii=0; ii<m; ++ii)
        {
            board[i][ii] = (int)t[ii]-48;
        }
    }
    for (int i=0; i<n; ++i)
    {
        for (int ii=m-1; ii>=0; --ii)
        {
            if (board[i][ii] == 0)
            {
                for (int iii=i+1; iii<n; ++iii)
                {
                    board[iii][ii] ^= 1;
                }
                for (int iii=ii; iii>=0; --iii)
                {
                    board[i][iii] ^= 1;
                }
                ++r;
            }
        }
        
    }
    printf("%d\n", r);
    return 0;
}
