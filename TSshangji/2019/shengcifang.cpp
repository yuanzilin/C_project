#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    int hi=sqrt(n),lo=1;
    int mid=0;
    while(lo<=hi){
        mid=(hi+lo)>>1;
        if(pow(mid,m)>n)
            hi=mid-1;
        else if(pow(mid,m)<n)
            lo=mid+1;
        else{
            printf("%d",mid);
            break;
        }
    }


}