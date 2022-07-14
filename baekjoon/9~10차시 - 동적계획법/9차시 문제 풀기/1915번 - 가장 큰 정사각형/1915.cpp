#include <iostream>
#define MAX 1001

using namespace std;

int arr[MAX][MAX];

int main(){
    int n, m, ans=0;
    string s;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        cin >> s;
        for(int j=0; j<m; j++)
            arr[i][j+1]=s[j]-48;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j]!=0){
                arr[i][j]=min(arr[i-1][j], min(arr[i][j-1], arr[i-1][j-1])) + 1;
                if(ans<arr[i][j]) ans=arr[i][j];
            }
        }
    }

    printf("%d", ans*ans);

    return 0;
}