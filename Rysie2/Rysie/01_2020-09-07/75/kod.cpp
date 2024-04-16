// Jakub Daszkiewicz
// zadanie KOD

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	bool ic[n + 1];
	fill(ic, ic+n+1, false);
	int t;
	vector <int> c;
	priority_queue <int, vector <int>, greater <int>> o;
	for (int i=0; i<n-2; i++)
	{
		scanf("%d", &t);
		c.push_back(t);
		ic[t] = true;
	}
	reverse(c.begin(), c.end());
	for (int i=1; i<n+1; i++)
	{
		if (!ic[i]) o.push(i);
	}
	vector <pair <int, int>> con;
	pair <int, int> co;
	int lv;
	while (!o.empty())
	{
		if (!c.empty())
		{
			co.first = c.back();
			lv = c.back();
			co.second = o.top();
			if (co.first > co.second) swap(co.first, co.second);
			c.pop_back();
			o.pop();
			if (!c.empty() && c.back() != lv) o.push(lv);
			if (c.empty()) o.push(lv);
		}
		else
		{
			co.first = o.top();
			o.pop();
			co.second = o.top();
			o.pop();
		}
		con.push_back(co);
	}
	sort(con.begin(), con.end());
	for (int i=0; i<con.size(); i++)
	{
		printf("%d %d\n", con[i].first, con[i].second);
	}
	return 0;
}