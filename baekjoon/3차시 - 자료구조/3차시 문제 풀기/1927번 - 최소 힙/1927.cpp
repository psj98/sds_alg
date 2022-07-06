#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a; scanf("%d", &a);
        if(a==0){
            if(pq.size()){
                printf("%d\n", pq.top());
                pq.pop();
            }
            else printf("0\n");
        }
        else pq.push(a);
    }
    return 0;
}