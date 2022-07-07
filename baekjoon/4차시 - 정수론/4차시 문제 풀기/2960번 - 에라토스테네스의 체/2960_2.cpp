// vector »ç¿ë
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main(){
    int n, k, cnt=0;
    scanf("%d %d", &n, &k);

    for(int i=2; i<=n; i++)
        v.push_back(1);

    for(int i=2; i<=n; i++){
        for(int j=1; i*j<=n; j++){
            if(v[i*j-2]==1){
                v[i*j-2]=0;
                cnt++;

                if(cnt==k){
                    printf("%d", i*j);
                    return 0;
                }
            }
        }
    }

    return 0;
}