#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }

    vector<int> cpy(v);

    sort(cpy.begin(), cpy.end());
    cpy.erase(unique(cpy.begin(), cpy.end()), cpy.end());

    for(int i=0; i<n; i++){
        auto a=lower_bound(cpy.begin(), cpy.end(), v[i]);
        printf("%d ", a-cpy.begin());
    }

    return 0;
}