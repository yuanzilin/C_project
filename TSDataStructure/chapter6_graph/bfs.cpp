#include <stdio.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <cstring>

#define maxn 100005

using namespace std;

int n,m;

typedef struct node{
    int op;
    int level;
    struct node * next;
}node;

typedef node* nodeptr;

nodeptr cities[maxn];
bool visited[maxn];
queue<nodeptr > myqueue;

int min_lone_city(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        printf("%d=%d ",i,visited[i]);
        if(!visited[i])
            cnt++;
    }
    printf("\n");
    return cnt;
}

nodeptr insertline(int xi,int yi){
    nodeptr new_y=new node;
    new_y->op=yi;
    new_y->level=0;
    new_y->next=NULL;
    if(cities[xi]==NULL){
        cities[xi]=new node;
        cities[xi]->op=xi;
        cities[xi]->level=0;
        cities[xi]->next=new_y;
    }else{
        nodeptr p,q;
        for(p=cities[xi],q=p->next;q!=NULL;p=q,q=q->next){
        }
        p->next=new_y;
    }
}

void make_two_line(int xi,int yi){
    insertline(xi,yi);
    insertline(yi,xi);
}

void print_array(){
    nodeptr p,q;
    int i;
    for(i=1;i<=n;i++){
        if(cities[i]){
            printf("%d ",i);
            for(p=cities[i],q=p->next;q!=NULL;p=q,q=q->next){
                printf("%-3d",q->op);
            }
            printf("\n");
        }
    }
}

int bfs(int start){
    int level;
    nodeptr p,q;
    myqueue.push(cities[start]);
    while (!myqueue.empty()){
        nodeptr tmp=myqueue.front();
        if(tmp==NULL)
            return -1;
        level=tmp->level+1;//开始遍历这一层的节点
        myqueue.pop();
        if(visited[tmp->op])
            continue;
        visited[tmp->op]=true;
        for(p=tmp,q=p->next;q!=NULL;p=q,q=p->next){
            if(!visited[q->op]){
                cities[q->op]->level=level;
                myqueue.push(cities[q->op]);
            }
            else{
                if(q->op==start&&p->level>1){
                    return p->level+1;
                }
            }
        }
    }
    return -1;
}

void BFS(){
    int result=10000;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cities[j]->level=0;
        }
        int tmp=bfs(i);
        if(tmp>0&&result>tmp){
            result=tmp;
        }
    }
    printf("min_road=%d\n",result);
}


int main(){
    scanf("%d%d",&n,&m);
    int xi,yi;
    for(int i=0;i<m;i++){
        scanf("%d%d",&xi,&yi);
        make_two_line(xi,yi);
    }
    print_array();
    BFS();
    printf("%d\n",min_lone_city(n));
}