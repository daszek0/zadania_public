// Jakub Daszkiewicz
// zadanie Przycinanie drzewa

#include <cstdio>
#include <vector>

using namespace std;

struct Edge
{
	int destination;//, nodes_of_color[3];
	int connection_id;
};

const int N = 300000;
int color[N]; // 1 - red, 2 - blue
vector<Edge> graph[N];
int nodes_of_color[N - 1][2][3];

void dfs(int node, int color_counter[], int node_previous)
{
	color_counter[color[node]]++;
	for (auto connection : graph[node])
	{
		if (connection.destination != node_previous)
		{
			for (int color = 0; color < 3; color++)
			{
			// 	connection.nodes_of_color[color] += color_counter[color];
				nodes_of_color[connection.connection_id][(connection.destination > node) ? 1 : 0][color] += color_counter[color];
			}
			dfs(connection.destination, color_counter, node);
		}
	}
	color_counter[color[node]]--;
}

int main()
{
	int nodes;
	scanf("%d", &nodes);
	for (int node = 0; node < nodes; node++)
	{
		scanf("%d", &color[node]);
	}
	int connection_input[2];
	Edge connection;
	// fill(connection.nodes_of_color, connection.nodes_of_color + 3, 0);
	for (int connection_id = 0; connection_id < nodes - 1; connection_id++)
	{
		scanf("%d %d", &connection_input[0], &connection_input[1]);
		connection_input[0]--;
		connection_input[1]--;
		connection.connection_id = connection_id;
		connection.destination = connection_input[1];
		graph[connection_input[0]].push_back(connection);
		connection.destination = connection_input[0];
		graph[connection_input[1]].push_back(connection);
	}
	int color_counter[3];
	for (int node = 0; node < nodes; node++)
	{
		if (graph[node].size() == 1)
		{
			fill(color_counter, color_counter + 3, 0);
			dfs(node, color_counter, -1);
		}
	}
	int answer = 0;
	for (int connection_id = 0; connection_id < nodes - 1; connection_id++)
	{
		if ((nodes_of_color[connection_id][0][1] == 0 && nodes_of_color[connection_id][1][2] == 0) || (nodes_of_color[connection_id][1][1] == 0 && nodes_of_color[connection_id][0][2] == 0))
			answer++;
	}
	printf("%d", answer);
	return 0;
}