#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;

        if(str=="push"){
            int a;
            cin >> a;
            q.push(a);
        }

        else if(str=="pop"){
            if(!q.empty()){
                printf("%d\n", q.front());
                q.pop();
            }
            else printf("-1\n");
        }

        else if(str=="size")
            printf("%d\n", q.size());
            
        else if(str=="empty"){
            if(!q.empty()) printf("0\n");
            else printf("1\n");
        }

        else if(str=="front"){
            if(!q.empty()) printf("%d\n", q.front());
            else printf("-1\n");
        }

        else if(str=="back"){
            if(!q.empty()) printf("%d\n", q.back());
            else printf("-1\n");
        }
    }

    return 0;
}