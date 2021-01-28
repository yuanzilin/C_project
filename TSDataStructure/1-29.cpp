#include <stdio.h>

int len;

void H(int n){
    len++;
    if(n==1){
        return;
    }
    if(n&1){
        H(3*n+1);
    }
    else{
        H(n/2);
    }
}

int main(){
    H(4);
    printf("%d",len);
}