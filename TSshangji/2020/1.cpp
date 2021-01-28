#include<stdio.h>
int main(){
    int n,x;
    int cnt=0;
    int a=0,b=0;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        b=i;
        do{
            a=b%10;
            if(a==x)
                cnt++;
            b=b/10;
        }
        while(b);

    }
    printf("%d",cnt);
}