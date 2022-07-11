#include <iostream>

typedef long long ll;
using namespace std;

ll tree[1024*1024*2+1];

int main(){
    int n, m, k, idx=1;
    scanf("%d %d %d", &n, &m, &k);

    while(idx<n) idx*=2;

    for(int i=0; i<n; i++) scanf("%lld", &tree[idx+i]);
    for(int i=idx-1; i>0; i--) tree[i]=tree[i*2]+tree[i*2+1];

    for(int i=0; i<m+k; i++){
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if(a==1){
            tree[idx+b-1]=c;
            ll t=(idx+b-1)/2;

            while(t>0){
                tree[t]=tree[t*2]+tree[t*2+1];
                t/=2;
            }
        }

        else if(a==2){
            ll sum=0;
            ll l=idx+b-1, r=idx+c-1;

            while(l<=r){
                if(l%2==1) sum+=tree[l];
                if(r%2==0) sum+=tree[r];

                l=(l+1)/2;
                r=(r-1)/2;
            }

            printf("%lld\n", sum);
        }
    }

    return 0;
}