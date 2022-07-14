#include <iostream>
#define MAX 501

using namespace std;

int dp[MAX][MAX];

int main(){
    int n, ans=0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            scanf("%d", &dp[i][j]);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==1) dp[i][j]+=dp[i-1][j];
            else if(i==j) dp[i][j]+=dp[i-1][j-1];
            else dp[i][j]+=max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    for(int i=1; i<=n ;i++)
        ans=max(ans, dp[n][i]);

    printf("%d", ans);

    return 0;
}