#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

#define maxn 600

using namespace std;

struct edge{
    int to;
    int w;
    int nxt;
}E[maxn*2];

int id,head[maxn];

void add(int u,int v,int w){
    E[++id]=((edge){v,w,head[u]});
    head[u]=id;
}

int k,father[maxn],dis[maxn];
int mark[maxn];

void dfs(int f,int x){
    father[x]=f;
    if(dis[x]>dis[k])
        k=x;
    for(int e=head[x];e!=0;e=E[e].nxt){
        int y=E[e].to;
        if(y==f||mark[y])
            continue;
        dis[y]=dis[x]+E[e].w;
        dfs(x,y);
    }
}

int n,s;
int u,v,w;
int top;
int ecc;
int min_ecc=100000010;
int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n-1;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }

    //找直径
    dfs(0,1);
    dis[k]=0;
    dfs(0,k);
    top=k;

    //树上尺取
    for(int i=top,j=top;i!=0;i=father[i]){
        while(dis[j]-dis[i]>s)
            j=father[j];
        ecc=max(dis[top]-dis[j],dis[i]);
        min_ecc=min(ecc,min_ecc);
    }

    //标记直径
    for(int i=top;i!=0;i=father[i])
        mark[i]=1;

//    找非直径上的点到直径的距离
    for(int i=top;i!=0;i=father[i]){
        dis[i]=0;
        dfs(father[i],i);
    }

    for(int i=1;i<=n;i++)
        min_ecc=max(min_ecc,dis[i]);

    printf("%d",min_ecc);
}