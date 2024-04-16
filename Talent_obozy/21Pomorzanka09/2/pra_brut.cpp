// Jakub Daszkiewicz
// zadanie Prawie równoważne słowa

#include <cstdio>
#include <vector>

using namespace std;

const int N = 1000001;

int main()
{
	int n;
	scanf("%d", &n);
	char w[N], p[N];
	scanf("%s %s", w, p);
	int dc, cl;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		dc = 0;
		cl = i;
		for (int j = 0; j < n; j++)
		{
			if (w[cl] != p[j])
			{
				dc++;
			}
			if (dc > 1)
			{
				break;
			}
			cl++;
			if (cl == n)
			{
				cl = 0;
			}
		}
		if (dc <= 1)
		{
			a.push_back(i);
		}
	}
	if (a.size())
	{
		printf("TAK\n");
		for (auto i : a)
		{
			printf("%d ", i);
		}
	}
	else
	{
		printf("NIE\n");
	}
	return 0;
}