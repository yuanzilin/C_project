#include <stdio.h>

const int board_size=8;
int board[board_size][board_size]={0};
int tile=1;

void chess(int tr,int tc,int dr,int dc,int size){
    if(size==1)
        return;
    int t=tile++;
    int sz=size/2;
    //左上角子棋盘
    if(dr<tr+sz&&dc<tc+sz){
        chess(tr,tc,dr,dc,sz);
    }else{
        board[tr+sz-1][tc+sz-1]=t;
        chess(tr,tc,tr+sz-1,tc+sz-1,sz);
    }

    //右上角子棋盘
    if(dr<tr+sz&&dc>=tc+sz){
        chess(tr,tc+sz,dr,dc,sz);

    }else{
        board[tr+sz-1][tc+sz]=t;
        chess(tr,tc+sz,tr+sz-1,tc+sz,sz);
    }

    //左下角子棋盘
    if(dr>=tr+sz&&dc<tc+sz){
        chess(tr+sz,tc,dr,dc,sz);
    }else{
        board[tr+sz][tc+sz-1]=t;
        chess(tr+sz,tc,tr+sz,tc+sz-1,sz);
    }

    //右下角子棋盘
    if(dr>=tr+sz&&dc>=tc+sz){
        chess(tr+sz,tc+sz,dr,dc,sz);
    }else{
        board[tr+sz][tc+sz]=t;
        chess(tr+sz,tc+sz,tr+sz,tc+sz,sz);
    }
}

void printBoard(){
    for(int i=0;i<board_size;i++){
        for(int j=0;j<board_size;j++){
            printf("%d  ",board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    chess(0,0,3,4,board_size);
    printBoard();
}