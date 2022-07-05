// ÀÌºÐ Å½»ö
#include <iostream>

using namespace std;

int main(){
    long long x, y;
    int z, ans=0, l=0, h=1000000000;
    cin >> x >> y;
    z = (y*100)/x;

    if(z>=99) ans=-1;
    else{
        while(l<=h){
            int mid=(l+h)/2;
            int a=(100*(y+mid))/(x+mid);
            if(z>=a){
                ans=mid+1;
                l=mid+1;
            }
            else h=mid-1;
        }
    }

    cout << ans;

    return 0;
}