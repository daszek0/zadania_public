// Jakub Daszkiewicz
// zadanie Dysortografia

#include <iostream>

using namespace std;

int main()
{
    int n, r = 0;
    cin>>n;
    string o, w;
    cin>>o>>w;
    for (int i=0; i<n; i++)
    {
        if (o[i] == w[i]) r++;
    }
    cout<<r;
    return 0;
}