#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=2005;

int n,m;
int up[maxn][maxn],left[maxn][maxn],right[maxn][maxn];
int bit[maxn][maxn];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&bit[i][j]);
            left[i][j]=right[i][j]=j;
            up[i][j]=1;
        }
    }

    //设置左边界
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(bit[i][j]!=bit[i][j-1])
                left[i][j]=left[i][j-1];
        }
    }

    //设置右边界
    for(int i=1;i<=n;i++){
        for(int j=m-1;j>=1;j--){
            if(bit[i][j]!=bit[i][j+1])
                right[i][j]=right[i][j+1];
        }
    }

//    开始循环
    int kuan=0;
    int rect=0;
    int sq=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>1&&bit[i][j]!=bit[i-1][j]){
                up[i][j]=up[i-1][j]+1;
                left[i][j]=max(left[i][j],left[i-1][j]);
                right[i][j]=min(right[i][j],right[i-1][j]);
            }
            kuan=right[i][j]-left[i][j]+1;
            rect=max(rect,kuan*up[i][j]);
            sq=max(sq,min(up[i][j],kuan)*min(up[i][j],kuan));
        }
    }
    printf("%d\n%d",sq,rect);
}