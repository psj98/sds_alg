#include <iostream>

typedef long long ll;
using namespace std;

ll arr[91] = {0, 1, 1}; // 배열 초기화

ll fibo(int n){
    if(n == 0)
        return 0;
    else if(n == 1||n == 2)
        return 1;
    
    if(arr[n] > 1)
        return arr[n];
    else {
        arr[n] = fibo(n - 2) + fibo(n - 1);
        return arr[n];
    }
}

int main(){
    int n;
    cin >> n;
    cout << fibo(n);

    return 0;
}