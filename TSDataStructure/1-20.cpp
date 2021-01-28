#include <stdio.h>
#include <malloc.h>

struct Matrix{
    int a[2][2];
};

//矩阵乘法
Matrix matrixmulti(int a[][2],int b[][2]){
    Matrix c;
    int i=0,j=0,k=0;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            c.a[i][j]=0;
            for(k=0;k<2;k++){
                c.a[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return c;
}

//计算{{0,1},{1,1}}矩阵的n次方
Matrix computeArray(int n){
    Matrix result,pow;
    result.a[0][0]=1;
    result.a[0][1]=0;
    result.a[1][0]=0;
    result.a[1][1]=1;
    pow.a[0][0]=0;
    pow.a[0][1]=1;
    pow.a[1][0]=1;
    pow.a[1][1]=1;
    while (0<n){
        if(n&1){
            result=matrixmulti(pow.a,result.a);
        }
        pow=matrixmulti(pow.a,pow.a);
        n>>=1;
    }
    return result;
}

//计算n>=3的斐波那契数列
int fib(int n){
    Matrix bigmatrix=computeArray(n-2);
    return bigmatrix.a[1][0]+bigmatrix.a[1][1];
}

int main(){
    printf("%d",fib(8));
}