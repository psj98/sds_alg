#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 50

using namespace std;

int n, m, answer;
int map[MAX][MAX];
int dp[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void nm(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string sen;
        cin >> sen;

        for(int j = 0; j < m; j++){
            if(sen[j] == 'H')
                map[i][j] = 0;
            else
                map[i][j] = sen[j] - '0';
        }
    }
}

int DFS(int x, int y){
    // ¹üÀ§ ¿Ü
    if(x < 0 || y < 0 || x >= n || y >= m || map[x][y] == 0)
        return 0;
    if(visit[x][y] == true){
        printf("%d\n", -1);
        exit(0);
    }

    if(dp[x][y] != -1)
        return dp[x][y];
    
    visit[x][y] = true;
    dp[x][y] = 0;

    for(int i = 0; i < 4; i++){
        int nx = x + (map[x][y] * dx[i]);
        int ny = y + (map[x][y] * dy[i]);
        if(dp[x][y] > DFS(nx, ny) + 1) dp[x][y] = dp[x][y];
        else dp[x][y] = DFS(nx, ny) + 1;
    }

    visit[x][y] = false;
    return dp[x][y];
}
 
int main(){
    nm();
    memset(dp, -1, sizeof(dp));
    answer = DFS(0, 0);
    printf("%d\n", answer);

    return 0;
}