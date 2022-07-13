// 플로이드-워셜 알고리즘
#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;
int matrix[101][101]; // 행렬

int main(){
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);

    // 초기화
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = INF;
        }
    }

    // 입력 받은 경로 중 최솟값을 넣음
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        matrix[a][b] = min(matrix[a][b], c);
    }

    // 원래 값 vs 경유로 가는 값 비교
    for(int k = 1; k <= n; k++) // 경유지
        for(int i = 1; i <= n; i++) // 시작 노드
            for(int j = 1; j <= n; j++) // 도착 노드
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

    // 출력
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            printf("%d ", matrix[i][j] == INF ? 0 : matrix[i][j]);
        printf("\n");

    return 0;
}