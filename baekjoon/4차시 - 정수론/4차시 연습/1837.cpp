#include <iostream>
#define MAX 1000001

using namespace std;

int arr[MAX];
int prime[MAX]; // n보다 작은 범위의 소수만 넣음

int main(){
    string p; // 범위가 크기 때문에 string으로 설정
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
            t = (t * 10 + p[j] - '0') % prime[i]; // p가 n보다 작은 소수로 나눠지는지 확인

        // n보다 작은 소수로 나눠지는 경우
        if(t == 0){
            ans = prime[i];
            break;
        }
    }

    // n보다 작은 소수로 나눠지는 경우 (BAD 답) 출력
    if(ans < n && ans != 0)
        printf("BAD %d", ans);
    else
        printf("GOOD");

    return 0;
}