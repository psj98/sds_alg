#include <iostream>
#include <string.h>
#define MAX 16
#define INF 987654321

using namespace std;

int dp[MAX][MAX];
int cost[MAX][1<<MAX];
int n;

int dfs(int node, int visitBit){
    if(node==(1<<n)-1){
        if(dp[node][0]==0) return INF;
        else dp[node][0];
    }

    if(cost[node][visitBit]!=-1)
        return cost[node][visitBit];

    for(int i=0; i<n; i++){
        if(dp[node][i]==0)
            continue;
        if((visitBit&(1<<i))==(1<<i)) continue;

        cost[node][visitBit] = min(cost[node][visitBit], dp[node][i]+dfs(i, visitBit | 1<<i));
    }

    return cost[node][visitBit];
}

int main(){
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &dp[i][j]);

    memset(cost, -1, sizeof(cost));

    printf("%d", dfs(0, 1));

    return 0;
}
