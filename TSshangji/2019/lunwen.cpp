#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,v,u;

#define N 10005
int MOD=1000000007;

vector<int> edge[N];

int f[N];
int ans;
int t[N];

vector<int> edge_son[N];//存储儿子
int l[N];//存储最晚结束时间

int dfs(int x){
    if(f[x]) return f[x];
    for(int i=0;i<edge[x].size();i++){
        f[x]=max(f[x],dfs(edge[x][i]));
    }
    f[x]+=t[x];
    return f[x];
}

int dfs_min(int x,int ans){
    if(l[x]<ans) return l[x];
    for(int i=0;i<edge_son[x].size();i++){
        l[x]=min(l[x],dfs_min(edge_son[x][i],ans)-t[edge_son[x][i]]);
    }
    return l[x];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        edge_son[u].push_back(v);
        edge[v].push_back(u);

    }

    //找最早结束时间
    for(int i=1;i<=n;i++){
        ans=max(ans,dfs(i));
    }

    //先初始化l数组
    for(int i=1;i<=n;i++)
        l[i]=ans;

//    找最晚结束时间
    for(int i=1;i<=n;i++){
        dfs_min(i,ans);
    }

    int sum=1;
    for(int i=1;i<=n;i++){
        sum=sum*((l[i]-f[i]+1)%MOD)%MOD;
    }

    printf("%d\n%d",ans,sum);
}