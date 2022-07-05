#include <iostream>
#define MAX 15

using namespace std;

int n, count = 0;
int b[MAX];

int check(int ch){
    // 같은 열, 대각선 X
    for(int i = 0; i<ch; i++)
        if(b[i] == b[ch] || ch-i == abs(b[ch]-b[i]))
            return 0;

    return 1;
}

void nqueen(int row){
    if(row == n) count++;
    else{
        for(int i=0; i<n; i++){
            b[row] = i;
            if(check(row)) nqueen(row + 1);
        }
    }
}

int main(){
    cin >> n;
    nqueen(0);
    printf("%d", count);

    return 0;
}