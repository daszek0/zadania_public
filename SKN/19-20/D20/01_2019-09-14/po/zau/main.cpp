#include <iostream>

using namespace std;

float w;
int x;

int nwd(int a,int b)
{
    long long result;
    if(a>b)
    {
        for(int i=b;i>0;i--)
        {
            if(a%i==0 && b%i==0)
            {
                result=i;
                break;
            }
        }
    }
    else if(a<b)
    {
        for(int i=a;i>0;i--)
        {
            if(a%i==0 && b%i==0)
            {
                result=i;
                break;
            }
        }
    }
    else if(a==b)
        result = a;
    return result;
}

int main()
{
	cin>>w;
	x = w*1000;
	cout<<x/nwd(x,1000)<<"/"<<1000/nwd(x,1000);
    return 0;
}
