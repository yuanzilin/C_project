#include <bits/stdc++.h>

using namespace std;

const int G=105,D=105;

struct rubbish{
    int t;
    int v;
    int h;
    bool operator < (const rubbish &r) const{
        return t<r.t;
    }
}r[G];

int d,g;
//dp[i][j]表示遍历到第i个垃圾，并且高度为j的时候，奶牛的最大生命
int dp[G][D];

int main(){
    scanf("%d%d",&d,&g);
    for(int i=1;i<=g;i++){
        scanf("%d%d%d",&r[i].t,&r[i].v,&r[i].h);
    }
    sort(r+1,r+g+1);
    memset(dp,128,sizeof dp);
    dp[0][0]=10;
    int res=-1000;
    for(int i=1;i<=g;i++){
        for(int j=d;j>=0;j--){
            if(j+r[i].h>=d&&dp[i-1][j]>=r[i].t-r[i-1].t){
                printf("%d",r[i].t);
                return 0;
            }
            if(dp[i-1][j]<r[i].t-r[i-1].t)
                continue;

            //吃，还是不吃？
            //这个j，相当于上一轮沿用i-1中的状态，来修改i中的状态
            //而这第一个状态，则是沿用了j+1中，吃掉当前垃圾得到的最大生命值
            dp[i][j+r[i].h]=max(dp[i][j+r[i].h],dp[i-1][j]-(r[i].t-r[i-1].t));
            //如果这个j可以让奶牛熬到第i个垃圾扔进来，那么要维持这个高度，那就只能把这个垃圾给吃了
            dp[i][j]=dp[i-1][j]+r[i].v-(r[i].t-r[i-1].t);

        }
        res=max(res,dp[i][0]+r[i].t);
    }
    printf("%d",res);
}
