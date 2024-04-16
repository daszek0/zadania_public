#include <stdio.h>
#include <vector>

using namespace std;

int check(bool tab[], int begin, int end)
{
    int r = 0;
    for (int i=begin+1; i<end; ++i)
        if (tab[i] == 1) ++r;
    return r;
}

int main()
{
    int people, girls_row, temp, r = 2147483647;
    vector<int> girls_places;
    scanf("%d %d", &people, &girls_row);
    bool person[people];
    for (int i=0; i<people; ++i)
    {
        scanf("%d", &temp);
        person[i] = temp;
        if (temp == 0) girls_places.push_back(i);
    }

    if (girls_places.size() >= girls_row)
    {
        for (int i=0; i<=girls_places.size()-girls_row; ++i)
        {
            temp = check(person, girls_places[i], girls_places[i+girls_row-1]);
            if (temp < r) r = temp;
        }
        printf("%d", r);
    }
    else printf("NIE");
    return 0;
}