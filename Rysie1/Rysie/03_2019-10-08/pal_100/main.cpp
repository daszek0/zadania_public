#include <bits/stdc++.h>

using namespace std;

string check(string w)
{
    for (int i=0; i<w.length()/2; i++)
    {
        if (w[i] != w[w.length()-1-i])
            return "NIE";
    }
    return "TAK";
}

int main()
{
    vector <string> result;
    string input;
    //cin >> input
    for (;;)
    {
        cin>>input;
        if (input == "**")
            break;
        else
            result.push_back(check(input));
    }
    for (int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<"\n";
    }
    return 0;
}
