#include <iostream>
#define MOD 100000

typedef long long ll;
using namespace std;

ll dp[101][101][4];
// 0 ¡è ¡è
// 1 ¡æ ¡è
// 2 ¡æ ¡æ
// 3 ¡è ¡æ

int main(){
    int w, h, ans=0;
    scanf("%d %d", &w, &h);

    for(int i=1; i<=w; i++)
        dp[1][i][2]=1; // ¡æ ¡æ
    
    for(int i=1; i<=h; i++)
        dp[i][1][0]=1; // ¡è ¡è

    for(int i=2; i<=h; i++){
        for(int j=2; j<=w; j++){
            dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]) % MOD; // ¡æ ¡è , ¡è ¡è
            dp[i][j][1]=dp[i-1][j][2] % MOD; // 
            dp[i][j][2]=(dp[i][j-1][2]+dp[i][j-1][3]) % MOD;
            dp[i][j][3]=dp[i][j-1][0] % MOD;
        }
    }

    for(int i=0; i<4; i++)
        ans+=dp[h][w][i];

    printf("%d", ans%MOD);

    return 0;
}