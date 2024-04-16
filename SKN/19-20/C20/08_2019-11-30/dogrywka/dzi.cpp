// Jakub Daszkiewicz
// zadanie Dziewczynki
//
// test 1: 8 3 0 1 1 0 1 0 1 0 => 2
// test m1: 3 2 0 1 0 => 1

#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int people, girls_row, temp, r = 2147483647;
    vector<int> girls_places;
    scanf("%d %d", &people, &girls_row);
    for (int i=0; i<people; ++i)
    {
        scanf("%d", &temp);
        if (temp == 0) girls_places.push_back(i);
    }

    if (girls_places.size() >= girls_row)
    {
        for (int i=0; i<=girls_places.size()-girls_row; ++i)
        {
            temp = girls_places[i+girls_row-1]-girls_places[i]-(girls_row-1);
            if (temp < r) r = temp;
        }
        printf("%d", r);
    }
    else printf("NIE");
    return 0;
}