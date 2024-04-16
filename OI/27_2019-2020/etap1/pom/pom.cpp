// zadanie Pomniejszenie
// Jakub Daszkiewicz

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int qpow(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return a;
    else if (n%2 == 0)
    {
        int r = qpow(a, n/2);
        return r*r;
    }
    else
    {
        int r = qpow(a, n-1);
        return a*r;
    }
}

void string_to_int_tab(string str, int n[], int length)
{
    int j = length-1;
    for (int i=0; i<length; ++i)
    {
        n[i] = (int)str[j]-48;
        --j;
    }
}

/*
int string_to_int(string str)
{
    int j = 0, r = 0;
    for (int i=str.length(), i>=0; --i)
    {
        r += ((int)str[i]-48)*qpow(10, j);
        ++j;
    }
    return r;
}
*/

int int_tab_to_int(int n[], int size)
{
    int r = 0;
    for (int i=0; i<size; ++i)
    {
        r += n[i]*qpow(10, i);
    }
    return r;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int p=0; p<t; ++p)
    {
        string a_str, b_str;
        int k, a, b, c;
        cin >> a_str >> b_str;
        scanf("%d", &k);
        int length = a_str.length();
        int a_tab[length], b_tab[length];
        string_to_int_tab(a_str, a_tab, length);
        string_to_int_tab(b_str, b_tab, length);
        int c_tab[length];
        for (int i=0; i<length; ++i)
        {
            c_tab[i] = a_tab[i];
        }

        /*
        // test string_to_int_tab
        for (int i=length-1; i>=0; --i)
        {
            printf("%d", a_tab[i]);
        }
        printf(" ");
        for (int i=length-1; i>=0; --i)
        {
            printf("%d", b_tab[i]);
        }
        printf("\n");
        */

        if (k == 1)
        {
            for (int i=length-1; i>=0; --i)
            {
                if (a_tab[i] == b_tab[i])
                    continue;
                else
                {
                    /*if (a_tab[i]-b_tab[i] >= 0)
                    {
                        c_tab[i] = a_tab[i]-b_tab[i];
                        break;
                    }*/
                    if (b_tab[i]-1 >= 0)
                    {
                        c_tab[i] = b_tab[i]-1;
                        break;
                    }
                }
                
            }
            a = int_tab_to_int(a_tab, length);
            // b = int_tab_to_int(b_tab, length);
            c = int_tab_to_int(c_tab, length);
            if (c != a)
                printf("%d", c);
            else
                printf("-1");
        }
        else
        {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}