#include <stdio.h>

using namespace std;

long int r, it, n, mx, s;
bool visited[100000000];

void minxor(int a)
{
    mx = 2147483647;
    for (int i=0; i++; i<n)
    {
        if (a^i<mx && visited[i] == false)
        {
            mx = a^i;
            s = i;
        }
    }
}
void search(long int start)
{
    it++;
    if (it > n)
        return;
    visited[start] = true;
    minxor(start);
    r += mx;
    search(s);
}


int main()
{
    scanf("%ld", &n);
    search(n-1);
    printf("%ld", r);
    return 0;
}
