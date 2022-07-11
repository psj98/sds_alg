#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4000

typedef long long ll;
using namespace std;

ll arr[4][MAX];
vector<ll> v1, v2;

int main(){
    int n, l=0, r=0;
    ll ans=0;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        for(int j=0; j<4; j++)
            scanf("%lld", &arr[j][i]);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v1.push_back(arr[0][i]+arr[1][j]);
            v2.push_back(arr[2][i]+arr[3][j]);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());

    while(l<n*n && r<n*n){
        if(v1[l]+v2[r]==0){
            ll ab=0, cd=0, t=v2[r];
            while((v1[l]+t==0)&&l<n*n) ab++, l++;
            while((v2[r]-t==0)&&r<n*n) cd++, r++;
            ans+=ab*cd;
        }

        else if(v1[l]+v2[r]>0) r++;
        else l++;
    }

    printf("%lld", ans);

    return 0;
}