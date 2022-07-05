// 피사모 법칙(vector)
#include <iostream>
#include <vector>
#define MOD 1000000
#define SIZE 1500000

typedef long long ll;
using namespace std;

vector<int> vec;

int main(){
    ll n;
    cin >> n;

    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    
    for(int i=3; i<SIZE; i++)
        vec.push_back((vec[i-2]+vec[i-1])%MOD);

    printf("%d", vec[n%SIZE]);

    return 0;
}