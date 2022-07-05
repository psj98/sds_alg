// 이분 법칙
#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

vector<int> vec;
ll n, m, sum;
int answer;

int main(){
    int left, right;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }

    left=0;
    right=*max_element(vec.begin(), vec.end());

    while(left<=right){
        int mid=(left+right)/2;
        sum=0;
        for(int i=0; i<n; i++)
            if(mid<vec[i]) sum+=vec[i]-mid;
        
        if(sum>=m){
            if(answer<mid) answer=mid;
            left=mid+1;
        }
        else right=mid-1;
    }

    printf("%d", answer);

    return 0;
}