#include <iostream>

using namespace std;

int main()
{
    int g;
    cin>>g;
    g %= 12;
    if (g == 0)
    {
        cout<<"0";
    }
    else
    {
        int t11 = g*60;
        int r = t11/11;
        int l = t11%11;
        if (l == 0)
        {
            cout<<r;
        }
        else
        {
            cout<<r<<" "<<l<<"/11";
        }
    }

    return 0;
}
