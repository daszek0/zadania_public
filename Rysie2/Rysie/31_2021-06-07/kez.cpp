// Jakub Daszkiewicz
// zadanie Kozy Julii

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int width, height, goats, queries, x, y, x1, y1;
	long long counter, point_previous, sum;
	vector<pair<int, int>> left, right, up, down; // -1 - koza, x - początek przedziału nr x
	scanf("%d %d %d %d", &width, &height, &goats, &queries);
	long long answer[300000];
	fill(answer, answer + 300000, 0);
	for (int i = 0; i < goats; i++)
	{
		scanf("%d %d", &x, &y);
		left.push_back(make_pair(x, -1));
		right.push_back(make_pair(x, -1));
		up.push_back(make_pair(y, -1));
		down.push_back(make_pair(y, -1));
	}
	for (int i = 0; i < queries; i++)
	{
		scanf("%d %d %d %d", &x, &x1, &y, &y1);
		left.push_back(make_pair(x1, i));
		right.push_back(make_pair(x, i));
		up.push_back(make_pair(y, i));
		down.push_back(make_pair(y1, i));
	}
	sort(left.begin(), left.end(), greater<pair<int, int>>());
	sort(right.begin(), right.end());
	sort(up.begin(), up.end());
	sort(down.begin(), down.end(), greater<pair<int, int>>());
	counter = 0;
	point_previous = 0;
	sum = 0;
	for (auto i : left)
	{
		sum += counter * abs(i.first - point_previous);
		if (i.second == -1)
		{
			counter++;
		}
		else
		{
			answer[i.second] += sum;
		}
		point_previous = i.first;
	}
	counter = 0;
	point_previous = 0;
	sum = 0;
	for (auto i : right)
	{
		sum += counter * abs(i.first - point_previous);
		if (i.second == -1)
		{
			counter++;
		}
		else
		{
			answer[i.second] += sum;
		}
		point_previous = i.first;
	}
	counter = 0;
	point_previous = 0;
	sum = 0;
	for (auto i : up)
	{
		sum += counter * abs(i.first - point_previous);
		if (i.second == -1)
		{
			counter++;
		}
		else
		{
			answer[i.second] += sum;
		}
		point_previous = i.first;
	}
	counter = 0;
	point_previous = 0;
	sum = 0;
	for (auto i : down)
	{
		sum += counter * abs(i.first - point_previous);
		if (i.second == -1)
		{
			counter++;
		}
		else
		{
			answer[i.second] += sum;
		}
		point_previous = i.first;
	}
	for (int i = 0; i < queries; i++)
	{
		printf("%lld\n", answer[i]);
	}
	return 0;
}