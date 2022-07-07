#include <iostream>
#include <vector>
#define MAX 4000001

using namespace std;

int arr[MAX];
int prime[MAX];

int main(){
    int n, l=0, r=0, ans=0, sum=0;
    scanf("%d", &n);

    for(int i=2; i<=n; i++)
        arr[i]=1;

    for(int i=2; i<=n; i++)
        for(int j=2; i*j<=n; j++)
            if(arr[i*j]==1)
                arr[i*j]=0;
    
    if(arr[n]==1) ans+=1;

    for(int i=2, j=0; i<n; i++){
        if(arr[i]==1){
            prime[j]=i;
            j++;
        }
    }

    while(prime[r]!=0){
        if(sum>=n)
            sum-=prime[l++];
        else
            sum+=prime[r++];
            
        if(sum==n) ans++;
    }

    printf("%d", ans);

    return 0;
}