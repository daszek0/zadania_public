#include <iostream>

using namespace std;

int minvaluefromarray(int a[], int b, int c)
{
    int result=a[0];
    int place=0;
    for(int i=1;i<b;i++)
    {
        if (a[i]<result)
        {
            result=a[i];
            place=i;
        }
    }
    if (c==0)
        return result;
    else if (c==1)
        return place;
    else
        return -1;
}

int main()
{
    int r=10;
	int tablica[r] = {0, 3, 4, 3, 6, 7, 11, -5, -10, 87};

	cout <<minvaluefromarray(tablica,r,'a')<<minvaluefromarray(tablica,r,'b')<< endl;
    return 0;
}
