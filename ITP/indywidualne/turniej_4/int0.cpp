// Jakub Daszkiewicz
// zadanie Integracja

#include <stdio.h>

using namespace std;

int I, M, D, init_I, init_M, init_D;
char first;
int *f = &I;

void result(char c);

void place(char c)
{
    switch (c)
    {
        case 'I':
        {
            if (I == 0) return;
            putchar_unlocked('I');
            I--;
            result('I');
            return;
        }
        case 'M':
        {
            if (M == 0) return;
            putchar_unlocked('M');
            M--;
            result('M');
            return;
        }
        case 'D':
        {
            if (D == 0) return;
            putchar_unlocked('D');
            D--;
            result('D');
            return;
        }
    }
}

void result(char c)
{
    if (*f == 0 || c == first)
    {
        if (c == 'I')
        {
            // if (M == D)
            // {
            //     if (init_M > init_D)
            //     {
            //         place('M');
            //         return;
            //     }
            //     else
            //     {
            //         place('D');
            //         return;
            //     }
            // }
            if (M > D)
            {
                place('M');
                return;
            }
            else
            {
                place('D');
                return;
            }
        }
        if (c == 'M')
        {
            // if (I == D)
            // {
            //     if (init_I > init_D)
            //     {
            //         place('I');
            //         return;
            //     }
            //     else
            //     {
            //         place('D');
            //         return;
            //     }
            // }
            if (I > D)
            {
                place('I');
                return;
            }
            else
            {
                place('D');
                return;
            }
        }
        if (c == 'D')
        {
            // if (I == M)
            // {
            //     if (init_I > init_M)
            //     {
            //         place('I');
            //         return;
            //     }
            //     else
            //     {
            //         place('M');
            //         return;
            //     }
            // }
            if (I > M)
            {
                place('I');
                return;
            }
            else
            {
                place('M');
                return;
            }
        }
    }
    else
    {
        place(first);
        return;
    }
}

void result0()
{
    if (I > M && I > D)
    {
        first = 'I';
        f = &I;
        place('I');
        return;
    }
    else if (M > I && M > D)
    {
        first = 'M';
        f = &M;
        place('M');
        return;
    }
    else
    {
        first = 'D';
        f = &D;
        place('D');
        return;
    }

}

int main()
{
    scanf("%d %d %d", &I, &M, &D);
    init_I = I;
    init_M = M;
    init_D = D;
    if (!((I <= M + D) && (M <= I + D) && (D <= M + I)))
    {
        printf("NIE");
        return 0;
    }
    printf("TAK\n");
    result0();
    return 0;
}