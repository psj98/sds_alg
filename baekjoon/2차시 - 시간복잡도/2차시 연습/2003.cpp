#include <iostream>

using namespace std;

int main(){
    int n, m; // �Է°�
    int l  = 0, r = 0; // �� ������
    int sum = 0, cnt = 0; // ��, ����
    int arr[10000] = {0};
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // ������ ���� sum�� ���� ��츦 �����ϱ� ���� r<=n���� ����
    while(r <= n){
        if(sum >= m)
            sum -= arr[l++];
        else
            sum += arr[r++];

        // ������ ���
        if(sum == m)
            cnt++;
    }

    printf("%d", cnt);

    return 0;
}