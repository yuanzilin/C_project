#include <bits/stdc++.h>

using namespace std;

const int maxn=205;

int s_image[maxn][maxn],s_reality[maxn][maxn];
int f_image[maxn][maxn],f_reality[maxn][maxn];
int visit[maxn][maxn];
int score[maxn][maxn];
int n,m,k;
char c[3];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d%s",&score[i][j],c);
            if(c[0]=='Y')
                visit[i][j]=1;
        }
    }

    //计算s_i和s_r
    for(int i=1;i<=m;i++){
        //cnt表示实际用的子弹个数
        int cnt=0;
        for(int j=n;j>=1;j--){
            if(visit[j][i])
                s_image[i][cnt]+=score[j][i];
            else{
                cnt++;
                s_image[i][cnt]=s_image[i][cnt-1]+score[j][i];
                s_reality[i][cnt]=s_image[i][cnt-1]+score[j][i];
            }
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=0;j<=k;j++){
            //p表示第i列可以用p颗子弹
            for(int p=0;p<=j&&p<=n;p++){
                f_image[i][j]=max(f_image[i][j],f_image[i-1][j-p]+s_image[i][p]);
                if(p){
                    //如果p>=1，那么第i列可以借一些子弹给前i-1列
                    f_reality[i][j]=max(f_reality[i][j],f_image[i-1][j-p]+s_reality[i][p]);
                }
                if(j-p){
                    //如果j-p>=1，那么前i-1列可以借一些子弹给第i列
                    f_reality[i][j]=max(f_reality[i][j],f_reality[i-1][j-p]+s_image[i][p]);
                }
            }
        }
    }

    printf("%d",f_reality[m][k]);
}