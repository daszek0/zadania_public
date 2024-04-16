#include <stdio.h>
#include <vector>

using namespace std;

/*void findconnections(vector <int> v[])
{

}*/


int main()
{
    int cities, connections, queries;
    scanf("%d", &cities);
    vector<int> connection[cities];
    scanf("%d", &connections);
    int a, b;
    for (int i=0; i<connections; i++)
    {
        scanf("%d %d", &a, &b);
        connection[a-1].push_back(b-1);
        connection[b-1].push_back(a-1);
    }
    //vector<int> graph[cities];
    for (int i=0; i<cities; i++)
    {
        for (int j=0; j<connection[i].size(); i++)
        {
            for (int k=0; k<connection[connection[i][j]].size(); k++)
            {
                bool exists = false;
                for(int l=0; l<connection[i].size(); l++)
                {
                    if (connection[i][l] == connection[connection[i][j]][k])
                    {
                        exists = true;
                        break;
                    }
                }
                if (i != connection[connection[i][j]][k] && exists == false)
                    connection[i].push_back(connection[connection[i][j]][k]);
            }
            /*for (int k=connection[i][j]; k<connection[j].size(); k++)
            {
                bool exists = false;
                for(int l=0; l<connection[i].size(); l++)
                {
                    if (connection[i][l] == connection[j][k])
                        exists = true;
                }
                if (i != connection[j][k] && exists == false)
                    connection[i].push_back(connection[j][k]);
            }*/
        }
    }




    scanf("%d", &queries);
    for (int i=0; i<queries; i++)
    {
        bool connected = false;
        scanf("%d %d", &a, &b);
        for (int i=0; i<connection[a-1].size(); i++)
        {
            if (connection[a-1][i] == b)
            {
                connected = true;
                break;
            }
        }
        if (connected == true)
            printf("1");
        else
            printf("0");
    }

    return 0;
}
