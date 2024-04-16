// Jakub Daszkiewicz
// zadanie Korale

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string b;
    cin >> b;
    for (int i = 1; i < n; i++)
    {
        if (b[i - 1] == b[i])
        {
            cout << "NIE\n";
            return 0;
        }
    }
    if (b[0] == b[n - 1])
    {
        cout << "NIE\n";
        return 0;
    }
    cout << "TAK\n";
    return 0;
}