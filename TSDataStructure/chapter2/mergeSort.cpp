#include <stdio.h>
#include <algorithm>
#include <vector>

int len=2;

//int a[10]={4,3,2,5,6,4,3,2,66,43};
int a[10]={5,4};

void merge(int a[],int lo,int mi,int hi){
    //复制前子向量
    int *aleft=new int[mi-lo];
    int len_left=mi-lo;
    for(int i=0;i<len_left;i++){
        aleft[i]=a[lo+i];
    }
    //复制后子向量
    int *aright=new int[hi-mi];
    int len_right=hi-mi;
    for(int i=0;i<len_right;i++){
        aright[i]=a[mi+i];
    }
    //开始比较
    for(int i=lo,j=0,k=0;k<len_right;){
        if(j<len_left&&(aleft[j]<=aright[k])){
            a[i++]=aleft[j++];
        }
        if(j>=len_left||(aright[k]<aleft[j]))
            a[i++]=aright[k++];
    }
//    for(int i=lo,j=0,k=0;j<len_left;){
//        if(k<len_right&&(aleft[j]>aright[k])){
//            a[i++]=aright[k++];
//        }
//        if(k>=len_right||(aright[k]>=aleft[j]))
//            a[i++]=aleft[j++];
//    }
}

//要求划分的子区间为[lo,mi)和[mi,hi)
void mergeSort(int a[],int lo,int hi){
    if(hi-lo==1)
        return;
    int mi=(lo+hi)>>1;
    mergeSort(a,lo,mi);
    mergeSort(a,mi,hi);
    merge(a,lo,mi,hi);
}

int main(){
    mergeSort(a,0,len);
    for(int i=0;i<len;i++){
        printf("%d ",a[i]);
    }

    int myints[]={32,71,42,90};
    std::vector<int>myvector(myints,myints+4);
    std::sort(myvector.begin(),myvector.begin()+4);
}