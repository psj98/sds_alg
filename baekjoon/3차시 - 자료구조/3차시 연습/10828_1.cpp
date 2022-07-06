// stack »ç¿ë
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

stack<int> s;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char str[10];
        scanf("%s", str);

        if(!strcmp(str, "push")){
            int a;
            scanf("%d", &a);
            s.push(a);
        }

        else if(!strcmp(str, "pop")){
            if(s.empty())
                printf("-1\n");
            else{
                printf("%d\n", s.top());
                s.pop();
            }
        }

        else if(!strcmp(str, "size"))
            printf("%d\n", s.size());

        else if(!strcmp(str, "empty")){
            if(s.empty())
                printf("1\n");
            else
                printf("0\n");
        }

        else if(!strcmp(str, "top")){
            if(s.empty())
                printf("-1\n");
            else
                printf("%d\n", s.top());
        }
    }

    return 0;
}