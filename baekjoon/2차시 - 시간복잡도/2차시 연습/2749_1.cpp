// 피사모 법칙 적용
#include <iostream>
#define MAX 1500000
#define MOD 1000000

typedef long long ll;
using namespace std;

ll arr[MAX]={0, 1};

int main(){
    ll n;
    cin >> n;

    for(int i = 2; i < MAX; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;

    printf("%lld", arr[n % MAX]);

    return 0;
}