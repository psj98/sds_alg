// 각 값을 배열에 저장해놓고 재귀
#include <iostream>

typedef long long ll;
using namespace std;

ll val[90]={0};

ll fibo(int a){
    if(a==0) return 0;
    else if(a==1) return 1;

    if(val[a]>0) return val[a];
    else{
        val[a]=fibo(a-2)+fibo(a-1);
        return val[a];
    }
}

int main(){
    int n;
    cin >> n;
    cout << fibo(n);

    return 0;
}