#include <stdio.h>
int gcd(int a,int b){
    int p=1;
    while((!(a&1))&&(!(b&1))){
        p<<=1;
        a>>=1;
        b>>=1;
    }
    int t=a>b?a-b:b-a;
    while(t){
        while(!(t&1)){
            t>>=1;
        }
        if(a>=b){
            a=t;
        }else{
            b=t;
        }
        t=a>b?a-b:b-a;
    }
    return a*p;
}
int main(){
    printf("%d",gcd(4,6));
}