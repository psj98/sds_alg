// ¿Œµ¶Ω∫ ∆Æ∏Æ
#include <iostream>

typedef long long ll;
using namespace std;

ll tree[1024*1024*2+1];

int main(){
    int n, m, k, idx=1;
    cin >> n >> m >> k;

    while(idx<n) idx*=2;

    for(int i=0; i<n; i++) cin >> tree[i+idx];
    for(int i=idx-1; i>0; i--)
        tree[i]=tree[i*2]+tree[(i*2)+1];

    ll a, b, c;
    for(int i=0; i<m+k; i++){
        cin >> a >> b >> c;
        if(a==1){
            ll node = b+idx-1;
            ll diff = c-tree[b+idx-1];
            while(node>0){
                tree[node] += diff;
                node/=2;
            }
        }
        else{
            ll sum=0;
            ll r=b+idx-1, l=c+idx-1;
            while(r<=l){
                if(r%2==1) sum+=tree[r];
                if(l%2==0) sum+=tree[l];
                r=(r+1)/2;
                l=(l-1)/2;
            }
            printf("%lld\n", sum);
        }
    }

    return 0;
}