//3层循环，但是最里层循环中不要取模
//工厂从0开始编号,这样，0号工厂和1号工厂之间的道路编号为1号道路
//sum数组的第一维是时刻编号，第二维是工厂编号
//r数组的第一维是工厂编号，第二维是时刻编号
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=1005;
int dp[N],r[N][N],cost[N],sum[N][N];

int n,m,p;

int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&r[i%n][j]);
        }
    }
    for(int i=0;i<n;i++)
        scanf("%d",&cost[i]);

    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++)
            sum[i][j]=sum[i-1][(j-1+n)%n]+r[j][i];
    }

    memset(dp,-0x3f,sizeof dp);

    dp[0]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<=min(i,p);k++){
                int x=((j-k)%n+n)%n;
                dp[i]=max(dp[i],dp[i-k]+sum[i][j]-sum[i-k][x]-cost[x]);
            }
        }
    }
    printf("%d",dp[m]);
}
