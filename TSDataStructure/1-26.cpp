#include <stdio.h>

void swap(int& a,int& b){
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}

void reverse(int *A,int lo,int hi){
    if(lo<hi){
        swap(A[lo],A[hi]);
        reverse(A,lo+1,hi-1);
    }
}

//左移k位
void shift(int A[],int n,int k){
    reverse(A,0,k-1);
    reverse(A,k,n-1);
    reverse(A,0,n-1);
}

int main(){
    int len=8;
    int A[8]={0,1,2,3,4,5,6,7};
    shift(A,len,3);
    for(int i=0;i<len;i++){
        printf("%d ",A[i]);
    }
}