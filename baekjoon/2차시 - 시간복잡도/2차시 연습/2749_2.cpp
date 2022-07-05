// 피사모 법칙 적용
#include <iostream>
#include <vector>
#define MAX 1500000
#define MOD 1000000

typedef long long ll;
using namespace std;

vector<ll> vec;

int main(){
    ll n;
    cin >> n;

    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);

    for(int i = 3; i < MAX; i++)
        vec.push_back((vec[i - 1] + vec[i - 2]) % MOD);

    printf("%lld", vec[n % MAX]);

    return 0;
}