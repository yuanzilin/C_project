//
// Created by 17999 on 2020/10/9.
// 这段代码的基础是根据输入序列构成相应的二叉搜索树
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}node;

typedef node* nodeptr;

nodeptr root=NULL;

nodeptr insertBST(nodeptr p,int a){
    if(p==NULL){
        p=new node();
        p->data=a;
        p->left=p->right=NULL;
    }
    else{
        if(a<p->data){
            p->left=insertBST(p->left,a);
        }
        else{
            p->right=insertBST(p->right,a);
        }
    }
    return p;
}

nodeptr build(int a[],int len){
    for(int i=0;i<len;i++){
        root=insertBST(root,a[i]);
    }
    return root;
}

nodeptr searchIn(nodeptr v,int key,nodeptr hot){
    if(!v)
        return hot;
    if(v->data==key)
        return v;
    hot=v;
    return searchIn(((v->data<=key)?v->right:v->left),key,hot);
}

int main(){
    int a[10]={33};
    root=build(a,1);

    printf("%d",searchIn(root,15,NULL)->data);
}

