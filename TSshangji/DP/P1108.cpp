#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 5005;
int p[N],dp[N],num[N];
int n;
int max_dp;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }

    for(int i=0;i<n;i++){
        //最长下降子序列
        for(int j=0;j<i;j++){
            if(p[j]>p[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
        if(!dp[i])
            dp[i]=1;
        max_dp=max(max_dp,dp[i]);

        //以p[i]为结尾的方案数
        for(int j=0;j<i;j++){
            if(dp[j]==dp[i]&&p[j]==p[i])
                num[j]=0;
            //方案的累积来自于这里
            else if(dp[j]+1==dp[i]&&p[j]>p[i])
                num[i]+=num[j];
        }
//        方案数的初始值来自于此
        if(!num[i])
            num[i]=1;
    }

    int sum=0;
    for(int i=0;i<n;i++){
        if(dp[i]==max_dp)
            sum+=num[i];
    }
    printf("%d %d",max_dp,sum);
}
