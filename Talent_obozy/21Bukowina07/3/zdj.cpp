// Jakub Daszkiewicz
// zadanie Zdjęcia

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct event
{
	short c;
	short n;
	// bool operator<(const event &e) // nie działa nie wiem czemu
	// {
	// 	if (c == e.c)
	// 	{
	// 		// return n; // tutaj się wywala
	// 		// printf("dupa");
	// 		if (n == 1)
	// 			return true;
	// 		else
	// 			return false;
	// 	}
	// 	return c < e.c;
	// }
};

bool comp(event e0, event e1)
{
	if (e0.c == e1.c) // tutaj się wywala
	{
		// return e0.n;
		if (e0.n == 1)
		{
			return e0.c == e1.c;
		}
		else
		{
			return e0.c < e1.c;
		}
	}
	return e0.c < e1.c;
}

int main()
{
	unsigned short n;
	scanf("%hu", &n);
	event t;//, h[n << 1], v[n << 1];
	vector<event> h, v;
	h.reserve(n << 1);
	v.reserve(n << 1);
	short l, d, r, u;
	for (unsigned short i = 0; i < n; i++)
	{
		scanf("%hd %hd %hd %hd", &l, &d, &r, &u);
		t.n = 1;
		t.c = l;
		// h[i << 1] = t;
		h.push_back(t);
		t.n = -1;
		t.c = r;
		// h[(i << 1) + 1] = t;
		h.push_back(t);
		t.n = 1;
		t.c = d;
		// v[i << 1] = t;
		v.push_back(t);
		t.n = -1;
		t.c = u;
		// v[(i << 1) + 1] = t;
		v.push_back(t);
	}
	h.shrink_to_fit();
	v.shrink_to_fit();
	// sort(h, h + (n << 1));
	// sort(v, v + (n << 1));
	sort(h.begin(), h.end(), comp);
	sort(v.begin(), v.end(), comp);
	short hm = -32768, ch = 0, vm = -32768, cv = 0;
	// ch += h[0].n ? short(1) : short(-1);
	ch += h[0].n;
	hm = max(hm, ch);
	for (unsigned short i = 1; i < h.size(); i++)
	{
		// ch += h[i].n ? short(1) : short(-1);
		ch += h[i].n;
		hm = max(hm, ch);
	}
	// cv += v[0].n ? short(1) : short(-1);
	cv += v[0].n;
	vm = max(vm, cv);
	for (unsigned short i = 1; i < v.size(); i++)
	{
		// cv += v[i].n ? short(1) : short(-1);
		cv += v[i].n;
		vm = max(vm, cv);
	}
	printf("%hd\n", min(hm, vm));
	return 0;
}