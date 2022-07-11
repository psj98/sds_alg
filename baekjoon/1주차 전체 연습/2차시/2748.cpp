#include <iostream>

typedef long long ll;
using namespace std;

ll arr[91]={0, 1, 1};

ll fibo(int a){
    if(a==0) return 0;
    else if(a==1 || a==2) return 1;
    
    if(arr[a]>0) return arr[a];
    else {
        arr[a]=fibo(a-1)+fibo(a-2);
        return arr[a];
    }
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%lld", fibo(n));

    return 0;
}