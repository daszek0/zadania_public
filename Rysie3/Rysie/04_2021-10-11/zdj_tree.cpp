// Jakub Daszkiewicz
// zadanie Zdjęcia

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct event
{
	int o, v, f, t;
	bool operator<(const event &e) const
	{
		if (o == e.o)
		{
			return v > e.v;
		}
		return o < e.o;
	}
};

const int N = 1 << 20, F = 200001;
int tv[N], pv[N];

void push(int n)
{
	pv[n << 1] += pv[n];
	tv[n << 1] += pv[n];
	pv[(n << 1) + 1] += pv[n];
	tv[(n << 1) + 1] += pv[n];
	pv[n] = 0;
}

void add(int n, int f, int t, int nf, int nt, int v)
{
	if (f > nt || t < nf)
		return;
	if (f <= nf && nt <= t)
	{
		tv[n] += v;
		pv[n] += v;
	}
	else
	{
		push(n);
		add(n << 1, f, t, nf, (nf + nt) >> 1, v);
		add((n << 1) + 1, f, t, (nf + nt + 1) >> 1, nt, v);
		tv[n] = max(tv[n << 1], tv[(n << 1) + 1]);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	event t;
	vector<event> h;
	h.reserve(n << 1);
	int l, d, r, u;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &l, &d, &r, &u);
		l += F;
		d += F;
		r += F;
		u += F;
		t.v = 1;
		t.o = l;
		t.f = d;
		t.t = u;
		h.push_back(t);
		t.v = -1;
		t.o = r;
		h.push_back(t);
	}
	h.shrink_to_fit();
	sort(h.begin(), h.end());
	long long m = 0;
	for (auto i : h)
	{
		add(1, i.f, i.t, 0, (N >> 1) - 1, i.v);
		m = max(m, (long long)tv[1]);
	}
	printf("%lld\n", m);
	return 0;
}