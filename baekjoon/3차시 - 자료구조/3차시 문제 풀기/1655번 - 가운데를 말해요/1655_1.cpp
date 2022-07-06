// 시간 초과
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++){
        int a, size;
        scanf("%d", &a);
        pq.push(a);

        if(pq.size()<=2) printf("%d\n", pq.top());
        else{
            vector<int> v;
            if(pq.size()%2==0) size=pq.size()/2-1;
            else size=pq.size()/2;
            for(int j=0; j<size; j++){
                v.push_back(pq.top());
                pq.pop();
            }
            printf("%d\n", pq.top());

            for(int j=0; j<v.size(); j++) pq.push(v[j]);
        }    
    }

    return 0;
}