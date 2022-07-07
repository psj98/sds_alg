#include <iostream>
#define MAX 4000001

using namespace std;

int arr[MAX];
int prime[MAX];

int main(){
    int n, cnt = 0, l = 0, r = 0, sum = 0, ans = 0;
    scanf("%d", &n);

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

    // 투 포인터 -> 구간 합
    while(l <= r){
        if(sum >= n)
            sum -= prime[l++];
        else if(r == cnt)
            break;
        else
            sum += prime[r++];
        
        if(n == sum)
            ans++;
    }

    printf("%d", ans);

    return 0;
}