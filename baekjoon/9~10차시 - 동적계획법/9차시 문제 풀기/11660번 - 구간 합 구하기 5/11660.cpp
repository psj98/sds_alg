#include <iostream>
#define MAX 1025

using namespace std;

int mat[MAX][MAX];
int val[MAX][MAX];

int main(){
    int n, m, a, x1, x2, y1, y2;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a);

            if(i==1 && j==1) val[i][j]=a;
            else if(i==1) val[i][j]=a+val[i][j-1];
            else if(j==1) val[i][j]=a+val[i-1][j];
            else val[i][j]=a+val[i-1][j]+val[i][j-1]-val[i-1][j-1];
        }
    }

    for(int i=0; i<m; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        printf("%d\n", val[x2][y2]-val[x1-1][y2]-val[x2][y1-1]+val[x1-1][y1-1]);
    }


    return 0;
}