// Jakub Daszkiewicz
// zadanie Odgadywanie

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin.tie();
    ios_base::sync_with_stdio(false);
    cin>>n;
    string str;
    for (int i=0; i<n; i++)
    {
        cin>>str;
        if ((int)(str[str.length()-1] - '0') % 2)
        {
            cout<<"L\n";
        }
        else
        {
            cout<<"P\n";
        }
    }
    return 0;
}