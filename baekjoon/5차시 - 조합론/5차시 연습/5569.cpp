#include <iostream>
#define MOD 100000

typedef long long ll;
using namespace std;

// 0 : ↑↑, 1 : →↑, 2 : ↑→, 3 : →→
ll route[101][101][4]; // 좌표 (1, 1) ~ (100, 100)

int main(){
    int w, h, ans = 0;
    scanf("%d %d", &w, &h);

    for(int i = 1; i <= w; i++)
        route[i][1][3] = 1; // 가로의 맨 아래는 3 : →→ 으로 오는 경우

    for(int i = 1; i <= h; i++)
        route[1][i][0] = 1; // 세로의 맨 왼쪽은 0 : ↑↑ 로 오는 경우

    /*
        현재 위치에서  OO 로 오는 경우, 한 단계 전에서 OO으로 와야 가능
        ↑↑ -> →↑ / ↑↑ (2가지)
        →↑ -> →→ (1가지)
        ↑→ -> ↑↑ (1가지)
        →→ -> →→ / ↑→ (2가지)
    */
    for(int i = 2; i <= w; i++){
        for(int j = 2; j <= h; j++){
            route[i][j][0] = (route[i][j - 1][0] + route[i][j - 1][1]) % MOD;
            route[i][j][1] = route[i][j - 1][3] % MOD;
            route[i][j][2] = route[i - 1][j][0] % MOD;
            route[i][j][3] = (route[i - 1][j][2] + route[i - 1][j][3]) % MOD;
        }
    }

    for(int i = 0; i < 4; i++)
        ans += route[w][h][i]; // 최종 좌표의 모든 방향값을 더함

    printf("%d", ans % MOD);

    return 0;
}