#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(){
    int n;
    string a;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        cin >> a;
        if(a=="push"){
            int b;
            scanf("%d", &b);
            s.push(b);
        }
        
        else if(a=="pop"){
            if(s.empty()) printf("-1\n");
            else {
                printf("%d\n", s.top());
                s.pop();
            }
        }

        else if(a=="size")
            printf("%d\n", s.size());

        else if(a=="empty"){
            if(s.empty()) printf("1\n");
            else printf("0\n");
        }

        else if(a=="top"){
            if(s.empty()) printf("-1\n");
            else printf("%d\n", s.top());
        }
    }

    return 0;
}