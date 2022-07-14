#include <iostream>
#define MAX 1000001

using namespace std;

int arr[MAX];
int prime[MAX];

int main(){
    string str;
    int n, cnt=0, ans=0;
    cin >> str >> n;

    for(int i=2; i<=MAX; i++)
        arr[i]=1;

    for(int i=2; i<=MAX; i++)
        for(int j=2; i*j<=MAX; j++)
            arr[i*j]=0;

    for(int i=2, j=0; i<=MAX; i++){
        if(arr[i]==1){
            prime[j]=i;
            j++;
            if(i<=n) cnt++;
        }
    }

    for(int i=0; i<cnt; i++){
        int a=0;
        for(int j=0; j<str.size(); j++)
            a=(a*10+(str[j]-'0'))%prime[i];
        
        if(a==0){
            ans=prime[i];
            break;
        }
    }

    if(ans!=0 && ans<n)
        printf("BAD %d", ans);
    if(ans==0 || ans>=n)
        printf("GOOD");

    return 0;
}