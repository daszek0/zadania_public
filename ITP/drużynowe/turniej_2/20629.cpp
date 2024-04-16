// Wild Algorithm Rangers
// zadanie Tenis ziemny

#include <iostream>

using namespace std;

int punkty[2], gemy[2], sety[2];
bool tb;

string sprawdzam()
{
    if (!tb)
    {
        if (punkty[0] >= 4 && punkty[0] >= punkty[1]+2)
        {
            gemy[0]++;
            punkty[0] = 0;
            punkty[1] = 0;
        }
        else if (punkty[1] >= 4 && punkty[1] >= punkty[0]+2)
        {
            gemy[1]++;
            punkty[0] = 0;
            punkty[1] = 0;
        }
    }
    else
    {
        if (punkty[0] >= 7 && punkty[0] >= punkty[1]+2)
        {
            sety[0]++;
            gemy[0] = 0;
            gemy[1] = 0;
            punkty[0] = 0;
            punkty[1] = 0;
            tb = 0;
        }
        else if (punkty[1] >= 7 && punkty[1] >= punkty[0]+2)
        {
            sety[1]++;
            gemy[0] = 0;
            gemy[1] = 0;
            punkty[0] = 0;
            punkty[1] = 0;
            tb = 0;
        }
    }
    if (gemy[0] == 6 && gemy[1] == 6) // tie-break
    {
        tb = 1;
    }
    else if (gemy[0] >= gemy[1]+2 && gemy[0] >= 6)
    {
        sety[0]++;
        gemy[0] = 0;
        gemy[1] = 0;
    }
    else if (gemy[1] >= gemy[0]+2 && gemy[1] >= 6)
    {
        sety[1]++;
        gemy[0] = 0;
        gemy[1] = 0;
    }
    if (sety[0] == 2) return "PIERWSZY";
    if (sety[1] == 2) return "DRUGI";
    return "";
}

int main()
{
    int n, t;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &t);
        punkty[t-1]++;
        sprawdzam();
    }
    cout<<sprawdzam();
    return 0;
}