// Jakub Daszkiewicz
// zadanie Obramowanie

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, ii;
    int height, width, m_top, m_left, m_right, m_bottom;
    scanf("%d %d %d %d %d %d", &height, &width, &m_top, &m_left, &m_right, &m_bottom);
    string word[height];
    for (i=0; i<height; i++)
        cin>>word[i];
    i = 0;
    for (i; i<m_top; i++)
    {
        if (i%2 == 0)
        {
            for (ii=0; ii<m_left+width+m_right; ii++)
            {
                if (ii%2 == 0) printf("#");
                else printf(".");
            }
        }
        else
        {
            for (ii=0; ii<m_left+width+m_right; ii++)
            {
                if (ii%2 == 0) printf(".");
                else printf("#");
            }
        }
        printf("\n");
    }
    for (i; i<m_top+height; i++)
    {
        if (i%2 == 0)
        {
            for (ii=0; ii<m_left; ii++)
            {
                if (ii%2 == 0) printf("#");
                else printf(".");
            }
        }
        else
        {
            for (ii=0; ii<m_left; ii++)
            {
                if (ii%2 == 0) printf(".");
                else printf("#");
            }
        }
        cout<<word[i-m_top];
        ii += width;
        if (i%2 == 0)
        {
            for (ii; ii<m_left+width+m_right; ii++)
            {
                if (ii%2 == 0) printf("#");
                else printf(".");
            }
        }
        else
        {
            for (ii; ii<m_left+width+m_right; ii++)
            {
                if (ii%2 == 0) printf(".");
                else printf("#");
            }
        }
        printf("\n");
    }
    for (i; i<m_top+height+m_bottom; i++)
    {
        if (i%2 == 0)
        {
            for (ii=0; ii<m_left+width+m_right; ii++)
            {
                if (ii%2 == 0) printf("#");
                else printf(".");
            }
        }
        else
        {
            for (ii=0; ii<m_left+width+m_right; ii++)
            {
                if (ii%2 == 0) printf(".");
                else printf("#");
            }
        }
        printf("\n");
    }
    
    return 0;
}