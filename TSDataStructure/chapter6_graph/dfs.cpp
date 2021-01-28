#include <stdio.h>
#define maxn 10

typedef struct node{
    int dtime;
    int ftime;
    int out;
    int discovered;
}node;

typedef node* nodeptr;

int G[maxn][maxn];
node nodes[maxn];
int n=7;//结点的个数
int clock;

//对某个节点进行深度优先搜索
void dfs(int v){
    printf("%d ",v);
    nodes[v].dtime=++clock;
    nodes[v].discovered=1;
    for(int u=1;u<=n;u++){
        if(G[v][u]){
            //如果该节点没有被发现，那么就加入到树中，然后对这个节点继续深度遍历
            if(nodes[u].discovered==0){
                G[v][u]='t';
                dfs(u);
            }
            //如果该节点被发现了，但是u的所有邻居可能还没有被访问完，标志是u节点的ftime是否被赋值了
            else if(nodes[u].ftime==0){
                G[v][u]='b';
            }
            //如果已经被访问完了，那么如果dtime(v)<dtime(u)，那么v->u必然是一条祖先指向后代的边；如果dtime(v)>dtime(u)，那么v，u必来自两棵独立的分支
            else{
                G[v][u]=nodes[v].dtime<nodes[u].dtime?'f':'c';
            }
        }
    }
    nodes[v].ftime=++clock;
}

//检漏
void DFS(){
    for(int i=1;i<=n;i++){
        if(nodes[i].discovered==0){
            dfs(i);
        }
    }
}

//打印各条有向边的性质，t表示tree，b表示backward，f表示forward，c表示cross
void printArray(){
    printf("\n    ");
    for(int i=1;i<=n;i++){
        printf("%-3d",i);
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        printf("%-4d",i);
        for(int j=1;j<=n;j++){
            printf("%-3c",G[i][j]);
        }
        printf("\n");
    }
}

//打印各个节点的dtime和ftime
void printTime(){
    for(int i=1;i<=n;i++){
        printf("%d: dtime=%d, ftime=%d\n",i,nodes[i].dtime,nodes[i].ftime);
    }
}

int main(){
    int xi,yi;
    int len_num=10;
    //构造邻接矩阵
    for(int i=0;i<len_num;i++){
        scanf("%d%d",&xi,&yi);
        G[xi][yi]=1;
        nodes[xi].out++;
    }
    //如果想要指定从第i个节点开始深度遍历，那么就先调用dfs(i)，然后再用DFS()来检查所有节点，确保不漏
    //dfs(i);
    DFS();
    printArray();
    printTime();
}

