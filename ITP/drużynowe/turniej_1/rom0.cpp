// Wild Algorithm Rangers
// zadanie Dominik i słownik

#include <stdio.h>

using namespace std;

long long n,m;

bool skip[4000];

int main()
{
    for(int i=1;i<4000;i++){
        if(i/1000==4||i/1000==9){
            skip[i]=true;
        }else if((i/100)%10==4||(i/100)%10==9){
            skip[i]=true;
        }else if((i/10)%10==4||(i/10)%10==9){
            skip[i]=true;
        }else if(i%10==4||i%10==9){
            skip[i]=true;
        }
    }

    scanf("%lld",&n);

    for(int i=1;i<4000;i++){
        if(skip[i]) m++;
        if(m==n){
            printf("%d",i);
            return 0;
        }
    }

    printf("%lld",n+m);

    return 0;
}