#include <iostream>
#define MAX 100001

using namespace std;

int dp[MAX];

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++)
        scanf("%d", &dp[i]);

    for(int i=2; i<=n; i++)
        dp[i]+=dp[i-1];

    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[b]-dp[a-1]);        
    }

    return 0;
}