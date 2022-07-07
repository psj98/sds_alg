#include <iostream>
#define MAX 1000001

using namespace std;

int arr[MAX]; // 소수 체크 배열
int prime[MAX]; // 소수 배열

int main(){
    int cnt=0;

    for(int i = 2; i < MAX; i++)
        arr[i] = 1;

    for(int i = 2; i < MAX; i++){
        for(int j = 2; i * j < MAX; j++){
            if(arr[i * j] == 1)
                arr[i * j] = 0;
        }
    }

    // 홀수의 합으로 나타내므로 i=3부터 해도 상관 X
    for(int i = 2; i < MAX; i++){
        if(arr[i] == 1){
            prime[cnt] = i;
            cnt++;
        }
    }

    while(1){
        int n;
        scanf("%d", &n);

        if(n == 0)
            break;

        for(int i = 0; i < n; i++){
            if(arr[n - prime[i]] == 1){
                printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
                break;
            }
        }        
    }

    return 0;
}