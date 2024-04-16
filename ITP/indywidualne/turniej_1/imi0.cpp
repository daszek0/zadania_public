#include <stdio.h>

using namespace std;

int main()
{
    char letter;
    letter = getchar_unlocked();
    switch (letter)
    {
        case 'G':
        {
            printf("Pawel");
            break;
        }
        case 'L':
        {
            printf("Krzysztof");
            break;
        }
        case 'N':
        {
            printf("Rafal");
            break;
        }
        case 'P':
        {
            printf("Karol");
            break;
        }
        case 'U':
        {
            printf("Przemyslaw");
            break;
        }
    }
    return 0;
}