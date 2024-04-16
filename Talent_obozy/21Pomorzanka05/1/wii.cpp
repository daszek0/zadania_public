// Jakub Daszkiewicz
// zadanie Wieże

#include <iostream>
#include <unordered_map>

using namespace std;

string pow2str(string s, int n) // słaby punkt tego rozwiązania
{
    for (int i = 0; i < n; i++)
    {
        s += s;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string inp;
    unordered_map<string, int> b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        b[inp]++;
    }
    bool ch = true;
    while (ch)
    {
        ch = false;
        for (unordered_map<string, int>::iterator it = b.begin(); it != b.end(); it++) // TAAAAAAK
        {
            for (int i = 1; 1 << i <= it -> second; i++)
            {
                if ((it -> second >> i) & 1)
                {
                    b[pow2str(it -> first, i)]++;
                    it -> second -= (1 << i);
                    ch = true;
                }
            }
        }
    }
    string::size_type a = 0;
    for (auto it : b)
    {
        if (it.second)
        {
            a = max(a, it.first.length());
        }
    }
    cout << a;
    return 0;
}