#include <bits/stdc++.h>

using namespace std;

const int N=500005;

struct edge{
    int to;
    int w;
    int nxt;
}E[N*2];

int id;
int head[N];
void add(int u,int v,int w){
    E[++id]=((edge){v,w,head[u]});
    head[u]=id;
}

long long ans;
int depth[N];
void dfs(int fa,int x){
    //求这棵子树的深度
    for(int i=head[x];i!=0;i=E[i].nxt){
        int y=E[i].to;
        int z=E[i].w;
        if(y==fa)
            continue;
        dfs(x,y);
        depth[x]=max(depth[x],depth[y]+z);
    }

    //调整这棵子树的各个子树为等长
    for(int i=head[x];i!=0;i=E[i].nxt){
        int y=E[i].to;
        int z=E[i].w;
        if(y==fa)
            continue;
        ans+=depth[x]-(depth[y]+z);
    }
}

int n,st;
int u,v,w;
int main(){
    scanf("%d%d",&n,&st);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }

    dfs(0,st);
    printf("%lld",ans);

}