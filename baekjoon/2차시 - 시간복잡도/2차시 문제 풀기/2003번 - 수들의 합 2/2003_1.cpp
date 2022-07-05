// 전체 비교
#include <iostream>

using namespace std;

int main(){
    int n, m, sum, start, cnt=0;
    int a[10000]={0};

    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++){
        sum=0;
        start=i;
        while(1){
            if(start==n) break;
            sum+=a[start];
            if(sum==m){
                cnt++;
                break;
            }
            else if(sum>m) break;
            start++;
        }
    }

    printf("%d", cnt);

    return 0;
}