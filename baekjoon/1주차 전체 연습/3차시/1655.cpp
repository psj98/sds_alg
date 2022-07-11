#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<int> pq1; // 내림차순
priority_queue<int, vector<int>, greater<int>> pq2; // 오름차순

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        
        if(pq1.size()==pq2.size()) pq1.push(a);
        else pq2.push(a);

        if(!pq1.empty()&&!pq2.empty()&&pq1.top()>pq2.top()){
            int k, j;
            k=pq1.top();
            j=pq2.top();
            pq1.pop();
            pq2.pop();
            pq1.push(j);
            pq2.push(k);
        }

        printf("%d\n", pq1.top());
    }
    
    return 0;
}