// Å¥ (queue »ç¿ë)
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

queue<int> q;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char str[10];
        scanf("%s", str);

        if(!strcmp(str, "push")){
            int a;
            scanf("%d", &a);
            q.push(a);
        }

        else if(!strcmp(str, "pop")){
            if(q.empty())
                printf("-1\n");
            else{
                printf("%d\n", q.front());
                q.pop();
            }
        }

        else if(!strcmp(str, "size"))
            printf("%d\n", q.size());

        else if(!strcmp(str, "empty")){
            if(q.empty())
                printf("1\n");
            else
                printf("0\n");
        }

        else if(!strcmp(str, "front")){
            if(q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.front());
        }

        else if(!strcmp(str, "back")){
            if(q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.back());
        }
    }

    return 0;
}