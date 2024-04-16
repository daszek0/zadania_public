#include <stdio.h>

using namespace std;

int main()
{
    int king, queen, rook, knight, bishop, pawn;
    scanf("%d %d %d %d %d %d", &king, &queen, &rook, &knight, &bishop, &pawn);
    king = 1-king;
    queen = 1-queen;
    rook = 2-rook;
    knight = 2-knight;
    bishop = 2-bishop;
    pawn = 8-pawn;
    printf("%d %d %d %d %d %d", king, queen, rook, knight, bishop, pawn);
    return 0;
}
