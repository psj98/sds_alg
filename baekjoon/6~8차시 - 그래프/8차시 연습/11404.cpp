// �÷��̵�-���� �˰���
#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;
int matrix[101][101]; // ���

int main(){
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);

    // �ʱ�ȭ
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = INF;
        }
    }

    // �Է� ���� ��� �� �ּڰ��� ����
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        matrix[a][b] = min(matrix[a][b], c);
    }

    // ���� �� vs ������ ���� �� ��
    for(int k = 1; k <= n; k++) // ������
        for(int i = 1; i <= n; i++) // ���� ���
            for(int j = 1; j <= n; j++) // ���� ���
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

    // ���
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            printf("%d ", matrix[i][j] == INF ? 0 : matrix[i][j]);
        printf("\n");

    return 0;
}