//我就做初次可以推断的吧
#include <stdio.h>
#define maxn 1005
#define maxm 1005

int array[maxn][maxm];

typedef struct Node{
    int hang;
    int lie;
    int val;
    Node *next;
}node;

typedef struct Node2{
    int cnt;
    int delta;
}node2;

node2 heng[maxn],shu[maxm];


typedef node* nodeptr;

int n,m;

int main(){

    scanf("%d%d",&n,&m);
    int i,j;
    for(j=0;j<m;j++){
        shu[j].cnt=0;
        shu[j].delta=-1;
    }

    for(i=0;i<n;i++){
        heng[i].cnt=0;
        heng[i].delta=-1;
        for(j=0;j<m;j++){
            scanf("%d",&array[i][j]);
            if(array[i][j]!=0){
                heng[i].cnt++;
                shu[j].cnt++;
            }
        }
    }
    int a=0,ai=0,aj=0;
    int b=0,bi=0,bj=0;

    //求每一行的公差
    for(i=0;i<n;i++){
        a=0,ai=0;
        if(heng[i].cnt<=1)
            continue;
        for(j=0;j<m;j++){
            if(array[i][j]==0)
                continue;
            if(a==0){
                a=array[i][j];
                ai=j;
            }
            else{
                b=array[i][j];
                bi=j;
                heng[i].delta=(b-a)/(bi-ai);
                break;
            }
        }
    }

    //求每一列的公差
    for(j=0;j<m;j++){
        a=0,aj=0;
        if(shu[j].cnt<=1)
            continue;
        for(i=0;i<n;i++){
            if(array[i][j]==0){
                continue;
            }
            if(a==0){
                a=array[i][j];
                aj=i;
            } else{
                b=array[i][j];
                bj=i;
                shu[j].delta=(b-a)/(bj-aj);
                break;
            }
        }
    }

    //补数据
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(array[i][j]){
                continue;
            }
            if(heng[i].delta>=0){
                if(j==0){
                    int k=0;
                    for(;k<m&&array[i][k]==0;k++);
                    array[i][j]=array[i][k]-heng[i].delta*k;

                }
                else{
                    array[i][j]=array[i][j-1]+heng[i].delta;
                }
                printf("%d %d %d\n",i+1,j+1,array[i][j]);

            }
            else if(shu[j].delta>=0){
                if(i==0){
                    int k=0;
                    for(;k<=n&&array[k][j]==0;k++);
                    array[i][j]=array[k][j]-shu[j].delta*k;
                }
                else{
                    array[i][j]=array[i-1][j]+shu[j].delta;
                }
                printf("%d %d %d",i+1,j+1,array[i][j]);
            }
        }
    }


}