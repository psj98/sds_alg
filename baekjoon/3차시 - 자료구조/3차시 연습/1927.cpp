// priority queue 사용 (오름차순)
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);

        if(a == 0){
            if(pq.empty())
                printf("0\n");
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }

        else
            pq.push(a);
    }

    return 0;
}