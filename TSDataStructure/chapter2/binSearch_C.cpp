#include <stdio.h>

//[lo,hi)
int binsearch_C(int a[],int key,int lo,int hi){
    while (lo<hi){
        int mi=(lo+hi)>>1;
        (key<a[mi])?hi=mi:lo=mi+1;
    }
    return --lo;
}