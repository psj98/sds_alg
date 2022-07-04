#include <iostream>

using namespace std;

int sudoku[9][9];

int check(int x, int y, int val){
    // 가로, 세로 줄 체크
    for(int i=0; i<9; i++){
        if(sudoku[x][i]==val) return 0;
        if(sudoku[i][y]==val) return 0;
    }

    // 박스 체크
    for(int i=(x/3)*3; i<(x/3)*3+3; i++)
        for(int j=(y/3)*3; j<(y/3)*3+3; j++)
            if(sudoku[i][j]==val) return 0;

    return 1;
}

void solve(int x, int y){
    if(x==9){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++)
                printf("%d ", sudoku[i][j]);
            printf("\n"); 
        }
        exit(0);
    }

    if(y==9) solve(x+1, 0);
    
    // 0일 때
    if(sudoku[x][y] == 0){
        for(int i=1; i<=9; i++){
            if(check(x, y, i)){
                sudoku[x][y]=i;
                solve(x, y+1);
                sudoku[x][y]=0;
            }
        }
    }

    else solve(x, y+1);
}

int main(){
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin >> sudoku[i][j];

    solve(0, 0); // 스도쿠 풀기

    return 0;
}