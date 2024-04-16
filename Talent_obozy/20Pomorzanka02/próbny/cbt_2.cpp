// Jakub Daszkiewicz
// zadanie Coroczna Bajtocka Tradycja

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    char n;
    scanf("%c", &n);
    string surname, login;
    while (scanf("%c") != ' ')
    {
        cin>>surname>>login;
    }
    if (n+32 == login[0] && surname[0]+32 == login[1] && surname.substr(1, surname.length()-1) == login.substr(2, login.length()-2)) printf("WPUSCIC RYCERZA\n");
    else printf("ZGLADZIC RYCERZA\n");
    return 0;
}