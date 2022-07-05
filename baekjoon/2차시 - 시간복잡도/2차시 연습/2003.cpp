#include <iostream>

using namespace std;

int main(){
    int n, m; // 입력값
    int l  = 0, r = 0; // 투 포인터
    int sum = 0, cnt = 0; // 합, 정답
    int arr[10000] = {0};
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // 마지막 수가 sum과 같은 경우를 포함하기 위해 r<=n으로 조정
    while(r <= n){
        if(sum >= m)
            sum -= arr[l++];
        else
            sum += arr[r++];

        // 정답인 경우
        if(sum == m)
            cnt++;
    }

    printf("%d", cnt);

    return 0;
}