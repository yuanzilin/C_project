#include <stdio.h>

class Fib{
private:
    int f=1,g=0;
public:
    Fib(int n){
        while(g<n){
            g=g+f;
            f=g-f;
        }
    };
    int get(){
        return g;
    };
    int next(){
        g=g+f;
        f=g-f;
        return g;
    };
    int prev(){
        f=g-f;
        g=g-f;
        return g;
    };

    Fib() {

    }
};

//线性递归
long long fibL(int n,long long& prev){
    if(n==0){
        prev=1;
        return 0;
    }
    else{
        long long pPrev;
        prev=fibL(n-1,pPrev);
        return prev+pPrev;
    }
}

//迭代
int fibI(int n){
    int f=1,g=0;
    while(0<n--){
        g+=f;
        f=g-f;
    }
    return g;
}

int main(){
    Fib f=Fib(6);
    printf("%d",f.get());

}