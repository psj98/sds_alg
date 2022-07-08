// ��Ʈ��ŷ (������ ��)
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8], ans[8]; // ���� �� �迭, ���� ���� �迭
bool check[8] = {false}; // ��Ʈ��ŷ �ߺ� üũ

void dfs(int a){
    if(a == m){
        for(int i = 0; i < m; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }

    int b = 0; // �ߺ��� Ȯ�� ����
    for(int i = 0; i < n; i++){
        // �ߺ��� Ȯ��
        if(!check[i] && arr[i] != b){
            b = ans[a] = arr[i];
            check[i] = true;
            dfs(a + 1);
            check[i] = false;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + n); // ����
    dfs(0);

    return 0;
}