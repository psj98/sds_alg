// �÷��̵�-���� �˰���
#include <iostream>
#include <algorithm>
#include <climits>
#define INF 987654321

typedef long long ll;
using namespace std;

int am[101][101]; // ���� ���

int main(){
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);

    // �ʱ�ȭ
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) am[i][j]=0;
            else am[i][j]=INF;
        }
    }

    for(int i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        am[a][b] = min(am[a][b], c);
    }

    for(int k=1; k<=n; k++) // ������
        for(int i=1; i<=n; i++) // �����
            for(int j=1; j<=n; j++) // ������
                    am[i][j] = min(am[i][j], am[i][k]+am[k][j]);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", am[i][j] == INF ? 0 : am[i][j]);
        }
        printf("\n");
    }

    return 0;
}