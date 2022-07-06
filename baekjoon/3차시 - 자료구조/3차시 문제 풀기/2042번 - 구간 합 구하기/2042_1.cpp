// 시간 초과
#include <iostream>
#include <vector>
#include <numeric>

typedef long long ll;
using namespace std;

vector<ll> v;

int main(){
    int n, m, k;
    ll sum;
    cin >> n >> m >> k;

    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }

    for(int i=0; i<m+k; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a==1) v[b-1]=c;
        else if(a==2){
            sum=accumulate(&v[b-1], &v[c], 0LL);
            cout << sum << "\n";
        }
    }

    return 0;
}