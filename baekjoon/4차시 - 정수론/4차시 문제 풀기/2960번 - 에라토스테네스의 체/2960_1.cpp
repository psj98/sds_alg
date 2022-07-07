// 배열 사용
#include <iostream>

using namespace std;

int main(){
    int n, k, cnt=0;
    scanf("%d %d", &n, &k);

    int arr[n+1];

    for(int i=2; i<=n; i++)
        arr[i]=1;

    for(int i=2; i<=n; i++){
        for(int j=1; i*j<=n; j++){
            if(arr[i*j]==1){
                arr[i*j]=0;
                cnt++;

                if(cnt==k){
                    printf("%d", i*j);
                    return 0;
                }
            }
        }
    }

    return 0;
}