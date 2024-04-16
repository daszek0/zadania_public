#include <iostream>
#include <string>

using namespace std;

int main()
{
    string N;
    cin>>N;
    if (N.substr(N.length()-2, 2) == "00")
        cout<<"TAK";
    else
        cout<<"NIE";
    return 0;
}
