//dp[i][j][k][1]表示对字母j进行j次修改，对字母z进行k次修改后，s[i]为z，所能获得的最大价值，如果不存在对应的方案，那f[i][j][k][1]就取为非法值
//这个非法值是一个很大的负数
//dp[i][j][k][0]表示对字母j进行j次修改，对字母z进行k次修改后，s[i]为j，所能获得的最大价值
//初始化的另一步是，默认1号位前面都是已经匹配好的，所以dp[0][0][0][1]=0
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=505,maxk=105;
char s[maxn];
int dp[maxn][maxk][maxk][2];
int n,m;

int main(){
    scanf("%d%d%s",&n,&m,s+1);
    memset(dp,128, sizeof(dp));
    dp[0][0][0][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int z=0;z<=m;z++){
                if(s[i]=='z'){
                    //如果这个字符为z，而且要修改成z
                    dp[i][j][z][1]=max(dp[i-1][j][z][0]+1,dp[i-1][j][z][1]);
                    //如果这个字符为z，而且要修改成j
                    if(z)
                        dp[i][j][z][0]=max(dp[i-1][j][z-1][0],dp[i-1][j][z-1][1]);
                }
                else{
                    //如果这个字符为j，而且要修改成j
                    dp[i][j][z][0]=max(dp[i-1][j][z][0],dp[i-1][j][z][1]);
                    //如果这个字符为j，而且要修改成z
                    if(j)
                        dp[i][j][z][1]=max(dp[i-1][j-1][z][0]+1,dp[i-1][j-1][z][1]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++)
        ans=max(ans,max(dp[n][i][i][0],dp[n][i][i][1]));
    printf("%d",ans);
}