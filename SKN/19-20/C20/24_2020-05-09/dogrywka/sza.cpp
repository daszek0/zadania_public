// Jakub Daszkiewicz
// zadanie Szachy

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    int points[h][w];
    int tlmax[h+1][w+1];
    int trmax[h+1][w+1];
    int blmax[h+1][w+1];
    int brmax[h+1][w+1];
    for (int y=0; y<h+1; y++) for (int x=0; x<w+1; x++)
    {
        tlmax[y][x] = 0;
        trmax[y][x] = 0;
        blmax[y][x] = 0;
        brmax[y][x] = 0;
    }
    for (int y=0; y<h; y++) for (int x=0; x<w; x++) scanf("%d", &points[y][x]);
    for (int y=1; y<=h; y++) for (int x=1; x<=w; x++) tlmax[y][x] = max(points[y-1][x-1], max(tlmax[y-1][x], tlmax[y][x-1]));
    for (int y=1; y<=h; y++) for (int x=w-1; x>=0; x--) trmax[y][x] = max(points[y-1][x], max(trmax[y-1][x], trmax[y][x+1]));
    for (int y=h-1; y>=0; y--) for (int x=1; x<=w; x++) blmax[y][x] = max(points[y][x-1], max(blmax[y+1][x], blmax[y][x-1]));
    for (int y=h-1; y>=0; y--) for (int x=w-1; x>=0; x--) brmax[y][x] = max(points[y][x], max(brmax[y+1][x], brmax[y][x+1]));
    int a = 0, c = 0;
    for (int y=0; y<h; y++) for (int x=0; x<w; x++)
    {
        c = points[y][x] + tlmax[y][x];
        a = max(a, c);
        c = points[y][x] + trmax[y][x+1];
        a = max(a, c);
        c = points[y][x] + blmax[y+1][x];
        a = max(a, c);
        c = points[y][x] + brmax[y+1][x+1];
        a = max(a, c);
    }
    printf("%d", a);
    return 0;
}