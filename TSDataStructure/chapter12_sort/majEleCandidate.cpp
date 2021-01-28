#include <stdio.h>
int len=10;
int a[100]={3,2,1,3,2,1,3,3,3,3};

int majSelect(int a[],int len){
    int cnt=0,result=0;
    for(int i=0;i<len;i++){
        if(cnt==0){
            result=a[i];
            cnt++;
        }
        else{
            result==a[i]?cnt++:cnt--;
        }
    }
    return result;
}

int main(){
    printf("%d",majSelect(a,len));
}