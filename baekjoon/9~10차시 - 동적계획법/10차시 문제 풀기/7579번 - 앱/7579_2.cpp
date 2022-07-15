#include <iostream>
#define MAX 101

using namespace std;

int app[MAX];
int cost[MAX];
int dp[MAX][100*100+1];

int main(){
    int n, m, sum=0;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++)
        scanf("%d", &app[i]);

    for(int i=1; i<=n; i++){
        scanf("%d", &cost[i]);
        sum+=cost[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j-cost[i]>=0)
                dp[i][j]=max(dp[i][j], dp[i-1][j-cost[i]]+app[i]);
            
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
        }
    }

    for(int i=0; i<=sum; i++) 
        if(dp[n][i]>=m){
            printf("%d", i);
            break;
        }

    return 0;
}