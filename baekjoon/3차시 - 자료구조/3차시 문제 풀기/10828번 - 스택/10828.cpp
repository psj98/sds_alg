#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;

        if(str=="push"){
            int a;
            cin >> a;
            s.push(a);
        }

        else if(str=="pop"){
            if(!s.empty()){
                printf("%d\n", s.top());
                s.pop();
            }
            else printf("-1\n");
        }

        else if(str=="size")
            printf("%d\n", s.size());
            
        else if(str=="empty"){
            if(!s.empty()) printf("0\n");
            else printf("1\n");
        }

        else if(str=="top"){
            if(!s.empty()) printf("%d\n", s.top());
            else printf("-1\n");
        }
    }

    return 0;
}