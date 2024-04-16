//Wild Algorithm Rangers
//Gra w usuwanie

#include <stdio.h>

using namespace std;

int bruh[1000001];
int n,x;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        bruh[x]++;
    }

    for(int i=1000000;i>=0;i--){
        if(bruh[i]%2==1){
            printf("Lukasz");
            return 0;
        }
    }

    printf("Marcin");

    return 0;
}