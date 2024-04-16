// Jakub Daszkiewicz
// zadanie Coroczna Bajtocka Tradycja

#include <iostream>
#include <stdio.h>

using namespace std;

string lowercase(string s)
{
    string r = "";
    for (int i=0; i<s.length(); i++)
    {
        r += tolower(s[i]);
    }
    return r;
}

int main()
{
    string name, surname, login;
    cin>>name>>surname>>login;
    string check = "";
    check += name[0];
    check += surname;
    if (login == lowercase(check)) printf("WPUSCIC RYCERZA\n");
    else printf("ZGLADZIC RYCERZA\n");
    return 0;
}
