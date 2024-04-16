// Jakub Daszkiewicz
// zadanie Tuzin jaj

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x;
    for (int i=0; i<n; i++)
    {
        cin >> x;
        cout << x/12 << "\n";
    }
    return 0;
}