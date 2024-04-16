// Jakub Daszkiewicz
// zadanie Zdjęcia

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct event
{
	int c;
	int n;
	bool operator<(const event &e) const
	{
		if (c == e.c)
		{
			return n;
		}
		return c < e.c;
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	event t;
	vector<event> h, v;
	int l, d, r, u;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &l, &d, &r, &u);
		t.n = 1;
		t.c = l;
		h.push_back(t);
		t.n = -1;
		t.c = r;
		h.push_back(t);
		t.n = 1;
		t.c = d;
		v.push_back(t);
		t.n = -1;
		t.c = u;
		v.push_back(t);
	}
	sort(h.begin(), h.end());
	sort(v.begin(), v.end());
	int hm = -__INT_MAX__ - 1, ch = 0, vm = -__INT_MAX__ - 1, cv = 0;
	for (unsigned int i = 0; i < h.size(); i++)
	{
		ch += h[i].n;
		hm = max(hm, ch);
	}
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cv += v[i].n;
		vm = max(vm, cv);
	}
	printf("%d\n", min(hm, vm));
	return 0;
}