#include <stdio.h>
#define size 100

#define InHeap(n,i) (((-1)<(i))&&((i)<(n)))
#define Parent(i) ((i-1)>>1)
#define ParentValid(i) (i>0) //判断某节点是否有父亲
#define LChild(i) ((i*2)+1)
#define RChild(i) ((i*2)+2)
#define LChildValid(n,i) InHeap(n,LChild(i))
#define RChildValid(n,i) InHeap(n,RChild(i))
#define Bigger(i,j) ((a[i]>=a[j])?i:j)
#define ProperParent(n,i) \
                    ( RChildValid(n,i)? Bigger(Bigger(i,LChild(i)),RChild(i)):\
                      (LChildValid(n,i)? Bigger(i,LChild(i)):i)\
                    )
#define LastInternal(n) Parent(n-1)


int a[size]={3,5,2,1,6,7,8};

//获取某数组中元素的个数，函数名为getlen
int getlen(int a[]){
    int i=0;
    for(;a[i]!=0;i++);
    return i;
}

void printArray(int a[]){
    int len=getlen(a);
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

//上滤
int percolateUp(int i){
    //i是子节点，j是父节点
    while(ParentValid(i)){
        int j=Parent(i);
        if(a[i]<=a[j])
            break;
        else{
            swap(&a[i],&a[j]);
            i=j;
        }
    }
    /*用父节点下沉的方式，减少调用swap带来的大量赋值操作
    while(ParentValid(i)){
        int j=Parent(i);
        if(a[i]<=a[j])
            break;
        else{
            a[i]=a[j];//父节点的值下沉
            i=j;
        }
    }
     */

    return i;
}

int  insert(int tmp){
    int i=0;
    for(;a[i]!=0;i++);
    a[i]=tmp;
    return percolateUp(i);

    /*用父节点下沉的方式，减少调用swap带来的大量赋值操作
    int i=0;
    for(;a[i]!=0;i++);
    a[percolateUp(i)]=tmp;
    return percolateUp(i);
     */
}

//下滤
int percolateDown(int n,int i){
    int j;
    while(i!=(j=ProperParent(n,i))){
        swap(&a[i],&a[j]);
        i=j;
    }
    return i;
}

int delMax(){
    int maxElem=a[0];
    int a_len=getlen(a);
    a[0]=a[a_len-1];
    a[a_len-1]=0;
    percolateDown(--a_len,0);
    return maxElem;
}

//floyd算法建堆
void heapify(int n){
    for(int i=LastInternal(n);i>=0;i--)
        percolateDown(n,i);
}

int b[size];
void heapSort(int n){
    heapify(n);
    while(n>0){//这里的循环条件不能写成n>1，如果这样写，那么b[0]=0，你用你自己写的getlen函数求出b的数组的长度就是0了，这样也打印不出b数组了
        b[--n]=delMax();
    }
}

int main(){
    heapSort(getlen(a));
    printArray(b);
}