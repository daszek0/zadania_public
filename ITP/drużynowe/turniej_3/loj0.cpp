// Wild Algorithm Rangers
// zadanie Lojban

#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string n, r;
    cin>>n;
    for (int i=0; i<n.length(); i++)
    {
        switch(n[i])
        {
            case '0':
            {
                r += "no";
                break;
            }
            case '1':
            {
                r += "pa";
                break;
            }
            case '2':
            {
                r += "re";
                break;
            }
            case '3':
            {
                r += "ci";
                break;
            }
            case '4':
            {
                r += "vo";
                break;
            }
            case '5':
            {
                r += "mu";
                break;
            }
            case '6':
            {
                r += "xa";
                break;
            }
            case '7':
            {
                r += "ze";
                break;
            }
            case '8':
            {
                r += "bi";
                break;
            }
            case '9':
            {
                r += "so";
                break;
            }
        }
    }
    cout<<r;
    return 0;
}