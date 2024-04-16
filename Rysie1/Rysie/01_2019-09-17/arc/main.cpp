#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, r=0, rr=0;
    string word;
    cin>>n;
    cin>>word;
    for (int i=0;i<n;i++)
    {
        for (int j=1;;j++)
        {
            if(word[i+j-1]!=word[i+j] && i+j<n)
            {
                r++;
            }
            else
                break;
        }
        if (rr<r)
        {
            rr = r;
        }
        r = 0;
    }
    cout<<rr+1;
    return 0;
}
