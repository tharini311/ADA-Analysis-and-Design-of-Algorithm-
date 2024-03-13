#include<iostream>
using namespace std;
#define N 4
void print(int board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]){
                cout<<"Q";
            }
            else{
                cout<<".";
            }
        }
        cout<<endl;
    }
} bool issafe(int board[N][N],int row, int col){
    for(int i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
         for(int i=row, j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]){
                return false;
            }
         }
          for(int i=row, j=col;i<N&&j>=0;i++,j--){
            if(board[i][j]){
                return false;
            }
         }
    }
    return true;
}
 bool solveutil(int board[N][N], int col){
    if(col>=N){
        return true;
    }
    for(int i=0;i<N;i++){
        if(issafe(board,i,col)){
            board[i][col]=1;
            if(solveutil(board,col+1))
                return true;
            
            board[i][col]=0;
        }
    }
    return false;
 }
bool solve(){
    int board[N][N]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    if(solveutil(board,0)==false){
        cout<<"Cannot be solved";
        return false;
    }
    
        print(board);
        return true;
    
 }
  int main(){
    solve();
    return 0;
  }