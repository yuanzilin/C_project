#include<ctime>
#include<cstdio>
#include<cstdlib>
#include <cmath>

#define MAXN 100

char a[3]="YN";
int main(){
    srand((unsigned)time(NULL));
    int n,m;
    n=rand()%6+1;
    m=rand()%5+1;
    int k=rand()%5+1;
    printf("%d %d %d\n",n,m,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int l=rand()%20+1;
            printf("%d %c ",l,a[rand()%2]);
        }
        printf("\n");
    }

}
