// Jakub Daszkiewicz
// zadanie Montażysta

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Movie
{
	int id; // numer filmu
	int time; // czas montowania
	int deadline; // termin publikacji
	bool operator<(const Movie &m) const
	{
		if (deadline == m.deadline)
		{
			return time < m.time;
		}
		return deadline < m.deadline;
	}
};

int main()
{
	int movie_count; // liczba filmów
	scanf("%d", &movie_count);
	Movie movies[movie_count]; // filmy
	for (int i = 0; i < movie_count; i++)
	{
		scanf("%d %d", &movies[i].time, &movies[i].deadline);
		movies[i].id = i + 1;
	}
	sort(movies, movies + movie_count);
	int time_used = 0; // czas wykorzystany
	vector<pair<int, int>> answers;
	for (int i = 0; i < movie_count; i++)
	{
		if (time_used + movies[i].time <= movies[i].deadline)
		{
			answers.push_back(make_pair(movies[i].id, time_used + 1));
			time_used += movies[i].time;
		}
	}
	printf("%lu\n", answers.size());
	for (auto i : answers)
	{
		printf("%d %d\n", i.first, i.second);
	}
	return 0;
}