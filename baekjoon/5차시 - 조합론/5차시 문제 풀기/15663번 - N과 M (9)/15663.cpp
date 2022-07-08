// 백트래킹
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9], ans[9];
bool check[9]={false};

void dfs(int a){
    if(a==m){
        for(int i=0; i<m; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }

    int t=0;
    for(int i=0; i<n; i++){
        if(!check[i]&&arr[i]!=t){
            t=ans[a]=arr[i];
            check[i]=true;
            dfs(a+1);
            check[i]=false;
        }
    }

}

int main(){
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr+n);
    dfs(0);    

    return 0;
}