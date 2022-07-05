// 시간 초과
#include <iostream>
#include <algorithm>

using namespace std;

int a[1000000]={0};

int main(){
    int n, m, h, sum=0;

    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> a[i];
    h=*max_element(a, a+n)-1;

    while(1){
        for(int i=0; i<n; i++){
            if(a[i]>=h)
                sum=sum+a[i]-h;
        }

        if(sum>=m) break;
        sum=0;
        h--;
    }

    printf("%d", h);

    return 0;
}