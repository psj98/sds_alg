#include <iostream>

typedef long long ll;
using namespace std;

int arr[100];
ll arr2[100][21];

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    arr2[0][arr[0]]=1;

    for(int i=1; i<n-1; i++){
        for(int j=0; j<=20; j++){
            if(arr2[i-1][j]){
                if(j+arr[i]<=20) arr2[i][j+arr[i]] += arr2[i-1][j];
                if(j-arr[i]>=0) arr2[i][j-arr[i]] += arr2[i-1][j];
            }
        }
    }

    printf("%lld", arr2[n-2][arr[n-1]]);

    return 0;
}