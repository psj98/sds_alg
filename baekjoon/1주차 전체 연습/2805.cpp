#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

vector<ll> v;

int main(){
    ll n, m, a, sum, ans=0, l, r;

    scanf("%lld %lld", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%lld", &a);
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    l=0, r=v.back();

    while(l<=r){
        ll mid=(l+r)/2;
        sum=0;
        for(int i=0; i<n; i++)
            if(mid<v[i]) sum+=v[i]-mid;
        
        if(sum>=m){
            if(ans<mid) ans=mid;
            l=mid+1;
        }

        else
            r=mid-1;
    }

    printf("%lld", ans);

    return 0;
}