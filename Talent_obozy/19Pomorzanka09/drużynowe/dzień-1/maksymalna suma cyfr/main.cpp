#include <iostream>

using namespace std;

int sumacyfr(int x)
{
    int r = 0;
    while (x/10 >= 10)
    {
        r += x%10;
        x /= 10;
    }
    // r += x%10;
    return r;
}

int main()
{
    cout << sumacyfr(2137) << endl;
    return 0;
}
