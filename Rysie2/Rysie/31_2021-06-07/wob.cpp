// Jakub Daszkiewicz
// zadanie Wielki Obserwator

#include <cstdio>
#include <algorithm>

using namespace std;

struct Event
{
	double tg;
	int a, d, id;
	// bool operator<(Event e)
	// {
	// 	// if (tg == e.tg)
	// 	if (abs(tg - e.tg) < 0.000000001)
	// 		return d < e.d;
	// 	return tg < e.tg;
	// }
};

bool comp(Event e, Event e1)
{
	if (abs(e.tg - e1.tg) < 0.000000001)
			return e.d < e1.d;
		return e.tg < e1.tg;
}

int main()
{
	int n, x, y, l;
	scanf("%d", &n);
	Event e[n << 1];
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x, &y, &l);
		e[i << 1].tg = double(x) / double(y + l);
		e[i << 1].a = 1;
		e[i << 1].d = x + y;
		e[i << 1].id = i;
		e[(i << 1) + 1].tg = double(x + l) / double(y);
		e[(i << 1) + 1].a = -1;
		e[(i << 1) + 1].d = x + y;
		e[(i << 1) + 1].id = i;
	}
	sort(e, e + (n << 1), comp);
	int s[n], c = 0, a = 0;
	for (int i = 0; i < (n << 1); i++)
	{
		if (e[i].a == 1)
			s[e[i].id] = c;
		else if (s[e[i].id] == c - 1)
			a++;
		c += e[i].a;
	}
	printf("%d", a);
	return 0;
}