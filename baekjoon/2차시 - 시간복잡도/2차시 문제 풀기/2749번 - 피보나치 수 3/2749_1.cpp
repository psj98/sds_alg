// 피사모 법칙(배열)
#include <iostream>

typedef long long ll;
using namespace std;

int arr[1500000]={0, 1};

int main(){
    ll n;
    cin >> n;
    
    for(int i=2; i<1500000; i++)
        arr[i]=(arr[i-1]+arr[i-2])%1000000;

    printf("%d", arr[n%1500000]);

    return 0;
}