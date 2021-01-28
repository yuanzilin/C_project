#include <bits/stdc++.h>

using namespace std;

const int maxn=55;

int dp[maxn][maxn][2];
int sum[maxn];
int journey[maxn];
int p[maxn];

int n,c;
int main(){
    scanf("%d%d",&n,&c);

    //初始化sum数组
    for(int i=1;i<=n;i++){
        scanf("%d%d",&journey[i],&p[i]);
        sum[i]=sum[i-1]+p[i];
    }

    memset(dp,127, sizeof(dp));
    dp[c][c][1]=0;
    dp[c][c][0]=0;

    for(int l=2;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int j=i+l-1;
            //min(继续走；折返)
            int remain_0=sum[i]+sum[n]-sum[j];
            dp[i][j][0]=min(dp[i+1][j][0]+(journey[i+1]-journey[i])*remain_0,dp[i+1][j][1]+(journey[j]-journey[i])*remain_0);
            int remain_1=sum[i-1]+sum[n]-sum[j-1];
            dp[i][j][1]=min(dp[i][j-1][1]+(journey[j]-journey[j-1])*remain_1,dp[i][j-1][0]+(journey[j]-journey[i])*remain_1);
        }
    }
    printf("%d",min(dp[1][n][0],dp[1][n][1]));
}