#include <iostream>

using namespace std;

int x, y;

int main()
{
	cin>>x>>y;
	if(x<0&&y<0) cout<<"III";
	else if(x>0&&y<0) cout<<"IV";
	else if(x>0&&y>0) cout<<"I";
	else if(x<0&&y>0) cout<<"II";

    return 0;
}
