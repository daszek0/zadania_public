#include <iostream>

using namespace std;

int nwd(int x,int y)
{
    int result;
    if(x>y)
    {
        for(int i=y;i>0;i--)
        {
            if(x%i==0 && y%i==0)
            {
                result=i;
                break;
            }
        }
    }
    else if(x<y)
    {
        for(int i=x;i>0;i--)
        {
            if(x%i==0 && y%i==0)
            {
                result=i;
                break;
            }
        }
    }
    return result;
}

int nww(int x,int y)
{
    return x/nwd(x,y)*y;
}

int main()
{
	unsigned int a, b, d;
	int tablica[1000];
	cin>>a>>b;
	d = 1;
	for(int i=1;i<=1000;i++)
    {
        tablica[i-1]=nww(a+i,b+i);
    }
    for(int i=0;i<1000;i++)
        cout<<tablica[i]<<"\n";

    //cout<<d;

    return 0;
}
