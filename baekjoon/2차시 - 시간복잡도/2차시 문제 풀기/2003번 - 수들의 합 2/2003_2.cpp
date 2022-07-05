// 투 포인터
#include <iostream>

using namespace std;

int main(){
    int n, m, sum=0, left=0, right=0, cnt=0;
    int a[10000]={0};

    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> a[i];

    while(1){
        if(sum>=m) sum-=a[left++];
        else if(right==n) break;
        else sum+=a[right++];

        if(sum==m) cnt++;
    }

    printf("%d", cnt);

    return 0;
}