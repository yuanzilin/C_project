//这道题我偷懒了，只是实现了书上的思路，但是没有debug，也没有跑过
#include <stdio.h>
#include <stdlib.h>

int len=10;

int a[15]={41,67,34,0,69,24,78,58,2,64};//记录输入
int bucket[15][15];//记录每个桶中的数

typedef struct node{
    int full;
    int left;
    int right;
    int len;
}node;

typedef node* nodeptr;

//不知道这样会不会申请一个野指针数组
nodeptr record[15];//记录每个桶中的最大值和最小值

nodeptr result;//记录结果

int hash(int x,int lo,int hi){
    return (len-1)*(x-lo)/(hi-lo);
}

//把元素插入到桶中
void insertBucket(int x,int op){
    bucket[op][record[op]->full++]=x;
}

//寻找某个桶中的最大和最小值
void getleft_and_right(int op){
    if(record[op]->full==0)
        return;
    record[op]->right=0;
    record[op]->left=1000;
    int len=record[op]->full;
    for(int i=0;i<len;i++){
        if(bucket[op][i]>record[op]->right)
            record[op]->right=bucket[op][i];
        if(bucket[op][i]<record[op]->left)
            record[op]->left=bucket[op][i];
    }
}

int main() {
    int i=0;
//    for(;i<len;i++){
//        a[i]=rand()%100;
//        printf("a[%d]=%d ",i,a[i]);
//    }
//    printf("\n");
    //找到最大值和最小值
    int lo=1000;
    int hi=0;
    for(i=0;i<len;i++){
        if(a[i]<lo)
            lo=a[i];
        if(a[i]>hi)
            hi=a[i];
    }

    //把各个数映射到桶中
    int op;
    for(i=0;i<len;i++){
        op=hash(a[i],lo,hi);
        insertBucket(a[i],op);
    }

    //获取每个桶中的最大值和最小值
    for(i=0;i<len;i++){
        getleft_and_right(i);
    }

    //对每对桶进行最终的查找
    result=new node;
    result->len=0;
    for(i=0;i<len;){
        while(record[i]->full==0)
            i++;
        int j=i+1;
        while (record[j]->full==0)
            j++;
        if(record[j]->left-record[j]->right>result->len){
            result->len=record[j]->left-record[j]->right;
            result->left=record[i]->right;
            result->right=record[j]->left;
        }

        i=j;
    }

    printf("left=%d,right=%d,len=%d",result->left,result->right,result->len);
}