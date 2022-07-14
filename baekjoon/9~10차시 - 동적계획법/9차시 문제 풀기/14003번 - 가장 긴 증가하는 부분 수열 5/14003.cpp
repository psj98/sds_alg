#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int arr[MAX];
int index[MAX];
vector<int> v, ans;

int main(){
    int n, cnt=0;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);

        // 값의 위치 찾기 (시작 0부터)
        int it=lower_bound(v.begin(), v.end(), arr[i])-v.begin();
        index[i]=it;
        
        if(it+v.begin()==v.end()){
            v.push_back(arr[i]);
            cnt++;
        }
        else v[it]=arr[i];
    }

    printf("%d\n", cnt);

    for(int i=n-1; n>=0; i--){
        if(cnt<1) break;
        if(index[i]==cnt-1){
            ans.push_back(arr[i]);
            cnt--;
        }
    }

    while(!ans.empty()){
        printf("%d ", ans.back());
        ans.pop_back();
    }

    return 0;
}