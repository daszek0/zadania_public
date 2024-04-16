#include <stdio.h>

using namespace std;

int main()
{
    int _0, _1;
    scanf("%d %d", &_0, &_1);
    if (_0 == _1) printf("%d=%d", _0, _1);
    else
    {
        if (_0 < _1) printf("%d<%d", _0, _1);
        else printf("%d>%d", _0, _1);
    }
    return 0;
}
