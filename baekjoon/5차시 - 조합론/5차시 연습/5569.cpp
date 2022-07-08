#include <iostream>
#define MOD 100000

typedef long long ll;
using namespace std;

// 0 : ���, 1 : ���, 2 : ���, 3 : ���
ll route[101][101][4]; // ��ǥ (1, 1) ~ (100, 100)

int main(){
    int w, h, ans = 0;
    scanf("%d %d", &w, &h);

    for(int i = 1; i <= w; i++)
        route[i][1][3] = 1; // ������ �� �Ʒ��� 3 : ��� ���� ���� ���

    for(int i = 1; i <= h; i++)
        route[1][i][0] = 1; // ������ �� ������ 0 : ��� �� ���� ���

    /*
        ���� ��ġ����  OO �� ���� ���, �� �ܰ� ������ OO���� �;� ����
        ��� -> ��� / ��� (2����)
        ��� -> ��� (1����)
        ��� -> ��� (1����)
        ��� -> ��� / ��� (2����)
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
        ans += route[w][h][i]; // ���� ��ǥ�� ��� ���Ⱚ�� ����

    printf("%d", ans % MOD);

    return 0;
}