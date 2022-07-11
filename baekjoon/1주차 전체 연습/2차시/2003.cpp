#include <iostream>
#define MAX 10000

using namespace std;

int arr[MAX];

int main(){
    int n, m, l=0, r=0, sum=0, cnt=0;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    while(l<=r){
        if(sum>=m) sum-=arr[l++];
        else if(r==n) break;
        else sum+=arr[r++];

        if(sum==m) cnt++;
    }

    printf("%d", cnt);

    return 0;
}