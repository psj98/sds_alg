#include <iostream>

using namespace std;

int arr[100002]={0};

int main(){
    int n, m, a , b;
    scanf("%d %d", &n, &m);

    for(int i=2; i<=n+1; i++){
        scanf("%d", &arr[i]);
        arr[i-1]=arr[i]+arr[i-2];
    }

    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", arr[b]-arr[a-1]);
    }

    return 0;
}