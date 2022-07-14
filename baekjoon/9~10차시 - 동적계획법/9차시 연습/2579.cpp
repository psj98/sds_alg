#include <iostream>
#define MAX 301

using namespace std;

int dp[MAX];
int ans[MAX];

int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &dp[i]);

    ans[1]=dp[1];
    ans[2]=dp[1]+dp[2];
    ans[3]=max(dp[1], dp[2])+dp[3];

    for(int i=4; i<=n; i++)
        ans[i]=max(dp[i-1]+ans[i-3], ans[i-2])+dp[i];

    printf("%d", ans[n]);

    return 0;
}