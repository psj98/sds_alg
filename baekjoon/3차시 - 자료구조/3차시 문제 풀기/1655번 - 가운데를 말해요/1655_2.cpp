// priority queue µÎ °³
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

int main(){
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++){
        int a, size;
        scanf("%d", &a);

        if(pq1.size()==pq2.size()) pq1.push(a);
        else pq2.push(a);

        if(!pq1.empty()&&!pq2.empty()&&pq1.top()>pq2.top()){
            int max, min;
            max = pq1.top(), min=pq2.top();
            pq1.pop(), pq2.pop();
            pq1.push(min), pq2.push(max);
        }

        printf("%d\n", pq1.top());
    }

    return 0;
}