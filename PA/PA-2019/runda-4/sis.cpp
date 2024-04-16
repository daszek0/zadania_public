// Jakub Daszkiewicz
// zadanie Szprotki i Szczupaki [B]
//
// test 1: 4 1 4 8 1 15 1 2 3 1 2 4 1 2 5 1 3 3 1 3 5 1 3 16 1 4 16 1 8 17 1 100 101 1 100 115 1 3 9 2 2 1 3 9 3 4 1 3 9 => 1 2 -1 0 2 4 3 2 1 -1 3 2 -1

#include <stdio.h>
#include <vector>
#include <algorithm>

#define ull unsigned long long

using namespace std;

vector<ull> fish;

void fish_erase_value(ull value)
{
    ull begin = 0, end = fish.size()-1, check;
    while (true)
    {
        check = (begin+end)/2;
        if (fish[check] > value)
            end = check;
        else if (fish[check] < value)
            begin = check;
        else
        {
            fish.erase(fish.begin()+check);
            return;
        }
    }
}

ull fish_find_uneaten(ull value, bool e[])
{
   for (ull i=0; i<fish.size(); i++)
    {
        if (fish[i] == value && !e[i])
            return i;
    }
    return 18446744073709551615;
}

ull fish_find_greater(ull value)
{
    for (ull i=0; i<fish.size(); i++)
    {
        if (fish[i] >= value) return i;
    }
    return fish.size();
}

bool less_true(bool b[], ull v)
{
    for (int i=v-1; i>=0; i--)
    {
        if (b[i] == false) return false;
    }
    return true;
}

int main()
{
    ull fish_amount;
    scanf("%llu", &fish_amount);
    ull t;
    for (ull i=0; i<fish_amount; i++)
    {
        scanf("%llu", &t);
        fish.push_back(t);
    }
    sort(fish.begin(), fish.end());
    ull q, p_w, p_g;
    long long r;
    scanf("%llu", &q);
    unsigned int type;
    for (ull p=0; p<q; p++)
    {
        scanf("%u", &type);
        switch (type)
        {
            case 1:
            {
                r = 0;
                scanf("%llu%llu", &p_w, &p_g);
                bool eaten[fish.size()] = {};
                while (true)
                {
                    if (p_w >= p_g) break;
                    for (ull i=p_w-1; i>0; i--)
                    {
                        if (fish_find_uneaten(i, eaten) == 18446744073709551615) continue;
                        else
                        {
                            p_w += i;
                            eaten[fish_find_uneaten(i, eaten)] = true;
                            r++;
                            break;
                        }
                    }
                    if (p_w < p_g && less_true(eaten, fish_find_greater(p_w)))
                    {
                        r = -1;
                        break;
                    }
                }
                printf("%lld\n", r);
                break;
            }
            case 2:
            {
                scanf("%llu", &t);
                fish.push_back(t);
                sort(fish.begin(), fish.end());
                break;
            }
            case 3:
            {
                scanf("%llu", &t);
                fish_erase_value(t);
                break;
            }
        }
    }
    return 0;
}