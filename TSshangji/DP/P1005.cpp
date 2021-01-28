#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN=85,mod=10000;
int n,m;
int ar[MAXN];

struct HP{
    int p[505],len;
    HP(){
        memset(p,0, sizeof p);
        len=0;
    }//构造函数，创建一个高精度变量
    //四位压缩输出
    void print(){
        printf("%d",p[len]);
        for(int i=len-1;i>0;i--){
            if(p[i]==0){
                printf("0000");
                continue;
            }
            for(int k=10;k*p[i]<mod;k*=10)
                printf("0");
            printf("%d",p[i]);
        }
    }
}f[MAXN][MAXN],base[MAXN],ans;

//高精度+高精度
HP operator + (const HP &a, const HP &b){
    HP c;
    c.len=max(a.len,b.len);
    int x=0;
    for(int i=1;i<=c.len;i++){
        c.p[i]=a.p[i]+b.p[i]+x;
        x=c.p[i]/mod;
        c.p[i]=c.p[i]%mod;
    }
    if(x>0){
        c.p[++c.len]=x;
    }
    return c;
}

//高精度*单精度
HP operator * (const HP &a, const int &b){
    HP c;
    c.len=a.len;
    int x=0;
    for(int i=1;i<=c.len;i++){
        c.p[i]=a.p[i]*b+x;
        x=c.p[i]/mod;
        c.p[i]=c.p[i]%mod;
    }
    while(x>0){
        c.p[++c.len]=x%mod;
        x/=mod;
    }
    return c;
}

//max(高精度,高精度)
HP _max(const HP &a,const HP &b){
    if(a.len<b.len)
        return b;
    if(a.len>b.len)
        return a;
    for(int i=a.len;i>0;i--){
        if(a.p[i]>b.p[i])
            return a;
        if(a.p[i]<b.p[i])
            return b;
    }
    return a;
}

void BaseTwo(){
    base[0].p[1]=1,base[0].len=1;
    for(int i=1;i<=m;i++){
        base[i]=base[i-1]*2;
    }
}

//f[i][j]表示区间变为[i,j]时，已经取得的最大得分
int main(){
    scanf("%d%d",&n,&m);
    BaseTwo();
    while(n--){
        for(int i=1;i<=m;i++){
            scanf("%d",&ar[i]);
        }
        for(int i=1;i<=m;i++){
            for(int j=m;j>=i;j--){
                f[i][j]=_max(f[i-1][j]+base[m-(j-i+1)]*ar[i-1],f[i][j+1]+base[m-(j-i+1)]*ar[j+1]);
            }
        }
        HP max;
        for(int i=1;i<=m;i++){
            max=_max(max,f[i][i]+base[m]*ar[i]);
        }
        ans=ans+max;
    }
    ans.print();
}