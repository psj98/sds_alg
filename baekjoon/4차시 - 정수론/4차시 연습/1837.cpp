#include <iostream>
#define MAX 1000001

using namespace std;

int arr[MAX];
int prime[MAX]; // n���� ���� ������ �Ҽ��� ����

int main(){
    string p; // ������ ũ�� ������ string���� ����
    int n, cnt = 0, ans = 0;
    cin >> p >> n;

    for(int i = 2; i <= n; i++)
        arr[i] = 1;

    for(int i = 2; i <= n; i++)
        for(int j = 2; i * j <= n; j++)
            if(arr[i * j] == 1)
                arr[i * j] = 0;

    for(int i = 2; i <= n; i++){
        if(arr[i] == 1){
            prime[cnt] = i;
            cnt++;
        }
    }

    for(int i = 0; i < cnt; i++){
        int t = 0;
        for(int j = 0; j < p.size(); j++)
            t = (t * 10 + p[j] - '0') % prime[i]; // p�� n���� ���� �Ҽ��� ���������� Ȯ��

        // n���� ���� �Ҽ��� �������� ���
        if(t == 0){
            ans = prime[i];
            break;
        }
    }

    // n���� ���� �Ҽ��� �������� ��� (BAD ��) ���
    if(ans < n && ans != 0)
        printf("BAD %d", ans);
    else
        printf("GOOD");

    return 0;
}