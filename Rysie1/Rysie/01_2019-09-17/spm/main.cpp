#include <iostream>

using namespace std;

int n;

int nwd(int a, int b)
{
    int result;
    if (a>b)
    {
        for(int i=a;i>0;i--)
        {
            if (a%i==0 && b%i==0)
            {
                result = i;
                break;
            }
        }
    }
    else if (a<b)
    {
        for(int i=b;i>0;i--)
        {
            if (a%i==0 && b%i==0)
            {
                result = i;
                break;
            }
        }
    }
    else if (a==b)
        result=a;
    return result;
}

int main()
{
    cin>>n;

    cout<<n/nwd(n,1440)<<"/"<<1440/nwd(n,1440);

    return 0;
}
