// zadanie Pomniejszenie
// Jakub Daszkiewicz

#include <stdio.h>
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
int string_to_int(string str, int length)
{
    int j = 0, r = 0;
    for (int i=length; i>=0; --i)
    {
        r += ((int)str[i]-48)*qpow(10, j);
        ++j;
    }
    return r;
}

int int_tab_to_int(int n[], int size)
{
    int r = 0;
    for (int i=0; i<size; ++i)
    {
        r += n[i]*qpow(10, i);
    }
    return r;
}

void int_to_int_tab(int n, int tab[], int size)
{
    for (int i=0; i<size; ++i)
    {
        tab[i] = n%10;
        n /= 10;
    }
}
*/

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

        // int a = string_to_int(a_str, length);
        // int b = string_to_int(b_str, length);

        string_to_int_tab(a_str, a_tab, length);
        string_to_int_tab(b_str, b_tab, length);

        int c_tab[length];
        for (int i=0; i<length; ++i)
        {
            c_tab[i] = a_tab[i];
        }
        // int c = a;

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

        bool done = false;

        if (k == 1)
        {
            /*for (int i=length-1; i>=0; --i)
            {
                if (a_tab[i]-b_tab[i] < 0)
                    continue;
                
                
            }*/
            for (int i=length-1; i>=0; --i)
            {
                if (a_tab[i] > b_tab[i])
                {
                    if (a_tab[i]-b_tab[i] >= 0)
                    {
                        c_tab[i] = a_tab[i]-b_tab[i];
                        done = true;
                        goto endfor;
                    }
                    else
                    {
                        for (int j=i+1; j<length; ++j)
                        {
                            if (a_tab[j]-b_tab[j] >= 0)
                            {
                                c_tab[j] = a_tab[j]-b_tab[j];
                                done = true;
                                goto endfor;
                            }
                        }
                        /*if (i+1 <= length-1)
                        {
                            c_tab[i+1] = a_tab[i+1]-b_tab[i+1];
                        }*/
                    }
                }
            }
            endfor:
            /*
            a = int_tab_to_int(a_tab, length);
            // b = int_tab_to_int(b_tab, length);
            c = int_tab_to_int(c_tab, length);
            */
            if (done)
            {
                for (int i=length-1; i>=0; --i)
                    printf("%d", c_tab[i]);
            }
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