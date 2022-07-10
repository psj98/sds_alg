#include <iostream>
#define MAX 1500000
#define MOD 1000000

typedef long long ll;
using namespace std;

int arr[MAX]={0, 1, 1};

int main(){
    ll n;
    scanf("%lld", &n);

    for(int i=3; i<MAX; i++)
        arr[i]=(arr[i-1]+arr[i-2])%MOD;

    printf("%d", arr[n%MAX]);

    return 0;
}