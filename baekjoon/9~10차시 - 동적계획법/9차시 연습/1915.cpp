#include <iostream>
#define MAX 1001

using namespace std;

int dp[MAX][MAX];

int main(){
    int n, m, ans=0;
    string s;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        cin >> s;
        for(int j=0; j<m; j++)
            dp[i][j+1]=s[j]-48;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(dp[i][j]!=0){
               dp[i][j]=min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]))+1;
               ans=max(ans, dp[i][j]);
            }
        }
    }

    printf("%d", ans*ans);

    return 0;
}