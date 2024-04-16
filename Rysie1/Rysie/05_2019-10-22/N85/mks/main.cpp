#include <stdio.h>

using namespace std;

int main()
{
    int k, n, r = -2147483648;
	scanf("%d %d", &n, &k);
	int a[n];
	for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<n-k+1; i++)
    {
        int sum = 0;
        for (int j=i; j<i+k; j++) sum += a[j];
        if (sum > r) r = sum;
    }
    printf("%d", r);
    return 0;
}
