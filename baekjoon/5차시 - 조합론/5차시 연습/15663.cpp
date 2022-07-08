// 백트래킹 (연습할 것)
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8], ans[8]; // 원래 값 배열, 정답 넣은 배열
bool check[8] = {false}; // 백트래킹 중복 체크

void dfs(int a){
    if(a == m){
        for(int i = 0; i < m; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }

    int b = 0; // 중복값 확인 변수
    for(int i = 0; i < n; i++){
        // 중복값 확인
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

    sort(arr, arr + n); // 정렬
    dfs(0);

    return 0;
}