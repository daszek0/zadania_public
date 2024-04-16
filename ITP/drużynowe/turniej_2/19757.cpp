// Wild Algorithm Rangers
// zadanie Bogaty Janusz

#include <iostream>

using namespace std;

int main()
{
    char c;
    int n;
    while (cin>>c)
    {
        n += (int)(c - '0');
    }
    if (n % 3 == 0 && (int)(c - '0') % 2 == 0)
    {
        cout<<"TAK";
    }
    else
    {
        cout<<"NIE";
    }
    return 0;
}