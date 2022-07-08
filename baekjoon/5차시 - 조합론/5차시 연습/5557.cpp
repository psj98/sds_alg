#include <iostream>

typedef long long ll;
using namespace std;

int arr[100];
ll ans[100][21]; // + �Ǵ� -�� ���� 20�� ������ �ȵǱ� ������ [21]

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    ans[0][arr[0]] = 1; // �ʱⰪ�� ��ġ�� 1 ����

    // ��(�Է°��� �� �迭(arr)�� ������ ���� ����)
    for(int i = 1; i < n - 1; i++){
        for(int j = 0; j < 21; j++){
            // ans�迭�� ����� ���� 1�� ��쿡�� ����
            if(ans[i - 1][j]){
                // ���� ������ ��, 20���� �۰ų� ���ƾ���
                if(j + arr[i] <= 20)
                    ans[i][j + arr[i]] += ans[i - 1][j];

                // ���� ���� ��, 0���� ũ�ų� ���ƾ���
                if(j - arr[i] >= 0)
                    ans[i][j - arr[i]] += ans[i - 1][j];
            }
        }
    }

    printf("%lld", ans[n - 2][arr[n - 1]]);

    return 0;
}