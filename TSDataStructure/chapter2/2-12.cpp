#include <stdio.h>

int uniquify(int a[],int size){
    int i=0,j=0;
    while(++j<size){
        if(a[i]!=a[j])
            a[++i]=a[j];
    }
    size=++i;
    return size;
}

