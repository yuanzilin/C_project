#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> w(n);
    int i;
    for(i=0;i<n;i++)
        cin>>w[i];
    vector<vector<int> > edge(n);
    vector<int> cnt(n);
    int u,v;
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        edge[u-1].push_back(v-1);
        cnt[v-1]++;
    }
    int sp=-1;
    for(i=0;i<n;i++)
        if(cnt[i]==0)
        {
            cnt[i]=sp;
            sp=i;
        }
    vector<int> index(n),numIndex(n);
    i=0;
    while(sp!=-1)
    {
        int cur=sp;
        index[i++]=cur;
        numIndex[cur]=i-1;
        sp=cnt[sp];
        for(int j=0;j<edge[cur].size();j++)
            if(--cnt[edge[cur][j]]==0)
            {
                cnt[edge[cur][j]]=sp;
                sp=edge[cur][j];
            }
    }
    vector<long long> e(n);
    for(i=0;i<n;i++)
        for(int j=0;j<edge[index[i]].size();j++)
            e[  numIndex[  edge[index[i]][j]  ]  ]=max(e[numIndex[edge[index[i]][j]]],e[i]+w[index[i]]);
    long long finish=0;
    for(i=0;i<n;i++)
        finish=max(finish,e[i]+w[index[i]]);

    vector<long long> l(n,finish);
    for(i=n-1;i>=0;i--)
        for(int j=0;j<edge[index[i]].size();j++)
            l[i]=min(l[i],l[numIndex[edge[index[i]][j]]]-w[edge[index[i]][j]]);
    cout<<l.back()<<endl;
    int mod=1e9+7;
    int ans=1;
    for(i=0;i<n;i++)
        ans=(long long)ans*(l[i]-e[i]-w[index[i]]+1)%mod;
    cout<<ans<<endl;
    return 0;
}