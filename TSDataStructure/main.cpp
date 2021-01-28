#include <cstdio>
#include <cstdlib>

int main()
{
    int len=15;
    for(int i=0;i<len;i++){
        printf("%d:%d\n",i,rand()%100);
    }

    int del_len=5;
    for(int i=0;i<del_len;i++){
        printf("%d\n",rand()%15);
    }
}
