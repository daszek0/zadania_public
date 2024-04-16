#include <iostream>

using namespace std;

int main()
{
    string input;
    int r = 90;
    cin>>input;
    if (input[0] == 'X')
    {
        r += (int)input[2]-48;
        r += (9-((int)input[2]-48))*100;
    }
    else
    {
        r += ((int)input[0]-48)*100;
        r += 9-((int)input[0]-48);
    }
    cout<<r;
    return 0;
}
