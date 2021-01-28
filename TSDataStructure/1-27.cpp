#include <stdio.h>

int acm(int m,int n){
    if(m==0)
        return n+1;
    if(n==0)
        return acm(m-1,1);
    return acm(m-1,acm(m,n-1));
}

int main(){
    printf("%d",acm(2,1));
}