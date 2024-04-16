#include <iostream>

using namespace std;

int main()
{
	int n,result;
	cin>>n;
	if(n%2==0)
        result = n;
    else
        result = n*2;
	cout<<result;
    return 0;
}
