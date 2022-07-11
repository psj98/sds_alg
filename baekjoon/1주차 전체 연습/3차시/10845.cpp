#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        if(s=="push"){
            int a;
            scanf("%d", &a);
            q.push(a);
        }

        else if(s=="pop"){
            if(q.empty()) printf("-1\n");
            else{
                printf("%d\n", q.front());
                q.pop();
            }
        }

        else if(s=="size") printf("%d\n", q.size());
        else if(s=="empty"){
            if(q.empty()) printf("1\n");
            else printf("0\n");
        }

        else if(s=="front"){
            if(q.empty()) printf("-1\n");
            else printf("%d\n", q.front());
        }

        else if(s=="back"){
            if(q.empty()) printf("-1\n");
            else printf("%d\n", q.back());
        }
    }

    return 0;
}