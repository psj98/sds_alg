#include <iostream>
#define MAX 1025

using namespace std;

int dp[MAX][MAX];

int main(){
    int n, m, x1, x2, y1, y2;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &dp[i][j]);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1) dp[i][j]+=dp[i][j-1];
            else dp[i][j]+=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
        }
    }

    for(int i=0; i<m; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1]);
    }

    return 0;
}