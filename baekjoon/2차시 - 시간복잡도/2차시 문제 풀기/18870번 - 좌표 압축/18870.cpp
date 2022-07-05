// 벡터 중복 제거, lower_bound 사용(원래 숫자보다 작은 개수)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int v;
        cin >> v;
        vec.push_back(v);
    }

    vector<int> cpy(vec);

    sort(cpy.begin(), cpy.end());
    cpy.erase(unique(cpy.begin(),cpy.end()),cpy.end());

    for(int i=0; i<n; i++){
        auto a=lower_bound(cpy.begin(), cpy.end(), vec[i]);
        printf("%d ", a-cpy.begin());
    }
        
    return 0;
}