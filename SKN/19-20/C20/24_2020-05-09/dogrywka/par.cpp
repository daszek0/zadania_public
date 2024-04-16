// Jakub Daszkiewicz
// zadanie Liczby parzystocyfrowe

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    unsigned long long n;
    scanf("%llu", &n);
    vector <char> r;
    while (n > 0)
    {
        r.push_back((n % 5 * 2) + '0');
        n /= 5;
    }
    for (int i=r.size()-1; i>=0; i--)
    {
        putchar_unlocked(r[i]);
    }
    return 0;
}