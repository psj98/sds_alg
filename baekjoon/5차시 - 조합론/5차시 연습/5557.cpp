#include <iostream>

typedef long long ll;
using namespace std;

int arr[100];
ll ans[100][21]; // + 또는 -한 값이 20을 넘으면 안되기 때문에 [21]

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    ans[0][arr[0]] = 1; // 초기값의 위치에 1 저장

    // 답(입력값이 들어간 배열(arr)의 마지막 숫자 제외)
    for(int i = 1; i < n - 1; i++){
        for(int j = 0; j < 21; j++){
            // ans배열에 저장된 값이 1인 경우에만 수행
            if(ans[i - 1][j]){
                // 값을 더했을 때, 20보다 작거나 같아야함
                if(j + arr[i] <= 20)
                    ans[i][j + arr[i]] += ans[i - 1][j];

                // 값을 뺐을 때, 0보다 크거나 같아야함
                if(j - arr[i] >= 0)
                    ans[i][j - arr[i]] += ans[i - 1][j];
            }
        }
    }

    printf("%lld", ans[n - 2][arr[n - 1]]);

    return 0;
}