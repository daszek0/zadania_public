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
    vector <string> word;
    string input;
    for (;;)
    {
        cin>>input;
        if (input != "**")
            word.push_back(input);
        else
            break;
    }

    for (int i=0; i<word.size(); i++)
    {
        cout<<check(word[i])<<"\n";
    }

    return 0;
}
