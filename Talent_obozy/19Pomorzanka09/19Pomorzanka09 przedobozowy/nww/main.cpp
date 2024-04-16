#include <iostream>

using namespace std;

int nwd(int x,int y)
{
    long long result;
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
    else if(x==y)
        result = x;
    return result;
}

int nww(int x,int y)
{
    return x/nwd(x,y)*y;
}

int main()
{
	int a, b;
	long long d;
	cin>>a>>b;
	d = 1;
	for(int i=1;i<nww(a+i,b+i);i++)
    {
        if(nww(a+i,b+i)<nww(a+d,b+d))
            d = i;
    }

    cout<<d;

    return 0;
}
