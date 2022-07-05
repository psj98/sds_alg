// 시간 초과
#include <iostream>

using namespace std;

int main(){
    long long x, y;
    int z, ans=0;
    cin >> x >> y;
    z = (y*100)/x;

    if(z>=99) ans=-1;
    else{
        while(1){
            x++;
            y++;
            ans++;
            if((y*100)/x!=z)
                break;
        }
    }

    cout << ans;

    return 0;
}