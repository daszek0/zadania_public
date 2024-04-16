// Jakub Daszkiewicz
// zadanie Silnia

#include <iostream>

using namespace std;

int main()
{
    string n;
    cin>>n;
    if (n.length() == 1)
    {
        switch (n[0])
        {
            case '1':
            {
                printf("1");
                break;
            }
            case '2':
            {
                printf("2");
                break;
            }
            case '3':
            {
                printf("6");
                break;
            }
            case '4':
            {
                printf("4");
                break;
            }
            default:
            {
                printf("0");
                break;
            }
        }
    }
    else printf("0");
    return 0;
}