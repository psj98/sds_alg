// 큐 (배열 사용)
#include <iostream>
#include <string.h>

using namespace std;

int arr[10001];

int main(){
    int n, front=0, back=0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char str[10];
        scanf("%s", &str);

        if(!strcmp(str, "push")){
            int a;
            scanf("%d", &a);
            arr[back]=a;
            back++;
        }

        else if(!strcmp(str, "pop")){
            if(arr[front] == 0)
                printf("-1\n");
            else{
                printf("%d\n", arr[front]);
                arr[front++] = 0;
            }
        }

        else if(!strcmp(str, "size"))
            printf("%d\n", back - front);

        else if(!strcmp(str, "empty")){
            if(arr[front] == 0)
                printf("1\n");
            else
                printf("0\n");
        }

        else if(!strcmp(str, "front")){
            if(arr[front] != 0)
                printf("%d\n", arr[front]);
            else
                printf("-1\n");
        }

        else if(!strcmp(str, "back")){
            if(arr[back - 1] != 0)
                printf("%d\n", arr[back - 1]);
            else
                printf("-1\n");
        }
    }

    return 0;
}