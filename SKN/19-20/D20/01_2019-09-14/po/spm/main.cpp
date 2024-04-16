#include <iostream>

using namespace std;

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

int n, a, b;

int main()
{
	cin>>n;

	a = n/nwd(n,1440);
	b = 1440/nwd(n,1440);

	cout<<a<<"/"<<b;
}
