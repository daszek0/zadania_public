#include <iostream>
#include <stdio.h>
#include <vector>
// #include <string>

using namespace std;

bool counter[8][8];
bool counterAttacked[8][8];
int queen[2][2];

vector <char> positions[2];

string input;

int main()
{
    /*getline(cin,input);
    int j = 0;
    for (int i=0; i<input.length(); i++)
    {
        if (input[i] != ' ')
        {
            positions[j%2].push_back(input[i]);
            j++;
        }
    }*/
    int j = 0;

    char x;
    while(x != '\eof')
    {
        cin>>x;
        positions[j%2].push_back(x);
        j++;
        //if (cin.eof())
            //break;
    }

    for (int i=0; i<positions[0].size()-2; i++)
        counter[(int)positions[0][i]-97][(int)positions[1][i]-48] = true;

    queen[0][0] = (int)positions[0][positions[0].size()-1]-97;
    queen[0][1] = (int)positions[1][positions[0].size()-1]-48;
    queen[1][0] = (int)positions[0][positions[0].size()-2]-97;
    queen[1][1] = (int)positions[1][positions[0].size()-2]-48;

    int k;
    for (int i=0; i<2; i++)
    {
        j = queen[i][0]-1;
        k = queen[i][1];
        while (j >= 0 && j <= 7 && k >= 0 && k <= 7)
        {
            if (counter[j][k] == true)
            {
                counterAttacked[j][k] = true;
                break;
            }
            j--;
        }

        j = queen[i][0]-1;
        k = queen[i][1]+1;
        while (j >= 0 && j <= 7 && k >= 0 && k <= 7)
        {
            if (counter[j][k] == true)
            {
                counterAttacked[j][k] = true;
                break;
            }
            j--;
            k++;
        }

        j = queen[i][0];
        k = queen[i][1]+1;
        while (j >= 0 && j <= 7 && k >= 0 && k <= 7)
        {
            if (counter[j][k] == true)
            {
                counterAttacked[j][k] = true;
                break;
            }
            k++;
        }

        j = queen[i][0]+1;
        k = queen[i][1]+1;
        while (j >= 0 && j <= 7 && k >= 0 && k <= 7)
        {
            if (counter[j][k] == true)
            {
                counterAttacked[j][k] = true;
                break;
            }
            j++;
            k++;
        }

        j = queen[i][0]+1;
        k = queen[i][1];
        while (j >= 0 && j <= 7 && k >= 0 && k <= 7)
        {
            if (counter[j][k] == true)
            {
                counterAttacked[j][k] = true;
                break;
            }
            j++;
        }

        j = queen[i][0]+1;
        k = queen[i][1]-1;
        while (j >= 0 && j <= 7 && k >= 0 && k <= 7)
        {
            if (counter[j][k] == true)
            {
                counterAttacked[j][k] = true;
                break;
            }
            j++;
            k--;
        }

        j = queen[i][0];
        k = queen[i][1]-1;
        while (j >= 0 && j <= 7 && k >= 0 && k <= 7)
        {
            if (counter[j][k] == true)
            {
                counterAttacked[j][k] = true;
                break;
            }
            k--;
        }

        j = queen[i][0]-1;
        k = queen[i][1]-1;
        while (j >= 0 && j <= 7 && k >= 0 && k <= 7)
        {
            if (counter[j][k] == true)
            {
                counterAttacked[j][k] = true;
                break;
            }
            j--;
            k--;
        }
    }

    int r = 0;
    for (int i=0; i<8; i++)
    {
        for (int ii=0; ii<8; ii++)
        {
            if (counterAttacked[i][ii] == true)
                r++;
        }
    }

    printf("%d", r);

    return 0;
}
