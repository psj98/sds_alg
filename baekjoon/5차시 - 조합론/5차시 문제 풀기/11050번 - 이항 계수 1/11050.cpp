// 파스칼 삼각형으로도 해보기
#include <iostream>

using namespace std;

int fact(int a){
    int ans=1;
    for(int i=a; i>0; i--)
        ans*=i;

    return ans;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int ans = fact(n)/(fact(n-k)*fact(k));

    printf("%d", ans);
    
    return 0;
}