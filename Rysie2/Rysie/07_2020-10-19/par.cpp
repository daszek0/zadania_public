// Jakub Daszkiewicz
// zadanie Liczby parzystocyfrowe

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    unsigned long long n;
    vector <char> a;
    scanf("%llu", &n);
    while (n > 0)
    {
        a.push_back((n % 5) * 2 + '0');
        n /= 5;
    }
    for (int i=a.size()-1; i>=0; i--)
    {
        putchar_unlocked(a[i]);
    }
    return 0;
}