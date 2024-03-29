// 스택 (배열 사용)
#include <iostream>
#include <string.h>

using namespace std;

int arr[10001];

int main(){
    int n, back = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char str[10];
        scanf("%s", &str);

        if(!strcmp(str, "push")){
            int a;
            scanf("%d", &a);
            arr[back] = a;
            back++;
        }

        else if(!strcmp(str, "pop")){
            if(arr[back - 1] != 0 && back != 0){
                printf("%d\n", arr[back - 1]);
                arr[back - 1]=0;
                back--;
            }
            else
                printf("-1\n");
        }

        else if(!strcmp(str, "size"))
            printf("%d\n", back);

        else if(!strcmp(str, "empty")){
            if(arr[back - 1] != 0 && back != 0)
                printf("0\n");
            else
                printf("1\n");
        }

        else if(!strcmp(str, "top")){
            if(arr[back - 1] != 0 && back != 0)
                printf("%d\n", arr[back - 1]);
            else
                printf("-1\n");
        }
    }

    return 0;
}