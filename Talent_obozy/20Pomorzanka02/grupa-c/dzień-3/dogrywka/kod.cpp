// Jakub Daszkiewicz
// zadanie Kodowanie permutacji

// test 1: 7 0 0 1 0 2 0 4

#include <stdio.h>

using namespace std;

const int N=32767;
const int R=65536;
int tree[R];

void add (int w, int val)
{
	tree[w]+=val;
	if (w==1) return;
	else add(w/2,val);
}

int query (int w, int v)
{
	if (w > N) return w-N;
    if (tree[2*w] >= v) return query(2*w, v);
    else return query(2*w+1, v-tree[2*w]);
}

int main()
{
    int n;
    scanf("%d", &n);
    int b[n], a[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &b[i]);
        add(N+i+1, 1);
    }
    for (int i=n-1; i>=0; i--)
    {
        if (i+1-b[i] <= 0)
        {
            printf("NIE\n");
            return 0;
        }
        a[i] = query(1, i+1-b[i]);
        add(N+a[i], -1);
    }
    for (int i=0; i<n; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}